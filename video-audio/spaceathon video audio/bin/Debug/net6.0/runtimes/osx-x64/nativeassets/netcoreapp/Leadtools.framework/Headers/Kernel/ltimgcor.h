//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTIMGCOR_H)
#define LTIMGCOR_H

#include "lttyp.h"
#define L_LTIMGCOR_API LT_EXPORTED

#include "ltkrn.h"
#include "lttyp.h"
#include "ltdis.h"
#include "ltprimitives.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

/****************************************************************
   Enums/defines/macros/structures
****************************************************************/

//----------------L_HalfToneBitmap Flags-----------------------
#define HT_PRINT   0x0000
#define HT_VIEW    0x0001
#define HT_RECT    0x0002
#define HT_CIRC    0x0003
#define HT_ELLIPS  0x0004
#define HT_RAND    0x0005
#define HT_LINEAR  0x0006
#define HT_USERDEF 0x0007

//---------------- Fourier Transform Flags-----------------------
#define FFT_FFT         0x00000001
#define FFT_IFFT        0x00000002
#define FFT_BLUE        0x00000010
#define FFT_GREEN       0x00000020
#define FFT_RED         0x00000030
#define FFT_GRAY        0x00000040
#define FFT_IFFT_MAG    0x00000100
#define FFT_IFFT_PHS    0x00000200
#define FFT_IFFT_BOTH   0x00000300
#define FFT_IFFT_CLIP   0x00001000
#define FFT_IFFT_SCL    0x00002000

#define FFT_PAD_NEVER   0x00000000
#define FFT_PAD_OPTIMAL 0x00010000
#define FFT_PAD_SQUARE  0x00020000

#define DFT_DFT         0x00000001
#define DFT_IDFT        0x00000002
#define DFT_BLUE        0x00000010
#define DFT_GREEN       0x00000020
#define DFT_RED         0x00000030
#define DFT_GRAY        0x00000040
#define DFT_IDFT_MAG    0x00000100
#define DFT_IDFT_PHS    0x00000200
#define DFT_IDFT_BOTH   0x00000300
#define DFT_IDFT_CLIP   0x00001000
#define DFT_IDFT_SCL    0x00002000
#define DFT_ALL         0x00010000
#define DFT_RANGE       0x00020000
#define DFT_INSIDE_X    0x00100000
#define DFT_OUTSIDE_X   0x00200000
#define DFT_INSIDE_Y    0x01000000
#define DFT_OUTSIDE_Y   0x02000000

#define FRQ_INSIDE_X    0x00000001
#define FRQ_OUTSIDE_X   0x00000002
#define FRQ_INSIDE_Y    0x00000010
#define FRQ_OUTSIDE_Y   0x00000020

#define DSP_FT_MAG      0x00000001
#define DSP_FT_PHS      0x00000002
#define DSP_FT_NORM     0x00000010
#define DSP_FT_LOG      0x00000020

//--------------L_AutoColorLevelBitmap Flags---------------------
#define AUTO_LEVEL      0x00000001
#define AUTO_CONTRAST   0x00000002
#define AUTO_INTENSITY  0x00000003
#define AUTO_NOPROCESS  0x00000004

//-------------- Constants and Flags for Doc Imaging functions ---------------------
#define SMOOTH_BUMP  0x0000
#define SMOOTH_NICK  0x0001
#define SMOOTH_NONE  0x0002

#define SMOOTH_HORIZONTAL_ELEMENT   0x0000
#define SMOOTH_VERTICAL_ELEMENT     0x0001

#define SUCCESS_REMOVE              0x0001
#define SUCCESS_NOREMOVE            0x0002
#define LINEREMOVE_HORIZONTAL       0x0001
#define LINEREMOVE_VERTICAL         0x0002
#define SUCCESS_INVERT              0x0001
#define SUCCESS_NOINVERT            0x0002

#define BORDER_LEFT        0x0001
#define BORDER_RIGHT       0x0002
#define BORDER_TOP         0x0004
#define BORDER_BOTTOM      0x0008
#define BORDER_ALL         (BORDER_LEFT | BORDER_RIGHT | BORDER_TOP | BORDER_BOTTOM)
#define BORDER_DELTA_MAX   (0xffffffff)

//-------------- flags for iLocation ---------------------
#define HOLEPUNCH_LEFT     0x0001
#define HOLEPUNCH_RIGHT    0x0002
#define HOLEPUNCH_TOP      0x0003
#define HOLEPUNCH_BOTTOM   0x0004

#define STAPLE_TOPLEFT     0x0001
#define STAPLE_TOPRIGHT    0x0002
#define STAPLE_BOTTOMLEFT  0x0003
#define STAPLE_BOTTOMRIGHT 0x0004

#define FLAG_USE_DPI          0x00000001
#define FLAG_SINGLE_REGION    0x00000002
#define FLAG_LEAD_REGION      0x00000004
#define FLAG_CALLBACK_REGION  0x00000008
#define FLAG_IMAGE_UNCHANGED  0x00000010
#define FLAG_USE_SIZE         0x00000020
#define FLAG_USE_COUNT        0x00000040
#define FLAG_USE_LOCATION     0x00000080
#define FLAG_FAVOR_LONG       0x00000100
#define FLAG_REMOVE_ENTIRE    0x00000200
#define FLAG_USE_GAP          0x00000400
#define FLAG_USE_VARIANCE     0x00000800
#define FLAG_USE_DIAGONALS    0x00001000

//--------------L_DeskewBitmap Flags---------------------
#define DSKW_PROCESS    0x00000000
#define DSKW_NOPROCESS  0x00000001

#define DSKW_FILL    0x00000000
#define DSKW_NOFILL  0x00000010

#define DSKW_NOTHRESHOLD   0x00000000
#define DSKW_THRESHOLD     0x00000100

#define DSKW_LINEAR     0x00000000
#define DSKW_RESAMPLE   0x00001000
#define DSKW_BICUBIC    0x00002000

#define DSKW_DOCUMENTIMAGE       0x00000000
#define DSKW_DOCUMENTANDPICTURE  0x00010000

#define DSKW_NORMALSPEEDROTATE  0x00000000
#define DSKW_HIGHSPEEDROTATE    0x00100000

#define DSKW_DONT_USE_CHECK_DESKEW           0x00000000
#define DSKW_USE_CHECK_DESKEW                0x01000000
#define DSKW_USE_CHECK_DESKEW_DETECT_LINES   0x02000000

#define DSKW_PERFORM_PREPROCESSING         0x00000000
#define DSKW_DONT_PERFORM_PREPROCESSING    0x10000000

#define DSKW_SELECTIVE_DETECTION     0x00000000
#define DSKW_NORMAL_DETECTION        0x20000000


#define DSKW_USE_EXTENDED_DESKEW            0x04000000
#define DSKW_DONT_DETECT_DESKEW_ANGLE       0x00000001
#define DSKW_DONT_DETECT_ORIENTATION_ANGLE  0x00000002
#define ORNT_NOPROCESS                      0x00000001

//--------------L_SmoothBitmap Flags---------------------
#define SMOOTH_SINGLE_REGION     FLAG_SINGLE_REGION
#define SMOOTH_LEAD_REGION       FLAG_LEAD_REGION
#define SMOOTH_IMAGE_UNCHANGED   FLAG_IMAGE_UNCHANGED
#define SMOOTH_FAVOR_LONG        FLAG_FAVOR_LONG
#define SMOOTH_ALLFLAGS          (                             \
                                    SMOOTH_SINGLE_REGION    |  \
                                    SMOOTH_LEAD_REGION      |  \
                                    SMOOTH_IMAGE_UNCHANGED  |  \
                                    SMOOTH_FAVOR_LONG          \
                                 )

//--------------L_LineRemoveBitmap Flags---------------------
#define LINE_USE_DPI          FLAG_USE_DPI
#define LINE_SINGLE_REGION    FLAG_SINGLE_REGION
#define LINE_LEAD_REGION      FLAG_LEAD_REGION
#define LINE_CALLBACK_REGION  FLAG_CALLBACK_REGION
#define LINE_IMAGE_UNCHANGED  FLAG_IMAGE_UNCHANGED
#define LINE_REMOVE_ENTIRE    FLAG_REMOVE_ENTIRE
#define LINE_USE_GAP          FLAG_USE_GAP
#define LINE_USE_VARIANCE     FLAG_USE_VARIANCE
#define LINE_ALLFLAGS         (                          \
                                 LINE_USE_DPI         |  \
                                 LINE_SINGLE_REGION   |  \
                                 LINE_LEAD_REGION     |  \
                                 LINE_CALLBACK_REGION |  \
                                 LINE_IMAGE_UNCHANGED |  \
                                 LINE_REMOVE_ENTIRE   |  \
                                 LINE_USE_GAP         |  \
                                 LINE_USE_VARIANCE       \
                              )

//--------------L_BorderRemoveBitmap Flags---------------------
#define BORDER_LEAD_REGION       FLAG_LEAD_REGION
#define BORDER_CALLBACK_REGION   FLAG_CALLBACK_REGION
#define BORDER_SINGLE_REGION     FLAG_SINGLE_REGION
#define BORDER_IMAGE_UNCHANGED   FLAG_IMAGE_UNCHANGED
#define BORDER_USE_VARIANCE      FLAG_USE_VARIANCE
#define BORDER_SMART_AUTO_REMOVE 0x00001000
#define BORDER_ALLFLAGS          (                             \
                                    BORDER_LEAD_REGION      |  \
                                    BORDER_CALLBACK_REGION  |  \
                                    BORDER_SINGLE_REGION    |  \
                                    BORDER_IMAGE_UNCHANGED  |  \
                                    BORDER_USE_VARIANCE        \
                                 )

//--------------L_InvertedTextBitmap Flags---------------------
#define INVERTEDTEXT_USE_DPI           FLAG_USE_DPI
#define INVERTEDTEXT_SINGLE_REGION     FLAG_SINGLE_REGION
#define INVERTEDTEXT_LEAD_REGION       FLAG_LEAD_REGION
#define INVERTEDTEXT_CALLBACK_REGION   FLAG_CALLBACK_REGION
#define INVERTEDTEXT_IMAGE_UNCHANGED   FLAG_IMAGE_UNCHANGED
#define INVERTEDTEXT_USE_DIAGONALS     FLAG_USE_DIAGONALS
#define INVERTEDTEXT_ALLFLAGS          (                                   \
                                          INVERTEDTEXT_USE_DPI          |  \
                                          INVERTEDTEXT_SINGLE_REGION    |  \
                                          INVERTEDTEXT_LEAD_REGION      |  \
                                          INVERTEDTEXT_CALLBACK_REGION  |  \
                                          INVERTEDTEXT_IMAGE_UNCHANGED  |  \
                                          INVERTEDTEXT_USE_DIAGONALS       \
                                       )

