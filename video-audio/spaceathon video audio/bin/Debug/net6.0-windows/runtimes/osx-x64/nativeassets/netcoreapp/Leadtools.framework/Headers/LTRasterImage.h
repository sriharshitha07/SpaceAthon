// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterImage.h
//  Leadtools
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTRasterColor16.h>
#import <Leadtools/LTRasterHsvColor.h>
#import <Leadtools/LTRasterRegion.h>
#import <Leadtools/LTRasterMetadata.h>
#import <Leadtools/LTRasterCommentMetadata.h>
#import <Leadtools/LTRasterTagMetadata.h>
#import <Leadtools/LTRasterMarkerMetadata.h>
#import <Leadtools/LTRasterOverlayAttributes.h>
#import <Leadtools/LTRasterImageDataCallbacks.h>
#import <Leadtools/LTRasterImageMemoryInformation.h>
#import <Leadtools/LTHandle.h>

#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

/** @brief LTRasterImage Changed notification */
LEADTOOLS_EXPORT NSNotificationName const LTRasterImageDidChangeNotification;
/** @brief NSDictionary key. Value: NSNumber (LTRasterImageChangedFlags) */
LEADTOOLS_EXPORT NSString * const LTRasterImageChangedNotificationFlags;

LEADTOOLS_EXPORT NSString * const LTRasterImageChangedNotification LT_DEPRECATED_USENEW(19_0, "LTRasterImageDidChangeNotification");
LEADTOOLS_EXPORT NSString * const LTRasterImageChangedNotification_flags LT_DEPRECATED_USENEW(19_0, "LTRasterImageChangedNotificationFlags");

typedef NS_ENUM(NSInteger, LTRasterImagePagesChangedAction) {
    LTRasterImagePagesChangedActionAdded,
    LTRasterImagePagesChangedActionRemoved,
    LTRasterImagePagesChangedActionInserted
};

/** @brief The @p LTRasterImage PagesChanged notification. */
LEADTOOLS_EXPORT NSNotificationName const LTRasterImagePagesDidChangeNotification;
/** @brief NSDictionary key. Value: NSNumber(LTRasterImagePagesChangedAction) */
LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotificationAction;
/** @brief NSDictionary key. Value: NSNumber(NSUInteger) */
LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotificationStartIndex;
/** @brief NSDictionary key. Value: NSNumber(NSUInteger) */
LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotificationCount;

LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotification LT_DEPRECATED_USENEW(19_0, "LTRasterImagePagesDidChangeNotification");
LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotification_action LT_DEPRECATED_USENEW(19_0, "LTRasterImagePagesChangedNotificationAction");
LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotification_startIndex LT_DEPRECATED_USENEW(19_0, "LTRasterImagePagesChangedNotificationStartIndex");
LEADTOOLS_EXPORT NSString * const LTRasterImagePagesChangedNotification_count LT_DEPRECATED_USENEW(19_0, "LTRasterImagePagesChangedNotificationCount");

/** @brief The maximum number of overlays allowed in a @p LTRasterImage. */
LEADTOOLS_EXPORT const NSUInteger LTRasterImageMaxOverlays NS_SWIFT_NAME(LTRasterImage.maxOverlays);

LEADTOOLS_EXPORT const unsigned int LTRasterImage_MaxOverlays LT_DEPRECATED_USENEW(19_0, "LTRasterImageMaxOverlays");


/**
 @brief The LTRasterImage class serves as a working area for image manipluation and conversion. LEADTOOLS functions use this class for accessing the image in memory and for maintaining the characteristics fo the image.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImage : NSObject <NSCopying, NSSecureCoding>

/** @brief The width of this @p LTRasterImage in pixels. */
@property (nonatomic, assign, readonly)           NSInteger width;

/** @brief The height of this @p LTRasterImage in pixels. */
@property (nonatomic, assign, readonly)           NSInteger height;

/** @brief The width of this @p LTRasterImage in pixels, taking the @p viewPerspective into account. */
@property (nonatomic, assign, readonly)           NSInteger imageWidth;

/** @brief The height of this @p LTRasterImage in pixels, taking the @p viewPerspective into account. */
@property (nonatomic, assign, readonly)           NSInteger imageHeight;

/** @brief The size, in pixels, of this @p LTRasterImage object. */
@property (nonatomic, assign, readonly)           LeadSize   imageSize;


/** @brief The number of bits per pixel of this @p LTRasterImage. */
@property (nonatomic, assign, readonly)           NSInteger bitsPerPixel;

/** @brief The number of bytes per scanline for this image data of this @p LTRasterImage. */
@property (nonatomic, assign, readonly)           NSUInteger bytesPerLine;

/** @brief The view perspective of the image data of this @p LTRasterImage. */
@property (nonatomic, assign)                     LTRasterViewPerspective viewPerspective;

/** @brief The color order of this @p LTRasterImage. */
@property (nonatomic, assign)                     LTRasterByteOrder order;

/** @brief The image horizontal resolution, in dots per inch (DPI). */
@property (nonatomic, assign)                     NSInteger xResolution;

/** @brief The image vertical resolution, in dots per inch (DPI). */
@property (nonatomic, assign)                     NSInteger yResolution;


/** @brief The image window level low bit value. */
@property (nonatomic, assign)                     NSInteger lowBit;

/** @brief The image window level high bit value. */
@property (nonatomic, assign)                     NSInteger highBit;

/** @brief The image's minimum grayscale value. */
@property (nonatomic, assign)                     NSInteger minValue;

/** @brief The image's maximum grayscale value. */
@property (nonatomic, assign)                     NSInteger maxValue;


/** @brief The image paint low bit value. */
@property (nonatomic, assign)                     NSInteger paintLowBit;

/** @brief The image paint high bit value. */
@property (nonatomic, assign)                     NSInteger paintHighBit;

/** @brief The current contrast value for the image. */
@property (nonatomic, assign)                     NSInteger paintContrast;

/** @brief The current intensity value for the image. */
@property (nonatomic, assign)                     NSInteger paintIntensity;

/** @brief The current gamma correction value for the image. */
@property (nonatomic, assign)                     NSUInteger paintGamma;

/** @brief The transparent color used when painting this image. */
@property (nonatomic, copy)                       LTRasterColor *transparentColor;

/** @brief The default dithering method, referenced by some internal LEADTOOLS methods. */
@property (nonatomic, assign)                     LTRasterDitheringMethod ditheringMethod;


/** @brief The data for the image in native format. */
@property (nonatomic, assign, readonly, nullable) const NSData *data;

/** @brief The size, in bytes, of the image data buffer. */
@property (nonatomic, assign, readonly)           uint64_t dataSize;


/** @brief A dictionary that holds user-added data for the image */
@property (nonatomic, strong, readonly)           NSMutableDictionary<NSString *, id> *customData;


/** @brief A value that indicates if the memory allocated for the image data is conventional memory */
@property (nonatomic, assign, readonly)           BOOL usesConventionalMemory;

/** @brief A value that indicates if the memory allocated for the immage data is allocated as a disk file rather than in physical memory. */
@property (nonatomic, assign, readonly)           BOOL usesDiskMemory;

/** @brief A value that indicates if the memory allocated for the image data is a global handle. */
@property (nonatomic, assign, readonly)           BOOL usesGlobalMemory;

/** @brief Gets or sets information about the memory allocated for the image data. */
@property (nonatomic, copy)                       LTRasterImageMemoryInformation *memoryInformation;

/** @brief Sets information about the memory allocated for the image data with an optional error parameter in case of failure. */
- (BOOL)setMemoryInformation:(LTRasterImageMemoryInformation *)memoryInformation error:(NSError **)error;


/** @brief A value that indicates if the memory allocated for the image data is compressed memory. */
@property (nonatomic, assign, readonly)           BOOL isCompressed;

/** @brief A value that indicates if the memory allocated for the image data is allocated in tiles. */
@property (nonatomic, assign, readonly)           BOOL isTiled;

/** @brief A value that indicates if the memory allocated for the image data is super-compressed memory. */
@property (nonatomic, assign, readonly)           BOOL isSuperCompressed;


/** @brief A value that indicates if the image data is mirrored. */
@property (nonatomic, assign, readonly)           BOOL isMirrored;

/** @brief A value that indicates whether or not to use the transparent color. */
@property (nonatomic, assign)                     BOOL isTransparent;

/** @brief A value that indicates if the image data contains signed values. */
@property (nonatomic, assign)                     BOOL isSignedData;

/** @brief A value that indicates if the image data is basic. */
@property (nonatomic, assign, readonly)           BOOL isBasic;

/** @brief A value that indicates if the image has a rotated @p viewPerspective. */
@property (nonatomic, assign, readonly)           BOOL isRotated;

/** @brief A value that indicates if the image data has a flipped @p viewPerspective. */
@property (nonatomic, assign, readonly)           BOOL isFlipped;

/** @brief A value that indicates if the image data has a grayscale byte order. */
@property (nonatomic, assign, readonly)           BOOL isGray;


/** @brief For internal use by LEADTOOLS. */
@property (nonatomic, assign, readonly, nullable) const void *ditherData;

/** @brief A value that indicates if this @p LTRasterImage is a grayscale image. */
@property (nonatomic, assign, readonly)           LTRasterGrayscaleMode grayscaleMode;


/** @brief Enables or disables clipping the image to the region. */
@property (nonatomic, assign)                     BOOL clipsRegion;

/** @brief Enables or disables automatic handling of premultiplied alpha channel values. */
@property (nonatomic, assign)                     BOOL premultiplyAlpha;

/** @brief The original format of this @p LTRasterImage. */
@property (nonatomic, assign)                     LTRasterImageFormat originalFormat;


/** @brief Enables or disables using the lookup table (LUT) of this @p LTRasterImage. */
@property (nonatomic, assign, getter=usesLookupTable)      BOOL useLookupTable;

/** @brief For internal use by LEADTOOLS. */
@property (nonatomic, assign, getter=usesPaintLookupTable) BOOL usePaintLookupTable;



