//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTCLR_H)
#define LTCLR_H

#include "lttyp.h"
#define L_LTCLR_API LT_EXPORTED

#include "ltdis.h"
#include "ltfil.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

/****************************************************************
   Data types
****************************************************************/

// ICC stuff

/* 7-Bit ASCII - must be terminated by NULL */
typedef L_UCHAR L_Icc7BitAscii;

/* Fixed Numbers */
typedef L_INT32  L_IccS15Fixed16Number;   // fixed signed   4bytes, with 16 fractional bits
typedef L_UINT32 L_IccU16Fixed16Number;  // fixed unsigned 4bytes, with 16 fractional bits
typedef L_UINT16 L_IccU1Fixed15Number;   // fixed unsigned 2bytes, with 15 fractional bits
typedef L_UINT16 L_IccU8Fixed8Number;    // fixed unsigned 2bytes, with  8 fractional bits

/* Unsigned Integer Numbers */
typedef L_UINT16 L_IccUInt16Number;
typedef L_UINT32 L_IccUInt32Number;
typedef L_UINT64 L_IccUInt64Number;
typedef L_UCHAR  L_IccUInt8Number;

/* Signed Integer Numbers - not in specification but might be needed */
typedef L_CHAR  L_IccInt8Number;
typedef L_INT16 L_IccInt16Number;
typedef L_INT32 L_IccInt32Number;
typedef L_INT64 L_IccInt64Number;
typedef L_INT32 L_IccSignature;

/****************************************************************
   Enums/defines/macros
****************************************************************/

// white points constants
#define CIELAB_D50      50
#define CIELAB_D55      55
#define CIELAB_D65      65
#define CIELAB_D75      75
#define CIELAB_D93      93
#define CIELAB_CUSTOM   00
#define CIELAB_DEFAULT  CIELAB_D50

// nMethod values for CONVERSION_PARAMS
#define USE_BUILTIN     1  // for equations
#define USE_ICC         2  // for Profiles
#define USE_CUSTOM_ICC  4  // for Custom Profiles
#define USE_ET          8  // for Emulation Tables
#define USE_CUSTOM_ET   16 // for Custom Emulation Tables
#define USE_AUTO        32 // for Best Conversion
#define USE_ALL         63 // for all of the above

// nMask values for SET_CONVERSION_PARAMS
#define CHANGE_ACTIVE_METHOD     1     // change the active method
#define CHANGE_CUSTOM_PROFILES   2     // change profiles
#define CHANGE_WHITE_POINT       4     // change white point
#define CHANGE_ET                8     // change Emulation Tables
#define CHANGE_CMYK              16    // change CMYK parameters
#define CHANGE_YUV               32    // change YUV parameters
#define CHANGE_LAB               64    // change LAB parameters
#define CHANGE_ALL               127   // change all of the above

// nMask values for CMYK_PARAMS
#define CMYK_GCR  1  // change nGcr_level

// nDlg values for L_ClrDlg
#define DLG_CMYK  1  // CMYK dialog
#define DLG_LAB   2  // LAB dialog

// nMask values for LAB_PARAMS
#define LAB_L_OFFSET    1  // change L_min value
#define LAB_L_RANGE     2  // change a_min value
#define LAB_a_OFFSET    4  // change b_min value
#define LAB_a_RANGE     8  // change L_max value
#define LAB_b_OFFSET    16 // change a_max value
#define LAB_b_RANGE     32 // change b_max value

// nMask values for YUV_PARAMS
#define YUV_UH          1  // change nUh value
#define YUV_UV          2  // change nUv value
#define YUV_VH          4  // change nVh value
#define YUV_VV          8  // change nvV value
#define YUV_OFFSETS     16 // change pOffsets value
#define YUV_MACROPIXEL  32 // change nMacroPixel value
#define YUV_RANGE       64 // change nRange value

// nRange values for YUV_PARAMS
#define YUVRANGE_FULL      0  // the range is 000 - 255
#define YUVRANGE_16_240    1  // the range is 016 - 240

#define PLANAR_YUV   0
#define PLANAR_YVU   1
#define PLANAR_UYV   2
#define PLANAR_UVY   3
#define PLANAR_VYU   4
#define PLANAR_VUY   5

// nGamma constants
#define GAMMA_STANDARD  45 // 2.22

#define ICC_PROFILE_SIG    0x61637370  // 'acsp'
#define ICC_PROFILE_VER42  0x04200000  // 4.2.0.0
#define ICC_PROFILE_VER40  0x04000000  // 4.0.0.0

#define ICC_LITTLE_INDIAN  0x0   /* We are using Little Indian Notation */
#define ICC_BIG_INDIAN     0x1   /* We are using Big Indian Notation */

// Profile header flags, the low 16 bits are reserved for consortium use
#define ICC_EMBEDDED_PROFILE_FALSE        0x00000000  // Bit pos 0
#define ICC_EMBEDDED_PROFILE_TRUE         0x00000001  // Bit pos 0
#define ICC_USE_ANYWHERE                  0x00000000  // Bit pos 1
#define ICC_USE_WITH_EMBEDDED_DATA_ONLY   0x00000002  // Bit pos 1

// Device attributes, currently defined values correspond
// to the low 4 bytes of the 8 byte attribute quantity, see
// the header for their location.
#define ICC_REFLECTIVE                 0x0000000000000000   // Bit pos 0
#define ICC_TRANSPARENCY               0x0000000000000001   // Bit pos 0
#define ICC_GLOSSY                     0x0000000000000000   // Bit pos 1
#define ICC_MATTE                      0x0000000000000002   // Bit pos 1
#define ICC_MEDIA_POLARITY_POSITIVE    0x0000000000000000   // Bit pos 2
#define ICC_MEDIA_POLARITY_NEGATIVE    0x0000000000000004   // Bit pos 2
#define ICC_COLOR_MEDIA                0x0000000000000000   // Bit pos 3
#define ICC_BLACK_AND_WHITE            0x0000000000000008   // Bit pos 3

// Other defines needed for the programming
#define ICC_HEADER_SIZE       128
#define ICC_TAG_COUNTER_SIZE  4
#define ICC_TAG_UNIT_SIZE     12
#define ICC_D50_X             0x0000F6D6
#define ICC_D50_Y             0x00010000
#define ICC_D50_Z             0x0000D32D

#define ICC_LUT_CURVEA  1
#define ICC_LUT_CURVEB  2
#define ICC_LUT_CURVEM  3

#define ICC_PROFILE_FLAGS_MASK      0x00000003
#define ICC_DEVICE_ATTRIBUTES_MASK  0x0000000F
#define ICC_VENDOR_FLAG_MASK        0xFFFF0000

#define LTCLR_DISABLE_WHITE_POINT_ADJUSTMENT 0x00000001  /* If this is set, the white points are not adjusted to perfect white to fix scum dot problems */

#define _255Bytes    255
#define _84Bytes     84
#define _52Bytes     52
#define _38Bytes     38
#define _36Bytes     36
#define _32Bytes     32
#define _28Bytes     28
#define _20Bytes     20
#define _16Bytes     16
#define _14Bytes     14
#define _13Bytes     13
#define _12Bytes     12
#define _11Bytes     11
#define _9Bytes      9
#define _8Bytes      8
#define _7Bytes      7
#define _6Bytes      6
#define _4Bytes      4
#define _3Bytes      3
#define _2Bytes      2
#define _1Byte       1
#define _4Bits       4
#define _12Elements  12
#define _7Elements   7
#define _5Elements   5
#define _4Elements   4
#define _3Elements   3
#define _1Elements   1

// Rendering Intents, used in the profile header
typedef enum
{
    Perceptual             = 0x00000000,
    RelativeColorimetric   = 0x00000001,
    Saturation             = 0x00000002,
    AbsoluteColorimetric   = 0x00000003
}
ICCRENDERINGINTENT;

