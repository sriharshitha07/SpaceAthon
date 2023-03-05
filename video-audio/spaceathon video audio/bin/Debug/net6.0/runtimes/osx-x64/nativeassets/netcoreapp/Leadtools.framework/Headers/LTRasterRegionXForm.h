// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterRegionXForm.h
//  Leadtools
//

#import <Leadtools/LTLeadtoolsDefines.h>

/**
 Provides data for translating between region coordinates and external representations of those coordinates.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterRegionXForm : NSObject <NSCopying, NSSecureCoding>

/** @brief The view perspective of the external representation */
@property (nonatomic, assign) LTRasterViewPerspective viewPerspective;

/** @brief The numerator for the X scaling factor. */
@property (nonatomic, assign) NSInteger xScalarNumerator;

/** @brief The denominator for the X scaling factor. */
@property (nonatomic, assign) NSInteger xScalarDenominator;

/** @brief The numerator for the Y scaling factor. */
@property (nonatomic, assign) NSInteger yScalarNumerator;

/** @brief The denominator for the Y scaling factor. */
@property (nonatomic, assign) NSInteger yScalarDenominator;

/** @brief The X offset of the external representation. */
@property (nonatomic, assign) NSInteger xOffset;

/** @brief The Y offset of the external representation. */
@property (nonatomic, assign) NSInteger yOffset;



@property (class, nonatomic, strong, readonly) LTRasterRegionXForm *defaultXForm NS_SWIFT_NAME(default);

@end
