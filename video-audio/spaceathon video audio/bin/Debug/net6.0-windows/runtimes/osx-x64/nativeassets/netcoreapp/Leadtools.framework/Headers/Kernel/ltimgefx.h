//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTIMGEFX_H)
#define LTIMGEFX_H

#include "lttyp.h"
#define L_LTIMGEFX_API LT_EXPORTED

#include "ltkrn.h"
#include "lttyp.h"
#include "ltdis.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

///****************************************************************
//   Enums/defines/macros/structures
//****************************************************************/

//----------------L_EmbossBitmap Flags-----------------------
#define EMBOSS_N  0x0000
#define EMBOSS_NE 0x0001
#define EMBOSS_E  0x0002
#define EMBOSS_SE 0x0003
#define EMBOSS_S  0x0004
#define EMBOSS_SW 0x0005
#define EMBOSS_W  0x0006
#define EMBOSS_NW 0x0007

//----------------L_ResizeBitmapRgn Flags-----------------------
#define RGN_EXPAND   0x0001
#define RGN_CONTRACT 0x0002

//----------------L_CreateFadedMask Flags-----------------------
#define FADE_OUTER                  0x0001
#define FADE_DUMPFILL               0x0002
#define FADE_FILLCOLOR_START        0x0004
#define FADE_WHITETOBLACK           0x0008
#define FADE_NOTRANSPARENCY         0x0010
#define FADE_TRANSPARENCY_DUMPCOLOR 0x0020

//----------------L_CombineBitmap Flags-----------------------
// flags for L_CombineBitmap
#define CB_SRC_NOP      0x00000000
#define CB_SRC_NOT      0x00000001
#define CB_SRC_0        0x00000002
#define CB_SRC_1        0x00000003
#define CB_DST_NOP      0x00000000
#define CB_DST_NOT      0x00000010
#define CB_DST_0        0x00000020
#define CB_DST_1        0x00000030
#define CB_OP_AND       0x00000000
#define CB_OP_OR        0x00000100
#define CB_OP_XOR       0x00000200
#define CB_OP_ADD       0x00000300
#define CB_OP_SUBSRC    0x00000400
#define CB_OP_SUBDST    0x00000500
#define CB_OP_MUL       0x00000600
#define CB_OP_DIVSRC    0x00000700
#define CB_OP_DIVDST    0x00000800
#define CB_OP_AVG       0x00000900
#define CB_OP_MIN       0x00000A00
#define CB_OP_MAX       0x00000B00
#define CB_OP_ABSDIF    0x00000C00
#define CB_OP_ALPHABLEND 0x00000D00

#define CB_RES_NOP      0x00000000
#define CB_RES_NOT      0x00001000
#define CB_RES_0        0x00002000
#define CB_RES_1        0x00003000

#define CB_SRC_MASTER   0x00000000
#define CB_SRC_RED      0x00010000
#define CB_SRC_GREEN    0x00020000
#define CB_SRC_BLUE     0x00030000

#define CB_DST_MASTER   0x00000000
#define CB_DST_RED      0x00100000
#define CB_DST_GREEN    0x00200000
#define CB_DST_BLUE     0x00300000

#define CB_RES_MASTER   0x00000000
#define CB_RES_RED      0x01000000
#define CB_RES_GREEN    0x02000000
#define CB_RES_BLUE     0x03000000
#define CB_RAWCOMBINE   0x04000000

// useful define for copying the source to the destination
#define L_SRC_COPY      (CB_DST_0 | CB_SRC_NOP | CB_OP_OR)

//----------------L_AntiAliasBitmap Flags-----------------------
#define ANTIALIAS_1     0x0000
#define ANTIALIAS_2     0x0001
#define ANTIALIAS_3     0x0002
#define ANTIALIAS_DIAG  0x0003
#define ANTIALIAS_HORZ  0x0004
#define ANTIALIAS_VERT  0x0005


//----------------L_EdgeDetectorBitmap Flags-----------------------
#define EDG_SOBEL_VERT    0x0101
#define EDG_SOBEL_HORZ    0x0102
#define EDG_SOBEL_ALL     0x0103