//--------------L_DotRemoveBitmap Flags---------------------
#define DOT_USE_DPI           FLAG_USE_DPI
#define DOT_SINGLE_REGION     FLAG_SINGLE_REGION
#define DOT_LEAD_REGION       FLAG_LEAD_REGION
#define DOT_CALLBACK_REGION   FLAG_CALLBACK_REGION
#define DOT_IMAGE_UNCHANGED   FLAG_IMAGE_UNCHANGED
#define DOT_USE_SIZE          FLAG_USE_SIZE
#define DOT_USE_DIAGONALS     FLAG_USE_DIAGONALS
#define DOT_ALLFLAGS          (                          \
                                 DOT_USE_DPI          |  \
                                 DOT_SINGLE_REGION    |  \
                                 DOT_LEAD_REGION      |  \
                                 DOT_CALLBACK_REGION  |  \
                                 DOT_IMAGE_UNCHANGED  |  \
                                 DOT_USE_SIZE         |  \
                                 DOT_USE_DIAGONALS       \
                              )

//--------------L_HolePunchRemoveBitmap Flags---------------------
#define HOLEPUNCH_USE_DPI           FLAG_USE_DPI
#define HOLEPUNCH_SINGLE_REGION     FLAG_SINGLE_REGION
#define HOLEPUNCH_LEAD_REGION       FLAG_LEAD_REGION
#define HOLEPUNCH_CALLBACK_REGION   FLAG_CALLBACK_REGION
#define HOLEPUNCH_IMAGE_UNCHANGED   FLAG_IMAGE_UNCHANGED
#define HOLEPUNCH_USE_SIZE          FLAG_USE_SIZE
#define HOLEPUNCH_USE_COUNT         FLAG_USE_COUNT
#define HOLEPUNCH_USE_LOCATION      FLAG_USE_LOCATION
#define HOLEPUNCH_ALLFLAGS          (                                \
                                       HOLEPUNCH_USE_DPI          |  \
                                       HOLEPUNCH_SINGLE_REGION    |  \
                                       HOLEPUNCH_LEAD_REGION      |  \
                                       HOLEPUNCH_CALLBACK_REGION  |  \
                                       HOLEPUNCH_IMAGE_UNCHANGED  |  \
                                       HOLEPUNCH_USE_SIZE         |  \
                                       HOLEPUNCH_USE_COUNT        |  \
                                       HOLEPUNCH_USE_LOCATION        \
                                    )
#define HOLEPUNCH_NORMAL_DETECTION        0x00000000
#define HOLEPUNCH_ADVANCED_DETECTION      0x00010000

//--------------L_StapleRemoveBitmap Flags---------------------
#define STAPLE_USE_DPI           FLAG_USE_DPI
#define STAPLE_SINGLE_REGION     FLAG_SINGLE_REGION
#define STAPLE_LEAD_REGION       FLAG_LEAD_REGION
#define STAPLE_CALLBACK_REGION   FLAG_CALLBACK_REGION
#define STAPLE_IMAGE_UNCHANGED   FLAG_IMAGE_UNCHANGED
#define STAPLE_USE_SIZE          FLAG_USE_SIZE
#define STAPLE_USE_LOCATION      FLAG_USE_LOCATION
#define STAPLE_ALLFLAGS          (                             \
                                    STAPLE_USE_DPI          |  \
                                    STAPLE_SINGLE_REGION    |  \
                                    STAPLE_LEAD_REGION      |  \
                                    STAPLE_CALLBACK_REGION  |  \
                                    STAPLE_IMAGE_UNCHANGED  |  \
                                    STAPLE_USE_SIZE         |  \
                                    STAPLE_USE_LOCATION        \
                                 )

//--------------L_ConvertBitmapSignedToUnsigned Flags---------------------
#define SHIFT_ZERO_TO_CENTER        0x0000
#define SHIFT_MIN_TO_ZERO           0x0001
#define SHIFT_NEG_TO_ZERO           0x0002
#define SHIFT_RANGE_ONLY            0x0003
#define SHIFT_RANGE_PROCESS_OUTSIDE 0x0004

//--------------L_ApplyLUTBitmap Flags---------------------
#define LUT_SIGNED   0x0001   // The LUT entries are signed

//--------------L_SubtractBackgroundBitmap Flags---------------------
#define SBK_DEPEND      0
#define SBK_1_1         1
#define SBK_1_2         2
#define SBK_1_4         3
#define SBK_1_8         4

#define SBK_BG_DARK     0x00000000
#define SBK_BG_BRIGHT   0x00000001

#define SBK_RES_SHOW    0x00000000
#define SBK_BG_SHOW     0x00000010

//-------------- L_ApplyModalityLUT, L_ApplyLinearModalityLUT flags-----------------------------
#define M_LUT_SIGNED                0x0001   // The LUT entries are signed
#define M_LUT_UPDATE_MIN_MAX        0x0002   // Update MinVal,MaxVal inside the bitmap handle
#define M_LUT_USE_FULL_RANGE        0x0004   // Do not mask the values in the LUT 
#define M_LUT_ALLOW_RANGE_EXPANSION 0x0008   // Allow the function to increase pBitmap->HighBit
                                             // (if needed) to be able to hold the data range after
                                             // applying modality LUT

//-------------- L_ApplyVOILUT,L_ApplyLinearVOILUT flags-----------------------------
#define VOI_LUT_UPDATE_MIN_MAX   0x0001   // Update MinVal,MaxVal inside the bitmap handle
#define VOI_LUT_REVERSE_ORDER    0x0002   // Reverse ordered grayscale (light to dark)
#define VOI_LUT_PAINT_ONLY       0x0004   // Set the LUT for paint only, not image processing (see BITMAPHANDLE.Flags.UseLUT)
#define VOI_LUT_IGNORE_EXISTING_PALETTE   0x0008

//-------------- L_CountLUTColors flags-----------------------------
#define COUNT_LUT_UNSIGNED 0x0001
#define COUNT_LUT_SIGNED   0x0002

//---------------- L_IntensityDetectBitmap Flags-----------------------
#define IDB_CHANNEL_MASTER 0x0000
#define IDB_CHANNEL_RED    0x0001
#define IDB_CHANNEL_GREEN  0x0010
#define IDB_CHANNEL_BLUE   0x0100

//---------------- L_MultiScaleEnhancementBitmap Flags-----------------------
#define MSE_GAUSSIAN 0x0000
#define MSE_RESAMPLE 0x0001
#define MSE_BICUBIC  0x0002
#define MSE_NORMAL   0x0003

#define MSE_EDGEENH  0x0010
#define MSE_LATRED   0x0020
#define MSE_DONTUSE_MULTITHREADING 0x0040


#define MSE_DEFAULT  (L_UINT)-1

//---------------- L_DigitalSubtractBitmap Flags-----------------------
#define DS_CONTRASTENH     0x0001
#define DS_OPTIMIZERANGE   0x0002

//---------------- L_SearchRegMarksBitmap & L_IsRegMarkBitmap Flags-----------------------
#define RGS_T  0x0000

//---------------- L_ApplyTransformationParameters Flags-----------------------
#define RGS_SIZE_NORMAL       0x0001
#define RGS_SIZE_RESAMPLE     0x0002
#define RGS_SIZE_BICUBIC      0x0003
#define RGS_SIZE_FAVORBLACK   0x0010
#define RGS_SIZE_FAVORWHITE   0x0020

//---------------- L_ConvertBitmapUnsignedToSigned Flags-----------------------
#define PROCESS_RANGE_ONLY    0x0001
#define PROCESS_OUTSIDE_RANGE 0x0002

//---------------- L_HalftonePattern   -----------------------
#define HTPATTERN_DOT      0x0001
#define HTPATTERN_LINE     0x0002
#define HTPATTERN_CIRCLE   0x0003
#define HTPATTERN_ELLIPSE  0x0004

//----------------- L_SliceBitmap Structure -----------------
#define SLC_DESKEW         0x0000
#define SLC_WITHOUTDESKEW  0x0001

#define SLC_DSKW_LINEAR    0x00000000
#define SLC_DSKW_RESAMPLE  0x00000010 
#define SLC_DSKW_BICUBIC   0x00000020

#define SLC_WITHOUTCUT     0x0000
#define SLC_CUTSLICES      0x0100

//----------------L_SizeBitmapInterpolate Flags-----------------------

#define SIZE_TRIANGLE                 0x0005
#define SIZE_HERMITE                  0x0006
#define SIZE_BELL                     0x0007
#define SIZE_QUADRATIC_B_SPLINE       0x0008
#define SIZE_CUBIC_B_SPLINE           0x0009
#define SIZE_BOXFILTER                0x000A
#define SIZE_LANCZOS                  0x000B
#define SIZE_MICHELL                  0x000C
#define SIZE_COSINE                   0x000D
#define SIZE_CATROM                   0x000E
#define SIZE_QUADRATIC                0x000F
#define SIZE_CUBIC_CONVOLUTION        0x0010
#define SIZE_BILINEAR                 0x0011
#define SIZE_BRESENHAM                0x0012

//--------------L_BlankPageDetectorBitmap---------------------

#define BLANK_DETECT_EMPTY               0x00000000
#define BLANK_DETECT_NOISY               0x00000001

#define BLANK_NOT_BLEED_THROUGH          0x00000000
#define BLANK_BLEED_THROUGH              0x00000010

#define BLANK_DONT_DETECT_LINES          0x00000000
#define BLANK_DETECT_LINES               0x00000100

#define BLANK_DONT_USE_ACTIVE_AREA       0x00000000
#define BLANK_USE_ACTIVE_AREA            0x00001000

#define BLANK_DEFAULT_MARGIN             0x00000000
#define BLANK_USER_MARGIN                0x00010000

#define BLANK_ADVANCED                   0x00100000
#define BLANK_USE_PIXELS                 0x00000000
#define BLANK_USE_INCHES                 0x00400000
#define BLANK_USE_CENTIMETERS            0x00800000
#define BLANK_DETECT_TEXT_ONLY           0x01000000


//--------------L_AutoBinarizeBitmap---------------------

#define AUTO_BINARIZE_PRE_AUTO                0x00000000
#define AUTO_BINARIZE_NO_PRE                  0x00000001
#define AUTO_BINARIZE_PRE_BG_ELIMINATION      0x00000002
#define AUTO_BINARIZE_PRE_LEVELING            0x00000004

#define AUTO_BINARIZE_THRESHOLD_AUTO          0x00000000
#define AUTO_BINARIZE_THRESHOLD_USER          0x00000010
#define AUTO_BINARIZE_THRESHOLD_PERCENTILE    0x00000020
#define AUTO_BINARIZE_THRESHOLD_MEDIAN        0x00000040

//--------------L_AutoZoneBitmap---------------------

#define AUTOZONE_DETECT_TEXT                        0x00000001
#define AUTOZONE_DETECT_GRAPHIC                     0x00000002
#define AUTOZONE_DETECT_TABLE                       0x00000004

#define AUTOZONE_DONT_ALLOW_OVERLAP                 0x00000000
#define AUTOZONE_ALLOW_OVERLAP                      0x00000010
#define AUTOZONE_ACCURATE_ZONES                     0x00000000
#define AUTOZONE_GENERAL_ZONES                      0x00000100

#define AUTOZONE_DONT_RECOGNIZE_ONE_CELL_TABLE      0x00000000
#define AUTOZONE_RECOGNIZE_ONE_CELL_TABLE           0x00001000

#define AUTOZONE_NORMAL_TABLE                       0x00000000
#define AUTOZONE_ASIAN_ZONING                       0x00000200
#define AUTOZONE_ADVANCED_TABLE                     0x00002000
#define AUTOZONE_LINES_RECONSTRUCTION               0x00004000
#define AUTOZONE_TEXT_DETECTION                     0x00008000
#define AUTOZONE_DETECT_CHECKBOX                    0x00010000
#define AUTOZONE_DETECT_ALL                         0x00010007

