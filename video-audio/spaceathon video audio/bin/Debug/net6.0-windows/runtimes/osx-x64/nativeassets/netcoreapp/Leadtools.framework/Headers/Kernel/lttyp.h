//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTTYP_H)
#define LTTYP_H

#include "ltsys.h"

#if defined(_MSC_VER) && _MSC_VER > 1600
#pragma warning(disable: 4211)
#endif // #if defined(_MSC_VER) && _MSC_VER > 1600
#define _USE_MATH_DEFINES
#include <math.h>
#if defined(_MSC_VER) && _MSC_VER > 1600
#pragma warning(default: 4211)
#endif // #if defined(_MSC_VER) && _MSC_VER > 1600

#include <fcntl.h>
#include <sys/stat.h>
#include <assert.h>

#if defined(FOR_ANDROID) && !defined(NDEBUG)
   #undef assert
   # if __ISO_C_VISIBLE >= 1999
   #  define	assert(e)	((e) ? (void)0 : (void)(LOGE("assert(%s(%d) %s)", __FILE__, __LINE__, #e), __assert2(__FILE__, __LINE__, __func__, #e)))
   # else
   #  define	assert(e)	((e) ? (void)0 : (void)(LOGE("assert2(%s(%d) %s)", __FILE__, __LINE__, #e), __assert(__FILE__, __LINE__, #e)))
   # endif
#endif // #if defined(FOR_ANDROID) && !defined(NDEBUG)

#include "ltcrt.h"

// needed for Windows Mobile
#if !defined(_MAX_FNAME)
#define _MAX_FNAME  256 /* max. length of file name component */
#define _MAX_EXT    256 /* max. length of extension component */
#endif // #if !defined(_MAX_FNAME)

#if !defined(_MAX_DRIVE)
#define _MAX_DRIVE  3   /* max. length of drive component */
#define _MAX_DIR    256 /* max. length of path component */
#endif // #if !defined(_MAX_DRIVE)

#if !defined(_TRUNCATE)
#define _TRUNCATE ((size_t)-1)
#endif // #if !defined(_TRUNCATE)

#define L_HEADER_ENTRY
#include "ltpck.h"

// Character types
typedef WCHAR           L_WCHAR; // 16-bit UNICODE character
typedef CHAR            L_CHAR;  // signed 8-bit integer
typedef UCHAR           L_UCHAR; // unsigned 8-bit integer

// Integer types
#if defined(INT8)
typedef INT8               L_INT8;     // 8-bit signed integer
typedef INT16              L_INT16;    // 16-bit signed integer
typedef INT32              L_INT32;    // 32-bit signed integer
typedef INT64              L_INT64;    // 64-bit signed integer
typedef UINT8              L_UINT8;    // 8-bit unsigned integer
typedef UINT16             L_UINT16;   // 16-bit unsigned integer
typedef UINT32             L_UINT32;   // 32-bit unsigned integer
typedef UINT64             L_UINT64;   // 64-bit unsigned integer
#else
typedef signed char        L_INT8;     // 8-bit signed integer
typedef signed short       L_INT16;    // 16-bit signed integer
typedef signed int         L_INT32;    // 32-bit signed integer
typedef signed __int64     L_INT64;    // 64-bit signed integer
typedef unsigned char      L_UINT8;    // 8-bit unsigned integer
typedef unsigned short     L_UINT16;   // 16-bit unsigned integer
typedef unsigned int       L_UINT32;   // 32-bit unsigned integer
typedef unsigned __int64   L_UINT64;   // 64-bit unsigned integer
#endif // #if defined(INT8)
typedef INT                L_INT;      // 32-bit signed integer
typedef UINT               L_UINT;     // 32-bit unsigned integer

// Integer limits
#define L_INT8_MAX      127
#define L_INT16_MAX     32767
#define L_INT32_MAX     2147483647
#define L_INT64_MAX     9223372036854775807LL

