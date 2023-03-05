//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTDIS_H)
#define LTDIS_H

#include "lttyp.h"
#define L_LTDIS_API LT_EXPORTED

#include "lterr.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

/****************************************************************
   Enums/defines/macros
****************************************************************/

// flags for L_CopyToClipboard
#define COPY2CB_EMPTY      0x0001   // Empty the clipboard
#define COPY2CB_DIB        0x0002   // Copy DIB data to the clipboard
#define COPY2CB_DDB        0x0004   // Copy DDB data to the clipboard
#define COPY2CB_PALETTE    0x0008   // Copy palette data to the clipboard
#define COPY2CB_RGN        0x0010   // Copy region data to the clipboard

// flags for L_ConvertColorSpace & L_ClrInit
#define CCS_RGB      0x00  // Color space is RGB
#define CCS_YUV      0x01  // Color space is YUV
#define CCS_CMYK     0x02  // Color space is CMYK
#define CCS_HSV      0x03  // Color space is HSV
#define CCS_HLS      0x04  // Color space is HLS
#define CCS_YIQ      0x05  // Color space is YIQ
#define CCS_CMY      0x06  // Color space is CMY
#define CCS_LAB      0x07  // Color space is CIELAB
#define CCS_XYZ      0x08  // Color space is XYZ
#define CCS_YCCK     0x0B  // Color space is YCCK
#define CCS_BGR      0x0C  // Color space is BGR

#define CCS_Y41P     0x0D  // Color space is Y41P
#define CCS_UYVY     0x0E  // Color space is UYVY
#define CCS_YUY2     0x09  // Color space is YUY2
#define CCS_YVU9     0x0A  // Color space is YVU9
#define CCS_YCC      0x0F  // Color space is YCC
#define CCS_RGB16    0x10  // Color space is RGB
#define CCS_YUV16    0x20  // Color space is YUV
#define CCS_YIQ16    0x30  // Color space is YIQ
#define CCS_HSV16    0x40  // Color space is HSV
#define CCS_HLS16    0x50  // Color space is HLS
#define CCS_CMY16    0x60  // Color space is CMY
#define CCS_CMYK16   0x70  // Color space is CMYK

#define CCS_IHS      0x80  // Color space is IHS

#define CCS_ARGB4    0x90  // Color space is ARGB4444

// flags for L_UnderlayBitmap
#define UB_TILE      0x00  // Tile the underlay
#define UB_STRETCH   0x01  // Stretch the underlay

// flags for L_SetDisplayMode
#define DISPLAYMODE_ORDEREDDITHER      0x00000001
#define DISPLAYMODE_FASTPAINT          0x00000002
#define DISPLAYMODE_INDEXEDPAINT       0x00000004
#define DISPLAYMODE_DITHEREDPAINT      0x00000008
#define DISPLAYMODE_SCALETOGRAY        0x00000010
#define DISPLAYMODE_HALFTONEPRINT      0x00000020
#define DISPLAYMODE_FAVORBLACK         0x00000040
#define DISPLAYMODE_FIXEDPALETTE       0x00000080
#define DISPLAYMODE_NETSCAPEPALETTE    0x00000100
#define DISPLAYMODE_RESAMPLE           0x00000200
#define DISPLAYMODE_BICUBIC            0x00000400
#define DISPLAYMODE_IGNORECOLORORDER   0x00000800
#define DISPLAYMODE_GDIPLUS            0x00001000
#define DISPLAYMODE_GDIPLUSUNITPIXEL   0x00002000
#define DISPLAYMODE_RESETPOSITIONS     0xFFFFFFFF

// playback state constants
#define PLAYSTATE_PRECLEAR          0x0000
#define PLAYSTATE_POSTCLEAR         0x0001
#define PLAYSTATE_PRERENDER         0x0002
#define PLAYSTATE_RENDER            0x0003
#define PLAYSTATE_POSTRENDER        0x0004
#define PLAYSTATE_WAITINPUT         0x0005
#define PLAYSTATE_WAITDELAY         0x0006
#define PLAYSTATE_WAITINPUTDELAY    0x0007
#define PLAYSTATE_PREDISPOSE        0x0008
#define PLAYSTATE_POSTDISPOSE       0x0009
#define PLAYSTATE_END               0x000A

#define PLAYDISPOSE_NONE               0
#define PLAYDISPOSE_LEAVE              1
#define PLAYDISPOSE_RESTOREBACKGROUND  2
#define PLAYDISPOSE_RESTOREPREVIOUS    3

