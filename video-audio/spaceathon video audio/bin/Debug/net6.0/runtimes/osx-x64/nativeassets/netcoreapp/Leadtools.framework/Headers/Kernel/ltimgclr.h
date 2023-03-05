//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTIMGCLR_H)
#define LTIMGCLR_H

#include "lttyp.h"
#define L_LTIMGCLR_API LT_EXPORTED

#include "ltkrn.h"
#include "lttyp.h"
#include "ltdis.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

/****************************************************************
   Enums/defines/macros/structures
****************************************************************/

//----------------L_GetHistogram, L_RemapBitmapIntensity, and L_AddNoiseBitmap Flags-----------------------
#define CHANNEL_MASTER  0x0000   // All channels
#define CHANNEL_RED     0x0001   // Red channel only
#define CHANNEL_GREEN   0x0002   // Green channel only
#define CHANNEL_BLUE    0x0003   // Blue channel only

#define HIST_ALL_BITS      0x0010
#define HIST_LOWHIGH_BITS  0x0000

//----------------L_ColorSeparateBitmap/L_ColorMergeBitmap Flags-----------------------
#define COLORSEP_RGB    0x0000   // Use 3 RGB color planes
#define COLORSEP_CMYK   0x0001   // Use 4 CMYK color planes
#define COLORSEP_HSV    0x0002   // Use 3 HSV color planes
#define COLORSEP_HLS    0x0003   // Use 3 HLS color planes
#define COLORSEP_CMY    0x0004   // Use 3 CMY color planes
#define COLORSEP_YUV    0x0005   // Use 3 YUV color planes
#define COLORSEP_XYZ    0x0006   // Use 3 XYZ color planes
#define COLORSEP_LAB    0x0007   // Use 3 XYZ color planes
#define COLORSEP_YCrCb  0x0008   // Use 3 YCrCb color planes
#define COLORSEP_SCT    0x0009   // Use 3 SCT color planes

#define RGB_SPACE    0x0001
#define YUV_SPACE    0x0002
#define GRAY_SPACE   0x0004
#define SWAP_RG      0x0001
#define SWAP_RB      0x0002
#define SWAP_GB      0x0004
#define SWAP_RGBR    0x0008
#define SWAP_RBGR    0x0010

//----------------L_AddBitmaps and L_AddWeightedBitmaps Flags-----------------------
#define BC_AVG          0x0001
#define BC_ADD          0x0002
#define BC_AVGWEIGHTED  0x0003
#define BC_ADDWEIGHTED  0x0004

//------------------L_SampleTargetBitmap Flags-------------------
#define SAMP_RED     0x0001
#define SAMP_GREEN   0x0002
#define SAMP_BLUE    0x0003
#define SAMP_RGB     0x0004
#define SAMP_LOW     0x0010
#define SAMP_MID     0x0020
#define SAMP_HIGH    0x0030

//--------------L_GrayScaleToMultitone Flags---------------------
#define DT_MONOTONE        0x00000000
#define DT_DUOTONE         0x00000001
#define DT_TRITONE         0x00000002
#define DT_QUADTONE        0x00000003

#define DT_LINEAR          0x00000000
#define DT_USERDEFINE      0x00000001

#define RP_ORDEREDNORMAL   0x00000000
#define RP_ORDEREDINVERSE  0x00000001

#define DT_MIX             0x00000000
#define DT_REPLACE         0x00000001

//--------------L_ColorLevelBitmap Flags---------------------
#define LEVEL_RED    0x00000001
#define LEVEL_GREEN  0x00000010
#define LEVEL_BLUE   0x00000100
#define LEVEL_MASTER 0x00001000

////--------------L_AutoColorLevelBitmap Flags---------------------
#define DEFAULT_GAMMA      0x00000064  // Equivalent to 1.0   (ex. Divide by 100)
#define DEFAULT_BLACK_CLIP 0x00000032  // Equivalent to 0.005 (ex. Divide by 10000)
#define DEFAULT_WHITE_CLIP 0x00000032  // Equivalent to 0.005 (ex. Divide by 10000)

//--------------L_SelectiveColorBitmap Flags---------------------
#define SELCLR_RED      0x00000000
#define SELCLR_YELLOW   0x00000001
#define SELCLR_GREEN    0x00000002
#define SELCLR_CYAN     0x00000003
#define SELCLR_BLUE     0x00000004
#define SELCLR_MAGENTA  0x00000005
#define SELCLR_WHITE    0x00000006
#define SELCLR_NEUTRAL  0x00000007
#define SELCLR_BLACK    0x00000008

