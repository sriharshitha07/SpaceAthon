//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTDOCWRT___H)
#define LTDOCWRT___H

#include "lttyp.h"
#define L_LTDOCWRT_API LT_EXPORTED

#include "ltann.h"

#include "ltfil.h"   // for DOCWRTFORMAT

#define L_HEADER_ENTRY
#include "ltpck.h"

typedef HANDLE DOCUMENTWRITER_HANDLE;

typedef  enum _DOCWRTPAGETYPE
{
   DOCWRTPAGETYPE_EMF,
   DOCWRTPAGETYPE_SVG,
   DOCWRTPAGETYPE_RASTER,
   DOCWRTPAGETYPE_EMPTY,
}
DOCWRTPAGETYPE, *pDOCWRTPAGETYPE;

typedef  enum _DOCWRTTEXTMODE
{
   DOCWRTTEXTMODE_AUTO,
   DOCWRTTEXTMODE_NONFRAMED,
   DOCWRTTEXTMODE_FRAMED,
}
DOCWRTTEXTMODE, *pDOCWRTTEXTMODE;


typedef struct _DOCWRTPAGE
{
   L_UINT            uStructSize;
   L_UINT            uFlags;
}
DOCWRTPAGE, *pDOCWRTPAGE;

typedef struct _DOCWRTEMFPAGE
{
   DOCWRTPAGE     Page;
   HENHMETAFILE   hEmf;
   pBITMAPHANDLE  pOverlayBitmap; //for Pdf file only
   L_DOUBLE       *pdwTextScale; //for Pdf Image over text only
   HANNOBJECT     hAnnObject; //handle to the root annotation
   L_VOID         *pData; //reserved for future use
}
DOCWRTEMFPAGE, *pDOCWRTEMFPAGE;

typedef struct _DOCWRTSVGPAGE
{
   DOCWRTPAGE     Page;
   L_HANDLE       hSvgHandle;
   pBITMAPHANDLE  pOverlayBitmap; //for Pdf file only
   L_DOUBLE       dPageWidth;
   L_DOUBLE       dPageHeight;
   HANNOBJECT     hAnnObject; //handle to the root annotation
}
DOCWRTSVGPAGE, *pDOCWRTSVGPAGE;

typedef struct _DOCWRTEMPTYPAGE
{
   DOCWRTPAGE     Page;
   L_DOUBLE       dPageWidth;
   L_DOUBLE       dPageHeight;
   L_INT          nXResolution;
   L_INT          nYResolution;
}
DOCWRTEMPTYPAGE, *pDOCWRTEMPTYPAGE;

typedef struct _DOCWRTRASTERPAGE
{
   DOCWRTPAGE     Page;
   pBITMAPHANDLE  pOverlayBitmap; //optional, for Pdf file only
}
DOCWRTRASTERPAGE, *pDOCWRTRASTERPAGE;

typedef enum _DOCWRTPDFPROFILE
{
   DOCWRTPDFPROFILE_PDF = 0, //default, save version 1.4 Pdf document
   DOCWRTPDFPROFILE_PDFA,    //save PdfA document
   DOCWRTPDFPROFILE_PDF12,   //save version 1.2 Pdf document
   DOCWRTPDFPROFILE_PDF13,   //save version 1.3 Pdf document 
   DOCWRTPDFPROFILE_PDF15,   //save version 1.5 Pdf document
   DOCWRTPDFPROFILE_PDF16    //save version 1.6 Pdf document
}
DOCWRTPDFPROFILE, *pDOCWRTPDFPROFILE;

typedef enum _DOCWRTPDFENCRYPTIONMODE
{
   DOCWRTPDFENCRYPTIONMODE_RC40BIT = 0,
   DOCWRTPDFENCRYPTIONMODE_RC128BIT,
}
DOCWRTPDFENCRYPTIONMODE, *pDOCWRTPDFENCRYPTIONMODE;

typedef enum _DOCWRTTXTTYPE
{
   DOCWRTTXTTYPE_ANSI = 0,
   DOCWRTTXTTYPE_UNICODE,
   DOCWRTTXTTYPE_UNICODE_BIGENDIAN,
   DOCWRTTXTTYPE_UTF8,
}
DOCWRTTXTTYPE, *pDOCWRTTXTTYPE;

