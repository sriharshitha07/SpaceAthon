// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsJpegOptions.h
//  Leadtools.Codecs
//

typedef NS_ENUM(NSInteger, LTCodecsCmpQualityFactorPredefined) {
    LTCodecsCmpQualityFactorPredefinedPerfectQuality1      = -1,
    LTCodecsCmpQualityFactorPredefinedPerfectQuality2      = -2,
    LTCodecsCmpQualityFactorPredefinedSuperQuality         = -3,
    LTCodecsCmpQualityFactorPredefinedQuality              = -4,
    LTCodecsCmpQualityFactorPredefinedQualityAndSize       = -5,
    LTCodecsCmpQualityFactorPredefinedSharp                = -6,
    LTCodecsCmpQualityFactorPredefinedLessTiling           = -7,
    LTCodecsCmpQualityFactorPredefinedMaximumQuality       = -8,
    LTCodecsCmpQualityFactorPredefinedMaximumCompression   = -9,
    LTCodecsCmpQualityFactorPredefinedCustom               = -10
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpegLoadOptions : NSObject

@property (nonatomic, assign) BOOL forceCieLab;
@property (nonatomic, assign) BOOL useBadJpegPredictor;
@property (nonatomic, assign) BOOL forceRgbFile;
@property (nonatomic, assign) BOOL useFastConversion;
@property (nonatomic, assign) BOOL ignoreAdobeColorTransform;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpegSaveOptions : NSObject

@property (nonatomic, assign) LTCodecsCmpQualityFactorPredefined cmpQualityFactorPredefined;

@property (nonatomic, assign) NSInteger qualityFactor;
@property (nonatomic, assign) NSInteger passes;

@property (nonatomic, assign) NSUInteger stampWidth;
@property (nonatomic, assign) NSUInteger stampHeight;
@property (nonatomic, assign) NSUInteger stampBitsPerPixel;

@property (nonatomic, assign) BOOL yccStamp;
@property (nonatomic, assign) BOOL jpegStamp;
@property (nonatomic, assign) BOOL saveWithStamp;
@property (nonatomic, assign) BOOL fixedPaletteStamp;
@property (nonatomic, assign) BOOL saveWithoutTimestamp;
@property (nonatomic, assign) BOOL saveOldJtif;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpegOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsJpegLoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsJpegSaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
