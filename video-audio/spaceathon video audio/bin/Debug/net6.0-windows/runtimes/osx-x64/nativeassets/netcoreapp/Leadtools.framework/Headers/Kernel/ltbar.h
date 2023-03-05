//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTBAR_H)
#define LTBAR_H

#include "lttyp.h"
#define L_LTBAR_API LT_EXPORTED

#include "lterr.h"

#define L_HEADER_ENTRY
#include "ltpck.h"


/****************************************************************
   Enums/defines/macros
****************************************************************/
/* Barcode Status */
#define BARCODE_NORMAL                    1
#define BARCODE_ERRORCHECK                2

/* Barcode Colors Flags */
#define BARCODE_USECOLORS                 0x0200   /* for R/W */
#define BARCODE_TRANSPARENT               0x0400   /* for W only */

#define BARCODE_DM_FORCE_INVERT           0x00000800   /* for DM/R */
#define BARCODE_DM_FASTFIND_DISABLE       0x00001000   /* for DM/R */

#define BARCODE_RETURN_FOUR_POINTS        0x00002000   /* for R only */

#define BARCODE_HRItoGS1                  0x00004000   /* Format HRI text as GS1 */
#define BARCODE_GS1toHRI                  0x00004001   /* Format GS1 text as HRI */

#define BARCODE_DOUBLE_PASS               0x04000000   /*double pass flag for read only*/
#define BARCODE_DOUBLE_PASS_IF_SUCCESS    0x04100000   /*double pass flag, even if the read process succeeded for read only*/
#define BARCODE_APPLY_PREPROCESSING       0x04200000   /*apply preprocessing flag*/
#define BARCODE_TRY_DISTORTED             0x04400000
#define BARCODE_IMAGETYPE_PICTURE         0x08000000  /* the image is a picture, not a scanned document */
 
/* Linear Barcode Flags */
#define BARCODE_JUSTIFYRIGHT              0x0010   /* For W only */
#define BARCODE_JUSTIFYHCENTER            0x0020   /* For W only */
#define BARCODE_RETURNCHECK               0x1000   /* for R only */
#define BARCODE_DONOTRETURNCHECK          0x4000   /* for R only */
#define BARCODE_CALCULATEBWR              0x8000   /* for R only. Calculate the bar width reduction value*/

/* Barcode Read/Write Flags for 1D */
#define BARCODE_MARKERS                   0x0001
#define BARCODE_BLOCK_SEARCH              0x0002
#define BARCODE_RRESIZESMALL1D            0x0004

/* Barcode Write Flags for 1D */
#define BARCODE_1D_USE_XMOD               0x0100

/* Barcode Write Flags for CodeOne and PDF417 */
#define BARCODE_TRUNCATE                  0x0010
#define BARCODE_MSGAPPEND                 0x0020
#define BARCODE_INITREADER                0x0040
#define BARCODE_COLROWASLIMITS            0x0080
#if defined(LEADTOOLS_V21_OR_LATER)
#define BARCODE_DISABLE_COMPRESSION       0x0100
#else
#define BARCODE_DISABLE_COMPRESSOPN       0x0100
#endif
#define BARCODE_MICRO_PDF417_MODE128      0x1000
#define BARCODE_MICRO_PDF417_LINKED       0x2000

/* Units of measurement in an image */
#define BARCODE_SCANLINES_PER_PIXELS      0  /* Use scanlines/pixels */
#define BARCODE_INCHES                    1  /* Use Inches, you must multiply one inch by 100 */
#define BARCODE_MILLIMETERS               2  /* Use Millimeters */

/* Barcode Direction, used for Read 1D and PDF417 */
#define BARCODE_DIR_LEFT_TO_RIGHT         0x001
#define BARCODE_DIR_RIGHT_TO_LEFT         0x002
#define BARCODE_DIR_TOP_TO_BOTTOM         0x004
#define BARCODE_DIR_BOTTOM_TO_TOP         0x008

#define BARCODE_DIR_SKEW                  0x010
#define BARCODE_DIR_HORIZONTAL            0x020
#define BARCODE_DIR_VERTICAL              0x040
#define BARCODE_DIR_DIAGONAL              0x080

/* Barcode Justification for Write CodeOne and PDF417 */
#define BARCODE_JUSTIFY_RIGHT             0x1000
#define BARCODE_JUSTIFY_H_CENTER          0x2000
#define BARCODE_JUSTIFY_BOTTOM            0x4000
#define BARCODE_JUSTIFY_V_CENTER          0x8000

/* PDF417 ECC LEVEL Constants */
#define BARCODE_PDF417_ECCLEVEL_0         0x0001
#define BARCODE_PDF417_ECCLEVEL_1         0x0002
#define BARCODE_PDF417_ECCLEVEL_2         0x0004
#define BARCODE_PDF417_ECCLEVEL_3         0x0008
#define BARCODE_PDF417_ECCLEVEL_4         0x0010
#define BARCODE_PDF417_ECCLEVEL_5         0x0020
#define BARCODE_PDF417_ECCLEVEL_6         0x0040
#define BARCODE_PDF417_ECCLEVEL_7         0x0080
#define BARCODE_PDF417_ECCLEVEL_8         0x0100
#define BARCODE_PDF417_ECCUSE_PERCENT     0x0FFF

/* PDF Read Flags */
#define BARCODE_RETURNCORRUPT                0x080 /* R / PDF417 */

#define BARCODE_PDF_READ_MODE_0              0x0000
#define BARCODE_PDF_READ_MODE_1              0x1000
#define BARCODE_PDF_READ_MODE_2              0x4000
#define BARCODE_PDF_READ_MODE_3_BASIC        0x5000
#define BARCODE_PDF_READ_MODE_3_EXTENDED     0x8000
#define BARCODE_MICRO_PDF_READ_BASIC         0x9000
#define BARCODE_MICRO_PDF_READ_EXTENDED      0xC000