/**
 @brief Creates a new @p LTRasterImage using the specified parameters.
 
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param resolution The value to be used as the x and y resolution for the image.
 @param backColor The @p LTRasterColor which will be used to fill the new image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
+ (nullable instancetype)coloredImageWithWidth:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel resolution:(NSInteger)resolution backgroundColor:(nullable LTRasterColor *)backColor error:(NSError **)error NS_SWIFT_NAME(coloredImage(width:height:bitsPerPixel:resolution:backgroundColor:));


/**
 @brief Creates a new @p LTRasterImage using the specified parameters.
 
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param resolution The value to be used as the x and y resolution for the image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
+ (nullable instancetype)grayscaleImageWithWidth:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel resolution:(NSInteger)resolution error:(NSError **)error NS_SWIFT_NAME(grayscaleImage(width:height:bitsPerPixel:resolution:));


/**
 @brief Initializes this @p LTRasterImage object using the specified parameters and optional managed memory.
 
 @param flags A combination of the @p LTRasterMemoryFlags enuberation members indicating the type of memory to allocate for the image data.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param order The color order for 16-, 24-, 32-, 48-, and 64-bit images. If thre resultant image is less than 16 bits per pixel, this parameter is ignored.
 @param viewPerspective Specified where the beginning of the image is stored. Most file formats start in the lower left corner while some formats start in the upper left corner.
 @param palette The palette that the image will use. You can specify your own palette, or use nil for LEAD's fixed palette. The palette member is used only when @p bitsPerPixel is less than or equal to 8.
 @param userData The managed data pointer that will contain the image data when @p flags is @p LTRasterMemoryFlagsUser.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithFlags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor*> *)palette userData:(nullable NSData *)userData error:(NSError **)error NS_SWIFT_NAME(init(flags:width:height:bitsPerPixel:order:viewPerspective:palette:userData:));


/**
 @brief Initializes this @p LTRasterImage object using the specified parameters and optional unmanaged memory.
 
 @param flags A combination of the @p LTRasterMemoryFlags enuberation members indicating the type of memory to allocate for the image data.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param order The color order for 16-, 24-, 32-, 48-, and 64-bit images. If thre resultant image is less than 16 bits per pixel, this parameter is ignored.
 @param viewPerspective Specified where the beginning of the image is stored. Most file formats start in the lower left corner while some formats start in the upper left corner.
 @param palette The palette that the image will use. You can specify your own palette, or use nil for LEAD's fixed palette. The palette member is used only when @p bitsPerPixel is less than or equal to 8.
 @param userData The unmanaged data pointer that will contain the image data when @p flags is @p LTRasterMemoryFlagsUser.
 @paarm dataLength The length in bytes of the data passed to @p data. Only used when @p data is not NULL and flags is @p LTRasterMemoryFlagsUser.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithFlags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor *> *)palette userData:(nullable void *)userData userDataLength:(uint64_t)dataLength error:(NSError **)error NS_SWIFT_NAME(init(flags:width:height:bitsPerPixel:order:viewPerspective:userData:userDataLength:palette:));

/**
 @brief Initializes this @p LTRasterImage object using the specified parameters.
 
 @param flags A combination of the @p LTRasterMemoryFlags enuberation members indicating the type of memory to allocate for the image data.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param order The color order for 16-, 24-, 32-, 48-, and 64-bit images. If thre resultant image is less than 16 bits per pixel, this parameter is ignored.
 @param viewPerspective Specified where the beginning of the image is stored. Most file formats start in the lower left corner while some formats start in the upper left corner.
 @param palette The palette that the image will use. You can specify your own palette, or use nil for LEAD's fixed palette. The palette member is used only when @p bitsPerPixel is less than or equal to 8.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithFlags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor *> *)palette error:(NSError **)error;

/**
 @brief Initializes this @p LTRasterImage object using the specified existing @p LTRasterImage object.
 
 @param rasterImage The @p LTRasterImage from which to create the new @p LTRasterImage.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithImage:(LTRasterImage *)rasterImage error:(NSError **)error;


/**
 @brief Creates an exact copy of the current page of this @p LTRasterImage.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The new @p LTRasterImage this method creates.
 */
- (nullable LTRasterImage *)clone:(NSError **)error;

/**
 @brief Creates an exact copy of this @p LTRasterImage.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The new @p LTRasterImage this method creates.
 */
- (nullable LTRasterImage *)cloneAll:(NSError **)error;

/**
 @brief Creates a new @p LTRasterImage object by copying an area of this @p LTRasterImage.
 
 @param rect Specifies the area to copy.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The new @p LTRasterImage this method creates.
 */
- (nullable LTRasterImage *)cloneWithRect:(LeadRect)rect error:(NSError **)error;


/**
 @brief Creates a thumbnail image of this @p LTRasterImage
 
 @param width The desired maximum width of the thumbnail image in pixels.
 @param height The desired maximum height of the thumbnail image in pixels.
 @param bitsPerPixel The desired bits per pixel.
 @param viewPerspective The desired view perspective.
 @param sizeFlags The flags that control the resize operation.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The new @p LTRasterImage that is the thumbnail image.
 */
- (nullable LTRasterImage *)createThumbnailWithWidth:(NSInteger)width thumbnailHeight:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel viewPerspectiveToUse:(LTRasterViewPerspective)viewPerspective sizeFlags:(LTRasterSizeFlags)sizeFlags error:(NSError ** )error NS_SWIFT_NAME(createThumbnail(width:height:bitsPerPixel:viewPerspective:sizeFlags:));


/**
 @brief Gets the width of this @p LTRasterImage in pixels, taking @p viewPerspective and @p xResolution into account.
 
 @param useDpi YES to take into account the resolution (DPI) of the image; NO to ignore the DPI.
 
 @returns The width of this @p LTRasterImage in pixels, taking @p viewPerspective and @p xResolution into account.
 */
- (NSInteger)imageWidthWithDpi:(BOOL)useDpi NS_SWIFT_NAME(imageWidth(useDpi:));

/**
 @brief Gets the height of this @p LTRasterImage in pixels, taking @p viewPerspective and @p yResolution into account.
 
 @param useDpi YES to take into account the resolution (DPI) of the image; NO to ignore the DPI.
 
 @returns The height of this @p LTRasterImage in pixels, taking @p viewPerspective and @p yResolution into account.
 */
- (NSInteger)imageHeightWithDpi:(BOOL)useDpi NS_SWIFT_NAME(imageHeight(useDpi:));

/**
 @brief Gets the size of this @p LTRasterImage in pixels, taking @p viewPerspective and @p yResolution into account.
 
 @param useDpi YES to take into account the resolution (DPI) of the image; NO to ignore the DPI.
 
 @returns The size of this @p LTRasterImage in pixels, taking @p viewPerspective and @p yResolution into account.
 */
- (LeadSize)imageSizeWithDpi:(BOOL)useDpi NS_SWIFT_NAME(imageSize(useDpi:));

@end


@interface LTRasterImage (DIB)

/**
 @brief Gets an unmanaged pointer containing a device independent bitmap (DIB) version of this image.
 
 @type The type of DIB to create.
 
 @returns A handle to the DIB.
 */
- (nullable LTHandle *)createDibWithType:(LTRasterConvertToDibType)type NS_SWIFT_NAME(createDib(type:));

/**
 @brief Gets a @p NSData instance containing a device independent bitmap (DIB) version of this image.
 
 @type The type of DIB to create.
 
 @returns A handle to the DIB.
 */
- (nullable NSData *)createDibArrayWithType:(LTRasterConvertToDibType)type NS_SWIFT_NAME(createDibArray(type:));

/**
 @brief Changes a LEAD @p LTRasterImage object to a device independent bitmap (DIB).
 
 @type The type of DIB to create.
 
 @returns A handle to the DIB.
 */
- (nullable LTHandle *)changeToDib:(LTRasterConvertToDibType)type NS_SWIFT_NAME(changeToDib(type:));


/**
 @brief Creates a new image from the specified device independent bitmap (DIB)
 
 @param dib A handle to the DIB.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly created @p LTRasterImage object.
 */
+ (nullable LTRasterImage *)imageWithDib:(LTHandle *)dib error:(NSError **)error;

/**
 @brief Creates a new image from the specified device independent bitmap (DIB)
 
 @param dibArray A @p NSData instance containing the DIB data
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly created @p LTRasterImage object.
 */
+ (nullable LTRasterImage *)imageWithDibArray:(NSData *)dibArray error:(NSError **)error;

/**
 @brief Changes a device independent bitmap (DIB) to a LEAD @p LTRasterImage object.
 
 @param dib A handle to the DIB.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly created @p LTRasterImage object.
 */
+ (nullable LTRasterImage *)changeFromDib:(LTHandle *)dib error:(NSError **)error;

@end



@interface LTRasterImage (Events)

/** @brief The notification center instance that this image will post events to. Default is [NSNotificationCenter defaultCenter] */
@property (nonatomic, weak, nullable) NSNotificationCenter *notificationCenter;


/**
 @brief Occurs when the image data or attributes has changed.
 
 @param flags The flags that indicate what part of the image changed.
 */
- (void)didChange:(LTRasterImageChangedFlags)flags;

/** @brief Disables raising the @p didChange: event. */
- (void)disableEvents;

/** @brief Enables raising the @p didChange: event. */
- (void)enableEvents;

@end



@interface LTRasterImage (Pages)

/** @brief The current active page for this @p LTRasterImage. This is a 1-based index. */
@property (nonatomic, assign)           NSInteger page;

/** @brief The total number of pages in this @p LTRasterImage. */
@property (nonatomic, assign, readonly) NSUInteger pageCount;


/** 
 @brief Adds a new page to this @p LTRasterImage.
 
 @param page The image to add.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The index of the page that was added on success, @p NSNotFound otherwise.
 */
- (NSInteger)addPage:(LTRasterImage *)page error:(NSError **)error;

/**
 @brief Adds one or more images to this @p LTRasterImage.
 
 @param pages The @p LTRasterImage object containing the pages to add.
 @param start The 1-based index starting from which to begin adding.
 @param count The total number of images to add. Specify -1 to add all images.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.

 @returns YES if the pages were added successfully, NO otherwise.
 */
- (BOOL)addPages:(LTRasterImage *)pages startIndex:(NSInteger)start count:(NSInteger)count error:(NSError **)error;


/**
 @brief Removes the page at the specified index from this @p LTRasterImage.
 
 @param index The 1-based index of the page to remove.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the page was removed successfully, NO otherwise.
 */
