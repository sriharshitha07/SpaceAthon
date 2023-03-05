//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTPRIMITIVES_H)
#define LTPRIMITIVES_H

#include "lttyp.h"
#define L_LTKRN_API LT_EXPORTED

//#if defined(__cplusplus)
//#  include <cfloat>
//#  include <cmath>
//#else
//#  include <float.h>
//#  include <math.h>
//#endif // defined(__cplusplus)

#define L_HEADER_ENTRY
#include "ltpck.h"

// Integer point
// L_POINT

// Integer size
// L_SIZE
   
// Integer rect
// L_RECT
   
// Double point
struct L_POINTD
{
   L_DOUBLE x;
   L_DOUBLE y;
};
typedef struct L_POINTD L_POINTD;

// Double size
struct L_SIZED
{
   L_DOUBLE width;
   L_DOUBLE height;
};
typedef struct L_SIZED L_SIZED;

// Double rect
struct L_RECTD
{
   L_DOUBLE x;
   L_DOUBLE y;
   L_DOUBLE width;
   L_DOUBLE height;
};
typedef struct L_RECTD L_RECTD;

// Double length
struct L_LENGTHD
{
   L_DOUBLE value;
};
typedef struct L_LENGTHD L_LENGTHD;

// Double matrix
// Do not set the values of this matrix directly, instead use
// LeadMatrix_GetM11/SetM11 for example or LeadMatrix_Set
// This will ensure that type is set to the correct internal type
// and greatly speeds up the matrix operations
struct L_MATRIX
{
   L_DOUBLE m11;
   L_DOUBLE m12;
   L_DOUBLE m21;
   L_DOUBLE m22;
   L_DOUBLE offsetX;
   L_DOUBLE offsetY;
   L_INT type;
   L_INT padding;
};
typedef struct L_MATRIX L_MATRIX;

// NaN/Infinite
#if defined(FOR_WINDOWS) || defined(FOR_UWP) || defined(_MSC_VER)
#  define L_ISNAN _isnan
#else
#  define L_ISNAN isnan
#endif // #if defined(FOR_WINDOWS) || defined(FOR_UWP) || defined(_MSC_VER)

#if defined(FOR_WINDOWS) || defined(FOR_UWP) || defined(_MSC_VER)
#  define L_ISFINITE _finite
#else
#  define L_ISFINITE isfinite
#endif // #if defined(FOR_WINDOWS) || defined(FOR_UWP) || defined(_MSC_VER)

#if !defined(nan) && !defined(LT_NAN_DEFINED)
   #define LT_NAN_DEFINED
   static const L_UINT _mynan[2]={0xffffffff, 0x7fffffff};
   #if defined(__cplusplus)
   #  define LT_NaN (*(L_DOUBLE*)_mynan)
   #endif
#else
   #define LT_NaN nan
#endif // #if !defined(nan)

// ##MOVE_TO_KERNEL## Done // make this #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_KERNEL)
#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_KERNEL)

// L_POINT functions
L_LTKRN_API L_VOID EXT_FUNCTION L_Point_Make(L_POINT* point, L_INT x, L_INT y);
L_LTKRN_API L_VOID EXT_FUNCTION L_Point_Empty(L_POINT* point);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Point_IsEmpty(const L_POINT* point);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Point_IsEqual(const L_POINT* point1, const L_POINT* point2);
L_LTKRN_API L_VOID EXT_FUNCTION L_Point_ToPointD(const L_POINT* point, L_POINTD* result);

// L_SIZE functions
L_LTKRN_API L_VOID EXT_FUNCTION L_Size_Make(L_SIZE* size, L_INT width, L_INT height);
L_LTKRN_API L_VOID EXT_FUNCTION L_Size_Empty(L_SIZE* size);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Size_IsEmpty(const L_SIZE* size);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Size_IsEqual(const L_SIZE* size1, const L_SIZE* size2);
L_LTKRN_API L_VOID EXT_FUNCTION L_Size_ToSizeD(const L_SIZE* size, L_SIZED* result);