// public tags and sizes
typedef enum
{
   AToB0Tag                = 0x41324230,  // 'A2B0'
   AToB1Tag                = 0x41324231,  // 'A2B1,
   AToB2Tag                = 0x41324232,  // 'A2B2'
   BlueMatrixColumnTag     = 0x6258595A,  // 'bXYZ,
   BlueTRCTag              = 0x62545243,  // 'bTRC,
   BToA0Tag                = 0x42324130,  // 'B2A0,
   BToA1Tag                = 0x42324131,  // 'B2A1,
   BToA2Tag                = 0x42324132,  // 'B2A2,
   CalibrationDateTimeTag  = 0x63616C74,  // 'calt,
   CharTargetTag           = 0x74617267,  // 'targ,
   ChromaticAdaptationTag  = 0x63686164,  // 'chad,
   ChromaticityTag         = 0x6368726D,  // 'chrm,
   ColorantOrderTag        = 0x636C726F,  // 'clro,
   ColorantTableTag        = 0x636C7274,  // 'clrt,
   ColorantTableOutTag     = 0x636C6F74,  // 'clot,
   CopyrightTag            = 0x63707274,  // 'cprt,
   DeviceMfgDescTag        = 0x646D6E64,  // 'dmnd,
   DeviceModelDescTag      = 0x646D6464,  // 'dmdd,
   GamutTag                = 0x67616D74,  // 'gamt,
   GrayTRCTag              = 0x6B545243,  // 'kTRC,
   GreenMatrixColumnTag    = 0x6758595A,  // 'gXYZ,
   GreenTRCTag             = 0x67545243,  // 'gTRC,
   LuminanceTag            = 0x6C756D69,  // 'lumi,
   MeasurementTag          = 0x6D656173,  // 'meas,
   MediaBlackPointTag      = 0x626B7074,  // 'bkpt,
   MediaWhitePointTag      = 0x77747074,  // 'wtpt,
   NamedColor2Tag          = 0x6E636C32,  // 'ncl2,
   OutputResponseTag       = 0x72657370,  // 'resp,
   Preview0Tag             = 0x70726530,  // 'pre0,
   Preview1Tag             = 0x70726531,  // 'pre1,
   Preview2Tag             = 0x70726532,  // 'pre2,
   ProfileDescriptionTag   = 0x64657363,  // 'desc,
   ProfileSequenceDescTag  = 0x70736571,  // 'pseq,
   RedMatrixColumnTag      = 0x7258595A,  // 'rXYZ,
   RedTRCTag               = 0x72545243,  // 'rTRC,
   TechnologyTag           = 0x74656368,  // 'tech,
   ViewingCondDescTag      = 0x76756564,  // 'vued,
   ViewingConditionsTag    = 0x76696577,  // 'view,
}
ICCTAGSIGNATURE;

// technology signature descriptions
typedef enum
{
   FilmScanner                = 0x6673636E,  // 'fscn'
   DigitalCamera              = 0x6463616D,  // 'dcam'
   ReflectiveScanner          = 0x7273636E,  // 'rscn'
   InkJetPrinter              = 0x696A6574,  // 'ijet' 
   ThermalWaxPrinter          = 0x74776178,  // 'twax'
   ElectrophotographicPrinter = 0x6570686F,  // 'epho'
   ElectrostaticPrinter       = 0x65737461,  // 'esta'
   DyeSublimationPrinter      = 0x64737562,  // 'dsub'
   PhotographicPaperPrinter   = 0x7270686F,  // 'rpho'
   FilmWriter                 = 0x6670726E,  // 'fprn'
   VideoMonitor               = 0x7669646D,  // 'vidm'
   VideoCamera                = 0x76696463,  // 'vidc'
   ProjectionTelevision       = 0x706A7476,  // 'pjtv'
   CRTDisplay                 = 0x43525420,  // 'CRT '
   PMDisplay                  = 0x504D4420,  // 'PMD '
   AMDisplay                  = 0x414D4420,  // 'AMD '
   PhotoCD                    = 0x4B504344,  // 'KPCD'
   PhotoImageSetter           = 0x696D6773,  // 'imgs'
   Gravure                    = 0x67726176,  // 'grav'
   OffsetLithography          = 0x6F666673,  // 'offs'
   Silkscreen                 = 0x73696C6B,  // 'silk'
   Flexography                = 0x666C6578,  // 'flex'
}
ICCTECHNOLOGYSIGNATURE;

// type signatures
typedef enum
{
   ChromaticityTypeSig           = 0x6368726D,  // 'chrm'
   ColorantOrderTypeSig          = 0x636c726f,  // 'clro'
   ColorantTableTypeSig          = 0x636c7274,  // 'clrt'
   CurveTypeSig                  = 0x63757276,  // 'curv'
   DataTypeSig                   = 0x64617461,  // 'data'
   DateTimeTypeSig               = 0x6474696D,  // 'dtim'
   Lut16TypeSig                  = 0x6d667432,  // 'mft2'
   Lut8TypeSig                   = 0x6d667431,  // 'mft1'
   LutAtoBTypeSig                = 0x6D414220,  // 'mAB' 
   LutBtoATypeSig                = 0x6D424120,  // 'mBA' 
   MeasurementTypeSig            = 0x6D656173,  // 'meas'
   MultiLocalizedUnicodeTypeSig  = 0x6D6C7563,  // 'mluc'
   NamedColor2TypeSig            = 0x6E636C32,  // 'ncl2'
   ParametricCurveTypeSig        = 0x70617261,  // 'para'
   ProfileSequenceDescTypeSig    = 0x70736571,  // 'pseq'
   ResponseCurveSet16TypeSig     = 0x72637332,  // 'rcs2'
   S15Fixed16ArrayTypeSig        = 0x73663332,  // 'sf32'
   SignatureTypeSig              = 0x73696720,  // 'sig '
   TextTypeSig                   = 0x74657874,  // 'text'
   U16Fixed16ArrayTypeSig        = 0x75663332,  // 'uf32'
   UInt16ArrayTypeSig            = 0x75693136,  // 'ui16'
   UInt32ArrayTypeSig            = 0x75693332,  // 'ui32'
   UInt64ArrayTypeSig            = 0x75693634,  // 'ui64'
   UInt8ArrayTypeSig             = 0x75693038,  // 'ui08'
   ViewingConditionsTypeSig      = 0x76696577,  // 'view'
   XYZTypeSig                    = 0x58595A20   // 'XYZ '
} ICCTAGTYPESIGNATURE;

// Standard Observer, used in the measurmentType tag
typedef enum
{
   StdObsUnknown        = 0x00000000,  // Unknown
   StdObs1931TwoDegrees = 0x00000001,  // 2 deg
   StdObs1964TenDegrees = 0x00000002,  // 10 deg
}
ICCSTANDARDOBSERVER;

// Measurement Geometry, used in the measurmentType tag
typedef enum 
{
   GeometryUnknown   = 0x00000000,  // Unknown
   Geometry045or450  = 0x00000001,  // 0/45, 45/0
   Geometry0dord0    = 0x00000002,  // 0/d or d/0
}
ICCMEASUREMENTGEOMETRY;

// Measurement Flare, used in the measurmentType tag
typedef enum
{
   Flare0   = 0x00000000,  // 0% flare
   Flare100 = 0x00010000,  // 100% flare
}
ICCMEASUREMENTFLARE;

// Pre-defined illuminants, used in measurement and viewing conditions type
typedef enum
{
   IccIlluminantUnknown    = 0x00000000,
   IccIlluminantD50        = 0x00000001,
   IccIlluminantD65        = 0x00000002,
   IccIlluminantD93        = 0x00000003,
   IccIlluminantF2         = 0x00000004,
   IccIlluminantD55        = 0x00000005,
   IccIlluminantA          = 0x00000006,
   IccIlluminantEquiPowerE = 0x00000007,
   IccIlluminantF8         = 0x00000008,
}
ICCSTANDARDILLUMINANT;

// Parametric Curve Function Type
typedef enum
{
   Func4Bytes  = 0x0000,   // Y = X^(gamma)
   Func12Bytes = 0x0001,   // Y = (aX + b)^(gamma)      ,  (X >= -b/a)
                           // Y = 0                     ,  (X <  -b/a)
   Func16Bytes = 0x0002,   // Y = (aX + b)^(gamma) + c  ,  (X >= -b/a)
                           // Y = c                     ,  (X <  -b/a)
   Func20Bytes = 0x0003,   // Y = (aX + b)^(gamma)      ,  (X >= -b/a)
                           // Y = cX                    ,  (X <  -b/a)
   Func28Bytes = 0x0004,   // Y = (aX + b)^(gamma) + e  ,  (X >= -b/a)
                           // Y = (cX + f)              ,  (X <  -b/a)
}
ICCFUNCTIONTYPE;

