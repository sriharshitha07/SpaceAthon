// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTPrimitives.h
//  Leadtools
//

#if !defined(LTPRIMITIVES_XCODE_H)
#define LTPRIMITIVES_XCODE_H

#import <objc/NSObjCRuntime.h> // NSInteger
#import <CoreFoundation/CFBase.h> // CF_INLINE
#import <CoreGraphics/CGGeometry.h> // CGPoint, CGSize, etc.
#import <CoreGraphics/CGAffineTransform.h> // CGAffineTransform

#import <Leadtools/LTLeadtools.h>

#define LT_INLINE CF_INLINE

#pragma pack(1)

/**
 @typedef LeadPoint
 
 @brief Stores two integer numbers that represent the coordinates of a point (X and Y).
 */
// Integer point
typedef struct LeadPoint {
   NSInteger x;
   NSInteger y;
} LT_BOXABLE LeadPoint;

/** 
 @typedef LeadSize
 
 @brief Stores two integer numbers that represent a size (Width and Height).
 */
// Integer size
typedef struct LeadSize {
   NSInteger width;
   NSInteger height;
} LT_BOXABLE LeadSize;

/** 
 @typedef LeadRect
 
 @brief Stores four integer numbers that represent the coordinates and size of a rectangle (X, Y, Width, and Height).
 */
// Integer rect
typedef struct LeadRect {
   NSInteger x;
   NSInteger y;
   NSInteger width;
   NSInteger height;
} LT_BOXABLE LeadRect;

/**
 @typedef LeadPointD
 
 @brief Stores two double numbers that represent the coordinates of a point (X and Y).
 */
// Double point
typedef struct LeadPointD {
   double x;
   double y;
} LT_BOXABLE LeadPointD;

/**
 @typedef LeadSizeD
 
 @brief Stores two double numbers that represent a size (Width and Height).
 */
// Double size
typedef struct LeadSizeD {
   double width;
   double height;
} LT_BOXABLE LeadSizeD;
/**
 @typedef LeadRectD
 
 @brief Stores four double numbers that represent the coordinates and size of a rectangle (X, Y, Width, and Height).
 */
// Double rect
typedef struct LeadRectD {
   double x;
   double y;
   double width;
   double height;
} LT_BOXABLE LeadRectD;

/** 
 @typedef LeadLengthD
 
 @brief Defines a double length value.
 */
// Double length
typedef struct LeadLengthD {
   double value;
} LT_BOXABLE LeadLengthD;

/** 
 @typedef LeadMatrix
 
 @brief Represents a 3x3 affine transformation matrix used for transformations in 2D space.
 */
// Double matrix
// Do not set the values of this matrix directly, instead use
// LeadMatrixGetM11/SetM11 for example or LeadMatrixSet
// This will ensure that type is set to the correct internal type
// and greatly speeds up the matrix operations
typedef struct LeadMatrix {
   double m11;
   double m12;
   double m21;
   double m22;
   double offsetX;
   double offsetY;
   NSInteger type;
   NSInteger padding;
} LT_BOXABLE LeadMatrix;

// NAN
LEADTOOLS_EXPORT const double LT_NAN;



// LeadPoint functions
LEADTOOLS_EXPORT LeadPoint LeadPoint_Make(int x, int y) LT_DEPRECATED_USENEW(19_0, "LeadPointMake");
LEADTOOLS_EXPORT LeadPoint LeadPoint_Empty(void) LT_DEPRECATED_USENEW(19_0, "LeadPointZero");
LEADTOOLS_EXPORT int LeadPoint_IsEmpty(LeadPoint point) LT_DEPRECATED_USENEW(19_0, "LeadPointIsZero");
LEADTOOLS_EXPORT int LeadPoint_IsEqual(LeadPoint point1, LeadPoint point2) LT_DEPRECATED_USENEW(19_0, "LeadPointEqualToPoint");

// // // // // // // //
LT_INLINE LeadPoint LeadPointMake(NSInteger x, NSInteger y);

LEADTOOLS_EXPORT const LeadPoint LeadPointZero CF_SWIFT_NAME(LeadPoint.zero);

LEADTOOLS_EXPORT BOOL LeadPointIsZero(LeadPoint point1) CF_SWIFT_NAME(getter:LeadPoint.isZero(self:));
LEADTOOLS_EXPORT BOOL LeadPointEqualToPoint(LeadPoint point1, LeadPoint point2) CF_SWIFT_NAME(LeadPoint.equalTo(self:_:));

LEADTOOLS_EXPORT CGPoint CGPointFromLeadPoint(LeadPoint point) CF_SWIFT_NAME(getter:LeadPoint.cgPoint(self:));

LEADTOOLS_EXPORT LeadPoint LeadPointFromCGPoint(CGPoint point) CF_SWIFT_NAME(LeadPoint.init(_:));
LEADTOOLS_EXPORT LeadPoint LeadPointFromLeadPointD(LeadPointD point) CF_SWIFT_NAME(LeadPoint.init(_:));
// // // // // // // //



// LeadSize functions
LEADTOOLS_EXPORT LeadSize LeadSize_Make(int width, int height) LT_DEPRECATED_USENEW(19_0, "LeadSizeMake");
LEADTOOLS_EXPORT LeadSize LeadSize_Empty(void) LT_DEPRECATED_USENEW(19_0, "LeadSizeZero");
LEADTOOLS_EXPORT int LeadSize_IsEmpty(LeadSize size) LT_DEPRECATED_USENEW(19_0, "LeadSizeIsZero");
LEADTOOLS_EXPORT int LeadSize_IsEqual(LeadSize size1, LeadSize size2) LT_DEPRECATED_USENEW(19_0, "LeadPointEqualToPoint");

