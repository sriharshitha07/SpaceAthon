// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsThumbnailOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTColorResolutionCommand.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsThumbnailOptions : NSObject <NSCopying, NSSecureCoding>

@property (class, nonatomic, strong, readonly) LTCodecsThumbnailOptions *defaultOptions NS_SWIFT_NAME(default);

@property (nonatomic, assign) BOOL maintainAspectRatio;
@property (nonatomic, assign) BOOL forceSize;
@property (nonatomic, assign) BOOL loadStamp;
@property (nonatomic, assign) BOOL resample;

@property (nonatomic, assign) NSUInteger width;
@property (nonatomic, assign) NSUInteger height;
@property (nonatomic, assign) NSUInteger bitsPerPixel;

@property (nonatomic, assign) LTRasterByteOrder order;
@property (nonatomic, assign) LTRasterDitheringMethod ditheringMethod;
@property (nonatomic, assign) LTColorResolutionCommandPaletteFlags paletteFlags;

@property (nonatomic, copy)   LTRasterColor *backColor;

@end



@interface LTCodecsThumbnailOptions (Deprecated)

@property (nonatomic, assign) BOOL maintainAspect LT_DEPRECATED_USENEW(20_0, "maintainAspectRatio");
@property (nonatomic, assign) NSUInteger bits LT_DEPRECATED_USENEW(20_0, "bitsPerPixel");;

@end

NS_ASSUME_NONNULL_END