// L_RECT functions
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Make(L_RECT* rect, L_INT x, L_INT y, L_INT width, L_INT height);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_FromLTRB(L_RECT* rect, L_INT left, L_INT top, L_INT right, L_INT bottom);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Empty(L_RECT* rect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Rect_IsEmpty(const L_RECT* rect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Rect_IsEqual(const L_RECT* rect1, const L_RECT* rect2);
L_LTKRN_API L_INT EXT_FUNCTION L_Rect_Width(const L_RECT* rect);
L_LTKRN_API L_INT EXT_FUNCTION L_Rect_Height(const L_RECT* rect);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_TopLeft(const L_RECT* rect, L_POINT* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_TopRight(const L_RECT* rect, L_POINT* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_BottomRight(const L_RECT* rect, L_POINT* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_BottomLeft(const L_RECT* rect, L_POINT* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Location(const L_RECT* rect, L_POINT* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Size(const L_RECT* rect, L_SIZE* size);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Rect_ContainsPoint(const L_RECT* rect, const L_POINT* testPoint);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Rect_ContainsRect(const L_RECT* rect, const L_RECT* testRect);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Inflate(L_RECT* rect, const L_SIZE* size);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Intersect(L_RECT* rect, const L_RECT* rect1, const L_RECT* rect2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Rect_IntersectsWith(const L_RECT* rect, const L_RECT* testRect);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Union(L_RECT* rect, const L_RECT* rect1, const L_RECT* rect2);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_Offset(L_RECT* rect, const L_SIZE* size);
L_LTKRN_API L_VOID EXT_FUNCTION L_Rect_ToRectD(const L_RECT* rect, L_RECTD* result);

// L_POINTD functions
L_LTKRN_API L_VOID EXT_FUNCTION L_PointD_Make(L_POINTD* point, L_DOUBLE x, L_DOUBLE y);
L_LTKRN_API L_VOID EXT_FUNCTION L_PointD_Empty(L_POINTD* point);
L_LTKRN_API L_BOOL EXT_FUNCTION L_PointD_IsEmpty(const L_POINTD* point);
L_LTKRN_API L_BOOL EXT_FUNCTION L_PointD_IsEqual(const L_POINTD* point1, const L_POINTD* point2);
L_LTKRN_API L_VOID EXT_FUNCTION L_PointD_Multiply(L_POINTD* point, const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_PointD_ToPoint(const L_POINTD* point, L_POINT* result);

// L_SIZED functions
L_LTKRN_API L_VOID EXT_FUNCTION L_SizeD_Make(L_SIZED* size, L_DOUBLE width, L_DOUBLE height);
L_LTKRN_API L_VOID EXT_FUNCTION L_SizeD_Empty(L_SIZED* size);
L_LTKRN_API L_BOOL EXT_FUNCTION L_SizeD_IsEmpty(const L_SIZED* size);
L_LTKRN_API L_BOOL EXT_FUNCTION L_SizeD_IsEqual(const L_SIZED* size1, const L_SIZED* size2);
L_LTKRN_API L_VOID EXT_FUNCTION L_SizeD_ToSize(const L_SIZED* size, L_SIZE* result);

// L_RECTD functions
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Make(L_RECTD* rect, L_DOUBLE x, L_DOUBLE y, L_DOUBLE width, L_DOUBLE height);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_FromLTRB(L_RECTD* rect, L_DOUBLE left, L_DOUBLE top, L_DOUBLE right, L_DOUBLE bottom);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Empty(L_RECTD* rect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_RectD_IsEmpty(const L_RECTD* rect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_RectD_IsEqual(const L_RECTD* rect1, const L_RECTD* rect2);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_RectD_Left(const L_RECTD* rect);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_RectD_Right(const L_RECTD* rect);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_RectD_Top(const L_RECTD* rect);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_RectD_Bottom(const L_RECTD* rect);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_TopLeft(const L_RECTD* rect, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_TopRight(const L_RECTD* rect, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_BottomRight(const L_RECTD* rect, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_BottomLeft(const L_RECTD* rect, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Location(const L_RECTD* rect, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Size(const L_RECTD* rect, L_SIZED* size);
L_LTKRN_API L_BOOL EXT_FUNCTION L_RectD_ContainsPoint(const L_RECTD* rect, const L_POINTD* testPoint);
L_LTKRN_API L_BOOL EXT_FUNCTION L_RectD_ContainsRect(const L_RECTD* rect, const L_RECTD* testRect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_RectD_IntersectsWith(const L_RECTD* rect, const L_RECTD* testRect);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Intersect(L_RECTD* rect, const L_RECTD* rect1, const L_RECTD* rect2);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Union(L_RECTD* rect, const L_RECTD* rect1, const L_RECTD* rect2);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Offset(L_RECTD* rect, const L_SIZED* size);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Inflate(L_RECTD* rect, const L_SIZED* size);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Scale(L_RECTD* rect, L_DOUBLE scaleX, L_DOUBLE scaleY);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_Transform(L_RECTD* rect, const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_RectD_ToRect(const L_RECTD* rect, L_RECT* result);

// L_LENGTHD functions
L_LTKRN_API L_VOID EXT_FUNCTION L_LengthD_Make(L_LENGTHD* length, L_DOUBLE value);
L_LTKRN_API L_BOOL EXT_FUNCTION L_LengthD_IsEqual(const L_LENGTHD* length1, const L_LENGTHD* length2);

// L_MATRIX functions
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Set(L_MATRIX* matrix, L_DOUBLE m11, L_DOUBLE m12, L_DOUBLE m21, L_DOUBLE m22, L_DOUBLE offsetX, L_DOUBLE offsetY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Identity(L_MATRIX* matrix);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Matrix_IsIdentity(const L_MATRIX* matrix);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_Determinant(const L_MATRIX* matrix);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Matrix_HasInverse(const L_MATRIX* matrix);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_GetM11(const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SetM11(L_MATRIX* matrix, L_DOUBLE value);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_GetM12(const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SetM12(L_MATRIX* matrix, L_DOUBLE value);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_GetM21(const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SetM21(L_MATRIX* matrix, L_DOUBLE value);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_GetM22(const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SetM22(L_MATRIX* matrix, L_DOUBLE value);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_GetOffsetX(const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SetOffsetX(L_MATRIX* matrix, L_DOUBLE value);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Matrix_GetOffsetY(const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SetOffsetY(L_MATRIX* matrix, L_DOUBLE value);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Multiply(L_MATRIX* result, const L_MATRIX* matrix1, const L_MATRIX* matrix2);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Append(L_MATRIX* result, const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Prepend(L_MATRIX* result, const L_MATRIX* matrix);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Rotate(L_MATRIX* matrix, L_DOUBLE degrees);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_RotatePrepend(L_MATRIX* matrix, L_DOUBLE degrees);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_RotateAt(L_MATRIX* matrix, L_DOUBLE degrees, L_DOUBLE centerX, L_DOUBLE centerY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_RotateAtPrepend(L_MATRIX* matrix, L_DOUBLE degrees, L_DOUBLE centerX, L_DOUBLE centerY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Scale(L_MATRIX* matrix, L_DOUBLE scaleX, L_DOUBLE scaleY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_ScalePrepend(L_MATRIX* matrix, L_DOUBLE scaleX, L_DOUBLE scaleY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_ScaleAt(L_MATRIX* matrix, L_DOUBLE scaleX, L_DOUBLE scaleY, L_DOUBLE centerX, L_DOUBLE centerY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_ScaleAtPrepend(L_MATRIX* matrix, L_DOUBLE scaleX, L_DOUBLE scaleY, L_DOUBLE centerX, L_DOUBLE centerY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Skew(L_MATRIX* matrix, L_DOUBLE degreesX, L_DOUBLE degreesY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_SkewPrepend(L_MATRIX* matrix, L_DOUBLE degreesX, L_DOUBLE degreesY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_Translate(L_MATRIX* matrix, L_DOUBLE offsetX, L_DOUBLE offsetY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_TranslatePrepend(L_MATRIX* matrix, L_DOUBLE offsetX, L_DOUBLE offsetY);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_TransformPoint(const L_MATRIX* matrix, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_TransformVector(const L_MATRIX* matrix, L_POINTD* point);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_TransformPoints(const L_MATRIX* matrix, L_POINTD* points, L_UINT count);
L_LTKRN_API L_VOID EXT_FUNCTION L_Matrix_TransformRect(const L_MATRIX* matrix, L_RECTD* rect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Matrix_Invert(L_MATRIX* matrix);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Matrix_IsEqual(const L_MATRIX* matrix1, const L_MATRIX* matrix2);

// Double helper functions
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_AreClose(L_DOUBLE value1, L_DOUBLE value2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_LessThan(L_DOUBLE value1, L_DOUBLE value2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_GreaterThan(L_DOUBLE value1, L_DOUBLE value2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_LessThanOrClose(L_DOUBLE value1, L_DOUBLE value2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_GreaterThanOrClose(L_DOUBLE value1, L_DOUBLE value2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_IsOne(L_DOUBLE value);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_IsZero(L_DOUBLE value);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_AreClosePoints(const L_POINTD* point1, const L_POINTD* point2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_AreCloseSizes(const L_SIZED* size1, const L_SIZED* size2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_AreCloseRects(const L_RECTD* rect1, const L_RECTD* rect2);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_IsBetweenZeroAndOne(L_DOUBLE val);
L_LTKRN_API L_INT EXT_FUNCTION L_Double_DoubleToInt(L_DOUBLE val);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_RectHasNaN(const L_RECTD* rect);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_IsNaN(L_DOUBLE value);
L_LTKRN_API L_BOOL EXT_FUNCTION L_Double_IsInfinity(L_DOUBLE value);
L_LTKRN_API L_DOUBLE EXT_FUNCTION L_Double_NormalizeAngle(L_DOUBLE angle);

#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_KERNEL)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTPRIMITIVES_H)