#define EDG_PREWITT_VERT  0x0201
#define EDG_PREWITT_HORZ  0x0202
#define EDG_PREWITT_ALL   0x0203

#define EDG_LAPLACE_1     0x0301
#define EDG_LAPLACE_2     0x0302
#define EDG_LAPLACE_3     0x0303
#define EDG_LAPLACE_DIAG  0x0304
#define EDG_LAPLACE_HORZ  0x0305
#define EDG_LAPLACE_VERT  0x0306

#define EDG_GRADIENT_N    0x0401
#define EDG_GRADIENT_NE   0x0402
#define EDG_GRADIENT_E    0x0403
#define EDG_GRADIENT_SE   0x0404
#define EDG_GRADIENT_S    0x0405
#define EDG_GRADIENT_SW   0x0406
#define EDG_GRADIENT_W    0x0407
#define EDG_GRADIENT_NW   0x0408

//----------------L_GetFunctionalLookupTable Flags-----------------------
#define FLT_EXP      0x0000
#define FLT_LN       0x0001
#define FLT_LINEAR   0x0002
#define FLT_SIGMOID  0x0003
#define FLT_SIGNED   0x0010
//#define FLT_USESTOREDVALUE    0x0100

//----------------L_AddFrame Flags-----------------------
#define FRAME_QUALITY_LOW  0x0000
#define FRAME_QUALITY_HIGH 0x0001

#define FRAME_INSIDE    0x0000
#define FRAME_OUTSIDE   0x0001

//----------------L_AddBorder Flags-----------------------
#define BORDER_INSIDE            0x0000
#define BORDER_OUTSIDE           0x0001

#define BORDER_STYLE_TRANSPARENT 0x0000
#define BORDER_STYLE_OPAQUE      0x0001
#define BORDER_STYLE_GRADIENT    0x0002
#define BORDER_STYLE_TILES       0x0003

#define BORDER_EFFECT_CURVEDIN   0x0001
#define BORDER_EFFECT_CURVEDOUT  0x0002
#define BORDER_EFFECT_RAISED     0x0003

#define BORDER_SHADOW_LEFT       0x0000
#define BORDER_SHADOW_RIGHT      0x0001
#define BORDER_SHADOW_SURROUND   0x0002

#define BORDER_GRAD_INSIDEOUT    0x0000
#define BORDER_GRAD_CENTEROUT    0x0001
#define BORDER_GRAD_CORNEROUT    0x0002

//----------------L_GetCurvePoints Flags-----------------------
#define GUB_CURVE    0x0000
#define GUB_LINEAR   0x0001

//---------------- General Flags-----------------------
#define FILL_CLR     0x0000
#define FILL_RPT     0x0001
#define FILL_NOCHG   0x0002
#define FILL_ROT     0x0000
#define FILL_WOUTROT 0x0010

//-------------------L_CubismBitmap Flags-------------------------
#define CUB_BKG   0x0001
#define CUB_COLOR 0x0002

#define CUB_SQR   0x0010
#define CUB_RECT  0x0020

#define CUB_RAND  0x0100
#define CUB_ORNT  0x0200

//------------------L_DeinterlaceBitmap -----------------------------
#define DEINTERLACE_NORMAL 0x0001
#define DEINTERLACE_SMOOTH 0x0002

#define DEINTERLACE_ODD    0x0010
#define DEINTERLACE_EVEN   0x0020

//--------------L_PicturizeBitmap Flags---------------------
#define PICTURIZE_LOADALL     0x0001   // Load all files in memory
#define PICTURIZE_RESIZE      0x0002   // Resize all images that are not the required size
#define PICTURIZE_RESAMPLE    0x0004   // Resample all images that are not the required size
#define PICTURIZE_ONCE        0x0010   // Use the image only once throughout the process
#define PICTURIZE_EQUALUSAGE  0x0020   // Use all images equally, i.e. before an image will be
                                       // used twice all other images must be used at least once
#define PICTURIZE_BESTFIT     0x0040   // Images will be resized to fit the image if the bitmap
                                       // width or height is not a multiple of nCellWidth/nCellHeight

