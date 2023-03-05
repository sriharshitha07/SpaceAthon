// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsAbcOptions.h
//  Leadtools.Codecs
//

typedef NS_ENUM(NSInteger, LTCodecsAbcQualityFactor) {
    LTCodecsAbcQualityFactorLossless = 0,
    LTCodecsAbcQualityFactorVirtualLossless,
    LTCodecsAbcQualityFactorRemoveBorder,
    LTCodecsAbcQualityFactorEnhance,
    LTCodecsAbcQualityFactorModified1,
    LTCodecsAbcQualityFactorModified1Fast,
    LTCodecsAbcQualityFactorModified2,
    LTCodecsAbcQualityFactorModified2Fast,
    LTCodecsAbcQualityFactorModified3,
    LTCodecsAbcQualityFactorModified3Fast,
    LTCodecsAbcQualityFactorLosslessFast,
    LTCodecsAbcQualityFactorLossyFast
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsAbcLoadOptions : NSObject

@property (nonatomic, assign) BOOL fastLoad;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsAbcSaveOptions : NSObject

@property (nonatomic, assign) LTCodecsAbcQualityFactor qualityFactor;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsAbcOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsAbcLoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsAbcSaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