typedef enum _DOCWRTFONTEMBED
{
   DOCWRTFONTEMBED_NOEMBED = 0,     //Do not embed fonts
   DOCWRTFONTEMBED_AUTO,            // Automatic embedding
   DOCWRTFONTEMBED_FORCE,           //force embedding for no-embedding license fonts
   DOCWRTFONTEMBED_ALL              // all fonts in the document should be embedded
}
DOCWRTFONTEMBED, *pDOCWRTFONTEMBED;

typedef enum _DOCWRTHTMTYPE
{
   DOCWRTHTMTYPE_IECOMPATIBLE = 0,     //IE5 and above
   DOCWRTHTMTYPE_NETSCAPEOMPATIBLE,    //Netscape 4.6, 6.0+
   DOCWRTHTMTYPE_IENETSCAPEOMPATIBLE   //IE5 and above, Netscape 4.6, 6.0+
}
DOCWRTHTMTYPE, *pDOCWRTHTMTYPE;

typedef enum _DOCWRTPAGERESTRICTION
{
   DOCWRTPAGERESTRICTION_DEFAULT = 0,
   DOCWRTPAGERESTRICTION_RELAXED,
}
DOCWRTPAGERESTRICTION, *pDOCWRTPAGERESTRICTION;

typedef enum _DOCWRTPAGEMODETYPE
{
   DOCWRTPAGEMODETYPE_PAGEONLY = 0,       //default, Neither document outline nor thumbnail images visible   
   DOCWRTPAGEMODETYPE_BOOKMARKSANDPAGE,   //document bookmarks visible
   DOCWRTPAGEMODETYPE_THUMBNAILANDPAGE,   //Thumbnail images visible
   DOCWRTPAGEMODETYPE_FULLSCREEN,         //full-screen mode, with no menu bar, window controls, or any other window visible
   DOCWRTPAGEMODETYPE_LAYERANDPAGE,       //layer panel visible
   DOCWRTPAGEMODETYPE_ATTACHMENTSANDPAGE, //attachments panel visible
}
DOCWRTPAGEMODETYPE, *pDOCWRTPAGEMODETYPE;

typedef enum _DOCWRTPAGELAYOUTTYPE
{
   DOCWRTPAGELAYOUTTYPE_SINGLEPAGEDISPLAY = 0,   //Default, Display one page at a time
   DOCWRTPAGELAYOUTTYPE_ONECOLUMNDISPLAY,        //Display the pages in one column
   DOCWRTPAGELAYOUTTYPE_TWOCOLUMNLEFTDISPLAY,    //Display the pages in two columns, with odd-numbered pages on the left
   DOCWRTPAGELAYOUTTYPE_TWOCOLUMNRIGHTDISPLAY,   //Display the pages in two columns, with odd-numbered pages on the right
   DOCWRTPAGELAYOUTTYPE_TWOPAGELEFT,             //Display the pages two at a time, with odd-numbered pages on the left
   DOCWRTPAGELAYOUTTYPE_TWOPAGERIGHT,            //Display the pages two at a time, with odd-numbered pages on the right
}
DOCWRTPAGELAYOUTTYPE, *pDOCWRTPAGELAYOUTTYPE;

typedef enum _DOCWRTPAGEFITTYPE
{
   DOCWRTPAGEFITTYPE_DEFAULT          = 0,    //any thing else below
   DOCWRTPAGEFITTYPE_FITWIDTH            ,    //FitH
   DOCWRTPAGEFITTYPE_FITHEIGHT           ,    //FitV
   DOCWRTPAGEFITTYPE_FITWIDTHBOUNDS      ,    //FitBH
   DOCWRTPAGEFITTYPE_FITHEIGHTBOUNDS     ,    //FitBV
   DOCWRTPAGEFITTYPE_FITBOUNDS           ,    //FitB
}
DOCWRTPAGEFITTYPE, *pDOCWRTPAGEFITTYPE;

typedef enum _DOCWRTALTOXMLMEASUREMENTUNIT
{
   DOCWRTALTOXMLMEASUREMENTUNIT_MM10    = 0,
   DOCWRTALTOXMLMEASUREMENTUNIT_INCH1200,
   DOCWRTALTOXMLMEASUREMENTUNIT_DPI,
   DOCWRTALTOXMLMEASUREMENTUNIT_PIXEL,
}
DOCWRTALTOXMLMEASUREMENTUNIT, *pDOCWRTALTOXMLMEASUREMENTUNIT;

