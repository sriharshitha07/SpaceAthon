// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTColorResolutionCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, LTColorResolutionCommandMode) {
    LTColorResolutionCommandModeInPlace,
    LTColorResolutionCommandModeCreateDestinationImage,
    LTColorResolutionCommandModeOnlyData,
    LTColorResolutionCommandModeAllPages
} NS_SWIFT_NAME(LTColorResolutionCommand.Mode);

typedef NS_OPTIONS(NSUInteger, LTColorResolutionCommandPaletteFlags) {
    LTColorResolutionCommandPaletteFlagsNone              = 0,
    LTColorResolutionCommandPaletteFlagsFixed             = 0x00000001,
    LTColorResolutionCommandPaletteFlagsOptimized         = 0x00000002,
    LTColorResolutionCommandPaletteFlagsIdentity          = 0x00000008,
    LTColorResolutionCommandPaletteFlagsUsePalette        = 0x00000010,
    LTColorResolutionCommandPaletteFlagsFastMatch         = 0x00000020,
    LTColorResolutionCommandPaletteFlagsNetscape          = 0x00000040,
    LTColorResolutionCommandPaletteFlagsSlowMatch         = 0x00000200,
    LTColorResolutionCommandPaletteFlagsFavorPureColors   = 0x00000400
} NS_SWIFT_NAME(LTColorResolutionCommand.PaletteFlags);

typedef void (^LTColorResolutionCommandDataEvent)(LTRasterImage * _Nullable image, NSInteger lines, NSData *data, BOOL *cancel) NS_SWIFT_NAME(LTColorResolutionCommand.DataEvent);

/**
 @brief Converts an image from any bits-per-pixel to any bits-per-pixel.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTColorResolutionCommand : LTRasterCommand

/** @brief The resulting image. */
@property (nonatomic, strong, readonly, nullable) LTRasterImage *destinationImage;

/** @brief The behavior of the command. */
@property (nonatomic, assign)                     LTColorResolutionCommandMode mode;

/** @brief The number of bits per pixel for the conversion. */
@property (nonatomic, assign)                     NSInteger bitsPerPixel;

/** @brief The desired color order for the conversion. */
@property (nonatomic, assign)                     LTRasterByteOrder order;

/** @brief The dithering options used when converting the image. */
@property (nonatomic, assign)                     LTRasterDitheringMethod ditheringMethod;

/** @brief The palette options used when converting the image. */
@property (nonatomic, assign)                     LTColorResolutionCommandPaletteFlags paletteFlags;

/** @brief The custom palette to use when converting the image. */
@property (nonatomic, copy, nullable)             NSArray<LTRasterColor *> *palette;

/** @brief The number of colors to use in the palette. */
@property (nonatomic, assign)                     NSUInteger colors;

/** @brief A value that indicates whether to initialize the alpha channel values when converting to 32 or 64-bit images. */
@property (nonatomic, assign)                     BOOL initAlpha;

/**
 @brief Initializes a new LTColorResolutionCommand object with explicit parameters.
 
 @param mode Flags which control the behavior of the command.
 @param bitsPerPixel The number of bits per pixel to use for the conversion. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 12, 16, 24, 32, 48 and 64.
 @param order The desired color order for the conversion.
 @param ditheringMethod Dithering options, useful only when the resulting image requires a palette (when it is 8 bits per pixel or less).
 @param paletteFlags Palette options, useful only when the resulting image requires a palette (when it is 8 bits per pixel or less).
 @param palette The palette used when converting the image if @p paletteFlags includes the LTColorResolutionCommandPaletteFlagsUsePalette flag.
 
 @returns A LTColorResolutionCommand object initialized with specific values.
 */
- (instancetype)initWithMode:(LTColorResolutionCommandMode)mode bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order ditheringMethod:(LTRasterDitheringMethod)ditheringMethod paletteFlags:(LTColorResolutionCommandPaletteFlags)paletteFlags palette:(nullable NSArray<LTRasterColor *> *)palette NS_DESIGNATED_INITIALIZER;



/**
 @brief Runs the image processing command.
 
 @param image The image on which the image processing command should be performed.
 @param progressHandler A block that is used for progress updates.
 @param dataEventHandler A block that is used for data updates.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the image processing command completed successfully, otherwise NO.
 */
- (BOOL)run:(LTRasterImage *)image progress:(nullable NS_NOESCAPE LTRasterCommandProgress)progressHandler dataEvent:(nullable LTColorResolutionCommandDataEvent)dataEventHandler error:(NSError **)error;

@end



@protocol LTColorResolutionCommandDataDelegate;

@interface LTColorResolutionCommand (Deprecated)

@property (nonatomic, weak, nullable) id<LTColorResolutionCommandDataDelegate> dataDelegate LT_DEPRECATED_USENEW(19_0, "run:progress:dataEvent:error:");

@end

NS_ASSUME_NONNULL_END