- (BOOL)removePageAtIndex:(NSInteger)index error:(NSError **)error NS_SWIFT_NAME(removePage(at:));

/**
 @brief Removes one or more page from this @p LTRasterImage.
 
 @param start The 1-based index of the first page to remove.
 @param count The number of pages to remove. Specify -1 to remove all pages.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the pages were removed successfully, NO otherwise.
 */
- (BOOL)removePages:(NSInteger)start count:(NSInteger)count error:(NSError **)error NS_SWIFT_NAME(removePages(start:count:));

/**
 @brief Removes all pages from this @p LTRasterImage.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the pages were removed successfully, NO otherwise.
 */
- (BOOL)removeAllPages:(NSError **)error;


/**
 @brief Inserts a new page into this @p LTRasterImage.
 
 @param page The image to add.
 @param index The 1-based index of the page from @p page to insert. If @p index is equal to -1, the page is inserted at the end. Use @p index = 0 to insert the new page at the beginning (first).
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The 1-based index of the newly inserted page on success, @p NSNotFound otherwise.
 */
- (NSInteger)insertPage:(LTRasterImage *)page atIndex:(NSInteger)index error:(NSError **)error;

/**
 @brief Inserts one or more pages into this @p LTRasterImage.
 
 @param pages The image containing the source pages.
 @param start The 1-based index of the page from @p pages to insert.
 @param count The number of pages to insert. Specify -1 to insert all pages.
 @param index The 1-based index of the first page to insert. Use @p index = 0 to insert the new page at the beginning (first).
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the pages were inserted successfully, NO otherwise.
 */
- (BOOL)insertPages:(LTRasterImage *)pages from:(NSInteger)start count:(NSInteger)count atIndex:(NSInteger)index error:(NSError **)error;


/**
 @brief Replaces an existing page in this @p LTRasterImage.
 
 @param page The source image to replace with.
 @param index The 1-based index of the page from @p page to replace. If @p index is equal to -1, the last page in the image will be replaced.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the page was replaced successfully, NO otherwise.
 */
- (BOOL)replacePageAtIndex:(NSInteger)index withPage:(LTRasterImage *)page error:(NSError **)error NS_SWIFT_NAME(replacePage(at:with:));

/**
 @brief Replaces one or more pages of this @p LTRasterImage.
 
 @param index The 1-based index of the page from @p page to replace.
 @param pages The image containing the sourece pages.
 @param start The 1-based index of the first page to replace from.
 @param count The number of pages to replace. Specify -1 to replace all pages.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the page was replaced successfully, NO otherwise.
 */
- (BOOL)replacePageAtIndex:(NSInteger)index withPages:(LTRasterImage *)pages start:(NSInteger)start count:(NSInteger)count error:(NSError **)error NS_SWIFT_NAME(replacePage(at:with:start:count:));

@end



@interface LTRasterImage (Palette)

/** @brief Gets the palette of this @p LTRasterImage object that will be used by 1-8 bit color or grayscale images. */
@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *palette;

/** @brief Gets the 8-bit lookup table (LUT) of this @p LTRasterImage. */
@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *lookupTable;

/** @brief Gets the 16-bit lookup table (LUT) of this @p LTRasterImage. */
@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor16 *> *lookupTable16;

/** @brief For internal use by LEADTOOLS. */
@property (nonatomic, strong)                     NSData *paintLookupTable;

/** @brief For internal use by LEADTOOLS. */
@property (nonatomic, strong, nullable)           NSData *paintLookupTable16;


/**
 @brief Sets the palette of this @p LTRasterImage object that will be used by 1-8 bit color or grayscale images.
 
 @param palette An array of @p LTRasterColor objects containing the new palette to use.
 @param range The range of palette entries to replace with the values in @p palette.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the palette was set correctly, NO otherwise.
 */
- (BOOL)setPalette:(nullable NSArray<LTRasterColor *> *)palette range:(NSRange)range error:(NSError **)error;

/**
 @brief Sets the 8-bit lookup table (LUT) of this @p LTRasterImage.
 
 @param lut An array of @p LTRasterColor objects which represent the lookup table (LUT) of this @p LTRasterImage.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the lookup table was set correctly, NO otherwise.
 */
- (BOOL)setLookupTable:(nullable NSArray<LTRasterColor *> *)lut error:(NSError **)error;

/**
 @brief Sets the 16-bit lookup table (LUT) of this @p LTRasterImage.
 
 @param lut16 An array of @p LTRasterColor16 objects which represent the lookup table (LUT) of this @p LTRasterImage.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the lookup table was set correctly, NO otherwise.
 */
- (BOOL)setLookupTable16:(nullable NSArray<LTRasterColor16 *> *)lut16 error:(NSError **)error;


/**
 @brief Copies the palette of this @p LTRasterImage into a destination image.
 
 @param dstImage The destination image into which the palette will be copied. You must have a valid image loaded for this method to work.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the lookup table was set correctly, NO otherwise.
 */
- (BOOL)copyPaletteTo:(LTRasterImage *)dstImage error:(NSError **)error NS_SWIFT_NAME(copyPalette(to:));

@end



@interface LTRasterImage (Region)

/** @brief A value indicating whether or not this @p LTRasterImage has a region. */
@property (nonatomic, assign, readonly) BOOL hasRegion;

/** @brief A value that represents the number of elements required to hold the clip segments for any row in the region. */
@property (nonatomic, assign, readonly) NSUInteger maximumClipSegmentsForRegion;

/** @breif A value that represents the total number of pixels in the image region. */
@property (nonatomic, assign, readonly) uint64_t regionArea;


/** @brief Removes the region from the image and frees the memory used for the region. */
- (void)makeRegionEmpty;

/**
 @brief Gets the segments contained in the region for a particular row.
 
 @param row The number of the row for which to get the segments. The first row is 0, and the last row is 1 less than the image height.
 @param buffer The buffer to be updated with the segments from row contained in the region.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of segments from @p row that are contained in the region on success, @p NSNotFound otherwise.
 */
- (NSUInteger)regionClipSegmentsForRow:(NSInteger)row segmentsBuffer:(unsigned int *)buffer error:(NSError **)error;


/**
 @brief Gets the bouding rectangle of the image region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The bounding rectangle.
 */
- (LeadRect)regionBounds:(nullable LTRasterRegionXForm *)xform error:(NSError **)error NS_SWIFT_NAME(regionBounds(xform:error:));

/**
 @brief Gets the bouding rectangle of the image region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The bounding rectangle.
 */
- (LeadRect)regionBoundsClipped:(nullable LTRasterRegionXForm *)xform error:(NSError **)error NS_SWIFT_NAME(regionBoundsClipped(xform:error:));


/**
 @brief Determines whether or not the specified pixel is in the image region.
 
 @param point The pixel.
 
 @returns YES if the specified pixel is in the region, otherwise NO.
 */
- (BOOL)regionContainsPoint:(LeadPoint)point NS_SWIFT_NAME(regionContains(_:));

/**
 @brief Moves the image region by the specified number of rows and columns.
 
 @param offset The number of rows and columns to move the region.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the region was moved, otherwise NO.
 */
- (BOOL)offsetRegionByAmount:(LeadPoint)offset error:(NSError **)error NS_SWIFT_NAME(offsetRegion(by:));

/**
 @brief Flips the image region (top to bottom).
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the region was flipped, otherwise NO.
 */
- (BOOL)flipRegion:(NSError **)error;

/**
 @brief Reverses the image region (left to right).
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the region was reversed, otherwise NO.
 */
- (BOOL)reverseRegion:(NSError **)error;


/**
 @brief Creates or updates the image region by adding a rectangular region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param rect A @p LeadRect value that specifies the region.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the rectangle was set into the region, otherwise NO.
 */
- (BOOL)addRectangleToRegion:(nullable LTRasterRegionXForm *)xform rect:(LeadRect)rect combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addRectangleToRegion(xform:rect:combineMode:));

/**
 @brief Creates or updates the image region by adding a elliptical region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param rect A @p LeadRect value that represents the bounding rectangle that defines the ellipse.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the ellipse was set into the region, otherwise NO.
 */
- (BOOL)addEllipseToRegion:(nullable LTRasterRegionXForm *)xform rect:(LeadRect)rect combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addEllipseToRegion(xform:rect:combineMode:));

/**
 @brief Creates or updates the image region by adding a round rectangle region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param rect A @p LeadRect value that represents the bounding rectangle that defines the rectangle.
 @param ellipse A @p LeadSize value that specifies the width and height of the rounded corners.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the ellipse was set into the region, otherwise NO.
 */
- (BOOL)addRoundRectangleToRegion:(nullable LTRasterRegionXForm *)xform rect:(LeadRect)rect ellipse:(LeadSize)ellipse combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addRoundRectangleToRegion(xform:rect:ellipse:combineMode:));

/**
 @brief Creates or updates the image region by adding a polygonal region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param points An unmanaged array of @p LeadPoint structures. The point in the array must be in the order in which the vertices of the polygon are connected. To create the line that closes the polygon, the last point in the array is connected to the first point of the array.
 @param length The number of @p LeadPoint structures in @p points
 @param fillMode A value that indicates how to handle complex crossing lines.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the polygon was set into the region, otherwise NO.
 */
- (BOOL)addPolygonToRegion:(nullable LTRasterRegionXForm *)xform points:(const LeadPoint *)points length:(NSInteger)length fillMode:(LTLeadFillMode)fillMode combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addPolygonToRegion(xform:points:length:fillMode:combineMode:));

/**
 @brief Creates or updates the image region by adding a region that consists of all the pixels that fall in the given RGB color range.
 
 @param lowerColor Specifies the minimum (inclusive) R, G, and B values. A pixel must have R, G, and B all greater than or equal to @p lowerColor and less than or equal to @p upperColor to be included in the region.
 @param upperColor Specifies the maximum (inclusive) R, G, and B values. A pixel must have R, G, and B all greater than or equal to @p lowerColor and less than or equal to @p upperColor to be included in the region.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the polygon was set into the region, otherwise NO.
 */
- (BOOL)addColorRgbRangeToRegion:(LTRasterColor *)lowerColor upperColor:(LTRasterColor *)upperColor combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addColorRangeToRegion(lowerColor:upperColor:combineMode:));