#define BARCODE_PDF_READ_MACRO_OPTION_0      0x00010000
#define BARCODE_PDF_READ_MACRO_OPTION_1      0x00020000
#define BARCODE_PDF_READ_MACRO_OPTION_2      0x00040000
#define BARCODE_PDF_READ_MACRO_OPTION_3      0x00080000
#define BARCODE_PDF_READ_MACRO_OPTION_4      0x00100000
#define BARCODE_PDF_READ_MACRO_OPTION_5      0x00200000
#define BARCODE_PDF_READ_MACRO_OPTION_6      0x00400000
#define BARCODE_PDF_READ_MACRO_OPTION_79AZ   0x00800000

#define BARCODE_PDF_READ_RETURN_PARTIAL      0x01000000 /* R / PDF417 */
#define BARCODE_PDF_FASTREAD                 0x02000000
#define BARCODE_PDF_NO_INDICATORS_TRIAL      0x10000000
#define BARCODE_MICRO_PDF_READ_CCA3COLS      0x20000000

/* Barcode (1D) Read/Write Types */
#define BARCODE_1D_EAN_13                 0x80000001
#define BARCODE_1D_EAN_8                  0x80000002
#define BARCODE_1D_UPC_A                  0x80000004
#define BARCODE_1D_UPC_E                  0x80000008
#define BARCODE_1D_CODE_3_OF_9            0x80000010
#define BARCODE_1D_CODE_3_OF_9_EXTENDED   0x80040000
#define BARCODE_1D_CODE_128               0x80000020
#define BARCODE_1D_CODE_I2_OF_5           0x80000040
#define BARCODE_1D_CODA_BAR               0x80000080
#define BARCODE_1D_UCCEAN_128             0x80000100
#define BARCODE_1D_CODE_93                0x80000200
#define BARCODE_1D_CODE_93_EXTENDED       0x80000201
#define BARCODE_1D_EANEXT_5               0x80000400
#define BARCODE_1D_EANEXT_2               0x80000800
#define BARCODE_1D_MSI                    0x80001000
#define BARCODE_1D_CODE11                 0x80002000
#define BARCODE_1D_CODE_S25               0x80004000
#define BARCODE_1D_RSS14                  0x80008000
#define BARCODE_1D_RSS14_LIMITED          0x80010000
#define BARCODE_1D_RSS14_EXPANDED         0x80020000
#define BARCODE_1D_PATCH_CODE             0x04000001
#define BARCODE_1D_POST_NET               0x04000002
#define BARCODE_1D_PLANET                 0x04000004
#define BARCODE_1D_AUST_POST              0x04000008
#define BARCODE_1D_RM4SCC                 0x04000010
#define BARCODE_1D_RSS14_STACKED          0x04000020
#define BARCODE_1D_RSS14_EXP_STACKED      0x04000040
#define BARCODE_1D_USPS4BC                0x04000080
#define BARCODE_1D_PHARMA_CODE            0x04000100

/* The following define used only for read any bar code (1D) type in the image */
#define BARCODE_1D_READ_ANYTYPE           0x8003FFFF
#define BARCODE_1D_READ_ANYTYPE_NO_RSS14  0x80007FFF

/*the following defines used to determine the MSI type for read and write*/
#define BARCODE_1D_TYPE_MSI_MOD10         0x00000000
#define BARCODE_1D_TYPE_MSI_2MOD10        0x00000001
#define BARCODE_1D_TYPE_MSI_MOD11         0x00000002
#define BARCODE_1D_TYPE_MSI_MOD11MOD10    0x00000003

/*the following defines used to determine the CODE11 type for read and write*/
#define BARCODE_1D_TYPE_CODE11_C          0x00000000
#define BARCODE_1D_TYPE_CODE11_K          0x00000010

/*the following defines used to determine the speed of barcode read engine*/
#define BARCODE_1D_FAST            0x00000000
#define BARCODE_1D_NORMAL          0x00000100

/*the following define used to set the linkage flag value to 1 for all RSS14 types write*/
#define BARCODE_1D_TYPE_RSS14_LINKAGE     0x00000001

/*the following define used to determine the type of RSS14 stacked write*/
#define BARCODE_1D_TYPE_RSS14_OMNI        0x00000002

/*the following defines used to determine the number of rows for RSS14 expanded stacked write*/
#define BARCODE_1D_TYPE_RSS14_EXP_1       0x00000004
#define BARCODE_1D_TYPE_RSS14_EXP_2       0x00000008
#define BARCODE_1D_TYPE_RSS14_EXP_3       0x0000000C
#define BARCODE_1D_TYPE_RSS14_EXP_4       0x00000010
#define BARCODE_1D_TYPE_RSS14_EXP_5       0x00000014
#define BARCODE_1D_TYPE_RSS14_EXP_6       0x00000018

/*the following defines used to determine the Australian Post type*/
#define BARCODE_AUS4STATE_CIF_C           0x00000000
#define BARCODE_AUS4STATE_CIF_N           0x00000040
#define BARCODE_AUS4STATE_CIF_S           0x00000080

/*the following define used to write the truncated version of RSS14*/
#define BARCODE_1D_TYPE_RSS14_TRUNCATED   0x00000100

/* Barcode Write Flags for Code128*/
#define BARCODE_1D_CODE128_ENCODE_AUTO    0x00000000
#define BARCODE_1D_CODE128_ENCODE_A       0x00000200
#define BARCODE_1D_CODE128_ENCODE_B       0x00000400
#define BARCODE_1D_CODE128_ENCODE_C       0x00000600

//Barcode 1d text position
#define BARCODE_1D_TEXT_BOTTOM            0x00000000
#define BARCODE_1D_TEXT_TOP               0x00000800

/* Barcode CodeOne Read Types */
#define BARCODE_R_CODEONE_A_TO_H          0x40000200
#define BARCODE_R_CODEONE_T               0x40000400
#define BARCODE_R_CODEONE_S               0x40000800
#define BARCODE_R_CODEONE_ANYTYPE         0x40001000

/* Barcode PDF417 Read/Write Type */
#define BARCODE_PDF417                    0x20002000
/* Barcode MicroPDF417 Read/Write Type */
#define BARCODE_MICRO_PDF417              0x20000001

