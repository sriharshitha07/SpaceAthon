// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTResizeCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Resizes the image from an existing image, and puts the resized image into a destination image, leaving the original image intact.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTResizeCommand : LTRasterCommand

/** @brief The destination image for the resize. */
@property (nonatomic, strong, nullable) LTRasterImage *destinationImage;

/** @brief Flags that determine resizing options. */
@property (nonatomic, assign)           LTRasterSizeFlags flags;


/**
 @brief Initializes a new LTResizeCommand with explicit parameters.
 
 @param dstImage The destination image for the resize.
 @param flags Flags that determine resizing options.
 
 @returns A LTResizeCommand object initialized with specific values.
 */
- (instancetype)initWithDestinationImage:(LTRasterImage *)dstImage flags:(LTRasterSizeFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
