//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

// LtPlatforms.h - useful macros to aid in porting code

#if !defined(LTPLATFORMS_H)
#define LTPLATFORMS_H

#if !defined(L_LTKRN_CLASS)
#  if !defined(FOR_MANAGED) && !defined(FOR_BORLAND) && !defined(FOR_LIB) && !defined(FOR_UNIX) && !defined(FOR_MANAGEDLIB)
#     define L_LTKRN_CLASS __declspec(dllimport)
#  elif defined(FOR_UNIX)
#     define L_LTKRN_CLASS __attribute__((visibility("default")))
#  else
#     define L_LTKRN_CLASS
#  endif
#endif

// Disable this for XCODE
#if defined(FOR_XCODE)
// warning : ISO C++11 does not allow conversion from string literal to 'L_WCHAR *' (aka 'wchar_t *')[-Wwritable-strings]
#pragma clang diagnostic ignored "-Wwritable-strings"
#endif // #if defined(FOR_XCODE)

// In windows, filenames use backslashes. In Unix/Linux, use forward slashes
#if defined(FOR_WINDOWS) || defined(FOR_UWP)
#define FILENAME_SEPARATOR '\\'
#define BAD_FILENAME_SEPARATOR '/'
#else
#define FILENAME_SEPARATOR '/'
#define BAD_FILENAME_SEPARATOR '\\'
#endif // #if defined(FOR_WINDOWS) || defined(FOR_UWP)

#if defined(FOR_UNIX) && !defined(_DEBUG) && !defined(DEBUG) && !defined(NDEBUG)
#  define NDEBUG
#endif // #if defined(FOR_UNIX) && !defined(_DEBUG) && !defined(DEBUG) && !defined(NDEBUG)

#ifndef MWT_SET
#define MWT_SET 4
#endif // #ifndef MWT_SET

#if defined(FOR_WINDOWS)
   #include <windows.h>
   typedef ULONG              L_THREADID;
   #define L_CloseHandle      CloseHandle
   #define L_CreateHandle(x)  x
   #define L_ExtractHandle(x) x
   #define L_CreateThread     CreateThread
   #define L_Sleep            Sleep
   #define L_ResumeThread     ResumeThread
   #define L_ExitThread       ExitThread
   #define L_EXTRACTEVENTHANDLE L_ExtractHandle
   #define MultiByteToUTF16 MultiByteToWideChar
   #define UTF16ToMultiByte WideCharToMultiByte
#else

#if defined(FOR_UWP)
   #include <windows.h>
   #include <stdlib.h>     // for qsort

   #if !defined(_stprintf_s)
   #define _stprintf_s     swprintf_s
   #endif // #if !defined(_stprintf_s)

   typedef ULONG              L_THREADID;
   #define L_CLOSEEVENTHANDLE CloseHandle
   #define L_CreateThread     CreateThread
   #define L_Sleep            Sleep
   #define L_ResumeThread     ResumeThread
   #define L_ExitThread       ExitThread
   #define L_EXTRACTEVENTHANDLE(x) x
   #define MultiByteToUTF16 MultiByteToWideChar
   #define UTF16ToMultiByte WideCharToMultiByte

#else
   // Unix platforms (Linux, Android, Mac)
   #include <sys/types.h>  // for size_t
   #include <stdlib.h>     //
   #include <stddef.h>
   #include <errno.h>      // for error codes
   #include <stdarg.h>     // for va_list
   #include <unistd.h>     // for getpid
#if defined(FOR_XCODE)
   #include <malloc/malloc.h>     // for malloc_usable_size
#else
   #include <malloc.h>     // for malloc_usable_size
#endif // #if defined(FOR_XCODE)

#if defined(_MSC_VER)
#if defined(LT_USE_PTHREADS)
   #include <pthread.h>
#else
   typedef void* pthread_t;
   typedef void* pthread_mutex_t;
   typedef void* pthread_cond_t;
#endif
#else
   #include <pthread.h>    // for pthread_mutex_t
#endif // #if defined(_MSC_VER)
   
   #include <stdint.h>
   #include <ctype.h>
   typedef pthread_t L_THREADID;
#endif // #if defined(FOR_UWP)

#if defined(FOR_LINUX)
   #include <stdarg.h>
   #include <wctype.h>
#endif // #if defined(FOR_LINUX)

#if defined(LT_COMP_UNICODE)
#include <stdio.h>      // you have to include this before wchar.h, otherwise you get a compiler warning
#include <wchar.h>      // for wcscasecmp
#endif // #if defined(LT_COMP_UNICODE)

#if !defined(DECLARE_HANDLE)
   #define DECLARE_HANDLE(name) typedef HANDLE name
#endif // #if !defined(DECLARE_HANDLE)

#if defined(FOR_ANDROID)
#  include <android/log.h>
#  if !defined(LOG_TAG)
#     define  LOG_TAG    "leadtools"
#  endif
#  if !defined(LOGI)
#     define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)
#  endif
#  if !defined(LOGE)
#     define  LOGE(...)  __android_log_print(ANDROID_LOG_ERROR,LOG_TAG,__VA_ARGS__)
#  endif
#elif defined(FOR_XCODE) || defined(FOR_LINUX)
#  if !defined(LOGI)
   #ifdef _DEBUG
      #define  LOGI(...) fprintf(stdout, __VA_ARGS__)
   #else
      #define  LOGI(...) /* Nothing */
   #endif // #ifdef _DEBUG
#  endif // #  if !defined(LOGI)

#  if !defined(LOGE)
   #ifdef _DEBUG
      #define LOGE(...) fprintf(stderr, __VA_ARGS__)
   #else
      #define LOGE(...) /* Nothing */
   #endif // #ifdef _DEBUG
#endif // #  if !defined(LOGE)
#endif // #if defined(FOR_ANDROID)

// Define in here functions and typedefs that should be in the windows.h from the Windows SDK
#ifdef __cplusplus 
extern "C"
{
#endif // #ifdef __cplusplus 
   
#pragma pack(1)

// Constant defines
#if !defined(MAX_PATH)
#define MAX_PATH 260
#endif // #if !defined(MAX_PATH)

#if !defined(_MAX_PATH)
#define _MAX_PATH MAX_PATH
#endif // #if !defined(_MAX_PATH)

#if !defined(_stprintf)
#define _stprintf       _swprintf
#endif

#if !defined(_MSC_VER)
#define _swprintf sprintf
#define _tcscmp L_STRCMP
#define _tcstok L_STRTOK
#define _tcsncpy  strncpy
#define _tcscpy  strcpy
#define _istalnum isalnum
#define _tcstol strtol
#define _tcstod strtod
#define _strcmpi strcasecmp
#define _mkgmtime timegm
#define _atoi64 atoll
#define _atof atof

#if defined(FOR_XCODE)
   #define _msize malloc_size
#else
   #define _msize malloc_usable_size
   #if defined(FOR_ANDROID) && __ANDROID_API__ < 17
      #define malloc_usable_size(x) 0
   #endif // #if defined(FOR_ANDROID) && __ANDROID_API__ < 17
#endif //  #if defined(FOR_XCODE)

#endif // #if !defined(_MSC_VER)

#ifndef FALSE
#define FALSE               0
#endif

#ifndef TRUE
#define TRUE                1
#endif

#ifndef INVALID_HANDLE_VALUE
#define INVALID_HANDLE_VALUE     ((HANDLE)-1)
#define INVALID_FILE_SIZE        ((DWORD)0xFFFFFFFF)
#define INVALID_SET_FILE_POINTER ((DWORD)-1)
#define INVALID_FILE_ATTRIBUTES  ((DWORD)-1)
#endif // #ifndef INVALID_HANDLE_VALUE

#define PAGE_READWRITE         0x04
#ifndef SEC_COMMIT
#define SEC_COMMIT        0x8000000
#endif // #ifndef SEC_COMMIT

#if !defined(FOR_UWP)
#define SECTION_QUERY                0x0001
#define SECTION_MAP_WRITE            0x0002
#define SECTION_MAP_READ             0x0004
#define SECTION_MAP_EXECUTE          0x0008
#define SECTION_EXTEND_SIZE          0x0010
#define SECTION_MAP_EXECUTE_EXPLICIT 0x0020 // not included in SECTION_ALL_ACCESS

#define STANDARD_RIGHTS_REQUIRED         (0x000F0000L)

#define SECTION_ALL_ACCESS (STANDARD_RIGHTS_REQUIRED|SECTION_QUERY|\
                            SECTION_MAP_WRITE |      \
                            SECTION_MAP_READ |       \
                            SECTION_MAP_EXECUTE |    \
                            SECTION_EXTEND_SIZE)

// MapViewOfFile defines
#define FILE_MAP_WRITE        SECTION_MAP_WRITE
#define FILE_MAP_READ         SECTION_MAP_READ
#define FILE_MAP_COPY         SECTION_QUERY
#define FILE_MAP_ALL_ACCESS   SECTION_ALL_ACCESS
#define FILE_MAP_EXECUTE      SECTION_MAP_EXECUTE_EXPLICIT    // not included in FILE_MAP_ALL_ACCESS
#endif // #if !defined(FOR_UWP)