/**
 @brief Creates or updates the image region by adding a region that consists of all the pixels that fall in the given HSV color range.
 
 @param lowerColor Specifies the minimum (inclusive) H, S, and V values. A pixel must have H, S, and V all greater than or equal to @p lowerColor and less than or equal to @p upperColor to be included in the region.
 @param upperColor Specifies the maximum (inclusive) H, S, and V values. A pixel must have H, S, and V all greater than or equal to @p lowerColor and less than or equal to @p upperColor to be included in the region.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the polygon was set into the region, otherwise NO.
 */
- (BOOL)addColorHsvRangeToRegion:(LTRasterHsvColor *)lowerColor upperColor:(LTRasterHsvColor*)upperColor combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addColorRangeToRegion(lowerColor:upperColor:combineMode:));

/**
 @brief Creates or updates the image region by adding a region that consists of all the pixels of a specified color
 
 @param color Specifies the color to use for the region.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the polygon was set into the region, otherwise NO.
 */
- (BOOL)addColorToRegion:(LTRasterColor *)color combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addColorToRegion(color:combineMode:));


/**
 @brief Creates a 1-bit mask image from the region that is defined in the image.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly create @p LTRasterImage which will be updated with a 1-bit, black-and-white image, where pixels from the reigon are white, and all others are black.
 */
- (nullable LTRasterImage *)createMaskFromRegion:(NSError **)error;


/**
 @brief Create or updates the image region by adding a region that consists of all the white pixels in a 1-bit mask image.
 
 @param xform The LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates.
 @param mask The 1-bit black-and-white @p LTRasterImage used as a mask.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the mask was added to the region, otherwise NO.
 */
- (BOOL)addMaskToRegion:(nullable LTRasterRegionXForm *)xform maskImage:(LTRasterImage *)mask combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addMaskToRegion(xform:mask:combineMode:));

/**
 @brief Sets a region based on the color found at point x, y, in the image.
 
 @param left The X-coordinate of a point. The color of the specified point will be used to set the region.
 @param top The Y-coordinate of a point. The color of the specified point will be used to set the region.
 @param lowTolColor The lower tolerance values that set the lower stopping point for the region.
 @param upTolColor The upper tolerance values that set the upper stopping point for the region.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the region was set or updated, otherwise NO.
 */
- (BOOL)addMagicWandToRegion:(NSInteger)left top:(NSInteger)top lowerToleranceColor:(LTRasterColor *)lowTolColor upperToleranceColor:(LTRasterColor *)upTolColor combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addMagicWantToRegion(left:top:lowerTolerance:upperTolerance:combineMode:));

/**
 @brief Creates a region of pixels with values that fall within a range defined by the value of a specific pixel and a lower and upper tolerance avluae but are not equal to the @p borderColor.
 
 @param left The X-coordinate of a point. The color of the specified point will be used to set the region.
 @param top The Y-coordinate of a point. The color of the specified point will be used to set the region.
 @param borderColor The border color.
 @param lowTolColor The lower tolerance values that set the lower stopping point for the region.
 @param upTolColor The upper tolerance values that set the upper stopping point for the region.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the border was added to the region, otherwise NO.
 */
- (BOOL)addBorderToRegion:(NSInteger)left top:(NSInteger)top borderColor:(LTRasterColor *)borderColor lowerToleranceColor:(LTRasterColor *)lowTolColor upperToleranceColor:(LTRasterColor *)upTolColor combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(addBorderToRegion(left:top:borderColor:lowerTolerance:upperTolerance:combineMode:));


/**
 @brief Sets or updates the @p LTRasterRegion object that describes this @p LTRasterImage's current region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 @param region A @p LTRasterRegion object to set or update into this @p LTRasterImage. If this parameter is an empty region or nil, then the current region in the image will be deleted (equivalent of calling @p makeRegionEmpty.
 @param combineMode The action to take regarding the existing image region, if one is defined.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the region was set, otherwise NO.
 */
- (BOOL)setRegion:(nullable LTRasterRegionXForm *)xform region:(nullable LTRasterRegion *)region combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error NS_SWIFT_NAME(setRegion(xform:region:combineMode:));

/**
 @brief Gets the @p LTRasterRegion object that describes this @p LTRasterImage's current region.
 
 @param xform The @p LTRasterRegionXForm object that LEADTOOLS uses to translate between display coordinates and image coordinates. If you specify nil for this parameter, the scalar fields default to 1, the offets default to 0, and the view perspective defaults to the image view perspective.
 
 @returns The @p LTRasterRegion object that describes this @p LTRasterImage's current region.
 */
- (nullable LTRasterRegion *)getRegion:(nullable LTRasterRegionXForm *)xform error:(NSError **)error NS_SWIFT_NAME(getRegion(xform:));

@end



@interface LTRasterImage (ImageData)

/** 
 @brief Provides exclusive access to the image data contained in this @p LTRasterImage.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if you have exclusive access to the data, otherwise NO.
 */
- (BOOL)accessData:(NSError **)error;

/**
 @brief Releases memory locked with @p accessData: back to the system.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was releasing to the system, otherwise NO.
 */
- (BOOL)releaseData:(NSError **)error;


/**
 @brief Retrieves one or more rows of image data from this @p LTRasterImage into an unmanaged memory buffer.
 
 @param row The number of the row to retrieve. The first row is 0, and the last row is 1 less than the image height.
 @param buffer The buffer to hold the image data that this method gets. The size of this buffer must be large enough to hold the image data.
 @param count The number of bytes in the row to retieve. To get a full row, use the value in the @p bytesPerLine property.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of bytes copied into the buffer.
 */
- (NSInteger)getRow:(NSInteger)row buffer:(void *)buffer bufferCount:(uint64_t)count error:(NSError **)error;

/**
 @brief Copies one or more rows of image data to this @p LTRasterImage.
 
 @param row The number of the row to update. The first row is 0, and the last row is 1 less than the image height.
 @param buffer The buffer containing the image data. The data is copied exactly as it is stored in the buffer. The buffer should contain uncompressed data regardless of whether the image is compressed or not.
 @param count The number of bytes to set. Use the @p bytesPerLine property of this @p LTRasterImage to determine the byte count of each line.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of bytes copied.
 */
- (NSInteger)setRow:(NSInteger)row buffer:(const void *)buffer bufferCount:(uint64_t)count error:(NSError **)error;

/**
 @brief Accepts a column offset to retrieve data from an image and place it in a buffer.
 
 @param row The number of the row to retrieve. The first row is 0, and the last row is 1 less than the image height.
 @param column The column offset within the row to retrieve. The first column offset is 0, and the last column offset is 1 less that the image width.
 @param buffer The buffer to hold the image data that this method gets. The buffer will be filled with uncompressed data.
 @param count The number of bytes to retrieve. Consider the bits per pixel, and avoid specifying a number that goes past the end of the row.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of bytes copied.
 */
- (NSInteger)getRowColumn:(NSInteger)row column:(NSInteger)column buffer:(void *)buffer bufferCount:(uint64_t)count error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(getRow(_:column:buffer:bufferCount:error:));

/**
 @brief Copies data from a buffer into an image.
 
 @param row The number of the row to update. The first row is 0, and the last row is 1 less than the image height.
 @param column The column offset within the row to update. The first column offset is 0, and the last column offset is 1 less that the image width.
 @param buffer The buffer to hold the image data that this method gets. The buffer should contain uncompressed data regardless of whether the image is compressed or not.
 @param count The number of bytes to udate. Consider the bits per pixel, and avoid specifying a number that goes past the end of the row.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of bytes put.
 */
- (NSInteger)setRowColumn:(NSInteger)row column:(NSInteger)column buffer:(const void *)buffer bufferCount:(uint64_t)count error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(setRow(_:column:buffer:bufferCount:error:));


/** @brief For internal use by LEADTOOLS. */
- (BOOL)setRowSegments:(NSInteger)row column:(NSInteger)column buffer:(const void *)buffer segments:(const unsigned int *)segments segmentCount:(uint64_t)count preserveAlpha:(BOOL)preserveAlpha error:(NSError **)error;


/**
 @brief Retrieves one or more rows of 1-bit compressed data from an image that has been loaded in its compressed format.
 
 @param workBuffer Optional work buffer. Allocating the work buffer speeds processing if you call this method more than once, becuase if you do not allocate a work buffer, the method allocates and frees a temporary buffer each time it is called. Bytes required = @p lines * ((@p width + 3) * 2). Pass NULL to @p runBuffer if you do not want to use a work buffer.
 @param runBuffer The output buffer, which will be filled with 1-bit compressed image data.
 @param row The number of the row to retrieve. The first row is 0, and the last row is 1 less than the image height.
 @param lines The number of rows to retrieve.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of bytes copied.
 */
- (NSInteger)getRowCompressed:(nullable void *)workBuffer runBuffer:(unsigned short *)runBuffer row:(NSUInteger)row lines:(NSUInteger)lines error:(NSError **)error;

/**
 @brief Retrieves one or more rows of 1-bit compressed data from an image that has been loaded in its compressed format.
 
 @param workBuffer Optional work buffer. Allocating the work buffer speeds processing if you call this method more than once, becuase if you do not allocate a work buffer, the method allocates and frees a temporary buffer each time it is called. The size of this buffer should be the same as the image's @p bytesPerLine property. Pass NULL to @p runBuffer if you do not want to use a work buffer.
 @param runBuffer The input buffer, which contains 1-bit compressed image data.
 @param row The number of the first row to update.
 @param lines The number of rows to update.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of bytes put.
 */
- (NSInteger)setRowCompressed:(nullable void *)workBuffer runBuffer:(const unsigned short *)runBuffer row:(NSUInteger)row lines:(NSUInteger)lines error:(NSError **)error;

/**
 @brief Retrieves a row (or part of a row) of 1-bit compressed data from an image that has been loaded in its compressed format.
 
 @param workBuffer Optional work buffer. Allocating the work buffer speeds processing if you call this method more than once, becuase if you do not allocate a work buffer, the method allocates and frees a temporary buffer each time it is called. The size of this buffer should be the same as the image's @p bytesPerLine property. Pass NULL to @p runBuffer if you do not want to use a work buffer.
 @param runBuffer The output buffer, which will be filled with 1-bit compressed image data. Calculate the required size ofthis buffer as follows: bytes required = (@p width + 3) * 2.
 @param row The number of the row to retrieve. The first row is 0, and the last row is 1 less than the image height.
 @param column The column offset within the row to retrieve. The first column offset is 0, and the last column offset is 1 less than the image width.
 @param pixels The number of pixels to retrieve.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of pixels processed.
 */
