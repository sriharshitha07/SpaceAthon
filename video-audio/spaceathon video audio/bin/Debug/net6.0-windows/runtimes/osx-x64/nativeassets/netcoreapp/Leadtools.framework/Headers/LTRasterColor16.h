// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterColor16.h
//  Leadtools
//

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Describes a color consisting of 16-bit relative intensities of alpha, red, gree, and blue.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterColor16 : NSObject <NSCopying, NSSecureCoding>

/** The red component of the color */
@property (nonatomic, assign) unsigned short r;

/** The green component of the color */
@property (nonatomic, assign) unsigned short g;

/** The blue component of the color */
@property (nonatomic, assign) unsigned short b;

/** The alpha component of the color */
@property (nonatomic, assign) unsigned short a;

/** For internal use by LEADTOOLS */
@property (nonatomic, assign) unsigned short reserved;



/** Maximum value for the alpha, red, green, blue component. */
@property (class, nonatomic, assign, readonly) unsigned short maximumComponent;

/** Minimum value for the alpha, red, green, blue component. */
@property (class, nonatomic, assign, readonly) unsigned short minimumComponent;

/**
 @brief Creates a LTRasterColor16 instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 @param alpha The alpha color component.
 
 @returns An initialized LTRasterColor16 instance.
 */
+ (instancetype)colorWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha OBJC_SWIFT_UNAVAILABLE("use object initializers instead");;

/**
 @brief Creates a LTRasterColor16 instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 
 @returns An initialized LTRasterColor16 instance.
 */
+ (instancetype)colorWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue OBJC_SWIFT_UNAVAILABLE("use object initializers instead");;

/**
 @brief Creates a LTRasterColor16 instance representing white.
 
 @returns An initialized LTRasterColor16 instance.
 */
@property (class, nonatomic, readonly) LTRasterColor16 *white;

/**
 @brief Creates a LTRasterColor16 instance representing black.
 
 @returns An initialized LTRasterColor16 instance.
 */
@property (class, nonatomic, readonly) LTRasterColor16 *black;

/**
 @brief Initializes a LTRasterColor16 instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 @param alpha The alpha color component.
 
 @returns An initialized LTRasterColor16 instance.
 */
- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha NS_DESIGNATED_INITIALIZER;

/**
 @brief Initializes a LTRasterColor16 instance with explicit color components.
 
 @param red The red color component.
 @param green The green color component.
 @param blue The blue color component.
 
 @returns An initialized LTRasterColor16 instance.
 */
- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue;

@end

NS_ASSUME_NONNULL_END