// Curve Measurement Signatures
typedef enum
{
   StaA  = 0x53746141,
   StaE  = 0x53746145,
   StaI  = 0x53746149,
   StaT  = 0x53746154,
   StaM  = 0x5374614D,
   DN    = 0x434E2020,
   DN_P  = 0x434E2050,
   DNN   = 0x434E4E20,
   DNNP  = 0x434E4E50,
}
ICCMEASUREMENTSIGNATURE;

// Phosphore or Colorant Type
typedef enum
{
   UnknownColorant   = 0x0000,
   ITU_R_BT709       = 0x0001,
   SMPTE_RP145_1994  = 0x0002,
   EBU_TECH3213_E    = 0x0003,
   P22               = 0x0004,
}
ICCCOLORANTTYPE;

// Type of data in dataType encoding
typedef enum
{
   ASCII    = 0x00000000,
   Binary   = 0x00000001,
}
ICCDATATYPEFLAGS;

// profileClass enumerations
typedef enum _ICCPROFILECLASS
{
   InputClass        = 0x73636E72,  // 'scnr'
   DisplayClass      = 0x6D6E7472,  // 'mntr'
   OutputClass       = 0x70727472,  // 'prtr'
   DeviceLinkClass   = 0x6C696E6B,  // 'link'
   AbstractClass     = 0x61627374,  // 'abst'
   ColorSpaceClass   = 0x73706163,  // 'spac'
   NamedColorClass   = 0x6E6D636C,  // 'nmcl'
}
ICCPROFILECLASS;

// color spaces
typedef enum _ICCCOLORSPACE
{
   XyzData     = 0x58595A20,  // 'XYZ '
   LabData     = 0x4C616220,  // 'Lab '
   LuvData     = 0x4C757620,  // 'Luv '
   YCbCrData   = 0x59436272,  // 'YCbr'
   YxyData     = 0x59787920,  // 'Yxy '
   RgbData     = 0x52474220,  // 'RGB '
   GrayData    = 0x47524159,  // 'GRAY'
   HsvData     = 0x48535620,  // 'HSV '
   HlsData     = 0x484C5320,  // 'HLS '
   CmykData    = 0x434D594B,  // 'CMYK'
   CmyData     = 0x434D5920,  // 'CMY '
   ColorData2  = 0x32434C52,  // '2CLR'
   ColorData3  = 0x33434C52,  // '3CLR'
   ColorData4  = 0x34434C52,  // '4CLR'
   ColorData5  = 0x35434C52,  // '5CLR'
   ColorData6  = 0x36434C52,  // '6CLR'
   ColorData7  = 0x37434C52,  // '7CLR'
   ColorData8  = 0x38434C52,  // '8CLR'
   ColorData9  = 0x39434C52,  // '9CLR'
   ColorData10 = 0x41434C52,  // 'ACLR'
   ColorData11 = 0x42434C52,  // 'BCLR'
   ColorData12 = 0x43434C52,  // 'CCLR'
   ColorData13 = 0x44434C52,  // 'DCLR'
   ColorData14 = 0x45434C52,  // 'ECLR'
   ColorData15 = 0x46434C52,  // 'FCLR'
}
ICCCOLORSPACE;

// Platform Signatures
typedef enum _ICCPLATFORMSIGNATURE
{
   NoPlatformSignature  = 0x00000000,
   MacintoshSignature   = 0x4150504C,  // 'APPL'
   MicrosoftSignature   = 0x4D534654,  // 'MSFT'
   SolarisSignature     = 0x53554E57,  // 'SUNW'
   SGISignature         = 0x53474920,  // 'SGI '
}
ICCPLATFORMSIGNATURE;

/****************************************************************
   Classes/structures
****************************************************************/
typedef struct _WHITEPOINT
{
   L_INT nWhitePoint;
   L_DOUBLE xWhite;
   L_DOUBLE yWhite;
}
WHITEPOINT, *LPWHITEPOINT;

typedef struct _CMYK_PARAMS
{
   L_UINT uStructSize;
   L_INT nGcr_level; // value between 0.0 and 1.0
   L_INT nMask;
}
CMYK_PARAMS, *LPCMYK_PARAMS;

typedef struct _YUV_PARAMS
{
   L_UINT uStructSize;
   L_INT nMask;
   L_INT nUh;           // horizontal frequency of U
   L_INT nUv;           // vertical frequency of U
   L_INT nVh;           // horizontal frequency of V
   L_INT nVv;           // vertical frequency of V
   L_INT* pOffsets;     // offsets of the byte ordering for the proposed YUV format
                        // when bPlaner is TRUE, the only useful data is pOffset[0]
                        // which will indicate what is the arrangement of the YUV
                        // buffer(YUV,YVU,UYV,UVY,VYU,VUY)
   L_INT nMacroPixel;   // number of pixels in the macro pixel
   L_INT nRange;        // the range of values in the input buffer; full
                        // range or 16-240 (YUVRANGE_FULL and YUVRANGE_16_240)
   L_BOOL bPlanar;      // the buffer consists of planes; Y plane, V plane and U plane
}
YUV_PARAMS, *LPYUV_PARAMS;

typedef struct _LAB_PARAMS
{
   L_UINT uStructSize;
   L_INT nMask;
   L_INT L_offset;
   L_INT L_range;
   L_INT a_offset;
   L_INT a_range;
   L_INT b_offset;
   L_INT b_range;
}
LAB_PARAMS, *LPLAB_PARAMS;

typedef struct _MEMICCPROFILE
{
   L_UINT uStructSize;
   L_UCHAR* pData;
   L_SIZE_T uDataSize;
}
MEMICCPROFILE, *pMEMICCPROFILE;

typedef struct _CONVERSION_PARAMSA
{
   L_UINT uStructSize;
   L_INT nActiveMethod;                //  one of the values: USE_BUILTIN    for built-in,
                                       //                     USE_ICC        for Profiles,
                                       //                     USE_CUSTOM_ICC for user-defined profiles
                                       //                     USE_ET         for built-in Emulation Tables
                                       //                     USE_CUSTOM_ET  for custom Emulation Tables
                                       //                     USE_AUTO       for best conversion method
                                       //                     USE_ALL        for all
   LPWHITEPOINT pWpoint;               //  white point struct that describes the white point to be used
   L_CHAR sInputProfile[L_MAXPATH];    //  optional input profile
   pMEMICCPROFILE pMemInputProfile;    //  optional source memory profile
   L_CHAR sOutputProfile[L_MAXPATH];   //  optional output profile
   pMEMICCPROFILE pMemOutputProfile;   //  optional destination memory profile
   L_CHAR sDstInputTable[L_MAXPATH];   //  optional Dst image for emulation
   LPCMYK_PARAMS pCmykParams;          //  CMYK data
   LPYUV_PARAMS pYuvParams;            //  YUV data
   LPLAB_PARAMS pLabParams;            //  CIELab data
   L_INT nMethod;                      //  in the case we use it with L_ClrInit function this structure
                                       //  will have one of the values:
                                       //                     USE_BUILTIN    for built-in,
                                       //                     USE_ICC        for Profiles,
                                       //                     USE_CUSTOM_ICC for user-defined profiles
                                       //                     USE_ET         for built-in Emulation Tables
                                       //                     USE_CUSTOM_ET  for custom Emulation Tables
                                       //                     USE_AUTO       for best conversion method
                                       //                     USE_ALL        for all
                                       //  in the case used with L_SetConversionParams function, it will
                                       //  hold the masking values
   L_INT nQuantization;                //  quantization level, used with USE_ET
   L_UINT uFlags;                      //  Optional flags (pass 0 if unsure). The only flag supported right now is LTCLR_DISABLE_WHITE_POINT_ADJUSTMENT
}
CONVERSION_PARAMSA, *LPCONVERSION_PARAMSA;