/* Code One Write/Return Read Type Sub Types */
#define BARCODE_CODEONE_DEF               0x40000001
#define BARCODE_CODEONE_TDEF              0x40000002
#define BARCODE_CODEONE_SDEF              0x40000004
#define BARCODE_CODEONE_A                 0x40000008
#define BARCODE_CODEONE_B                 0x40000010
#define BARCODE_CODEONE_C                 0x40000020
#define BARCODE_CODEONE_D                 0x40000040
#define BARCODE_CODEONE_E                 0x40000080
#define BARCODE_CODEONE_F                 0x40000100
#define BARCODE_CODEONE_G                 0x40000200
#define BARCODE_CODEONE_H                 0x40000400
#define BARCODE_CODEONE_T16               0x40000800
#define BARCODE_CODEONE_T32               0x40001000
#define BARCODE_CODEONE_T48               0x40002000
#define BARCODE_CODEONE_S10               0x40004000
#define BARCODE_CODEONE_S20               0x40008000
#define BARCODE_CODEONE_S30               0x40010000

/* Barcodes Major Types */
#define BARCODES_1D                       0x0001
#define BARCODES_2D_READ                  0x0002
#define BARCODES_2D_WRITE                 0x0004
#define BARCODES_PDF_READ                 0x0008
#define BARCODES_PDF_WRITE                0x0010
#define BARCODES_DATAMATRIX_READ          0x0020
#define BARCODES_DATAMATRIX_WRITE         0x0040
#define BARCODES_QR_READ                  0x0080
#define BARCODES_QR_WRITE                 0x0100
#define BARCODES_MICRO_PDF_READ           0x1000
#define BARCODES_MICRO_PDF_WRITE          0x2000

/* DataMatrix Write / Return Read Type Sub Types */
#define BARCODE_DM_DEF                    0x10000101 /* Use Default DataMatrix Size */
#define BARCODE_DM_10x10                  0x10000102
#define BARCODE_DM_12x12                  0x10000103
#define BARCODE_DM_14x14                  0x10000104
#define BARCODE_DM_16x16                  0x10000105
#define BARCODE_DM_18x18                  0x10000106
#define BARCODE_DM_20x20                  0x10000107
#define BARCODE_DM_22x22                  0x10000108
#define BARCODE_DM_24x24                  0x10000109
#define BARCODE_DM_26x26                  0x1000010A
#define BARCODE_DM_32x32                  0x1000010B
#define BARCODE_DM_36x36                  0x1000010C
#define BARCODE_DM_40x40                  0x1000010D
#define BARCODE_DM_44x44                  0x1000010E
#define BARCODE_DM_48x48                  0x1000010F
#define BARCODE_DM_52x52                  0x10000110
#define BARCODE_DM_64x64                  0x10000111
#define BARCODE_DM_72x72                  0x10000112
#define BARCODE_DM_80x80                  0x10000113
#define BARCODE_DM_88x88                  0x10000114
#define BARCODE_DM_96x96                  0x10000115
#define BARCODE_DM_104x104                0x10000116
#define BARCODE_DM_120x120                0x10000117
#define BARCODE_DM_132x132                0x10000118
#define BARCODE_DM_144x144                0x10000119
#define BARCODE_DM_8x18                   0x1000011A
#define BARCODE_DM_8x32                   0x1000011B
#define BARCODE_DM_12x26                  0x1000011C
#define BARCODE_DM_12x36                  0x1000011D
#define BARCODE_DM_16x36                  0x1000011E
#define BARCODE_DM_16x48                  0x1000011F
#define BARCODE_DM_WRITE_RECTANGLE        0x10000180 /* Write Rectangular Default Symbol */

/* DataMatrix Read General Types */
#define BARCODE_DM_READ_SQUARE            0x10000001
#define BARCODE_DM_READ_RECTANGLE         0x10000002
#define BARCODE_DM_READ_SMALL             0x10000004

/* QR Write / Return Read Sub Types */
#define BARCODE_QR_DEF                    0x08000300
#define BARCODE_QR_M2_1                   0x08000301
#define BARCODE_QR_M2_2                   0x08000302
#define BARCODE_QR_M2_3                   0x08000303
#define BARCODE_QR_M2_4                   0x08000304
#define BARCODE_QR_M2_5                   0x08000305
#define BARCODE_QR_M2_6                   0x08000306
#define BARCODE_QR_M2_7                   0x08000307
#define BARCODE_QR_M2_8                   0x08000308
#define BARCODE_QR_M2_9                   0x08000309
#define BARCODE_QR_M2_10                  0x0800030A
#define BARCODE_QR_M2_11                  0x0800030B
#define BARCODE_QR_M2_12                  0x0800030C
#define BARCODE_QR_M2_13                  0x0800030D
#define BARCODE_QR_M2_14                  0x0800030E
#define BARCODE_QR_M2_15                  0x0800030F
#define BARCODE_QR_M2_16                  0x08000310
#define BARCODE_QR_M2_17                  0x08000311
#define BARCODE_QR_M2_18                  0x08000312
#define BARCODE_QR_M2_19                  0x08000313
#define BARCODE_QR_M2_20                  0x08000314
#define BARCODE_QR_M2_21                  0x08000315
#define BARCODE_QR_M2_22                  0x08000316
#define BARCODE_QR_M2_23                  0x08000317
#define BARCODE_QR_M2_24                  0x08000318
#define BARCODE_QR_M2_25                  0x08000319
#define BARCODE_QR_M2_26                  0x0800031A
#define BARCODE_QR_M2_27                  0x0800031B
#define BARCODE_QR_M2_28                  0x0800031C
#define BARCODE_QR_M2_29                  0x0800031D
#define BARCODE_QR_M2_30                  0x0800031E
#define BARCODE_QR_M2_31                  0x0800031F
#define BARCODE_QR_M2_32                  0x08000320
#define BARCODE_QR_M2_33                  0x08000321
#define BARCODE_QR_M2_34                  0x08000322
#define BARCODE_QR_M2_35                  0x08000323
#define BARCODE_QR_M2_36                  0x08000324
#define BARCODE_QR_M2_37                  0x08000325
#define BARCODE_QR_M2_38                  0x08000326
#define BARCODE_QR_M2_39                  0x08000327
#define BARCODE_QR_M2_40                  0x08000328
#define BARCODE_QR_M1_1                   0x08000329
#define BARCODE_QR_M1_2                   0x0800032A
#define BARCODE_QR_M1_3                   0x0800032B
#define BARCODE_QR_M1_4                   0x0800032C
#define BARCODE_QR_M1_5                   0x0800032D
#define BARCODE_QR_M1_6                   0x0800032E
#define BARCODE_QR_M1_7                   0x0800032F
#define BARCODE_QR_M1_8                   0x08000330
#define BARCODE_QR_M1_9                   0x08000331
#define BARCODE_QR_M1_10                  0x08000332
#define BARCODE_QR_M1_11                  0x08000333
#define BARCODE_QR_M1_12                  0x08000334
#define BARCODE_QR_M1_13                  0x08000335
#define BARCODE_QR_M1_14                  0x08000336
#define BARCODE_QR_M1_DEF                 0x08000337
                                          