//--------------L_SegmentBitmap Flags---------------------
#define SGM_RGB      0x00001
#define SGM_Y        0x00002
#define SGM_U        0x00003
#define SGM_V        0x00004
#define SGM_UV       0x00005
#define SGM_NGTV_UV  0x00010

//--------------L_MathFunctionBitmap Flags---------------------
#define MF_SQR    0x0000
#define MF_LOG    0x0001
#define MF_SQRT   0x0002
#define MF_SIN    0x0003
#define MF_COS    0x0004

//--------------L_ColorThresholdBitmap Flags---------------------
#define CLTH_TYP_BANDPASS     0x00000000
#define CLTH_TYP_BANDREJECT   0x00000001

#define CLTH_MOD_CHANNEL      0x00000000
#define CLTH_MOD_ALL          0x00000010

#define CLTH_VALUE_MIN        0x00000000
#define CLTH_VALUE_MAX        0x00000100
#define CLTH_VALUE_CLAMP      0x00000200

#define CLTH_RGB_SPACE        0x00000000
#define CLTH_HSV_SPACE        0x00000001
#define CLTH_HLS_SPACE        0x00000002
#define CLTH_XYZ_SPACE        0x00000003
#define CLTH_YCrCb_SPACE      0x00000004
#define CLTH_YUV_SPACE        0x00000005
#define CLTH_LAB_SPACE        0x00000006
#define CLTH_CMY_SPACE        0x00000007

//-------------- L_AdaptiveContrastBitmap Flags---------------------
#define ACE_EXP   0x0001
#define ACE_LIN   0x0002

//-------------- L_ApplyMathLogicBitmap Flags---------------------
#define AML_VALUE_NOP   0x00000000
#define AML_VALUE_NOT   0x00000010
#define AML_VALUE_0     0x00000020
#define AML_VALUE_1     0x00000030

#define AML_OP_AND      0x00000000
#define AML_OP_OR       0x00000100
#define AML_OP_XOR      0x00000200
#define AML_OP_ADD      0x00000300
#define AML_OP_SUBFACT  0x00000400
#define AML_OP_SUBVALUE 0x00000500
#define AML_OP_ABSDIF   0x00000600
#define AML_OP_MUL      0x00000700
#define AML_OP_DIVFACT  0x00000800
#define AML_OP_DIVVALUE 0x00000900
#define AML_OP_AVG      0x00000A00
#define AML_OP_MIN      0x00000B00
#define AML_OP_MAX      0x00000C00

#define AML_RES_NOP     0x00000000
#define AML_RES_NOT     0x00001000
#define AML_RES_0       0x00002000
#define AML_RES_1       0x00003000

//---------------- Gamma Ext Data -----------------------
#define YUV_CHANNELS       3
#define KeepInRange8(n)    L_MIN(L_MAX(n, 0), 255)
#define KeepInRange16(n)   L_MIN(L_MAX(n, 0), 65535)

//---------------- L_RemapBitmapIntensity Data -----------------------
#define REMAP_CHANGEHIGHBIT   0x0010
#define REMAP_NORMAL          0x0100

/****************************************************************
   Classes/structures
****************************************************************/

//********************** L_SelectiveColorBitmap Structure **********************
typedef struct _SELCLRINF
{
   L_CHAR   cCyan;
   L_CHAR   cMagenta;
   L_CHAR   cYellow;
   L_CHAR   cBlack;
}
SELCLRINF, *pSELCLRINF;

typedef struct _SELCLR 
{
   L_UINT      uStructSize;
   SELCLRINF   selClrs[9];
}
SELCLR, *pSELCLR;

//********************** L_ColorLevelBitmap and L_AutoColorLevelBitmap Structure**********************

//--------------  Internal structure for LVLCLR structure ---------------------
typedef struct _LVLCLRINF
{
   L_INT   nMinInput;
   L_INT   nMaxInput;
   L_INT   nMinOutput;
   L_INT   nMaxOutput;
   L_UINT  uGamma; // This value represents a double. It should be 100 times the real gamma value.
}
LVLCLRINF, *pLVLCLRINF;

typedef struct _LVLCLR
{
   L_UINT      uStructSize;
   LVLCLRINF   master;
   LVLCLRINF   red;
   LVLCLRINF   green;
   LVLCLRINF   blue;
}
LVLCLR, *pLVLCLR;