#if defined(FOR_UNICODE)
typedef struct _CONVERSION_PARAMS
{
   L_UINT uStructSize;
   L_INT nActiveMethod;                //  one of the values: USE_BUILTIN    for built-in,
                                       //                     USE_ICC        for Profiles,
                                       //                     USE_CUSTOM_ICC for user-defined profiles
                                       //                     USE_ET         for built-in Emulation Tables
                                       //                     USE_CUSTOM_ET  for custom Emulation Tables
                                       //                     USE_AUTO       for best conversion method
                                       //                     USE_ALL        for all
   LPWHITEPOINT pWpoint;               //  white point struct that describes the white point to be used
   L_TCHAR sInputProfile[L_MAXPATH];   //  optional input profile
   pMEMICCPROFILE pMemInputProfile;    //  optional source memory profile
   L_TCHAR sOutputProfile[L_MAXPATH];  //  optional output profile
   pMEMICCPROFILE pMemOutputProfile;   //  optional destination memory profile
   L_TCHAR sDstInputTable[L_MAXPATH];  //  optional Dst image for emulation
   LPCMYK_PARAMS pCmykParams;          //  CMYK data
   LPYUV_PARAMS pYuvParams;            //  YUV data
   LPLAB_PARAMS pLabParams;            //  CIELab data
   L_INT nMethod;                      //  in the case we use it with L_ClrInit function this structure
                                       //  will have one of the values:
                                       //                     USE_BUILTIN    for built-in,
                                       //                     USE_ICC        for Profiles,
                                       //                     USE_CUSTOM_ICC for user-defined profiles
                                       //                     USE_ET         for built-in Emulation Tables
                                       //                     USE_CUSTOM_ET  for custom Emulation Tables
                                       //                     USE_AUTO       for best conversion method
                                       //                     USE_ALL        for all
                                       //  in the case used with L_SetConversionParams function, it will
                                       //  hold the masking values
   L_INT nQuantization;                //  quantization level, used with USE_ET
   L_UINT uFlags;                      //  Optional flags (pass 0 if unsure). The only flag supported right now is LTCLR_DISABLE_WHITE_POINT_ADJUSTMENT
}
CONVERSION_PARAMS, *LPCONVERSION_PARAMS;
#else
typedef CONVERSION_PARAMSA CONVERSION_PARAMS;
typedef LPCONVERSION_PARAMSA LPCONVERSION_PARAMS;
#endif  // #if defined(FOR_UNICODE)
// XYZ Number
typedef struct _ICC_XYZ_NUMBER
{
   L_IccS15Fixed16Number nX;
   L_IccS15Fixed16Number nY;
   L_IccS15Fixed16Number nZ;
}
ICC_XYZ_NUMBER, *pICC_XYZ_NUMBER;

typedef struct _ICC_RESPONSE_16_NUMBER
{
   L_IccUInt16Number uDeviceCode;
   L_IccUInt16Number uReserved;
   L_IccS15Fixed16Number uMeasurement;
}
ICC_RESPONSE_16_NUMBER, *pICC_RESPONSE_16_NUMBER;

// XYZ Array
typedef struct _ICC_XYZ_ARRAY
{
   pICC_XYZ_NUMBER XYZData;   // Variable array of XYZ numbers
}
ICC_XYZ_ARRAY, *pICC_XYZ_ARRAY;

// Curve
typedef struct _ICCCURVE
{
    L_IccUInt32Number uCurveCount;  // Number of entries
    L_IccUInt16Number* pCurveData;  // The actual table data, real
                                    // number is determined by count
                                    // Interpretation depends on how
                                    // data is used with a given tag
}
ICC_CURVE, *pICC_CURVE;

// Data
typedef struct _ICCDATA
{
    L_UINT32         uDataFlag;           // 0 = ascii, 1 = binary
    L_Icc7BitAscii*  pData;               /* Data                    */
    L_UINT           uDataElementsCount;  /* Number of Data Elements */
} ICC_DATA, * pICC_DATA;

/* MATRIX Structure */
typedef struct _MATRIX
{
   L_IccS15Fixed16Number pElement[12];    /* Matrix elements */
} ICC_MATRIX, * pICC_MATRIX;

/* lut16 */
typedef struct _ICCLUT16
{
    L_IccUInt8Number          uInputChan;     /* Number of input channels   */
    L_IccUInt8Number          uOutputChan;    /* Number of output channels  */
    L_IccUInt8Number          uClutPoints;    /* Number of grid points      */
    L_IccUInt8Number          uPad;           /* Padding for byte alignment */
    L_IccS15Fixed16Number     nE00;           /* e00 in the 3 * 3           */
    L_IccS15Fixed16Number     nE01;           /* e01 in the 3 * 3           */
    L_IccS15Fixed16Number     nE02;           /* e02 in the 3 * 3           */
    L_IccS15Fixed16Number     nE10;           /* e10 in the 3 * 3           */
    L_IccS15Fixed16Number     nE11;           /* e11 in the 3 * 3           */
    L_IccS15Fixed16Number     nE12;           /* e12 in the 3 * 3           */
    L_IccS15Fixed16Number     nE20;           /* e20 in the 3 * 3           */
    L_IccS15Fixed16Number     nE21;           /* e21 in the 3 * 3           */
    L_IccS15Fixed16Number     nE22;           /* e22 in the 3 * 3           */
    L_IccUInt16Number         uInputEnt;      /* Num of in-table entries    */
    L_IccUInt16Number         uOutputEnt;     /* Num of out-table entries   */
    L_IccUInt16Number * pInputTables;   /* Input Tables               */
    L_IccUInt16Number * pCLUT;          /* CLUT value                 */
    L_IccUInt16Number * pOutputTables;  /* Output Tables              */
} ICC_LUT16, * pICC_LUT16;

/* lut8, input & output tables are always 256 bytes in length */
typedef struct _ICCLUT8
{
    L_IccUInt8Number         uInputChan;     /* Number of input channels   */
    L_IccUInt8Number         uOutputChan;    /* Number of output channels  */
    L_IccUInt8Number         uClutPoints;    /* Number of grid points      */
    L_IccUInt8Number         uPad;           /* Padding for byte alignment */
    L_IccS15Fixed16Number    nE00;           /* e00 in the 3 * 3           */
    L_IccS15Fixed16Number    nE01;           /* e01 in the 3 * 3           */
    L_IccS15Fixed16Number    nE02;           /* e02 in the 3 * 3           */
    L_IccS15Fixed16Number    nE10;           /* e10 in the 3 * 3           */
    L_IccS15Fixed16Number    nE11;           /* e11 in the 3 * 3           */
    L_IccS15Fixed16Number    nE12;           /* e12 in the 3 * 3           */
    L_IccS15Fixed16Number    nE20;           /* e20 in the 3 * 3           */
    L_IccS15Fixed16Number    nE21;           /* e21 in the 3 * 3           */
    L_IccS15Fixed16Number    nE22;           /* e22 in the 3 * 3           */
    L_IccUInt16Number        uInputEnt;      /* Num of in-table entries    */
    L_IccUInt16Number        uOutputEnt;     /* Num of out-table entries   */
    L_IccUInt8Number * pInputTables;   /* Input Tables               */
    L_IccUInt8Number * pCLUT;          /* CLUT value                 */
    L_IccUInt8Number * pOutputTables;  /* Output Tables              */
} ICC_LUT8, * pICC_LUT8;

/* Measurement Data */
typedef struct _ICCMEASUREMENT
{
    L_UINT32               uStdObserver;  /* Standard observer */
    ICC_XYZ_NUMBER         Backing;        /* XYZ for backing   */
    L_UINT32               uGeometry;      /* Meas. geometry    */
    L_UINT32               uFlare;         /* Measurement flare */
    L_UINT32               uIlluminant;    /* Illuminant        */
} ICC_MEASUREMENT, * pICC_MEASUREMENT;

/* Named Color */
typedef struct _ICC_NAMEDCOLORDATA
{
   L_Icc7BitAscii    uColorRootName[32];        /* Color root name Null terminated */
   L_IccUInt16Number uColorPCSCoord[3];         /* Color PCS coordinates           */
   L_IccUInt16Number * uColorDeviceCoord; /* Named color device coordinates  */
} ICC_NAMED_COLOR2_DATA, * pICC_NAMED_COLOR2_DATA;

/* IccNamedColor2 */
typedef struct _ICCNAMEDCOLOR2
{
    L_IccUInt32Number      uVendorFlag;        /* Bottom 16 bits for IC use  */
    L_IccUInt32Number      uNamedColorsCount;  /* Count of named colors      */
    L_IccUInt32Number      uDeviceCoordsCount; /* Num of device coordinates  */
    L_Icc7BitAscii         pPrefix[32];        /* Prefix for each color name */
    L_Icc7BitAscii         pSuffix[32];        /* Suffix for each color name */
    pICC_NAMED_COLOR2_DATA pNamedColors;       /* Named colors               */
} ICC_NAMED_COLOR2, * pICC_NAMED_COLOR2;