#define CONTOUR_THIN             0x0000
#define CONTOUR_LINK_BLACKWHITE  0x0001
#define CONTOUR_LINK_GRAY        0x0002
#define CONTOUR_LINK_COLOR       0x0003
#define CONTOUR_APPROX_COLOR     0x0004

#define DEFAULT_THRESHOLD        15 // default for background threshold value
#define DEFAULT_DELTADIRECTION   35 // default for maximum angle for the thinning algorithm
#define DEFAULT_MAXIMUMERROR     5  // default for maximum approximation error

//--------------L_UserFilterBitmap Flags---------------------
#define UD_SUM 0x0000
#define UD_MAX 0x0001
#define UD_MIN 0x0002

//-------------- L_EdgeDetectEffectBitmap Flags---------------------
#define EDGE_SOFT    0
#define EDGE_SOLID   1

//---------------- L_OffsetBitmap -----------------------------------
#define FILL_WRAP 0x0003

//---------------- Plasma Data  -----------------------
#define MSKC_EMBOSS           0x0000
#define MSKC_EDGE             0x0001
#define MSKC_ESPLOTCH         0x0002
#define MSKC_SPLOTCH          0x0003

#define FIRST_LINE            0
#define FIRST_PIXEL           0
#define NO_LINE_READ          -1000

#define EMBOSS_COEF           100.0    // Coefficient of Emboss, divide the matrix on this value
#define ANGLE_COEF            100.0    // Coefficient for Angle to give it precision
#define EMBOSS_BIAS8          128      // Bias of Emboss, add this value to resulted values
#define EMBOSS_BIAS16         32768

#define EDGE_COEF             100.0    // Coefficient of Edge Detection, divide the matrix on this value
#define ANGLE_COEF            100.0    // Coefficient for Angle to give it precision
#define EDGE_BIAS             0        // Bias of Edge Detection, add this value to resulted values

#define EMBOSS_SPLOTCH_COEF   100.0    // Coefficient of Edge Detection, divide the matrix on this value
#define ANGLE_COEF            100.0    // Coefficient for Angle to give it precision
#define EMBOSS_SPLOTCH_BIAS8  128      // Bias of Edge Detection, add this value to resulted values
#define EMBOSS_SPLOTCH_BIAS16 32768

#define SPLOTCH_COEF          100.0    // Coefficient of Edge Detection, divide the matrix on this value
#define ANGLE_COEF            100.0    // Coefficient for Angle to give it precision
#define SPLOTCH_BIAS          0        // Bias of Edge Detection, add this value to resulted values

//----------------   L_DisplaceBitmap  -----------------------
#define DSPL_TILE    0x0000
#define DSPL_STRETCH 0x0010

//-----------------L_BinaryFilterBitmap Flags, Macros, -------------------
#define BINARYFLTSIZE(dim)    (sizeof(BINARYFLT) + (sizeof(L_INT) * (((L_INT) (dim) * (L_INT) (dim)) - 1)))
#define MAKEINTBFLT(i)        ((pBINARYFLT)((L_UINT32)((L_UINT16) (i))))

#define BFLT_EROSION_OMNI     MAKEINTBFLT(0)
#define BFLT_EROSION_HORZ     MAKEINTBFLT(1)
#define BFLT_EROSION_VERT     MAKEINTBFLT(2)
#define BFLT_EROSION_DIAG     MAKEINTBFLT(3)
#define BFLT_DILATION_OMNI    MAKEINTBFLT(4)
#define BFLT_DILATION_HORZ    MAKEINTBFLT(5)
#define BFLT_DILATION_VERT    MAKEINTBFLT(6)
#define BFLT_DILATION_DIAG    MAKEINTBFLT(7)

#define BFLT_DONTCARE         256

//-----------------L_SpatialFilterBitmap Flags, Macros, -------------------
#define SPATIALFLTSIZE(dim)   (sizeof(SPATIALFLT) + (sizeof(L_INT) * (((L_INT) (dim) * (L_INT) (dim)) - 1)))
#define MAKEINTFLT(i)         ((pSPATIALFLT)((L_UINT32)((L_UINT16) (i))))

