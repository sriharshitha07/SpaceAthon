// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRotateCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTRotateCommandFlags) {
    LTRotateCommandFlagsNone     = 0,
    LTRotateCommandFlagsResize   = 0x0001,
    LTRotateCommandFlagsResample = 0x0002,
    LTRotateCommandFlagsBicubic  = 0x0004
} NS_SWIFT_NAME(LTRotateCommand.Flags);

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Rotates an image by the number of degrees specified.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRotateCommand : LTRasterCommand

/** @brief The rotation angle. */
@property (nonatomic, assign) NSInteger angle;

/** @brief The flags to keep the resulting image the same size as the original image or to resize according to the rotation direction specified. */
@property (nonatomic, assign) LTRotateCommandFlags flags;

/** @brief The background fill color. */
@property (nonatomic, copy)   LTRasterColor *fillColor;


/**
 @brief Initializes a new LTRotateCommand with explicit parameters.
 
 @param angle Hundredths of degrees to rotate (+/-). This can be a number from 1 to 36,000. A positive value will rotate the image in a clockwise direction, while a negative value will rotate the image in a counter-clockwise direction.
 @param flags Flags to keep the resulting image the same size as the original image or to resize according to the rotation direction specified.
 @param fillColor The background fill color.
 
 @returns A LTRotateCommand object initialized with specific values.
 */
- (instancetype)initWithAngle:(NSInteger)angle flags:(LTRotateCommandFlags)flags fillColor:(LTRasterColor *)fillColor NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
