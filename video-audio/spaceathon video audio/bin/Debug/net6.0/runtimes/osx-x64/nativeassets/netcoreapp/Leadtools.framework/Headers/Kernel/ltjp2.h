//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTJP2_H)
#define LTJP2_H

#include "lttyp.h"

#if defined(__cplusplus)
   #if defined(FOR_UNIX)
      #define _LEAD_JP2_NO_EXP_IMP
   #endif

   #if defined(_LEAD_JP2_NO_EXP_IMP)
      #define  JP2_EXPORT
   #else
      #if defined(_LEAD_JP2_)
         #define  JP2_EXPORT __declspec(dllexport)
      #else
         #define  JP2_EXPORT __declspec(dllimport)
      #endif   
   #endif // #if defined(_LEAD_JP2_NO_EXP_IMP)
#endif // #if defined(__cplusplus)

#define L_LTJP2_API LT_EXPORTED

#include "ltkrn.h"
#include "ltfil.h"
////////////////////
//JP2 Enums
////////////////////
typedef enum
{
   LEADJP2_JP2 = FILE_JP2,
   LEADJP2_JPX = FILE_JPX,
} eJP2FILEFORMAT;

typedef enum
{
   LEADJP2_J2K = FILE_J2K,
} eJP2CODESTREAMFORMAT;

typedef enum
{
   L_JP2B_RESOLUTION         = 1,
   L_JP2B_IPR                = 2,
   L_JP2B_XML                = 3,
   L_JP2B_UUID               = 4,
   L_JP2B_UUID_INFO          = 5,
   L_JPXB_RESOLUTION         = 11,
   L_JPXB_IPR                = 12,
   L_JPXB_XML                = 13,
   L_JPXB_UUID               = 14,
   L_JPXB_UUID_INFO          = 15,
   L_JPXB_MPEG7              = 16,
   L_JPXB_FREE               = 17,
   L_JPXB_BINARYFILTER       = 18,
   L_JPXB_GTSO               = 19,
   L_JPXB_COMPOSITION        = 20,
   L_JPXB_DIGITAL_SIGNATURE  = 21,
   L_JPXB_ASSOCIATION        = 22,
   L_JPXB_MEDIADATA          = 23,
} eJP2BOXTYPE;


////////////////////
//JP2 Box's Structures
////////////////////

typedef struct _tagL_JP2_RESOLUTION_BOX
{
   L_UINT32 uStructSize;
   L_UINT32 uCaptureXRes;
   L_UINT32 uCaptureYRes;
   L_UINT32 uDefDisplayXRes;
   L_UINT32 uDefDisplayYRes;
}L_JP2_RESOLUTION_BOX,*pL_JP2_RESOLUTION_BOX;

typedef struct _tagL_JP2_IPR_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_IPR_BOX, *pL_JP2_IPR_BOX;

typedef struct _tagL_JP2_XML_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_XML_BOX, *pL_JP2_XML_BOX;

typedef struct _tagL_JP2_UUID_ID
{
   L_UINT32  uStructSize;
   L_UINT8   pValue[16];
}L_JP2_UUID_ID, *pL_JP2_UUID_ID;

typedef struct _tagL_JP2_UUID_BOX
{
   L_UINT32 uStructSize;
   L_JP2_UUID_ID ID;
   L_UINT8*      pData;
   L_SIZE_T      uDataSize;
}L_JP2_UUID_BOX, *pL_JP2_UUID_BOX;

typedef struct _tagL_JP2_UUID_LIST_BOX
{
   L_UINT32       uStructSize;
   L_UINT16       uNumOfIDs;//number of UUID's
   pL_JP2_UUID_ID pIDs;
}L_JP2_UUID_LIST_BOX, *pL_JP2_UUID_LIST_BOX;

typedef struct _tagL_JP2_UUID_URL_BOX
{
   L_UINT32 uStructSize;
   L_UINT8  uVERS;
   L_UINT8  pFLAG[3];
   L_UINT8* pLOC;
   L_SIZE_T uLOCSize;
}L_JP2_UUID_URL_BOX, *pL_JP2_UUID_URL_BOX;

typedef struct _tagL_JP2_UUIDINFO_BOX
{
   L_UINT32            uStructSize;
   L_JP2_UUID_LIST_BOX List;
   L_JP2_UUID_URL_BOX  URL;
}L_JP2_UUIDINFO_BOX, *pL_JP2_UUIDINFO_BOX;


