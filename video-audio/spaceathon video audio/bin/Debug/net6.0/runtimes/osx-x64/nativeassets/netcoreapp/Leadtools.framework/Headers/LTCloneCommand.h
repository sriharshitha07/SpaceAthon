// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCloneCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Creates a copy of a LTRasterImage object.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCloneCommand : LTRasterCommand

/** @brief The flags that control memory allocation for the destination image. */
@property (nonatomic, assign)                     LTRasterMemoryFlags createFlags;

/** @brief A value that indicates whether to clone all the pages if the source image is multi-page. */
@property (nonatomic, assign)                     BOOL allPages;

/** @brief The source image used in this LTCloneCommand. */
@property (nonatomic, strong, readonly, nullable) LTRasterImage *sourceImage;

/** @brief The resulting image of this command. */
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;


/**
 @brief Initializes a new LTCloneCommand with explicit parameters.
 
 @param flags Flags that control memory allocation for the destination image.
 
 @returns A LTCloneCommand object initialized with specific values.
 */
- (instancetype)initWithFlags:(LTRasterMemoryFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
