// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  Leadtools.Codecs.h
//  Leadtools.Codecs
//

#if !defined(LEADTOOLS_CODECS_FRAMEWORK)
#define LEADTOOLS_CODECS_FRAMEWORK

#import <Leadtools.Codecs/LTCodecsDefines.h>

#import <Leadtools.Codecs/LTCodecsImageInfo.h>
#import <Leadtools.Codecs/LTCodecsGifImageInfo.h>
#import <Leadtools.Codecs/LTCodecsFaxImageInfo.h>
#import <Leadtools.Codecs/LTCodecsJpegImageInfo.h>
#import <Leadtools.Codecs/LTCodecsPsdChannelInfo.h>
#import <Leadtools.Codecs/LTCodecsPsdImageInfo.h>
#import <Leadtools.Codecs/LTCodecsPsdLayerInfo.h>
#import <Leadtools.Codecs/LTCodecsPstImageInfo.h>
#import <Leadtools.Codecs/LTCodecsTiffImageInfo.h>
#import <Leadtools.Codecs/LTCodecsVectorImageInfo.h>
#import <Leadtools.Codecs/LTCodecsDocumentImageInfo.h>
#import <Leadtools.Codecs/LTCodecsRasterPdfInfo.h>
#import <Leadtools.Codecs/LTCodecsOptimizedLoadData.h>

#import <Leadtools.Codecs/LTCodecsOptions.h>
#import <Leadtools.Codecs/LTCodecsAbcOptions.h>
#import <Leadtools.Codecs/LTCodecsAnzOptions.h>
#import <Leadtools.Codecs/LTCodecsDocOptions.h>
#import <Leadtools.Codecs/LTCodecsEpsOptions.h>
#import <Leadtools.Codecs/LTCodecsFpxOptions.h>
#import <Leadtools.Codecs/LTCodecsGifOptions.h>
#import <Leadtools.Codecs/LTCodecsJbigOptions.h>
#import <Leadtools.Codecs/LTCodecsJbig2Options.h>
#import <Leadtools.Codecs/LTCodecsJpegOptions.h>
#import <Leadtools.Codecs/LTCodecsJpeg2000Options.h>
#import <Leadtools.Codecs/LTCodecsLoadSvgOptions.h>
#import <Leadtools.Codecs/LTCodecsPdfOptions.h>
#import <Leadtools.Codecs/LTCodecsPngOptions.h>
#import <Leadtools.Codecs/LTCodecsPtokaOptions.h>
#import <Leadtools.Codecs/LTCodecsRasterizeDocumentOptions.h>
#import <Leadtools.Codecs/LTCodecsStartDecompressOptions.h>
#import <Leadtools.Codecs/LTCodecsRawOptions.h>
#import <Leadtools.Codecs/LTCodecsRtfOptions.h>
#import <Leadtools.Codecs/LTCodecsTiffOptions.h>
#import <Leadtools.Codecs/LTCodecsTxtOptions.h>
#import <Leadtools.Codecs/LTCodecsThumbnailOptions.h>
#import <Leadtools.Codecs/LTCodecsVectorOptions.h>
#import <Leadtools.Codecs/LTCodecsVffOptions.h>
#import <Leadtools.Codecs/LTCodecsExcelOptions.h>
#import <Leadtools.Codecs/LTCodecsPowerPointOptions.h>

#import <Leadtools.Codecs/LTCodecsPageEventArgs.h>
#import <Leadtools.Codecs/LTCodecsLoadImageEventArgs.h>
#import <Leadtools.Codecs/LTCodecsSaveImageEventArgs.h>
#import <Leadtools.Codecs/LTCodecsLoadInformationEventArgs.h>
#import <Leadtools.Codecs/LTCodecsEnumTagsEventArgs.h>
#import <Leadtools.Codecs/LTCodecsEnumGeoKeysEventArgs.h>

#import <Leadtools.Codecs/LTCompressDataCallback.h>
#import <Leadtools.Codecs/LTCodecsTransformMarkerCallback.h>
#import <Leadtools.Codecs/LTCodecsExtension.h>
#import <Leadtools.Codecs/LTCodecsOverlayData.h>
#import <Leadtools.Codecs/LTRasterCodecs.h>

// Versioning
#import <Leadtools/LTLeadtools.h>

LEADTOOLS_EXPORT const unsigned char LeadtoolsCodecsVersionString[];
LEADTOOLS_EXPORT const double LeadtoolsCodecsVersionNumber;

#endif // #if !defined(LEADTOOLS_CODECS_FRAMEWORK)