typedef struct _tagL_JP2_MPEG7_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_MPEG7_BOX, *pL_JP2_MPEG7_BOX;

typedef struct _tagL_JP2_MEDIADATA_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_MEDIADATA_BOX, *pL_JP2_MEDIADATA_BOX;


typedef struct _tagL_JP2_ASSOCIATION_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_ASSOCIATION_BOX, *pL_JP2_ASSOCIATION_BOX;

typedef struct _tagL_JP2_FREE_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_FREE_BOX, *pL_JP2_FREE_BOX;

typedef struct _tagL_JP2_BINARYFILTER_BOX
{
   L_UINT32      uStructSize;
   L_JP2_UUID_ID FilterType;
   L_UINT8*      pData;
   L_SIZE_T      uDataSize;
}L_JP2_BINARYFILTER_BOX, *pL_JP2_BINARYFILTER_BOX;

typedef struct _tagL_JP2_GTSO_BOX
{
   L_UINT32 uStructSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_GTSO_BOX, *pL_JP2_GTSO_BOX;

typedef struct _tagL_JP2_COMPOPTIONS_BOX
{
   L_UINT32 uStructSize;
   L_UINT32 uHeight;
   L_UINT32 uWidth;
   L_UINT8  uLoop;
}L_JP2_COMPOPTIONS_BOX, *pL_JP2_COMPOPTIONS_BOX;

typedef struct _tagL_JP2_INSTPARAM
{
   L_UINT32 uStructSize;
   L_UINT32 uXo;
   L_UINT32 uYo;
   L_UINT32 uWidth;
   L_UINT32 uHeight;
   L_UINT8  uPersist;
   L_UINT32 uLife;
   L_UINT32 uNextUse;
   L_UINT32 uXc;
   L_UINT32 uYc;
   L_UINT32 uWc;
   L_UINT32 uHc;
}L_JP2_INSTPARAM, *pL_JP2_INSTPARAM;

typedef struct _tagL_JP2_INSTSET_BOX
{
   L_UINT32         uStructSize;
   L_UINT16         uItyp;
   L_UINT16         uRept;
   L_UINT32         uTick;
   L_UINT32         uNumOfInst;
   pL_JP2_INSTPARAM pInstParam;
}L_JP2_INSTSET_BOX, *pL_JP2_INSTSET_BOX;

typedef struct _tagL_JP2_INSTSET_BOXES
{
   L_UINT32           uStructSize;
   pL_JP2_INSTSET_BOX pBoxes;
   L_UINT32           uNumOfBoxes;
}L_JP2_INSTSET_BOXES, *pL_JP2_INSTSET_BOXES;

typedef struct _tagL_JP2_COMPOSITION_BOX
{
   L_UINT32              uStructSize;
   L_JP2_COMPOPTIONS_BOX Options;
   L_JP2_INSTSET_BOXES   Instructions;
}L_JP2_COMPOSITION_BOX, *pL_JP2_COMPOSITION_BOX;

typedef struct _tagL_JP2_DIGITAL_SIGNATURE_BOX
{
   L_UINT32 uStructSize;
   L_UINT8  uStyp;
   L_UINT8  uPtyp;
   L_UINT64 uOFF;
   L_UINT64 uLength;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_DIGITAL_SIGNATURE_BOX, *pL_JP2_DIGITAL_SIGNATURE_BOX;


typedef struct _tagL_JP2_GML_ELEMENT
{
   L_UINT32 uStructSize;
   L_UINT8* pLabel;
   L_SIZE_T uLabelSize;
   L_UINT8* pData;
   L_SIZE_T uDataSize;
}L_JP2_GML_ELEMENT, *pL_JP2_GML_ELEMENT;

typedef struct _tagL_JP2_GMLDATA
{
   L_UINT32           uStructSize;
   pL_JP2_GML_ELEMENT pElements;
   L_UINT32           uNumOfElem;
}L_JP2_GMLDATA, *pL_JP2_GMLDATA;

typedef struct _tagL_JP2_JPXBITMAPS
{
   L_UINT32             uStructSize;
   BITMAPHANDLE         ColorBitmap;
   eJP2CODESTREAMFORMAT eColorFormat;
   BITMAPHANDLE         OpacityBitmap;
   eJP2CODESTREAMFORMAT eOpacityFormat;
   BITMAPHANDLE         PreOpacityBitmap;
   eJP2CODESTREAMFORMAT ePreOpacityFormat;
}L_JP2_JPXBITMAPS, *pL_JP2_JPXBITMAPS;

typedef struct _tagL_JP2_JPXCOMPOSITE
{
   L_UINT32          uStructSize;
   pL_JP2_JPXBITMAPS pBitmaps;
   L_UINT32          uNumOfBitmaps;
}L_JP2_JPXCOMPOSITE, *pL_JP2_JPXCOMPOSITE;

typedef struct _tagL_JP2_IMAGEINFO_ELEMENT
{
   L_UINT32  uStructSize;
   L_UINT32  uNumOfBoxes;
   L_SIZE_T* pBoxOffset;
   L_SIZE_T* pBoxSize;
   L_SIZE_T* pBoxDataOffset;
   L_SIZE_T* pBoxDataSize;
}L_JP2_IMAGEINFO_ELEMENT, *pL_JP2_IMAGEINFO_ELEMENT;

typedef struct _tagL_JP2_FRAMEINFO
{
   L_UINT32  uStructSize;
   L_UINT    uWidth;
   L_UINT    uHeight;
   L_UINT    uBitsPerPixel;
   L_UINT32  uNumOfCodeStream;
   L_UINT32 *puCodeStream;
}L_JP2_FRAMEINFO, *pL_JP2_FRAMEINFO;

typedef struct _tagL_JP2_FILEINFO
{
   L_UINT32                uStructSize;
   eJP2FILEFORMAT          eFormat;
   L_JP2_IMAGEINFO_ELEMENT Header;
   L_JP2_IMAGEINFO_ELEMENT DataRef;
   L_JP2_IMAGEINFO_ELEMENT XML;
   L_JP2_IMAGEINFO_ELEMENT Free;
   L_JP2_IMAGEINFO_ELEMENT MPEG7;
   L_JP2_IMAGEINFO_ELEMENT MediaData;
   L_JP2_IMAGEINFO_ELEMENT DigitalSignature;
   L_JP2_IMAGEINFO_ELEMENT BinaryFilter;
   L_JP2_IMAGEINFO_ELEMENT UUID;
   L_JP2_IMAGEINFO_ELEMENT IPR;
   L_JP2_IMAGEINFO_ELEMENT UUIDInfo;
   L_JP2_IMAGEINFO_ELEMENT Association;
   L_JP2_IMAGEINFO_ELEMENT DesiredReproduction;
   L_JP2_IMAGEINFO_ELEMENT Composition;
   L_JP2_IMAGEINFO_ELEMENT CodeStream;
   L_JP2_IMAGEINFO_ELEMENT FragmentTable;
   L_UINT32                uNumOfFrames;
   pL_JP2_FRAMEINFO        pFrames;
}L_JP2_FILEINFO, *pL_JP2_FILEINFO;

typedef struct _tagL_JP2_FRAGMENT
{
   L_UINT32 uStructSize;
   L_UINT32   uCodeStreamIndex;
   L_UINT32   uUrlIndex;
   L_SIZE_T   uOffset;
}L_JP2_FRAGMENT, *pL_JP2_FRAGMENT;
////////////////////
//JP2 Defines
////////////////////

typedef L_VOID* L_HJP2;

//////////////////////////
//JP2 Exported Functions
//////////////////////////
#if defined(__cplusplus)

class JP2_EXPORT LJp2FileFormat
{
public:
   LJp2FileFormat();
   virtual ~LJp2FileFormat();

   L_INT Save(L_TCHAR* pszFile, pBITMAPHANDLE pBitmap, eJP2FILEFORMAT eFormat, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData);
   L_INT SaveList(L_TCHAR* pszFile, HBITMAPLIST hList, eJP2FILEFORMAT eFormat, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData);
   L_INT SaveComposite(L_TCHAR* pszFile, pL_JP2_JPXCOMPOSITE pComposite, eJP2FILEFORMAT eFormat, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData);
   L_INT SaveMemory(L_UINT8** lpBuffer, L_SIZE_T *puBufferSize, pBITMAPHANDLE pBitmap, eJP2FILEFORMAT eFormat, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData );
   L_INT SaveListMemory(L_UINT8** lpBuffer, L_SIZE_T *puBufferSize, HBITMAPLIST hList, eJP2FILEFORMAT eFormat, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData );
   L_INT SaveCompositeMemory(L_UINT8** lpBuffer, L_SIZE_T *puBufferSize, pL_JP2_JPXCOMPOSITE pComposite, eJP2FILEFORMAT eFormat, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData );
   L_INT AppendBoxes(L_TCHAR* pszFile, eJP2BOXTYPE uBoxType, L_VOID *pBoxes, L_UINT  uNumOfBoxes);
   L_INT AppendBoxesMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, L_UINT8** lpOutBuffer, L_SIZE_T * puOutBufferSize, eJP2BOXTYPE uBoxType, L_VOID *pBoxes, L_UINT  uNumOfBoxes);
   L_INT AppendFrames(L_TCHAR* pszFile, pL_JP2_JPXCOMPOSITE pComposite, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData);
   L_INT AppendFramesMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, L_UINT8** lpOutBuffer, L_SIZE_T * puOutBufferSize, pL_JP2_JPXCOMPOSITE pComposite, L_INT nBitsPerPixel, L_INT nQFactor, pSAVEFILEOPTION pSaveOptions, FILESAVECALLBACK pSaveCallBack, L_VOID*pUserData);
   L_INT AppendGMLData(L_TCHAR* pFileName, pL_JP2_GMLDATA pGMLData);
   L_INT AppendGMLDataMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, L_UINT8** lpOutBuffer, L_SIZE_T * puOutBufferSize, pL_JP2_GMLDATA pGMLData);

   L_INT Read(L_TCHAR* pszFile, pBITMAPHANDLE pBitmap, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadList(L_TCHAR* pszFile, pHBITMAPLIST phList, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadComposite(L_TCHAR* pszFile, pL_JP2_JPXCOMPOSITE pComposite, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, pBITMAPHANDLE pBitmap, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadListMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, pHBITMAPLIST phList, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadCompositeMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, pL_JP2_JPXCOMPOSITE pComposite, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadBox(L_TCHAR* pszFile, eJP2BOXTYPE eBoxType, L_VOID **plBox, L_UINT32 uBoxIndex);
   L_INT ReadBoxMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, eJP2BOXTYPE eBoxType, L_VOID ** plBox, L_UINT32 uBoxIndex);
   L_INT ReadFrames(L_TCHAR*pszFile, pL_JP2_JPXCOMPOSITE pComposite, L_UINT32 * pFrames, L_UINT32 uNumOfFrames, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadFramesMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, pL_JP2_JPXCOMPOSITE pComposite, L_UINT32 * pFrames, L_UINT32 uNumOfFrames, L_INT nBitsPerPixel, L_INT nOrder, pLOADFILEOPTION pLoadOptions, pFILEINFO pFileInfo, FILEREADCALLBACK pReadCallBack, L_VOID*pUserData);
   L_INT ReadGMLData(L_TCHAR* pFileName, pL_JP2_GMLDATA pGMLData);
   L_INT ReadGMLDataMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, pL_JP2_GMLDATA pGMLData);

   L_INT FragmentJpxFile(L_TCHAR* pInFileName, L_TCHAR* pOutFileName, pL_JP2_UUID_URL_BOX pURLs, L_UINT32 uNumOfURLs, pL_JP2_FRAGMENT pFragments, L_UINT32 uNumOfFrgm);
   L_INT ExtractFrames(L_TCHAR* pInFileName, L_TCHAR* pOutFileName, L_UINT32 * puFrames, L_UINT32 uNumOfFrames);
   L_INT SetBoxes(eJP2BOXTYPE eBox, L_VOID *pBoxes,L_UINT  uNumOfBoxes);
   L_INT GetBoxes(eJP2BOXTYPE eBox, L_VOID **plBox, L_UINT * puNumOfBoxes);
   L_INT GetFileInfo(L_TCHAR* pszFile, pL_JP2_FILEINFO pFileInfo);
   L_INT GetFileInfoMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, pL_JP2_FILEINFO pFileInfo);
   L_INT ExtractFramesBuffer(L_TCHAR* pInFileName, L_UCHAR** lpBuffer, L_SIZE_T* puBufferSize, L_UINT32 * puFrames, L_UINT32 uNumOfFrames);
   L_INT ExtractFramesBufferMemory(L_UINT8* pBuffer, L_SIZE_T uBufferSize, L_UINT8 ** lpBuffer, L_SIZE_T * puBufferSize, L_UINT32 * puFrames, L_UINT32 uNumOfFrames);

   L_INT ResetBoxes();
   L_INT FreeBoxes(eJP2BOXTYPE eBox, L_VOID *pBox, L_UINT uNumOfBoxes);
   L_INT FreeComposite(pL_JP2_JPXCOMPOSITE pComposite);
   L_INT FreeFileInfo(pL_JP2_FILEINFO pFileInfo);
   L_INT FreeGMLData(pL_JP2_GMLDATA pGMLData);
