using System;
using System.IO;
using Leadtools;
using Leadtools.Multimedia;

namespace spaceathon_video_audio
{
    class Program
    {
        [STAThread]
        static void Main(string[] args)
        {
            string _audioFile = @"D:\Documents\Projects\Hackathon\Space\video-audio\Example\audio.mpg";
            string _videoFile = @"D:\Documents\Projects\Hackathon\Space\video-audio\Example\video.mp4";
            string _targetFile = @"D:\Documents\Projects\Hackathon\Space\video-audio\Example\test-case.mp4";

            SetLicense();
            CombineAudioandVideo(_videoFile, _audioFile, _targetFile);


        }


        static void SetLicense()
        {
            string license = @"C:\LEADTOOLS22\Support\Common\License\LEADTOOLS.LIC";
            string key = File.ReadAllText(@"C:\LEADTOOLS22\Support\Common\License\LEADTOOLS.LIC.KEY");
            RasterSupport.SetLicense(license, key);
            if (RasterSupport.KernelExpired)
                Console.WriteLine("License file invalid or expired.");
            else
                Console.WriteLine("License file set successfully");
        }
        
        static void CombineAudioandVideo(string _videoFile, string _audioFile, string _targetFile)
        {
            ConvertCtrl vidConvert = new ConvertCtrl();
            ConvertCtrl audConvert = new ConvertCtrl();

            // Init the SampleTargets. The Video and Audio data from our files will write to these 
            SampleTarget _vidTarget = new SampleTarget();
            SampleTarget _audTarget = new SampleTarget();


            // Set the Media Type of the VideoTarget to Video 
            MediaType mt = new MediaType();
            mt.Type = Constants.MEDIATYPE_Video;
            _vidTarget.SetAcceptedMediaType(mt);
            vidConvert.TargetObject = _vidTarget;

            // Clear 
            mt = null;

            // Set the Media type for our AudioTarget to Audio 
            mt = new MediaType();
            mt.Type = Constants.MEDIATYPE_Audio;
            _audTarget.SetAcceptedMediaType(mt);
            audConvert.TargetObject = _audTarget;

            // Clear 
            mt = null;

            // Set the ConvertCtrls to point to the Files as their sources 
            vidConvert.SourceFile = _videoFile;
            audConvert.SourceFile = _audioFile;

            // Start running the two conversion controls. These are writing to the Sample Targets 
            vidConvert.StartConvert();
            audConvert.StartConvert();

            // Enter the Combine Method 
            CombineFiles(_vidTarget, _audTarget, _targetFile);

            // Stop running the ConvertCtrls 
            if (vidConvert.State == ConvertState.Running)
                vidConvert.StopConvert();
            if (audConvert.State == ConvertState.Running)
                audConvert.StopConvert();

            // Dispose of the targets we wrote the data to 
            _vidTarget.Dispose();
            _audTarget.Dispose();

            // Dispose of the ConvertCtrls that read the file data into the SampleTarget Buffers 
            vidConvert.Dispose();
            audConvert.Dispose();
        }




