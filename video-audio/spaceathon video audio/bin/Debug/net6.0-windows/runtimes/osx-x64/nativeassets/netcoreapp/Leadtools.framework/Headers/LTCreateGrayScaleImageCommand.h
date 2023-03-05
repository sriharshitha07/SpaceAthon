// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCreateGrayScaleImageCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Converts a 1-, 4-, 8-, 16-, 24-, or 32-bit LTRasterImage to an 8-bit, 12-bit, or 16-bit grayscale image.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCreateGrayScaleImageCommand : LTRasterCommand

/** @brief The number of bits for the destination image. */
@property (nonatomic, assign)                     NSInteger bitsPerPixel;

/** @brief The low bit used for window leveling when the @p bitsPerPixel is 12 or 16. */
@property (nonatomic, assign)                     NSInteger lowBit;

/** @brief The high bit used for window leveling when the @p bitsPerPixel is 12 or 16. */
@property (nonatomic, assign)                     NSInteger highBit;

/** @brief The resulting image. */
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;


/**
 @brief Initializes a new LTCreateGrayScaleImageCommand with explicit parameters.
 
 @param bitsPerPixel A value that indicates the number of bits for the destination image. Valid values are 8, 12, or 16.
 @param low A value that indicates the low bit used for window leveling when the @p bitsPerPixel is 12 or 16.
 @param high A value that indicates the high bit used for window leveling when the @p bitsPerPixel is 12 or 16.
 
 @returns A LTCreateGrayScaleImageCommand object initialized with specific values.
 */
- (instancetype)initWithBitsPerPixel:(NSInteger)bitsPerPixel lowBit:(NSInteger)low highBit:(NSInteger)high NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