#define L_INT8_MIN      -128
#define L_INT16_MIN     -32768
#define L_INT32_MIN     (-L_INT32_MAX-1)
#define L_INT64_MIN     (-L_INT64_MAX-1)

#define L_UINT8_MAX     255
#define L_UINT16_MAX    65535
#define L_UINT32_MAX    4294967295U
#define L_UINT64_MAX    18446744073709551615ULL

// long and short
typedef LONG               L_LONG;
typedef ULONG              L_ULONG;
typedef USHORT             L_USHORT;

// Float types
typedef FLOAT              L_FLOAT;    // single precision 32-bit number (IEEE 754)

#if !defined(DOUBLE)
typedef double DOUBLE;
typedef DOUBLE             L_DOUBLE;   // double-precision 64-bit number (IEEE 754)
#endif // #if !defined(DOUBLE)

// 32/64 bit types
typedef INT_PTR            L_INT_PTR;
typedef UINT_PTR           L_UINT_PTR;

#if defined(LONG_PTR)
typedef LONG_PTR           L_LONG_PTR;
typedef ULONG_PTR          L_ULONG_PTR;
#else
   #if defined(FOR_X64) || defined(_WIN64) || defined(FOR_UNIX64)
      typedef __int64            L_LONG_PTR;
      typedef unsigned __int64   L_ULONG_PTR;
   #else
      #if (_MSC_VER <=1200) || (_WIN32_WCE)
         typedef long          L_LONG_PTR;
         typedef unsigned long L_ULONG_PTR;
      #else
         typedef _W64 long          L_LONG_PTR;
         typedef _W64 unsigned long L_ULONG_PTR;
      #endif
   #endif // defined(FOR_X64) || defined(_WIN64) || defined(FOR_UNIX64)
   #if !defined(L_LONG_PTR_DEFINED)
      typedef L_LONG_PTR            LONG_PTR;
      typedef L_ULONG_PTR           ULONG_PTR;
      typedef L_ULONG_PTR           DWORD_PTR;
   #endif // #if !defined(L_LONG_PTR_DEFINED)
#endif // #if defined(LONG_PTR)

#if defined(FOR_WIN64)
   #define L_UNALIGNED __unaligned
#else
   #define L_UNALIGNED
#endif // #if defined(FOR_WIN64)

typedef SIZE_T             L_SIZE_T;   // Maximum number of bytes to which a pointer can refer
typedef SSIZE_T            L_SSIZE_T;  // Signed L_SIZE_T

#define L_OFFSET           L_INT64
#define L_UOFFSET          L_UINT64

// Other types
#if defined(FOR_WINDOWS)
typedef VOID               L_VOID;     // void
#else
#define L_VOID             VOID        // void
#endif // #if !defined(FOR_WINDOWS)
typedef L_UINT             L_BITFIELD; // bit field (in a structure of a class)

// Booleans
#if defined(FOR_WINDOWS) || defined(FOR_UWP)
typedef BOOL               L_BOOL;     // boolean
#endif // #if defined(FOR_WINDOWS) || defined(FOR_UWP)

#define L_TRUE    TRUE
#define L_FALSE   FALSE

typedef COLORREF           L_COLORREF;

// Unicode types
#if defined (_LEAD_FORCE_UNICODE_)
   typedef WCHAR            L_TCHAR;
#else
   typedef TCHAR            L_TCHAR;
#endif // #if defined (_LEAD_FORCE_UNICODE_) || defined(FOR_LINUX)
#if !defined(L_TEXT)
#define L_TEXT          TEXT
#endif // #if !defined(L_TEXT)

#define L_TEXTW(str)       L##str

#define L_DECLARE_HANDLE   DECLARE_HANDLE
#if defined(FOR_WINDOWS)
typedef HANDLE          L_HANDLE;
// L_EVENTHANDLE used for event, mutex and thread handles.
// Must be closed using L_CLOSEEVENTHANDLE.
typedef L_HANDLE L_EVENTHANDLE;
#endif // #if defined(FOR_WINDOWS)