- (NSInteger)getRowColumnCompressed:(void *)workBuffer runBuffer:(unsigned short *)runBuffer row:(NSInteger)row column:(NSInteger)column width:(NSUInteger)pixels error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(getRowCompressed(_:runBuffer:row:column:width:error:));

/**
 @brief Retrieves one or more rows of 1-bit compressed data from an image that has been loaded in its compressed format.
 
 @param workBuffer Optional work buffer. Allocating the work buffer speeds processing if you call this method more than once, becuase if you do not allocate a work buffer, the method allocates and frees a temporary buffer each time it is called. The size of this buffer should be the same as the image's @p bytesPerLine property. Pass NULL to @p runBuffer if you do not want to use a work buffer.
 @param runBuffer The input buffer, which contains 1-bit compressed image data.
 @param row The number of the row to update. The first row is 0, and the last row is 1 less than the image height.
 @param column The column offset within the row to update. The first column offset is 0, and the last column offset is 1 less than the image width.
 @param pixels The number of pixels to retrieve.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The number of pixels processed.
 */
- (NSInteger)setRowColumnCompressed:(void *)workBuffer runBuffer:(const unsigned short *)runBuffer row:(NSInteger)row column:(NSInteger)column width:(NSUInteger)pixels error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(setRowCompressed(_:runBuffer:row:column:width:error:));

/**
 @brief Compresses or decompresses this @p LTRasterImage
 
 @param compression Indicates the type of compression to use on the image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the compression was changed, otherwise NO.
 */
- (BOOL)changeCompression:(LTRasterCompression)compression error:(NSError **)error;

/**
 @brief Creates a grayscale image from this @p LTRasterImage's alpha channel data.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly created image, which contains the source image alpha channel data.
 */
- (nullable LTRasterImage *)createAlphaImage:(NSError **)error;

/**
 @brief Replaces existing alpha channel data or creates new alpha channel data.
 
 @param alphaImage The source @p LTRasterImage which references the image that is used to create or replace the alpha channel data.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the alpha channel was set, otherwise NO.
 */
- (BOOL)setAlphaImage:(LTRasterImage *)alphaImage error:(NSError **)error;


/**
 @brief Translates the specified color in the image, and returns the nearest matching color in the destination image.
 
 @param dstImage The destination @p LTRasterImage object.
 @param rgb The value that specifies the color in the image to be translated.
 
 @returns The color value or the palette index of the nearest matching color in the destination image. If the destination image is 8 bits per pixel or less, this is always the palette index. Otherwise, it is the color value.
 */
- (uint32_t)translateColorRgb:(LTRasterImage *)dstImage rgb:(uint32_t)rgb NS_SWIFT_NAME(translateColor(destinationImage:color:));

/**
 @brief Translates the specified color in the image, and returns the nearest matching color in the destination image.
 
 @param dstImage The destination @p LTRasterImage object.
 @param color The value that specifies the color in the image to be translated.
 
 @returns The color value of the nearest matching color in the destination image.
 */
- (LTRasterColor *)translateColor:(LTRasterImage *)dstImage color:(LTRasterColor *)color NS_SWIFT_NAME(translateColor(destinationImage:color:));


/**
 @brief Increases or decreases the allocated height of an image.
 
 @param newHeight The new height in pixels.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the height was changed, otherwise NO.
 */
- (BOOL)changeHeight:(NSInteger)newHeight error:(NSError **)error NS_SWIFT_NAME(changeHeight(newHeight:));


/**
 @brief Returns the color of the specified pixel.
 
 @param row The zero-based row number of the pixel.
 @param column The zero-based column number of the pixel.
 
 @returns A @p LTRasterColor object which represents a grayscale value (Medical Imaging only), or red, green, and blue color values.
 */
- (LTRasterColor *)getPixelColorAtRow:(NSInteger)row column:(NSInteger)column NS_SWIFT_NAME(getPixelColor(row:column:));

/**
 @brief Returns the color of the specified pixel.
 
 @param row The zero-based row number of the pixel.
 @param column The zero-based column number of the pixel.
 
 @returns A @p LTRasterColor object which represents a grayscale value (Medical Imaging only), or red, green, and blue color values. Alpha value for 32 and 64-bit images are also returned.
 */
- (LTRasterColor *)getPixelAtRow:(NSInteger)row column:(NSInteger)column NS_SWIFT_NAME(getPixel(row:column:));

/**
 @brief Changes the color value of the specified pixel.
 
 @param color The color to assign to the pixel.
 @param row The zero-based row number of the pixel.
 @param column The zero-based column number of the pixel.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the pixel was set, otherwise NO.
 */
- (BOOL)setColor:(LTRasterColor *)color forPixelAtRow:(NSInteger)row column:(NSInteger)column error:(NSError **)error NS_SWIFT_NAME(setPixelColor(_:row:column:));

/**
 @brief Changes the color value of the specified pixel.
 
 @param color The color to assign to the pixel. If the image has 32 or 64-bits per pixel, the alpha value of this parameter is used in the pixel data.
 @param row The zero-based row number of the pixel.
 @param column The zero-based column number of the pixel.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the pixel was set, otherwise NO.
 */
- (BOOL)setPixel:(LTRasterColor *)color atRow:(NSInteger)row column:(NSInteger)column error:(NSError **)error NS_SWIFT_NAME(setPixel(_:row:column:));


/**
 @brief Copies the pixel data of the specified pixel into an unmanaged memory buffer.
 
 @param data The pointer to an unmanaged memory buffer to copy the pixel data to.
 @param size The size, in bytes, of the buffer in @p data.
 @param row The zero-based row number of the pixel.
 @param column The zero-based column number of the pixel.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was retrieved, otherwise NO.
 */
- (BOOL)getData:(void *)data ofSize:(uint64_t)size forPixelAtRow:(NSInteger)row column:(NSInteger)column error:(NSError **)error;

/**
 @brief Changes the data of the specified pixel by copying from an unmanaged memory buffer.
 
 @param data The pointer to an unmanaged memory buffer to that contains the pixel data to set. This buffer should contain ((@p bitsPerPixel + 7) / 8) bytes.
 @param size The size of the @p data unmanaged memory buffer.
 @param row The zero-based row number of the pixel.
 @param column The zero-based column number of the pixel.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was set, otherwise NO.
 */
- (BOOL)setData:(const void *)data ofSize:(uint64_t)size forPixelAtRow:(NSInteger)row column:(NSInteger)column error:(NSError **)error;

/**
 @brief Updates the data of this @p LTRasterImage.
 
 @param data The new data
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was copied successfully, otherwise NO.
 */
- (BOOL)copyData:(NSData *)data error:(NSError **)error;

/**
 @brief Sets the data for the image to the specified unmanaged memory buffer.
 
 @param userData The pointer to the unmanaged memory buffer containing the new data.
 @param userDataSize The number of bytes in @p userData.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was set, otherwise NO.
 */
- (BOOL)setUserData:(nullable void *)userData userDataSize:(uint64_t)userDataSize error:(NSError **)error;


/**
 @brief Flips this @p LTRasterImage image by changing its @p viewPerspective.
 
 @param horizontal YES to flip horizontall, NO to flip vertically
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the image was flipped, otherwise NO.
 */
- (BOOL)flipViewPerspective:(BOOL)horizontal error:(NSError **)error NS_SWIFT_NAME(flipViewPerspective(horizontal:));

/**
 @brief Rotates this @p LTRasterImage image by changing its @p viewPerspective.
 
 @param degrees The degrees of rotation. Valid values are +-90, +-180, +-270, or +-360. Positive values are clockwise; negative values are counter-clockwise.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the image was rotated, otherwise NO.
 */
- (BOOL)rotateViewPerspective:(NSInteger)degrees error:(NSError **)error NS_SWIFT_NAME(rotateViewPerspective(degrees:));

/**
 @brief Rotates and flips the image data as necessary to achieve the desired view perspective.
 
 @param viewPerspective The desired view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES is the view perspective was changed, otherwise NO.
 */
- (BOOL)changeViewPerspective:(LTRasterViewPerspective)viewPerspective error:(NSError **)error;


/**
 @brief Translates a point (x,y) from this @p LTRasterImage view perspective to the specified view perspective.
 
 @param viewPerspective The destination view perspective to which the point should be translated.
 @param src The point to translate.
 
 @returns The translated point.
 */
- (LeadPoint)pointFromImage:(LTRasterViewPerspective)viewPerspective sourcePoint:(LeadPoint)src NS_SWIFT_NAME(pointFromImage(viewPerspective:source:));

/**
 @brief Translates a point (x,y) from the specified view perspective to this @p LTRasterImage view perspective.
 
 @param viewPerspective The source view perspective from which the point should be translated.
 @param src The point to translate.
 
 @returns The translated point.
 */
- (LeadPoint)pointToImage:(LTRasterViewPerspective)viewPerspective sourcePoint:(LeadPoint)src NS_SWIFT_NAME(pointToImage(viewPerspective:source:));

/**
 @brief Translates a rectangle from this @p LTRasterImage view perspective to the specified view perspective.
 
 @param viewPerspective The destination view perspective to which the rectangle should be translated.
 @param src The rectangle to translate.
 
 @returns The translated rectangle.
 */
- (LeadRect)rectangleFromImage:(LTRasterViewPerspective)viewPerspective sourceRect:(LeadRect)src NS_SWIFT_NAME(rectangleFromImage(viewPerspective:source:));

/**
 @brief Translates a retangle from the specified view perspective to this @p LTRasterImage view perspective.
 
 @param viewPerspective The source view perspective from which the point should be translated.
 @param src The rectangle to translate.
 
 @returns The translated rectangle.
 */
- (LeadRect)rectangleToImage:(LTRasterViewPerspective)viewPerspective sourceRect:(LeadRect)src NS_SWIFT_NAME(rectangleToImage(viewPerspective:source:));