#define FLT_EMBOSS_N          MAKEINTFLT(0)
#define FLT_EMBOSS_NE         MAKEINTFLT(1)
#define FLT_EMBOSS_E          MAKEINTFLT(2)
#define FLT_EMBOSS_SE         MAKEINTFLT(3)
#define FLT_EMBOSS_S          MAKEINTFLT(4)
#define FLT_EMBOSS_SW         MAKEINTFLT(5)
#define FLT_EMBOSS_W          MAKEINTFLT(6)
#define FLT_EMBOSS_NW         MAKEINTFLT(7)

#define FLT_GRADIENT_N        MAKEINTFLT(8)
#define FLT_GRADIENT_NE       MAKEINTFLT(9)
#define FLT_GRADIENT_E        MAKEINTFLT(10)
#define FLT_GRADIENT_SE       MAKEINTFLT(11)
#define FLT_GRADIENT_S        MAKEINTFLT(12)
#define FLT_GRADIENT_SW       MAKEINTFLT(13)
#define FLT_GRADIENT_W        MAKEINTFLT(14)
#define FLT_GRADIENT_NW       MAKEINTFLT(15)

#define FLT_LAPLACE_1         MAKEINTFLT(16)
#define FLT_LAPLACE_2         MAKEINTFLT(17)
#define FLT_LAPLACE_3         MAKEINTFLT(18)
#define FLT_LAPLACE_DIAG      MAKEINTFLT(19)
#define FLT_LAPLACE_HORZ      MAKEINTFLT(20)
#define FLT_LAPLACE_VERT      MAKEINTFLT(21)

#define FLT_SOBEL_HORZ        MAKEINTFLT(22)
#define FLT_SOBEL_VERT        MAKEINTFLT(23)

#define FLT_PREWITT_HORZ      MAKEINTFLT(24)
#define FLT_PREWITT_VERT      MAKEINTFLT(25)

#define FLT_SHIFTDIFF_DIAG    MAKEINTFLT(26)
#define FLT_SHIFTDIFF_HORZ    MAKEINTFLT(27)
#define FLT_SHIFTDIFF_VERT    MAKEINTFLT(28)

#define FLT_LINESEG_HORZ      MAKEINTFLT(29)
#define FLT_LINESEG_VERT      MAKEINTFLT(30)
#define FLT_LINESEG_LTOR      MAKEINTFLT(31)
#define FLT_LINESEG_RTOL      MAKEINTFLT(32)

//-------------- L_GetRgnContourPoints Flags---------------------
#define RGNCONTOUR_ALL       0
#define RGNCONTOUR_OUTSIDE   1


//-------------- L_StitchImages Flags ---------------------------
typedef enum
{
   STITCH_SIDE_MATCHING_TYPE_NONE, /* Do not prioritize any side of the image */
   STITCH_SIDE_MATCHING_TYPE_KEEPRIGHT,  /*                                      ^                                                         */
   STITCH_SIDE_MATCHING_TYPE_KEEPLEFT,   /* Attempt to match a given side of pSrcBitmap                                                    */
   STITCH_SIDE_MATCHING_TYPE_KEEPTOP,    /* For example, KEEPTOP means the program will only focus on stitching the top portion pSrcBitmap */
   STITCH_SIDE_MATCHING_TYPE_KEEPBOTTOM, /*                                      V                                                         */
   STITCH_SIDE_MATCHING_TYPE_ALLSIDES, /* Attempt to match all sides of pSrcBitmap. This neglects data in the center of pSrcBitmap */
}
STITCH_SIDE_MATCHING_TYPE; /* For choosing which side to match on pSrcBitmap */

typedef enum
{
   STITCH_METHOD_TYPE_ESTIMATE,  /* Faster, but it may not work with certain images */
   STITCH_METHOD_TYPE_EXHAUSTIVE, /* Slower, but should produce the best result unconditionally */
}
STITCH_METHOD_TYPE; /* For choosing method of stitching, trade accuracy for speed */

typedef enum
{
   STITCH_IMAGE_TYPE_PICTURE,  /* Pictures */
   STITCH_IMAGE_TYPE_VSCROLL, /* Computer Vertical Scroll */
   STITCH_IMAGE_TYPE_HSCROLL, /* Computer Vertical Scroll */
}
STITCH_IMAGE_TYPE; /* For choosing method of stitching, trade accuracy for speed */

