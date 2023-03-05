// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFlipCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Flips a LTRasterImage from top to bottom or from left to right.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFlipCommand : LTRasterCommand

/** @brief Specifies whether the image is to be flipped horizontally or vertically. */
@property (nonatomic, assign) BOOL horizontal;


/**
 @brief Initializes a new LTFlipCommand with explicit parameters.
 
 @param horizontal YES to flip horizontally (left to right), NO to flip vertically (top to bottom).
 
 @returns A LTFlipCommand object initialized with specific values.
 */
- (instancetype)initWithHorizontal:(BOOL)horizontal NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