#define AUTOZONE_TEXTBOOK                           0x00040000
#define AUTOZONE_DETECT_VERTICAL_TEXT               0x00100000
#define AUTOZONE_FAVOR_GRAPHICS                     0x00400000

#define AUTOZONE_CHECKBOX_SENSITIVITY_HIGH          0x00000000 //detects objects with shapes that are highly likely to be checkboxes, i.e., has small margin of error, so less false negative
#define AUTOZONE_CHECKBOX_SENSITIVITY_LOW           0x00200000 //detects objects with shapes that are likely to be checkboxes, i.e., has large margin of error.

#if defined (LEADTOOLS_V21_OR_LATER)
#define AUTOZONE_ICR_ZONING                         0x00000080
#endif // #if defined (LEADTOOLS_V21_OR_LATER)

////Do not use below numbers, they are allocated for internal use.
//#define AUTOZONE_GET_TEXT_CHARACTER_COUNT 0x10000000
//#define AUTOZONE_ISINVERTED               0x20000000
//#define AUTOZONE_DO_NOT_DETECT_LINES      0x40000000

///////////// L_CLAHE-----------------------------------
#define CLAHE_RAYLIEH                       0x00001
#define CLAHE_EXPONENTIAL                   0x00002
#define CLAHE_NORMAL                        0x00004
#define CLAHE_SIGMOID                       0x00008
#define CLAHE_RETURN8BITIMAGE               0x00010
#define CLAHE_RETURN16BITIMAGE              0x00020

#define AUTOZONE_USE_MULTITHREADING                 0x00000000
#define AUTOZONE_DONTUSE_MULTITHREADING             0x80000000

#define IMAGE_REGISTRATION_UNKNOWN   0x00000000
#define IMAGE_REGISTRATION_XY        0x00000001
#define IMAGE_REGISTRATION_RSXY      0x00000002
#define IMAGE_REGISTRATION_AFFINE6   0x00000003
#define IMAGE_REGISTRATION_AFFINE8   0x00000004

#define LEAD_ZONE_TYPE_TEXT       0
#define LEAD_ZONE_TYPE_GRAPHIC    1
#define LEAD_ZONE_TYPE_TABLE      2
#define LEAD_ZONE_TYPE_DOT_LINE   3

//--------------L_InvertedPageBitmap-------------------
#define INVERTEDPAGE_PROCESS        0x00000000
#define INVERTEDPAGE_NOPROCESS      0x00000001
#define INVERTEDPAGE_EXCLUDE_BORDER 0x00000002
#define INVERTEDPAGE_USE_ZONES      0x00000004

//--------------L_HighQualityRotateBitmap--------------
#define HIGHQUALITYROTATE_CROP        0x0000
#define HIGHQUALITYROTATE_RESIZE      0x0001

#define HIGHQUALITYROTATE_HIGH        0x0000
#define HIGHQUALITYROTATE_BEST        0x0010

//--------------TISSUE EQUALIZE FLAGS--------------
#define TISSUEEQUALIZE_SIMPLIFY        0x00000001
#define TISSUEEQUALIZE_INTENSIFY       0x00000002

//-------------- L_ExtractObjectsXX directions ---------------
#define EXOBJ_DIRECTION_EAST  0
#define EXOBJ_DIRECTION_NORTH 1
#define EXOBJ_DIRECTION_WEST  2
#define EXOBJ_DIRECTION_SOUTH 3

//-------------- L_ExtractObjectsXX locations ---------------
#define EXOBJ_LOCATION_AFTER     0
#define EXOBJ_LOCATION_BEFORE    1
#define EXOBJ_LOCATION_CHILD     2
#define EXOBJ_LOCATION_SIBLING   3


#if defined LEADTOOLS_V21_OR_LATER
//-------------- L_ICRBinarize ---------------
#define ICRBINARIZE_REMOVE_PAGE_LINES     1
#endif

//-------------- L_ExtractObjectsBitmap flags ---------------
#define EXOBJ_8_CONNECTIVITY              0x0001   // Pass to enable 8-way connectivity (diagonals), otherwise 4-way (only NSEW)
#define EXOBJ_OUTLINE                     0x0002   // Extract pixels along each object's outline
#define EXOBJ_DETECT_CHILDREN             0x0004   // Detect the children for each object, and output as a tree of nested objects
#define EXOBJ_REPORT_IGNORED              0x0008   // Return ignored noise/containers in their respective lists
#define EXOBJ_IGNORE_SMALL_NOISE          0x0010   // Ignore small noise during extraction (refer to nSmallNoiseThreshold)
#define EXOBJ_IGNORE_LARGE_NOISE          0x0020   // Ignore large noise during extraction (refer to nLargeNoiseThreshold)
#define EXOBJ_IGNORE_CONTAINERS           0x0040   // (Requires _DETECT_CHILDREN) Ignore containers during extraction (refer to uContainerMinCount)
#define EXOBJ_CHECK_CONTAINER_SUBCHILDREN 0x0080   // (Requires _IGNORE_CONTAINERS) Check the number of children in a container by recursing to lower objects (not just immediate children)
#define EXOBJ_CHECK_FOR_TABLES            0x0100   // (Requires _CHECK_CONTAINER_SUBCHILDREN) When filtering out a container, attempt to preserve the cell containers as children (refer to dTableMaxBorderPercent)
#define EXOBJ_USE_MULTICOLORS             0x0200   // Extract objects for each specified color level (instead of just 1 BPP)
#define EXOBJ_SORT_TOPLEFT                0x0400   // Sort the object lists in each EXOBJ_RESULT structure (sub-lists not sorted)
#define EXOBJ_FLATTEN                     0x0800   // (Requires _DETECT_CHILDREN) Flatten the final lists to store the children of an object immediately after the parent, rather than in a tree structure. Note: Using _SORT_TOPLEFT is applied after the flattening and will remove the parent-child ordering.

//-------------- L_ExtractObjects_CalcContentBound flags ---------------
#define EXOBJ_CONTENTBOUND_OPTIMIZED_FOR_REPETITION   0x1   // Cache certain calculations from this iteration for use in consecutive calls

//-------------- L_ExtractObjects_CalcRegion flags ---------------
#define EXOBJ_REGION_HORIZONTAL  0x1   // Extract the region as horizontal segments
#define EXOBJ_REGION_VERTICAL    0x2   // Extract the region as vertical segments

//-------------- L_ExtractObjects_FilterList flags ---------------
#define EXOBJ_FILTER_REPORT_REMOVED_OBJECTS  0x1   // Return a new list containing the filtered out objects (refer to pRemoved)
#define EXOBJ_FILTER_INVERT_RANGE            0x2   // Invert the range (min <= filtered out <= max [instead of: filtered out < min or max < filtered out])


///****************************************************************
//   Classes/structures
//****************************************************************/

L_DECLARE_HANDLE(FORMIDENTIFIER);
typedef FORMIDENTIFIER* pFORMIDENTIFIER;

L_DECLARE_HANDLE(GWIREHANDLE);
typedef GWIREHANDLE* pGWIREHANDLE;

typedef struct _RAKEREMOVE {
   L_INT nMinLength;
   L_INT nMaxWidth;
   L_INT nMinWallHeight;
   L_INT nMaxWallPercent;
   L_INT nMaxSideteethLength;
   L_INT nMaxMidteethLength;
   L_INT nTeethSpacing;
   L_INT nGaps;
   L_INT nVariance;
}RAKEREMOVE, *pRAKEREMOVE;

typedef L_INT(pEXT_CALLBACK RAKEREMOVECALLBACK)(
   L_HRGN      hRgn,
   L_INT       nLength,
   L_VOID      *pUserData);

typedef L_INT(pEXT_CALLBACK OBJECTCOUNTERCALLBACK)(
   L_RECT      rcRect,
   L_INT      **Object,
   L_VOID      *pUserData);

typedef struct _OBJECTINFO
{
   L_RECT     rcRect;
   L_INT      **pObject;

}OBJECTINFO, *pOBJECTINFO;

typedef HANDLE MAGICWANDHANDLE;
typedef MAGICWANDHANDLE * pMAGICWANDHANDLE;

typedef L_INT(pEXT_CALLBACK AUTOZONECALLBACK)(
   PRECT    pRect,
   L_UINT   uType,
   L_VOID   *pUserData);

//****************** L_AutoZoneBitmap Structure*******************

typedef struct _LEADZONE
{
   L_UINT uStructSize;
   L_UINT uIndex;
   L_UINT uZoneType;
   RECT   rcLocation;
   L_VOID* pZoneData;
} LEADZONE, *pLEADZONE;

typedef struct _TABLEZONE
{
   PRECT       pCells;
   L_UINT       Rows;
   L_UINT       Columns;
   L_UINT       nCellsCount;
   L_UINT* puCellTypes;
   L_INT* InsideCellsNumber;
   L_RECT** ppInsideRects;
   L_RECT* pBoundsToDraw;
   L_UINT* puCellTextTypes;
}TABLEZONE, *pTABLEZONE;

typedef struct _TEXTZONE
{
   PRECT       pTextLines;
   L_UINT      uTextLinesCount;
}TEXTZONE, *pTEXTZONE;

typedef struct _DOTLINEZONE
{
   L_RECT* pDots;
   L_UINT  uDotsCount;
   L_BOOL  bIsVerticalLine;
}DOTLINEZONE, *pDOTLINEZONE;


//********************** FT functions Structure**********************

typedef struct _COMPLEX
{
   L_DOUBLE r;
   L_DOUBLE i;
}
L_COMPLEX, *pCOMPLEX;

typedef struct _FTARRAY
{
   L_UINT uStructSize;
   L_UINT uWidth;
   L_UINT uHeight;
   L_COMPLEX acxData[1];
}
FTARRAY, *pFTARRAY;


//********************** L_SmoothBitmap Structure**********************
typedef struct _SMOOTH
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_INT          iLength;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
   L_HRGN         hRgn;
}
SMOOTH, *pSMOOTH;

//********************** L_HolePunchRemoveBitmap Structure**********************
typedef struct _HOLEPUNCH
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_INT          iMinHoleCount;
   L_INT          iMaxHoleCount;
   L_INT          iMinHoleWidth;
   L_INT          iMinHoleHeight;
   L_INT          iMaxHoleWidth;
   L_INT          iMaxHoleHeight;
   L_INT          iLocation;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
   L_HRGN         hRgn;
}
HOLEPUNCH, *pHOLEPUNCH;

//********************** L_StapleRemoveBitmap Structure**********************
typedef struct _STAPLE
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_INT          iMinLength;
   L_INT          iMaxLength;
   L_INT          iLocation;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
   L_HRGN         hRgn;
}
STAPLE, *pSTAPLE;

//********************** L_DotRemoveBitmap Structure**********************
typedef struct _DOTREMOVE
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_INT          iMinDotWidth;
   L_INT          iMinDotHeight;
   L_INT          iMaxDotWidth;
   L_INT          iMaxDotHeight;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
   L_HRGN         hRgn;
}
DOTREMOVE, *pDOTREMOVE;