#define CREATE_NEW          1
#define CREATE_ALWAYS       2
#define OPEN_EXISTING       3
#define OPEN_ALWAYS         4
#define TRUNCATE_EXISTING   5
#define FILE_SHARE_READ                 0x00000001
#define FILE_SHARE_WRITE                0x00000002
#define FILE_SHARE_DELETE               0x00000004
#define FILE_ATTRIBUTE_READONLY             0x00000001
#define FILE_ATTRIBUTE_HIDDEN               0x00000002
#define FILE_ATTRIBUTE_SYSTEM               0x00000004
#define FILE_ATTRIBUTE_DIRECTORY            0x00000010
#define FILE_ATTRIBUTE_ARCHIVE              0x00000020
#define FILE_ATTRIBUTE_DEVICE               0x00000040
#define FILE_ATTRIBUTE_NORMAL               0x00000080
#define FILE_ATTRIBUTE_TEMPORARY            0x00000100
#define FILE_ATTRIBUTE_SPARSE_FILE          0x00000200
#define FILE_ATTRIBUTE_REPARSE_POINT        0x00000400
#define FILE_ATTRIBUTE_COMPRESSED           0x00000800
#define FILE_ATTRIBUTE_OFFLINE              0x00001000
#define FILE_ATTRIBUTE_NOT_CONTENT_INDEXED  0x00002000
#define FILE_ATTRIBUTE_ENCRYPTED            0x00004000
#define FILE_ATTRIBUTE_VIRTUAL              0x00010000
#define GENERIC_READ                     (0x80000000L)
#define GENERIC_WRITE                    (0x40000000L)
#define GENERIC_EXECUTE                  (0x20000000L)
#define GENERIC_ALL                      (0x10000000L)
    
#if !defined(MOVEFILE_COPY_ALLOWED)
#  define MOVEFILE_REPLACE_EXISTING   0x00000001
#  define MOVEFILE_COPY_ALLOWED       0x00000002
#  define MOVEFILE_DELAY_UNTIL_REBOOT 0x00000004
#  define MOVEFILE_WRITE_THROUGH      0x00000008
#endif

   //
// File creation flags must start at the high end since they
// are combined with the attributes
//

#define FILE_FLAG_WRITE_THROUGH         0x80000000
#define FILE_FLAG_OVERLAPPED            0x40000000
#define FILE_FLAG_NO_BUFFERING          0x20000000
#define FILE_FLAG_RANDOM_ACCESS         0x10000000
#define FILE_FLAG_SEQUENTIAL_SCAN       0x08000000
#define FILE_FLAG_DELETE_ON_CLOSE       0x04000000
#define FILE_FLAG_BACKUP_SEMANTICS      0x02000000
#define FILE_FLAG_POSIX_SEMANTICS       0x01000000
#define FILE_FLAG_OPEN_REPARSE_POINT    0x00200000
#define FILE_FLAG_OPEN_NO_RECALL        0x00100000
#define FILE_FLAG_FIRST_PIPE_INSTANCE   0x00080000

#define RC_PALETTE         0x0100      /* supports a palette           */

#define MM_TEXT            1

#define COLORONCOLOR       3
#define HALFTONE           4

#define TECHNOLOGY         2
#define DT_RASPRINTER      2
#define DIB_RGB_COLORS     0
#define DIB_PAL_COLORS     1
#if !defined(GDI_ERROR)
#define GDI_ERROR (0xFFFFFFFF)
#endif // #if !defined(GDI_ERROR)

/* palette entry flags */

#define PC_RESERVED     0x01    /* palette index used for animation */
#define PC_EXPLICIT     0x02    /* palette index is explicit to device */
#define PC_NOCOLLAPSE   0x04    /* do not match color to system palette */

#define RGB(r,g,b)          ((COLORREF)(((BYTE)(r)|((WORD)((BYTE)(g))<<8))|(((DWORD)(BYTE)(b))<<16)))
#define CMYK(c,m,y,k)       ((COLORREF)((((BYTE)(k)|((WORD)((BYTE)(y))<<8))|(((DWORD)(BYTE)(m))<<16))|(((DWORD)(BYTE)(c))<<24)))
#define PALETTERGB(r,g,b)   (0x02000000 | RGB(r,g,b))
#define PALETTEINDEX(i)     ((COLORREF)(0x01000000 | (DWORD)(WORD)(i)))

#define GetRValue(rgb)      (LOBYTE(rgb))
#define GetGValue(rgb)      (LOBYTE(((WORD)(rgb)) >> 8))
#define GetBValue(rgb)      (LOBYTE((rgb)>>16))
    
#define GetKValue(cmyk)     ((BYTE)(cmyk))
#define GetYValue(cmyk)     ((BYTE)((cmyk)>> 8))
#define GetMValue(cmyk)     ((BYTE)((cmyk)>>16))
#define GetCValue(cmyk)     ((BYTE)((cmyk)>>24))

#define MAKEWORD(a, b)      ((WORD)(((BYTE)(((DWORD_PTR)(a)) & 0xff)) | ((WORD)((BYTE)(((DWORD_PTR)(b)) & 0xff))) << 8))
#define MAKELONG(a, b)      ((LONG)(((WORD)(((DWORD_PTR)(a)) & 0xffff)) | ((DWORD)((WORD)(((DWORD_PTR)(b)) & 0xffff))) << 16))
#define LOWORD(l)           ((WORD)(((DWORD_PTR)(l)) & 0xffff))
#define HIWORD(l)           ((WORD)((((DWORD_PTR)(l)) >> 16) & 0xffff))
#define LOBYTE(w)           ((BYTE)(((DWORD_PTR)(w)) & 0xff))
#define HIBYTE(w)           ((BYTE)((((DWORD_PTR)(w)) >> 8) & 0xff))

/* MMIO macros */
#define MAKEFOURCC(ch0, ch1, ch2, ch3)                              \
                ((DWORD)(BYTE)(ch0) | ((DWORD)(BYTE)(ch1) << 8) |   \
                ((DWORD)(BYTE)(ch2) << 16) | ((DWORD)(BYTE)(ch3) << 24 ))
#define mmioFOURCC(ch0, ch1, ch2, ch3)  MAKEFOURCC(ch0, ch1, ch2, ch3)

#ifndef NEAR
#define NEAR
#define FAR
#define near
#define far
#endif // #ifndef NEAR

#if !defined(FOR_UWP) && !defined(_MSC_VER)
#define _O_RDONLY       O_RDONLY /* open for reading only */
#define _O_WRONLY       O_WRONLY /* open for writing only */
#define _O_RDWR         O_RDWR   /* open for reading and writing */
#define _O_APPEND       O_APPEND /* writes done at eof */

   // #define _O_CREAT        O_CREAT  /* create and open file */
#define _O_TRUNC        O_TRUNC  /* open and truncate */
#define _O_EXCL         O_EXCL   /* open only if file doesn't already exist */
#define _O_CREAT        O_CREAT /* create and open file */

#define _O_RANDOM       0x0010  /* file access is primarily random */
#define _O_TEMPORARY    0x0040  /* temporary file bit */
#define _O_TEXT         0x4000  /* file mode is text (translated) */
#define _O_BINARY       0x8000  /* file mode is binary (untranslated) */

#define _S_IFMT         0xF000          /* file type mask */
#define _S_IFDIR        0x4000          /* directory */
#define _S_IFCHR        0x2000          /* character special */
#define _S_IFIFO        0x1000          /* pipe */
#define _S_IFREG        0x8000          /* regular */
#define _S_IREAD        0x0100          /* read permission, owner */
#define _S_IWRITE       0x0080          /* write permission, owner */
#define _S_IEXEC        0x0040          /* execute/search permission, owner */

#else
   /* Seek method constants */
#define SEEK_CUR    1
#define SEEK_END    2
#define SEEK_SET    0
#endif // #if !defined(FOR_UWP) && !defined(_MSC_VER)

#if !defined(O_TEMPORARY)
#  define O_TEMPORARY _O_TEMPORARY
#endif // #if !defined(O_TEMPORARY)
#if !defined(O_TEXT)
#  define O_TEXT _O_TEXT
#endif // #if !defined(O_TEXT)
#if !defined(O_BINARY)
#  define O_BINARY      _O_BINARY
#endif // #if !defined(O_BINARY)

#if !defined(_MSC_VER) && ((defined(FOR_ANDROID) || defined(FOR_LINUX)))
#include <linux/stat.h> // for S_IFMT
#endif // #if (defined(FOR_ANDROID) || defined(FOR_LINUX))

#if !defined(S_IWRITE)
#define S_IWRITE _S_IWRITE
#endif // #if !defined(S_IWRITE)
#if !defined(S_IREAD)
#define S_IREAD  _S_IREAD
#endif // #if !defined(S_IREAD)

#ifndef WINGDIAPI
#define WINGDIAPI
#endif // #ifndef WINGDIAPI

#ifndef ERROR_WRITE_FAULT
#define ERROR_WRITE_FAULT                229L      // need a better error code here
#define ERROR_READ_FAULT                 230L      // need a better error code here
#define ERROR_FILE_EXISTS                EEXIST
#define ERROR_DISK_FULL                  ENOSPC
#define ERROR_HANDLE_DISK_FULL           EDQUOT
#define ERROR_INSUFFICIENT_BUFFER        122L
#define ERROR_FILE_NOT_FOUND             2L
#define ERROR_NOT_ENOUGH_MEMORY          8L
#define ERROR_OUTOFMEMORY                14L
#define ERROR_ACCESS_DENIED              EACCES
#define ERROR_PATH_NOT_FOUND             20L


#define FILE_BEGIN           SEEK_SET
#define FILE_CURRENT         SEEK_CUR
#define FILE_END             SEEK_END
#endif // #ifndef ERROR_WRITE_FAULT