/* Parametric curve data */
typedef struct _ICCPARAMETRICCURVE
{
   L_UINT16                      uFunctionType;   /* Function Type       */
   L_IccUInt8Number              uReserved[2];     /* Reserved 2 bytes    */
   L_IccS15Fixed16Number * pParameters;      /* Function parameters */
} ICC_PARAMETRIC_CURVE, * pICC_PARAMETRIC_CURVE;

/* Response Arrays */
typedef struct _ICC_RESPONSEARRAYS
{
   pICC_RESPONSE_16_NUMBER    pResponseNumber;
} ICC_RESPONSE_ARRAYS, * pICC_RESPONSE_ARRAYS;

/* Curve Structure */
typedef struct _ICC_CURVESTRUCTURE
{
   L_UINT32                  uMeasurementSig;              /* Curve Measurement Signature        */
   L_IccUInt32Number * pMeasurementCount;             /* Measurement count for each channel */
   pICC_XYZ_NUMBER           pMeasOfPatch;                  /* Number of Measurements of patch 
                                                             * with the maximum colorant value.   */
   pICC_RESPONSE_ARRAYS      pRespArrays;                   /* Number of response arrays channels */
} ICC_CURVE_STRUCTURE, * pICC_CURVE_STRUCTURE;

/* Response Curve Set16 data */
typedef struct _ICC_RESPONSECURVE
{
   L_IccUInt16Number         uChannelsCount;          /* Number of Channels                     */
   L_IccUInt16Number         uMeasurementTypesCount;  /* Count of Measurement Type              */
   L_IccUInt32Number * pResponseDataOffsets;    /* Response data for the measurement unit 
                                                       * each offset is relative to byte 0 of 
                                                       * this structure                         */
   pICC_CURVE_STRUCTURE      pCurveStructure;         /* Count response curve structures        */
} ICC_RESPONSE_CURVE, * pICC_RESPONSE_CURVE;

/* Viewing Condition data */
typedef struct _ICC_VIEWCOND
{
    ICC_XYZ_NUMBER        AbsIlluminant;     /* In candelas per sq. meter */
    ICC_XYZ_NUMBER        AbsSurround;       /* In candelas per sq. meter */
    L_UINT32              uIlluminantType;   /* See icIlluminant defines  */
} ICC_VIEW_COND, * pICC_VIEW_COND;

/* Channel Coordinates */
typedef struct _ICC_CHROMATICITY_CHANNELS
{
   L_IccU16Fixed16Number Coords[2];
} ICC_CHANNEL_COORD, * pICC_CHANNEL_COORD;

/* Chromaticity Data */
typedef struct _ICC_CHROMATICITY
{
   L_IccUInt16Number  uChannelsCount;     /* Number of device channels           */
   L_UINT32           uColorantType;      /* Phosphor or Colorant Type           */
   pICC_CHANNEL_COORD pChannels;          /* Other Channel Coordinates if needed */
} ICC_CHROMATICITY, * pICC_CHROMATICITY;

/* Colorant Table data */
typedef struct _ICC_COLORANTTABLEDATA
{
   L_Icc7BitAscii    pColorantName[32];  /* Colorant name, null terminated, unused bytes set to zero    */
   L_IccUInt16Number uPCSValue[3];       /* PCS value of the colorant in the color space of the profile */
} ICC_COLORANT_TABLE_DATA, * pICC_COLORANT_TABLE_DATA;

/* Multi Localized Unicode Data - Name Records */
typedef struct _ICC_NAME_RECORD
{
   L_IccUInt16Number uNameLangCode;     /* Language Code from ISO-639                */
   L_IccUInt16Number uNameCountryCode;  /* Region Code from IDO-3166                 */
   L_IccUInt32Number uNameLength;       /* Length in bytes of the string             */
   L_IccUInt32Number uNameOffset;       /* Offset from the start of the tag in bytes */   
} ICC_NAME_RECORD, * pICC_NAME_RECORD;

/* Multi Localized Unicode Data */
typedef struct _ICC_MULTILOCALIZEDUNICODE
{
   L_IccUInt32Number uNameRecordsCount;    /* Number of name records that follow  */
   L_IccUInt32Number uNameRecordSize;      /* Length in bytes of each name record */
   pICC_NAME_RECORD  pNameRecordsData;     /* Name records if available           */
   L_UINT16 *  pUnicodeCharacters;   /* Storage Area of Unicode Characters  */
} ICC_MULTI_LOCALIZED_UNICODE, * pICC_MULTI_LOCALIZED_UNICODE;

/*------------------------------------------------------------------------*/
/* Tag Type Definitions                                                   */
/*------------------------------------------------------------------------*/

/* The base part of each tag */
typedef struct _ICCTAG_BASE
{
    L_UINT32  Signature;       /* Signature          */
    L_UCHAR   uReserved[4];    /* Reserved, set to 0 */
} ICCTAG_BASE, * pICCTAG_BASE;

/* chromaticityType */
typedef struct _ICCTAG_CHROMATICITY_TYPE
{
   ICCTAG_BASE      tagBase;    /* Signature "chrm"       */
   ICC_CHROMATICITY Chrom;      /* Chromaticity structure */
} ICCTAG_CHROMATICITY_TYPE, * pICCTAG_CHROMATICITY_TYPE;

/* colorantOrderType */
typedef struct _ICCTAG_COLORANT_ORDER_TYPE
{
   ICCTAG_BASE              tagBase;         /* Signature "clro"    */
   L_IccUInt32Number        uColorantsCount; /* Count of colorants  */
   L_IccUInt8Number * pColorantsData;  /* Remaining Colorants */
} ICCTAG_COLORANT_ORDER_TYPE, * pICCTAG_COLORANT_ORDER_TYPE;

/* colorantTableType */
typedef struct _ICCTAG_COLORANT_TABLE_TYPE
{
   ICCTAG_BASE              tagBase;         /* Signature "clrt"                  */
   L_IccUInt32Number        uColorantsCount; /* Count of colorants                */
   pICC_COLORANT_TABLE_DATA pColorantsData;  /* Remaining Colorants               */
} ICCTAG_COLORANT_TABLE_TYPE, * pICCTAG_COLORANT_TABLE_TYPE;

/* curveType */
typedef struct _ICCTAG_CURVE_TYPE
{
    ICCTAG_BASE tagBase;            /* Signature, "curv" */
    ICC_CURVE   Curve;              /* The curve data    */
} ICCTAG_CURVE_TYPE, * pICCTAG_CURVE_TYPE;

/* dataType */
typedef struct _ICCTAG_DATA_TYPE
{
   ICCTAG_BASE tagBase;             /* Signature "data"          */
   ICC_DATA    Data;                /* The data structure        */ 
} ICCTAG_DATA_TYPE, * pICCTAG_DATA_TYPE;

/* The base date time number */
typedef struct _ICC_DATE_TIME_NUMBER
{
    L_IccUInt16Number uYear;
    L_IccUInt16Number uMonth;
    L_IccUInt16Number uDay;
    L_IccUInt16Number uHours;
    L_IccUInt16Number uMinutes;
    L_IccUInt16Number uSeconds;
}
ICC_DATE_TIME_NUMBER, * pICC_DATE_TIME_NUMBER;

/* dateTimeType */
typedef struct _ICCTAG_DATE_TIME_TYPE
{
   ICCTAG_BASE          tagBase;    /* Signature "dtim"       */
   ICC_DATE_TIME_NUMBER DateTime;   /* The DateTime structure */
} ICCTAG_DATE_TIME_TYPE, * pICCTAG_DATE_TIME_TYPE;

/* lut16Type */
typedef struct _ICCTAG_LUT16_TYPE
{
   ICCTAG_BASE tagBase; /* Signature "mft2"    */
   ICC_LUT16   Lut16;   /* The LUT16 structure */
} ICCTAG_LUT16_TYPE, * pICCTAG_LUT16_TYPE;

/* lut8Type */
typedef struct _ICCTAG_LUT8_TYPE
{
   ICCTAG_BASE tagBase; /* Signature "mft1"   */
   ICC_LUT8    Lut8;    /* The LUT8 structure */
} ICCTAG_LUT8_TYPE, * pICCTAG_LUT8_TYPE;