/**
 @brief Initializes the buffered dithering of an image.
 
 @param palette The palette this uses for dithering. You can specify your own palette, or can pass nil for LEAD's fixed palette.
 @param colors The number of colors used in the palette. If the palette contains more colors than @p colors, only the first @p colors colors are used. Valid values are 2 to 256.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if it initialized, otherwise NO.
 */
- (BOOL)startDithering:(nullable NSArray<LTRasterColor *> *)palette colors:(NSUInteger)colors error:(NSError **)error NS_SWIFT_NAME(startDithering(palette:colors:));

/**
 @brief Used in a loop, dithers the line in a specified unmanaged memory input buffer, and writes it to an unmanaged memory output buffer.
 
 @param srcBuffer A pointer to the unmanaged memory input buffer.
 @param dstBuffer A pointer to the unmanaged memory output buffer.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the line was dithered, otherwise NO.
 */
- (BOOL)ditherLine:(const void *)srcBuffer destBuffer:(void *)dstBuffer error:(NSError **)error NS_SWIFT_NAME(ditherLine(source:destination:));

/**
 @brief Cleans up all data variables and buffers allocated by the @p startDithering:colors:error: and @p ditherLine:destBuffer:error: methods.
 
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if everything was cleaned up, otherwise NO.
 */
- (BOOL)stopDithering:(NSError **)error;

@end



@interface LTRasterImage (YUV)

/**
 @brief Creates a @p LTRasterImage using the specified parameters and fills the image using the specified YUV data.
 
 @param buffer The unmanaged data pointer that contains the YUV image data.
 @paarm bufferCount The length in bytes of the data passed via @p buffer. Only used when @p buffer is not NULL.
 @param format The format of the YUV data contained in @p buffer.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 8, 24, and 32.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
+ (nullable instancetype)imageWithYUVData:(const void *)buffer bufferCount:(uint64_t)bufferCount format:(LTRasterYUVFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

/**
 @brief Creates a @p LTRasterImage using the specified parameters and fills the image using the specified YUV data.
 
 @param data The managed data that contains the YUV image data.
 @paarm bufferCount The length in bytes of the data passed via @p buffer. Only used when @p buffer is not NULL.
 @param format The format of the YUV data contained in @p buffer.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 8, 24, and 32.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
+ (nullable instancetype)imageWithYUVData:(NSData *)data format:(LTRasterYUVFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error OBJC_SWIFT_UNAVAILABLE("use object initializers instead");


/**
 @brief Initializes this @p LTRasterImage using the specified parameters and fills the image using the specified YUV data.
 
 @param buffer The unmanaged data pointer that contains the YUV image data.
 @paarm bufferCount The length in bytes of the data passed via @p buffer. Only used when @p buffer is not NULL.
 @param format The format of the YUV data contained in @p buffer.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 8, 24, and 32.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithYUVData:(const void *)buffer bufferCount:(uint64_t)bufferCount format:(LTRasterYUVFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error NS_SWIFT_NAME(init(yuvData:count:format:width:height:bitsPerPixel:));

/**
 @brief Initializes this @p LTRasterImage using the specified parameters and fills the image using the specified YUV data.
 
 @param data The managed data that contains the YUV image data.
 @paarm bufferCount The length in bytes of the data passed via @p buffer. Only used when @p buffer is not NULL.
 @param format The format of the YUV data contained in @p buffer.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 8, 24, and 32.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithYUVData:(NSData *)data format:(LTRasterYUVFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error  NS_SWIFT_NAME(init(yuvData:format:width:height:bitsPerPixel:));


/**
 @brief Updates the image data using the YUV data from an input buffer. The YUV data is converted to grayscale/BGR before being set in the @p LTRasterImage
 
 @param buffer The buffer that contains the YUV data.
 @paarm bufferCount The size of the data buffer pointed to by buffer.
 @param format Specifies the YUV data format.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was set, otherwise NO.
 */
- (BOOL)setYUVData:(const void *)buffer bufferCount:(uint64_t)bufferCount format:(LTRasterYUVFormat)format error:(NSError **)error;

/**
 @brief Updates the image data using the YUV data from an input buffer. The YUV data is converted to grayscale/BGR before being set in the @p LTRasterImage
 
 @param data The data object that contains the YUV data.
 @param format Specifies the YUV data format.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the data was set, otherwise NO.
 */
- (BOOL)setYUVData:(NSData *)data format:(LTRasterYUVFormat)format error:(NSError **)error;


/**
 @brief Converts the @p LTRasterImage grayscale or BGR data to YUV and stores it in an output buffer.
 
 @param buffer The buffer to receive the YUV data. If NULL, this method will return the expected size of the YUV data buffer. If not NULL, the YUV data will be extracted and stored in @p buffer if the buffer is large enough to contain the YUV data.
 @paarm bufferCount The size of the data buffer pointed to by buffer.
 @param format Specifies the YUV data format.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The expected size of the YUV data buffer.
 */
- (NSInteger)getYUVData:(nullable void *)buffer bufferCount:(uint64_t)bufferCount format:(LTRasterYUVFormat)format error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(getYUVData(buffer:count:format:error:));

/**
 @brief Converts the @p LTRasterImage grayscale or BGR data to YUV and stores it in an output buffer.
 
 @param data The data to receive the YUV data. If nil, this method will return the expected size of the YUV data buffer. If not nil, the YUV data will be extracted and stored in @p data.
 @param format Specifies the YUV data format.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The expected size of the YUV data buffer.
 */
- (NSInteger)getYUVData:(nullable NSMutableData *)data format:(LTRasterYUVFormat)format error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(getYUVData(data:format:error:));

@end



@interface LTRasterImage (Callbacks)

/** @brief The data callbacks that were used to initialize this @p LTRasterImage, or nil if none were used. */
@property (nonatomic, strong, readonly, nullable) LTRasterImageDataCallbacks *dataCallbacks;

/**
 @brief Initializes this @p LTRasterImage object using the specified parameters and optional managed memory.
 
 @param flags A combination of the @p LTRasterMemoryFlags enuberation members indicating the type of memory to allocate for the image data.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param order The color order for 16-, 24-, 32-, 48-, and 64-bit images. If thre resultant image is less than 16 bits per pixel, this parameter is ignored.
 @param viewPerspective Specified where the beginning of the image is stored. Most file formats start in the lower left corner while some formats start in the upper left corner.
 @param palette The palette that the image will use. You can specify your own palette, or use nil for LEAD's fixed palette. The palette member is used only when @p bitsPerPixel is less than or equal to 8.
 @param data The managed data pointer that will contain the image data when @p flags is @p LTRasterMemoryFlagsUser.
 @param callbacks The data callbacks to use when creating this image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithFlags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor*> *)palette userData:(nullable NSData *)data dataCallbacks:(LTRasterImageDataCallbacks *)callbacks error:(NSError **)error NS_SWIFT_NAME(init(flags:width:height:bitsPerPixel:order:viewPerspective:palette:userData:dataCallbacks:));

/**
 @brief Initializes this @p LTRasterImage object using the specified parameters and optional unmanaged memory.
 
 @param flags A combination of the @p LTRasterMemoryFlags enuberation members indicating the type of memory to allocate for the image data.
 @param width Width of the image in pixels.
 @param height Height of the image in pixels.
 @param bitsPerPixel The number of bits per pixel. Valid values are 1, 2, 3, 4, 5, 6, 7, 8, 16, 24, 32, 48, and 64.
 @param order The color order for 16-, 24-, 32-, 48-, and 64-bit images. If thre resultant image is less than 16 bits per pixel, this parameter is ignored.
 @param viewPerspective Specified where the beginning of the image is stored. Most file formats start in the lower left corner while some formats start in the upper left corner.
 @param palette The palette that the image will use. You can specify your own palette, or use nil for LEAD's fixed palette. The palette member is used only when @p bitsPerPixel is less than or equal to 8.
 @param userData The unmanaged data pointer that will contain the image data when @p flags is @p LTRasterMemoryFlagsUser.
 @paarm dataLength The length in bytes of the data passed to @p data. Only used when @p data is not NULL and flags is @p LTRasterMemoryFlagsUser.
 @param callbacks The data callbacks to use when creating this image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized @p LTRasterImage instance.
 */
- (nullable instancetype)initWithFlags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor *> *)palette userData:(nullable void *)userData userDataLength:(uint64_t)dataLength dataCallbacks:(LTRasterImageDataCallbacks *)callbacks error:(NSError **)error NS_SWIFT_NAME(init(userData:length:flags:width:height:bitsPerPixel:order:viewPerspective:palette:dataCallbacks:));

@end



@interface LTRasterImage (Painting)

/**
 @brief Sets up the paint or paint and image processing methods' window leveling options for this @p LTRasterImage.
 
 @param lowBitValue A value indicating the low bit used for leveling. 0 <= @p lowBit <= @p highBit <= (11 for 12-bit grayscale or 15 for 16-bit grayscale).
 @param highBitValue A value indicating the high bit used for leveling.  0 <= @p lowBit <= @p highBit <= (11 for 12-bit grayscale or 15 for 16-bit grayscale).
 @param palette Optional 8-bit lookup table that can be used to implement a user defined conversion. For every intensity value between 0 and 2 raised to the power of (@p highBit - @p lowBit + 1) - 1 there should be a corresponding entry in the lookup table that contains a color. If @p palette is nil, the conversion is a normal shift (right or left) and the painted image is 8-bit grayscale. If @p palette is not nil, the pained image is a 24-bit image.
 @param mode A value indicating whether @p palette is used by the paint and image processing methods or only by the paint methods.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the options were set, otherwise NO.
 */
- (BOOL)windowLevel:(NSInteger)lowBitValue highBit:(NSInteger)highBitValue palette:(nullable NSArray<LTRasterColor *> *)palette mode:(LTRasterWindowLevelMode)mode error:(NSError **)error NS_SWIFT_NAME(windowLevel(lowBit:highBit:palette:mode:));