// // // // // // // //
LT_INLINE LeadSize LeadSizeMake(NSInteger width, NSInteger height);

LEADTOOLS_EXPORT const LeadSize LeadSizeZero CF_SWIFT_NAME(LeadSize.zero);

LEADTOOLS_EXPORT BOOL LeadSizeIsZero(LeadSize size) CF_SWIFT_NAME(getter:LeadSize.isZero(self:));
LEADTOOLS_EXPORT BOOL LeadSizeEqualToSize(LeadSize size1, LeadSize size2) CF_SWIFT_NAME(LeadSize.equalTo(self:_:));

LEADTOOLS_EXPORT CGSize CGSizeFromLeadSize(LeadSize size) CF_SWIFT_NAME(getter:LeadSize.cgSize(self:));

LEADTOOLS_EXPORT LeadSize LeadSizeFromCGSize(CGSize size) CF_SWIFT_NAME(LeadSize.init(_:));
LEADTOOLS_EXPORT LeadSize LeadSizeFromLeadSizeD(LeadSizeD size) CF_SWIFT_NAME(LeadSize.init(_:));
// // // // // // // //



// LeadRect functions
LEADTOOLS_EXPORT LeadRect LeadRect_Make(int x, int y, int width, int height) LT_DEPRECATED_USENEW(19_0, "LeadRectMake");
LEADTOOLS_EXPORT LeadRect LeadRect_FromLTRB(int left, int top, int right, int bottom) LT_DEPRECATED_USENEW(19_0, "LeadRectFromLTRB");
LEADTOOLS_EXPORT LeadRect LeadRect_Empty(void) LT_DEPRECATED_USENEW(19_0, "LeadRectZero");
LEADTOOLS_EXPORT int LeadRect_IsEmpty(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectIsZero");
LEADTOOLS_EXPORT int LeadRect_IsEqual(LeadRect rect1, LeadRect rect2) LT_DEPRECATED_USENEW(19_0, "LeadRectEqualToRect");
LEADTOOLS_EXPORT int LeadRect_Left(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectLeft");
LEADTOOLS_EXPORT int LeadRect_Right(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectRight");
LEADTOOLS_EXPORT int LeadRect_Top(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectTop");
LEADTOOLS_EXPORT int LeadRect_Bottom(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectBottom");
LEADTOOLS_EXPORT LeadPoint LeadRect_TopLeft(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectTopLeft");
LEADTOOLS_EXPORT LeadPoint LeadRect_TopRight(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectTopRight");
LEADTOOLS_EXPORT LeadPoint LeadRect_BottomRight(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectBottomRight");
LEADTOOLS_EXPORT LeadPoint LeadRect_BottomLeft(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectBottomLeft");
LEADTOOLS_EXPORT LeadPoint LeadRect_Location(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectLocation");
LEADTOOLS_EXPORT LeadSize LeadRect_Size(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectSize");
LEADTOOLS_EXPORT int LeadRect_ContainsPoint(LeadRect rect, LeadPoint testPoint) LT_DEPRECATED_USENEW(19_0, "LeadRectContainsPoint");
LEADTOOLS_EXPORT int LeadRect_ContainsRect(LeadRect rect, LeadRect testRect) LT_DEPRECATED_USENEW(19_0, "LeadRectContainsRect");
LEADTOOLS_EXPORT int LeadRect_IntersectsWith(LeadRect rect, LeadRect testRect) LT_DEPRECATED_USENEW(19_0, "LeadRectIntersectsRect");
LEADTOOLS_EXPORT LeadRect LeadRect_Inflate(LeadRect rect, LeadSize size) LT_DEPRECATED_USENEW(19_0, "LeadRectInflate");
LEADTOOLS_EXPORT LeadRect LeadRect_Intersect(LeadRect rect1, LeadRect rect2) LT_DEPRECATED_USENEW(19_0, "LeadRectIntersect");
LEADTOOLS_EXPORT LeadRect LeadRect_Union(LeadRect rect1, LeadRect rect2) LT_DEPRECATED_USENEW(19_0, "LeadRectUnion");
LEADTOOLS_EXPORT LeadRect LeadRect_Offset(LeadRect rect, LeadSize size) LT_DEPRECATED_USENEW(19_0, "LeadRectOffset");
LEADTOOLS_EXPORT LeadRect LeadRect_Standardize(LeadRect rect) LT_DEPRECATED_USENEW(19_0, "LeadRectStandardize");

// // // // // // // //
LT_INLINE LeadRect LeadRectMake(NSInteger x, NSInteger y, NSInteger width, NSInteger height);
LEADTOOLS_EXPORT LeadRect LeadRectFromLTRB(NSInteger left, NSInteger top, NSInteger right, NSInteger bottom) CF_SWIFT_NAME(LeadRect.init(left:top:right:bottom:));

LEADTOOLS_EXPORT const LeadRect LeadRectZero CF_SWIFT_NAME(LeadRect.zero);

LEADTOOLS_EXPORT BOOL LeadRectIsZero(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.isZero(self:));
LEADTOOLS_EXPORT BOOL LeadRectEqualToRect(LeadRect rect1, LeadRect rect2) CF_SWIFT_NAME(LeadRect.equalTo(self:_:));

LEADTOOLS_EXPORT NSInteger LeadRectLeft(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.left(self:));
LEADTOOLS_EXPORT NSInteger LeadRectRight(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.right(self:));
LEADTOOLS_EXPORT NSInteger LeadRectTop(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.top(self:));
LEADTOOLS_EXPORT NSInteger LeadRectBottom(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.bottom(self:));

LEADTOOLS_EXPORT LeadPoint LeadRectTopLeft(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.topLeft(self:));
LEADTOOLS_EXPORT LeadPoint LeadRectTopRight(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.topRight(self:));
LEADTOOLS_EXPORT LeadPoint LeadRectBottomRight(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.bottomRight(self:));
LEADTOOLS_EXPORT LeadPoint LeadRectBottomLeft(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.bottomLeft(self:));
LEADTOOLS_EXPORT LeadPoint LeadRectLocation(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.location(self:));

LEADTOOLS_EXPORT LeadSize LeadRectSize(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.size(self:));

LEADTOOLS_EXPORT BOOL LeadRectContainsPoint(LeadRect rect, LeadPoint point) CF_SWIFT_NAME(LeadRect.contains(self:_:));
LEADTOOLS_EXPORT BOOL LeadRectContainsRect(LeadRect rect1, LeadRect rect2) CF_SWIFT_NAME(LeadRect.contains(self:_:));
LEADTOOLS_EXPORT BOOL LeadRectIntersectsRect(LeadRect rect1, LeadRect rect2) CF_SWIFT_NAME(LeadRect.intersects(self:_:));

LEADTOOLS_EXPORT LeadRect LeadRectInflate(LeadRect rect, LeadSize size) CF_SWIFT_NAME(LeadRect.inflated(self:by:));
LEADTOOLS_EXPORT LeadRect LeadRectIntersect(LeadRect rect1, LeadRect rect2) CF_SWIFT_NAME(LeadRect.intersected(self:with:));
LEADTOOLS_EXPORT LeadRect LeadRectUnion(LeadRect rect1, LeadRect rect2) CF_SWIFT_NAME(LeadRect.unioned(self:with:));
LEADTOOLS_EXPORT LeadRect LeadRectOffset(LeadRect rect, LeadSize size) CF_SWIFT_NAME(LeadRect.offset(self:by:));
LEADTOOLS_EXPORT LeadRect LeadRectStandardize(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.standardized(self:));

LEADTOOLS_EXPORT CGRect CGRectFromLeadRect(LeadRect rect) CF_SWIFT_NAME(getter:LeadRect.cgRect(self:));

LEADTOOLS_EXPORT LeadRect LeadRectFromCGRect(CGRect rect) CF_SWIFT_NAME(LeadRect.init(_:));
LEADTOOLS_EXPORT LeadRect LeadRectFromLeadRectD(LeadRectD rect) CF_SWIFT_NAME(LeadRect.init(_:));
// // // // // // // //



CF_ASSUME_NONNULL_BEGIN

// LeadPointD functions
LEADTOOLS_EXPORT LeadPointD LeadPointD_Make(double x, double y) LT_DEPRECATED_USENEW(19_0, "LeadPointDMake");
LEADTOOLS_EXPORT LeadPointD LeadPointD_Empty(void) LT_DEPRECATED_USENEW(19_0, "LeadPointDEmpty");
LEADTOOLS_EXPORT int LeadPointD_IsEmpty(LeadPointD point) LT_DEPRECATED_USENEW(19_0, "LeadPointDIsEmpty");
LEADTOOLS_EXPORT int LeadPointD_IsEqual(LeadPointD point1, LeadPointD point2) LT_DEPRECATED_USENEW(19_0, "LeadPointDEqualToPointD");
LEADTOOLS_EXPORT LeadPointD LeadPointD_Multiply(LeadPointD point, const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadPointDMultiply");

// // // // // // // //
LT_INLINE LeadPointD LeadPointDMake(double x, double y);

LEADTOOLS_EXPORT const LeadPointD LeadPointDZero CF_SWIFT_NAME(LeadPointD.zero);
LEADTOOLS_EXPORT const LeadPointD LeadPointDEmpty CF_SWIFT_NAME(LeadPointD.empty);

LEADTOOLS_EXPORT BOOL LeadPointDIsZero(LeadPointD point) CF_SWIFT_NAME(getter:LeadPointD.isZero(self:));
LEADTOOLS_EXPORT BOOL LeadPointDIsEmpty(LeadPointD point) CF_SWIFT_NAME(getter:LeadPointD.isEmpty(self:));
LEADTOOLS_EXPORT BOOL LeadPointDEqualToPointD(LeadPointD point1, LeadPointD point2) CF_SWIFT_NAME(LeadPointD.equalTo(self:_:));

LEADTOOLS_EXPORT LeadPointD LeadPointDMultiply(LeadPointD point, LeadMatrix matrix) CF_SWIFT_NAME(LeadPointD.multiply(self:matrix:));

LEADTOOLS_EXPORT CGPoint CGPointFromLeadPointD(LeadPointD point) CF_SWIFT_NAME(getter:LeadPointD.cgPoint(self:));

LEADTOOLS_EXPORT LeadPointD LeadPointDFromCGPoint(CGPoint point) CF_SWIFT_NAME(LeadPointD.init(_:));
LEADTOOLS_EXPORT LeadPointD LeadPointDFromLeadPoint(LeadPoint point) CF_SWIFT_NAME(LeadPointD.init(_:));
// // // // // // // //



// LeadSizeD functions
LEADTOOLS_EXPORT LeadSizeD LeadSizeD_Make(double width, double height) LT_DEPRECATED_USENEW(19_0, "LeadSizeDMake");
LEADTOOLS_EXPORT LeadSizeD LeadSizeD_Empty(void) LT_DEPRECATED_USENEW(19_0, "LeadSizeDZero");
LEADTOOLS_EXPORT int LeadSizeD_IsEmpty(LeadSizeD size) LT_DEPRECATED_USENEW(19_0, "LeadSizeDIsZero");
LEADTOOLS_EXPORT int LeadSizeD_IsEqual(LeadSizeD size1, LeadSizeD size2) LT_DEPRECATED_USENEW(19_0, "LeadSizeDEqualToSizeD");

// // // // // // // //
LT_INLINE LeadSizeD LeadSizeDMake(double width, double height);

LEADTOOLS_EXPORT const LeadSizeD LeadSizeDZero CF_SWIFT_NAME(LeadSizeD.zero);

LEADTOOLS_EXPORT BOOL LeadSizeDIsZero(LeadSizeD size) CF_SWIFT_NAME(getter:LeadSizeD.isZero(self:));
LEADTOOLS_EXPORT BOOL LeadSizeDEqualToSizeD(LeadSizeD size1, LeadSizeD size2) CF_SWIFT_NAME(LeadSizeD.equalTo(self:_:));

LEADTOOLS_EXPORT CGSize CGSizeFromLeadSizeD(LeadSizeD size) CF_SWIFT_NAME(getter:LeadSizeD.cgSize(self:));

LEADTOOLS_EXPORT LeadSizeD LeadSizeDFromCGSize(CGSize size) CF_SWIFT_NAME(LeadSizeD.init(_:));
LEADTOOLS_EXPORT LeadSizeD LeadSizeDFromLeadSize(LeadSize size) CF_SWIFT_NAME(LeadSizeD.init(_:));
// // // // // // // //



// LeadRectD functions
LEADTOOLS_EXPORT LeadRectD LeadRectD_Make(double x, double y, double width, double height) LT_DEPRECATED_USENEW(19_0, "LeadRectDMake");
LEADTOOLS_EXPORT LeadRectD LeadRectD_FromLTRB(double left, double top, double right, double bottom) LT_DEPRECATED_USENEW(19_0, "LeadRectDFromLTRB");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Empty(void) LT_DEPRECATED_USENEW(19_0, "LeadRectDEmpty");
LEADTOOLS_EXPORT int LeadRectD_IsEmpty(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDIsEmpty");
LEADTOOLS_EXPORT int LeadRectD_IsEqual(LeadRectD rect1, LeadRectD rect2) LT_DEPRECATED_USENEW(19_0, "LeadRectDEqualToRectD");
LEADTOOLS_EXPORT double LeadRectD_Left(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDLeft");
LEADTOOLS_EXPORT double LeadRectD_Right(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDRight");
LEADTOOLS_EXPORT double LeadRectD_Top(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDTop");
LEADTOOLS_EXPORT double LeadRectD_Bottom(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDBottom");
LEADTOOLS_EXPORT LeadPointD LeadRectD_TopLeft(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDTopLeft");
LEADTOOLS_EXPORT LeadPointD LeadRectD_TopRight(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDTopRight");
LEADTOOLS_EXPORT LeadPointD LeadRectD_BottomRight(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDBottomRight");
LEADTOOLS_EXPORT LeadPointD LeadRectD_BottomLeft(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDBottomLeft");
LEADTOOLS_EXPORT LeadPointD LeadRectD_Location(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDLocalization");
LEADTOOLS_EXPORT LeadSizeD LeadRectD_Size(LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadRectDSize");
LEADTOOLS_EXPORT int LeadRectD_ContainsPoint(LeadRectD rect, LeadPointD testPoint) LT_DEPRECATED_USENEW(19_0, "LeadRectDContainsPoint");
LEADTOOLS_EXPORT int LeadRectD_ContainsRect(LeadRectD rect, LeadRectD testRect) LT_DEPRECATED_USENEW(19_0, "LeadRectDContainsRect");
LEADTOOLS_EXPORT int LeadRectD_IntersectsWith(LeadRectD rect, LeadRectD testRect) LT_DEPRECATED_USENEW(19_0, "LeadRectDIntersectsWith");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Intersect(LeadRectD rect1, LeadRectD rect2) LT_DEPRECATED_USENEW(19_0, "LeadRectDIntersection");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Union(LeadRectD rect1, LeadRectD rect2) LT_DEPRECATED_USENEW(19_0, "LeadRectDUnion");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Offset(LeadRectD rect, LeadSizeD size) LT_DEPRECATED_USENEW(19_0, "LeadRectDOffset");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Inflate(LeadRectD rect, LeadSizeD size) LT_DEPRECATED_USENEW(19_0, "LeadRectDInflate");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Scale(LeadRectD rect, double scaleX, double scaleY) LT_DEPRECATED_USENEW(19_0, "LeadRectDScale");
LEADTOOLS_EXPORT LeadRectD LeadRectD_Transform(LeadRectD rect, const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadRectDTransform");

// // // // // // // //
LT_INLINE LeadRectD LeadRectDMake(double x, double y, double width, double height);
LEADTOOLS_EXPORT LeadRectD LeadRectDFromLTRB(double left, double top, double right, double bottom) CF_SWIFT_NAME(LeadRectD.init(left:top:right:bottom:));

LEADTOOLS_EXPORT const LeadRectD LeadRectDEmpty CF_SWIFT_NAME(LeadRectD.empty);
LEADTOOLS_EXPORT const LeadRectD LeadRectDZero CF_SWIFT_NAME(LeadRectD.zero);

LEADTOOLS_EXPORT BOOL LeadRectDEqualToRectD(LeadRectD rect1, LeadRectD rect2) CF_SWIFT_NAME(LeadRectD.equalTo(self:_:));
LEADTOOLS_EXPORT BOOL LeadRectDIsEmpty(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.isEmpty(self:));
LEADTOOLS_EXPORT BOOL LeadRectDIsZero(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.isZero(self:));

LEADTOOLS_EXPORT double LeadRectDLeft(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.left(self:));
LEADTOOLS_EXPORT double LeadRectDRight(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.right(self:));
LEADTOOLS_EXPORT double LeadRectDTop(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.top(self:));
LEADTOOLS_EXPORT double LeadRectDBottom(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.bottom(self:));

LEADTOOLS_EXPORT LeadPointD LeadRectDTopLeft(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.topLeft(self:));
LEADTOOLS_EXPORT LeadPointD LeadRectDTopRight(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.topRight(self:));
LEADTOOLS_EXPORT LeadPointD LeadRectDBottomRight(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.bottomRight(self:));
LEADTOOLS_EXPORT LeadPointD LeadRectDBottomLeft(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.bottomLeft(self:));
LEADTOOLS_EXPORT LeadPointD LeadRectDLocation(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.location(self:));

LEADTOOLS_EXPORT LeadSizeD LeadRectDSize(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.size(self:));

LEADTOOLS_EXPORT BOOL LeadRectDContainsPoint(LeadRectD rect, LeadPointD point) CF_SWIFT_NAME(LeadRectD.contains(self:_:));
LEADTOOLS_EXPORT BOOL LeadRectDContainsRect(LeadRectD rect1, LeadRectD rect2) CF_SWIFT_NAME(LeadRectD.contains(self:_:));
LEADTOOLS_EXPORT BOOL LeadRectDIntersectsWith(LeadRectD rect1, LeadRectD rect2) CF_SWIFT_NAME(LeadRectD.intersects(self:_:));

LEADTOOLS_EXPORT LeadRectD LeadRectDIntersection(LeadRectD rect1, LeadRectD rect2) CF_SWIFT_NAME(LeadRectD.intersected(self:with:));
LEADTOOLS_EXPORT LeadRectD LeadRectDUnion(LeadRectD rect1, LeadRectD rect2) CF_SWIFT_NAME(LeadRectD.unioned(self:with:));
LEADTOOLS_EXPORT LeadRectD LeadRectDOffset(LeadRectD rect, LeadPointD offset) CF_SWIFT_NAME(LeadRectD.offset(self:by:));
LEADTOOLS_EXPORT LeadRectD LeadRectDInflate(LeadRectD rect, LeadSizeD size) CF_SWIFT_NAME(LeadRectD.inflated(self:by:));
LEADTOOLS_EXPORT LeadRectD LeadRectDScale(LeadRectD rect, double scaleX, double scaleY) CF_SWIFT_NAME(LeadRectD.scaledBy(self:x:y:));
LEADTOOLS_EXPORT LeadRectD LeadRectDTransform(LeadRectD rect, LeadMatrix matrix) CF_SWIFT_NAME(LeadRectD.transformed(self:_:));

LEADTOOLS_EXPORT CGRect CGRectFromLeadRectD(LeadRectD rect) CF_SWIFT_NAME(getter:LeadRectD.cgRect(self:));

LEADTOOLS_EXPORT LeadRectD LeadRectDFromCGRect(CGRect rect) CF_SWIFT_NAME(LeadRectD.init(_:));
LEADTOOLS_EXPORT LeadRectD LeadRectDFromLeadRect(LeadRect rect) CF_SWIFT_NAME(LeadRectD.init(_:));
// // // // // // // //



// LeadLengthD functions
LEADTOOLS_EXPORT LeadLengthD LeadLengthD_Make(double value) LT_DEPRECATED_USENEW(19_0, "LeadLengthDMake");
LEADTOOLS_EXPORT int LeadLengthD_IsEqual(LeadLengthD length1, LeadLengthD length2) LT_DEPRECATED_USENEW(19_0, "LeadLengthDEqualToLengthD");

// // // // // // // //
LEADTOOLS_EXPORT LeadLengthD LeadLengthDMake(double value);

LEADTOOLS_EXPORT BOOL LeadLengthDEqualToLengthD(LeadLengthD length1, LeadLengthD length2) CF_SWIFT_NAME(LeadLengthD.equalTo(self:_:));
// // // // // // // //



// LeadMatrix functions
LEADTOOLS_EXPORT void LeadMatrix_Set(LeadMatrix *matrix, double m11, double m12, double m21, double m22, double offsetX, double offsetY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSet");
LEADTOOLS_EXPORT const LeadMatrix LeadMatrix_Identity LT_DEPRECATED_USENEW(19_0, "LeadMatrixIdentity");
LEADTOOLS_EXPORT int LeadMatrix_IsIdentity(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixEqualToMatrix(matrix, &LeadMatrixIdentity)");
LEADTOOLS_EXPORT double LeadMatrix_Determinant(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixDeterminant");
LEADTOOLS_EXPORT int LeadMatrix_HasInverse(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixHasInverse");
LEADTOOLS_EXPORT double LeadMatrix_GetM11(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixGetM11");
LEADTOOLS_EXPORT void LeadMatrix_SetM11(LeadMatrix *matrix, double value) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetM11");
LEADTOOLS_EXPORT double LeadMatrix_GetM12(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixGetM12");
LEADTOOLS_EXPORT void LeadMatrix_SetM12(LeadMatrix *matrix, double value) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetM12");
LEADTOOLS_EXPORT double LeadMatrix_GetM21(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixGetM21");
LEADTOOLS_EXPORT void LeadMatrix_SetM21(LeadMatrix *matrix, double value) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetM21");
LEADTOOLS_EXPORT double LeadMatrix_GetM22(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixGetM22");
LEADTOOLS_EXPORT void LeadMatrix_SetM22(LeadMatrix *matrix, double value) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetM22");
LEADTOOLS_EXPORT double LeadMatrix_GetOffsetX(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixGetOffsetX");
LEADTOOLS_EXPORT void LeadMatrix_SetOffsetX(LeadMatrix *matrix, double value) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetOffsetX");
LEADTOOLS_EXPORT double LeadMatrix_GetOffsetY(const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixGetOffsetY");
LEADTOOLS_EXPORT void LeadMatrix_SetOffsetY(LeadMatrix *matrix, double value) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetOffsetY");
LEADTOOLS_EXPORT void LeadMatrix_SetIdentity(LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSetIdentity");
LEADTOOLS_EXPORT void LeadMatrix_Multiply(LeadMatrix *result, const LeadMatrix *matrix1, const LeadMatrix *matrix2) LT_DEPRECATED_USENEW(19_0, "LeadMatrixMultiply");
LEADTOOLS_EXPORT void LeadMatrix_Append(LeadMatrix *result, const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixAppend");
LEADTOOLS_EXPORT void LeadMatrix_Prepend(LeadMatrix *result, const LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixPrepend");
LEADTOOLS_EXPORT void LeadMatrix_Rotate(LeadMatrix *matrix, double degrees) LT_DEPRECATED_USENEW(19_0, "LeadMatrixRotate");
LEADTOOLS_EXPORT void LeadMatrix_RotatePrepend(LeadMatrix *matrix, double degrees) LT_DEPRECATED_USENEW(19_0, "LeadMatrixRotatePrepend");
LEADTOOLS_EXPORT void LeadMatrix_RotateAt(LeadMatrix *matrix, double degrees, double centerX, double centerY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixRotateAt");
LEADTOOLS_EXPORT void LeadMatrix_RotateAtPrepend(LeadMatrix *matrix, double degrees, double centerX, double centerY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixRotateAtPrepend");
LEADTOOLS_EXPORT void LeadMatrix_Scale(LeadMatrix *matrix, double scaleX, double scaleY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixScale");
LEADTOOLS_EXPORT void LeadMatrix_ScalePrepend(LeadMatrix *matrix, double scaleX, double scaleY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixScalePrepend");
LEADTOOLS_EXPORT void LeadMatrix_ScaleAt(LeadMatrix *matrix, double scaleX, double scaleY, double centerX, double centerY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixScaleAt");
LEADTOOLS_EXPORT void LeadMatrix_ScaleAtPrepend(LeadMatrix *matrix, double scaleX, double scaleY, double centerX, double centerY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixScaleAtPrepend");
LEADTOOLS_EXPORT void LeadMatrix_Skew(LeadMatrix *matrix, double degreesX, double degreesY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSkew");
LEADTOOLS_EXPORT void LeadMatrix_SkewPrepend(LeadMatrix *matrix, double degreesX, double degreesY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixSkewPrepend");
LEADTOOLS_EXPORT void LeadMatrix_Translate(LeadMatrix *matrix, double offsetX, double offsetY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixTranslate");
LEADTOOLS_EXPORT void LeadMatrix_TranslatePrepend(LeadMatrix *matrix, double offsetX, double offsetY) LT_DEPRECATED_USENEW(19_0, "LeadMatrixTranslatePrepend");
LEADTOOLS_EXPORT LeadPointD LeadMatrix_TransformPoint(const LeadMatrix *matrix, LeadPointD point) LT_DEPRECATED_USENEW(19_0, "LeadMatrixTransformPoint");
LEADTOOLS_EXPORT LeadPointD LeadMatrix_TransformVector(const LeadMatrix *matrix, LeadPointD point) LT_DEPRECATED_USENEW(19_0, "LeadMatrixTransformVector");
LEADTOOLS_EXPORT void LeadMatrix_TransformPoints(const LeadMatrix *matrix, LeadPointD* points, unsigned int count) LT_DEPRECATED_USENEW(19_0, "LeadMatrixTransformPoints");
LEADTOOLS_EXPORT LeadRectD LeadMatrix_TransformRect(const LeadMatrix *matrix, LeadRectD rect) LT_DEPRECATED_USENEW(19_0, "LeadMatrixTransformRect");
LEADTOOLS_EXPORT int LeadMatrix_Invert(LeadMatrix *matrix) LT_DEPRECATED_USENEW(19_0, "LeadMatrixInvert");
LEADTOOLS_EXPORT int LeadMatrix_IsEqual(const LeadMatrix *matrix1, const LeadMatrix *matrix2) LT_DEPRECATED_USENEW(19_0, "LeadMatrixEqualToMatrix");

// // // // // // // //
LEADTOOLS_EXPORT LeadMatrix LeadMatrixMake(double m11, double m12, double m21, double m22, double offsetX, double offsetY);
LEADTOOLS_EXPORT void LeadMatrixSet(LeadMatrix *matrix, double m11, double m12, double m21, double m22, double offsetX, double offsetY) CF_SWIFT_NAME(LeadMatrix.set(self:M11:M12:M21:M22:offsetX:offsetY:));

LEADTOOLS_EXPORT const LeadMatrix LeadMatrixIdentity CF_SWIFT_NAME(LeadMatrix.identity);
LEADTOOLS_EXPORT BOOL LeadMatrixIsIdentity(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.isIdentity(self:));

LEADTOOLS_EXPORT double LeadMatrixDeterminant(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.determinant(self:));
LEADTOOLS_EXPORT double LeadMatrixGetM11(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.m11(self:));
LEADTOOLS_EXPORT double LeadMatrixGetM12(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.m12(self:));
LEADTOOLS_EXPORT double LeadMatrixGetM21(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.m21(self:));
LEADTOOLS_EXPORT double LeadMatrixGetM22(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.m22(self:));
LEADTOOLS_EXPORT double LeadMatrixGetOffsetX(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.offsetX(self:));
LEADTOOLS_EXPORT double LeadMatrixGetOffsetY(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.offsetY(self:));

LEADTOOLS_EXPORT BOOL LeadMatrixHasInverse(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.hasInverse(self:));
LEADTOOLS_EXPORT BOOL LeadMatrixInvert(LeadMatrix *matrix) CF_SWIFT_NAME(LeadMatrix.invert(self:));

LEADTOOLS_EXPORT void LeadMatrixSetM11(LeadMatrix *matrix, double value);
LEADTOOLS_EXPORT void LeadMatrixSetM12(LeadMatrix *matrix, double value);
LEADTOOLS_EXPORT void LeadMatrixSetM21(LeadMatrix *matrix, double value);
LEADTOOLS_EXPORT void LeadMatrixSetM22(LeadMatrix *matrix, double value);
LEADTOOLS_EXPORT void LeadMatrixSetOffsetX(LeadMatrix *matrix, double value);
LEADTOOLS_EXPORT void LeadMatrixSetOffsetY(LeadMatrix *matrix, double value);
LEADTOOLS_EXPORT void LeadMatrixSetIdentity(LeadMatrix *matrix) CF_SWIFT_NAME(LeadMatrix.setIdentity(self:));

LEADTOOLS_EXPORT LeadMatrix LeadMatrixMultiply(LeadMatrix matrix1, LeadMatrix matrix2) CF_SWIFT_NAME(LeadMatrix.multiplied(self:with:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixAppend(LeadMatrix matrix1, LeadMatrix matrix2) CF_SWIFT_NAME(LeadMatrix.appending(self:_:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixPrepend(LeadMatrix matrix1, LeadMatrix matrix2) CF_SWIFT_NAME(LeadMatrix.prepending(self:_:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixRotate(LeadMatrix matrix, double degrees) CF_SWIFT_NAME(LeadMatrix.rotated(self:degrees:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixRotatePrepend(LeadMatrix matrix, double degrees) CF_SWIFT_NAME(LeadMatrix.rotatedPrepending(self:degrees:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixRotateAt(LeadMatrix matrix, double degrees, double centerX, double centerY) CF_SWIFT_NAME(LeadMatrix.rotated(self:degrees:atX:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixRotateAtPrepend(LeadMatrix matrix, double degrees, double centerX, double centerY) CF_SWIFT_NAME(LeadMatrix.rotatedPrepending(self:degrees:atX:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixScale(LeadMatrix matrix, double scaleX, double scaleY) CF_SWIFT_NAME(LeadMatrix.scaledBy(self:x:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixScalePrepend(LeadMatrix matrix, double scaleX, double scaleY) CF_SWIFT_NAME(LeadMatrix.scaledPrepending(self:x:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixScaleAt(LeadMatrix matrix, double scaleX, double scaleY, double centerX, double centerY) CF_SWIFT_NAME(LeadMatrix.scaledBy(self:x:y:atX:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixScaleAtPrepend(LeadMatrix matrix, double scaleX, double scaleY, double centerX, double centerY) CF_SWIFT_NAME(LeadMatrix.scaledPrepending(self:x:y:atX:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixSkew(LeadMatrix matrix, double degreesX, double degreesY) CF_SWIFT_NAME(LeadMatrix.skewedBy(self:x:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixSkewPrepend(LeadMatrix matrix, double degreesX, double degreesY) CF_SWIFT_NAME(LeadMatrix.skewedPrepending(self:x:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixTranslate(LeadMatrix matrix, double offsetX, double offsetY) CF_SWIFT_NAME(LeadMatrix.translatedBy(self:x:y:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixTranslatePrepend(LeadMatrix matrix, double offsetX, double offsetY) CF_SWIFT_NAME(LeadMatrix.translatedPrepending(self:x:y:));

LEADTOOLS_EXPORT LeadPointD LeadMatrixTransformPoint(LeadMatrix matrix, LeadPointD point) CF_SWIFT_NAME(LeadMatrix.transform(self:point:));
LEADTOOLS_EXPORT LeadPointD LeadMatrixTransformVector(LeadMatrix matrix, LeadPointD point) CF_SWIFT_NAME(LeadMatrix.transform(self:vector:));
LEADTOOLS_EXPORT LeadRectD  LeadMatrixTransformRect(LeadMatrix matrix, LeadRectD rect) CF_SWIFT_NAME(LeadMatrix.transform(self:rect:));

LEADTOOLS_EXPORT void LeadMatrixTransformPoints(LeadMatrix matrix, LeadPointD *points, NSUInteger count) CF_SWIFT_NAME(LeadMatrix.transform(self:points:count:));

LEADTOOLS_EXPORT BOOL LeadMatrixEqualToMatrix(LeadMatrix matrix1, LeadMatrix matrix2) CF_SWIFT_NAME(LeadMatrix.equalTo(self:_:));

LEADTOOLS_EXPORT CGAffineTransform CGAffineTransformFromLeadMatrix(LeadMatrix matrix) CF_SWIFT_NAME(getter:LeadMatrix.cgAffineTransform(self:));
LEADTOOLS_EXPORT LeadMatrix LeadMatrixFromCGAffineTransform(CGAffineTransform transform) CF_SWIFT_NAME(LeadMatrix.init(_:));
// // // // // // // //

// // // // // // // //
LeadPoint LeadPointMake(NSInteger x, NSInteger y) {
    LeadPoint point = {x, y}; return point;
}

LeadSize LeadSizeMake(NSInteger width, NSInteger height) {
    LeadSize size = {width, height}; return size;
}

LeadRect LeadRectMake(NSInteger x, NSInteger y, NSInteger width, NSInteger height) {
    LeadRect rect = {x, y, width, height}; return rect;
}

LeadPointD LeadPointDMake(double x, double y) {
    LeadPointD point = {x, y}; return point;
}

LeadSizeD LeadSizeDMake(double width, double height) {
    LeadSizeD size = {width, height}; return size;
}

LeadRectD LeadRectDMake(double x, double y, double width, double height) {
    LeadRectD rect = {x, y, width, height}; return rect;
}
// // // // // // // //

// // // // // // // //
#if defined(__OBJC__)
    
@interface NSValue (LTPrimitives)

@property (nonatomic, assign, readonly) LeadPoint leadPointValue;
@property (nonatomic, assign, readonly) LeadSize leadSizeValue;
@property (nonatomic, assign, readonly) LeadRect leadRectValue;

@property (nonatomic, assign, readonly) LeadPointD leadPointDValue;
@property (nonatomic, assign, readonly) LeadSizeD leadSizeDValue;
@property (nonatomic, assign, readonly) LeadRectD leadRectDValue;

@property (nonatomic, assign, readonly) LeadLengthD leadLengthDValue;

@property (nonatomic, assign, readonly) LeadMatrix leadMatrixValue;



- (instancetype)initWithLeadPoint:(LeadPoint)point;
- (instancetype)initWithLeadSize:(LeadSize)size;
- (instancetype)initWithLeadRect:(LeadRect)rect;

- (instancetype)initWithLeadPointD:(LeadPointD)point;
- (instancetype)initWithLeadSizeD:(LeadSizeD)size;
- (instancetype)initWithLeadRectD:(LeadRectD)rect;

- (instancetype)initWithLeadLengthD:(LeadLengthD)length;

- (instancetype)initWithLeadMatrix:(LeadMatrix)matrix;

+ (NSValue *)valueWithLeadPoint:(LeadPoint)point OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
+ (NSValue *)valueWithLeadSize:(LeadSize)size OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
+ (NSValue *)valueWithLeadRect:(LeadRect)rect OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

+ (NSValue *)valueWithLeadPointD:(LeadPointD)point OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
+ (NSValue *)valueWithLeadSizeD:(LeadSizeD)size OBJC_SWIFT_UNAVAILABLE("use object initializers instead");
+ (NSValue *)valueWithLeadRectD:(LeadRectD)rect OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

+ (NSValue *)valueWithLeadLengthD:(LeadLengthD)length OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

+ (NSValue *)valueWithLeadMatrix:(LeadMatrix)matrix OBJC_SWIFT_UNAVAILABLE("use object initializers instead");

@end



@interface NSCoder (LTPrimitives)

- (void)encodeLeadPoint:(LeadPoint)point forKey:(NSString *)key;
- (void)encodeLeadSize:(LeadSize)size forKey:(NSString *)key;
- (void)encodeLeadRect:(LeadRect)rect forKey:(NSString *)key;
- (void)encodeLeadPointD:(LeadPointD)point forKey:(NSString *)key;
- (void)encodeLeadSizeD:(LeadSizeD)size forKey:(NSString *)key;
- (void)encodeLeadRectD:(LeadRectD)rect forKey:(NSString *)key;
- (void)encodeLeadLengthD:(LeadLengthD)length forKey:(NSString *)key;
- (void)encodeLeadMatrix:(LeadMatrix)matrix forKey:(NSString *)key;

- (LeadPoint)decodeLeadPointForKey:(NSString *)key;
- (LeadSize)decodeLeadSizeForKey:(NSString *)key;
- (LeadRect)decodeLeadRectForKey:(NSString *)key;
- (LeadPointD)decodeLeadPointDForKey:(NSString *)key;
- (LeadSizeD)decodeLeadSizeDForKey:(NSString *)key;
- (LeadRectD)decodeLeadRectDForKey:(NSString *)key;
- (LeadLengthD)decodeLeadLengthDForKey:(NSString *)key;
- (LeadMatrix)decodeLeadMatrixForKey:(NSString *)key;

@end
    
#endif // #if defined(__OBJC__)
// // // // // // // //

CF_ASSUME_NONNULL_END

#pragma pack()

#endif // #if !defined(LTPRIMITIVES_XCODE_H)