//********************** L_InvertedTextBitmap Structure**********************
typedef struct _INVERTEDTEXT
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_INT          iMinInvertWidth;
   L_INT          iMinInvertHeight;
   L_INT          iMinBlackPercent;
   L_INT          iMaxBlackPercent;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
   L_HRGN         hRgn;
}
INVERTEDTEXT, *pINVERTEDTEXT;

//********************** L_BorderRemoveBitmap Structure**********************
typedef struct _BORDERREMOVE
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_UINT         uBorderToRemove;
   L_INT          iBorderPercent;
   L_INT          iWhiteNoiseLength;
   L_INT          iVariance;
   L_HRGN         hRgn;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
}
BORDERREMOVE, *pBORDERREMOVE;

//********************** L_LineRemoveBitmap Structure**********************
typedef struct _LINEREMOVE
{
   L_UINT         uStructSize;
   L_UINT         uFlags;
   L_INT          iMinLineLength;
   L_INT          iMaxLineWidth;
   L_INT          iWall;
   L_INT          iMaxWallPercent;
   L_INT          iGapLength;
   L_INT          iVariance;
   L_UINT         uRemoveFlags;
   L_HRGN         hRgn;
   pBITMAPHANDLE  pBitmapRegion;
   L_UINT         uBitmapStructSize;
}
LINEREMOVE, *pLINEREMOVE;

//********************** L_ColorizeGrayBitmap Structure**********************
typedef struct _LTGRAYCOLOR
{
   L_UINT   uStructSize;
   RGBQUAD  crColor;
   L_UINT   uThreshold;
}
LTGRAYCOLOR, *pLTGRAYCOLOR;

//********************** L_SearchRegMarksBitmap Structure**********************
typedef struct _SEARCHMARKS
{
   L_UINT   uStructSize;
   L_UINT   uType;
   L_UINT   uWidth;
   L_UINT   uHeight;
   L_UINT   uMinScale;
   L_UINT   uMaxScale;
   RECT     rcRect;
   L_UINT   uSearchMarkCount;
   POINT    *pMarkDetectedPoints;
   L_UINT   uMarkDetectedCount;
}
SEARCHMARKS, *pSEARCHMARKS;

//********************** L_SliceBitmap Structure**********************
typedef struct _SLICEBITMAPOPTIONS
{
   L_UINT   uStructSize;
   L_UINT   uMaxDeskewAngle;
   L_INT    crFill;
   L_INT    uFlags;
}
SLICEBITMAPOPTIONS, *pSLICEBITMAPOPTIONS;

//**************************L_BlankPageDetectorBitmap***********************
typedef struct _PAGEMARGINS
{
   L_UINT   uTopMargin;
   L_UINT   uBottomMargin;
   L_UINT   uLeftMargin;
   L_UINT   uRightMargin;
}
PAGEMARGINS, *pPAGEMARGINS;

#if defined LEADTOOLS_V21_OR_LATER

typedef struct _BLANKPAGEDETECTOROPTIONS
{
   L_UINT   uStructSize;
   L_BOOL   bIsBlank;
   L_UINT   uAccuracy;
   PAGEMARGINS PMargins;
   L_UINT uSensitivity;
   L_UINT uMinimumTextSize;
   L_UINT uFlags;
}
BLANKPAGEDETECTOROPTIONS, *pBLANKPAGEDETECTOROPTIONS;
#endif


#define MICR_DETECTION_NORMAL                                0x0000//100
#define MICR_DETECTION_OVERLAPPED_CHAR                       0x0001// 40
#define MICR_DETECTION_BLUR_IMAGE                            0x0002// 40
#define MICR_DETECTION_INCORRECT_FIELDS_COUNT                0x0004// 80
#define MICR_DETECTION_LARGE_FIELDS_DISTANCE                 0x0008// 80
#define MICR_DETECTION_MISSING_CHAR                          0x0010// 40
#define MICR_DETECTION_NOISY                                 0x0020// 40
#define MICR_DETECTION_ATTACHED_TO_SIGNATURE                 0x0040// 40
//#define MICR_DETECTION_INCORRECT_PATTERNS                    0x0080// 40

typedef struct _MICRCODEDETECTOROPTIONS
{
   L_UINT  uStructSize;
   L_RECT  rcInputROI;
   L_RECT  rcMICRZone;
   L_RECT* pOCRAOutrc;
   L_INT   nOCRACount;
   L_INT   nConfidence;
   L_UINT  uIssues;
}
MICRCODEDETECTOROPTIONS, *pMICRCODEDETECTOROPTIONS;



//**************************L_DetectBitmapDeskewOrientation***********************
typedef struct _DESKEWDETECTION
{
   L_UINT   uStructSize;
   L_UINT   uFlags;//DSKW_USE_EXTENDED_DESKEW//
   L_INT32  pnDeskewAngle;
   L_UINT   uAngleRange;
   L_UINT   uAngleResolution;
   COLORREF crBack;
}
DESKEWDETECTION, *pDESKEWDETECTION;

typedef struct _ORIENTATIONDETECTION
{
   L_UINT   uStructSize;
   L_UINT   uFlags;
   L_INT32  nOrientationAngle;
}
ORIENTATIONDETECTION, *pORIENTATIONDETECTION;


#define MRZ_FIND_ORIENTATION_ANGLE     0x0001
#define MRZ_FIND_DESKEW_ANGLE          0x0002
#define MRZ_DOUBLE_PASS_PROCESSING     0x0004
#define MRZ_EXPAND_MRZ_ZONE            0x0008
#define MRZ_RETURN_PROCESSED_IMAGE     0x0010

typedef struct _MRZDETECTION
{
   L_UINT   uStructSize;
   L_UINT   uFlags;
   L_RECT   rcROI;
   L_RECT   rcMRZZone;
   L_INT    nOrientationAngle;
   L_BOOL   bVerticallyFlipped;
   L_FLOAT  fDeskewAngle;
}
MRZDETECTION, *pMRZDETECTION;

//************************ L_ExtractObjectsXX shared structures ************************
typedef struct _EXOBJ_OBJECT *pEXOBJ_OBJECT;
typedef struct _EXOBJ_OBJECTLIST *pEXOBJ_OBJECTLIST;
typedef struct _EXOBJ_OUTLINE_POINT *pEXOBJ_OUTLINE_POINT;
typedef struct _EXOBJ_OUTLINE_POINTLIST *pEXOBJ_OUTLINE_POINTLIST;
typedef struct _EXOBJ_SEGMENT *pEXOBJ_SEGMENT;
typedef struct _EXOBJ_SEGMENTLIST *pEXOBJ_SEGMENTLIST;

typedef struct _EXOBJ_OBJECT
{
   L_UINT uStructSize;
   pEXOBJ_OBJECT pPrev;                   // Pointer to the previous object in the list
   pEXOBJ_OBJECT pNext;                   // Pointer to the next object in the list
   L_BOOL bWhiteOnBlack;                  // If this object is white on black background
   L_RECT rcTotalBounds;                  // The total bounding rectangle for an object (defaults to outline bounds, but must be maintained if siblings are added by user)
   pEXOBJ_OUTLINE_POINTLIST pOutline;     // Pointer to the outline for an object. Note: This will contain four points (each corner) if it's around a single pixel
   pEXOBJ_SEGMENTLIST pRegionHorizontal;  // Pointer to the region for an object stored as a collection of horizontal segments
   pEXOBJ_SEGMENTLIST pRegionVertical;    // Pointer to the region for an object stored as a collection of vertical segments
   L_UINT64 uImmediatePixelCount;         // The number of pixels for the object excluding any children
   pEXOBJ_OBJECTLIST pChildren;           // Pointer to the children of the object
   L_UINT64 uImmediateChildCount;         // The number of immediate children (this will be equal to pChildren->uCount)
   pEXOBJ_OBJECTLIST pSiblings;           // Optional pointer to the siblings of the object. Note: This will not be populated by L_ExtractObjectsBitmap, but will be used by helper methods if populated by user
   L_VOID *pUserData;                     // For internal use only
}
EXOBJ_OBJECT, *pEXOBJ_OBJECT;

typedef struct _EXOBJ_OBJECTLIST
{
   L_UINT uStructSize;
   pEXOBJ_OBJECT pHead; // Pointer to the first object
   pEXOBJ_OBJECT pTail; // Pointer to the last object (for fast adding, should use count)
   L_UINT uCount;       // Number of objects in list
}
EXOBJ_OBJECTLIST, *pEXOBJ_OBJECTLIST;

typedef struct _EXOBJ_OUTLINE_POINT
{
   L_UINT uStructSize;
   pEXOBJ_OUTLINE_POINT pPrev;   // Pointer to the previous outline point in the list
   pEXOBJ_OUTLINE_POINT pNext;   // Pointer to the next outline point in the list
   L_POINT ptPosition;           // The pixel coordinates for the outline point
   L_UINT8 uDirection;           // Direction to the next outline point
}
EXOBJ_OUTLINE_POINT, *pEXOBJ_OUTLINE_POINT;

typedef struct _EXOBJ_OUTLINE_POINTLIST
{
   L_UINT uStructSize;
   L_RECT rcBounds;              // The bounding rectangle for the positions
   pEXOBJ_OUTLINE_POINT pHead;   // Pointer to the first outline point
   pEXOBJ_OUTLINE_POINT pTail;   // Pointer to the last outline point
   L_UINT uCount;                // Number of outline points
}
EXOBJ_OUTLINE_POINTLIST, *pEXOBJ_OUTLINE_POINTLIST;

typedef struct _EXOBJ_SEGMENT
{
   L_UINT uStructSize;
   pEXOBJ_SEGMENT pPrev;   // Pointer to the previous segment in the list
   pEXOBJ_SEGMENT pNext;   // Pointer to the next segment in the list
   L_RECT rcBounds;        // The bounds for this segment
}
EXOBJ_SEGMENT, *pEXOBJ_SEGMENT;

typedef struct _EXOBJ_SEGMENTLIST
{
   L_UINT uStructSize;
   pEXOBJ_SEGMENT pHead;   // Pointer to the first segment in the list
   pEXOBJ_SEGMENT pTail;   // Pointer to the last segment in the list
   L_UINT uCount;          // The number of segments in the list
   L_UINT uTotalArea;      // The total number of pixels represented by this segment list (equal to the area of the region)
}
EXOBJ_SEGMENTLIST, *pEXOBJ_SEGMENTLIST;

//************************ L_ExtractObjectsBitmap structures ************************
typedef struct _EXOBJ_RESULT *pEXOBJ_RESULT;

typedef struct _EXOBJ_COLORINFO
{
   L_UINT uStructSize;
   L_COLORREF crColor;  // The specified color
   L_UINT uThreshold;   // Maximum distance of equality (euclidean distance in RGB-space)
}
EXOBJ_COLORINFO, *pEXOBJ_COLORINFO;

typedef struct _EXOBJ_DATA
{
   L_UINT uStructSize;
   L_VOID *pInternal;   // For internal use only
   pEXOBJ_RESULT pHead; // Pointer to the first result
   pEXOBJ_RESULT pTail; // Pointer to the last result
   L_UINT uCount;       // Number of result structures (will be one if multi-color not used)
}
EXOBJ_DATA, *pEXOBJ_DATA;

