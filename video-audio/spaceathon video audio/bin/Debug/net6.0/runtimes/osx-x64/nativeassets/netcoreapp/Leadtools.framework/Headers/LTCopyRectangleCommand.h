// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCopyRectangleCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Copies a portion of an image to create another image that is the size of the rectangle that you specify.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCopyRectangleCommand : LTRasterCommand

/** @brief The flags that control memory allocation for the destination image. */
@property (nonatomic, assign)                     LTRasterMemoryFlags createFlags;

/** @brief The rectangle area to copy (in pixels). */
@property (nonatomic, assign)                     LeadRect rectangle;

/** @brief The resulting image. */
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;


/**
 @brief Initializes a new LTCopyRectangleCommand with explicit parameters.
 
 @param rect The rectangle to copy (in pixels).
 @param flags Flags that control memory allocation for the destination image.
 
 @returns A LTCopyRectangleCommand object initialized with specific values.
 */
- (instancetype)initWithRectangle:(LeadRect)rect flags:(LTRasterMemoryFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
