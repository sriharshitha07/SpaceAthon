// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSetAlphaValuesCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Fills the image alpha values, while preserving the other image components.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSetAlphaValuesCommand : LTRasterCommand

/** @brief The alpha component value. */
@property (nonatomic, assign) NSUInteger alpha;


/**
 @brief Initializes a new LTSetAlphaValuesCommand with explicit parameters.
 
 @param alpha The alpha value to set.
 
 @returns A LTSetAlphaValuesCommand object initialized with specific values.
 */
- (instancetype)initWithAlpha:(NSUInteger)alpha NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