/* QR Read Type */
#define BARCODE_QR_CODE                   0x08000001

/* QR ECC LEVEL Constants */
#define BARCODE_QR_ECC_L                  0
#define BARCODE_QR_ECC_M                  1
#define BARCODE_QR_ECC_Q                  2
#define BARCODE_QR_ECC_H                  3

/* Aztec Write */ 
#define BARCODE_AZTEC_CODE                0x21000000
#define BARCODE_AZTEC_CODE_Compact1       0x21000001
#define BARCODE_AZTEC_CODE_Compact2       0x21000002
#define BARCODE_AZTEC_CODE_Compact3       0x21000003
#define BARCODE_AZTEC_CODE_Compact4       0x21000004
#define BARCODE_AZTEC_CODE_Full1          0x21000101
#define BARCODE_AZTEC_CODE_Full2          0x21000102
#define BARCODE_AZTEC_CODE_Full3          0x21000103
#define BARCODE_AZTEC_CODE_Full4          0x21000104
#define BARCODE_AZTEC_CODE_Full5          0x21000105
#define BARCODE_AZTEC_CODE_Full6          0x21000106
#define BARCODE_AZTEC_CODE_Full7          0x21000107
#define BARCODE_AZTEC_CODE_Full8          0x21000108
#define BARCODE_AZTEC_CODE_Full9          0x21000109
#define BARCODE_AZTEC_CODE_Full10         0x21000110
#define BARCODE_AZTEC_CODE_Full11         0x21000111
#define BARCODE_AZTEC_CODE_Full12         0x21000112
#define BARCODE_AZTEC_CODE_Full13         0x21000113
#define BARCODE_AZTEC_CODE_Full14         0x21000114
#define BARCODE_AZTEC_CODE_Full15         0x21000115
#define BARCODE_AZTEC_CODE_Full16         0x21000116
#define BARCODE_AZTEC_CODE_Full17         0x21000117
#define BARCODE_AZTEC_CODE_Full18         0x21000118
#define BARCODE_AZTEC_CODE_Full19         0x21000119
#define BARCODE_AZTEC_CODE_Full20         0x21000120
#define BARCODE_AZTEC_CODE_Full21         0x21000121
#define BARCODE_AZTEC_CODE_Full22         0x21000122
#define BARCODE_AZTEC_CODE_Full23         0x21000123
#define BARCODE_AZTEC_CODE_Full24         0x21000124
#define BARCODE_AZTEC_CODE_Full25         0x21000125
#define BARCODE_AZTEC_CODE_Full26         0x21000126
#define BARCODE_AZTEC_CODE_Full27         0x21000127
#define BARCODE_AZTEC_CODE_Full28         0x21000128
#define BARCODE_AZTEC_CODE_Full29         0x21000129
#define BARCODE_AZTEC_CODE_Full30         0x21000130
#define BARCODE_AZTEC_CODE_Full31         0x21000131
#define BARCODE_AZTEC_CODE_Full32         0x21000132

/* Maxi Write */ 
#define BARCODE_MAXI_CODE                 0x22000000
#define BARCODE_MAXI_CODE_MODE_2          0x22000002
#define BARCODE_MAXI_CODE_MODE_3          0x22000003
#define BARCODE_MAXI_CODE_MODE_4          0x22000004
#define BARCODE_MAXI_CODE_MODE_5          0x22000005

/* MicroQR Write */ 
#define BARCODE_MICRO_QR_CODE             0x24000000
#define BARCODE_MICRO_QR_CODE_M1          0x24000001
#define BARCODE_MICRO_QR_CODE_M2_L        0x24000002
#define BARCODE_MICRO_QR_CODE_M2_M        0x24000003
#define BARCODE_MICRO_QR_CODE_M3_L        0x24000004
#define BARCODE_MICRO_QR_CODE_M3_M        0x24000005
#define BARCODE_MICRO_QR_CODE_M4_L        0x24000006
#define BARCODE_MICRO_QR_CODE_M4_M        0x24000007
#define BARCODE_MICRO_QR_CODE_M4_Q        0x24000008

/* Number of Jurisdictions */
#define AAMVA_JURISDICTIONS_COUNT           72

/* Number of defined data elements */
#define AAMVA_DEFINED_DATA_ELEMENTS_COUNT   83

/* Number of defined eye colors */
#define AAMVA_EYE_COLORS_COUNT 11

/* Number of defined hair colors */
#define AAMVA_HAIR_COLORS_COUNT 10

/* Number of defined races/ethnicities */
#define AAMVA_RACE_ETHNICITY_COUNT 7

/* Number of defined names suffixes */
#define AAMVA_NAME_SUFFIX_COUNT 13

typedef enum {
   L_AAMVA_VERSION_PRE_2000 =                    1 << 0,
   L_AAMVA_VERSION_2000     =                    1 << 1,
   L_AAMVA_VERSION_2003     =                    1 << 2,
   L_AAMVA_VERSION_2005     =                    1 << 3,
   L_AAMVA_VERSION_2009     =                    1 << 4,
   L_AAMVA_VERSION_2010     =                    1 << 5,
   L_AAMVA_VERSION_2011     =                    1 << 6,
   L_AAMVA_VERSION_2012     =                    1 << 7,
   L_AAMVA_VERSION_2013     =                    1 << 8,
   L_AAMVA_VERSION_2016     =                    1 << 9
} L_AAMVA_VERSION;


