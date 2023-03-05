// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCombineWarpCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTCombineWarpCommandFlags) {
    LTCombineWarpCommandFlagsNone        = 0,
    LTCombineWarpCommandFlagsBilinear    = 0x0001,
    LTCombineWarpCommandFlagsReserved1   = 0x0002,
    LTCombineWarpCommandFlagsReserved2   = 0x0004,
    LTCombineWarpCommandFlagsReserved3   = 0x0008,
    LTCombineWarpCommandFlagsReserved4   = 0x0010,
    LTCombineWarpCommandFlagsReserved5   = 0x0020,
    LTCombineWarpCommandFlagsReserved6   = 0x0040,
    LTCombineWarpCommandFlagsReserved7   = 0x0080,
    LTCombineWarpCommandFlagsReserved8   = 0x0100,
    LTCombineWarpCommandFlagsReserved9   = 0x0200
} NS_SWIFT_NAME(LTCombineWarpCommand.Flags);

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Combines image data from the source image (the slave) and the destination image (the master), using a perspective warp.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCombineWarpCommand : LTRasterCommand

/** @brief The destination image. */
@property (nonatomic, strong, nullable) LTRasterImage *destinationImage;

/** @brief The area of the source image to be warped. */
@property (nonatomic, assign)           LeadRect sourceRectangle;

/** @brief The flags that indicate the type of interpolation to use, if interpolation is used. */
@property (nonatomic, assign)           LTCombineWarpCommandFlags flags;

/** @brief An array that contains the four points that define the warp area in the destination image. */
@property (nonatomic, assign)           LeadPoint *destinationPoints;


/**
 @brief Initializes a new LTCombineWarpCommand with explicit parameters.
 
 @param destinationImage The destination image for the command.
 @param destinationPoints An array that contains the four points that define the warp area in the destination image.
 @param sourceRectangle Define the area of the source image to be warped.
 @param flags Flags that indicate the type of interpolation to use, if interpolation is used.
 
 @returns A LTCombineWarpCommand object initialized with specific values.
 */
- (instancetype)initWithDestinationImage:(LTRasterImage *)destinationImage destinationPoints:(const LeadPoint[__nonnull 4])destinationPoints sourceRectangle:(LeadRect)sourceRectangle flags:(LTCombineWarpCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