#ifndef INFINITE
#define INFINITE                          ((DWORD)-1)
#define STATUS_WAIT_0                     ((DWORD   )0x00000000L)
#define STATUS_ABANDONED_WAIT_0           ((DWORD   )0x00000080L)

#define WAIT_FAILED ((DWORD)0xFFFFFFFF)
#define WAIT_OBJECT_0       ((STATUS_WAIT_0 ) + 0 )

#define WAIT_ABANDONED         ((STATUS_ABANDONED_WAIT_0 ) + 0 )
#define WAIT_ABANDONED_0       ((STATUS_ABANDONED_WAIT_0 ) + 0 )

#define WAIT_TIMEOUT                     258L    // dderror
#endif // #ifndef INFINITE

   // PolyFill() Modes
#ifndef WINDING
#define ALTERNATE                    1
#define WINDING                      2
#endif // #ifndef WINDING

#if !defined(UNREFERENCED_PARAMETER)
#  if defined(_MSC_VER)
#     define UNREFERENCED_PARAMETER(P) (P)
#  else
#     define UNREFERENCED_PARAMETER(expr) (void)(expr)
#  endif
#endif // #if !defined(UNREFERENCED_PARAMETER)

#if !defined(_countof)
#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#endif // #if !defined(_countof)

#if !defined(FOR_UWP)
// undefine __declspec for other platforms
#define __declspec(XXX)
#endif // #if !defined(FOR_UWP)

#if defined(__cplusplus)
   #define EXTERN_C extern "C"
#else
   #define EXTERN_C extern
#endif // #if defined(__cplusplus)

#define SAFE_FREE(ptr) if(ptr) {free(ptr); (ptr) = NULL; }

#define CREATE_SUSPENDED                  0x00000004
#define TLS_OUT_OF_INDEXES                ((DWORD)0xFFFFFFFF)

#define DUPLICATE_CLOSE_SOURCE      0x00000001
#define DUPLICATE_SAME_ACCESS       0x00000002

#define GMEM_FIXED            0x0000
#define GMEM_MOVEABLE         0x0002
#define GMEM_NOCOMPACT        0x0010
#define GMEM_NODISCARD        0x0020
#define GMEM_ZEROINIT         0x0040
#define GMEM_MODIFY           0x0080
#define GMEM_DISCARDABLE      0x0100
#define GMEM_NOT_BANKED       0x1000
#define GMEM_SHARE            0x2000
#define GMEM_DDESHARE         0x2000
#define GMEM_NOTIFY           0x4000
#define GMEM_INVALID_HANDLE   0x8000
#define GMEM_LOWER            GMEM_NOT_BANKED
#define GHND                  (GMEM_MOVEABLE | GMEM_ZEROINIT)
#define GPTR                  (GMEM_FIXED | GMEM_ZEROINIT)

#define DLL_PROCESS_ATTACH   1
#define DLL_THREAD_ATTACH    2
#define DLL_THREAD_DETACH    3
#define DLL_PROCESS_DETACH   0

// Typedefs and type-related defines
#if !defined(FOR_UWP)
typedef unsigned int        DWORD;
#endif // #if !defined(FOR_UWP)

typedef int                 L_BOOL;

#if (defined(FOR_XCODE) && !defined(__OBJC__)) || !defined(FOR_XCODE)
typedef L_BOOL              BOOL;
#endif // #if (defined(FOR_XCODE) && !defined(__OBJC__)) || !defined(FOR_XCODE)
   
typedef unsigned char       BYTE;
typedef unsigned short      WORD;
typedef float               FLOAT;
typedef FLOAT              *PFLOAT;
typedef L_BOOL             *PBOOL;
typedef L_BOOL             *LPBOOL;
typedef BYTE               *PBYTE;
typedef BYTE               *LPBYTE;
typedef int                *PINT;
typedef int                *LPINT;
typedef WORD               *PWORD;
typedef WORD               *LPWORD;
#if !defined(FOR_UWP)
typedef int                *LPLONG;
typedef int                *PLONG;
#endif // #if !defined(FOR_UWP)
typedef DWORD              *PDWORD;
typedef DWORD              *LPDWORD;
typedef void               *LPVOID;
typedef const void         *LPCVOID;
typedef char               *LPSTR, *LPCH;
typedef const char         *LPCSTR;
typedef const wchar_t      *LPCWSTR;
typedef wchar_t            *LPWSTR;

typedef int                 INT;
typedef unsigned int        UINT;
typedef unsigned int        *PUINT;
#if !defined(FOR_UWP)
typedef unsigned int        ULONG;
#endif // #if !defined(FOR_UWP)
typedef ULONG *PULONG;
typedef unsigned short USHORT;
typedef USHORT *PUSHORT;
typedef unsigned char UCHAR;
typedef UCHAR *PUCHAR;
typedef char *PSZ;

typedef char CHAR;
typedef short SHORT;
#if !defined(FOR_UWP)
typedef int LONG;
#endif // #if !defined(FOR_UWP)

typedef wchar_t WCHAR;    // wc,   16 or 32-bit UNICODE character

#define             __int64     long long

typedef signed char         INT8, *PINT8;
typedef signed short        INT16, *PINT16;
typedef signed int          INT32, *PINT32;
typedef signed __int64      INT64, *PINT64;
typedef unsigned char       UINT8, *PUINT8;
typedef unsigned short      UINT16, *PUINT16;
typedef unsigned int        UINT32, *PUINT32;
typedef unsigned __int64    UINT64, *PUINT64;

#if !defined(_W64)
#if defined(FOR_UNIX64) || defined(FOR_X64) || defined(__LP64__)
#  define _W64 long
#else
#  define _W64
#endif // #if defined(FOR_UNIX64) || defined(FOR_X64) || defined(__LP64__)
#endif // #if !defined(_W64)

#if !defined(_WIN64) && !defined(WIN64)
typedef _W64 int INT_PTR, *PINT_PTR;
typedef _W64 unsigned int UINT_PTR, *PUINT_PTR;
typedef _W64 long LONG_PTR, *PLONG_PTR;
typedef _W64 unsigned long ULONG_PTR, *PULONG_PTR;
#endif // #if !defined(_WIN64)

typedef ULONG_PTR SIZE_T, *PSIZE_T;
typedef LONG_PTR SSIZE_T, *PSSIZE_T;
#define L_LONG_PTR_DEFINED

#define VOID void
typedef VOID    *PVOID;
#define CONST   const

typedef DWORD   COLORREF;
typedef DWORD   *LPCOLORREF;

#ifndef _TCHAR_DEFINED
#  define _TCHAR_DEFINED
#  if defined(_LEAD_FORCE_UNICODE_)
typedef wchar_t TCHAR, *PTCHAR;
typedef CONST   TCHAR  *LPCTSTR;
typedef wchar_t TBYTE, *PTBYTE;
#  else
typedef char  TCHAR, *PTCHAR;
typedef CONST TCHAR  *LPCTSTR;
typedef char  TBYTE, *PTBYTE;
#  endif // #if defined(_LEAD_FORCE_UNICODE_)
#endif // #ifndef _TCHAR_DEFINED

typedef UINT_PTR           WPARAM;
typedef LONG_PTR           LPARAM;
typedef LONG_PTR           LRESULT;
typedef ULONG_PTR          DWORD_PTR, *PDWORD_PTR;

typedef LONG HRESULT;

#if !defined(S_OK)
#  define S_OK                                   ((HRESULT)0L)
#endif
#if !defined(S_FALSE)
#  define S_FALSE                                ((HRESULT)1L)
#endif
#if !defined(SUCCEEDED)
#  define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)
#endif
#if !defined(FAILED)
#  define FAILED(hr) (((HRESULT)(hr)) < 0)
#endif
#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)
#if !defined(E_FAIL)
#  define E_FAIL _HRESULT_TYPEDEF_(0x80004005L)
#endif
#if !defined(E_NOTIMPL)
#  define E_NOTIMPL                        _HRESULT_TYPEDEF_(0x80004001L)
#endif
   
#define FACILITY_WIN32                   7
#define HRESULT_FROM_WIN32(x) ((HRESULT)(x) <= 0 ? ((HRESULT)(x)) : ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_WIN32 << 16) | 0x80000000)))

#ifndef STDMETHODCALLTYPE
#define STDMETHODCALLTYPE       __cdecl
#endif // #ifndef STDMETHODCALLTYPE
#define STDMETHODIMP            HRESULT STDMETHODCALLTYPE
#define STDMETHODIMP_(type)     type STDMETHODCALLTYPE

#if !defined(FOR_UWP)
typedef struct tagRGBTRIPLE {
        BYTE    rgbtBlue;
        BYTE    rgbtGreen;
        BYTE    rgbtRed;
} RGBTRIPLE, *PRGBTRIPLE, NEAR *NPRGBTRIPLE, FAR *LPRGBTRIPLE;

typedef struct tagRGBQUAD {
        BYTE    rgbBlue;
        BYTE    rgbGreen;
        BYTE    rgbRed;
        BYTE    rgbReserved;
} RGBQUAD;
typedef RGBQUAD *LPRGBQUAD;

typedef struct tagPOINT
{
    LONG  x;
    LONG  y;
} POINT, *PPOINT, NEAR *NPPOINT, FAR *LPPOINT;

typedef struct _POINTL      /* ptl  */
{
    LONG  x;
    LONG  y;
} POINTL, *PPOINTL;