/* CLUT 16-bit Structure */
typedef struct __ICC_CLUT16
{
   L_IccUInt8Number    NumOfGridPoints[16];    /* Number of Grid Points in each dimension */
   L_IccUInt8Number    uPrecision;             /* Precision of data elements in bytes.    *
                                                * Either 01h or 02h                       */
   L_IccUInt8Number    uPad[3];                /* Reserved for Padding                    */
   L_IccUInt16Number * pData;                  /* CLUT Data Points                        */
} ICC_CLUT16, * pICC_CLUT16;

/* CLUT 8-bit Structure */
typedef struct __ICC_CLUT8
{
   L_IccUInt8Number   NumOfGridPoints[16];    /* Number of Grid Points in each dimension */
   L_IccUInt8Number   uPrecision;             /* Precision of data elements in bytes.    *
                                               * Either 01h or 02h                       */
   L_IccUInt8Number   uPad[3];                /* Reserved for Padding                    */
   L_IccUInt8Number * pData;                  /* CLUT Data Points                        */
} ICC_CLUT8, * pICC_CLUT8;

/* lutAtoBType and lutBtoAType */
typedef struct _ICCTAG_LUT_A2B_B2A_TYPE
{
   ICCTAG_BASE              tagBase;          /* Signature "mAB"            */
   L_IccUInt8Number         uInputChannels;   /* Number of input channels   */
   L_IccUInt8Number         uOutputChannels;  /* Number of output channels  */
   L_IccUInt8Number         uPad[2];          /* Must be set to Zero        */
   L_IccUInt32Number        uOffsetToCurveB;  /* Offset to first "B" Curve  */
   L_IccUInt32Number        uOffsetToMatrix;  /* Offset to Matrix           */
   L_IccUInt32Number        uOffsetToCurveM;  /* Offset to first "M" Curve  */
   L_IccUInt32Number        uOffsetToCLUT;    /* Offset to CLUT             */
   L_IccUInt32Number        uOffsetToCurveA;  /* Offset to first "A" Curve  */
   L_IccUInt8Number * pData;            /* Pointer to LUT Data        */
   L_UCHAR *          pCurveB;          /* Pointer to Curve B in Data */
   L_UCHAR *          pCurveM;          /* Pointer to Curve M in Data */
   L_UCHAR *          pCurveA;          /* Pointer to Curve A in Data */
   L_UCHAR *          pCLUT;            /* Pointer to CLUT in Data    */
   ICC_MATRIX               Matrix;           /* Pointer to Matrix in Data  */
} ICCTAG_LUT_A_TO_B_TYPE, * pICCTAG_LUT_A_TO_B_TYPE,
  ICCTAG_LUT_B_TO_A_TYPE, * pICCTAG_LUT_B_TO_A_TYPE;

/* measurementType */
typedef struct _ICCTAG_MEASUREMENT_TYPE
{
    ICCTAG_BASE      tagBase;        /* Signature, "meas" */
    ICC_MEASUREMENT  Measurement;    /* Measurement data  */
} ICCTAG_MEASUREMENT_TYPE, * pICCTAG_MEASUREMENT_TYPE;

/* multiLocalizedUnicodeType */
typedef struct _ICCTAG_MULTI_LOCALIZED_UNICODE_TYPE
{
   ICCTAG_BASE tagBase;                               /* Signature mluc                  */
   ICC_MULTI_LOCALIZED_UNICODE MultiLocalizedUnicode; /* MultiLocalizedUnicode structure */
} ICCTAG_MULTI_LOCALIZED_UNICODE_TYPE, * pICCTAG_MULTI_LOCALIZED_UNICODE_TYPE;

/* Profile description structure from corresponding profile's header */
typedef struct _ICCPROFILEDESC
{
   L_IccUInt32Number                   DevManufacturerSig;  /* Device Manufacturer signature    */
   L_IccUInt32Number                   DevModelSig;         /* Device Model Signature           */
   L_IccUInt8Number                    DevAttributes[8];    /* Device Attributes                */
   L_IccUInt32Number                   DevTechInfo;         /* Device Technology Information    */
   ICCTAG_MULTI_LOCALIZED_UNICODE_TYPE DevManufacturerDesc; /* Device Manufacturer Description  *
                                                             * (deviceMfgDescTag)               */
   ICCTAG_MULTI_LOCALIZED_UNICODE_TYPE DevModelDesc;        /* Device Model Description         *
                                                             * (deviceModelDescTag)             */
} ICC_PROFILE_DESC, * pICC_PROFILE_DESC;

/* Profile sequence description data */
typedef struct _ICCPROFILESEQDESC
{
    L_IccUInt32Number uCount;           /* Number of descriptions        */
    pICC_PROFILE_DESC pProfDescription; /* Profile description structure */
} ICC_PROFILE_SEQ_DESC, * pICC_PROFILE_SEQ_DESC;

/* Named color type */
/* icNamedColor2Type, replaces icNamedColorType */
typedef struct _ICCTAG_NAMED_COLOR2_TYPE
{
    ICCTAG_BASE      tagBase;    /* Signature, "ncl2" */
    ICC_NAMED_COLOR2 NColor;     /* Named color data  */
} ICCTAG_NAMED_COLOR2_TYPE, * pICCTAG_NAMED_COLOR2_TYPE;

/* parametricCurveType */
typedef struct _ICCTAG_PARAMETRIC_CURVE_TYPE
{
   ICCTAG_BASE          tagBase;         /* Signature "para"           */
   ICC_PARAMETRIC_CURVE ParametricCurve; /* Parametric curve structure */
} ICCTAG_PARAMETRIC_CURVE_TYPE, * pICCTAG_PARAMETRIC_CURVE_TYPE;

/* profileSequenceDescType */
typedef struct _ICCTAG_PROFILE_SEQ_DESC_TYPE
{
    ICCTAG_BASE          tagBase;/* Signature, "pseq"   */
    ICC_PROFILE_SEQ_DESC Desc;   /* The seq description */
} ICCTAG_PROFILE_SEQ_DESC_TYPE, * pICCTAG_PROFILE_SEQ_DESC_TYPE;

/* responseCurveSet16Type */
typedef struct _ICCTAG_RESPONSE_CURVE_SET16_TYPE
{
   ICCTAG_BASE        tagBase;       /* Signature "rcs2"               */
   ICC_RESPONSE_CURVE ResponseCurve; /* Response curve set16 structure */
} ICCTAG_RESPONSE_CURVE_SET16_TYPE, * pICCTAG_RESPONSE_CURVE_SET16_TYPE;

/* s15Fixed16ArrayType */
typedef struct _ICCTAG_S15_FIXED16_ARRAY_TYPE
{
    ICCTAG_BASE                   tagBase;            /* Signature, "sf32"  */
    L_IccS15Fixed16Number * pData;              /* Array of values    */
    L_UINT                        uDataElementsCount; /* Number of Elements */
} ICCTAG_S15_FIXED16_ARRAY_TYPE, * pICCTAG_S15_FIXED16_ARRAY_TYPE;

/* signatureType */
typedef struct _ICCTAG_SIGNATURE_TYPE
{
    ICCTAG_BASE            tagBase;       /* Signature, "sig"   */
    L_UINT32               uSignature;    /* The signature data */
} ICCTAG_SIGNATURE_TYPE, * pICCTAG_SIGNATURE_TYPE;

/* textType */
typedef struct _ICCTAG_TEXT_TYPE
{
    ICCTAG_BASE            tagBase;    /* Signature, "text"       */
    L_Icc7BitAscii * pTextData;  /* Descriptions follow     */
} ICCTAG_TEXT_TYPE, * pICCTAG_TEXT_TYPE;

/* u16Fixed16ArrayType */
typedef struct _ICCTAG_U16_FIXED16_ARRAY_TYPE
{
    ICCTAG_BASE                   tagBase;            /* Signature, "uf32"        */
    L_IccU16Fixed16Number * pData;              /* Variable array of values */
    L_UINT                        uDataElementsCount; /* Number of Data Elements  */
} ICCTAG_U16_FIXED16_ARRAY_TYPE, * pICCTAG_U16_FIXED16_ARRAY_TYPE;

/* uInt16ArrayType */
typedef struct _ICCTAG_UINT16_ARRAY_TYPE
{
    ICCTAG_BASE               tagBase;            /* Signature, "ui16"        */
    L_IccUInt16Number * pData;              /* Variable array of values */
    L_UINT                    uDataElementsCount; /* Number of Data Elements  */
} ICCTAG_UINT16_ARRAY_TYPE, * pICCTAG_UINT16_ARRAY_TYPE;