typedef enum _DOCWRTLTDDOCUMENTTYPE
{
   DOCWRTLTDDOCUMENTTYPE_OCR    = 0,
   DOCWRTLTDDOCUMENTTYPE_SVG,
   DOCWRTLTDDOCUMENTTYPE_RASTER,
   DOCWRTLTDDOCUMENTTYPE_MIXED,
}
DOCWRTLTDDOCUMENTTYPE, *pDOCWRTLTDDOCUMENTTYPE;

//Html uFontFlags
#define DOCWRT_FONT_FLAGS_DEFAULT      0x00 //default WOFF1
#define DOCWRT_FONT_FLAGS_WOFF1        0x01
#define DOCWRT_FONT_FLAGS_EOT          0x02
#define DOCWRT_FONT_FLAGS_TTF          0x04
#define DOCWRT_FONT_FLAGS_WOFF2        0x08


typedef struct _DOCWRTOPTIONS
{
   L_UINT                uStructSize;            // Structure size
   DOCWRTPAGERESTRICTION PageRestriction;        // Page restriction      
   L_DOUBLE              dEmptyPageWidth;        // Empty page width in inches
   L_DOUBLE              dEmptyPageHeight;       // Empty page height in inches
   L_INT                 nEmptyPageResolution;   // Empty page resolution
   L_BOOL                bMaintainAspectRatio;   // Maintain the aspect ratio of original emf file.
   L_INT                 nDocumentResolution;    // Document resolution, 0 means keep the original emf resolution
}
DOCWRTOPTIONS, *pDOCWRTOPTIONS;

typedef struct _DOCWRTLTDOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
}
DOCWRTLTDOPTIONS, *pDOCWRTLTDOPTIONS;

typedef struct _DOCWRTEMFOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
}
DOCWRTEMFOPTIONS, *pDOCWRTEMFOPTIONS;

typedef struct _DOCWRTXPSOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
   L_UINT32          uFlags;              // Flags - reserved
}
DOCWRTXPSOPTIONS, *pDOCWRTXPSOPTIONS;

typedef struct _DOCWRTDOCXOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   DOCWRTTEXTMODE     TextMode;           //Auto, NonFramed or Framed
   L_UINT32          uFlags;              // Flags - reserved
}
DOCWRTDOCXOPTIONS, *pDOCWRTDOCXOPTIONS;

typedef struct _DOCWRTTXTOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   DOCWRTTXTTYPE     Type;                // Text file type
   L_BOOL            bAddPageNumber;      // TRUE means to add page number to saved file
   L_BOOL            bAddPageBreak;       // TRUE means to add page break at end of each page
   L_BOOL            bFormatted;          // If TRUE the saved file will maintain the same format for original document
   L_UINT32          uFlags;              // Flags
}
DOCWRTTXTOPTIONS, *pDOCWRTTXTOPTIONS;

typedef struct _DOCWRTXLSOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
   L_UINT32          uFlags;              // Flags - reserved
}
DOCWRTXLSOPTIONS, *pDOCWRTXLSOPTIONS;

typedef enum _DOCWRT1BITIMGCOMP
{
   DOCWRT1BITIMGCOMP_FLATE = 0,
   DOCWRT1BITIMGCOMP_FAX_G31D,
   DOCWRT1BITIMGCOMP_FAX_G32D,
   DOCWRT1BITIMGCOMP_FAX_G4,
   DOCWRT1BITIMGCOMP_LZW,
   DOCWRT1BITIMGCOMP_JBIG2
}
DOCWRT1BITIMGCOMP,*pDOCWRT1BITIMGCOMP;

typedef enum _DOCWRTCOLORIMGCOMP
{
   DOCWRTCOLORIMGCOMP_FLATE_JPEG = 0, //If chosen JPEG will be valid for (saving images more than 8PP or 8BPP gray images), else flate compression will be used
   DOCWRTCOLORIMGCOMP_LZW_JPEG, //If chosen JPEG will be valid for (saving images more than 8PP or 8BPP gray images), else LZW compression will be used
   DOCWRTCOLORIMGCOMP_FLATE,    //Flate compression will be used for all images
   DOCWRTCOLORIMGCOMP_LZW,       //LZW compression will be used for all images 
   DOCWRTCOLORIMGCOMP_JPEG,      //JPEG compression will be used for all images
   DOCWRTCOLORIMGCOMP_FLATE_JPX, //If chosen JPX will be valid for (saving images more than 8PP or 8BPP gray images), else flate compression will be used
   DOCWRTCOLORIMGCOMP_LZW_JPX, //If chosen JPEG will be valid for (saving images more than 8PP or 8BPP gray images), else LZW compression will be used
   DOCWRTCOLORIMGCOMP_JPX       //JPX compression will be used for all images     
}
DOCWRTCOLORIMGCOMP,*pDOCWRTCOLORIMGCOMP;