typedef enum {
   L_AAMVA_SUBFILE_TYPE_JURISDICTION_SPECIFIC =       0,
   L_AAMVA_SUBFILE_TYPE_DL                    =  1 << 0,
   L_AAMVA_SUBFILE_TYPE_ID                    =  1 << 1
} L_AAMVA_SUBFILE_TYPE;


typedef enum {
   L_AAMVA_VALID_CHARACTERS_ALPHA   =            1 << 0,
   L_AAMVA_VALID_CHARACTERS_NUMERIC =            1 << 1,
   L_AAMVA_VALID_CHARACTERS_SPECIAL =            1 << 2
} L_AAMVA_VALID_CHARACTERS;

typedef enum {
   L_AAMVA_LENGTH_TYPE_VARIABLE,
   L_AAMVA_LENGTH_TYPE_FIXED
} L_AAMVA_LENGTH_TYPE;

typedef enum {
   L_AAMVA_JURISDICTION_UNKNOWN,
   L_AAMVA_JURISDICTION_ALABAMA,
   L_AAMVA_JURISDICTION_ALASKA,
   L_AAMVA_JURISDICTION_AMERICAN_SAMOA,
   L_AAMVA_JURISDICTION_ARIZONA,
   L_AAMVA_JURISDICTION_ARKANSAS,
   L_AAMVA_JURISDICTION_BRITISH_COLUMBIA,
   L_AAMVA_JURISDICTION_CALIFORNIA,
   L_AAMVA_JURISDICTION_COAHUILA,
   L_AAMVA_JURISDICTION_COLORADO,
   L_AAMVA_JURISDICTION_CONNECTICUT,
   L_AAMVA_JURISDICTION_DISTRICT_OF_COLUMBIA,
   L_AAMVA_JURISDICTION_DELAWARE,
   L_AAMVA_JURISDICTION_FLORIDA,
   L_AAMVA_JURISDICTION_GEORGIA,
   L_AAMVA_JURISDICTION_GUAM,
   L_AAMVA_JURISDICTION_HAWAII,
   L_AAMVA_JURISDICTION_HIDALGO,
   L_AAMVA_JURISDICTION_IDAHO,
   L_AAMVA_JURISDICTION_ILLINOIS,
   L_AAMVA_JURISDICTION_INDIANA,
   L_AAMVA_JURISDICTION_IOWA,
   L_AAMVA_JURISDICTION_KANSAS,
   L_AAMVA_JURISDICTION_KENTUCKY,
   L_AAMVA_JURISDICTION_LOUISIANA,
   L_AAMVA_JURISDICTION_MAINE,
   L_AAMVA_JURISDICTION_MANITOBA,
   L_AAMVA_JURISDICTION_MARYLAND,
   L_AAMVA_JURISDICTION_MASSACHUSETTS,
   L_AAMVA_JURISDICTION_MICHIGAN,
   L_AAMVA_JURISDICTION_MINNESOTA,
   L_AAMVA_JURISDICTION_MISSISSIPPI,
   L_AAMVA_JURISDICTION_MISSOURI,
   L_AAMVA_JURISDICTION_MONTANA,
   L_AAMVA_JURISDICTION_NEBRASKA,
   L_AAMVA_JURISDICTION_NEVADA,
   L_AAMVA_JURISDICTION_NEW_BRUNSWICK,
   L_AAMVA_JURISDICTION_NEW_HAMPSHIRE,
   L_AAMVA_JURISDICTION_NEW_JERSEY,
   L_AAMVA_JURISDICTION_NEW_MEXICO,
   L_AAMVA_JURISDICTION_NEW_YORK,
   L_AAMVA_JURISDICTION_NEWFOUNDLAND,
   L_AAMVA_JURISDICTION_NORTH_CAROLINA,
   L_AAMVA_JURISDICTION_NORTH_DAKOTA,
   L_AAMVA_JURISDICTION_NOVA_SCOTIA,
   L_AAMVA_JURISDICTION_OHIO,
   L_AAMVA_JURISDICTION_OKLAHOMA,
   L_AAMVA_JURISDICTION_ONTARIO,
   L_AAMVA_JURISDICTION_OREGON,
   L_AAMVA_JURISDICTION_PENNSYLVANIA,
   L_AAMVA_JURISDICTION_PRINCE_EDWARD_ISLAND,
   L_AAMVA_JURISDICTION_QUEBEC,
   L_AAMVA_JURISDICTION_RHODE_ISLAND,
   L_AAMVA_JURISDICTION_SASKATCHEWAN,
   L_AAMVA_JURISDICTION_SOUTH_CAROLINA,
   L_AAMVA_JURISDICTION_SOUTH_DAKOTA,
   L_AAMVA_JURISDICTION_TENNESSEE,
   L_AAMVA_JURISDICTION_STATE_DEPT_USA,
   L_AAMVA_JURISDICTION_TEXAS,
   L_AAMVA_JURISDICTION_US_VIRGIN_ISLANDS,
   L_AAMVA_JURISDICTION_UTAH,
   L_AAMVA_JURISDICTION_VERMONT,
   L_AAMVA_JURISDICTION_VIRGINIA,
   L_AAMVA_JURISDICTION_WASHINGTON,
   L_AAMVA_JURISDICTION_WEST_VIRGINIA,
   L_AAMVA_JURISDICTION_WISCONSIN,
   L_AAMVA_JURISDICTION_WYOMING,
   L_AAMVA_JURISDICTION_YUKON,
   L_AAMVA_JURISDICTION_ALBERTA,
   L_AAMVA_JURISDICTION_NORTHERN_MARIANA_ISLANDS,
   L_AAMVA_JURISDICTION_NUNAVUT,
   L_AAMVA_JURISDICTION_PUERTO_RICO
} L_AAMVA_JURISDICTION;