private:
   L_HJP2 engine;
};
#endif // #if defined(__cplusplus)

#if defined(__cplusplus)
extern "C"
{
#endif // #if defined(__cplusplus)

L_LTJP2_API L_HJP2     EXT_FUNCTION    L_Jp2Create                      (L_VOID);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2Destroy                     (L_HJP2 hJp2);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2Save                        (L_HJP2 hJp2,
                                                                         L_TCHAR* pszFile,
                                                                         pBITMAPHANDLE pBitmap,
                                                                         eJP2FILEFORMAT eFormat,
                                                                         L_INT nBitsPerPixel,
                                                                         L_INT nQFactor,
                                                                         pSAVEFILEOPTION pSaveOptions,
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2Read                        (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         pBITMAPHANDLE pBitmap, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2SaveList                    (L_HJP2 hJp2,
                                                                         L_TCHAR* pszFile,
                                                                         HBITMAPLIST hList,
                                                                         eJP2FILEFORMAT eFormat,
                                                                         L_INT nBitsPerPixel,
                                                                         L_INT nQFactor,
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadList                    (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         pHBITMAPLIST phList, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2SaveComposite               (L_HJP2 hJp2,
                                                                         L_TCHAR* pszFile,
                                                                         pL_JP2_JPXCOMPOSITE pComposite,
                                                                         eJP2FILEFORMAT eFormat,
                                                                         L_INT nBitsPerPixel,
                                                                         L_INT nQFactor,
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadComposite               (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2SetBoxes                    (L_HJP2 hJp2, 
                                                                         eJP2BOXTYPE eBox, 
                                                                         L_VOID *pBoxes,
                                                                         L_UINT  uNumOfBoxes);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2GetBoxes                    (L_HJP2 hJp2, 
                                                                         eJP2BOXTYPE eBox, 
                                                                         L_VOID **plBox,
                                                                         L_UINT * puNumOfBoxes);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2FreeBoxes                   (L_HJP2 hJp2, 
                                                                         eJP2BOXTYPE eBox, 
                                                                         L_VOID *pBox,
                                                                         L_UINT uNumOfBoxes);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2FreeComposite               (L_HJP2 hJp2, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2GetFileInfo                 (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         pL_JP2_FILEINFO pFileInfo);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2FreeFileInfo                (L_HJP2 hJp2, 
                                                                         pL_JP2_FILEINFO pFileInfo);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadBox                     (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         eJP2BOXTYPE eBoxType, 
                                                                         L_VOID **plBox,
                                                                         L_UINT32 uBoxIndex);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2AppendBoxes                 (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         eJP2BOXTYPE uBoxType,
                                                                         L_VOID *pBoxes,
                                                                         L_UINT  uNumOfBoxes);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadFrames                  (L_HJP2 hJp2, 
                                                                         L_TCHAR*pszFile, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         L_UINT32 * pFrames, 
                                                                         L_UINT32 uNumOfFrames, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2AppendFrames                (L_HJP2 hJp2, 
                                                                         L_TCHAR* pszFile, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nQFactor, 
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2FragmentJpxFile             (L_HJP2 hJp2, 
                                                                         L_TCHAR* pInFileName, 
                                                                         L_TCHAR* pOutFileName, 
                                                                         pL_JP2_UUID_URL_BOX pURLs, 
                                                                         L_UINT32 uNumOfURLs, 
                                                                         pL_JP2_FRAGMENT pFragments, 
                                                                         L_UINT32 uNumOfFrgm);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ExtractFrames               (L_HJP2 hJp2, 
                                                                         L_TCHAR* pInFileName, 
                                                                         L_TCHAR* pOutFileName, 
                                                                         L_UINT32 * puFrames, 
                                                                         L_UINT32 uNumOfFrames);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ExtractFramesBuffer         (L_HJP2 hJp2, 
                                                                         L_TCHAR* pInFileName, 
                                                                         L_UCHAR** lpBuffer, 
                                                                         L_SIZE_T* puBufferSize, 
                                                                         L_UINT32 * puFrames, 
                                                                         L_UINT32 uNumOfFrames);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadGMLData                 (L_HJP2 hJp2, 
                                                                         L_TCHAR* pFileName, 
                                                                         pL_JP2_GMLDATA pGMLData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2AppendGMLData               (L_HJP2 hJp2, 
                                                                         L_TCHAR* pFileName, 
                                                                         pL_JP2_GMLDATA pGMLData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2FreeGMLData                 (L_HJP2 hJp2,
                                                                         pL_JP2_GMLDATA pGMLData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ResetBoxes                  (L_HJP2 hJp2);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2SaveMemory                  (L_HJP2 hJp2, 
                                                                         L_UINT8** lpBuffer, 
                                                                         L_SIZE_T *puBufferSize, 
                                                                         pBITMAPHANDLE pBitmap, 
                                                                         eJP2FILEFORMAT eFormat, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nQFactor, 
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData );

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadMemory                  (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         pBITMAPHANDLE pBitmap, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2SaveListMemory              (L_HJP2 hJp2, 
                                                                         L_UINT8** lpBuffer, 
                                                                         L_SIZE_T *puBufferSize, 
                                                                         HBITMAPLIST hList, 
                                                                         eJP2FILEFORMAT eFormat, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nQFactor, 
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData );

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadListMemory              (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         pHBITMAPLIST phList, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2SaveCompositeMemory         (L_HJP2 hJp2, 
                                                                         L_UINT8** lpBuffer, 
                                                                         L_SIZE_T *puBufferSize, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         eJP2FILEFORMAT eFormat, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nQFactor, 
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData );

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadCompositeMemory         (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2GetFileInfoMemory           (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         pL_JP2_FILEINFO pFileInfo);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadBoxMemory               (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         eJP2BOXTYPE eBoxType, 
                                                                         L_VOID ** plBox, 
                                                                         L_UINT32 uBoxIndex);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2AppendBoxesMemory           (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         L_UINT8** lpOutBuffer, 
                                                                         L_SIZE_T * puOutBufferSize, 
                                                                         eJP2BOXTYPE uBoxType, 
                                                                         L_VOID *pBoxes, 
                                                                         L_UINT  uNumOfBoxes);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadFramesMemory            (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         L_UINT32 * pFrames, 
                                                                         L_UINT32 uNumOfFrames, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nOrder, 
                                                                         pLOADFILEOPTION pLoadOptions, 
                                                                         pFILEINFO pFileInfo, 
                                                                         FILEREADCALLBACK pReadCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2AppendFramesMemory          (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         L_UINT8** lpOutBuffer, 
                                                                         L_SIZE_T * puOutBufferSize, 
                                                                         pL_JP2_JPXCOMPOSITE pComposite, 
                                                                         L_INT nBitsPerPixel, 
                                                                         L_INT nQFactor, 
                                                                         pSAVEFILEOPTION pSaveOptions, 
                                                                         FILESAVECALLBACK pSaveCallBack, 
                                                                         L_VOID*pUserData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ExtractFramesBufferMemory   (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         L_UINT8 ** lpBuffer, 
                                                                         L_SIZE_T * puBufferSize, 
                                                                         L_UINT32 * puFrames, 
                                                                         L_UINT32 uNumOfFrames);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2ReadGMLDataMemory           (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         pL_JP2_GMLDATA pGMLData);

L_LTJP2_API L_INT      EXT_FUNCTION    L_Jp2AppendGMLDataMemory         (L_HJP2 hJp2, 
                                                                         L_UINT8* pBuffer, 
                                                                         L_SIZE_T uBufferSize, 
                                                                         L_UINT8** lpOutBuffer, 
                                                                         L_SIZE_T * puOutBufferSize, 
                                                                         pL_JP2_GMLDATA pGMLData);

#if defined(__cplusplus)
};
#endif // #if defined(__cplusplus)

#endif // #if !defined(LTJP2_H)