typedef struct tagRECT
{
    LONG    left;
    LONG    top;
    LONG    right;
    LONG    bottom;
} RECT, *PRECT, NEAR *NPRECT, FAR *LPRECT;

typedef const RECT FAR* LPCRECT;

typedef struct tagSIZE
{
    LONG        cx;
    LONG        cy;
} SIZE, *PSIZE, *LPSIZE;
#endif // #if !defined(FOR_UWP)

/* constants for the biCompression field */
#define BI_RGB        0L
#define BI_RLE8       1L
#define BI_RLE4       2L
#define BI_BITFIELDS  3L
#define BI_JPEG       4L
#define BI_PNG        5L

typedef struct tagBITMAPCOREHEADER {
        DWORD   bcSize;                 /* used to get to color table */
        WORD    bcWidth;
        WORD    bcHeight;
        WORD    bcPlanes;
        WORD    bcBitCount;
} BITMAPCOREHEADER, FAR *LPBITMAPCOREHEADER, *PBITMAPCOREHEADER;

#if !defined(FOR_UWP)
typedef struct tagBITMAPINFOHEADER{
        DWORD      biSize;
        LONG       biWidth;
        LONG       biHeight;
        WORD       biPlanes;
        WORD       biBitCount;
        DWORD      biCompression;
        DWORD      biSizeImage;
        LONG       biXPelsPerMeter;
        LONG       biYPelsPerMeter;
        DWORD      biClrUsed;
        DWORD      biClrImportant;
} BITMAPINFOHEADER, FAR *LPBITMAPINFOHEADER, *PBITMAPINFOHEADER;

typedef struct tagBITMAPINFO {
    BITMAPINFOHEADER    bmiHeader;
    RGBQUAD             bmiColors[1];
} BITMAPINFO, FAR *LPBITMAPINFO, *PBITMAPINFO;
#endif // #if !defined(FOR_UWP)

typedef struct tagBITMAPFILEHEADER {
        WORD    bfType;
        DWORD   bfSize;
        WORD    bfReserved1;
        WORD    bfReserved2;
        DWORD   bfOffBits;
} BITMAPFILEHEADER, FAR *LPBITMAPFILEHEADER, *PBITMAPFILEHEADER;

typedef struct tagBITMAPCOREINFO {
   BITMAPCOREHEADER    bmciHeader;
   RGBTRIPLE           bmciColors[1];
} BITMAPCOREINFO, FAR *LPBITMAPCOREINFO, *PBITMAPCOREINFO;

#if !defined(FOR_UWP)
#define __stdcall
#define __cdecl
#endif // #if !defined(FOR_UWP)
#define CALLBACK    __stdcall
#define WINAPI      __stdcall
#define WINAPIV     __cdecl
#define APIENTRY    WINAPI
#define APIPRIVATE  __stdcall
#define PASCAL      __stdcall

typedef __int64 LONGLONG;

#if !defined(FOR_UWP)
typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    };
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
} LARGE_INTEGER;

typedef LARGE_INTEGER *PLARGE_INTEGER;

typedef union _ULARGE_INTEGER {
    struct {
        DWORD LowPart;
        DWORD HighPart;
    };
    struct {
        DWORD LowPart;
        DWORD HighPart;
    } u;
    LONGLONG QuadPart;
} ULARGE_INTEGER;

typedef ULARGE_INTEGER *PULARGE_INTEGER;

typedef struct  tagXFORM
  {
    FLOAT   eM11;
    FLOAT   eM12;
    FLOAT   eM21;
    FLOAT   eM22;
    FLOAT   eDx;
    FLOAT   eDy;
  } XFORM, *PXFORM, FAR *LPXFORM;

/* Bitmap Header Definition */
typedef struct tagBITMAP
  {
    LONG        bmType;
    LONG        bmWidth;
    LONG        bmHeight;
    LONG        bmWidthBytes;
    WORD        bmPlanes;
    WORD        bmBitsPixel;
    LPVOID      bmBits;
  } BITMAP, *PBITMAP, NEAR *NPBITMAP, FAR *LPBITMAP;

typedef struct tagLOGPEN
  {
    UINT        lopnStyle;
    POINT       lopnWidth;
    COLORREF    lopnColor;
  } LOGPEN, *PLOGPEN, NEAR *NPLOGPEN, FAR *LPLOGPEN;
#endif // #if !defined(FOR_UWP)

typedef struct tagEXTLOGPEN {
    DWORD       elpPenStyle;
    DWORD       elpWidth;
    UINT        elpBrushStyle;
    COLORREF    elpColor;
    ULONG_PTR   elpHatch;     //Sundown: elpHatch could take a HANDLE
    DWORD       elpNumEntries;
    DWORD       elpStyleEntry[1];
} EXTLOGPEN, *PEXTLOGPEN, NEAR *NPEXTLOGPEN, FAR *LPEXTLOGPEN;

#if !defined(FOR_UWP)
typedef struct tagPALETTEENTRY {
    BYTE        peRed;
    BYTE        peGreen;
    BYTE        peBlue;
    BYTE        peFlags;
} PALETTEENTRY, *PPALETTEENTRY, FAR *LPPALETTEENTRY;

typedef struct tagLOGPALETTE {
    WORD        palVersion;
    WORD        palNumEntries;
    /*__field_ecount_opt(palNumEntries)*/ PALETTEENTRY        palPalEntry[1];
} LOGPALETTE, *PLOGPALETTE, NEAR *NPLOGPALETTE, FAR *LPLOGPALETTE;

typedef struct tagLOGBRUSH
  {
    UINT        lbStyle;
    COLORREF    lbColor;
    ULONG_PTR   lbHatch;    // Sundown: lbHatch could hold a HANDLE
  } LOGBRUSH, *PLOGBRUSH, NEAR *NPLOGBRUSH, FAR *LPLOGBRUSH;

/* Logical Font */
#define LF_FACESIZE         32

typedef struct tagLOGFONTA
{
    LONG      lfHeight;
    LONG      lfWidth;
    LONG      lfEscapement;
    LONG      lfOrientation;
    LONG      lfWeight;
    BYTE      lfItalic;
    BYTE      lfUnderline;
    BYTE      lfStrikeOut;
    BYTE      lfCharSet;
    BYTE      lfOutPrecision;
    BYTE      lfClipPrecision;
    BYTE      lfQuality;
    BYTE      lfPitchAndFamily;
    CHAR      lfFaceName[LF_FACESIZE];
} LOGFONTA, *PLOGFONTA, NEAR *NPLOGFONTA, FAR *LPLOGFONTA;

typedef struct tagLOGFONTW
{
    LONG      lfHeight;
    LONG      lfWidth;
    LONG      lfEscapement;
    LONG      lfOrientation;
    LONG      lfWeight;
    BYTE      lfItalic;
    BYTE      lfUnderline;
    BYTE      lfStrikeOut;
    BYTE      lfCharSet;
    BYTE      lfOutPrecision;
    BYTE      lfClipPrecision;
    BYTE      lfQuality;
    BYTE      lfPitchAndFamily;
    WCHAR     lfFaceName[LF_FACESIZE];
} LOGFONTW, *PLOGFONTW, NEAR *NPLOGFONTW, FAR *LPLOGFONTW;

#if defined(LT_COMP_UNICODE)
typedef LOGFONTW LOGFONT;
typedef PLOGFONTW PLOGFONT;
typedef NPLOGFONTW NPLOGFONT;
typedef LPLOGFONTW LPLOGFONT;
#else
typedef LOGFONTA LOGFONT;
typedef PLOGFONTA PLOGFONT;
typedef NPLOGFONTA NPLOGFONT;
typedef LPLOGFONTA LPLOGFONT;
#endif //#if defined(LT_COMP_UNICODE)

typedef struct _GUID {
    ULONG  Data1;
    USHORT Data2;
    USHORT Data3;
    USHORT Data4[ 8 ];
} GUID, *LPGUID;
typedef GUID CLSID;
#define REFGUID const GUID &

typedef GUID IID;
#define REFIID const IID &
#define REFCLSID const IID &

typedef void *IUnknown;
typedef /* [unique] */ IUnknown *LPUNKNOWN;

#ifndef FOR_UNICODE
// ANSI definition
#define __TEXT(quote) quote// r_winnt
#else
// Unicode definition
#define __TEXT(quote) L##quote      // r_winnt
#endif // #ifndef FOR_UNICODE

#define TEXT(quote) __TEXT(quote)   // r_winnt

#if !defined(FOR_UWP) && !defined(_T)
#define _T(quote) TEXT(quote)

typedef int64_t __time64_t;
#endif // #if !defined(FOR_UWP) && !defined(_T)

/* size of a device name string */
#define CCHDEVICENAME 32

/* size of a form name string */
#define CCHFORMNAME 32