typedef struct _DOCWRTPDFAUTOBOOKMARK
{
   L_UINT     uStructSize;  // Structure size   
   L_BOOL     bUseStyles;  //check for bBold & bItalic      
   L_BOOL     bBold;
   L_BOOL     bItalic;
   L_DOUBLE   dFontHeight;
   L_CHAR     szFaceName[ LF_FACESIZE ];
}
DOCWRTPDFAUTOBOOKMARK,*pDOCWRTPDFAUTOBOOKMARK;

typedef struct _DOCWRTPDFCUSTOMBOOKMARK
{
   L_UINT      uStructSize;   // Structure size   
   L_INT       nLevelNumber;
   L_INT       nPageNumber;
   L_DOUBLE    dXCoordinate;
   L_DOUBLE    dYCoordinate;
   L_TCHAR     szBookmarkName[100];
}
DOCWRTPDFCUSTOMBOOKMARK, *pDOCWRTPDFCUSTOMBOOKMARK;

typedef struct _DOCWRTPDFBOOKMARK
{
   L_UINT                     uStructSize;     // Structure size
   pDOCWRTPDFAUTOBOOKMARK     pAutoBookmark;
   pDOCWRTPDFCUSTOMBOOKMARK   pCustomBookmark;
   L_BOOL                     bAutoBookmark;
   L_INT                      nLevelsCount;
   L_INT                      nCustomBookmarksCount;  
}
DOCWRTPDFBOOKMARK,*pDOCWRTPDFBOOKMARK;

//Only in Pdf, may be used for other formats in future that is why it in uFlags of DOCWRTPDFOPTIONS
#define DOCWRT_IMAGEOVERTEXT_SIZE_NONE          0x000 //default
#define DOCWRT_IMAGEOVERTEXT_SIZE_HALF          0x001 
#define DOCWRT_IMAGEOVERTEXT_SIZE_QUARTER       0x002 
#define DOCWRT_IMAGEOVERTEXT_MODE_NONE          0x004
#define DOCWRT_IMAGEOVERTEXT_MODE_STRICT        0x008 //default
#define DOCWRT_IMAGEOVERTEXT_MODE_RELAXED       0x010

//Drop objects flags 
#define DOCWRTDROPOBJECTSMODE_NONE              0x00 // Default behavior, all text, images and shapes are added to the final document
#define DOCWRTDROPOBJECTSMODE_DROPTEXT          0x040 // Drop text from final document
#define DOCWRTDROPOBJECTSMODE_DROPIMAGES        0x080 // Drop images from final document
#define DOCWRTDROPOBJECTSMODE_DROPSHAPES        0x0100 // Drop shapes from final document



typedef struct _DOCWRTPDFOPTIONS
{
   DOCWRTOPTIONS           Options;            // Options
   DOCWRTPDFPROFILE        PdfProfile;         // Pdf profile mode
   DOCWRTFONTEMBED         FontEmbed;          // Font Embedding mode
   L_BOOL                  bImageOverText;     // Image over text flag
   L_UINT32                uFlags;             // Flags
   L_BOOL                  bLinearized;        // Linearization flag, for fast web view
   L_TCHAR                *pwszTitle;          // Pdf document title
   L_TCHAR                *pwszSubject;        // Pdf document subject
   L_TCHAR                *pwszKeywords;       // Pdf document keywords
   L_TCHAR                *pwszAuthor;         // Pdf document author
   L_BOOL                  bProtected;         // TRUE means the document will be saved with password protection
   L_CHAR                 *pszUserPassword;    // User password
   L_CHAR                 *pszOwnerPassword;   // Owner password
   DOCWRTPDFENCRYPTIONMODE EncryptionMode;
   L_BOOL                  bPrintEnabled;
   L_BOOL                  bHighQualityPrintEnabled;
   L_BOOL                  bCopyEnabled;
   L_BOOL                  bEditEnabled;
   L_BOOL                  bAnnotationsEnabled;
   L_BOOL                  bAssemblyEnabled;
   DOCWRT1BITIMGCOMP       OneBitCompression;
   DOCWRTCOLORIMGCOMP      ColorImgCompression;
   L_INT                   nQualityFactor;
   DOCWRTPDFBOOKMARK       PdfBookmark;
   DOCWRTPAGEFITTYPE      PageFitType;
   DOCWRTPAGEMODETYPE     PageModeType;
   DOCWRTPAGELAYOUTTYPE   PageLayoutType;
   L_INT                  nInitialPage;
   L_DOUBLE               dZoomPercent;
   L_DOUBLE               dXCoordinate;
   L_DOUBLE               dYCoordinate;
   L_BOOL                 bHideToolbar;
   L_BOOL                 bHideMenubar;
   L_BOOL                 bHideWindowUI;
   L_BOOL                 bFitWindow;
   L_BOOL                 bCenterWindow;
   L_BOOL                 bDisplayDocTitle;
   L_TCHAR               *pwszCreator;        // Pdf document creator name
   L_TCHAR               *pwszProducer;       // Pdf document producer name
}
DOCWRTPDFOPTIONS, *pDOCWRTPDFOPTIONS;