/* uInt32ArrayType */
typedef struct _ICCTAG_UINT32_ARRAY_TYPE
{
    ICCTAG_BASE               tagBase;            /* Signature, "ui32"        */
    L_IccUInt32Number * pData;              /* Variable array of values */
    L_UINT                    uDataElementsCount; /* Number of Data Elements  */
} ICCTAG_UINT32_ARRAY_TYPE, * pICCTAG_UINT32_ARRAY_TYPE;

/* uInt64ArrayType */
typedef struct _ICCTAG_UINT64_ARRAY_TYPE
{
    ICCTAG_BASE               tagBase;            /* Signature, "ui64"        */
    L_IccUInt64Number * pData;              /* Variable array of values */
    L_UINT                    uDataElementsCount; /* Number of Data Elements  */
} ICCTAG_UINT64_ARRAY_TYPE, * pICCTAG_UINT64_ARRAY_TYPE;

/* uInt8ArrayType */
typedef struct _ICCTAG_UINT8_ARRAY_TYPE
{
    ICCTAG_BASE               tagBase;            /* Signature, "ui08"        */
    L_IccUInt8Number *  pData;              /* Variable array of values */
    L_UINT                    uDataElementsCount; /* Number of Data Elements  */
} ICCTAG_UINT8_ARRAY_TYPE, * pICCTAG_UINT8_ARRAY_TYPE;

/* viewingConditionsType */
typedef struct _ICCTAG_VIEW_COND_TYPE
{
    ICCTAG_BASE   tagBase;           /* Signature, "view"  */
    ICC_VIEW_COND ViewCondition;  /* Viewing conditions */
} ICCTAG_VIEW_COND_TYPE, * pICCTAG_VIEW_COND_TYPE;

/* XYZType */
typedef struct _ICCTAG_XYZ_TYPE
{
    ICCTAG_BASE     tagBase;        /* Signature, "XYZ"           */
    pICC_XYZ_NUMBER pXYZNumData;    /* Variable array of XYZ nums */
    L_UINT          uXYZNumCount;   /* Number of Data Elements    */
} ICCTAG_XYZ_TYPE, * pICCTAG_XYZ_TYPE;

/* Unknown Tag Type */
typedef struct _ICCTAG_UNKNOWN_TYPE
{
   ICCTAG_BASE            tagBase;     /* Hexadecimal Signature Value   */
   L_Icc7BitAscii * pData;       /* Data stored as it is          */
   L_UINT                 uDataSize;   /* Size of Data                  */
} ICCTAG_UNKNOWN_TYPE, * pICCTAG_UNKNOWN_TYPE;

/* A Tag */
typedef struct _ICCTAG
{
    L_UINT32          uSig;     /* The tag signature        */
    L_IccUInt32Number uOffset;  /* Start of tag relative to
                                 * start of header, Spec 
                                 * Clause 5                 */
    L_IccUInt32Number uSize;    /* Size in bytes            */
}
ICCTAG, * pICCTAG;

/* A Structure that may be used independently for a list of tags */
typedef struct _ICCTAG_LIST
{
    L_IccUInt32Number uTagCount;      /* Num tags in the profile */
    pICCTAG           pTags;          /* Variable array of tags  */
}
ICCTAG_LIST, * pICCTAG_LIST;

/* Profile Header */
typedef struct _ICCHEADER
{
   L_IccUInt32Number       uSize;               /* Profile size in bytes      */
   L_IccSignature          nCmmID;              /* CMM for Profile            */
   L_IccUInt32Number       uVersion;            /* Profile Format Version     */
   L_UINT32                uDeviceClass;        /* Type of Profile            */
   L_UINT32                uColorSpace;         /* Color Space of Data        */
   L_UINT32                uPCS;                /* Profile Connection Space   */
   ICC_DATE_TIME_NUMBER    DateTime;            /* Date and Time              */
   L_IccSignature          nProfileSignature;   /* Profile File Sig."acsp"    */
   L_UINT32                uPlatform;           /* Primary Platform           */
   L_IccUInt32Number       uFlags;              /* Profile Flags              */
   L_IccSignature          nManufacturer;       /* Device Manufacturer        */
   L_IccUInt32Number       uModel;              /* Device Model               */
   L_IccUInt64Number       uAttributes;         /* Device Attributes          */
   L_IccUInt32Number       uRenderingIntent;    /* Rendering Intent           */
   ICC_XYZ_NUMBER          Illuminant;          /* Profile Illuminant         */
   L_IccSignature          nCreator;            /* Profile Creator            */
   L_IccUInt8Number        uProfileID[16];      /* Profile ID                 */
   L_IccUInt8Number        uReserved[28];       /* Reserved Fields for Future */
}
ICCHEADER, * pICCHEADER;

/* ICC Profile */
typedef struct _ICCPROFILEEXT
{
   L_UINT          uStructSize;  /* Size of ICC Profile structure    */
   L_SIZE_T        uDataSize;    /* Size of data pointed to by pData */
   L_SIZE_T        uTagDataSize; /* Size of Tag Data Elements so far */
   pICCHEADER      pIccHeader;   /* ICC Profile Header               */
   ICCTAG_LIST     tagList;      /* Tag List                         */
   L_UCHAR * pTagData;     /* Pointer to Tag Data Elements     */
   L_UCHAR * pData;        /* Pointer to whole ICC Profile - this variable is kept *
                                  * to ensure compatibility with old version of ICC      */
}
ICCPROFILEEXT, * pICCPROFILEEXT;

/****************************************************************
   Function prototypes
****************************************************************/
#if !defined(FOR_MANAGED) || defined(FOR_MANAGED_CLR)

L_LTCLR_API L_INT EXT_FUNCTION L_ClrInitA(
   L_HANDLE *pClrHandle,
   L_INT nSrcFormat,
   L_INT nDstFormat,
   LPCONVERSION_PARAMSA pParams);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrSetConversionParamsA(
   L_HANDLE ClrHandle,
   LPCONVERSION_PARAMSA pParams);

#if defined(FOR_UNICODE)
L_LTCLR_API L_INT EXT_FUNCTION L_ClrInit(
   L_HANDLE *pClrHandle,
   L_INT nSrcFormat,
   L_INT nDstFormat,
   LPCONVERSION_PARAMS pParams);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrSetConversionParams(
   L_HANDLE ClrHandle,
   LPCONVERSION_PARAMS pParams);
#else
#define L_ClrInit L_ClrInitA
#define L_ClrSetConversionParams L_ClrSetConversionParamsA
#endif // #if defined(FOR_UNICODE)

#if defined(LEADTOOLS_V22_OR_LATER)
/* Convert data contained into pSrcBitmap and store the output in pDstBitmap.
   If pDstBitmap == NULL or == pSrcBitmap, then the conversion will be in place and pSrcBitmap will contain the output.
   pSrcBitmap should always be != NULL.

   Note that this conversion will have good results only if ClrHandle is set up to convert BGR->BGR. 
   Non-BGR conversion types might not have the desired effect.
*/
L_LTCLR_API L_INT EXT_FUNCTION L_ClrConvertBitmap(L_HANDLE ClrHandle, pBITMAPHANDLE pSrcBitmap, pBITMAPHANDLE pDstBitmap);
#endif // #if defined(LEADTOOLS_V22_OR_LATER)

L_LTCLR_API L_INT EXT_FUNCTION L_ClrConvertDirect(
   L_INT nSrcFormat,
   L_INT nDstFormat,
   L_UCHAR* pSrcBuf,
   L_UCHAR* pDstBuf,
   L_INT nWidth,
   L_INT nHeight,
   L_INT nInAlign,
   L_INT nOutAlign);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrConvertDirectToBitmap(
   L_INT nSrcFormat,
   L_INT nDstFormat,
   L_UCHAR* pSrcBuf,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nWidth,
   L_INT nHeight,
   L_INT nInAlign,
   L_INT nOutAlign);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrConvert(
   L_HANDLE ClrHandle,
   L_UCHAR* pSrc,
   L_UCHAR* pDst,
   L_INT nWidth,
   L_INT nHeight,
   L_INT nInAlign,
   L_INT nOutAlign);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrConvertToBitmap(
   L_HANDLE ClrHandle,
   L_UCHAR* pSrcBuf,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_INT nWidth,
   L_INT nHeight,
   L_INT nInAlign,
   L_INT nOutAlign);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrFree(
   L_HANDLE ClrHandle);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrIsValid(
   L_HANDLE ClrHandle);

