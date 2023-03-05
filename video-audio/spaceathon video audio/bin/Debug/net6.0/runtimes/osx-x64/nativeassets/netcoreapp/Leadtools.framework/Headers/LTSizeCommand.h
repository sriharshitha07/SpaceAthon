// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSizeCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Resizes an image to a new width and height.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSizeCommand : LTRasterCommand

/** @brief The new image width in pixels. */
@property (nonatomic, assign) NSInteger width;

/** @brief The new image height in pixels. */
@property (nonatomic, assign) NSInteger height;

/** @brief The flags that control the behavior when resizing the image. */
@property (nonatomic, assign) LTRasterSizeFlags flags;


/**
 @brief Initializes a new LTSizeCommand with explicit parameters.
 
 @param width The new image width in pixels.
 @param height The new image height in pixels.
 @param flags The flags that control the behavior when resizing the image.
 
 @returns A LTSizeCommand object initialized with specific values.
 */
- (instancetype)initWithWidth:(NSInteger)width height:(NSInteger)height flags:(LTRasterSizeFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