// region processing
#define L_RGN_AND             0
#define L_RGN_SET             1
#define L_RGN_ANDNOTBITMAP    2
#define L_RGN_ANDNOTRGN       3
#define L_RGN_OR              4
#define L_RGN_XOR             5
#define L_RGN_SETNOT          6
// L_RGN_LEGACY_ELLIPSE is valid only for L_SetBitmapRgnEllipse. Pass this flag together with region set mode, to obtain ellipse regions compatible with older versions of LEADTOOLS (v18 and some old v19 DLLs).
// So:
//    L_SetBitmapRgnEllipse(pBitmap, pXForm, pRect, L_RGN_LEGACY_ELLIPSE | L_RGN_SET)   - create ellipse regions using older code
//    L_SetBitmapRgnEllipse(pBitmap, pXForm, pRect, L_RGN_SET)   - create ellipse regions using newer code
// L_RGN_LEGACY_ELLIPSE is not recommended unless you need to preserve backwards compatibility
#define L_RGN_LEGACY_ELLIPSE  0x08  

#define L_POLY_WINDING     0
#define L_POLY_ALTERNATE   1

#define L_FRAME_MOVING0    0
#define L_FRAME_MOVING1    1
#define L_FRAME_MOVING2    2
#define L_FRAME_MOVING3    3
#define L_FRAME_MOVING4    4
#define L_FRAME_MOVING5    5
#define L_FRAME_MOVING6    6
#define L_FRAME_MOVING7    7

// flags for L_WindowLevel
#define WINDOWLEVEL_PAINT                 0x00
#define WINDOWLEVEL_PAINT_AND_PROCESSING  0x01

// constants for nCrosshair in L_StartMagGlass
#define CROSSHAIR_NONE           0
#define CROSSHAIR_FINE           1
#define CROSSHAIR_INVERTPEN      2
#define CROSSHAIR_INVERTSCREEN   3

// constants for uMagGlassFlags in L_StartMagGlass
#define MAGGLASS_MASK_NORMAL        0x0000
#define MAGGLASS_MASK_INVERT        0x0001
#define MAGGLASS_MANUAL_UPDATE      0x0002
#define MAGGLASS_MASK_FROM_REGION   0x0004
#define MAGGLASS_RIGHTMOUSE         0x0008

// constants for uMagGlassShape in L_UpdateMagGlassShape
#define MAGGLASS_SHAPE_RECT      0
#define MAGGLASS_SHAPE_ELLIPSE   1
#define MAGGLASS_SHAPE_HRGN      2

#define CURVE_BEZIER                0
#define CURVE_STANDARD              1  // Catmull Rom
#define CURVE_NATURAL_CUBIC_SPLINE  2
#define CURVE_NO_CLOSE              0  //Process only included points -- For n points draw (n-3) segments
#define CURVE_CLOSE                 1  //For n points draw (n-1) segments
#define CURVE_PARTIAL_CLOSE         2  //Repeat first three points -- For n points draw (n) segments

// Flags for L_WindowLevelFillLUT, L_WindowLevelFillLUT2 and L_WindowLevelFillLUTExt
#define FILLLUT_INSIDE        0x0001
#define FILLLUT_OUTSIDE       0x0002
#define FILLLUT_LINEAR        0x0010
#define FILLLUT_EXPONENTIAL   0x0020
#define FILLLUT_LOGARITHMIC   0x0030
#define FILLLUT_SIGMOID       0x0040

#define FILLLUT_UNSIGNED      0x0000
#define FILLLUT_SIGNED        0x0100

#define FILLLUT_DICOM_STYLE   0x1000

// flags for PanWindow Callback
#define PANWIN_CREATED              0
#define PANWIN_UPDATED              1
#define PANWIN_DESTROYED            2
#define PANWIN_MOVED                3
#define PANWIN_REPAINTED            4
#define DISPLAYMODE_INVALIDATEPAN   0x10000000

// Flags for L_CalculatePaintModeRectangle
#define PAINTMODE_SIZEMODE_NORMAL     0
#define PAINTMODE_SIZEMODE_FIT        1
#define PAINTMODE_SIZEMODE_FIT_ALWAYS 2
#define PAINTMODE_SIZEMODE_FIT_WIDTH  3
#define PAINTMODE_SIZEMODE_STRETCH    4
#define PAINTMODE_SIZEMODE_FIT_HEIGHT 5

#define PAINTMODE_ALIGN_NEAR           0
#define PAINTMODE_ALIGN_CENTER         1
#define PAINTMODE_ALIGN_CENTER_ALWAYS  2
#define PAINTMODE_ALIGN_FAR            3

// Flags that make up PAINTDIBINFO.uFlags
#define DIBFLAG_IGNORELUT           0x0001 // Ignore the LUT during color conversion. The window leveling will be done through a hardware LUT.
#define DIBFLAG_LOWHIGHBITVALID     0x0002 // The low and high bit values are valid. The data does not use the whole range
#define DIBFLAG_SUPPORTS_WIDECOLORS 0x0004 // 48 and 64 bits per pixel supported. Only used when using paint callbacks

// Flags that make up PAINTCALLBACKDATA.uFlags
#define PAINTCALLBACKDATA_NO_INDEXEDPAINT 0x0001
#define PAINTCALLBACKDATA_SUPPORTS_ALPHA  0x0002

