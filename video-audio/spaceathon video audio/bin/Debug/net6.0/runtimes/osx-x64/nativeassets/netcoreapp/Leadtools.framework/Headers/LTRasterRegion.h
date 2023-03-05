// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterRegion.h
//  Leadtools
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterRegionXForm.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Describes a region of interest in a LTRasterImage object.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterRegion : NSObject <NSCopying, NSSecureCoding>

/** @brief Checks if this LTRasterRegion has an empty interior. */
@property (nonatomic, assign, readonly, getter=isEmpty) BOOL empty;

/** @brief A LeadRect structure representing a rectangle that bounds this LTRasterRegion in pixels. */
@property (nonatomic, assign, readonly)                 LeadRect bounds;

/** @brief An array out LeadPoints that contains the outline of this region or @p nil if the region is empty. */
@property (nonatomic, strong, readonly, nullable)       NSArray<NSArray<NSValue/*LeadPoint*/ *> *> *outline;

/** @brief Gets data that represents the information that describes this region or @p nil if the region is empty */
@property (nonatomic, strong, readonly, nullable)       NSData *regionData;

/**
 @brief Gets data that represents the information that describes this @p LTRasterRegion.
 
 @param data The region data to set
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the region data was set successfully, NO otherwise
 */
- (BOOL)setRegionData:(NSData *)data error:(NSError **)error;

/**
 @brief Initializes a rectangular @p LTRasterRegion with bounds equal to the bounds of the rectangle
 
 @param rect A LeadRect describing the bounds for this @p LTRasterRegion.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly initialized @p LTRasterRegion
 */
- (nullable instancetype)initWithRect:(LeadRect)rect error:(NSError **)error;

/**
 @brief Initializes a rectangular @p LTRasterRegion with bounds equal to the bounds of the rectangle
 
 @param rect A LeadRect describing the bounds for this @p LTRasterRegion.
 @param xform A @p LTRasterRegionXForm object that is used to translate between display coordinates and image coordinates. If you specify @p nil for this parameter, the scalar field default to 1, the offsets default to 0, and the view perspective defaults to the image view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly initialized @p LTRasterRegion
 */
- (nullable instancetype)initWithRect:(LeadRect)rect xform:(LTRasterRegionXForm *)xform error:(NSError **)error;

/**
 @brief Initializes an elliptical @p LTRasterRegion with bounds equal to the bounds of the rectangle
 
 @param bounds A LeadRect describing the bounds for this elliptical @p LTRasterRegion.
 @param xform A @p LTRasterRegionXForm object that is used to translate between display coordinates and image coordinates. If you specify @p nil for this parameter, the scalar field default to 1, the offsets default to 0, and the view perspective defaults to the image view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly initialized @p LTRasterRegion
 */
- (nullable instancetype)initWithEllipse:(LeadRect)bounds xform:(LTRasterRegionXForm *)xform error:(NSError **)error;

/**
 @brief Initializes a rounded rectangular @p LTRasterRegion with bounds equal to the bounds of the rectangle
 
 @param rect A LeadRect describing the bounds for this @p LTRasterRegion.
 @param ellipse A LeadSize describing the width and height of the rounded corners for this @p LTRasterRegion.
 @param xform A @p LTRasterRegionXForm object that is used to translate between display coordinates and image coordinates. If you specify @p nil for this parameter, the scalar field default to 1, the offsets default to 0, and the view perspective defaults to the image view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly initialized @p LTRasterRegion
 */
- (nullable instancetype)initWithRoundRect:(LeadRect)rect ellipse:(LeadSize)ellipse xform:(LTRasterRegionXForm *)xform error:(NSError **)error;

/**
 @brief Initializes a polygonal @p LTRasterRegion with the specified points
 
 @param points An array of @p LeadPoint values. The points in the collection must be in the order in which the vertices of the polygon are connected. To create the line that closes the polygon, the last point in the array is connected to the first point in the array.
 @param fillMode A @p LTLeadFillMode indicating how to handle complex crossing lines.
 @param xform A @p LTRasterRegionXForm object that is used to translate between display coordinates and image coordinates. If you specify @p nil for this parameter, the scalar field default to 1, the offsets default to 0, and the view perspective defaults to the image view perspective.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly initialized @p LTRasterRegion
 */
- (nullable instancetype)initWithPolygon:(NSArray<NSValue/*LeadPoint*/ *> *)points fillMode:(LTLeadFillMode)fillMode xform:(LTRasterRegionXForm *)xform error:(NSError **)error;

/**
 @brief Initializes a @p LTRasterRegion with the specified data
 
 @param regionData Data that represents the information that describes a @p LTRasterRegion
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The newly initialized @p LTRasterRegion
 */
- (nullable instancetype)initWithRegionData:(NSData *)regionData error:(NSError **)error;

/**
 @brief Initializes this LTRasterRegion to an empty interior.
 */
- (void)makeEmpty;

/**
 @brief Updates this LTRasterRegion to a combination of itself and the specified LeadRect.
 
 @param rect The LeadRect structure to combine with this LTRasterRegion.
 @param combineMode One of the LTRasterRegionCombineMode enumeration members that describes the combine method to use. This cannot be LTRasterRegionCombineModeAndNotImage or LTRasterRegionCombineModeAndNotRegion. Using any of these combine method will result in an exception.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the LeadRect and LTRasterRegion combined successfully, otherwise NO.
 */
- (BOOL)combineWithRect:(LeadRect)rect combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error;

/**
 @brief Updates this LTRasterRegion to a combination of itself and the specified LTRasterRegion.
 
 @param region The LTRasterRegion to combine with this LTRasterRegion.
 @param combineMode One of the LTRasterRegionCombineMode enumeration members that describes the combine method to use. This cannot be LTRasterRegionCombineModeAndNotImage or LTRasterRegionCombineModeAndNotRegion. Using any of these combine method will result in an exception.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the regions combined successfully, otherwise NO.
 */
- (BOOL)combineWithRegion:(LTRasterRegion *)region combineMode:(LTRasterRegionCombineMode)combineMode error:(NSError **)error;

/**
 @brief Tests whether the specified LeadPoint structure is contained within this LTRasterRegion.
 
 @param point The LeadPoint structure to test.
 
 @returns YES is the point is contained within this LTRasterRegion, otherwise NO.
 */
- (BOOL)isVisible:(LeadPoint)point;

/**
 @brief Trims this LTRasterRegion to fit inside a specified LeadRect.
 
 @param rect A LeadRect that defines the clipping boundaries.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if this LTRasterRegion was clipped successfully, otherwise NO.
 */
- (BOOL)clip:(LeadRect)rect error:(NSError **)error;

/**
 @brief Transforms this LTRasterRegion by the specified LTRasterRegionXForm.
 
 @param xform The LTRasterRegionXForm by which to transform this region.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if this LTRasterRegion was transformed successfully, otherwise NO.
 */
- (BOOL)transform:(LTRasterRegionXForm *)xform error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
