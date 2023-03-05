// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCopyDataCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Copied image data from one image to another.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCopyDataCommand : LTRasterCommand

/** @brief The destination image. */
@property (nonatomic, strong, nullable) LTRasterImage *destinationImage;


/**
 @brief Initializes a new LTCopyDataCommand with explicit parameters.
 
 @param destinationImage The destination image for the command.
 
 @returns A LTCopyDataCommand object initialized with specific values.
 */
- (instancetype)initWithDestinationImage:(LTRasterImage *)destinationImage NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
