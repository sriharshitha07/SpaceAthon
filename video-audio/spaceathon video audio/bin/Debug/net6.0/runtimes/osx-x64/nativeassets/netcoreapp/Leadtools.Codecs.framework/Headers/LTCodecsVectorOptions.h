// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsVectorOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterColor.h>

typedef NS_ENUM(NSInteger, LTCodecsVectorViewMode) {
    LTCodecsVectorViewModeUseBest,
    LTCodecsVectorViewModeUseWidthAndHeight,
    LTCodecsVectorViewModeUseWidth,
    LTCodecsVectorViewModeUseHeight
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsVectorLoadOptions : NSObject

@property (nonatomic, assign) NSInteger viewWidth;
@property (nonatomic, assign) NSInteger viewHeight;
@property (nonatomic, assign) NSInteger bitsPerPixel;

@property (nonatomic, assign) LTCodecsVectorViewMode viewMode;

@property (nonatomic, assign) BOOL forceBackgroundColor;
@property (nonatomic, copy)   LTRasterColor *backgroundColor;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsVectorOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsVectorLoadOptions *load;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
