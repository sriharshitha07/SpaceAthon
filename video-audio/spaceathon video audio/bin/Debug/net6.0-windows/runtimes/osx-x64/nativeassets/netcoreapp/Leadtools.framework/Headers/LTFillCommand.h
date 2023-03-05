// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTFillCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Fills the specified image with the specified color.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTFillCommand : LTRasterCommand

/** The fill color. */
@property (nonatomic, copy, nonnull) LTRasterColor *color;


/**
 @brief Initializes a new LTFillCommand with explicit parameters.
 
 @param color The fill color.
 
 @returns A LTFillCommand object initialized with specific values.
 */
- (instancetype)initWithColor:(LTRasterColor *)color NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