typedef struct _EXOBJ_OPTIONS
{
   L_UINT64 uStructSize;
   L_UINT uFlags;                   // Flags for specifying the extraction method
   L_RECT *pROI;                    // Optional region of interest
   L_INT nSmallNoiseThreshold;      // The maximum pixel size of noise that will be considered too small
   L_INT nLargeNoiseThreshold;      // The minimum pixel size of noise that will be considered too large (if specified, must be larger than nSmallNoiseThreshold)
   L_UINT uContainerMinCount;       // The minimum number of sub-objects within a container before ignoring
   L_DOUBLE dTableMaxBorderPercent; // The maximum percentage of black pixels (estimated by area of bounding rectangles) for a container to be considered a table
   L_INT nTableSizeThreshold;       // The minimum pixel size for a container to be considered a table
   EXOBJ_COLORINFO *pColorInfo;     // Optional array of color info structures (pass NULL to pull from bitmap handle)
   L_UINT uColorInfoCount;          // The number of color info in pColorInfo (pass 0 to pull from bitmap handle)
   L_INT nMaxObjectCount;           // The maximum number of objects to return (or 0 for all objects). Note: Containers will count towards this number even if ignored, while small/large noise will not.
}
EXOBJ_OPTIONS, *pEXOBJ_OPTIONS;

typedef struct _EXOBJ_RESULT
{
   L_UINT64 uStructSize;
   pEXOBJ_RESULT pPrev;             // Pointer to the previous result in the list
   pEXOBJ_RESULT pNext;             // Pointer to the next result in the list
   pEXOBJ_OBJECTLIST pObjects;      // Pointer to the list of extracted objects (hierarchy preserved if the _DETECT_CHILDREN flag is provided)
   pEXOBJ_OBJECTLIST pSmallNoise;   // Pointer to the list of noise that was too small (hierarchy not preserved)
   pEXOBJ_OBJECTLIST pLargeNoise;   // Pointer to the list of noise that was too large (hierarchy not preserved)
   pEXOBJ_OBJECTLIST pContainers;   // Pointer to the list of containers with too many sub-objects (hierarchy not preserved)
}
EXOBJ_RESULT, *pEXOBJ_RESULT;

//************************ L_ExtractObjects_CalcContentBound structures ************************
typedef struct _EXOBJ_CONTENTBOUND
{
   L_UINT uStructSize;
   L_RECT rcInput;      // Search rectangle
   L_RECT rcContent;    // Content bounds (output)
}
EXOBJ_CONTENTBOUND, *pEXOBJ_CONTENTBOUND;

typedef struct _EXOBJ_CONTENTBOUND_OPTIONS
{
   L_UINT uStructSize;
   L_UINT uFlags;                      // Flags for specifying the calculation method
   L_VOID *pInternalCache;             // Internal cache of previous calculations. To free, use L_ExtractObjects_ClearInternalCache
   pEXOBJ_OBJECT *pObjectsOfInterest;  // Array of objects to process (not used if providing the internal cache from a previous run)
   L_UINT uObjectsOfInterestCount;     // Number of objects in pObjectsOfInterest
   L_UINT uFullObjectMargin;           // Additional margin when extracting full object bounds (set to 0 to disable and use outline-only clipping)
}
EXOBJ_CONTENTBOUND_OPTIONS, *pEXOBJ_CONTENTBOUND_OPTIONS;

//************************ L_ExtractObjects_CalcRegion structures ************************
typedef struct _EXOBJ_REGION_OPTIONS
{
   L_UINT uStructSize;
   L_UINT uFlags;       // Flags for specifying the calculation method
}
EXOBJ_REGION_OPTIONS, *pEXOBJ_REGION_OPTIONS;

//************************ L_ExtractObjects_FilterList structures ************************
typedef struct _EXOBJ_FILTER_OPTIONS
{
   L_UINT uStructSize;
   L_UINT uFlags;                // Flags for specifying the filtering method
   pEXOBJ_OBJECTLIST pRemoved;   // Pointer to be populated with the removed objects (requires _OUTPUT_REMOVED)
   L_INT nSmallObjectThreshold;  // The maximum size of an object that will be considered too small
   L_INT nLargeObjectThreshold;  // The minimum size of an object that will be considered too large (if specified, must be larger than nSmallObjectThreshold)
}
EXOBJ_FILTER_OPTIONS, *pEXOBJ_FILTER_OPTIONS;

//************************ L_FindBarcodCandidateAreas structures ************************
#define BARCODE_CANDIDATE_AREAS_USE_PIXELS                 0x00000001
#define BARCODE_CANDIDATE_AREAS_USE_INCHES                 0x00000002
#define BARCODE_CANDIDATE_AREAS_USE_CENTIMETERS            0x00000003

struct _tagFIND_BARCODE_CANDIDATE_AREAS_OPTIONS
{
   L_UINT uStructSize;
   L_COLORREF BarcodeColor;
   L_COLORREF BackgroundColor;
   L_DOUBLE dMinimumQuietMargin;
   L_DOUBLE dMinimumBarcodeDim;
   L_DOUBLE dMaximumBarcodeDim;
   L_INT nMinimumConfidence;
   L_UINT uUnits;
   L_UINT uFlags;
};
typedef struct _tagFIND_BARCODE_CANDIDATE_AREAS_OPTIONS FIND_BARCODE_CANDIDATE_AREAS_OPTIONS;

struct _tagBARCODE_CANDIDATE_AREA
{
   L_UINT uStructSize;
   L_RECT Bounds;
   L_RECT EffectiveBounds;
   L_UINT Type;
   L_DOUBLE Confidence;
};
typedef struct _tagBARCODE_CANDIDATE_AREA BARCODE_CANDIDATE_AREA;

struct _tagBARCODE_CANDIDATE_AREAS
{
   L_UINT uStructSize;
   BARCODE_CANDIDATE_AREA* Areas;
   L_INT AreasCount;
};
typedef struct _tagBARCODE_CANDIDATE_AREAS BARCODE_CANDIDATE_AREAS;

//************************ L_CompareBitmap structures ************************
typedef struct _COMPAREOPTIONS
{
   L_UINT uStructSize;
   L_UINT uThreshold;                  // Maximum distance of color equality (euclidean distance in RGB-space)
   L_COLORREF crReferenceBackground;   // The background color within the reference image (typically white)
   L_COLORREF crReferenceForeground;   // The foreground color within the reference image (typically black)
   L_COLORREF crModifiedBackground;    // The background color within the modified image (typically white)
   L_COLORREF crModifiedForeground;    // The foreground color within the modified image (typically black)
   L_COLORREF crOutputExternal;        // The color used in the final image to indicate pixels which were outside of both images
   L_COLORREF crOutputBackground;      // ^ indicate[s] pixels which were equal to the background in both images
   L_COLORREF crOutputMatch;           // ^ indicate[s] pixels which were equivalent in each image
   L_COLORREF crOutputAddition;        // ^ indicate[s] pixels which were added in the modified image
   L_COLORREF crOutputDeletion;        // ^ indicate[s] pixels which were removed in the modified image
   L_COLORREF crOutputChange;          // ^ indicate[s] pixels which were changed in the modified image, but weren't explicitly added or deleted
}
COMPAREOPTIONS, *pCOMPAREOPTIONS;


#if defined(LEADTOOLS_V21_OR_LATER)
//************************ L_CannyEdgeDetector structures ************************
#define CANNY_MASTER_CHANNEL 0
#define CANNY_RED_CHANNEL    1
#define CANNY_GREEN_CHANNEL  2
#define CANNY_BLUE_CHANNEL   4

typedef struct _tagCANNYOPTIONS
{
   L_UINT16 uRadius;
   L_UINT16 uLowThreshold;
   L_UINT16 uHighThreshold;
   L_UINT8 uChannels;
}
CANNYOPTIONS, *pCANNYOPTIONS;
//************************ L_FindCandidateFormFields structures ************************
#define OMR_FIELD_TYPE_BOX 0
#define OMR_FIELD_TYPE_CIRCLE 1
typedef struct _tagOMRFIELD
{
   L_UINT uStructSize;
   RECT rcFilledBound;
   RECT rcUnfilledBound;
   L_BOOL bIsFilled;
   L_UINT uFilledConfidence;
   L_UINT uOMRConfidence;
   L_UINT uFieldType;
}
OMRFIELD, *pOMRFIELD;

#define TEXT_FIELD_TYPE_LINE 0
#define TEXT_FIELD_TYPE_BOX 1
#define TEXT_FIELD_TYPE_CELL 2
typedef struct _tagTEXTFIELD
{
   L_UINT uStructSize;
   RECT rcBounds;
   RECT rcFilledAreaBounds;
   RECT rcSpaceBounds[2];
   L_BOOL bIsFilled;
   L_UINT uFieldType;
}
TEXTFIELD, *pTEXTFIELD;

typedef struct _tagTEXTFIELDS
{
   L_UINT uStructSize;
   TEXTFIELD* pTextFieldAreas;
   L_UINT uCount;
}
TEXTFIELDS, *pTEXTFIELDS;

typedef struct _tagOMRFIELDS
{
   L_UINT uStructSize;
   OMRFIELD* pOMRFieldAreas;
   L_UINT uCount;
}
OMRFIELDS, *pOMRFIELDS;


typedef struct _tagFIND_CANDIDATE_FORM_FIELDS_OUTPUTS
{
   L_UINT uStructSize;
   TEXTFIELDS TextFields;
   OMRFIELDS OMRFields;
}
FIND_CANDIDATE_FORM_FIELDS_OUTPUTS, *pFIND_CANDIDATE_FORM_FIELDS_OUTPUTS;

typedef struct _tagFIND_CANDIDATE_FORM_FIELDS_OPTIONS
{
   L_UINT uStructSize;
   L_UINT uHorizontalLineMinimumLength;
   L_UINT uVerticalLineMinimumLength;
}
FIND_CANDIDATE_FORM_FIELDS_OPTIONS, *pFIND_CANDIDATE_FORM_FIELDS_OPTIONS;

//************************ L_DetectLinesBitmap structures ************************

#define SOLID_LINE 0
#define DASHED_LINE 1
#define BIG_DASHED_LINE 2
#define DATE_LINE 3
#define BARCODE_LINE 4

typedef struct _CORELINE
{
   L_UINT uStructSize;
   POINT StartPoint;
   POINT EndPoint;
   L_UINT uType;
   RECT rcLine;
   L_HANDLE InternalHandle;
}
CORELINE, *pCORELINE;

typedef struct _CORE_LINES
{
   L_UINT uStructSize;
   CORELINE* pLines;
   L_UINT uCount;
}
CORELINES, *pCORELINES;

typedef struct _tagDETECT_LINES_RESULT
{
   L_UINT uStructSize;
   CORELINES VerticalLines;
   CORELINES HorizontalLines;
   L_HANDLE InternalHandle;
}
DETECT_LINES_RESULT, *pDETECT_LINES_RESULT;


#define REMOVE_LINES 1

typedef struct _tagDETECT_LINES_OPTIONS
{
   L_UINT uStructSize;
   L_UINT uHorizontalLineMinimumLength;
   L_UINT uVerticalLineMinimumLength;
   L_UINT uFlags;
}
DETECT_LINES_OPTIONS, *pDETECT_LINES_OPTIONS;

//************************ L_DetectTablesBitmap structures ************************