typedef enum {
   L_AAMVA_REGION_UNKNOWN,
   L_AAMVA_REGION_CANADA,
   L_AAMVA_REGION_UNITED_STATES,
   L_AAMVA_REGION_MEXICO
} L_AAMVA_REGION;

typedef enum {
   L_AAMVA_EYE_COLOR_UNKNOWN,
   L_AAMVA_EYE_COLOR_BLACK,
   L_AAMVA_EYE_COLOR_BLUE,
   L_AAMVA_EYE_COLOR_BROWN,
   L_AAMVA_EYE_COLOR_DICHROMATIC,
   L_AAMVA_EYE_COLOR_GRAY,
   L_AAMVA_EYE_COLOR_GREEN,
   L_AAMVA_EYE_COLOR_HAZEL,
   L_AAMVA_EYE_COLOR_MAROON,
   L_AAMVA_EYE_COLOR_PINK
} L_AAMVA_EYE_COLOR;

typedef enum {
   L_AAMVA_HAIR_COLOR_UNKNOWN,
   L_AAMVA_HAIR_COLOR_BALD,
   L_AAMVA_HAIR_COLOR_BLACK,
   L_AAMVA_HAIR_COLOR_BLONDE,
   L_AAMVA_HAIR_COLOR_BROWN,
   L_AAMVA_HAIR_COLOR_GRAY,
   L_AAMVA_HAIR_COLOR_RED,
   L_AAMVA_HAIR_COLOR_SANDY,
   L_AAMVA_HAIR_COLOR_WHITE
} L_AAMVA_HAIR_COLOR;

typedef enum {
   L_AAMVA_SEX_UNKNOWN = 9,
   L_AAMVA_SEX_MALE = 1,
   L_AAMVA_SEX_FEMALE = 2
} L_AAMVA_SEX;

typedef enum {
   L_AAMVA_RACE_ETHNICITY_UNKNOWN,
   L_AAMVA_RACE_ETHNICITY_ALASKAN_OR_AMERICAN_INDIAN,
   L_AAMVA_RACE_ETHNICITY_ASIAN_OR_PACIFIC_ISLANDER,
   L_AAMVA_RACE_ETHNICITY_BLACK,
   L_AAMVA_RACE_ETHNICITY_HISPANIC_ORIGIN,
   L_AAMVA_RACE_ETHNICITY_NON_HISPANIC,
   L_AAMVA_RACE_ETHNICITY_WHITE
} L_AAMVA_RACE_ETHNICITY;

typedef enum {
   L_AAMVA_NAME_SUFFIX_UNKNOWN,
   L_AAMVA_NAME_SUFFIX_ESQUIRE,
   L_AAMVA_NAME_SUFFIX_JUNIOR,
   L_AAMVA_NAME_SUFFIX_SENIOR,
   L_AAMVA_NAME_SUFFIX_FIRST,
   L_AAMVA_NAME_SUFFIX_SECOND,
   L_AAMVA_NAME_SUFFIX_THIRD,
   L_AAMVA_NAME_SUFFIX_FOURTH,
   L_AAMVA_NAME_SUFFIX_FIFTH,
   L_AAMVA_NAME_SUFFIX_SIXTH,
   L_AAMVA_NAME_SUFFIX_SEVENTH,
   L_AAMVA_NAME_SUFFIX_EIGHTH,
   L_AAMVA_NAME_SUFFIX_NINTH
} L_AAMVA_NAME_SUFFIX;

/****************************************************************
   Classes/structures
****************************************************************/

typedef struct _tagBarCodeData
{
   L_UINT            uStructSize;
   L_INT             nGroup;              // used only for CodeOne and PDF417
   L_UINT32          ulType;
   L_INT             nUnits;
   RECT              rcBarLocation;
   L_INT             nSizeofBarCodeData;
   L_CHAR *          pszBarCodeData;
   L_INT             nIndexDuplicate;     // for reading only
   L_INT             nTotalCount;         // for reading only
   L_INT             nDupCount;           // for reading only
   L_UINT            uFlags;
   L_UINT            uDataCode;
   L_INT             nAngle;
   L_INT             nBWR;
   POINT Vertices[4]; // Vertices of barcode
} BARCODEDATA, * pBARCODEDATA;

typedef struct _tagBarCodeColor
{
   L_UINT      uStructSize;
   DWORD       dwColorBar;
   DWORD       dwColorSpace;
} BARCODECOLOR, * pBARCODECOLOR;

typedef struct _tagBarCode1D
{
   L_UINT      uStructSize;
   L_BOOL      bOutShowText;              // for writing only
   L_INT       nDirection;                // for reading only
   L_BOOL      bErrorCheck;
   L_INT       nGranularity;
   L_INT       nMinLength;
   L_INT       nMaxLength;
   L_INT       nWhiteLines;
   L_UINT      uStd1DFlags;
   L_UINT      uAdvancedFlags; 
   L_INT       nXModule;
} BARCODE1D, * pBARCODE1D;

typedef struct _tagBarCodeReadPDF
{
   L_UINT      uStructSize;
   L_INT       nDirection;
} BARCODEREADPDF, * pBARCODEREADPDF;

typedef struct _tagBarCodeWritePDF
{
   L_UINT      uStructSize;
   L_UINT16    wEccPerc;
   L_UINT16    wEccLevel;
   L_UINT16    wAspectHeight;
   L_UINT16    wAspectWidth;
   L_UINT16    wModAspectRatio;
   L_UINT16    wColumns;
   L_UINT16    wRows;
   L_UINT16    wModule;
   L_INT       nJustify;
} BARCODEWRITEPDF, * pBARCODEWRITEPDF;

typedef struct _tagBarCodeVersion
{
   L_UINT      uStructSize;
   L_UCHAR     Product[60];
   L_INT       MajorNumber;
   L_INT       MinorNumber;
   L_UCHAR     Date[16];
   L_UCHAR     Time[16];
} BARCODEVERSION, * pBARCODEVERSION;