typedef struct _devicemodeA {
    BYTE   dmDeviceName[CCHDEVICENAME];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union {
      /* printer only fields */
      struct {
        short dmOrientation;
        short dmPaperSize;
        short dmPaperLength;
        short dmPaperWidth;
        short dmScale;
        short dmCopies;
        short dmDefaultSource;
        short dmPrintQuality;
      };
      /* display only fields */
      struct {
        POINTL dmPosition;
        DWORD  dmDisplayOrientation;
        DWORD  dmDisplayFixedOutput;
      };
    };
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    BYTE   dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    DWORD  dmBitsPerPel;
    DWORD  dmPelsWidth;
    DWORD  dmPelsHeight;
    union {
        DWORD  dmDisplayFlags;
        DWORD  dmNup;
    };
    DWORD  dmDisplayFrequency;
#if(WINVER >= 0x0400)
    DWORD  dmICMMethod;
    DWORD  dmICMIntent;
    DWORD  dmMediaType;
    DWORD  dmDitherType;
    DWORD  dmReserved1;
    DWORD  dmReserved2;
#if (WINVER >= 0x0500) || (_WIN32_WINNT >= _WIN32_WINNT_NT4)
    DWORD  dmPanningWidth;
    DWORD  dmPanningHeight;
#endif
#endif /* WINVER >= 0x0400 */
} DEVMODEA, *PDEVMODEA, *NPDEVMODEA, *LPDEVMODEA;

#if defined(LT_COMP_UNICODE)
typedef struct _devicemodeW {
    WCHAR  dmDeviceName[CCHDEVICENAME];
    WORD dmSpecVersion;
    WORD dmDriverVersion;
    WORD dmSize;
    WORD dmDriverExtra;
    DWORD dmFields;
    union {
      /* printer only fields */
      struct {
        short dmOrientation;
        short dmPaperSize;
        short dmPaperLength;
        short dmPaperWidth;
        short dmScale;
        short dmCopies;
        short dmDefaultSource;
        short dmPrintQuality;
      };
      /* display only fields */
      struct {
        POINTL dmPosition;
        DWORD  dmDisplayOrientation;
        DWORD  dmDisplayFixedOutput;
      };
    };
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    WCHAR  dmFormName[CCHFORMNAME];
    WORD   dmLogPixels;
    DWORD  dmBitsPerPel;
    DWORD  dmPelsWidth;
    DWORD  dmPelsHeight;
    union {
        DWORD  dmDisplayFlags;
        DWORD  dmNup;
    };
    DWORD  dmDisplayFrequency;
#if(WINVER >= 0x0400)
    DWORD  dmICMMethod;
    DWORD  dmICMIntent;
    DWORD  dmMediaType;
    DWORD  dmDitherType;
    DWORD  dmReserved1;
    DWORD  dmReserved2;
#if (WINVER >= 0x0500) || (_WIN32_WINNT >= _WIN32_WINNT_NT4)
    DWORD  dmPanningWidth;
    DWORD  dmPanningHeight;
#endif
#endif /* WINVER >= 0x0400 */
} DEVMODEW, *PDEVMODEW, *NPDEVMODEW, *LPDEVMODEW;
#endif // #if defined(LT_COMP_UNICODE)

typedef struct _RGNDATAHEADER {
    DWORD   dwSize;
    DWORD   iType;
    DWORD   nCount;
    DWORD   nRgnSize;
    RECT    rcBound;
} RGNDATAHEADER, *PRGNDATAHEADER;

typedef struct _RGNDATA {
    RGNDATAHEADER   rdh;
    char            Buffer[1];
} RGNDATA, *PRGNDATA, NEAR *NPRGNDATA, FAR *LPRGNDATA;

/*
 * original NT 32 bit dialog template:
 */
typedef struct {
    DWORD style;
    DWORD dwExtendedStyle;
    WORD cdit;
    short x;
    short y;
    short cx;
    short cy;
} DLGTEMPLATE;

typedef CONST DLGTEMPLATE *LPCDLGTEMPLATEA;
typedef CONST DLGTEMPLATE *LPCDLGTEMPLATEW;

typedef struct _SECURITY_ATTRIBUTES {
    DWORD nLength;
    LPVOID lpSecurityDescriptor;
    L_BOOL bInheritHandle;
} SECURITY_ATTRIBUTES, *PSECURITY_ATTRIBUTES, *LPSECURITY_ATTRIBUTES;

typedef struct _MEMORYSTATUS {
    DWORD dwLength;
    DWORD dwMemoryLoad;
    SIZE_T dwTotalPhys;
    SIZE_T dwAvailPhys;
    SIZE_T dwTotalPageFile;
    SIZE_T dwAvailPageFile;
    SIZE_T dwTotalVirtual;
    SIZE_T dwAvailVirtual;
} MEMORYSTATUS, *LPMEMORYSTATUS;

typedef void *LPOVERLAPPED;

/* Type of the mutex_cond object */
typedef struct mutex_cond
{
   pthread_mutex_t i_mutex;
   pthread_cond_t i_cv;
} mutex_cond_t;

/* Type of the List element object */
typedef struct List_element
{
   struct List_element *next;
   struct List_element *prev;
   struct mutex_cond *i_mutex_cond;
} List_element_t;

/* Type of the List object, Any other implementation
 * of List can be used
 */
typedef struct List
{
   struct List_element *start_list;
   struct List_element *end_list;
   pthread_mutex_t i_mutex;	 /* This mutex is used to protect the List critical section */
} List_t;

typedef DWORD (WINAPI *PTHREAD_START_ROUTINE)(LPVOID lpThreadParameter);
typedef PTHREAD_START_ROUTINE LPTHREAD_START_ROUTINE;

typedef struct _SYSTEM_INFO {
   WORD wProcessorArchitecture;
   WORD wReserved;
   DWORD dwPageSize;
   LPVOID lpMinimumApplicationAddress;
   LPVOID lpMaximumApplicationAddress;
   DWORD_PTR dwActiveProcessorMask;
   DWORD dwNumberOfProcessors;
   DWORD dwProcessorType;
   DWORD dwAllocationGranularity;
   WORD wProcessorLevel;
   WORD wProcessorRevision;
} SYSTEM_INFO, *LPSYSTEM_INFO;