/****************************************************************
   Classes/structures
****************************************************************/
typedef struct _RGNXFORM
{
   L_UINT uViewPerspective;
   L_INT nXScalarNum;
   L_INT nXScalarDen;
   L_INT nYScalarNum;
   L_INT nYScalarDen;
   L_INT nXOffset;
   L_INT nYOffset;
}
RGNXFORM, *pRGNXFORM;

typedef struct _HSVREF
{
   L_UCHAR uH;
   L_UCHAR uS;
   L_UCHAR uV;
   L_UCHAR uReserved;
}
HSVREF, *pHSVREF;

typedef struct _CURVE
{
   L_UINT uStructSize;
   L_INT nType;         //RGNCURVE_BEZIER, RGNCURVE_CURVE
   L_INT nPointCount;
   L_POINT* pPoints;
   L_UINT uFillMode;
   L_DOUBLE dTension;   //0.0 to 1.0
   L_INT nClose;
   L_INT nReserved;
}
CURVE, *pCURVE;

typedef struct _MAGGLASSOPTIONS
{
   L_UINT uStructSize;
   L_INT nWidth;
   L_INT nHeight;
   L_INT nZoom;
   L_COLORREF clrPen;
   L_HCURSOR hMagCursor;
   L_COLORREF clrBack;
   L_BOOL bEllipse;
   L_INT nBorderSize;
   L_BOOL b3D;
   L_UINT uPaintFlags;
   L_COLORREF* pMask;
   L_UINT uMaskCount;
   L_UINT uMagGlassFlags;
   L_INT nCrosshair;
   L_BOOL bIgnoreRgn;
   L_BOOL bCenter;
   L_BOOL bZoomOnMouseWheel;
}
MAGGLASSOPTIONS, *pMAGGLASSOPTIONS;

typedef struct _MAGGLASSPAINTOPTIONS
{
   L_UINT uStructSize;
   L_INT nContrast;
   L_INT nGamma;
   L_INT nIntensity;
}
MAGGLASSPAINTOPTIONS, *pMAGGLASSPAINTOPTIONS;

// Structure defining the desired DIB info
typedef struct _PAINTDIBINFO
{
   L_UINT   uStructSize;         // size of structure
   L_UINT   uViewPerspective;    // view perspective of the image (TOP_DOWN or BOTTOM_LEFT)
   L_UINT   uBitsPerPixel;       // the desired bits per pixel in the DIB
   L_UINT   uPlaneCount;         // the number of planes (set to 1 if grayscale or interleaved, set to > 1 if planar DIB)
   L_UINT   uBytesPerLine;       // the desired bytes per line (for image or plane)
   L_INT    nOrder;              // desired DIB order (ORDER_BGR, ORDER_RGB or ORDER_GRAY)
   L_UINT   uFlags;              // miscellaneous flags for the DIB. Made up of DIBFLAG_XXX flags
   L_UINT   uLowBit;             // the low bit of the desired data
   L_UINT   uHighBit;            // the high bit of the desired data
   L_UINT   uDataOffset;         // Reserved for future use (set to 0)
   L_VOID   *pUserData;          // user data for the application
} PAINTDIBINFO, *pPAINTDIBINFO;

/****************************************************************
   Callback typedefs
****************************************************************/

typedef L_INT (pEXT_CALLBACK MAGGLASSCALLBACK)(
   L_HWND hWnd,
   L_INT nMaskPlaneStart,
   L_INT nMaskPlaneEnd,
   L_UCHAR* pMaskPlane,
   L_SIZE_T uMaskPlaneSize,
   L_VOID* pUserData);

typedef L_INT (pEXT_CALLBACK MAGGLASSOWNERDRAWCALLBACK)(
   L_HWND hWnd,
   L_HDC hMemDC,
   L_INT nXPos,
   L_INT nYPos,
   L_RECT* pMagGlass,
   L_VOID* pUserData);

typedef L_VOID (pEXT_CALLBACK PANWNDCALLBACK)(
   L_HWND hPanWindow,
   L_HWND hWndParent,
   L_UINT uFlags,
   L_RECT* prcPan,
   L_VOID* pUserData);

typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_GETDEVICECAPS)(L_VOID* pDisplay, L_INT nIndex, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_GETMAPMODE)(L_VOID* pDisplay, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_SETSTRETCHBLTMODE)(L_VOID* pDisplay, L_INT nStretchMode, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_INTERSECTCLIPRECT)(L_VOID* pDisplay, L_INT nLeftRect, L_INT nTopRect, L_INT nRightRect, L_INT nBottomRect, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_SAVEDC)(L_VOID* pDisplay, L_VOID *pUserData);
typedef L_VOID (EXT_CALLBACK* PAINTCALLBACK_RESTOREDC)(L_VOID* pDisplay, L_INT nSaveDC, L_VOID *pUserData);
typedef L_BOOL (EXT_CALLBACK* PAINTCALLBACK_STRETCHDIBITS)(L_VOID* pDisplay, L_INT nXDest, L_INT nYDest, L_INT nDestWidth, L_INT nDestHeight, L_INT nXSrc, L_INT nYSrc, L_INT nSrcWidth, L_INT nSrcHeight, const L_VOID* lpvBits, const BITMAPINFO* lpbmi, L_UINT fuColorUse, L_UINT32 ulROP3Code, L_VOID *pUserData);
typedef L_BOOL (EXT_CALLBACK* PAINTCALLBACK_SETVIEWPORTORGEX)(L_VOID* pDisplay, L_INT nX, L_INT nY, LPPOINT lpPoint, L_VOID *pUserData);
typedef L_BOOL (EXT_CALLBACK* PAINTCALLBACK_GETVIEWPORTORGEX)(L_VOID* pDisplay, LPPOINT lpPoint, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_EXTSELECTCLIPRGN)(L_VOID* pDisplay, L_HRGN hRgn, L_INT nMode, L_VOID *pUserData);
typedef L_HPALETTE (EXT_CALLBACK* PAINTCALLBACK_SELECTPALETTE)(L_VOID* pDisplay, L_HPALETTE hPal, L_BOOL bForceBackground, L_VOID *pUserData);
typedef L_VOID (EXT_CALLBACK* PAINTCALLBACK_REALIZEPALETTE)(L_VOID* pDisplay, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_GETGRAPHICSMODE)(L_VOID* pDisplay, L_VOID *pUserData);
typedef L_BOOL (EXT_CALLBACK* PAINTCALLBACK_GETWORLDTRANSFORM)(L_VOID* pDisplay, LPXFORM lpXform, L_VOID *pUserData);
typedef L_BOOL (EXT_CALLBACK* PAINTCALLBACK_ISCOMPATIBLEDC)(L_VOID* pDisplay, pBITMAPHANDLE pBitmap, L_VOID *pUserData);
typedef L_VOID (EXT_CALLBACK* PAINTCALLBACK_CONVERTLINE) (L_UCHAR* pOutScan, L_UCHAR* pInScan, pBITMAPHANDLE pBitmap, L_INT nLeft, L_INT nRight, pPAINTDIBINFO pDibInfo, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_GETDIBINFO) (L_HDC hdc, pBITMAPHANDLE pBitmap, L_UINT uWidth, pPAINTDIBINFO pDibInfo, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_PREPAINT) (L_HDC hdc, pBITMAPHANDLE pBitmap, LPRECT prcDestClip, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_POSTPAINT) (L_HDC hdc, pBITMAPHANDLE pBitmap, L_VOID *pUserData);
typedef L_INT (EXT_CALLBACK* PAINTCALLBACK_FILLRECT) (L_VOID* pDisplay, LPRECT lpRect, L_COLORREF color, L_VOID *pUserData);

typedef struct _PAINTCALLBACKDATA
{
   L_UINT   uStructSize;
   L_UINT32 uFlags;
   L_VOID*  pDisplay;
   L_VOID*  pUserData;
   PAINTCALLBACK_GETDEVICECAPS pGetDeviceCaps;
   PAINTCALLBACK_GETMAPMODE pGetMapMode;
   PAINTCALLBACK_SETSTRETCHBLTMODE pSetStretchBltMode;
   PAINTCALLBACK_INTERSECTCLIPRECT pIntersectClipRect;
   PAINTCALLBACK_SAVEDC pSaveDC;
   PAINTCALLBACK_RESTOREDC pRestoreDC;
   PAINTCALLBACK_STRETCHDIBITS pStretchDIBits;
   PAINTCALLBACK_SETVIEWPORTORGEX pSetViewportOrgEx;
   PAINTCALLBACK_GETVIEWPORTORGEX pGetViewportOrgEx;
   PAINTCALLBACK_EXTSELECTCLIPRGN pExtSelectClipRgn;
   PAINTCALLBACK_SELECTPALETTE pSelectPalette;
   PAINTCALLBACK_REALIZEPALETTE pRealizePalette;
   PAINTCALLBACK_GETGRAPHICSMODE pGetGraphicsMode;
   PAINTCALLBACK_GETWORLDTRANSFORM pGetWorldTransform;
   PAINTCALLBACK_ISCOMPATIBLEDC pIsCompatibleDC;
   PAINTCALLBACK_CONVERTLINE pConvertLine;
   PAINTCALLBACK_GETDIBINFO pGetDibInfo;
   PAINTCALLBACK_PREPAINT pPrePaint;
   PAINTCALLBACK_POSTPAINT pPostPaint;
   PAINTCALLBACK_FILLRECT pFillRect;
}
PAINTCALLBACKDATA, *pPAINTCALLBACKDATA;

/****************************************************************
   Function prototypes
****************************************************************/