//********************** L_BalanceColors Structure**********************
typedef struct _BALANCING
{
   L_UINT   uStructSize;
   L_DOUBLE toRed;
   L_DOUBLE toGreen;
   L_DOUBLE toBlue;
}
BALANCING, *pBALANCING;

//********************** L_ChannelMix Structure**********************
typedef struct _COLORDATA
{
   L_UINT   uStructSize;
   L_INT    nRedFactor;
   L_INT    nGreenFactor;
   L_INT    nBlueFactor;
   L_INT    nConstant;
}
COLORDATA, *pCOLORDATA;

//********************** L_ColorReplaceBitmap Structure**********************
typedef struct _COLORREPLACE
{
   L_UINT   uStructSize;
   COLORREF crColor;
   L_UINT   uFuzziness;
}
COLORREPLACE, *pCOLORREPLACE;

//********************** L_ChangeHueSatIntBitmap Structure**********************
typedef struct _HSIDATA
{
   L_UINT   uStructSize;
   L_INT    nHue;
   L_INT    nSaturation;
   L_INT    nIntensity;
   L_INT    nOuterLow;
   L_INT    nOuterHigh;
   L_INT    nInnerLow;
   L_INT    nInnerHigh;
}
HSIDATA, *pHSIDATA;

//********************** L_ColorThresholdBitmap Structure**********************
typedef struct _COMPDATA
{
   L_UINT   uStructSize;
   L_INT    nMinRange;
   L_INT    nMaxRange;
   L_UINT   uFlags;
}
COMPDATA, *pCOMPDATA;

//********************** L_ColorIntensityBalance Structure**********************
typedef struct _BALANCEDATA
{
   L_UINT   uStructSize;
   L_INT    nRed;
   L_INT    nGreen;
   L_INT    nBlue;
}
BALANCEDATA, *pBALANCEDATA;