typedef struct _SYSTEMTIME {
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

typedef struct _FILETIME
{
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;

typedef struct _TIME_ZONE_INFORMATION {
    LONG Bias;
    WCHAR StandardName[ 32 ];
    SYSTEMTIME StandardDate;
    LONG StandardBias;
    WCHAR DaylightName[ 32 ];
    SYSTEMTIME DaylightDate;
    LONG DaylightBias;
} TIME_ZONE_INFORMATION, *PTIME_ZONE_INFORMATION, *LPTIME_ZONE_INFORMATION;
#endif // #if !defined(FOR_UWP)

#if defined(FOR_UNIX) // || defined(FOR_UWP)
typedef struct _MEMORYSTATUSEX {
   DWORD dwLength;
   DWORD dwMemoryLoad;
   UINT64 ullTotalPhys;
   UINT64 ullAvailPhys;
   UINT64 ullTotalPageFile;
   UINT64 ullAvailPageFile;
   UINT64 ullTotalVirtual;
   UINT64 ullAvailVirtual;
   UINT64 ullAvailExtendedVirtual;
} MEMORYSTATUSEX, * LPMEMORYSTATUSEX;
#endif // #if defined(FOR_UNIX) || defined(FOR_UWP)

// In WinRT, operating system handles (HANDLE type for File handles). These handles are wrapped into a L_HANDLE
// You delete all these handles with L_CLOSEHANDLE
// Note that you use HANDLE_HANDLE for handles that should be closed with CloseHandle (so no GDI or HGLOBAL handles)
typedef enum tagHANDLETYPE
{
   HANDLE_UNKNOWN,
   HANDLE_PALETTE,
   HANDLE_BITMAP,
   HANDLE_MEMORY,
   HANDLE_REGION,
#if defined(FOR_UWP)
   HANDLE_HDC,
   HANDLE_BRUSH,
   HANDLE_PEN,
   HANDLE_FONT,
#endif // #if defined(FOR_UWP)
#if !defined(FOR_UWP)
   HANDLE_FILE,
   HANDLE_MODULE,
   HANDLE_EVENT,
   HANDLE_MUTEX,
   HANDLE_SEMAPHORE,
   HANDLE_THREAD,
   HANDLE_FILEMAPPING,
#else
   HANDLE_HANDLE,
#endif // #if !defined(FOR_UWP)
} HANDLETYPE;

typedef struct tagHANDLE
{
   HANDLETYPE type;   // the handle type
   union
   {
      struct
      {
         unsigned short palVersion;
         unsigned short palNumEntries;
         PALETTEENTRY palPalEntry[1];
      } Palette;
      struct
      {
         void *ptr;
         unsigned __int64 size;
         unsigned int flags;
      } Memory;
      struct
      {
         void *pRgn;
      } Region;
#if defined(FOR_UWP)
      struct
      {
         void *pDc;
         unsigned int flags;
      } DeviceContext;
      struct
      {
         void *pBrush;
         unsigned int flags;
      } Brush;
      struct
      {
         void *pPen;
         unsigned int flags;
      } Pen;
      struct
      {
         void *pFont;
      } Font;
      struct
      {
         void *pData;
         BITMAPINFO BitmapInfo; 
         int selected;
      } Bitmap;
#endif // #if defined(FOR_UWP)
#if !defined(FOR_UWP)
      struct
      {
         int fd;  // file descriptor for files
         char *pszFileName;
      } File;
      struct
      {
         void *pModule;
         char *pszFileName;
      } Module;
      struct
      {
         L_BOOL bSignalled;     // the predicate
         L_BOOL bManualReset;
      } Event;
      struct
      {
         LONG uCurrentCount;    // the predicate - object is signalled if uCurrentCounter > 0
         LONG uMaxCount;        // maximum counter value
      } Semaphore;
      struct
      {
         L_BOOL bAvailable;     // the predicate
      } Mutex;
      struct
      {
         L_BOOL bFinished;      // the predicate
         pthread_t id;
         LPTHREAD_START_ROUTINE pfnProc;
         LPVOID pUserData;
         LONG refCount;        // reference count (handle can be closed when it goes to 0)
         L_BOOL bWaitForCondition; // indicates whether the thread should wait for hStartThreadEvent
         mutex_cond_t hStartThreadEvent;   // can be NULL if the thread is not created in suspended mode
      } Thread;
      struct
      {
         int fd;                    // the file descriptor
         long page_size;            // the page size - all file mapping offsets should be a multiple of this value
         unsigned __int64 uFileMappingSize; // the size of the file mapping
      } FileMapping;
#else
      struct
      {
         HANDLE hHandle;
      } Handle;
#endif // #if !defined(FOR_UWP)
   };
#if !defined(FOR_UWP)
   pthread_mutex_t m_predicateMutex;   // mutex for the waitable objects
   struct List m_list;                 // list of threads waiting for this object. Valid only for Event and Mutex objects
#endif // #if !defined(FOR_UWP)
} *L_HANDLE;

#if !defined(FOR_UWP)
typedef L_HANDLE HWND;
typedef L_HANDLE HGDIOBJ;
typedef L_HANDLE HDC;
typedef L_HANDLE HRGN;
typedef L_HANDLE HPALETTE;
typedef L_HANDLE HBITMAP;
typedef L_HANDLE HCURSOR;
typedef L_HANDLE HICON;
typedef L_HANDLE HMETAFILE;
typedef L_HANDLE HENHMETAFILE;
typedef L_HANDLE HGLOBAL;
typedef L_HANDLE HINSTANCE;
typedef L_HANDLE HPEN;
typedef L_HANDLE HFONT;
typedef L_HANDLE HBRUSH;
typedef L_HANDLE HMODULE;
typedef L_HANDLE HMENU;
typedef L_HANDLE HANDLE;
#endif // #if !defined(FOR_UWP)

typedef HANDLE HEVENT;
// L_EVENTHANDLE should be used for event, mutex, semaphore and thread handles.
// This is important on UWP, where L_HANDLE and HANDLE are very different
// Must be closed using L_CLOSEEVENTHANDLE.
#if defined(FOR_UWP)
typedef HANDLE L_EVENTHANDLE;
#else
typedef L_HANDLE L_EVENTHANDLE;
#endif // #if defined(FOR_UWP)

#if !defined(FOR_UWP)
typedef pthread_mutex_t CRITICAL_SECTION;
typedef pthread_mutex_t *LPCRITICAL_SECTION;
#endif // #if !defined(FOR_UWP)

// macros for checking whether a handle is valid
#define CHECK_HANDLE(handle, desiredtype, errorcode)     \
   if(handle == INVALID_HANDLE_VALUE || handle == NULL)  \
   {                                                     \
      errno = EINVAL;                                    \
      return errorcode;                                  \
   }                                                     \
   if(handle->type != desiredtype)                       \
   {                                                     \
      errno = EINVAL;                                    \
      return errorcode;                                  \
   }

#if !defined(FOR_UWP)
#define CHECK_FILEHANDLE(handle)  CHECK_HANDLE(handle, HANDLE_FILE, EBADF)
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
L_HANDLE WINAPI L_CreateThread(
   LPSECURITY_ATTRIBUTES lpThreadAttributes,
   SIZE_T dwStackSize,
   LPTHREAD_START_ROUTINE lpStartAddress,
   LPVOID lpParameter,
   DWORD dwCreationFlags,
   L_THREADID* lpThreadId
);
EXTERN_C VOID WINAPI L_Sleep(DWORD dwMilliseconds);
EXTERN_C DWORD WINAPI L_ResumeThread(L_HANDLE hThread);
#define L_ExitThread(ret) // No ExitThread or TerminateThread (just return from the thread function to exit)
#endif // #if !defined(FOR_UWP)

#if defined(FOR_JNI)
EXTERN_C VOID WINAPI L_OnThreadCreated(VOID);
EXTERN_C VOID WINAPI L_OnThreadDestroyed(VOID);
#endif // #if defined(FOR_JNI)

#if defined(FOR_UNIX)
   #define GetCurrentProcess()   NULL
   #define GetCurrentProcessId getpid

   #if !defined(FOR_XCODE)
   HANDLE WINAPI GetCurrentThread(VOID);
   #endif // #if !defined(FOR_XCODE)

   #define GetCurrentThreadId pthread_self
#endif // #if defined(FOR_UNIX)

// function typedefs
#if !defined(FOR_UWP)
typedef INT_PTR (CALLBACK * DLGPROC)(HWND, UINT, WPARAM, LPARAM);
typedef int (FAR WINAPI *FARPROC)(void);
#endif // #if !defined(FOR_UWP)

// functions
#if !defined(FOR_LINUX)
#define GetModuleHandle(X) 0x0000
#else
HMODULE WINAPI GetModuleHandle(const TCHAR* lpModuleName);
#endif

#if !defined(FOR_UWP)
#define GetFileAttributes(psxFileName)  -1
#endif // #if !defined(FOR_UWP)
#define GetDeviceCaps(hdc, index)   0

#define MB_OK                       0x00000000L
      
#define MB_ICONHAND                 0x00000010L
#define MB_ICONQUESTION             0x00000020L
#define MB_ICONEXCLAMATION          0x00000030L
#define MB_ICONASTERISK             0x00000040L
#define MB_ICONINFORMATION          MB_ICONASTERISK
#define MB_ICONSTOP                 MB_ICONHAND

INT WINAPI MessageBox(HWND hWnd, const TCHAR* lpText, const TCHAR* lpCaption, UINT uType);

#define SetFilePointer L_SetFilePointer
DWORD WINAPI L_SetFilePointer(
    HANDLE hFile,
    LONG lDistanceToMove,
    PLONG lpDistanceToMoveHigh,
    DWORD dwMoveMethod
    );

#if !defined(FOR_UWP)
#define IsWindows(x) FALSE
DWORD WINAPI SetFilePointerEx(
    HANDLE hFile,
    LARGE_INTEGER liDistanceToMove,
    PLARGE_INTEGER lpNewFilePointer,
    DWORD dwMoveMethod
    );
#endif // #if !defined(FOR_UWP)

L_HANDLE WINAPI CreatePalette(CONST LOGPALETTE * plpal);
UINT WINAPI GetPaletteEntries(L_HANDLE hpal, UINT iStartIndex, UINT nEntries, LPPALETTEENTRY lppe);
UINT WINAPI SetPaletteEntries(L_HANDLE hpal, UINT iStartIndex, UINT nEntries, CONST PALETTEENTRY* lppe);
UINT WINAPI GetNearestPaletteIndex(L_HANDLE hpal, COLORREF crColor);

L_BOOL WINAPI SetRect(LPRECT lprc, int xLeft, int yTop, int xRight, int yBottom);
L_BOOL WINAPI IsRectEmpty(LPRECT rc);
L_BOOL WINAPI PtInRect(const RECT *lprc, POINT pt);
L_BOOL WINAPI IntersectRect(LPRECT lprcDst, CONST RECT *lprcSrc1, CONST RECT *lprcSrc2);
L_BOOL WINAPI InflateRect(LPRECT lprc, int dx, int dy);
L_BOOL WINAPI CopyRect(LPRECT lprcDst, CONST RECT *lprcSrc);
L_BOOL WINAPI UnionRect(LPRECT lprcDst, CONST RECT *lprcSrc1, CONST RECT *lprcSrc2);
L_BOOL WINAPI OffsetRect(LPRECT lprc, int dx, int dy);

HBRUSH WINAPI CreateSolidBrush(COLORREF color);

#if !defined(FOR_UWP)
int __cdecl _memicmp(const void * _Buf1, const void * _Buf2, size_t _Size);

int __cdecl _wcsicmp(const wchar_t * _Str1, const wchar_t * _Str2);
//int __cdecl wcstombs_s(size_t *pReturnValue, char *mbstr, size_t sizeInBytes, const wchar_t *wcstr, size_t count);
#endif // #if !defined(FOR_UWP)
       
#if defined(FOR_UNIX)
int _splitpath_s(const char *path,
                     char *drive,
                     size_t driveNumberOfElements,
                     char *dir,
                     size_t dirNumberOfElements,
                     char *fname,
                     size_t nameNumberOfElements,
                     char *ext,
                     size_t extNumberOfElements);
       
int _wsplitpath_s(const wchar_t *path,
                      wchar_t *drive,
                      size_t driveNumberOfElements,
                      wchar_t *dir,
                      size_t dirNumberOfElements,
                      wchar_t *fname,
                      size_t nameNumberOfElements,
                      wchar_t *ext,
                      size_t extNumberOfElements);
       
int _makepath_s(char *path,
                    size_t sizeInBytes,
                    const char *drive,
                    const char *dir,
                    const char *fname,
                    const char *ext);
       
int _wmakepath_s(wchar_t *path,
                     size_t sizeInWords,
                     const wchar_t *drive,
                     const wchar_t *dir,
                     const wchar_t *fname,
                     const wchar_t *ext);
#endif // #if defined(FOR_UNIX)

L_HANDLE WINAPI WinGlobalAlloc(UINT uFlags, SIZE_T dwBytes);
L_HANDLE WINAPI WinGlobalReAlloc(L_HANDLE hMem, SIZE_T dwBytes, UINT uFlags);
#define  WinGlobalAllocPtr(flags, cb)           WinGlobalLock(WinGlobalAlloc((flags), (cb)))
#define  WinGlobalReAllocPtr(lp, cbNew, flags)  \
                (WinGlobalUnlockPtr(lp), WinGlobalLock(WinGlobalReAlloc(WinGlobalPtrHandle(lp) , (cbNew), (flags))))
#define  WinGlobalFreePtr(lp)                   \
                (WinGlobalUnlockPtr(lp), (L_BOOL)(ULONG_PTR)WinGlobalFree(WinGlobalPtrHandle(lp)))
#define  WinGlobalUnlockPtr(lp)                 (UNREFERENCED_PARAMETER(lp))
#define  WinGlobalPtrHandle(lp)                 ((L_HANDLE)WinGlobalHandle(lp))
#define  WinGlobalSizePtr(lp)                   WinGlobalSize(WinGlobalHandle(lp))


LPVOID WINAPI WinGlobalLock(L_HANDLE hMem);
L_HANDLE WINAPI WinGlobalHandle(LPVOID pMem);
L_BOOL WINAPI WinGlobalUnlock(L_HANDLE hMem);
size_t WINAPI WinGlobalSize(L_HANDLE hMem);
UINT WINAPI WinGlobalFlags(L_HANDLE hMem);
L_HANDLE WINAPI WinGlobalFree(L_HANDLE hMem);

/*
EXTERN_C L_HANDLE WINAPI WinGlobalAlloc(UINT uFlags, SIZE_T dwBytes);
EXTERN_C L_HANDLE WINAPI WinGlobalReAlloc(L_HANDLE hMem, SIZE_T dwBytes, UINT uFlags);
EXTERN_C LPVOID WINAPI WinGlobalLock(L_HANDLE hMem);
EXTERN_C L_BOOL WINAPI WinGlobalUnlock(L_HANDLE hMem);
EXTERN_C L_HANDLE WINAPI WinGlobalFree(L_HANDLE hMem);
EXTERN_C L_HANDLE WINAPI WinGlobalHandle(LPVOID pMem);
EXTERN_C UINT WINAPI WinGlobalSize(L_HANDLE hMem);
EXTERN_C UINT WINAPI WinGlobalFlags(L_HANDLE hMem);
*/

#if !defined(FOR_UWP)
L_BOOL WINAPI L_CloseHandle(HANDLE hObject);
#define CloseHandle L_CloseHandle
#define L_CreateHandle(x)  x
#define L_ExtractHandle(x) x
#define L_EXTRACTEVENTHANDLE L_ExtractHandle
#else
L_HANDLE WINAPI L_CreateHandle(HANDLE hHandle); // create a LEADTOOLS L_HANDLE from a Windows HANDLE
HANDLE WINAPI L_ExtractHandle(L_HANDLE hObject);
L_BOOL WINAPI L_CloseHandle(L_HANDLE hObject);
//#define L_EXTRACTEVENTHANDLE L_ExtractHandle
#endif // #if !defined(FOR_UWP)

L_BOOL WINAPI DeleteObject(L_HANDLE hObject);

#if !defined(ZeroMemory)
#define ZeroMemory(ptr, len) memset(ptr, 0,len)
#endif // #if !defined(ZeroMemory)

int WINAPI GetObject(L_HANDLE hgdiobj, int cbBuffer, LPVOID lpvObject);

#if !defined(FOR_UWP)
L_HANDLE WINAPI CreateEventA(LPSECURITY_ATTRIBUTES lpEventAttributes, L_BOOL bManualReset, L_BOOL InitialState, const char* lpName);
L_HANDLE WINAPI CreateMutexA(LPSECURITY_ATTRIBUTES lpMutexAttributes, L_BOOL bInitialOwner, const char *lpName);
#endif // #if !defined(FOR_UWP)

#if defined(LT_COMP_UNICODE) && !defined(FOR_UWP)
L_EVENTHANDLE WINAPI CreateEventW(LPSECURITY_ATTRIBUTES lpEventAttributes, L_BOOL bManualReset, L_BOOL InitialState, const wchar_t* lpName);
L_EVENTHANDLE WINAPI CreateMutexW(LPSECURITY_ATTRIBUTES lpMutexAttributes, L_BOOL bInitialOwner, const wchar_t *lpName);
#endif // #if defined(LT_COMP_UNICODE) && !defined(FOR_UWP)

#if !defined(FOR_UWP)
L_BOOL WINAPI SetEvent(HEVENT event);
L_BOOL WINAPI ResetEvent(HEVENT event);
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
L_HANDLE WINAPI CreateSemaphoreA(LPSECURITY_ATTRIBUTES lpSemaphoreAttributes, LONG lInitialCount, LONG lMaximumCount, const char* lpName);
L_BOOL WINAPI ReleaseSemaphore(L_EVENTHANDLE hSemaphore, LONG lReleaseCount, LPLONG lpPreviousCount);
#define CreateSemaphore CreateSemaphoreA
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
DWORD WINAPI L_WaitForSingleObject(L_HANDLE hObject, DWORD msTimeOut);
DWORD WINAPI L_WaitForMultipleObjects(DWORD Count, L_HANDLE* pObjects, L_BOOL bWaitAll, DWORD msTimeOut);
EXTERN_C DWORD WINAPI GetTempPath(DWORD nBufferLength, TCHAR *lpBuffer);
EXTERN_C UINT WINAPI GetTempFileName(const TCHAR *lpPathName, const TCHAR *lpPrefixString, UINT uUnique, TCHAR *lpTempFileName);
#endif // #if !defined(FOR_UWP)

#if defined(FOR_UWP)
EXTERN_C DWORD WINAPI GetCurrentTime(void);
#endif // #if defined(FOR_UWP)

#if !defined(FOR_UWP)
DWORD WINAPI TlsAlloc(void);
#else
#if !defined(FOR_UWP) && (VER_PRODUCTBUILD_QFE <= 17095)// && !defined(_PROCESSTHREADSAPI_H_)
// New SDK defines TlsAlloc for us
DWORD WINAPI TlsAlloc(void);
#endif // #if !defined(FOR_UWP) && (VER_PRODUCTBUILD_QFE <= 17095)
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
#if defined(_MSC_VER)
#pragma warning (disable : 4273)
#endif // #if defined(_MSC_VER)

L_LTKRN_CLASS int WINAPI MulDiv(int x, int y, int z);
//EXTERN_C int WINAPI MulDiv(int x, int y, int z);

L_LTKRN_CLASS void WINAPI InitializeCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
L_LTKRN_CLASS void WINAPI DeleteCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
L_LTKRN_CLASS void WINAPI EnterCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
L_LTKRN_CLASS void WINAPI LeaveCriticalSection(LPCRITICAL_SECTION lpCriticalSection);
L_LTKRN_CLASS LONG WINAPI InterlockedIncrement(LONG volatile *Addend);
L_LTKRN_CLASS LONG WINAPI InterlockedDecrement(LONG volatile *Addend);
L_LTKRN_CLASS INT64 WINAPI InterlockedIncrement64(INT64 volatile *Addend);
L_LTKRN_CLASS INT64 WINAPI InterlockedDecrement64(INT64 volatile *Addend);
L_LTKRN_CLASS L_BOOL WINAPI TlsSetValue(DWORD dwTlsIndex, LPVOID lpTlsValue);
L_LTKRN_CLASS LPVOID WINAPI TlsGetValue(DWORD dwTlsIndex);
L_LTKRN_CLASS L_BOOL WINAPI TlsFree(DWORD dwTlsIndex);

#if defined(_MSC_VER)
#pragma warning (default : 4273)
#endif

#else
#define InitializeCriticalSection(lpCriticalSection) InitializeCriticalSectionEx(lpCriticalSection, 0, 0)
#define TlsSetValue FlsSetValue
#define TlsGetValue FlsGetValue
#define TlsFree FlsFree
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
VOID WINAPI SetLastError(DWORD dwErrCode);
L_BOOL WINAPI ReadFile(
  HANDLE hFile,
  LPVOID lpBuffer,
  DWORD nNumberOfBytesToRead,
  LPDWORD lpNumberOfBytesRead,
  LPOVERLAPPED lpOverlapped
);
L_BOOL WINAPI WriteFile(
  HANDLE hFile,
  LPCVOID lpBuffer,
  DWORD nNumberOfBytesToWrite,
  LPDWORD lpNumberOfBytesWritten,
  LPOVERLAPPED lpOverlapped
);
L_BOOL WINAPI SetEndOfFile(HANDLE hFile);
L_BOOL WINAPI DeleteFile(const TCHAR* lpFileName);
L_BOOL WINAPI DeleteFileA(const char* lpFileName);
L_BOOL WINAPI GetDiskFreeSpaceEx(
    TCHAR *lpDirectoryName,
    PULARGE_INTEGER lpFreeBytesAvailableToCaller,
    PULARGE_INTEGER lpTotalNumberOfBytes,
    PULARGE_INTEGER lpTotalNumberOfFreeBytes
    );
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
L_BOOL WINAPI GetFileSizeEx(L_HANDLE hFile, PLARGE_INTEGER lpFileSize);
#endif // #if !defined(FOR_UWP)

L_HANDLE WINAPI CreateFileA(
    const char *lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
#if defined(LT_COMP_UNICODE)
L_HANDLE WINAPI CreateFileW(
    const wchar_t *lpFileName,
    DWORD dwDesiredAccess,
    DWORD dwShareMode,
    LPSECURITY_ATTRIBUTES lpSecurityAttributes,
    DWORD dwCreationDisposition,
    DWORD dwFlagsAndAttributes,
    HANDLE hTemplateFile
    );
#endif // #if defined(LT_COMP_UNICODE)
#if defined(FOR_UNICODE)
    #define CreateFile CreateFileW
#else
    #define CreateFile CreateFileA
#endif // #if defined(FOR_UNICODE)

#if !defined(FOR_UWP)
EXTERN_C L_HANDLE WINAPI L_CreateFileMappingA(
  L_HANDLE hFile,
  LPSECURITY_ATTRIBUTES lpAttributes,
  DWORD flProtect,
  DWORD dwMaximumSizeHigh,
  DWORD dwMaximumSizeLow,
  const char *lpName,
  L_BOOL bTryMalloc     // set this to TRUE when allocating bitmap memory
                        // false if you want a true file mapping object using mmap
);
#if defined(LT_COMP_UNICODE)
EXTERN_C L_HANDLE WINAPI L_CreateFileMappingW(
  L_HANDLE hFile,
  LPSECURITY_ATTRIBUTES lpAttributes,
  DWORD flProtect,
  DWORD dwMaximumSizeHigh,
  DWORD dwMaximumSizeLow,
  const wchar_t *lpName,
  L_BOOL bTryMalloc     // set this to TRUE when allocating bitmap memory
                        // false if you want a true file mapping object using mmap
);
#endif // #if defined(LT_COMP_UNICODE)
#endif // #if !defined(FOR_UWP)

#if defined(FOR_UWP)
// In UWP, this function exists and it just a wrapper for MapViewOfFileFromApp
#else
EXTERN_C LPVOID WINAPI MapViewOfFile(
  L_HANDLE hFileMappingObject,
  DWORD dwDesiredAccess,
  DWORD dwFileOffsetHigh,
  DWORD dwFileOffsetLow,
  SIZE_T dwNumberOfBytesToMap
);
#endif // #if defined(FOR_UWP)

#if !defined(FOR_UWP)
L_BOOL WINAPI L_UnmapViewOfFile(L_HANDLE hFileMappingObject, LPCVOID lpBaseAddress, SIZE_T uLength);
#endif // #if !defined(FOR_UWP)

#if !defined(FOR_UWP)
DWORD WINAPI GetLastError(void);
#endif // #if !defined(FOR_UWP)

#if defined(FOR_UNIX)
void WINAPI GlobalMemoryStatus(LPMEMORYSTATUS lpBuffer);
L_BOOL WINAPI GlobalMemoryStatusEx(LPMEMORYSTATUSEX lpBuffer);
#endif // #if defined(FOR_UNIX)

#if !defined(FOR_UWP)
// for Codeblocks only
#if (defined(FOR_LINUX) && !defined(__x86_64__) && !defined(__aarch64__))
typedef int ptrdiff_t;
#endif // #if (defined(FOR_LINUX) && !defined(__x86_64__))

#define OutputDebugString(str)               LOGI(L_TEXT("%s"), str)
#define OutputDebugStringA(str)              LOGI("%s", str)


int WINAPI CloseEvent(HEVENT event);
L_BOOL WINAPI CloseMutex(HANDLE hObject);
L_BOOL WINAPI ReleaseMutex(HANDLE hMutex);
// internal functions in WindowsEvent.cpp
L_BOOL WINAPI InitMutexCondPair(mutex_cond_t *pPair);
void WINAPI FreeMutexCondPair(mutex_cond_t *pPair);
L_BOOL WINAPI FreeWaitableObject(HANDLE hObject);
char * __cdecl strupr(char *str); // should have been in string.h
char * __cdecl strlwr(char *str);
#endif // #if !defined(FOR_UWP)

/*WINADVAPI*/ L_BOOL WINAPI IsTextUnicode(CONST VOID* lpv, int iSize, LPINT lpiResult);

#if !defined(FOR_UWP)

#if !defined(CP_UTF7)
#  define CP_UTF7 65000
#endif // #if !defined(CP_UTF7)
#if !defined(CP_UTF8)
#  define CP_UTF8 65001
#endif
#if !defined(CP_ACP)
#  define CP_ACP 0
#endif

/* MultiByteToWideChar and MultiByteToUTF16 are very similar, except that in Linux wchar_t is a unsigned int (32-bit) value.
   So in Linux:
      MultiByteToWideChar converts UTF8 to an array of uints
      MultiByteToUTF16 converts UTF8 to an array of ushorts

   The same comment applies to WideCharToMultiByte & UTF16ToMultiByte
*/
int WINAPI MultiByteToWideChar(UINT CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, wchar_t* lpWideCharStr, int cchWideChar);
int WINAPI WideCharToMultiByte(UINT CodePage, DWORD dwFlags, const wchar_t* lpWideCharStr, int cchWideChar, char* lpMultiByteStr, int cbMultiByte, const char* lpDefaultChar, int* lpUsedDefaultChar);
int WINAPI MultiByteToUTF16(UINT CodePage, DWORD dwFlags, const char* lpMultiByteStr, int cbMultiByte, UINT16* lpWideCharStr, int cchWideChar);
int WINAPI UTF16ToMultiByte(UINT CodePage, DWORD dwFlags, const UINT16* lpWideCharStr, int cchWideChar, char* lpMultiByteStr, int cbMultiByte, const char* lpDefaultChar, int* lpUsedDefaultChar);

HMODULE WINAPI LoadLibrary(LPCSTR lpLibFileName);
FARPROC WINAPI GetProcAddress(HMODULE hModule, LPCSTR lpProcName);
L_BOOL WINAPI FreeLibrary(HMODULE hLibModule);
DWORD WINAPI GetModuleFileName(HMODULE hModule, LPCH lpFilename, DWORD nSize);
HMODULE CreateInstance(void *pModule, LPCSTR pszFileName);
#else
#define LoadLibrary(FILENAME) LoadPackagedLibrary(FILENAME, 0);
#endif // #if !defined(FOR_UWP)

#define IsBadReadPtr(lp, ucb) FALSE
#define IsBadWritePtr(lp, ucb) FALSE

#define GetSystemInfo L_GetSystemInfo
VOID WINAPI L_GetSystemInfo(LPSYSTEM_INFO lpSystemInfo);

#if !defined(FOR_UWP)
DWORD WINAPI GetTickCount(void);
#else
#define GetTickCount (DWORD)GetTickCount64
#endif // #if !defined(FOR_UWP)

#define _hypot hypot

#define ERROR                 0
#define NULLREGION            1
#define SIMPLEREGION          2
#define COMPLEXREGION         3
#define RGN_ERROR ERROR

#if !defined(FOR_UWP)
#define RGN_AND               L_RGN_AND
#define RGN_DIFF              L_RGN_ANDNOTRGN
#define RGN_COPY              L_RGN_SET
#define RGN_OR                L_RGN_OR
#define RGN_XOR               L_RGN_XOR
#endif // #if !defined(FOR_UWP)

#define GM_COMPATIBLE      1
#define GM_ADVANCED        2
#define GM_LAST            2

#define RDH_RECTANGLES     1

int WINAPI OffsetRgn(L_HANDLE hrgn, int x, int y);
int WINAPI CombineRgn(L_HANDLE hrgnDst, L_HANDLE hrgnSrc1, L_HANDLE hrgnSrc2, int iMode);
int WINAPI GetRgnBox(L_HANDLE hrgn, LPRECT lprc);
DWORD WINAPI GetRegionData(L_HANDLE hrgn, DWORD nCount, LPRGNDATA lpRgnData);
L_HANDLE WINAPI ExtCreateRegion(const XFORM *lpXform, DWORD nCount, const RGNDATA *lpRgnData);
L_HANDLE WINAPI CreateRectRgn(int x1, int y1, int x2, int y2);
L_HANDLE WINAPI CreateEllipticRgn(int x1, int y1, int x2, int y2);
L_HANDLE WINAPI CreatePolygonRgn(const POINT *pptl, int cPoint, int iMode);
L_BOOL WINAPI PtInRegion(L_HANDLE hrgn, int x, int y);
L_BOOL WINAPI SetRectRgn(L_HANDLE hrgn, int left, int top, int right, int bottom);
int WINAPI FrameRect(HDC hdc, const RECT* lprc, HBRUSH hbr);

#if !defined(FOR_UWP)
VOID WINAPI GetLocalTime(LPSYSTEMTIME lpSystemTime);
VOID WINAPI GetSystemTime(LPSYSTEMTIME lpSystemTime);
L_BOOL WINAPI SystemTimeToFileTime(CONST SYSTEMTIME *lpSystemTime, LPFILETIME lpFileTime);

#define TIME_ZONE_ID_UNKNOWN  0
#define TIME_ZONE_ID_STANDARD 1
#define TIME_ZONE_ID_DAYLIGHT 2
#define TIME_ZONE_ID_INVALID ((DWORD)0xFFFFFFFF)

DWORD WINAPI GetTimeZoneInformation(LPTIME_ZONE_INFORMATION lpTimeZoneInformation);

#define UInt32x32To64(X, Y) ((UINT64)(X) * (Y))

#endif // #if !defined(FOR_UWP)


#pragma pack()

#ifdef __cplusplus 
}  // closing bracket from extern "C"
#endif // #ifdef __cplusplus 

#endif // #if defined(FOR_WINDOWS)

#endif // #if !defined(LTPLATFORMS_H)