typedef struct _DOCWRTDOCOPTIONS
{
   DOCWRTOPTIONS      Options;            // Options
   DOCWRTTEXTMODE     TextMode;           //Auto, NonFramed or Framed
   L_UINT32           uFlags;             // Flags
}
DOCWRTDOCOPTIONS, *pDOCWRTDOCOPTIONS;

typedef struct _DOCWRTRTFOPTIONS
{
   DOCWRTOPTIONS      Options;            // Options
   DOCWRTTEXTMODE     TextMode;           //Auto, NonFramed or Framed
   L_UINT32           uFlags;             // Flags
}
DOCWRTRTFOPTIONS,*pDOCWRTRTFOPTIONS;

typedef struct _DOCWRTHTMOPTIONS
{
   DOCWRTOPTIONS      Options;               // Options
   DOCWRTHTMTYPE      Type;                  // Html document type
   DOCWRTFONTEMBED    FontEmbed;             // Font Embedding mode
   L_BOOL             bUseBackgroundColor;   // TRUE means to use the rgbBackground as background color at saved Html document
   COLORREF           rgbBackground;         // Background color
   L_UINT32           uFlags;                // Flags
   L_INT              nImageFormat;          // PNG or JPEG
   L_BOOL             bEmbedCSS;             // TRUE, embed CSS inside file, else it will be in separate folder
   L_BOOL             bEmbedImages;          // TRUE, embed images inside file, else it will be in separate folder
   L_BOOL             bEmbedFonts;           // TRUE, embed fonts inside file, else it will be in separate folder
   L_UINT             uFontFlags;            // EOT, TTF, BOTH
}
DOCWRTHTMOPTIONS,*pDOCWRTHTMOPTIONS;

// DOCWRT_ALTOXML_xxx flags DOCWRTALTOXMLOPTIONS.uFlags
#define DOCWRT_ALTOXML_Sort               0x00000001  // If set, the text will be sorted
#define DOCWRT_ALTOXML_PlainText          0x00000002  // If set, the font information will be discarded and all the text will use the same font
#define DOCWRT_ALTOXML_ShowGlyphInfo      0x00000004  // If set, extra information is displayed for each glyph (position, bounding rectangle)
#define DOCWRT_ALTOXML_ShowGlyphVariants  0x00000008  // If set, text from OCR will display variants for some glyphs

typedef struct _DOCWRTALTOXMLOPTIONS
{
   DOCWRTOPTIONS                  Options;                       // Options
   DOCWRTALTOXMLMEASUREMENTUNIT   MeasurementUnit;               // Default = DOCWRTALTOXMLMEASUREMENTUNIT_MM10
   L_TCHAR                       *FileName;                      // Optional
   L_TCHAR                       *ProcessingDateTime;            // Optional
   L_TCHAR                       *ProcessingAgency;              // Optional
   L_TCHAR                       *ProcessingStepDescription;     // Optional
   L_TCHAR                       *ProcessingStepSettings;        // Optional
   L_TCHAR                       *SoftwareCreator;               // Optional
   L_TCHAR                       *SoftwareName;                  // Optional
   L_TCHAR                       *SoftwareVersion;               // Optional
   L_TCHAR                       *ApplicationDescription;        // Optional
   L_INT                          FirstPhysicalPageNumber;       // Default = 1
   L_BOOL                         Formatted;                     // Default = L_FALSE (output formatted XML, if L_TRUE, Indentation is used)   
   L_TCHAR                        Indentation[80];               // Default = "  "
   L_UINT                        uFlags;                         // Default = 0. One or more DOCWRT_ALTOXML_xxx flags (eg: DOCWRT_ALTOXML_Sort)
   L_INT                         nDesiredVersion;                // Default = 4. Only 4 is supported at the moment
}
DOCWRTALTOXMLOPTIONS, *pDOCWRTALTOXMLOPTIONS;

