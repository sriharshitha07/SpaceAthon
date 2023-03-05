// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterImageAnimator.h
//  Leadtools
//

#import <Leadtools/LTRasterImage.h>

typedef NS_ENUM(NSInteger, LTRasterImageAnimatorState) {
    LTRasterImageAnimatorStatePreClear       = 0x0000,
    LTRasterImageAnimatorStatePostClear      = 0x0001,
    LTRasterImageAnimatorStatePreRender      = 0x0002,
    LTRasterImageAnimatorStateRender         = 0x0003,
    LTRasterImageAnimatorStatePostRender     = 0x0004,
    LTRasterImageAnimatorStateWaitInput      = 0x0005,
    LTRasterImageAnimatorStateWaitDelay      = 0x0006,
    LTRasterImageAnimatorStateWaitInputDelay = 0x0007,
    LTRasterImageAnimatorStatePreDispose     = 0x0008,
    LTRasterImageAnimatorStatePostDispose    = 0x0009,
    LTRasterImageAnimatorStateEnd            = 0x000A
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImageAnimator : NSObject

@property (nonatomic, assign)           NSInteger index;
@property (nonatomic, assign, readonly) NSUInteger delay;

@property (nonatomic, assign, readonly) LTRasterImageAnimatorState state;

- (nullable instancetype)initWithTargetImage:(LTRasterImage *)targetImage animatedImage:(LTRasterImage *)animatedImage error:(NSError **)error;
- (instancetype)init NS_UNAVAILABLE;

- (nullable LTRasterImage *)destroy:(NSError **)error;
- (BOOL)append:(LTRasterImage *)image error:(NSError **)error;

- (BOOL)cancelWait:(NSError **)error;
- (BOOL)clearUpdateRectangle:(NSError **)error;
- (BOOL)validateLines:(NSInteger)lines row:(NSInteger)row error:(NSError **)error;

- (LeadRect)getUpdateRectangle:(BOOL)clear error:(NSError **)error NS_SWIFT_NAME(getUpdateRectangle(clear:));
- (LTRasterImageAnimatorState)process:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