L_LTDIS_API L_INT EXT_FUNCTION L_AppendPlayback(
   HPLAYBACK hPlayback,
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_CancelPlaybackWait(
   HPLAYBACK hPlayback);

L_LTDIS_API L_INT EXT_FUNCTION L_ChangeFromDDB(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HBITMAP hBitmap,
   L_HPALETTE hPalette);

L_LTDIS_API L_HBITMAP EXT_FUNCTION L_ChangeToDDB(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_ClearPlaybackUpdateRect(
   HPLAYBACK hPlayback);

L_LTDIS_API L_BOOL EXT_FUNCTION L_ClipboardReady(L_VOID);

L_LTDIS_API L_INT EXT_FUNCTION L_ConvertColorSpace(
   L_UCHAR* pBufferSrc,
   L_UCHAR* pBufferDst,
   L_INT nWidth,
   L_INT nFormatSrc,
   L_INT nFormatDst);

L_LTDIS_API L_INT EXT_FUNCTION L_ConvertFromDDB(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HBITMAP hBitmap,
   L_HPALETTE hPalette);

L_LTDIS_API L_HBITMAP EXT_FUNCTION L_ConvertToDDB(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_BOOL EXT_FUNCTION L_CopyFromClipboard(
   L_HWND hWnd,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize);

L_LTDIS_API L_INT EXT_FUNCTION L_CopyToClipboard(
   L_HWND hWnd,
   pBITMAPHANDLE pBitmap,
   L_UINT uFlags);

L_LTDIS_API L_HPALETTE EXT_FUNCTION L_CreatePaintPalette(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_CreatePlayback(
   pHPLAYBACK phPlayback,
   pBITMAPHANDLE pBitmap,
   HBITMAPLIST hList);

L_LTDIS_API L_INT EXT_FUNCTION L_DestroyPlayback(
   HPLAYBACK hPlayback,
   pHBITMAPLIST phList);

L_LTDIS_API L_UINT EXT_FUNCTION L_GetDisplayMode(L_VOID);

L_LTDIS_API L_INT EXT_FUNCTION L_GetPaintContrast(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_UINT EXT_FUNCTION L_GetPaintGamma(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_GetPaintIntensity(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_GetPlaybackDelay(
   HPLAYBACK hPlayback,
   L_UINT *puDelay);

L_LTDIS_API L_INT EXT_FUNCTION L_GetPlaybackIndex(
   HPLAYBACK hPlayback,
   L_INT *pnIndex);

L_LTDIS_API L_INT EXT_FUNCTION L_GetPlaybackState(
   HPLAYBACK hPlayback,
   L_UINT *puState);

L_LTDIS_API L_INT EXT_FUNCTION L_GetPlaybackUpdateRect(
   HPLAYBACK hPlayback,
   L_RECT* prcUpdate,
   L_BOOL fClear);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDC(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCBuffer(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3,
   L_UCHAR* pBuffer,
   L_INT nRow,
   L_INT nCount);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCOverlayCallback(
   pPAINTCALLBACKDATA pCallbackData,
   pBITMAPHANDLE pBitmap,
   L_INT nIndex,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCBufferCallback(
   pPAINTCALLBACKDATA pCallbackData,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pSrcClip,
   L_RECT* pDest,
   L_RECT* pDestClip,
   L_UINT32 uROP3,
   L_UCHAR* pBuffer,
   L_INT nBufferRow,
   L_INT nNumRows);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCCallback(
   pPAINTCALLBACKDATA pCallbackData,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pSrcClip,
   L_RECT* pDest,
   L_RECT* pDestClip,
   L_UINT32 uROP3);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintRgnDCCallback(
   pPAINTCALLBACKDATA pCallbackData,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintRgnDCBufferCallback(
   pPAINTCALLBACKDATA pCallbackData,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3,
   L_UCHAR* pBuffer,
   L_INT nRow,
   L_INT nCount);

L_LTDIS_API L_INT EXT_FUNCTION L_ProcessPlayback(
   HPLAYBACK hPlayback,
   L_UINT* puState);

L_LTDIS_API HSVREF EXT_FUNCTION L_RGBtoHSV(
   L_COLORREF crColor);

L_LTDIS_API L_COLORREF EXT_FUNCTION L_HSVtoRGB(
   HSVREF hsvColor);

L_LTDIS_API L_UINT EXT_FUNCTION L_SetDisplayMode(
   L_UINT uFlagPos,
   L_UINT uFlagSet);

L_LTDIS_API L_INT EXT_FUNCTION L_SetPaintContrast(
   pBITMAPHANDLE pBitmap,
   L_INT nValue);

L_LTDIS_API L_INT EXT_FUNCTION L_SetPaintGamma(
   pBITMAPHANDLE pBitmap,
   L_UINT uValue);

L_LTDIS_API L_INT EXT_FUNCTION L_SetPaintIntensity(
   pBITMAPHANDLE pBitmap,
   L_INT nValue);

L_LTDIS_API L_INT EXT_FUNCTION L_SetPlaybackIndex(
   HPLAYBACK hPlayback,
   L_INT nIndex);

L_LTDIS_API L_INT EXT_FUNCTION L_UnderlayBitmap(
   pBITMAPHANDLE pBitmapDst,
   pBITMAPHANDLE pUnderlay,
   L_UINT uFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_ValidatePlaybackLines(
   HPLAYBACK hPlayback,
   L_INT nRow,
   L_INT nLines);

L_LTDIS_API L_INT EXT_FUNCTION L_WindowLevel(
   pBITMAPHANDLE pBitmap,
   L_INT nLowBit,
   L_INT nHighBit,
   L_RGBQUAD* pLUT,
   L_UINT ulLUTLength,
   L_UINT uFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_WindowLevelExt(
   pBITMAPHANDLE pBitmap,
   L_INT nLowBit,
   L_INT nHighBit,
   L_RGBQUAD16* pLUT,
   L_UINT ulLUTLength,
   L_UINT uFlags);

// new WindowLevel dialog helper function
L_LTDIS_API L_INT EXT_FUNCTION L_WindowLevelFillLUT(
   L_RGBQUAD* pLUT,
   L_UINT ulLUTLen,
   L_COLORREF crStart,
   L_COLORREF crEnd,
   L_INT nLow,
   L_INT nHigh,
   L_UINT uLowBit,
   L_UINT uHighBit,
   L_INT nMinValue,
   L_INT nMaxValue,
   L_INT nFactor,
   L_UINT uFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_WindowLevelFillLUT2(
   L_RGBQUAD* pLUT,
   L_UINT ulLUTLen,
   L_COLORREF crStart,
   L_COLORREF crEnd,
   L_INT nLow,
   L_INT nHigh,
   L_UINT uLowBit,
   L_UINT uHighBit,
   L_INT nMinValue,
   L_INT nMaxValue,
   L_INT nFactor,
   L_UINT uFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_WindowLevelFillLUTExt(
   L_RGBQUAD16* pLUT,
   L_UINT ulLUTLen,
   L_RGBQUAD16 rgbStart,
   L_RGBQUAD16 rgbEnd,
   L_INT nLow,
   L_INT nHigh,
   L_UINT uLowBit,
   L_UINT uHighBit,
   L_INT nMinValue,
   L_INT nMaxValue,
   L_INT nFactor,
   L_UINT uFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_WindowLevelFillLUTExt2(
   L_RGBQUAD16* pLUT,
   L_UINT ulLUTLen,
   L_RGBQUAD16* pRgbStart,
   L_RGBQUAD16* pRgbEnd,
   L_INT nLow,
   L_INT nHigh,
   L_UINT uLowBit,
   L_UINT uHighBit,
   L_INT nMinValue,
   L_INT nMaxValue,
   L_INT nFactor,
   L_UINT uFlags);


L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapClipSegments(
   pBITMAPHANDLE pBitmap,
   L_INT nRow,
   L_UINT* pSegmentBuffer,
   L_UINT* puSegmentCount);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapClipSegmentsMax(
   pBITMAPHANDLE pBitmap,
   L_UINT* puMaxSegments);

L_LTDIS_API L_INT EXT_FUNCTION L_StartMagGlass(
   L_HWND hWnd,
   pBITMAPHANDLE pBitmap,
   L_RECT* prcDst,
   MAGGLASSOPTIONS* pMagGlassOptions,
   MAGGLASSCALLBACK pfnCallback,
   L_VOID* pUserData);

L_LTDIS_API L_INT EXT_FUNCTION L_StopMagGlass(
   L_HWND hWnd);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdateMagGlassRect(
   L_HWND hWnd,
   L_RECT* prcDst);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdateMagGlassPaintFlags(
   L_HWND hWnd,
   L_UINT uPaintFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdateMagGlass(
   L_HWND hWnd,
   L_COLORREF* pColor,
   L_UCHAR* pMaskPlane,
   L_INT nMaskPlaneStart,
   L_INT nMaskPlaneEnd,
   L_BOOL bUpdateBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdateMagGlassBitmap(
   L_HWND hWnd,
   pBITMAPHANDLE pBitmap,
   L_BOOL bUpdateBitmap);

L_LTDIS_API L_BOOL EXT_FUNCTION L_WindowHasMagGlass(
   L_HWND hWnd);

L_LTDIS_API L_INT EXT_FUNCTION L_SetMagGlassOwnerDrawCallback(
   L_HWND hWnd,
   MAGGLASSOWNERDRAWCALLBACK pfnCallback,
   L_VOID* pUserData);

L_LTDIS_API L_INT EXT_FUNCTION L_SetMagGlassPaintOptions(
   L_HWND hWnd,
   pMAGGLASSPAINTOPTIONS pMagGlassPaintOptions);

L_LTDIS_API L_INT EXT_FUNCTION L_ShowMagGlass(
   L_HWND hWnd,
   L_BOOL bShowMagGlass);

L_LTDIS_API L_INT EXT_FUNCTION L_SetMagGlassPos(
   L_HWND hWnd,
   L_INT xPos,
   L_INT yPos);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdateMagGlassShape(
   L_HWND hWnd,
   L_UINT uMagGlassShape,
   L_HRGN hMagGlassRgn);

L_LTDIS_API L_HDC EXT_FUNCTION L_PrintBitmap(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_INT nX,
   L_INT nY,
   L_INT nWidth,
   L_INT nHeight,
   L_BOOL fEndDoc);

L_LTDIS_API L_HDC EXT_FUNCTION L_PrintBitmapFast(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_INT nX,
   L_INT nY,
   L_INT nWidth,
   L_INT nHeight,
   L_BOOL fEndDoc);

L_LTDIS_API L_INT EXT_FUNCTION L_PrintBitmapGDIPlus (
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_INT nX,
   L_INT nY,
   L_INT nWidth,
   L_INT nHeight,
   L_UINT32 uFlags);

L_LTDIS_API L_INT EXT_FUNCTION L_ScreenCaptureBitmap(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_RECT* pRect);

L_LTDIS_API L_BOOL EXT_FUNCTION L_BitmapHasRgn(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_CreateMaskFromBitmapRgn(
   pBITMAPHANDLE pBitmap,
   pBITMAPHANDLE pMask,
   L_UINT uStructSize);

L_LTDIS_API L_INT EXT_FUNCTION L_CurveToBezier(
   pCURVE pCurve,
   L_INT* pOutPointCount,
   L_POINT *OutPoint);

L_LTDIS_API L_INT EXT_FUNCTION L_FrameBitmapRgn(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_UINT uType);

L_LTDIS_API L_INT EXT_FUNCTION L_ColorBitmapRgn(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_COLORREF crRgnColor);

L_LTDIS_API L_INT EXT_FUNCTION L_FreeBitmapRgn(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapRgnArea(
   pBITMAPHANDLE pBitmap,
   L_SIZE_T* puArea);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapRgnBounds(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_RECT* pRect);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapRgnHandle(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_HRGN* phRgn);

L_LTDIS_API L_BOOL EXT_FUNCTION L_IsPtInBitmapRgn(
   pBITMAPHANDLE pBitmap,
   L_INT nRow,
   L_INT nCol);

L_LTDIS_API L_INT EXT_FUNCTION L_OffsetBitmapRgn(
   pBITMAPHANDLE pBitmap,
   L_INT nRowOffset,
   L_INT nColOffset);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintRgnDC(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintRgnDCBuffer(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3,
   L_UCHAR* pBuffer,
   L_INT nRow,
   L_INT nCount);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnColor(
   pBITMAPHANDLE pBitmap,
   L_COLORREF crColor,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnColorHSVRange(
   pBITMAPHANDLE pBitmap,
   HSVREF hsvLower,
   HSVREF hsvUpper,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnColorRGBRange(
   pBITMAPHANDLE pBitmap,
   L_COLORREF crLower,
   L_COLORREF crUpper,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnMagicWand(
   pBITMAPHANDLE pBitmap,
   L_INT x,
   L_INT y,
   L_COLORREF crLowerTolerance,
   L_COLORREF crUpperTolerance,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnFromMask(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   pBITMAPHANDLE pMask,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnHandle(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_HRGN hRgn,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnRect(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_RECT* pRect,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnEllipse(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_RECT* pRect,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnPolygon(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_POINT* pPoints,
   L_UINT uPoints,
   L_UINT uFillMode,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnRoundRect(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_RECT* pRect,
   L_INT nWidthEllipse,
   L_INT nHeightEllipse,
   L_UINT uCombineMode);

#if defined(FOR_WINDOWS)
L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnCurve(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   pCURVE pCurve,
   L_UINT uCombineMode);
#endif // #if defined(FOR_WINDOWS)

L_LTDIS_API L_INT EXT_FUNCTION L_CreatePanWindowA(
   L_HWND hWndParent,
   pBITMAPHANDLE pBitmap,
   L_UINT ulDisplayFlags,
   L_INT nLeft,
   L_INT nTop,
   L_INT nWidth,
   L_INT nHeight,
   L_CHAR* pszClassName,
   L_HICON hIcon,
   L_HCURSOR hCursor,
   L_BOOL bSysMenu,
   PANWNDCALLBACK pfnPanCallback,
   L_VOID* pUserData);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdatePanWindowA(
   L_HWND hPanWindow,
   pBITMAPHANDLE pBitmap,
   L_UINT ulDisplayFlags,
   L_COLORREF crPen,
   L_CHAR* pszTitle,
   L_RECT* prcDst);

#if defined(FOR_UNICODE)
L_LTDIS_API L_INT EXT_FUNCTION L_CreatePanWindow(
   L_HWND hWndParent,
   pBITMAPHANDLE pBitmap,
   L_UINT ulDisplayFlags,
   L_INT nLeft,
   L_INT nTop,
   L_INT nWidth,
   L_INT nHeight,
   L_TCHAR* pszClassName,
   L_HICON hIcon,
   L_HCURSOR hCursor,
   L_BOOL bSysMenu,
   PANWNDCALLBACK pfnPanCallback,
   L_VOID* pUserData);

L_LTDIS_API L_INT EXT_FUNCTION L_UpdatePanWindow(
   L_HWND hPanWindow,
   pBITMAPHANDLE pBitmap,
   L_UINT ulDisplayFlags,
   L_COLORREF crPen,
   L_TCHAR* pszTitle,
   L_RECT* prcDst);
#else
#define L_CreatePanWindow L_CreatePanWindowA
#define L_UpdatePanWindow L_UpdatePanWindowA
#endif // #if defined(FOR_UNICODE)

L_LTDIS_API L_INT EXT_FUNCTION L_DestroyPanWindow(
   L_HWND hPanWindow);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapRgnData(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_INT nDataSize,
   L_VOID* pData);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnData(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_INT nDataSize,
   L_VOID* pData,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnClip(
   pBITMAPHANDLE pBitmap,
   L_BOOL bClip);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapRgnClip(
   pBITMAPHANDLE pBitmap,
   L_BOOL* pbClip);

L_LTDIS_API L_INT EXT_FUNCTION L_GetBitmapRgnBoundsClip(
   pBITMAPHANDLE pBitmap,
   pRGNXFORM pXForm,
   L_RECT* pRect);

L_LTDIS_API L_INT EXT_FUNCTION L_ConvertFromWMF(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight);

L_LTDIS_API L_INT EXT_FUNCTION L_ConvertFromWMF2(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight,
   L_COLORREF clrBackground);

L_LTDIS_API L_INT EXT_FUNCTION L_ChangeFromWMF(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight);

L_LTDIS_API L_INT EXT_FUNCTION L_ChangeFromWMF2(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight,
   L_COLORREF clrBackground);

L_LTDIS_API L_HMETAFILE EXT_FUNCTION L_ConvertToWMF(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_HMETAFILE EXT_FUNCTION L_ChangeToWMF(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_ConvertFromEMF(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HENHMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight);

L_LTDIS_API L_INT EXT_FUNCTION L_ConvertFromEMF2(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HENHMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight,
   L_COLORREF clrBackground);

L_LTDIS_API L_INT EXT_FUNCTION L_ChangeFromEMF(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HENHMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight);

L_LTDIS_API L_INT EXT_FUNCTION L_ChangeFromEMF2(
   pBITMAPHANDLE pBitmap,
   L_UINT uStructSize,
   L_HENHMETAFILE hWmf,
   L_UINT uWidth,
   L_UINT uHeight,
   L_COLORREF clrBackground);

L_LTDIS_API L_HENHMETAFILE EXT_FUNCTION L_ConvertToEMF(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_HENHMETAFILE EXT_FUNCTION L_ChangeToEMF(
   pBITMAPHANDLE pBitmap);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCOverlay(
   L_HDC hDC,
   pBITMAPHANDLE pBitmap,
   L_INT nIndex,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3);

L_LTDIS_API L_INT EXT_FUNCTION L_DoubleBufferEnable(
   L_HANDLE hDoubleBufferHandle,
   L_BOOL bEnable);

L_LTDIS_API L_INT EXT_FUNCTION L_DoubleBufferCreateHandle(
   L_HANDLE* phDoubleBufferHandle);

L_LTDIS_API L_INT EXT_FUNCTION L_DoubleBufferDestroyHandle(
   L_HANDLE hDoubleBufferHandle);

L_LTDIS_API L_HDC EXT_FUNCTION L_DoubleBufferBegin(
   L_HANDLE hDoubleBufferHandle,
   L_HDC hDC,
   L_INT cx,
   L_INT cy);

L_LTDIS_API L_INT EXT_FUNCTION L_DoubleBufferEnd(
   L_HANDLE hDoubleBufferHandle,
   L_HDC hDC);

L_LTDIS_API L_INT EXT_FUNCTION L_SetBitmapRgnBorder(
   pBITMAPHANDLE pBitmap,
   L_INT x,
   L_INT y,
   L_COLORREF crBorderColor,
   L_COLORREF crLowerTolerance,
   L_COLORREF crUpperTolerance,
   L_UINT uCombineMode);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCCMYKArray(
   L_HDC hDC,
   pBITMAPHANDLE* ppBitmapArray,
   L_UINT uBitmapArrayCount,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3,
   L_HANDLE hClrHandle);

L_LTDIS_API L_INT EXT_FUNCTION L_PaintDCCMYKArrayCallback(
   pPAINTCALLBACKDATA pCallbackData,
   pBITMAPHANDLE* ppBitmapArray,
   L_UINT uBitmapArrayCount,
   L_RECT* pSrc,
   L_RECT* pClipSrc,
   L_RECT* pDst,
   L_RECT* pClipDst,
   L_UINT32 uROP3,
   L_HANDLE hClrHandle);

L_LTDIS_API L_INT EXT_FUNCTION L_CalculatePaintModeRectangle(
   L_UINT uSrcWidth,
   L_UINT uSrcHeight,
   L_RECT* prcDestRect,
   L_UINT uSizeMode,
   L_UINT uHorzAlignMode,
   L_UINT uVertAlignMode);

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTDIS_H)