typedef struct _DOCWRTSVGOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
}
DOCWRTSVGOPTIONS, *pDOCWRTSVGOPTIONS;

typedef struct _DOCWRTEPUBOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
}
DOCWRTEPUBOPTIONS, *pDOCWRTEPUBOPTIONS;

typedef struct _DOCWRTMOBIOPTIONS
{
   DOCWRTOPTIONS     Options;             // Options
   L_VOID*           pReserved;
}
DOCWRTMOBIOPTIONS, *pDOCWRTMOBIOPTIONS;

typedef struct _LTDINFO
{
   L_UINT32                       uStructSize;
   DOCWRTLTDDOCUMENTTYPE          Type;
   L_UINT32                       uPageCount;
}LTDINFO, *pLTDINFO;

L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterInitA(DOCUMENTWRITER_HANDLE *phDocument, L_CHAR *pszFileName, DOCWRTFORMAT Format, L_VOID* pDocOptions, STATUSCALLBACK pfnStatusCallback, L_VOID *pUserData);

L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterFinishA(DOCUMENTWRITER_HANDLE hDocument);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterConvertA(L_CHAR* pszLtdFileName, L_CHAR *pszFileName, DOCWRTFORMAT Format, L_VOID* pDocOptions, STATUSCALLBACK pfnStatusCallback, L_VOID *pUserData);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterInsertPage(DOCUMENTWRITER_HANDLE hDocument, DOCWRTPAGETYPE PageType, L_VOID* pPage, L_UINT pageNumber);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterAppendLtdA(L_CHAR* pszSrcFileName, L_CHAR* pszDestFileName);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterAddPageA(DOCUMENTWRITER_HANDLE hDocument, DOCWRTPAGETYPE PageType, L_VOID* pPage);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterGetLtdFileInfo(const L_TCHAR* ltdFileName, LTDINFO* ltdInfo);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterGetDefaultOptions(DOCWRTFORMAT format, DOCWRTOPTIONS* formatOptions);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterFreeOptions(DOCWRTFORMAT format, DOCWRTOPTIONS* formatOptions);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterCopyOptions(DOCWRTFORMAT format, const DOCWRTOPTIONS* srcFormatOptions, DOCWRTOPTIONS* destFormatOptions);


#if defined(FOR_UNICODE)
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterInit(DOCUMENTWRITER_HANDLE *phDocument, L_TCHAR *pszFileName, DOCWRTFORMAT Format, L_VOID* pDocOptions, STATUSCALLBACK pfnStatusCallback, L_VOID *pUserData);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterFinish(DOCUMENTWRITER_HANDLE hDocument);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterConvert(L_TCHAR* pszLtdFileName, L_TCHAR *pszFileName, DOCWRTFORMAT Format, L_VOID* pDocOptions, STATUSCALLBACK pfnStatusCallback, L_VOID *pUserData);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterAppendLtd(L_TCHAR* pszSrcFileName, L_TCHAR* pszDestFileName);
L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterAddPage(DOCUMENTWRITER_HANDLE hDocument, DOCWRTPAGETYPE PageType, L_VOID* pPage);
#else
#define L_DocWriterInit       L_DocWriterInitA
#define L_DocWriterAddPage    L_DocWriterAddPageA
#define L_DocWriterFinish     L_DocWriterFinishA
#define L_DocWriterConvert    L_DocWriterConvertA
#define L_DocWriterAppendLtd  L_DocWriterAppendLtdA
#endif // #if defined(FOR_UNICODE)

L_LTDOCWRT_API L_INT EXT_FUNCTION L_DocWriterUpdateMetaFileResolution(L_HENHMETAFILE hEmfSrc, L_INT xResolution, L_INT yResolution, L_HENHMETAFILE* phEmfDest);

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTDOCWRT___H)
