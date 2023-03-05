// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTChangeViewPerspectiveCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Rotates and flips the image data as necessary to achieve the desired view perspective.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTChangeViewPerspectiveCommand : LTRasterCommand

/** @brief Determines whether or not the soure image is converted in place (or a new image is created). */
@property (nonatomic, assign)                     BOOL inPlace;

/** @brief The desired view perspective */
@property (nonatomic, assign)                     LTRasterViewPerspective viewPerspective;

/** @brief The resulting image, if @p inPlace is set to YES. */
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;


/**
 @brief Initializes a new LTChangeViewPerspectiveCommand object with the specified values.
 
 @param inPlace YES to convert the source image in place (no copy will be made). NO to leave the source image unchanged and place the result in the @p destinationImage property.
 @param viewPerspective The desired view perspective.
 
 @returns A LTRasterMarkerMetadata object initialized with the specified values.
 */
- (instancetype)initWithInPlace:(BOOL)inPlace viewPerspective:(LTRasterViewPerspective)viewPerspective NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