L_LTCLR_API L_INT EXT_FUNCTION L_ClrDlgA(
   L_INT  nDlg,
   L_HANDLE hWnd,
   L_HANDLE *pClrHandle,
   LPCONVERSION_PARAMSA pParams);

#if defined(FOR_UNICODE)
L_LTCLR_API L_INT EXT_FUNCTION L_ClrDlg(
   L_INT  nDlg,
   L_HANDLE hWnd,
   L_HANDLE *pClrHandle,
   LPCONVERSION_PARAMS pParams);
#else
#define L_ClrDlg L_ClrDlgA
#endif // #if defined(FOR_UNICODE)

L_LTCLR_API L_INT EXT_FUNCTION L_GetParametricCurveNumberOfParameters(ICCFUNCTIONTYPE enFunctionType);

L_LTCLR_API L_INT EXT_FUNCTION L_FillICCProfileStructure(pICCPROFILEEXT pICCProfile,
                                             L_UCHAR     * pData,
                                             L_SIZE_T      uDataSize);

L_LTCLR_API L_INT EXT_FUNCTION L_FillICCProfileFromICCFileA(L_CHAR * pszFileName,
                                               pICCPROFILEEXT  pICCProfile);

#if defined(FOR_UNICODE)
L_LTCLR_API L_INT EXT_FUNCTION L_FillICCProfileFromICCFile(L_TCHAR * pszFileName,
                                               pICCPROFILEEXT  pICCProfile);
#else
#define L_FillICCProfileFromICCFile L_FillICCProfileFromICCFileA
#endif // #if defined(FOR_UNICODE)

L_LTCLR_API L_INT EXT_FUNCTION L_InitICCProfile(pICCPROFILEEXT pICCProfile, L_SIZE_T uStructSize);

L_LTCLR_API L_VOID EXT_FUNCTION L_FreeICCProfile(pICCPROFILEEXT pICCProfile);

L_LTCLR_API L_INT EXT_FUNCTION L_InitICCHeader(pICCPROFILEEXT pICCProfile);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCCMMType(pICCPROFILEEXT pICCProfile, L_IccInt32Number nCMMType);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCDeviceClass(pICCPROFILEEXT pICCProfile, ICCPROFILECLASS uDevClassSig);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCColorSpace(pICCPROFILEEXT pICCProfile, ICCCOLORSPACE uColorSpace);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCConnectionSpace(pICCPROFILEEXT pICCProfile, ICCCOLORSPACE uPCS);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCPrimaryPlatform(pICCPROFILEEXT pICCProfile, ICCPLATFORMSIGNATURE uPrimPlatform);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCFlags(pICCPROFILEEXT pICCProfile, L_IccUInt32Number uFlags);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCDevManufacturer(pICCPROFILEEXT pICCProfile, L_IccInt32Number nDevManufacturer);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCDevModel(pICCPROFILEEXT pICCProfile, L_IccUInt32Number uDevModel);
                   
L_LTCLR_API L_INT EXT_FUNCTION L_SetICCDeviceAttributes(pICCPROFILEEXT pICCProfile, L_IccUInt64Number uAttributes);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCRenderingIntent(pICCPROFILEEXT pICCProfile, ICCRENDERINGINTENT uRenderingIntent);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCCreator(pICCPROFILEEXT pICCProfile, L_IccInt32Number nCreator);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCDateTime(pICCPROFILEEXT pICCProfile, pICC_DATE_TIME_NUMBER pTime);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCTagData(pICCPROFILEEXT  pICCProfile, 
                                   L_UCHAR * pTagData, 
                                   L_UINT          uTagSig, 
                                   L_UINT          uTagTypeSig);

L_LTCLR_API L_INT EXT_FUNCTION L_GetICCTagData(pICCPROFILEEXT     pICCProfile, 
                                   L_UCHAR *    pTagData, 
                                   L_UINT32           uTagSignature);

L_LTCLR_API L_INT EXT_FUNCTION L_CreateICCTagData(L_UCHAR * pDestTagData, 
                                      L_UCHAR * pSrcTagData, 
                                      L_UINT32        uTagTypeSig);

L_LTCLR_API L_INT EXT_FUNCTION L_DeleteICCTag(pICCPROFILEEXT pICCProfile, L_UINT32 uTagSig, L_UCHAR * pTag);

L_LTCLR_API L_INT EXT_FUNCTION L_GenerateICCFileA(pICCPROFILEEXT pICCProfile, L_CHAR * pszFileName);

#if defined(FOR_UNICODE)
L_LTCLR_API L_INT EXT_FUNCTION L_GenerateICCFile(pICCPROFILEEXT pICCProfile, L_TCHAR * pszFileName);
#else
#define L_GenerateICCFile L_GenerateICCFileA
#endif //#if defined(FOR_UNICODE)

L_LTCLR_API L_UINT32 EXT_FUNCTION L_DoubleTo2bFixed2bNumber(L_DOUBLE dNumber);

L_LTCLR_API L_DOUBLE EXT_FUNCTION L_2bFixed2bNumberToDouble(L_UINT32 uNumber);

L_LTCLR_API L_UINT16 EXT_FUNCTION L_DoubleToU8Fixed8Number(L_DOUBLE dNumber);

L_LTCLR_API L_DOUBLE EXT_FUNCTION L_U8Fixed8NumberToDouble(L_UINT16 uNumber);

L_LTCLR_API L_INT EXT_FUNCTION L_GenerateICCPointer(pICCPROFILEEXT pICCProfile);

L_LTCLR_API L_UINT32 EXT_FUNCTION L_GetICCTagTypeSig(pICCPROFILEEXT pICCProfile, L_UINT32 uTagSig);

L_LTCLR_API L_VOID EXT_FUNCTION L_FreeICCTagType(L_UCHAR * pTagType, L_UINT32 uTagTypeSig);

L_LTCLR_API L_INT EXT_FUNCTION L_ConvertCLUTToBuffer(L_UCHAR  * pData, L_VOID * pIccCLUT, L_INT nPrecision, L_SSIZE_T znDataSize);

L_LTCLR_API L_INT EXT_FUNCTION L_ConvertCurveTypeToBuffer(L_UCHAR  * pData, pICCTAG_CURVE_TYPE pIccTagCurveType);

L_LTCLR_API L_INT EXT_FUNCTION L_ConvertParametricCurveTypeToBuffer(L_UCHAR  * pData, pICCTAG_PARAMETRIC_CURVE_TYPE pIccTagParametricCurveType);

L_LTCLR_API L_INT EXT_FUNCTION L_SetICCProfileId(pICCPROFILEEXT pICCProfile);

L_LTCLR_API L_INT EXT_FUNCTION L_LoadICCProfileA(L_CHAR * pszFilename, pICCPROFILEEXT pICCProfile, pLOADFILEOPTION pLoadOptions);

L_LTCLR_API L_INT EXT_FUNCTION L_SaveICCProfileA(L_CHAR * pszFilename, pICCPROFILEEXT pICCProfile, pSAVEFILEOPTIONA pSaveOptions);

L_LTCLR_API L_BOOL EXT_FUNCTION L_HasICCProfileA(L_CHAR*  pszFilename, pLOADFILEOPTION pLoadOptions);

#if defined(FOR_UNICODE)
L_LTCLR_API L_INT EXT_FUNCTION L_LoadICCProfile(L_TCHAR * pszFilename, pICCPROFILEEXT pICCProfile, pLOADFILEOPTION pLoadOptions);

L_LTCLR_API L_INT EXT_FUNCTION L_SaveICCProfile(L_TCHAR*  pszFilename, pICCPROFILEEXT  pICCProfile, pSAVEFILEOPTION pSaveOptions);

L_LTCLR_API L_BOOL EXT_FUNCTION L_HasICCProfile(L_TCHAR*  pszFilename, pLOADFILEOPTION pLoadOptions);
#else
#define L_LoadICCProfile L_LoadICCProfileA
#define L_SaveICCProfile L_SaveICCProfileA
#define L_HasICCProfile L_HasICCProfileA
#endif // #if defined(FOR_UNICODE)
#endif // #if !defined(FOR_MANAGED) || defined(FOR_MANAGED_CLR)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTCLR_H)

