// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterColor.h
//  Leadtools
//

#if TARGET_OS_IOS || TARGET_OS_TV
#   import <UIKit/UIColor.h>
#elif TARGET_OS_OSX
#   import <AppKit/NSColor.h>
#else
#   error "Unsupported Target OS"
#endif // #if TARGET_OS_IOS

#import <Leadtools/LTRasterKnownColor.h>

NS_ASSUME_NONNULL_BEGIN

/** 
 @brief Describes a color consisting of 8-bit relative intensities of alpha, red, gree, and blue.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterColor : NSObject <NSCopying, NSSecureCoding>

/** The red component of the color */
@property (nonatomic, assign) unsigned char r;

/** The green component of the color */
@property (nonatomic, assign) unsigned char g;

/** The blue component of the color */
@property (nonatomic, assign) unsigned char b;

/** The alpha component of the color */
@property (nonatomic, assign) unsigned char a;

/** For internal use by LEADTOOLS */
@property (nonatomic, assign) unsigned char reserved;



/** The 32-bit RGB representation of this @p LTRasterColor */
@property (nonatomic, assign, readonly) uint32_t RGB;

/** The 32-bit ARGB representation of this @p LTRasterColor */
@property (nonatomic, assign, readonly) uint32_t ARGB;

/** The 32-bit RGBA representation of this @p LTRasterColor */
@property (nonatomic, assign, readonly) uint32_t RGBA;

/** A value indicating whether this @p LTRasterColor instance is a predefined color. Predefined colors are represented by the elements of the @p LTRasterKnownColor enumeration. */
@property (nonatomic, assign, readonly) BOOL isKnownColor;

/** The known color enumeration member that matches this color ARGB value. */
@property (nonatomic, assign, readonly) LTRasterKnownColor knownColor;

/** Returns this @p LTRasterColor as an HTML color string. */
@property (nonatomic, copy, readonly)   NSString *htmlString;



/** Maximum value for the alpha, red, green, blue component. */
@property (class, nonatomic, assign, readonly) unsigned char maximumComponent;

/** Minimum value for the alpha, red, green, blue component. */
@property (class, nonatomic, assign, readonly) unsigned char minimumComponent;

/** 
 @brief Creates a @p LTRasterColor instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 @param alpha The alpha color component.
 
 @returns An initialized LTRasterColor instance.
 */
+ (LTRasterColor *)colorWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

/**
 @brief Creates a @p LTRasterColor instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 
 @returns An initialized LTRasterColor instance.
 */
+ (LTRasterColor *)colorWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

/**
 @brief Creates a @p LTRasterColor instance with an ARGB value.
 
 @param argb The color components.
 
 @returns An initialized LTRasterColor instance.
 */
+ (LTRasterColor *)colorWithARGB:(uint32_t)argb;

/**
 @brief Creates a @p LTRasterColor instance with an RGB value.
 
 @param rgb The color components.
 
 @returns An initialized LTRasterColor instance.
 */
+ (LTRasterColor *)colorWithRGB:(uint32_t)rgb;

/**
 @brief Creates a @p LTRasterColor instance with an RGBA value.
 
 @param rgba The color components.
 
 @returns An initialized LTRasterColor instance.
 */
+ (LTRasterColor *)colorWithRGBA:(uint32_t)rgba;

/**
 @brief Initializes a @p LTRasterColor instance with a known color value.
 
 @param color The known color value.
 
 @returns An initialized LTRasterColor instance.
 */
+ (LTRasterColor *)colorWithKnownColor:(LTRasterKnownColor)color;

/**
 @brief Creates a @p LTRasterColor instance representing white.
 
 @returns An initialized LTRasterColor instance.
 */
@property (class, nonatomic, readonly) LTRasterColor *white;

/**
 @brief Creates a @p LTRasterColor instance representing black.
 
 @returns An initialized LTRasterColor instance.
 */
@property (class, nonatomic, readonly) LTRasterColor *black;

/**
 @brief Initializes a @p LTRasterColor instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 @param alpha The alpha color component.
 
 @returns An initialized LTRasterColor instance.
 */
- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha NS_DESIGNATED_INITIALIZER;

/**
 @brief Initializes a @p LTRasterColor instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 
 @returns An initialized LTRasterColor instance.
 */
- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue;

/**
 @brief Initializes a @p LTRasterColor instance with an ARGB value.
 
 @param argb The color components.
 
 @returns An initialized LTRasterColor instance.
 */
- (instancetype)initWithARGB:(uint32_t)argb;

/**
 @brief Initializes a @p LTRasterColor instance with an RGB value.
 
 @param rgb The color components.
 
 @returns An initialized LTRasterColor instance.
 */
- (instancetype)initWithRGB:(uint32_t)rgb;

/**
 @brief Initializes a @p LTRasterColor instance with an RGBA value.
 
 @param rgba The color components.
 
 @returns An initialized LTRasterColor instance.
 */
- (instancetype)initWithRGBA:(uint32_t)rgba;

/**
 @brief Initializes a @p LTRasterColor instance with a known color value.
 
 @param color The known color value.
 
 @returns An initialized LTRasterColor instance.
 */
- (instancetype)initWithKnownColor:(LTRasterKnownColor)color;

@end



@interface LTRasterColor (RasterColorConversions)

/** Creates a platform color instance using the current values for this instance */
#if TARGET_OS_IOS || TARGET_OS_TV
@property (nonatomic, copy, readonly)   UIColor *UIColor;
#elif TARGET_OS_OSX
@property (nonatomic, copy, readonly)   NSColor *NSColor;
#endif

/** Returns the associated CGColorRef for the platform color property */
@property (nonatomic, assign, readonly) CGColorRef CGColor CF_RETURNS_RETAINED;

@end

#if TARGET_OS_IOS || TARGET_OS_TV
@interface UIColor (RasterColorConversions)
#elif TARGET_OS_OSX
@interface NSColor (RasterColorConversions)
#endif

/** Creates a LTRasterColor instance using the current values for this instance */
@property (nonatomic, copy, readonly) LTRasterColor *LTRasterColor;

@end

NS_ASSUME_NONNULL_END
