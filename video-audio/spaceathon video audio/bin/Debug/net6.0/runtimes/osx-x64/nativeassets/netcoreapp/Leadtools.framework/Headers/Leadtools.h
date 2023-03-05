// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  Leadtools.h
//  Leadtools
//

#if !defined(LEADTOOLS_FRAMEWORK)
#define LEADTOOLS_FRAMEWORK

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import <Leadtools/LTLeadtools.h>
#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTPrimitives.h>
#import <Leadtools/LTRasterKnownColor.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTRasterColor16.h>
#import <Leadtools/LTRasterHsvColor.h>
#import <Leadtools/LTRasterColorSpace.h>
#import <Leadtools/LTErrorCode.h>
#import <Leadtools/LTHandle.h>
#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools/LTRasterImageDataCallbacks.h>
#import <Leadtools/LTRasterImageMemoryInformation.h>
#import <Leadtools/LTMTLDataCallbacks.h>
#import <Leadtools/LTRasterSupport.h>
#import <Leadtools/LTRasterDefaults.h>
#import <Leadtools/LTRasterRegionXForm.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterPalette.h>
#import <Leadtools/LTRasterImageResize.h>
#import <Leadtools/LTRasterBufferResize.h>
#import <Leadtools/LTRasterBufferConverter.h>
#import <Leadtools/LTRasterRleCompressor.h>
#import <Leadtools/LTRasterOverlayAttributes.h>
#import <Leadtools/LTRasterMetadata.h>
#import <Leadtools/LTRasterTagMetadata.h>
#import <Leadtools/LTRasterCommentMetadata.h>
#import <Leadtools/LTRasterMarkerMetadata.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTRasterImageAnimator.h>
#import <Leadtools/LTRasterCommand.h>
#import <Leadtools/LTRasterCommandProcessor.h>
#import <Leadtools/LTRasterUserMatchTable.h>
#import <Leadtools/LTFlipCommand.h>
#import <Leadtools/LTCloneCommand.h>
#import <Leadtools/LTCopyRectangleCommand.h>
#import <Leadtools/LTChangeViewPerspectiveCommand.h>
#import <Leadtools/LTClearCommand.h>
#import <Leadtools/LTClearNegativePixelsCommand.h>
#import <Leadtools/LTCombineFastCommand.h>
#import <Leadtools/LTCombineWarpCommand.h>
#import <Leadtools/LTGrayscaleCommand.h>
#import <Leadtools/LTCopyDataCommand.h>
#import <Leadtools/LTFillCommand.h>
#import <Leadtools/LTCropCommand.h>
#import <Leadtools/LTShearCommand.h>
#import <Leadtools/LTSetAlphaValuesCommand.h>
#import <Leadtools/LTDetectAlphaCommand.h>
#import <Leadtools/LTScrambleCommand.h>
#import <Leadtools/LTSizeCommand.h>
#import <Leadtools/LTResizeCommand.h>
#import <Leadtools/LTRotateCommand.h>
#import <Leadtools/LTPremultiplyAlphaValuesCommand.h>
#import <Leadtools/LTCreateGrayScaleImageCommand.h>
#import <Leadtools/LTColorResolutionCommand.h>
#import <Leadtools/LTLeadStream.h>
#import <Leadtools/LTLeadFileStream.h>
#import <Leadtools/LTLeadDataStream.h>
#import <Leadtools/LTSvgDocument.h>

// Versioning
LEADTOOLS_EXPORT const unsigned char LeadtoolsVersionString[];
LEADTOOLS_EXPORT const double LeadtoolsVersionNumber;

#endif // #if !defined(LEADTOOLS_FRAMEWORK)