typedef struct _tagBARCODEWRITEDM
{
   L_UINT      uStructSize;
   L_UINT32    ulFlags;
   L_CHAR      cGroupNumber;
   L_CHAR      cGroupTotal;
   L_UCHAR     cFileIDLo;
   L_UCHAR     cFileIDHi;
   L_INT       nXModule;
} BARCODEWRITEDM, * pBARCODEWRITEDM;

typedef struct _tagBARCODEWRITEQR
{
   L_UINT      uStructSize;
   L_UINT32    ulFlags;
   L_INT       nGroupNumber;
   L_INT       nGroupTotal;
   L_INT       nEccLevel;
   L_INT       nXModule;
} BARCODEWRITEQR, * pBARCODEWRITEQR;

typedef struct _tagBARCODEWRITEAZTEC
{
   L_UINT      uStructSize;
   L_UINT32    ulFlags;
   L_INT       nXModule;
   L_INT       SymbolSize;
   L_INT       ErrorCorrectionRate;
   L_INT       QuietZone;
   L_BOOL      AztecRune;
   L_INT       AztecRuneValue;
} BARCODEWRITEAZTEC,*pBARCODEWRITEAZTEC;

typedef struct _tagBARCODEWRITEMAXI
{
   L_UINT      uStructSize;
   L_UINT32    ulFlags;
   L_INT       MaxiMode;
   L_INT       nXResolution;
   L_BOOL      OpenSystemStandard;
   L_INT       Year;
   L_INT       CountryCode;
   L_INT       ServiceClass;
   L_INT       PostalCodeNum;
   L_CHAR      PostalCodeChar[7];
} BARCODEWRITEMAXI,*pBARCODEWRITEMAXI;

typedef struct _tagBARCODEWRITEMICROQR
{
   L_UINT      uStructSize;
   L_UINT32    ulFlags;
   L_INT       nXModule;
   L_INT       SymbolSize ;
} BARCODEWRITEMICROQR,*pBARCODEWRITEMICROQR;

typedef L_INT (pEXT_CALLBACK BARCODEREADCALLBACK)
   (pBARCODEDATA pBarCodeData,
   L_VOID *    pUserData);

typedef struct _AAMVADATAELEMENT {
   L_UINT     uStructSize;
   L_CHAR     ElementID[3];
   L_CHAR*    Value;
   L_UINT     Length;
} AAMVADATAELEMENT;

typedef struct _AAMVASUBFILE {
   L_UINT                   uStructSize;
   L_AAMVA_SUBFILE_TYPE     SubfileType;
   L_CHAR                   SubfileTypeCode[2];
   L_UINT                   Offset;
   L_UINT                   Length;
   AAMVADATAELEMENT *       DataElements;
   L_UINT                   JurisdictionSpecificDataElementCount;
   L_UINT                   DataElementBufferSize;//For internal use
} AAMVASUBFILE;

typedef struct _AAMVAID {
   L_UINT               uStructSize;
   L_CHAR               IssuerIdentificationNumber[6];
   L_AAMVA_JURISDICTION Jurisdiction;
   L_AAMVA_VERSION      Version;
   L_CHAR               JurisdictionVersion[2];
   L_UINT               NumberOfEntries;
   AAMVASUBFILE*        Subfiles;
} AAMVAID;

typedef struct _AAMVADATAELEMENTINFO {
   L_UINT              uStructSize;
   L_CHAR*             ElementID;
   L_CHAR*             FriendlyName;
   L_UINT              FriendlyNameLength;
   L_CHAR*             Definition;
   L_UINT              DefinitionLength;
   L_UINT              ValueMaxLength;
   L_AAMVA_LENGTH_TYPE LengthType;
   L_BITFIELD          ValidCharacters;
   L_BITFIELD          ValidSubfileTypes;
} AAMVADATAELEMENTINFO;

typedef struct _AAMVAIDBUILDER{
   L_UINT                     uStructSize;
   AAMVAID *                  OutputID;
} AAMVAIDBUILDER;

/****************************************************************
   Function prototypes
****************************************************************/

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeRead(pBITMAPHANDLE   pBitmap,
                                RECT *          prcSearch,
                                L_UINT32        ulSearchType,
                                L_INT           nUnits,
                                L_UINT32        ulFlags,
                                L_INT           nMultipleMaxCount,
                                pBARCODE1D      pBarCode1D,
                                pBARCODEREADPDF pBarCodePDF,
                                pBARCODECOLOR   pBarCodeColor,
                                pBARCODEDATA *  ppBarCodeData,
                                L_UINT          uStructSize);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeReadExt(pBITMAPHANDLE   pBitmap,
                                RECT *          prcSearch,
                                L_UINT32        ulSearchType,
                                L_INT           nUnits,
                                L_UINT32        ulFlags,
                                L_INT           nMultipleMaxCount,
                                pBARCODE1D      pBarCode1D,
                                pBARCODEREADPDF pBarCodePDF,
                                pBARCODECOLOR   pBarCodeColor,
                                pBARCODEDATA *  ppBarCodeData,
                                BARCODEREADCALLBACK pfnCallback,
                                L_VOID*         pUserData,
                                L_UINT          uStructSize);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeWrite(pBITMAPHANDLE     pBitmap,
                                 pBARCODEDATA      pBarCodeData,
                                 pBARCODECOLOR     pBarCodeColor,
                                 L_UINT32          ulFlags,
                                 pBARCODE1D        pBarCode1D,
                                 pBARCODEWRITEPDF  pBarCodePDF,
                                 pBARCODEWRITEDM   pBarCodeDM,
                                 pBARCODEWRITEQR   pBarCodeQR,
                                 pBARCODEWRITEAZTEC   pBarCodeAZTEC,
                                 pBARCODEWRITEMAXI    pBarCodeMAXI,
                                 pBARCODEWRITEMICROQR pBarCodeMICROQR,
                                 LPRECT            lprcSize);

L_LTBAR_API L_VOID EXT_FUNCTION L_BarCodeFree(pBARCODEDATA * ppBarCodeData);

L_LTBAR_API L_BOOL EXT_FUNCTION L_BarCodeIsDuplicated(pBARCODEDATA pBarCodeDataItem);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeGetDuplicated(pBARCODEDATA pBarCodeDataItem);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeGetFirstDuplicated(pBARCODEDATA pBarCodeData, L_INT nIndex);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeGetNextDuplicated(pBARCODEDATA pBarCodeData, L_INT nCurIndex);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeInit (L_INT nMajorType);