        static void CombineFiles(SampleTarget _vidTarget, SampleTarget _audTarget, string _targetFile)
        {
            MultiStreamSource pMSSource;
            ConvertCtrl combine;

            // Initialize the MultiStreamSource. This is the data that our Combine ConvertCtrl will be reading and then finnally writing to fill 
            // We have two streams. 0 = Video  1 = Audio 
            pMSSource = new MultiStreamSource();
            pMSSource.StreamCount = 2;

            // Set the MediaType of the Sources Video Stream to that of the data connected to the VideoTarget 
            MediaType mt = _vidTarget.GetConnectedMediaType();
            pMSSource.SetMediaType(0, mt);

            // Clear 
            mt = null;

            // Set the Mediatype of the Sources Audio Stream to that of the data connected to the AudioTarget 
            mt = _audTarget.GetConnectedMediaType();
            pMSSource.SetMediaType(1, mt);

            // Clear 
            mt = null;

            // Init the Combine ConvertCtrl that will output our file. This ConvertCtrl will take in the MultiStream Source and output a file on disk 
            combine = new ConvertCtrl();
            combine.SourceObject = pMSSource;
            combine.TargetFile = _targetFile;
            combine.VideoCompressors.H264.Selected = true;
            combine.AudioCompressors.AAC.Selected = true;
            combine.TargetFormat = TargetFormatType.MPEG2Transport;

            // Our MediaSamples. Both a source retreived from our SampleTargets and a destination that will be written to the MultiStreamSource 
            MediaSample pmsSrc = null;
            MediaSample pmsDst = null;

            long LastStart;
            long LastStop;

            int lActualDataLength;

            // chatgpt suggested
            // Directory.CreateDirectory(_targetFile); // create directory if it doesn't exist


            // Begin the running the Combine ConvertCtrl 
            combine.StartConvert();

            // Video Write 
            while (true)
            {
                try
                {
                    // Get the target sample.  
                    // Note if we hit the end of the data stream an exception will trigger and break the loop. This is how we know to stop writing to the buffer 
                    pmsSrc = _vidTarget.GetSample(6000);
                    // Get the source buffer 
                    pmsDst = pMSSource.GetSampleBuffer(0, 2000);
                }
                catch (Exception)
                {
                    break;
                }
                try
                {
                    // get the source sample time 
                    pmsSrc.GetTime(out LastStart, out LastStop);

                    // Set the destination sample time 
                    pmsDst.SetTime(LastStart, LastStop);
                }
                catch (Exception)
                {
                    pmsDst.ResetTime();
                }
                // Copy the data 
                lActualDataLength = pmsSrc.ActualDataLength;

                // Set the destination buffer  
                // We could Marshal the unmanaged buffer here, but no need since we are merely  
                // Setting the destination to the source buffer contents (unaltered data) 
                pmsDst.SetData(lActualDataLength, pmsSrc.GetData(lActualDataLength));

                // Copy the other flags 
                pmsDst.Discontinuity = pmsSrc.Discontinuity;
                pmsDst.Preroll = pmsSrc.Preroll;
                pmsDst.SyncPoint = pmsSrc.SyncPoint;

                // Release the source sample 
                pmsSrc = null;

                // Deliver the destination sample 
                pMSSource.DeliverSample(0, 1000, pmsDst);

                // Release the destination sample 
                pmsDst = null;
            }
            // Audio Write 
            while (true)
            {
                try
                {
                    // Get the target sample 
                    // Note if we hit the end of the data stream an exception will trigger and break the loop. This is how we know to stop writing to the buffer 
                    pmsSrc = _audTarget.GetSample(6000);
                    // Get the source buffer 
                    pmsDst = pMSSource.GetSampleBuffer(1, 2000);
                }
                catch (Exception)
                {
                    break;
                }
                try
                {
                    // Get the source sample time 
                    pmsSrc.GetTime(out LastStart, out LastStop);

                    // Set the destination sample time 
                    pmsDst.SetTime(LastStart, LastStop);
                }
                catch (Exception)
                {
                    pmsDst.ResetTime();
                }
                // Copy the data 
                lActualDataLength = pmsSrc.ActualDataLength;

                // Set the destination buffer  
                // We could Marshal the unmanaged buffer here, but no need since we are merely  
                // Setting the destination to the source buffer contents (unaltered data) 
                pmsDst.SetData(lActualDataLength, pmsSrc.GetData(lActualDataLength));

                // Copy the other flags 
                pmsDst.Discontinuity = pmsSrc.Discontinuity;
                pmsDst.Preroll = pmsSrc.Preroll;
                pmsDst.SyncPoint = pmsSrc.SyncPoint;

                // Release the source sample 
                pmsSrc = null;

                // Deliver the destination sample 
                pMSSource.DeliverSample(1, 1000, pmsDst);

                // Release the destination sample 
                pmsDst = null;
            }

            // Deliver end of sample to stop the conversion 
            pMSSource.DeliverEndOfStream(0, 1000);
            pMSSource.DeliverEndOfStream(1, 1000);

            // Stop the Combine ConvertCtrl if it hasn't been already 
            if (combine.State == ConvertState.Running)
                combine.StopConvert();

            // Reset the Source 
            combine.ResetSource();

            // Dispose 
            pMSSource.Dispose();
            combine.Dispose();
        }

    }

}