/**
 @brief Sets up the paint or paint and image processing methods' window leveling options for this @p LTRasterImage.
 
 @param lowBitValue A value indicating the low bit used for leveling. 0 <= @p lowBit <= @p highBit <= (11 for 12-bit grayscale or 15 for 16-bit grayscale).
 @param highBitValue A value indicating the high bit used for leveling.  0 <= @p lowBit <= @p highBit <= (11 for 12-bit grayscale or 15 for 16-bit grayscale).
 @param palette Optional 16-bit lookup table that can be used to implement a user defined conversion. For every intensity value between 0 and 2 raised to the power of (@p highBit - @p lowBit + 1) - 1 there should be a corresponding entry in the lookup table that contains a color. If @p palette is nil, the conversion is a normal shift (right or left) and the painted image is 8 or 16-bit grayscale. If @p palette is not nil, the pained image is a 48-bit image.
 @param mode A value indicating whether @p palette is used by the paint and image processing methods or only by the paint methods.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the options were set, otherwise NO.
 */
- (BOOL)windowLevelExt:(NSInteger)lowBitValue highBit:(NSInteger)highBitValue palette:(nullable NSArray<LTRasterColor16 *> *)palette mode:(LTRasterWindowLevelMode)mode error:(NSError **)error NS_SWIFT_NAME(windowLevel(lowBit:highBit:palette:mode:));


/**
 @brief Adjusts the given rectangle based on the given paint mode properties.
 
 @param sourceWidth The width of the source rectangle.
 @param sourceHeight The height of the source rectangle.
 @param dstRect The destination rectangle.
 @param sizeMode A value that controls how the source rectangle is positioned inside the destination rectangle.
 @param horizontalAlignMode A value that controls how the source rectangle is aligned horizontally inside the destination rectangle.
 @param verticalAlignMode A value that controls how the source rectangle is aligned vertically inside the destination rectangle.
 
 @returns The new desintation rectangle adjusted based onn the size mode and alignment.
 */
+ (LeadRect)calculatePaintModeRectangle:(NSInteger)sourceWidth sourceHeight:(NSInteger)sourceHeight destinationRectangle:(LeadRect)dstRect sizeMode:(LTRasterPaintSizeMode)sizeMode horizontalAlignMode:(LTRasterPaintAlignMode)horizontalAlignMode verticalAlignMode:(LTRasterPaintAlignMode)verticalAlignMode NS_SWIFT_NAME(calculatePaintModeRectangle(sourceWidth:sourceHeight:destinationRectangle:sizeMode:horizontalAlignMode:verticalAlignMode:));

@end



@interface LTRasterImage (Metadata)

/** @brief The collection of tag data used when reading and writing certain file formats (including TIFF). */
@property (nonatomic, assign, readonly, nullable) NSMutableArray<LTRasterTagMetadata *>     *tags;

/** @brief The collection of GeoKeys used when reading and writing Geo TIFF files. */
@property (nonatomic, assign, readonly, nullable) NSMutableArray<LTRasterTagMetadata *>     *geoKeys;

/** @brief The collection of comment data used when reading and writing certain file formats (including GIF). */
@property (nonatomic, assign, readonly, nullable) NSMutableArray<LTRasterCommentMetadata *> *comments;

/** @brief The collection of marker data used when reading and writing certain file formats (including JPEG). */
@property (nonatomic, assign, readonly, nullable) NSMutableArray<LTRasterMarkerMetadata *>  *markers;


/**
 @brief Copies the metadata (tags, comment, and markers) to the given image.
 
 @param image The destination image.
 @param flags The type of metadata to copy.
 */
- (void)copyMetadataTo:(LTRasterImage *)image flags:(LTRasterMetadataFlags)flags NS_SWIFT_NAME(copyMetadata(to:flags:));

@end



@interface LTRasterImage (Overlay)

/** @brief The number of overlays that have been defined for this @p LTRasterImage. */
@property (nonatomic, assign, readonly) NSUInteger overlayCount;


/**
 @brief Gets the overlay image for the specified index.
 
 @param index The index of the overlay being retrieved. This index is zero-based and should be less than or equal to @p maxOverlays.
 @param mode A value that determines how to retrieve the image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns A @p LTRasterImage object that represents the overlay image of the specified index.
 */
- (nullable LTRasterImage *)getOverlayForImageAtIndex:(NSInteger)index mode:(LTRasterGetSetOverlayImageMode)mode error:(NSError **)error NS_SWIFT_NAME(overlay(at:mode:));

/**
 @brief Sets the overlay image for a certain index.
 
 @param overlayImage The new overlay image. This can be nil, in which case the corresponding overlay image will be freed.
 @param index The index of the overlay for which to set the image. This  index is zero-based and should be less than or equal to @p maxOverlays.
 @param mode A value that determines how to retrieve the image.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the overlay is set, otherwise NO.
 */
- (BOOL)setOverlay:(nullable LTRasterImage *)overlayImage forImageAtIndex:(NSInteger)index mode:(LTRasterGetSetOverlayImageMode)mode error:(NSError **)error NS_SWIFT_NAME(setOverlay(_:at:mode:));

/**
 @brief Changes the size of the overlay image for a certain index.
 
 @param size The new image size (width, height).
 @param index The index of the overlay for which to set the image size. This index is zero-based and should be less than or equal to @p maxOverlays.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the overlay is set, otherwise NO.
 */
- (BOOL)setOverlaySize:(LeadSize)size forImageAtIndex:(NSInteger)index error:(NSError **)error NS_SWIFT_NAME(setOverlaySize(_:at:));


/**
 @brief Updates the overlay image pixels with the bits from the corresponding bitplane of the main image.
 
 @param flags The flags that determine whether the main image or the overlay image should be updated.
 @param index The index of the overlay used in the process.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the overlay is updated, otherwise NO.
 */
- (BOOL)updateOverlayBitFlags:(LTRasterUpdateOverlayBitsFlags)flags forImageAtIndex:(NSInteger)index error:(NSError **)error NS_SWIFT_NAME(updateOverlayBitFlags(_:at:));


/**
 @brief Gets one or more overlay attributes for the specified index.
 
 @param index The zero-based index of the overlay for which to get the attributes.
 @param flags The flags that determine which attributes to retrieve.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns An @p LTRasterOverlayAttributes object filled with the attribute data requested or nil if the image does not have an overlay attribute at the specific index.
 */
- (nullable LTRasterOverlayAttributes *)getOverlayAttributesAtIndex:(NSInteger)index flags:(LTRasterGetSetOverlayAttributesFlags)flags error:(NSError **)error NS_SWIFT_NAME(overlayAttributes(at:flags:));

/**
 @brief Updates the overlay attributes for the overlay at the specified index.
 
 @param attributes A @p LTRasterOverlayAttributes object containing the overlay attributes to set.
 @param index the zero-based index of the overlay for which the attributes are being set.
 @param flags The flags that determine which attributes to set.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the attributes were updated, otherwise NO.
 */
- (BOOL)updateOverlayAttributes:(LTRasterOverlayAttributes *)attributes atIndex:(NSInteger)index flags:(LTRasterGetSetOverlayAttributesFlags)flags error:(NSError **)error NS_SWIFT_NAME(updateOverlayAttributes(_:at:flags:));

/**
 @brief Gets the true (RGB) value of the specified color based on the current image palette.
 
 @param color A @p LTRasterColor that specifies the source color.
 
 @returns A @p LTRasterColor that is guaranteed to be a true color (has RGB value).
 */
- (LTRasterColor *)getTrueColorValue:(LTRasterColor *)color NS_SWIFT_NAME(trueColorValue(of:));

/**
 @brief Combines two images so that one appears to be an underlying texture for the other.
 
 @param underlayImage The image that will be used as the underlying image. This is the image that appears to be on bottom and is grayscaled as it is combined with the target image.
 @param flags A value that indicates how the underlying image is to be positioned.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the images were combined, otherwise NO.
 */
- (BOOL)underlay:(LTRasterImage *)underlayImage flags:(LTRasterImageUnderlayFlags)flags error:(NSError **)error NS_SWIFT_NAME(underlay(_:flags:));

@end



@interface LTRasterImage (Animation)

/** @brief A value that indicates whether or not the @p LTRasterImageAnimator object should wait for user input in the current frame. */
@property (nonatomic, assign) BOOL animationWaitUserInput;

/** @brief A value indicates the animation offset for the current frame. */
@property (nonatomic, assign) LeadPoint animationOffset;

/** @brief A value that indicates the animation delay in milliseconds (ms) for the current frame. */
@property (nonatomic, assign) NSUInteger animationDelay;

/** @brief A value that indicates the animation background color for the current frame. */
@property (nonatomic, copy)   LTRasterColor *animationBackground;

/** @brief A value that indicates the animation disposal method for the current frame. */
@property (nonatomic, assign) LTRasterImageAnimationDisposalMethod animationDisposalMethod;


/** @brief A value that indicates the global loop count for animated images. */
@property (nonatomic, assign) NSInteger animationGlobalLoop;

/** @brief A value that indicates the global size of the animation image. */
@property (nonatomic, assign) LeadSize animationGlobalSize;

/** @brief A value that indicates the global background color of the animation image. */
@property (nonatomic, copy)   LTRasterColor *animationGlobalBackground;

@end



@interface LTRasterImage (Deprecated)

+ (nullable instancetype)createColoredWithWidth:(unsigned int)inWidth height:(unsigned int)inHeight bitsPerPixel:(unsigned int)inBitsPerPixel resolution:(unsigned int)resolution backgroundColor:(nullable LTRasterColor *)backgroundColor error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "coloredImageWithWidth:height:bitsPerPixel:resolution:backgroundColor:error:");

+ (nullable instancetype)createGrayscaleWithWidth:(unsigned int)inWidth height:(unsigned int)inHeight bitsPerPixel:(unsigned int)inBitsPerPixel resolution:(unsigned int)resolution error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "grayscaleImageWithWidth:height:bitsPerPixel:resolution:error:");

- (nullable instancetype)initWithNSData:(nullable NSData *)data flags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor*> *)palette error:(NSError **)error LT_DEPRECATED_USENEW(20_0, "initWithFlags:width:height:bitsPerPixel:order:viewPerspective:palette:userData:error:");
- (nullable instancetype)initWithUserData:(nullable void *)data userDataLength:(uint64_t)dataLength flags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor *> *)palette error:(NSError **)error  LT_DEPRECATED_USENEW(20_0, "initWithFlags:width:height:bitsPerPixel:order:viewPerspective:palette:userData:userDataLength:error:");