L_LTBAR_API L_VOID EXT_FUNCTION L_BarCodeExit (L_VOID);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeVersionInfo(pBARCODEVERSION pBarCodeVersion, L_UINT uStructSize);

#if defined(FOR_WINDOWS)
L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeParseECIData(L_CHAR * pszBarCodeData, L_INT nDataLength, L_CHAR ** pszECIData, L_INT* nECIDataLength);
#endif // #if defined(FOR_WINDOWS)

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeParseAAMVAData(const L_CHAR * barCodeData, L_UINT nDataLength, AAMVAID * pId, L_BOOL bStrictMode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeWriteAAMVAData(const AAMVAID * pId, L_CHAR ** barCodeData, L_UINT * nDataLength);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderInit(AAMVAIDBUILDER * pBuilder);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderSetJurisdiction(AAMVAIDBUILDER * pBuilder, 
                                 L_AAMVA_JURISDICTION jurisdiction, 
                                 const L_CHAR * psIssuerIdentificationNumber);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderSetVersion(AAMVAIDBUILDER * pBuilder, L_AAMVA_VERSION version);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderSetJurisdictionVersion(AAMVAIDBUILDER * pBuilder, const L_CHAR * psJurisdictionVersion);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderSetNumberOfEntries(AAMVAIDBUILDER * pBuilder, L_UINT nNumberOfEntries);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderSetSubfileType(AAMVAIDBUILDER * pBuilder,
                                 L_UINT nSubfileIndex,
                                 L_AAMVA_SUBFILE_TYPE subfileType,
                                 const L_CHAR * subfileTypeCode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderAddDataElementToSubfile(AAMVAIDBUILDER * pBuilder,
                                 L_UINT nSubfileIndex,
                                 const L_CHAR * elementID,
                                 const L_CHAR * value,
                                 L_UINT valueLength);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDBuilderBuild(AAMVAIDBUILDER * pBuilder);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeFreeAAMVAID(AAMVAID * pId);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeGetAAMVADataElementInfo(L_AAMVA_VERSION version, AAMVADATAELEMENTINFO ** values);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupIssuerIdentificationNumber(L_AAMVA_JURISDICTION jurisdiction, L_CHAR ** pszIssuerIdentificationNumber);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupJurisdiction(const L_CHAR * issuerIdentificationNumber, L_AAMVA_JURISDICTION * pJurisdiction);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupStateAbbreviation(L_AAMVA_JURISDICTION jurisdiction, L_CHAR ** pszAddressStateCode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupRegion(L_AAMVA_JURISDICTION jurisdiction, L_AAMVA_REGION * pRegion);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupRaceEthnicity(const L_CHAR * pszRaceEthnicityCode, L_AAMVA_RACE_ETHNICITY * pRaceEthnicity);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupRaceEthnicityCode(L_AAMVA_RACE_ETHNICITY raceEthnicity, L_CHAR ** pszRaceEthnicityCode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupNameSuffix(const L_CHAR * pszSuffixCode, L_AAMVA_NAME_SUFFIX * pSuffix);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupNameSuffixCodeArabic(L_AAMVA_NAME_SUFFIX suffix, L_CHAR ** pszSuffixCode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLookupNameSuffixCodeRoman(L_AAMVA_NAME_SUFFIX suffix, L_CHAR ** pszSuffixCode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDFirstName(const AAMVAID * pId, L_CHAR ** pszFirstName, L_BOOL * bInferredFromFullName);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDMiddleName(const AAMVAID * pId, L_CHAR ** pszMiddleName);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDLastName(const AAMVAID * pId, L_CHAR ** pszLastName, L_BOOL * bInferredFromFullName);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDAddressStreet1(const AAMVAID * pId, L_CHAR ** pszAddressStreet1);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDAddressStreet2(const AAMVAID * pId, L_CHAR ** pszAddressStreet2);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDAddressCity(const AAMVAID * pId, L_CHAR ** pszAddressCity);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDAddressStateAbbreviation(const AAMVAID * pId, L_CHAR ** pszAddressStateAbbrevation);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDAddressPostalCode(const AAMVAID * pId, L_CHAR ** pszAddressPostalCode);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDAddressRegion(const AAMVAID * pId, L_AAMVA_REGION * pRegion);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDDateOfBirth(const AAMVAID * pId, L_CHAR ** pszDateOfBirth);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDOver18Available(const AAMVAID * pId, L_BOOL * bAvailable);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDOver18(const AAMVAID * pId, const L_CHAR * pszCurrentDate, L_BOOL * bOver18);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDOver19Available(const AAMVAID * pId, L_BOOL * bAvailable);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDOver19(const AAMVAID * pId, const L_CHAR * pszCurrentDate, L_BOOL * bOver19);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDOver21Available(const AAMVAID * pId, L_BOOL * bAvailable);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDOver21(const AAMVAID * pId, const L_CHAR * pszCurrentDate, L_BOOL * bOver21);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDIssueDate(const AAMVAID * pId, L_CHAR ** pszIssueDate);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDExpirationDate(const AAMVAID * pId, L_CHAR ** pszExpirationDate);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDExpirationAvailable(const AAMVAID * pId, L_BOOL * bAvailable);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDExpired(const AAMVAID * pId, const L_CHAR * pszCurrentDate, L_BOOL * bExpired);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDNumber(const AAMVAID * pId, L_CHAR ** pszIDNumber);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDEyeColor(const AAMVAID * pId, L_AAMVA_EYE_COLOR * pEyeColor);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDHairColor(const AAMVAID * pId, L_AAMVA_HAIR_COLOR * pHairColor);

L_LTBAR_API L_INT EXT_FUNCTION L_BarCodeAAMVAIDSex(const AAMVAID * pId, L_AAMVA_SEX * pSex);

L_LTBAR_API L_VOID EXT_FUNCTION L_BarCodeAAMVAMemoryFree(L_VOID* pData);

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTBAR_H)
