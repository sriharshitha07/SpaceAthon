// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterDefaults.h
//  Leadtools
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTErrorCode.h>
#import <Leadtools/LTLeadStream.h>
#import <Leadtools/LTLeadtools.h>

typedef NS_ENUM(NSInteger, LTLEADResourceDirectory) {
    LTLEADResourceDirectoryLibraries,
    LTLEADResourceDirectoryFonts,
};

LT_ENUM_AVAILABLE(10_10, 8_0, 20_0)
typedef NS_ENUM(NSInteger, LTDrawEngineType) {
    LTDrawEngineTypeDefaultEngine,
    LTDrawEngineTypeMultiplatform,
};

LT_ENUM_AVAILABLE(10_10, 8_0, 20_0)
typedef NS_ENUM(NSInteger, LTDrawShadowFontMode) {
    LTDrawShadowFontModeAuto,
    LTDrawShadowFontModeSystemFirst,
    LTDrawShadowFontModeShadowFirst
};

LT_ENUM_AVAILABLE(10_10, 8_0, 20_0)
typedef NS_ENUM(NSInteger, LTLEADTempFileMode) {
    LTLEADTempFileModeAuto,
    LTLEADTempFileModeDisk,
    LTLEADTempFileModeDiskAndMemory,
    LTLEADTempFileModeMemory
};

LT_ENUM_AVAILABLE(10_10, 8_0, 20_0)
typedef NS_ENUM(NSInteger, LTAutoFixImageResolutionUnit) {
   LTAutoFixImageResolutionUnitInch         = 1,
   LTAutoFixImageResolutionUnitMillimeter   = 2
};

NS_ASSUME_NONNULL_BEGIN

/// Provides data for the @p LTRasterImageAllocateCallback
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImageAllocateData : NSObject <NSCopying, NSSecureCoding>

/// Gets of sets the memory model flags being used to create the @p LTRasterImage object.
@property (nonatomic, assign)                   LTRasterMemoryFlags memoryFlags;

/// Gets the view perspective of the @p LTRasterImage object being created.
@property (nonatomic, assign, readonly)         LTRasterViewPerspective viewPerspective;

/// Gets the bytes order of the @p LTRasterImage object being created.
@property (nonatomic, assign, readonly)         LTRasterByteOrder order;


/// Gets the width of the @p LTRasterImage object being created in pixels.
@property (nonatomic, assign, readonly)         NSInteger width;

/// Gets the height of the @p LTRasterImage object being created in pixels.
@property (nonatomic, assign, readonly)         NSInteger height;

/// Gets the bits per pxiel of the @p LTRasterImage object being created.
@property (nonatomic, assign, readonly)         NSInteger bitsPerPixel;

/// Gets the bytes per line of the @p LTRasterImage object being created.
@property (nonatomic, assign, readonly)         NSInteger bytesPerLine;

/// Gets the size of the data required by the @p LTRasterImage object being created in bytes.
@property (nonatomic, assign, readonly)         uint64_t size;


/// Gets the palette of the @p LTRasterImage object being created.
@property (nonatomic, copy, readonly, nullable) NSArray<LTRasterColor *> *palette;

- (instancetype)init __unavailable;

@end



/// Holds the memory restrictions used when allocating new @p LTRasterImage objects.
LT_CLASS_AVAILABLE(10_10, 8_0, 20_0)
@interface LTRasterMemoryThreshold : NSObject <NSCopying, NSSecureCoding>

@property (class, nonatomic, strong, readonly) LTRasterMemoryThreshold *defaultThreshold NS_SWIFT_NAME(default);

/// Gets or sets a value that specifies the maximum size allowed for all @p LTRasterImage object allocations.
@property (nonatomic, assign)                  NSInteger maximumGlobalRasterImageMemory;

/// Gets or sets a value that specifies the maximum size for a conventional image (default is 0x7FFFFFFF).
@property (nonatomic, assign)                  NSInteger maximumConventionalSize;

/// Gets or sets a value that specifies the number of buffers in conventional memory that will cache the disk tiles.
@property (nonatomic, assign)                  NSInteger conventionalBuffers;

/// Gets or sets a value that specifies the maximum number of tiles that will reside in conventional memory at any time.
@property (nonatomic, assign)                  NSInteger conventionalTiles;

/// Gets or sets a value that specifies the minimum amount of free memory required to allow the allocation of conventional images.
@property (nonatomic, assign)                  NSInteger tiledThreshold;

/// Gets or sets a value that specifies the size for a size of the tile for tiled images.
@property (nonatomic, assign)                  NSInteger tileSize;

@end



/// Holds conventional memory restrictions used when allocating new @p LTRasterImage objects.
LT_CLASS_AVAILABLE(10_10, 8_0, 20_0)
@interface LTGlobalMemoryThresholds : NSObject <NSCopying, NSSecureCoding>

@property (class, nonatomic, strong, readonly) LTGlobalMemoryThresholds *defaultThresholds NS_SWIFT_NAME(default);

/// Maximum size of continuous conventional memory in bytes to use when creating a @p LTRasterImage object.
@property (nonatomic, assign)                  NSInteger maximumConventionalMemory;

@end



/**
 @brief Callback to use when new @p LTRasterImage objects are created by LEADTOOLS
 
 @param data The allocate data that is being used to create the @p LTRasterImage object
 
 @returns LTErrorSuccess to continue creating the @p LTRasterImage object, any other value will cause the toolkit to return from the calling method with an @p NSError object whose code is equal to the value returned from this callback.
 */
typedef LTErrorCode (^LTRasterImageAllocateCallback)(LTRasterImageAllocateData *data);