#if defined(FOR_UWP)
   #define L_OSHANDLE(h) ((((L_HANDLE)h) == L_INVALID_HANDLE_VALUE || ((L_HANDLE)h) == 0) ? L_INVALID_HANDLE_VALUE : ((L_HANDLE)(h))->Handle.hHandle)
   typedef DWORD_PTR L_HFILE;
#else
   L_DECLARE_HANDLE(L_HFILE);
   #define L_OSHANDLE(h)   h
#endif // #if defined(FOR_UWP)

#if defined(FOR_WINDOWS) || defined(FOR_UWP)
   #define L_GETEVENTHANDLE(x) x
#else
   #define L_GETEVENTHANDLE L_OSHANDLE
#endif // #if defined(FOR_WINDOWS) || defined(FOR_UWP)

#if defined(FOR_WINDOWS)
typedef HGLOBAL      L_HDIB;
typedef HGDIOBJ      L_HGDIOBJ;
typedef HDC          L_HDC;
typedef HRGN         L_HRGN;
typedef HPALETTE     L_HPALETTE;
typedef HBITMAP      L_HBITMAP;
typedef HGLOBAL      L_HGLOBAL;
typedef HPEN         L_HPEN;
typedef HFONT        L_HFONT;
typedef HBRUSH       L_HBRUSH;
#else
typedef L_HANDLE     L_HDIB;
typedef L_HANDLE     L_HGDIOBJ;
typedef L_HANDLE     L_HDC;
typedef L_HANDLE     L_HRGN;
typedef L_HANDLE     L_HPALETTE;
typedef L_HANDLE     L_HBITMAP;
typedef L_HANDLE     L_HGLOBAL;
typedef L_HANDLE     L_HPEN;
typedef L_HANDLE     L_HFONT;
typedef L_HANDLE     L_HBRUSH;
#endif // #if defined(FOR_WINDOWS)

typedef HWND         L_HWND;
typedef HINSTANCE    L_HINSTANCE;
typedef HMETAFILE    L_HMETAFILE;
typedef HENHMETAFILE L_HENHMETAFILE;
typedef HCURSOR      L_HCURSOR;
typedef HICON        L_HICON;
typedef HMODULE      L_HMODULE;
typedef HMENU        L_HMENU;

#define L_INVALID_HANDLE_VALUE   INVALID_HANDLE_VALUE
#define L_INVALID_FILE           (L_HFILE)L_INVALID_HANDLE_VALUE

// Other defines
#if !defined(NULL)
   #define NULL 0
#endif // #if !defined(NULL)

#define L_MAXPATH    264   // 64-bit needs this to be multiple of 8

#if !defined(EXTERN_C)
   #if defined(__cplusplus)
      #define EXTERN_C extern "C"
   #else
      #define EXTERN_C extern
   #endif // #if defined(__cplusplus)
#endif // #if !defined(EXTERN_C)

#define L_STDCALL       WINAPI
#define EXT_CALLBACK    WINAPI
#define pEXT_CALLBACK   EXT_CALLBACK*
#define EXT_FUNCTION    WINAPI
#define pEXT_FUNCTION   EXT_FUNCTION*

typedef WPARAM          L_WPARAM;
typedef LPARAM          L_LPARAM;
typedef LRESULT         L_LRESULT;

// Structures
typedef RGBQUAD            L_RGBQUAD;
typedef POINT              L_POINT;
typedef RECT               L_RECT;
typedef SIZE               L_SIZE;
typedef BITMAPINFOHEADER   L_BITMAPINFOHEADER;
typedef BITMAPINFO         L_BITMAPINFO;
typedef struct tagL_RGBQUAD16
{
   L_UINT16 rgbBlue;
   L_UINT16 rgbGreen;
   L_UINT16 rgbRed;
   L_UINT16 rgbReserved;
} L_RGBQUAD16;

#if defined(FOR_UWP)
typedef RGBQUAD *LPRGBQUAD;
#endif // #if defined(FOR_UWP)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTTYP_H)