typedef struct tagDETECT_TABLES_OPTIONS
{
   L_UINT uStructSize;
   L_UINT uHorizontalLineMinimumLength;
   L_UINT uVerticalLineMinimumLength;
   pDETECT_LINES_RESULT pDetectedLines;
}
DETECT_TABLES_OPTIONS, *pDETECT_TABLES_OPTIONS;

typedef struct _CORECELL
{
   L_UINT uStructSize;
   POINT Vertices[4]; // LeftTop , RightTop, RightBottom, LeftBottom
}
CORECELL, *pCORECELL;

typedef struct _CORETABLE
{
   L_UINT uStructSize;
   CORECELL* pCells;
   L_UINT uCount;
}
CORETABLE, *pCORETABLE;

typedef struct tagDETECT_TABLES_RESULT
{
   L_UINT uStructSize;
   CORETABLE* pTables;
   L_UINT uCount;
}
DETECT_TABLES_RESULT, *pDETECT_TABLES_RESULT;

#endif // #if defined(LEADTOOLS_V21_OR_LATER)

/****************************************************************
   Callback typedefs
****************************************************************/
typedef L_INT(pEXT_CALLBACK BITMAPSLICECALLBACK)(
   pBITMAPHANDLE  pBitmap,
   LPRECT         lpSliceRect,
   L_INT          nAngle,
   L_VOID         *pUserData);

////----------------------------------- callback typedefs --------------------------------------

typedef L_INT(pEXT_CALLBACK SMOOTHCALLBACK)(
   L_UINT   uBumpOrNick,
   L_INT    iStartRow,
   L_INT    iStartCol,
   L_INT    iLength,
   L_UINT   uHorV,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK LINEREMOVECALLBACK)(
   L_HRGN     hRgn,
   L_INT    iStartRow,
   L_INT    iStartCol,
   L_INT    iLength,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK BORDERREMOVECALLBACK)(
   L_HRGN     hRgn,
   L_UINT   uBorderToRemove,
   PRECT    pBoundingRect,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK INVERTEDTEXTCALLBACK)(
   L_HRGN     hRgn,
   PRECT    pBoundingRect,
   L_INT    iWhiteCount,
   L_INT    iBlackCount,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK DOTREMOVECALLBACK)(
   L_HRGN     hRgn,
   PRECT    pBoundingRect,
   L_INT    iWhiteCount,
   L_INT    iBlackCount,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK HOLEPUNCHREMOVECALLBACK)(
   L_HRGN     hRgn,
   PRECT    pBoundingRect,
   L_INT    iHoleIndex,
   L_INT    iHoleTotalCount,
   L_INT    iWhiteCount,
   L_INT    iBlackCount,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK STAPLEREMOVECALLBACK)(
   L_HRGN     hRgn,
   PRECT    pBoundingRect,
   L_UINT   iWhiteCount,
   L_UINT   iBlackCount,
   L_VOID   *pUserData);

typedef L_INT(pEXT_CALLBACK ANALYZEBARCODECALLBACK)
   (pBITMAPHANDLE pBinarizedBitmap,
   const L_RECT* pBarcodeZone,
   L_VOID   *pUserData);

typedef struct _MANUALPERSPECTIVEDESKEWPOINTS
{
    L_UINT uStructSize;
   L_POINT InputPoints[4];
   L_POINT MappingPoints[4];
}MANUALPERSPECTIVEDESKEWPOINTS, *pMANUALPERSPECTIVEDESKEWPOINTS;

typedef struct _PERSPECTIVEDESKEWOPTIONS
{
   L_UINT uStructSize;
   L_UINT uFlags;//Default is 0
   L_POINT ptCorners[4];
   L_BOOL bDonotProcessBitmap;
}
PERSPECTIVEDESKEWOPTIONS, * pPERSPECTIVEDESKEWOPTIONS;

//********************** L_SauvolaBinarize Structure**********************
typedef struct _SAUVOLABINARIZE
{
   L_UINT    uStructSize;
   L_INT     nWSize;
   L_DOUBLE  dKFactor;
   L_INT     nRFactor; //dynamic range of standard deviation
}
SAUVOLABINARIZE, *pSAUVOLABINARIZE;

//--------------L_CreatePreDefinedFilter---------------------
#define CREATE_GAUSSIAN_FILTER             0x00000001
#define CREATE_MOTION_FILTER               0x00000002

typedef struct
{
   L_UINT      uStructSize;
   L_UINT      nHeight;
   L_UINT      nWidth;
   L_DOUBLE*   pValues;
}
POINTSPREADFUNCTION, *pPOINTSPREADFUNCTION;

typedef struct _LETTERBLUREXTENT
{
   L_RECT rc;
   L_DOUBLE dBlurExtent;
}
LETTERBLUREXTENT, *pLETTERBLUREXTENT;

typedef struct _GLAREDETECTIONOPTIONS
{
   L_UINT uStructSize;
   L_BOOL bExpandGlareRegions;//input
   pBITMAPHANDLE pMaskBitmap;//output
   L_INT nZonesCount;//output
   L_RECT* prcZones;//output
}
GLAREDETECTIONOPTIONS, *pGLAREDETECTIONOPTIONS;

typedef struct _REFLECTIONOPTIONS
{
   L_UINT uStructSize;
   pBITMAPHANDLE pReflectionMask;
}
REFLECTIONOPTIONS, *pREFLECTIONOPTIONS;

typedef struct _BLURDETECTIONOPTIONS
{
   L_UINT uStructSize;
   L_RECT rcROI;
   L_FLOAT fResizeFactor;
   L_DOUBLE dGlobalBlurExtent;
   L_DOUBLE dBlurThreshold; // get glare and reflection information as long as the dGlobalBlurExtent is greater than dBlurThreshold.
   L_FLOAT fLettersStretchThreshold;
   L_INT LettersCount;
   LETTERBLUREXTENT* pLettersBlurExtent;
   GLAREDETECTIONOPTIONS GlareOptions;//input / output
   REFLECTIONOPTIONS ReflectionOptions;
   L_BOOL bBypassBlurDetection ;
   L_FLOAT fDeskewAngle;
   L_FLOAT fLettersStretchFactor;//This value measures the stretching amount if the letter is stretched in either H "OR" V direction and not in both directions.
   L_INT nAverageCharsHeight;
}
BLURDETECTIONOPTIONS, *pBLURDETECTIONOPTIONS;

/****************************************************************
   Function prototypes
****************************************************************/
#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_IMGCOR)

