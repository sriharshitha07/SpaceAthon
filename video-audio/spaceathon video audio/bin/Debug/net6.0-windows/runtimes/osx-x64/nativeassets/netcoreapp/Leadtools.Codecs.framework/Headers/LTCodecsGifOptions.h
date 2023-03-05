// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsGifOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsGifLoadOptions : NSObject

@property (nonatomic, assign) NSUInteger animationLoop;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsGifSaveOptions : NSObject

@property (nonatomic, assign, getter=usesAnimationPalette)    BOOL useAnimationPalette;
@property (nonatomic, assign, getter=usesAnimationLoop)       BOOL useAnimationLoop;
@property (nonatomic, assign, getter=usesAnimationBackground) BOOL useAnimationBackground;

@property (nonatomic, assign)           BOOL interlaced;

@property (nonatomic, strong, nullable) NSArray<LTRasterColor *> *animationPalette;

@property (nonatomic, assign)           NSUInteger animationLoop;
@property (nonatomic, assign)           NSInteger animationWidth;
@property (nonatomic, assign)           NSInteger animationHeight;

@property (nonatomic, copy)             LTRasterColor *animationBackground;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsGifOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsGifLoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsGifSaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