/****************************************************************
   Classes/structures
****************************************************************/

//********************** L_AddFrame Structure**********************
typedef struct _ADDFRAMEINFO
{
   L_UINT         uStructSize;
   pBITMAPHANDLE  pBitmapFrame;
   L_BOOL         bKeepFrameState;
   L_BOOL         bUseMask;
   COLORREF       crMask;
   L_UCHAR        SmoothEdge;
   L_INT          nLocation;
   L_INT          nQuality;
}
ADDFRAMEINFO, *pADDFRAMEINFO;

//********************** L_AddBorder Structure**********************
typedef struct _ADDBORDERINFO
{
   L_UINT         uStructSize;
   L_INT          nLeftThickness;
   L_INT          nTopThickness;
   L_INT          nRightThickness;
   L_INT          nBottomThickness;
   L_INT          nLocation;
   L_INT          nStyle;
   L_INT          nEffectStyle;
   pBITMAPHANDLE  pTileBitmap;
   L_INT          nGradientStyle;
   COLORREF       crGradientStart;
   COLORREF       crGradientEnd;
   L_INT          nCurveIntensity;
   L_BOOL         bSoftCurve;
   L_BOOL         bShadow;
   L_INT          nShadowSize;
   L_INT          nShadowDirection;
   L_BOOL         bBumpyShadow;
}
ADDBORDERINFO, *pADDBORDERINFO;

//********************** L_AddMessageToBitmap and L_ExtractMessageFromBitmap Structure**********************

typedef struct _ADDMESGINFOA
{
   L_UINT   uStructSize;
   L_CHAR   *pStrMsg;
   L_UCHAR  *pPassword;
   L_CHAR   *pFileName;
   L_CHAR   *pDirectory;
   LPPOINT  pStart;
}
ADDMESGINFOA, *pADDMESGINFOA;

#if defined(FOR_UNICODE)
typedef struct _ADDMESGINFO
{
   L_UINT   uStructSize;
   L_TCHAR  *pStrMsg;
   L_TCHAR  *pPassword;
   L_TCHAR  *pFileName;
   L_TCHAR  *pDirectory;
   LPPOINT  pStart;
}
ADDMESGINFO, *pADDMESGINFO;
#else
typedef ADDMESGINFOA ADDMESGINFO;
typedef pADDMESGINFOA pADDMESGINFO;
#endif // #if defined(FOR_UNICODE)

//********************** L_BinaryfilterBitmap Structure**********************
typedef struct _BINARYFLT
{
   L_UINT   uStructSize;
   L_BOOL   bfltMax;       // select maximum value
   L_UINT   bfltDim;       // filter dimensions
   L_INT    bfltMatrix[1]; // array of filter coefficients
}
BINARYFLT, *pBINARYFLT;

//********************** L_SpatialFilterBitmap Structure**********************
typedef struct _SPATIALFLT
{
   L_UINT   uStructSize;
   L_INT    fltDivisor;            // sum divisor
   L_INT    fltBias;               // sum bias
   L_UINT   fltDim;               // filter dimensions
   L_INT    fltMatrix[1];          // array of filter coefficients
}
SPATIALFLT, *pSPATIALFLT;

//********************** L_GetBitmapStatisticsInfo Structure**********************
typedef struct _STATISTICSINFO
{
   L_UINT   uStructSize;
   L_DOUBLE dStdDev;
   L_DOUBLE dMean;
   L_INT    nMedian;
   L_INT    nMax;
   L_INT    nMin;
#if defined(LEADTOOLS_V175_OR_LATER)
   L_UINT64   uPixelCnt;
   L_UINT64   uTotalPixelCnt;
#else
   L_UINT   uPixelCnt;
   L_UINT   uTotalPixelCnt;
#endif // #if defined(LEADTOOLS_V175_OR_LATER)
   L_DOUBLE dPercent;
}
STATISTICSINFO, *pSTATISTICSINFO;

