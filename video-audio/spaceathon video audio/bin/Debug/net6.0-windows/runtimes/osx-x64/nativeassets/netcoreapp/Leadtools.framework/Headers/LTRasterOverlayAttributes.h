// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterOverlayAttributes.h
//  Leadtools
//

#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Contains the overlay attributes of a DICOM Image.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterOverlayAttributes : NSObject <NSCopying, NSSecureCoding>

/** @brief A value that determines whether to paint the overlay automatically when the image is painted. */
@property (nonatomic, assign)         BOOL autoPaint;

/** @brief A value that determines whether to automatically adjust the overlay image and position when the main image changes. */
@property (nonatomic, assign)         BOOL autoProcess;

/** @brief A value that determines whether the overlay has a corresponding bitplane is the main image. */
@property (nonatomic, assign)         BOOL useBitPlane;


/** @brief The corresponding bit plane associated with an overlay. */
@property (nonatomic, assign)         NSUInteger bitPosition;

/** @brief The number of rows in the overlay. */
@property (nonatomic, assign)         NSUInteger rows;

/** @brief The number of columns in the overlay. */
@property (nonatomic, assign)         NSUInteger columns;

/** @brief The number of bits allocated in the overlay */
@property (nonatomic, assign)         NSUInteger bitsAllocated;

/** @brief The number of the frame of a multi-frame image to which this overlay applies. */
@property (nonatomic, assign)         NSUInteger imageFrameOrigin;


/** @brief The number os frame in the overlay. */
@property (nonatomic, assign)         NSInteger framesInOverlay;

/** @brief The number of pixels in the Region of Interest area. */
@property (nonatomic, assign)         NSInteger roiArea;


/** @brief The average value of the pixels in the Region of Interest. */
@property (nonatomic, assign)         double roiMean;

/** @brief The standard deviation of the pixel values in the Region of Interest. */
@property (nonatomic, assign)         double roiStandardDeviation;


/** @brief A value that indicates whether this overlay represents a region of interest or other graphics. */
@property (nonatomic, copy, nullable) NSString *type;

/** @brief A value that contains user-defined comments about the overlay. */
@property (nonatomic, copy, nullable) NSString *description;

/** @brief A value that contains a defined term that identifies the intended purpose fo the overlay type. */
@property (nonatomic, copy, nullable) NSString *subtype;

/** @brief A value that contains user defined text, which may be used to label or name this overlay. */
@property (nonatomic, copy, nullable) NSString *label;

/** @brief A value that identifies the layer in which the overlay shall be displayed. */
@property (nonatomic, copy, nullable) NSString *activationLayer;


/** @brief Origin (top left point), in pixels, of the overlay image. */
@property (nonatomic, assign)         LeadPoint origin;

/** @brief The color used to display the pixels in the overlay image with a value of 1. */
@property (nonatomic, copy)           LTRasterColor *color;

@end

NS_ASSUME_NONNULL_END