- (nullable instancetype)initWithNSData:(nullable NSData *)data flags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor*> *)palette dataCallbacks:(LTRasterImageDataCallbacks *)callbacks error:(NSError **)error LT_DEPRECATED_USENEW(20_0, "initWithFlags:width:height:bitsPerPixel:order:viewPerspective:palette:userData:dataCallbacks:error:");
- (nullable instancetype)initWithUserData:(nullable void *)data userDataLength:(uint64_t)dataLength flags:(LTRasterMemoryFlags)flags width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective palette:(nullable NSArray<LTRasterColor *> *)palette dataCallbacks:(LTRasterImageDataCallbacks *)callbacks error:(NSError **)error LT_DEPRECATED_USENEW(20_0, "initWithFlags:width:height:bitsPerPixel:order:viewPerspective:palette:userData:userDataLength:dataCallbacks:error:");

@property (nonatomic, assign, readonly) BOOL isConventionalMemory LT_DEPRECATED_USENEW(19_0, "usesConventionalMemory");
@property (nonatomic, assign, readonly) BOOL isDiskMemory LT_DEPRECATED_USENEW(19_0, "usesDiskMemory");
@property (nonatomic, assign, readonly) BOOL isGlobalMemory LT_DEPRECATED_USENEW(19_0, "usesGlobalMemory");

@property (nonatomic, assign) BOOL transparent LT_DEPRECATED_USENEW(19_0, "isTrasparent");
@property (nonatomic, assign) BOOL signedData LT_DEPRECATED_USENEW(19_0, "isSignedData");

@property (nonatomic, assign) BOOL noRegionClip LT_DEPRECATED_USENEW(19_0, "clipsRegion");

- (nullable LTHandle *)toDib:(LTRasterConvertToDibType)type LT_DEPRECATED_USENEW(20_0, "createDibWithType:");
+ (LTRasterImage *)fromDib:(LTHandle *)dib error:(NSError **)error LT_DEPRECATED_USENEW(20_0, "imageWithDib:error:");

- (unsigned int)getImageWidthDpi:(BOOL)useDpi LT_DEPRECATED_USENEW(19_0, "imageWidthWithDpi:");
- (unsigned int)getImageHeightDpi:(BOOL)useDpi LT_DEPRECATED_USENEW(19_0, "imageHeightWithDpi:");
- (LeadSize)getImageSizeDpi:(BOOL)useDpi LT_DEPRECATED_USENEW(19_0, "imageSizeWithDpi:");

- (void)onChanged:(LTRasterImageChangedFlags)flags LT_DEPRECATED_USENEW(19_0, "didChange:");

- (void)removePageAt:(unsigned int)pageIndex LT_DEPRECATED_USENEW(19_0, "removePageAtIndex:");
- (unsigned int)insertPage:(int)index image:(LTRasterImage *)image LT_DEPRECATED_USENEW(19_0, "insertPage:atIndex:");
- (void)insertPages:(int)index image:(LTRasterImage *)image startIndex:(int)startIndex count:(int)count LT_DEPRECATED_USENEW(19_0, "insertPages:from:count:atIndex:");
- (void)replacePage:(int)index image:(LTRasterImage *)image LT_DEPRECATED_USENEW(19_0, "replacePageAtIndex:withPage:");
- (void)replacePages:(int)index image:(LTRasterImage *)image startIndex:(int)startIndex count:(int)count LT_DEPRECATED_USENEW(19_0, "replacePageAtIndex:withPages:start:count:");

- (NSInteger)addPage:(LTRasterImage *)page LT_DEPRECATED_USENEW(20_0, "addPage:error:");
- (void)addPages:(LTRasterImage *)pages startIndex:(NSInteger)start count:(NSInteger)count LT_DEPRECATED_USENEW(20_0, "addPages:startIndex:count:error:");
- (void)removePageAtIndex:(NSInteger)index NS_SWIFT_NAME(removePage(at:)) LT_DEPRECATED_USENEW(20_0, "removePageAtIndex:error:");
- (void)removePages:(NSInteger)start count:(NSInteger)count NS_SWIFT_NAME(removePages(start:count:)) LT_DEPRECATED_USENEW(20_0, "removePages:count:");
- (void)removeAllPages LT_DEPRECATED_USENEW(20_0, "removeAllPages:");

- (NSInteger)insertPage:(LTRasterImage *)page atIndex:(NSInteger)index LT_DEPRECATED_USENEW(20_0, "insertPage:atIndex:error:");
- (void)insertPages:(LTRasterImage *)pages from:(NSInteger)start count:(NSInteger)count atIndex:(NSInteger)index LT_DEPRECATED_USENEW(20_0, "insertPages:from:count:atIndex:error:");
- (void)replacePageAtIndex:(NSInteger)index withPage:(LTRasterImage *)page NS_SWIFT_NAME(replacePage(at:with:)) LT_DEPRECATED_USENEW(20_0, "replacePageAtIndex:withPage:error:");
- (void)replacePageAtIndex:(NSInteger)index withPages:(LTRasterImage *)pages start:(NSInteger)start count:(NSInteger)count NS_SWIFT_NAME(replacePage(at:with:start:count:)) LT_DEPRECATED_USENEW(20_0, "replacePageAtIndex:withPages:start:count:error:");

- (BOOL)setPalette:(nullable NSArray *)palette startIndex:(unsigned int)startIndex count:(unsigned int)count error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "setPalette:range:error:");

- (unsigned int)calculateRegionMaximumClipSegments LT_DEPRECATED_USENEW(19_0, "maximumClipSegmentsForRegion");
- (size_t)calculateRegionArea LT_DEPRECATED_USENEW(19_0, "regionArea");
- (unsigned int)getRegionClipSegments:(int)row segmentsBuffer:(unsigned int *)segmentsBuffer LT_DEPRECATED_USENEW(19_0, "regionClipSegmentsForRow:segmentsBuffer");
- (BOOL)regionContains:(int)row col:(int)col LT_DEPRECATED_USENEW(19_0, "regionContainsPoint:");
- (BOOL)offsetRegion:(int)rowOffset colOffset:(int)colOffset error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "offsetRegionByAmount:error:");
- (BOOL)addRectangleToRegion:(nullable LTRasterRegionXForm *)xform rc:(LeadRect)rc combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "addRectangleToRegion:rect:combineMode:error:");
- (BOOL)addEllipseToRegion:(nullable LTRasterRegionXForm *)xform rc:(LeadRect)rc combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "addEllipseToRegion:rect:combineMode:error:");

- (NSUInteger)regionClipSegmentsForRow:(NSInteger)row segmentsBuffer:(unsigned int *)buffer LT_DEPRECATED_USENEW(20_0, "regionClipSegmentsForRow:segmentsBuffer:error:");
- (LeadRect)regionBounds:(nullable LTRasterRegionXForm *)xform NS_SWIFT_NAME(regionBounds(xform:)) LT_DEPRECATED_USENEW(20_0, "regionBounds:error:");
- (LeadRect)regionBoundsClipped:(nullable LTRasterRegionXForm *)xform LT_DEPRECATED_USENEW(20_0, "regionBoundsClipped:error:");

- (nullable LTRasterColor *)getPixel:(int)row column:(int)column error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "getPixelAtRow:column:");
- (nullable LTRasterColor *)getPixelColor:(int)row column:(int)column error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "getPixelColorAtRow:column:");
- (BOOL)setPixelColor:(int)row column:(int)column color:(LTRasterColor *)color error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "setColor:forPixelAtRow:column:error:");
- (BOOL)setPixel:(int)row column:(int)column color:(LTRasterColor *)color error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "setPixel:atRow:column:error:");
- (BOOL)getPixelData:(int)row column:(int)column data:(void *)pixelData dataSize:(size_t)pixelDataSize error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "getData:ofSize:forPixelAtRow:column:error:");
- (BOOL)setPixelData:(int)row column:(int)column data:(const void *)pixelData dataSize:(size_t)pixelDataSize error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "setData:ofSize:forPixelAtRow:column:error:");

- (LeadPoint)pointFromImage:(LTRasterViewPerspective)viewPerspectiveToUse pt:(LeadPoint)pt LT_DEPRECATED_USENEW(19_0, "pointFromImage:sourcePoint:");
- (LeadPoint)pointToImage:(LTRasterViewPerspective)viewPerspectiveToUse pt:(LeadPoint)pt LT_DEPRECATED_USENEW(19_0, "pointToImage:sourcePoint:");
- (LeadRect)rectangleFromImage:(LTRasterViewPerspective)viewPerspectiveToUse rc:(LeadRect)rc LT_DEPRECATED_USENEW(19_0, "rectangleFromImage:sourceRect:");
- (LeadRect)rectangleToImage:(LTRasterViewPerspective)viewPerspectiveToUse rc:(LeadRect)rc LT_DEPRECATED_USENEW(19_0, "rectangleToImage:sourceRect:");

- (nullable LTRasterImage *)getOverlayImage:(int)index mode:(LTRasterGetSetOverlayImageMode)mode error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "getOverlayForImageAtIndex:mode:error:");
- (BOOL)setOverlayImage:(int)index overlayImage:(nullable LTRasterImage *)overlayImage mode:(LTRasterGetSetOverlayImageMode)mode error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "setOverlay:forImageAtIndex:mode:error:");
- (BOOL)setOverlayImageSize:(int)index overlayWidth:(unsigned int)overlayWidth overlayHeight:(unsigned int)overlayHeight error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "setOverlaySize:forImageAtIndex:error::");
- (BOOL)updateOverlayBits:(int)index flags:(LTRasterUpdateOverlayBitsFlags)flags error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "updateOverlayBitFlags:forImageAtIndex:error:");
- (nullable LTRasterOverlayAttributes *)getOverlayAttributes:(int)index flags:(LTRasterGetSetOverlayAttributesFlags)flags error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "getOverlayAttributes:flags:error:");
- (BOOL)updateOverlayAttributes:(int)index attributes:(LTRasterOverlayAttributes *)attributes flags:(LTRasterGetSetOverlayAttributesFlags)flags error:(NSError **)outError LT_DEPRECATED_USENEW(19_0, "updateOverlayAttributes:atIndex:flags:error:");

@end

NS_ASSUME_NONNULL_END

