// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTGrayscaleCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Converts a 1-, 4-, 8-, 16-, 24-, or 32-bit image to an 8-bit, 12-bit, or 16-bit grayscale image.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTGrayscaleCommand : LTRasterCommand

/** @brief A value indicated the number of bits in the destination image. Valid values are 8, 12, or 16. */
@property (nonatomic, assign) NSInteger bitsPerPixel;


/**
 @brief Initializes a new LTGrayscaleCommand with explicit parameters.
 
 @param bitsPerPixel A value indicating the number of bits in the destination image. Valid values are 8, 12, or 16.
 
 @returns A LTGrayscaleCommand object initialized with specific values.
 */
- (instancetype)initWithBitsPerPixel:(NSInteger)bitsPerPixel NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