L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetAutoTrimRect(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uThreshold,
   RECT           *pRect, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoTrimBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uThreshold, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DeskewBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          *pnAngle,
   COLORREF       crBack,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DeskewBitmapExt(
   pBITMAPHANDLE  pBitmap,
   L_INT          *pnAngle,
   L_UINT         uAngleRange,
   L_UINT         uAngleResolution,
   COLORREF       crBack,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoDocumentBinarization(pBITMAPHANDLE pBitmap);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DespeckleBitmap(
   pBITMAPHANDLE pBitmap, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_MinFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_MaxFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ConvertBitmapSignedToUnsigned(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uShift, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ConvertBitmapUnsignedToSigned(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_HalfToneBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uType,
   L_INT32        nAngle,
   L_UINT         uDim,
   HBITMAPLIST    hList, 
   L_UINT32       uFlags);

// These functions not ported to Windows CE
L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetMinMaxBits(
   pBITMAPHANDLE  pBitmap,
   L_INT          *pLowBit,
   L_INT          *pHighBit, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetMinMaxVal(
   pBITMAPHANDLE  pBitmap,
   L_INT          *pMinVal,
   L_INT          *pMaxVal, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_MedianFilterBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uDim, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_WindowLevelBitmap(
   pBITMAPHANDLE  pBitmap,
   L_INT          nLowBit,
   L_INT          nHighBit,
   RGBQUAD        *pLUT,
   L_UINT         uLUTLength,
   L_INT          nOrderDst, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_WindowLevelBitmapExt
(
   pBITMAPHANDLE pBitmap,
   L_INT nLowBit, 
   L_INT nHighBit,
   L_RGBQUAD16 *pLUT,
   L_UINT uLUTLength,
   L_INT nOrderDst, 
   L_UINT32 uFlags
);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SmoothBitmap(
   pBITMAPHANDLE  pBitmap,
   pSMOOTH        pSmooth,
   SMOOTHCALLBACK pfnCallback,
   L_VOID         *pUserData, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_LineRemoveBitmap(
   pBITMAPHANDLE        pBitmap,
   pLINEREMOVE          pLineRemove,
   LINEREMOVECALLBACK   pfnCallback,
   L_VOID               *pUserData,
   L_UINT32             uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_BorderRemoveBitmap(
   pBITMAPHANDLE        pBitmap,
   pBORDERREMOVE        pBorderRemove,
   BORDERREMOVECALLBACK pfnCallback,
   L_VOID               *pUserData, 
   L_UINT32             uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_InvertedTextBitmap(
   pBITMAPHANDLE        pBitmap,
   pINVERTEDTEXT        pInvertedText,
   INVERTEDTEXTCALLBACK pfnCallback,
   L_VOID               *pUserData, 
   L_UINT32             uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DotRemoveBitmap(
   pBITMAPHANDLE     pBitmap,
   pDOTREMOVE        pDotRemove,
   DOTREMOVECALLBACK pfnCallback,
   L_VOID            *pUserData, 
   L_UINT32           uFlags);


L_LTIMGCOR_API L_INT EXT_FUNCTION L_HolePunchRemoveBitmap(
   pBITMAPHANDLE           pBitmap,
   pHOLEPUNCH              pHolePunch,
   HOLEPUNCHREMOVECALLBACK pfnCallback,
   L_VOID                  *pUserData, 
   L_UINT32                uFlags);


L_LTIMGCOR_API L_INT EXT_FUNCTION L_StapleRemoveBitmap(
   pBITMAPHANDLE        pBitmap,
   pSTAPLE              pStaplePunch,
   STAPLEREMOVECALLBACK pfnCallback,
   L_VOID               *pUserData, 
   L_UINT32             uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FFTBitmap(
   pBITMAPHANDLE  pBitmap,
   pFTARRAY       pFTArray,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FTDisplayBitmap(
   pBITMAPHANDLE  pBitmap,
   pFTARRAY       pFTArray,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DFTBitmap(
   pBITMAPHANDLE  pBitmap,
   pFTARRAY       pFTArray,
   RECT           *prcRange,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FrqFilterBitmap(
   pFTARRAY pFTArray,
   LPRECT   prcRange,
   L_UINT   uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FrqFilterMaskBitmap(
   pBITMAPHANDLE  pMaskBitmap,
   pFTARRAY       pFTArray,
   L_BOOL         bOnOff, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AllocFTArray(
   pBITMAPHANDLE  pBitmap,
   pFTARRAY       *ppFTArray,
   L_UINT         uStructSize, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FreeFTArray(
   pFTARRAY pFTArray, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CorrelationBitmap(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  pCorBitmap,
   POINT          *pPoints,
   L_UINT         uMaxPoints,
   L_UINT         *puNumOfPoints,
   L_UINT         uXStep,
   L_UINT         uYStep,
   L_UINT         uThreshold, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SubtractBackgroundBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uRollingBall,
   L_UINT         uShrinkSize,
   L_UINT         uBrightnessFactor,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ApplyModalityLUT(
   pBITMAPHANDLE        pBitmap,
   L_UINT16             *pLUT,
   pDICOMLUTDESCRIPTOR  pLUTDescriptor,
   L_UINT               uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ApplyLinearModalityLUT(
   pBITMAPHANDLE  pBitmap,
   L_DOUBLE       fIntercept,
   L_DOUBLE       fSlope,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ApplyVOILUT(
   pBITMAPHANDLE        pBitmap,
   L_UINT16             *pLUT,
   pDICOMLUTDESCRIPTOR  pLUTDescriptor,
   L_UINT               uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ApplyLinearVOILUT(
   pBITMAPHANDLE  pBitmap,
   L_DOUBLE       fCenter,
   L_DOUBLE       fWidth,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetLinearVOILUT(
   pBITMAPHANDLE  pBitmap,
   L_DOUBLE       *pCenter,
   L_DOUBLE       *pWidth,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CountLUTColors(
   RGBQUAD  *pLUT,
   L_UINT   ulLLUTLen,
   L_UINT   *pNumberOfEntries,
   L_INT    *pFirstIndex,
   L_UINT   uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CountLUTColorsExt(
   L_RGBQUAD16 *pLUT,
   L_UINT   ulLLUTLen,
   L_UINT   *pNumberOfEntries,
   L_INT    *pFirstIndex,
   L_UINT   uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_MultiScaleEnhancementBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uContrast,
   L_UINT         uEdgeLevels,
   L_UINT         uEdgeCoeff,
   L_UINT         uLatitudeLevels,
   L_UINT         uLatitudeCoeff,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ShiftBitmapData(
   pBITMAPHANDLE  pDstBitmap,
   pBITMAPHANDLE  pSrcBitmap,
   L_UINT         uSrcLowBit,
   L_UINT         uSrcHighBit,
   L_UINT         uDstLowBit,
   L_UINT         uDstBitsPerPixel, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SelectBitmapData(
   pBITMAPHANDLE  pDstBitmap,
   pBITMAPHANDLE  pSrcBitmap,
   COLORREF       crColor,
   L_UINT         uSrcLowBit,
   L_UINT         uSrcHighBit,
   L_UINT         uThreshold,
   L_BOOL         bCombine, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ColorizeGrayBitmap(
   pBITMAPHANDLE  pDstBitmap,
   pBITMAPHANDLE  pSrcBitmap,
   pLTGRAYCOLOR   pGrayColors,
   L_UINT         uCount, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DigitalSubtractBitmap(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  pMaskBitmap,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_IsRegMarkBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uType,
   L_UINT         uMinScale,
   L_UINT         uMaxScale,
   L_UINT         uWidth,
   L_UINT         uHeight, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetMarksCenterMassBitmap(
   pBITMAPHANDLE  pBitmap,
   POINT          *pMarkPoints,
   POINT          *pMarkCMPoints,
   L_UINT         uMarksCount, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SearchRegMarksBitmap(
   pBITMAPHANDLE  pBitmap,
   pSEARCHMARKS   pSearchMarks,
   L_UINT         uMarkCount, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetTransformationParameters(
   pBITMAPHANDLE  pBitmap,
   POINT          *pRefPoints,
   POINT          *pTrnsPoints,
   L_INT          *pnXTranslation,
   L_INT          *pnYTranslation,
   L_INT          *pnAngle,
   L_UINT         *puXScale,
   L_UINT         *puYScale, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ApplyTransformationParameters(
   pBITMAPHANDLE  pBitmap,
   L_INT          nXTranslation,
   L_INT          nYTranslation,
   L_INT          nAngle,
   L_UINT         uXScale,
   L_UINT         uYScale,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_HalfTonePatternBitmap(
   pBITMAPHANDLE  pBitmap,
   L_UINT         uContrast,
   L_UINT         uRipple,
   L_UINT         uAngleContrast,
   L_UINT         uAngleRipple,
   L_INT          nAngleOffset,
   COLORREF       crForGround,
   COLORREF       crBackGround,
   L_UINT         uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CorrelationListBitmap(
   pBITMAPHANDLE  pBitmap,
   HBITMAPLIST    hCorList,
   POINT          *pPoints,
   L_UINT         *puListIndex,
   L_UINT         uMaxPoints,
   L_UINT         *puNumOfPoints,
   L_UINT         uXStep,
   L_UINT         uYStep,
   L_UINT         uThreshold, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SetKaufmannRgnBitmap(
   pBITMAPHANDLE  pBitmap,
   pBITMAPHANDLE  pKaufmannProcBitmap,
   L_INT          nRadius,
   L_INT          nMinInput,
   L_INT          nMaxInput,
   L_INT          nRgnThreshold,
   POINT          ptRgnStart,
   L_BOOL         bRemoveHoles,
   L_SIZE_T      *puPixelsCount,
   L_UINT         uCombineMode, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SliceBitmap(
   pBITMAPHANDLE        pBitmap,
   pSLICEBITMAPOPTIONS  pOptions,
   L_INT                *pnDeskewAngle,
   BITMAPSLICECALLBACK  pfnCallback,
   L_VOID               *pUserData, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ShiftMinimumToZero(
   pBITMAPHANDLE  pBitmap,
   L_UINT         *puShiftAmount, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ShiftZeroToNegative(
   pBITMAPHANDLE  pBitmap,
   L_INT          nShiftAmount,
   L_INT          nMinInput,
   L_INT          nMaxInput,
   L_INT          nMinOutput,
   L_INT          nMaxOutput, 
   L_UINT32       uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SizeBitmapInterpolate(pBITMAPHANDLE pBitmap,
                                                         L_INT         nWidth,
                                                         L_INT         nHeight,
                                                         L_UINT        uFlags);

#if !defined LEADTOOLS_V21_OR_LATER
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BlankPageDetectorBitmap(pBITMAPHANDLE   pBitmap,
   L_BOOL          *bIsBlank,
   L_UINT          *pAccuracy,
   pPAGEMARGINS    pMargins,
   L_UINT          uFlags);
#else
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BlankPageDetectorBitmap(pBITMAPHANDLE pBitmap, pBLANKPAGEDETECTOROPTIONS pOptions, L_UINT uFlags);
#endif

L_LTIMGCOR_API L_INT EXT_FUNCTION L_MICRDetectionEXT(BITMAPHANDLE* pBitmap, pMICRCODEDETECTOROPTIONS pOptions, L_UINT uFlags);


L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoBinarizeBitmap(pBITMAPHANDLE   pBitmap,
                                                        L_UINT          uFactor,
                                                        L_UINT          uFlags);


L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoZoneBitmap(pBITMAPHANDLE       pBitmap,
                                                   pLEADZONE *         phZones,
                                                   L_UINT32 *          puCount,
                                                   L_UINT32            uFlags,
                                                   AUTOZONECALLBACK    pCallback,
                                                   L_VOID *            pUserData);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FreeZoneData(pLEADZONE  hZones, L_INT nCount);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_InvertedPageBitmap(pBITMAPHANDLE   pBitmap,
                                                        L_BOOL *        bIsInverted,
                                                        L_UINT          uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_HighQualityRotateBitmap(pBITMAPHANDLE   pBitmap,
                                                             L_INT           nAngle,
                                                             L_UINT          uFlags,
                                                             L_COLORREF      crFill);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_TissueEqualizeBitmap(pBITMAPHANDLE pBitmap,
                                                         L_UINT uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_RakeRemoveBitmap(pBITMAPHANDLE pBitmap,
                                                     L_BOOL bAuto,
                                                     pRAKEREMOVE pComb,
                                                     RECT* pDstRect,
                                                     L_INT nRectCount,
                                                     RAKEREMOVECALLBACK pCallback,
                                                     L_VOID *pUserData,
                                                     L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_StartFastMagicWandEngine(MAGICWANDHANDLE* pMagicWnd,
                                                             pBITMAPHANDLE LeadBitmap,
                                                             L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_EndFastMagicWandEngine(MAGICWANDHANDLE MagicWnd,
                                                           L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_FastMagicWand(MAGICWANDHANDLE MagicWnd,
                                                  L_INT nTolerance,
                                                  L_INT nXposition,
                                                  L_INT nYposition,
                                                  pOBJECTINFO pObjectInfo,
                                                  L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DeleteObjectInfo(pOBJECTINFO pObjectInfo,
                                                     L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ObjectCounter(pBITMAPHANDLE pBitmap,
                                                  L_UINT *uCount,
                                                  OBJECTCOUNTERCALLBACK pCallback,
                                                  L_VOID *pUserData,
                                                  L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoSegmentBitmap(pBITMAPHANDLE pBitmap,
                                                      L_RECT * pRect,
                                                      L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_SigmaFilterBitmap(pBITMAPHANDLE pBitmap,
                                                      L_UINT nSize,
                                                      L_UINT nSigma,
                                                      L_FLOAT fThreshhold,
                                                      L_BOOL bOutline,
                                                      L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AnisotropicDiffusionBitmap(pBITMAPHANDLE pBitmap,
                                                               L_UINT uIterations,
                                                               L_UINT uSmoothing,
                                                               L_FLOAT fTimeStep,
                                                               L_FLOAT fMinVariation,
                                                               L_FLOAT fMaxVariation,
                                                               L_FLOAT fEdgeHeight,
                                                               L_UINT uUpdate,
                                                               L_UINT32 uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_MeanShiftFilterBitmap(pBITMAPHANDLE pBitmap,
                                                         L_INT nRadius,
                                                         L_UINT nColorDistance,
                                                         L_UINT32 uFlags);

#define BITMAP_COLORTYPE_FAVOR_COLOR            0x00000001
#define BITMAP_COLORTYPE_FAVOR_BLACKANDWHITE    0x00000002
#define BITMAP_COLORTYPE_FAVOR_GRAYSCALE        0x00000004

#define BITMAP_COLORTYPE_BLACKANDWHITE          1
#define BITMAP_COLORTYPE_GRAYSCALE              2
#define BITMAP_COLORTYPE_COLOR                  3

L_LTIMGCOR_API L_INT EXT_FUNCTION L_GetBitmapColorType(pBITMAPHANDLE pBitmap, L_UINT * puType, L_INT * puConfidence, L_UINT uFlag);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoLineRemove(pBITMAPHANDLE pBitmap);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_DocumentSegmentBitmap(pBITMAPHANDLE pBitmap, L_BOOL* AlmostBalckAndWhite, L_UINT Flags);

#if !defined LEADTOOLS_V22_OR_LATER//Use L_MICRDetectionExt instead
L_LTIMGCOR_API L_INT EXT_FUNCTION L_MICRDetection(BITMAPHANDLE* pBitmap, L_RECT Inrc, L_RECT* Outrc, L_UINT Flags);
#endif //LEADTOOLS_V22_OR_LATER

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CLAHE(BITMAPHANDLE*pBitmap0, L_FLOAT Alpha, L_UINT TileSize, L_FLOAT nfclipLimit, L_UINT nBinNumber, L_UINT uFlags);
//L_LTIMGCOR_API L_INT EXT_FUNCTION L_AlignBinarizedImage(BITMAPHANDLE*pFormBitmap, BITMAPHANDLE* pMasterBitmap);

typedef struct _REMOVEBACKGROUNDINFO
{
   L_UINT uStructSize;
   L_UINT uBGRemovaleFactor;
}
REMOVEBACKGROUNDINFO, *pREMOVEBACKGROUNDINFO;

#define KMEANS_RANDOM      0x0001
#define KMEANS_UNIFORM      0x0002
#define KMEANS_USERDEFINED   0x0003

#define SHRINK_RECT   0x0008
#define SHRINK_CIRCLE 0x0010

#define TAD_EXPON_FLUX 0x0001
#define TAD_QUAD_FLUX  0x0002

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExpandPage(pBITMAPHANDLE pBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_AutoPageSplitter(pBITMAPHANDLE pBitmap, pBITMAPHANDLE pOutBitmap, L_UINT* SplittingCoord);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_GlareDetection(pBITMAPHANDLE pBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_SignalToNoiseRatio(pBITMAPHANDLE pBitmap, L_FLOAT* SNR);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ManualPerspectiveDeskew(pBITMAPHANDLE pBitmap, pMANUALPERSPECTIVEDESKEWPOINTS InPoints, pBITMAPHANDLE* ppOutBitmap);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeManualPerspectiveDeskewBitmap(pBITMAPHANDLE pBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_TextBlurDetector(pBITMAPHANDLE pBitmap, L_RECT** pNonBlurredBlocks, L_INT* NonBlurredBlocksCount, L_RECT** pBlurredBlocks, L_INT* BlurredBlocksCount, L_RECT* CombinedTextBlocks);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_TextBlurFree(L_RECT* pNonBlurredBlocks, L_RECT* pBlurredBlocks);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_PerspectiveDeskew(pBITMAPHANDLE pBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_PerspectiveDeskewExt(pBITMAPHANDLE pBitmap, pPERSPECTIVEDESKEWOPTIONS pOptions, L_UINT uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_BrightnessDetection(pBITMAPHANDLE pBitmap, L_FLOAT* fBrightness, L_UINT uFlags);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeBlurDetectionOptions(BLURDETECTIONOPTIONS* pOptions);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_RemoveSaltPepperNoise(pBITMAPHANDLE pBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_AlignImages(BITMAPHANDLE*pRefBitmap, BITMAPHANDLE* pTempBitmap, BITMAPHANDLE* pOutBitmap, L_POINT* RefPoints, L_POINT* TempPoints, L_INT PointsCount, L_UINT nTransformationMethod);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_OtsuThreshold(pBITMAPHANDLE pBitmap, L_INT nClusters);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_LevelsetBitmapRgn(pBITMAPHANDLE pBitmap, L_INT LambdaIn, L_INT LambdaOut);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_LambdaConnectedness(pBITMAPHANDLE pBitmap, L_INT lambdaVal);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_KMeansBitmapSegmentation(pBITMAPHANDLE pBitmap, L_UINT nCluster, L_COLORREF** ppOutCenters, L_INT* nOutCentersCount, L_COLORREF* pInCenters, L_UINT uFlags);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeKmeansOutput(L_COLORREF *pOutCenters);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_GWireInit(pBITMAPHANDLE pBitmap, GWIREHANDLE *pHGWire, L_INT nExternalEnergy);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_GWireSetSeedPoint(GWIREHANDLE hGWire, L_POINT ptSeed);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_GWireGetMinPath(GWIREHANDLE hGWire, L_POINT ptTarget, L_POINT** pOutPath, L_INT* nOutLength);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_DestroyGWireHandle(GWIREHANDLE hGwire);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeGWirePath(L_POINT* pGWirePath);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_Keystone(pBITMAPHANDLE pBitmap, L_POINT* pPoints, pBITMAPHANDLE pOutBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ShrinkWrapTool(pBITMAPHANDLE pBitmap, L_INT nThreshold, POINT ptCenter, L_INT nRadius, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_TADAnisotropicDiffusion(pBITMAPHANDLE pBitmap, L_INT nIterations, L_INT nLambda, L_INT nKappa, L_UINT nFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_SRADAnisotropicDiffusion(pBITMAPHANDLE pBitmap, L_INT nIter, L_INT nLambda, LPRECT pRect);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_WatershedBitmap(pBITMAPHANDLE pBitmap, L_POINT** ppPoints, L_INT* pLengths, L_INT nSize);

#if defined(LEADTOOLS_V21_OR_LATER)
L_LTIMGCOR_API L_INT EXT_FUNCTION  L_UnWarp(pBITMAPHANDLE pInputBitmap, pBITMAPHANDLE pOutputBitmap, L_POINT* pPoints, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_MRZDetection(BITMAPHANDLE* pBitmap, pMRZDETECTION pMRZDetection, L_UINT uFlags);
#else
L_LTIMGCOR_API L_INT EXT_FUNCTION  L_UnWarp(pBITMAPHANDLE pInputBitmap, pBITMAPHANDLE* ppOutputBitmap, L_POINT* pPoints, L_UINT uFlags);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeUnWarpBitmap(pBITMAPHANDLE pBitmap);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_MRZDetection(BITMAPHANDLE* pBitmap, L_RECT Inrc, L_RECT* Outrc);
#endif

L_LTIMGCOR_API L_INT EXT_FUNCTION L_BezierPath(L_POINT* pInPoints, L_POINT** ppOutPoints, L_INT* pOutPointsCount, L_UINT uFlags);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeBezierPath(POINT* pPath);

#if !defined (LEADTOOLS_V21_OR_LATER)
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BlankPageDetectorBitmapExt(pBITMAPHANDLE pBitmap, L_BOOL *bIsBlank, L_UINT *pAccuracy, pPAGEMARGINS PMargins, L_UINT uSensitivity, L_UINT uFlags);
#endif

L_LTIMGCOR_API L_INT EXT_FUNCTION L_RemoveBackground(pBITMAPHANDLE pBitmap, REMOVEBACKGROUNDINFO* RBGInfo, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_DetectBitmapDeskewOrientation(pBITMAPHANDLE pBitmap, pDESKEWDETECTION pDeskewDetection, pORIENTATIONDETECTION pOrientationDetection, L_UINT uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CreatePreDefinedFilter(pPOINTSPREADFUNCTION* pPSF, L_DOUBLE dFirstParameter, L_DOUBLE dSecondParameter, L_UINT uFlags);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreePredefinedFilter(POINTSPREADFUNCTION* pPSF);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BitmapWienerFilter(pBITMAPHANDLE pBitmap, POINTSPREADFUNCTION pPSF, L_DOUBLE dNoiseToSignalRatio, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BitmapAdaptiveWienerFilter(pBITMAPHANDLE pBitmap, L_INT nWindowSize, L_DOUBLE dNoiseVariance, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_SauvolaBinarize(pBITMAPHANDLE pBitmap, pSAUVOLABINARIZE pSauvolaBinarize, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_CreditCardDetection(pBITMAPHANDLE pBitmap, L_RECT* prcROI, L_UINT uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_CompareBitmap(pBITMAPHANDLE pReferenceBitmap, pBITMAPHANDLE pModifiedBitmap, pBITMAPHANDLE pOutputBitmap, L_MATRIX* pAlignment, pCOMPAREOPTIONS pOptions);

L_LTIMGCOR_API L_INT EXT_FUNCTION  L_FindBarcodeCandidateAreas(pBITMAPHANDLE pBitmap, FIND_BARCODE_CANDIDATE_AREAS_OPTIONS* pOptions, BARCODE_CANDIDATE_AREAS*pFoundAreas);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeBarcodeCandidateAreas(BARCODE_CANDIDATE_AREAS* pAreas);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjectsBitmap(pBITMAPHANDLE pBitmap, pEXOBJ_OPTIONS pOptions, pEXOBJ_DATA *pData);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_FreeData(pEXOBJ_DATA *pData);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_AddObject(pEXOBJ_DATA pData, pEXOBJ_OBJECTLIST pTargetList, pEXOBJ_OBJECT pObject, pEXOBJ_OBJECT pObjectNeighbor, L_UINT8 uLocation, pEXOBJ_OBJECT *pReallocated);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_MoveObject(pEXOBJ_DATA pData, pEXOBJ_OBJECTLIST pSourceList, pEXOBJ_OBJECT pObject, pEXOBJ_OBJECTLIST pTargetList, pEXOBJ_OBJECT pObjectNeighbor, L_UINT8 uLocation);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_RemoveObject(pEXOBJ_DATA pData, pEXOBJ_OBJECTLIST pObjectList, pEXOBJ_OBJECT pObject);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_CalcContentBound(pEXOBJ_DATA pData, EXOBJ_CONTENTBOUND *pContentBoundBuffer, L_UINT uContentBoundCount, pEXOBJ_CONTENTBOUND_OPTIONS pOptions);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_ClearInternalCache(pEXOBJ_DATA pData, pEXOBJ_CONTENTBOUND_OPTIONS pOptions);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_CalcRegion(pEXOBJ_DATA pData, pEXOBJ_OBJECT *pObjectBuffer, L_UINT uObjectCount, pEXOBJ_REGION_OPTIONS pOptions);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ExtractObjects_FilterList(pEXOBJ_DATA pData, pEXOBJ_OBJECTLIST pObjectList, pEXOBJ_FILTER_OPTIONS pOptions);

#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_IMGCOR)





#if defined (LEADTOOLS_V21_OR_LATER)
L_LTIMGCOR_API L_INT EXT_FUNCTION L_ICRBinarize(pBITMAPHANDLE pBitmap, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_CannyEdgeDetectorBitmap(pBITMAPHANDLE pBitmap, CANNYOPTIONS* pOptions);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_FindCandidateFormFields(pBITMAPHANDLE pBitmap, FIND_CANDIDATE_FORM_FIELDS_OPTIONS* pOptions,
   FIND_CANDIDATE_FORM_FIELDS_OUTPUTS* pOutputs);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FindCandidateFormsFieldsFree(FIND_CANDIDATE_FORM_FIELDS_OUTPUTS* pOutputs);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_DetectLinesBitmap(pBITMAPHANDLE pBitmap, pDETECT_LINES_OPTIONS pOptions,
   pDETECT_LINES_RESULT pOutputs);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeDetectLinesBitmap(pDETECT_LINES_RESULT pOutputs);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_DetectTablesBitmap(pBITMAPHANDLE pBitmap, pDETECT_TABLES_OPTIONS pOptions,
   pDETECT_TABLES_RESULT pOutputs);
L_LTIMGCOR_API L_VOID EXT_FUNCTION L_FreeDetectTablesBitmap(pDETECT_TABLES_RESULT pOutputs);
#endif // #if defined(LEADTOOLS_V21_OR_LATER)
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BlurDetection(pBITMAPHANDLE pBitmap, L_BOOL* Blurred, L_DOUBLE* pBlurExtent);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_BlurDetectionExt(pBITMAPHANDLE pBitmapOrginal, BLURDETECTIONOPTIONS* pOptions, L_UINT uFlags);

L_LTIMGCOR_API L_INT EXT_FUNCTION L_AverageBinarization(pBITMAPHANDLE pBitmap, L_UINT uFlags);
L_LTIMGCOR_API L_INT EXT_FUNCTION L_IntIsBinarizedBitmap(pBITMAPHANDLE pBitmap, L_BOOL* pIsBinarized, L_UINT uFlags);

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTIMGCOR_H)