//********************** L_UserFilterBitmap Structure**********************
typedef struct _USERFLT
{
   L_UINT   uStructSize;
   L_UINT   ufltWidth;
   L_UINT   ufltHeight;
   POINT    ufltCenter;
   L_UINT   ufltDivisor;
   L_INT    nfltOffset;
   L_UINT   ufltFlag;
   L_INT    ufltMatrix[1];
}
USERFLT, *pUSERFLT;

//---------------- Mask Convolution Data -----------------------
typedef struct _MyPOINT
{
   L_INT nXPos;
   L_INT nYPos;
   L_INT *nPreValues;
}
MyPOINT, *pMyPOINT;

typedef struct _KERNELINFO
{
   pMyPOINT pPoint;
   L_INT    nCntr;
}
KERNELINFO, *pKERNELINFO;


//********************** L_StitchImages Structures **********************
typedef struct
{
   L_UINT uStructSize;
   L_DOUBLE dMinOverlap; /* Minimum overlap between images in terms of the smaller of the two, has values on [0:1] */
   STITCH_METHOD_TYPE StitchMethod; /* For choosing method of stitching, trade accuracy for speed */
   STITCH_SIDE_MATCHING_TYPE SideMatchingMethod; /* For choosing which side to match on pSrcBitmap */
   STITCH_IMAGE_TYPE ImageType;
   L_RECT* prcStitchArea;
}
STITCH_SETTINGS, * pSTITCH_SETTINGS;

///****************************************************************
//   Callback typedefs
//****************************************************************/

//----------------------------------- callback typedefs --------------------------------------
typedef L_INT (pEXT_CALLBACK PICTURIZECALLBACK)(
   pBITMAPHANDLE  pCellBitmap,
   L_INT          x,
   L_INT          y,
   L_VOID         *pUserData);

///****************************************************************
//   Function prototypes
//****************************************************************/
#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_IMGEFX)

L_LTIMGEFX_API L_INT EXT_FUNCTION L_UnsharpMaskBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nAmount,
   L_INT          nRadius,
   L_INT          nThreshold,
   L_UINT         uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_StitchBitmap(
   pBITMAPHANDLE    pRefBitmap,
   pBITMAPHANDLE*   pToStitchBitmaps,
   L_UINT           uNumToStichBitmaps,
   pSTITCH_SETTINGS pStitchSettings);