/// Provides the information needed to automatically convert the resolution of digital photos.
LT_CLASS_AVAILABLE(10_10, 8_0, 20_0)
@interface LTAutoFixImageResolutionOptions : NSObject <NSCopying, NSSecureCoding>

/// Specifies the minimum resolution acceptable for digital photos.
@property (nonatomic, assign) NSInteger minResolution;

/// The desired page width for the bitmaps that will be changed.
@property (nonatomic, assign) double pageWidth;

/// The desired page height for the bitmaps that will be changed.
@property (nonatomic, assign) double pageHeight;

/// Units to use for the page size.
@property (nonatomic, assign) LTAutoFixImageResolutionUnit unit;

@end

/// Specifies the default extra values used when creating @p LTRasterImage objects.
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterDefaults : NSObject

/// Gets or sets the horizontal resolution used when creating new @p LTRasterImage objects.
@property (class, nonatomic, assign) NSInteger xResolution;

/// Gets or sets the vertical resolution used when creating new @p LTRasterImage objects.
@property (class, nonatomic, assign) NSInteger yResolution;

/// Gets or sets the default dithering method to use when converting an image from 64, 48, 32, 24, or 16 bits per pixel to 8 bits per pixel or fewer.
@property (class, nonatomic, assign) LTRasterDitheringMethod ditheringMethod;

/// Gets or sets a value that specifies the type of memory to use when creating new @p LTRasterImage objects.
@property (class, nonatomic, assign) LTRasterMemoryFlags memoryFlags LT_AVAILABLE(10_10, 8_0, 20_0);

/// Gets or sets a value that specifies the type of memory to use when creating temporary files.
@property (class, nonatomic, assign) LTLEADTempFileMode tempFileMode LT_AVAILABLE(10_10, 8_0, 20_0);

/// Gets or sets a value that specifies the memory restrictions for allocating new @p LTRasterImage objects.
@property (class, nonatomic, strong) LTRasterMemoryThreshold *memoryThreshold LT_AVAILABLE(10_10, 8_0, 20_0);

/// Gets or sets a value that specifies the directory in which LEADTOOLS will create temporary files when creating disk-based @p LTRasterImage objects.
@property (class, nonatomic, copy, nullable) NSString *temporaryDirectory LT_AVAILABLE(10_10, 8_0, 20_0);

/// Allows the creation of a temporary filename in the LEADTOOLS temporary folder. The caller is responsible for deleting this file
@property (class, nonatomic, copy, readonly) NSString *temporaryFileName LT_AVAILABLE(10_10, 8_0, 20_0);

/// Gets or sets an object that contains the conventional memory restrictions used when allocating new @p LTRasterImage objects.
@property (class, nonatomic, copy, null_resettable) LTGlobalMemoryThresholds *globalMemoryThresholds LT_AVAILABLE(10_10, 8_0, 20_0);

/// Gets or sets the automatic resolution conversion options used by LEADTOOLS to automatically convert the resolution of digital photos.
@property (class, nonatomic, copy, null_resettable) LTAutoFixImageResolutionOptions *autoFixImageResolutionOptions LT_AVAILABLE(10_10, 8_0, 20_0);

/**
 @brief Gets the path for the specified LEADTOOLS resource directory.
 
 @param resource The LEADTOOLS resource directory to get.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The path for the specified LEADTOOLS resource directory upon success, nil otherwise
 */
+ (nullable NSString *)resourceDirectory:(LTLEADResourceDirectory)resource error:(NSError **)error;

/**
 @brief Sets the path for the specified LEADTOOLS resource directory.
 
 @param directory The path for the specified LEADTOOLS resource directory.
 @param resource The resource directory to set.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the path was successfully set, NO otherwise
 */
+ (BOOL)setDirectory:(NSString *)directory forResource:(LTLEADResourceDirectory)resource error:(NSError **)error;

/**
 @brief Sets a global callback to be called whenever the toolkit is creating a new @p LTRasterImage object.
 
 @param callback The callback to be called whenever the toolkit is create a new @p LTRasterImage object. You can pass @p nil to stop the toolkit from calling any callback.
 
 @returns The previous global callback set, or @p nil if no callback was previously set (default).
 */
+ (nullable LTRasterImageAllocateCallback)setRasterImageAllocateCallback:(nullable LTRasterImageAllocateCallback)callback;

/**
@brief Adds user font file.

@param file The path for the font file.
@param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
*/
+ (void)addUserFontFile:(NSString *)file error:(NSError **)error NS_SWIFT_NAME(addUserFont(fileName:));

/**
@brief Adds user font file.

@param stream The font stream data.
@param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
*/
+ (void)addUserFontStream:(LTLeadStream *)stream error:(NSError **)error NS_SWIFT_NAME(addUserFont(stream:));

/*
+ (void)addUserFontData:(NSData *)data error:(NSError **)error NS_SWIFT_NAME(addUserFont(data:));
*/

/**
@brief Adds user font file.

@param data The font file data.
@param range A range that specifies a subset of the data.
@param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
*/
+(void)addUserFontData:(NSData*)data dataRange : (NSRange)range error : (NSError**)error NS_SWIFT_NAME(addUserFont(data:range:));


/**
@brief Clears user fonts.

@param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
*/
+ (void)clearUserFonts:(NSError **)error;
@end



LT_CLASS_AVAILABLE(10_10, 8_0, 20_0)
@interface LTDrawEngineOptions : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, assign) LTDrawEngineType engineType;
@property (nonatomic, assign) LTDrawShadowFontMode shadowFontMode;

@end



LT_CLASS_AVAILABLE(10_10, 8_0, 20_0)
@interface LTDrawEngine : NSObject

@property (class, nonatomic, strong) LTDrawEngineOptions *options;

@end

NS_ASSUME_NONNULL_END
