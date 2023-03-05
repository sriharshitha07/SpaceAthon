// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterImageMemoryInformation.h
//  Leadtools
//

#import <Leadtools/LTLeadtoolsDefines.h>

typedef NS_OPTIONS(NSUInteger, LTRasterImageInformationFlags) {
    LTRasterImageInformationFlagNone              = 0x0000,
    LTRasterImageInformationFlagMemory            = 0x0001,
    LTRasterImageInformationFlagTileSize          = 0x0002,
    LTRasterImageInformationFlagTotalTiles        = 0x0004,
    LTRasterImageInformationFlagConventionalTiles = 0x0008,
    LTRasterImageInformationFlagMaximumTileViews  = 0x0010,
    LTRasterImageInformationFlagTileViews         = 0x0020
};

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Stores information about the memory allocated for the @p LTRasterImage's data.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImageMemoryInformation : NSObject <NSCopying, NSSecureCoding>

/** @brief Creates a new instance of the LTRasterImageMemoryInformation class with all members set to 0. */
@property (class, nonatomic, strong, readonly) LTRasterImageMemoryInformation *defaultInformation NS_SWIFT_NAME(default);


/** @brief Gets or sets type of memory allocated for the image data. */
@property (nonatomic, assign) LTRasterMemoryFlags memoryFlags;

/** @brief Gets or sets a value that specify which members of this instance are valid when calling -[LTRasterImage setMemoryInformation:]. */
@property (nonatomic, assign) LTRasterImageInformationFlags flags;


/** @brief Gets or sets the size for the tile */
@property (nonatomic, assign) NSUInteger tileSize;

/** @brief Gets or sets the number of tiles. */
@property (nonatomic, assign) NSUInteger totalTiles;

/** @brief Gets or sets the number of conventional tiles. */
@property (nonatomic, assign) NSUInteger conventionalTiles;

/** @brief Gets or sets maximum number of swap buffers for the disk tiles. */
@property (nonatomic, assign) NSUInteger maximumTileViews;

/** @brief Gets or sets the number of swap buffers for the disk tiles. */
@property (nonatomic, assign) NSUInteger tileViews;

@end

NS_ASSUME_NONNULL_END