/****************************************************************
   Function prototypes
****************************************************************/
#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_IMGCLR)

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ChangeBitmapContrast(
   pBITMAPHANDLE  pBitmap,
   L_INT          nChange, 
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ChangeBitmapHue(
   pBITMAPHANDLE  pBitmap,
   L_INT          nAngle, 
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_TemperatureBitmap (
   pBITMAPHANDLE pBitmap,
   L_INT         nFactor,
   L_UINT32      uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ChangeBitmapIntensity(
   pBITMAPHANDLE  pBitmap,
   L_INT          nChange,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ChangeBitmapSaturation(
   pBITMAPHANDLE  pBitmap,
   L_INT          nChange,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_InvertBitmap(
   pBITMAPHANDLE pBitmap, 
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT  EXT_FUNCTION L_RemapBitmapIntensity (
   pBITMAPHANDLE pBitmap, 
   L_INT  *  pLUT,
   L_UINT uLUTLen,
   L_UINT uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GetBitmapColorCount(
   pBITMAPHANDLE  pBitmap,
   L_UINT         *puCount,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_IntensityDetectBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uLow,
   L_UINT         uHigh,
   COLORREF       crInColor,
   COLORREF       crOutColor,
   L_UINT         uChannel,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_DynamicBinaryBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim,
   L_UINT         uLocalContrast,
   L_UINT32       uFlags);

// These functions not ported to Windows CE
L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorMergeBitmap(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  *ppBitmap,
   L_UINT         uStructSize,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorSeparateBitmap(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  *ppBitmap,
   L_UINT         uStructSize,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GammaCorrectBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uGamma,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_HistoContrastBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nChange,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_PosterizeBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uLevels,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_LineProfile(
   pBITMAPHANDLE  pBitmap,
   L_POINT        FirstPoint,
   L_POINT        SecondPoint,
   L_INT          **pRed,
   L_INT          **pGreen,
   L_INT          **pBlue,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_LineProfile2(
   pBITMAPHANDLE  pBitmap,
   L_POINT*       pFirstPoint,
   L_POINT*       pSecondPoint,
   L_INT          **pRed,
   L_INT          **pGreen,
   L_INT          **pBlue,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GrayScaleBitmapExt(
   pBITMAPHANDLE  pBitmap,
   L_INT          RedFact,
   L_INT          GreenFact,
   L_INT          BlueFact,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_SwapColors(
   pBITMAPHANDLE  pBitmap,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_BalanceColors(
   pBITMAPHANDLE  pBitmap,
   BALANCING      *pRedFact,
   BALANCING      *pGreenFact,
   BALANCING      *pBlueFact,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ConvertToColoredGray(
   pBITMAPHANDLE  pBitmap,
   L_INT          RedFact,
   L_INT          GreenFact,
   L_INT          BlueFact,
   L_INT          RedGrayFact,
   L_INT          GreenGrayFact,
   L_INT          BlueGrayFact,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_HistoEqualizeBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GetBitmapHistogram(
   pBITMAPHANDLE  pBitmap,
   L_UINT64       *pHisto,
   L_SIZE_T       uHistoLen,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_RemapBitmapHue(
   pBITMAPHANDLE  pBitmap,
   L_UINT         *pMask,
   L_UINT         *pHTable,
   L_UINT         *pSTable,
   L_UINT         *pVTable,
   L_UINT         uLUTLen,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_MultiplyBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uFactor,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_LocalHistoEqualizeBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nWidth,
   L_INT          nHeight,
   L_INT          nxExt,
   L_INT          nyExt,
   L_UINT         uType,
   L_UINT         uSmooth,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_SolarizeBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uThreshold,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_StretchBitmapIntensity(
   pBITMAPHANDLE  pBitmap,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_AddBitmaps(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uStructSize,
   HBITMAPLIST    hList,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_AddWeightedBitmaps(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uStructSize,
   HBITMAPLIST    hList,
   L_UINT         *puFactor,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_RemoveRedeyeBitmap(
   pBITMAPHANDLE  pBitmap,
   COLORREF       rcNewColor,
   L_UINT         uThreshold,
   L_INT          nLightness,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_SampleTargetBitmap(
   pBITMAPHANDLE  pBitmap,
   COLORREF       crSample,
   COLORREF       crTarget,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_LightControlBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         *puLowerAvr,
   L_UINT         *puAvrage,
   L_UINT         *puUpperAvr,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_DesaturateBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_AutoBinaryBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ChannelMix(
   pBITMAPHANDLE  pBitmap,
   COLORDATA      *pRedFactor,
   COLORDATA      *pGreenFactor,
   COLORDATA      *pBlueFactor,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GrayScaleToDuotone(
   pBITMAPHANDLE  pBitmap,
   LPRGBQUAD      pNewColor,
   COLORREF       crColor,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GrayScaleToMultitone(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uToneType,
   L_UINT         uDistType,
   LPCOLORREF     pColor,
   LPRGBQUAD      *pGradient,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorLevelBitmap(
   pBITMAPHANDLE  pBitmap,
   pLVLCLR        pLvlClr,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_AutoColorLevelBitmap(
   pBITMAPHANDLE  pBitmap,
   pLVLCLR        pLvlClr,
   L_UINT         uBlackClip,
   L_UINT         uWhiteClip,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_SelectiveColorBitmap(
   pBITMAPHANDLE  pBitmap,
   pSELCLR        pSelClr,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_SegmentBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uThreshold,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorReplaceBitmap(
   pBITMAPHANDLE  pBitmap,
   pCOLORREPLACE  pColorReplace,
   L_UINT         uColorCount,
   L_INT          nHue,
   L_INT          nSaturation,
   L_INT          nBrightness,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ChangeHueSatIntBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nHue,
   L_INT          nSaturation,
   L_INT          nIntensity,
   pHSIDATA       pHsiData,
   L_UINT         uHsiDataCount,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorReplaceWeightsBitmap(
   pBITMAPHANDLE  pBitmap,
   pCOLORREPLACE  pColorReplace,
   L_UINT         uColorCount,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_MathFunctionBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uMType,
   L_UINT         uFactor,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorThresholdBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uColorSpace,
   pCOMPDATA      pCompData,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_AdaptiveContrastBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim,
   L_UINT         uAmount,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ColorIntensityBalance(
   pBITMAPHANDLE  pBitmap,
   pBALANCEDATA   pShadows,
   pBALANCEDATA   pMidTone,
   pBALANCEDATA   pHighLight,
   L_BOOL         bLuminance,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ApplyMathLogicBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nFactor,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_ContBrightIntBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nContrast,
   L_INT          nBrightness,
   L_INT          nIntensity,
   L_UINT32       uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_GammaCorrectBitmapExt(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uGamma,
   L_UINT         uFlags);

L_LTIMGCLR_API L_INT EXT_FUNCTION L_AdjustBitmapTint(
   pBITMAPHANDLE  pBitmap,
   L_INT          nAngleA,
   L_INT          nAngleB,
   L_UINT32       uFlags);

#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_IMGCLR)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTIMGCLR_H)