// These functions not ported to Windows CE
L_LTIMGEFX_API L_INT EXT_FUNCTION L_SharpenBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nSharpness, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_EdgeDetectorBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nThreshold,
   L_UINT         uFilter, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AverageFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_BinaryFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   pBINARYFLT     pFilter, 
   L_UINT32       uFlags
);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_CombineBitmap(
   pBITMAPHANDLE  pBitmapDst,
   L_INT          nXDst,
   L_INT          nYDst,
   L_INT          nWidth,
   L_INT          nHeight,
   pBITMAPHANDLE  pBitmapSrc,
   L_INT          nXSrc,
   L_INT          nYSrc,
   L_UINT         uMaxedFlags,
   L_UINT32       uFlags
);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_UserFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   pUSERFLT       pFilter, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AddBitmapNoise(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uRange,
   L_UINT         uChannel, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_EmbossBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDirection,
   L_UINT         uDepth, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_MosaicBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AlphaBlendBitmap(
   pBITMAPHANDLE pBitmapDst,
   L_INT          nXDst,
   L_INT          nYDst,
   L_INT          nWidth,
   L_INT          nHeight,
   pBITMAPHANDLE  pBitmapSrc,
   L_INT          nXSrc,
   L_INT          nYSrc,
   L_INT          nOpacity, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AntiAliasBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT         nThreshold,
   L_UINT         uDim,
   L_UINT         uFilter, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetUserLookUpTable(
   L_UINT         *pLookupTable,
   L_UINT         uLookupLen,
   POINT          *apUserPoint,
   L_UINT         uUserPointCount,
   L_UINT         *puPointCount, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_TextureAlphaBlendBitmap(
   pBITMAPHANDLE pBitmapDst,
   L_INT          nXDst,
   L_INT          nYDst,
   L_INT          nWidth,
   L_INT          nHeight,
   pBITMAPHANDLE  pBitmapSrc,
   L_INT          nXSrc,
   L_INT          nYSrc,
   pBITMAPHANDLE  pBitmapMask,
   L_INT          nOpacity,
   pBITMAPHANDLE  pBitmapUnderlay,
   LPPOINT        pOffset, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_SpatialFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   pSPATIALFLT    pFilter, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GaussianFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nRadius, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_OilifyBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_ContourFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT16        nThreshold,
   L_INT16        nDeltaDirection,
   L_INT16        nMaximumError,
   L_INT          nOption, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_MotionBlurBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim,
   L_INT          nAngle,
   L_BOOL         bUnidirectional, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_PicturizeBitmapList(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uCellWidth,
   L_UINT         uCellHeight,
   L_UINT         uLightnessFact,
   HBITMAPLIST    hList, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_PicturizeBitmapSingle(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  pThumbBitmap,
   L_UINT         uCellWidth,
   L_UINT         uCellHeight,
   L_UINT         uLightnessFact, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AddBorder(
   pBITMAPHANDLE  pBitmap,
   pADDBORDERINFO pAddBorderInfo, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AddFrame(
   pBITMAPHANDLE  pBitmap,
   pADDFRAMEINFO  pAddFrameInfo, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_AddMessageToBitmapA(
   pBITMAPHANDLE  pBitmap,
   pADDMESGINFOA   pAddMesgInfo, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_ExtractMessageFromBitmapA(
   pBITMAPHANDLE  pBitmap,
   pADDMESGINFOA   pAddMesgInfo, 
   L_UINT32       uFlags);

#if defined(FOR_UNICODE)
L_LTIMGEFX_API L_INT EXT_FUNCTION L_AddMessageToBitmap(
   pBITMAPHANDLE  pBitmap,
   pADDMESGINFO   pAddMesgInfo, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_ExtractMessageFromBitmap(
   pBITMAPHANDLE  pBitmap,
   pADDMESGINFO   pAddMesgInfo, 
   L_UINT32       uFlags);
#else
#define L_AddMessageToBitmap L_AddMessageToBitmapA
#define L_ExtractMessageFromBitmap L_ExtractMessageFromBitmapA
#endif // #if defined(FOR_UNICODE)

L_LTIMGEFX_API L_INT EXT_FUNCTION L_HolesRemovalBitmapRgn(
   pBITMAPHANDLE  pBitmap, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_EdgeDetectStatisticalBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim,
   L_INT          nThreshold,
   COLORREF       crEdgeColor,
   COLORREF       crBkColor, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_SmoothEdgesBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         nAmount,
   L_UINT         nThreshold, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_SkeletonBitmap(
   pBITMAPHANDLE pBitmap,
   L_INT         nThreshold, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetObjectInfo(
   pBITMAPHANDLE  pBitmap,
   L_UINT         *puX,
   L_UINT         *puY,
   L_INT          *pnAngle,
   L_UINT         *puRoundness,
   L_BOOL         bWeighted, 
   L_UINT32       uFlags);

#if defined (FOR_WINDOWS)
L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetRgnPerimeterLength(
   pBITMAPHANDLE  pBitmap,
   pRGNXFORM      pXForm,
   L_SIZE_T      *puLength, 
   L_UINT32       uFlags);
#endif //#if defined (FOR_WINDOWS)

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetFeretsDiameter(
   POINT    *pPoints,
   L_UINT   uSize,
   L_UINT   *puFeretsDiameter,
   L_UINT   *puFirstIndex,
   L_UINT   *puSecondIndex, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetBitmapStatisticsInfo(
   pBITMAPHANDLE     pBitmap,
   pSTATISTICSINFO   pStatisticsInfo,
   L_UINT            uChannel,
   L_INT             nStart,
   L_INT             nEnd, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_DirectionEdgeStatisticalBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim,
   L_INT          nThreshold,
   L_INT          nAngle,
   COLORREF       crEdgeColor,
   COLORREF       crBkColor, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_HighPassFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uRadius,
   L_UINT         uOpacity, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_ColorHalfToneBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uMaxRad,
   L_INT          nCyanAngle,
   L_INT          nMagentaAngle,
   L_INT          nYellowAngle,
   L_INT          nBlackAngle, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_FeatherAlphaBlendBitmap(
   pBITMAPHANDLE  pBitmapDst,
   L_INT          nXDst,
   L_INT          nYDst,
   L_INT          nWidth,
   L_INT          nHeight,
   pBITMAPHANDLE  pBitmapSrc,
   L_INT          nXSrc,
   L_INT          nYSrc,
   pBITMAPHANDLE  pBitmapMask,
   L_INT          nXMaskShift,
   L_INT          nYMaskShift, 
   L_UINT32       uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetFunctionalLookupTable(L_INT *        pLookupTable,
                                                L_UINT         uLookupLen,
                                                L_INT          nStart,
                                                L_INT          nEnd,
                                                L_INT          nFactor,
                                                L_UINT         uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetCurvePoints(
   L_INT    *pCurve,
   POINT    *apUserPoint,
   L_UINT   uUserPointCount,
   L_UINT   *puPointCount,
   L_UINT   uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_PicturizeBitmapA(
   pBITMAPHANDLE     pBitmap,
   L_CHAR            *pszDirName,
   L_UINT            uFlags,
   L_INT             nCellWidth,
   L_INT             nCellHeight,
   PICTURIZECALLBACK pfnCallback,
   L_VOID            *pUserData);

#if defined(FOR_UNICODE)
L_LTIMGEFX_API L_INT EXT_FUNCTION L_PicturizeBitmap(
   pBITMAPHANDLE     pBitmap,
   L_TCHAR           *pszDirName,
   L_UINT            uFlags,
   L_INT             nCellWidth,
   L_INT             nCellHeight,
   PICTURIZECALLBACK pfnCallback,
   L_VOID            *pUserData);
#else
#define L_PicturizeBitmap L_PicturizeBitmapA
#endif // #if defined(FOR_UNICODE)

L_LTIMGEFX_API L_INT EXT_FUNCTION L_ResizeBitmapRgn(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim,
   L_UINT         uFlags,
   L_BOOL         bAsFrame);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_CreateFadedMask(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  pMaskBitmap,
   L_UINT         uStructSize,
   L_INT          nLength,
   L_INT          nFadeRate,
   L_INT          nStepSize,
   L_INT          nInflate,
   L_UINT         uFlags,
   L_INT          nMaxGray,
   COLORREF       crTransparent);

//*** v14 functions ***
L_LTIMGEFX_API L_INT EXT_FUNCTION L_DeinterlaceBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_CubismBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uSpace,
   L_UINT         uLength,
   L_INT          nBrightness,
   L_INT          nAngle,
   COLORREF       crColor,
   L_UINT         uFlags);


L_LTIMGEFX_API L_INT EXT_FUNCTION L_GetRgnContourPoints(
   pBITMAPHANDLE  pBitmap,
   pRGNXFORM        pXForm,
   POINT   *  *     ppPoints,
   L_UINT  *        puSize,
   L_UINT           uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_EdgeDetectEffectBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uLevel,
   L_INT          nThreshold,
   L_UINT         uFlags);


L_LTIMGEFX_API L_INT EXT_FUNCTION L_OffsetBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nHorizontalShift,
   L_INT          nVerticalShift,
   COLORREF       crBackColor,
   L_UINT         uFlags);


L_LTIMGEFX_API L_INT EXT_FUNCTION L_MaskConvolutionBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nAngle,
   L_UINT         uDepth,
   L_UINT         uHeight,
   L_UINT         uFlags);


L_LTIMGEFX_API L_INT EXT_FUNCTION L_DisplaceMapBitmap(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  pDisplacementMap,
   L_UINT         uHorzFact,
   L_UINT         uVertFact,
   COLORREF       crFill,
   L_UINT         uFlags);

L_LTIMGEFX_API L_INT EXT_FUNCTION L_MatchHistogram (pBITMAPHANDLE pBitmap, pBITMAPHANDLE pRefBitmap, L_UINT uFlags);

#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_IMGEFX)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTIMGEFX_H)
