//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************

#if !defined(LTOCR_H)
#define LTOCR_H

#include "lttyp.h"
#define L_LTOCR_API LT_EXPORTED

// OCR components
#define L_OCRDOCUMENTSUPPORTED

#include "lterr.h"

#if defined(L_OCRDOCUMENTSUPPORTED)
#  include "ltdocwrt.h"
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)

#include "ltspellcheck.h"

#define L_HEADER_ENTRY
#include "ltpck.h"

// ----------------------------------------------
// Defines and enums
// ----------------------------------------------
#include "ltocrEnums.h"

// ----------------------------------------------
// Handles
// ----------------------------------------------

L_DECLARE_HANDLE(L_OcrEngine);
L_DECLARE_HANDLE(L_OcrLanguageManager);
L_DECLARE_HANDLE(L_OcrSpellCheckManager);
L_DECLARE_HANDLE(L_OcrSettingManager);
L_DECLARE_HANDLE(L_OcrZoneManager);
L_DECLARE_HANDLE(L_OcrPage);
L_DECLARE_HANDLE(L_OcrDocumentManager);
#if defined(L_OCRDOCUMENTSUPPORTED)
L_DECLARE_HANDLE(L_OcrDocument);
L_DECLARE_HANDLE(L_OcrAutoRecognizeJob);
L_DECLARE_HANDLE(L_OcrAutoRecognizeManager);
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)

// ----------------------------------------------
// Structures
// ----------------------------------------------

struct L_OcrWriteXmlOptionsA
{
   L_UINT StructSize;
   L_OcrXmlEncoding Encoding;
   L_BOOL Formatted;
   L_CHAR Indent[10];
};
typedef struct L_OcrWriteXmlOptionsA L_OcrWriteXmlOptionsA;
#if defined(FOR_UNICODE)
struct L_OcrWriteXmlOptions
{
   L_UINT StructSize;
   L_OcrXmlEncoding Encoding;
   L_BOOL Formatted;
   L_TCHAR Indent[10];
};
typedef struct L_OcrWriteXmlOptions L_OcrWriteXmlOptions;
#else
typedef L_OcrWriteXmlOptionsA L_OcrWriteXmlOptions;
#endif // #if defined(FOR_UNICODE)

struct L_OcrProgressData
{
   L_UINT StructSize;
   L_UINT FirstPageIndex;
   L_UINT LastPageIndex;
   L_UINT CurrentPageIndex;
   L_OcrProgressOperation Operation;
   L_UINT Percentage;
};
typedef struct L_OcrProgressData L_OcrProgressData;

struct L_OcrSettingDescriptorA
{
   L_UINT StructSize;
   L_CHAR Name[120];
   L_OcrSettingValueType ValueType;
   L_CHAR FriendlyName[120];
   L_CHAR Units[120];
   L_INT IntegerMinimumValue;
   L_INT IntegerMaximumValue;
   L_BOOL EnumIsFlags;
   L_CHAR EnumMemberFriendlyNames[1024];
   L_DOUBLE DoubleMinimumValue;
   L_DOUBLE DoubleMaximumValue;
   L_BOOL StringNullAllowed;
   L_INT StringMaximumLength;
};
typedef struct L_OcrSettingDescriptorA L_OcrSettingDescriptorA;
#if defined(FOR_UNICODE)
struct L_OcrSettingDescriptor
{
   L_UINT StructSize;
   L_TCHAR Name[120];
   L_OcrSettingValueType ValueType;
   L_TCHAR FriendlyName[120];
   L_TCHAR Units[120];
   L_INT IntegerMinimumValue;
   L_INT IntegerMaximumValue;
   L_BOOL EnumIsFlags;
   L_TCHAR EnumMemberFriendlyNames[1024];
   L_DOUBLE DoubleMinimumValue;
   L_DOUBLE DoubleMaximumValue;
   L_BOOL StringNullAllowed;
   L_INT StringMaximumLength;
};
typedef struct L_OcrSettingDescriptor L_OcrSettingDescriptor;
#else
typedef L_OcrSettingDescriptorA L_OcrSettingDescriptor;
#endif // #if defined(FOR_UNICODE)

struct L_OcrOMROptions
{
   L_UINT StructSize;
   L_OcrOMRFrameDetectionMethod FrameDetectionMethod;
   L_OcrOMRSensitivity Sensitivity;
   L_WCHAR StateRecognitionCharacters[2]; // 0 = unfilled, 1 = filled
};
typedef struct L_OcrOMROptions L_OcrOMROptions;

struct L_OcrZoneA
{
   L_UINT StructSize;
   L_UINT Id;
   L_CHAR Name[80];
   L_RECT Bounds;
   L_OcrZoneType ZoneType;
   L_OcrZoneCharacterFilters CharacterFilters;
   L_OcrLanguage Language;
   L_BOOL IsEngineZone;
   L_COLORREF ForeColor;      // for future use, the main fore color of the zone
   L_COLORREF BackColor;      // for future use, the main back color of the zone
   L_UINT ViewPerspective;    // TOP_LEFT, BOTTOM_LEFT, ... etc
   L_OcrTextDirection TextDirection;
   L_OcrTextStyle TextStyle;  // Only available when ZoneType is L_OcrZoneType_Text
   L_FLOAT FontRatio;         // 1.0 is average font size of the document
   L_UCHAR EngineData[256];   // for internal use
};
typedef struct L_OcrZoneA L_OcrZoneA;

#if defined(FOR_UNICODE)
struct L_OcrZone
{
   L_UINT StructSize;
   L_UINT Id;
   L_TCHAR Name[80];
   L_RECT Bounds;
   L_OcrZoneType ZoneType;
   L_OcrZoneCharacterFilters CharacterFilters;
   L_OcrLanguage Language;
   L_BOOL IsEngineZone;
   L_COLORREF ForeColor;      // for future use, the main fore color of the zone
   L_COLORREF BackColor;      // for future use, the main back color of the zone
   L_UINT ViewPerspective;    // TOP_LEFT, BOTTOM_LEFT, ... etc
   L_OcrTextDirection TextDirection;
   L_OcrTextStyle TextStyle;  // Only available when ZoneType is L_OcrZoneType_Text
   L_FLOAT FontRatio;         // 1.0 is average font size of the document
   L_UCHAR EngineData[256];   // for internal use
};
typedef struct L_OcrZone L_OcrZone;
#else
typedef L_OcrZoneA L_OcrZone;
#endif // #if defined(FOR_UNICODE)

struct L_OcrZoneCell
{
   L_UINT StructSize;
   L_RECT Bounds;
   L_OcrZoneType CellType;
   L_COLORREF BackgroundColor;
   L_COLORREF LeftBorderColor;
   L_COLORREF TopBorderColor;
   L_COLORREF RightBorderColor;
   L_COLORREF BottomBorderColor;
   L_OcrBorderLineStyle LeftBorderStyle;
   L_OcrBorderLineStyle TopBorderStyle;
   L_OcrBorderLineStyle RightBorderStyle;
   L_OcrBorderLineStyle BottomBorderStyle;
   L_UINT LeftBorderWidth;
   L_UINT TopBorderWidth;
   L_UINT RightBorderWidth;
   L_UINT BottomBorderWidth;
   L_OcrBackgroundFillStyle BackgroundFillStyle;
};
typedef struct L_OcrZoneCell L_OcrZoneCell;

struct L_OcrCharacter
{
   L_UINT StructSize;
   L_WCHAR Code;
   L_WCHAR GuessCode1;
   L_WCHAR GuessCode2;
   L_WCHAR Reserved2;   // reserved for future use
   L_UINT Confidence;
   L_BOOL WordIsCertain;
   L_RECT Bounds;
   L_OcrCharacterPositions Positions;
   L_INT Base;
   L_UINT CellIndex;
   L_UINT LeadingSpaces;
   L_UINT LeadingSpacesConfidence;
   L_FLOAT FontSize;
   L_OcrCharacterFontStyles FontStyles;
   L_COLORREF Color;
   L_OcrLanguage Language;
   L_UINT16 RotationAngle;
   L_UINT16 Reserved;//reserved for future use
   L_UCHAR EngineData[16];   // for internal use
   L_INT ActualBase;
   L_COLORREF BackgroundColor;
   L_UINT GuessConfidence1;
   L_UINT GuessConfidence2;
   L_INT ReservedArray[16];
};
typedef struct L_OcrCharacter L_OcrCharacter;

struct L_OcrZoneCharacters
{
   L_UINT StructSize;
   L_OcrCharacter* Characters;
   L_UINT CharacterCount;
};
typedef struct L_OcrZoneCharacters L_OcrZoneCharacters;

struct L_OcrPageCharacters
{
   L_UINT StructSize;
   L_OcrZoneCharacters* ZoneCharacters;
   L_UINT ZoneCharacterCount;
};
typedef struct L_OcrPageCharacters L_OcrPageCharacters;

struct L_OcrWord
{
   L_UINT StructSize;
   L_WCHAR* Value;
   L_WCHAR Buffer[128];
   L_RECT Bounds;
   L_UINT FirstCharacterIndex;
   L_UINT LastCharacterIndex;
   L_POINT ActualBaseStartPoint;
   L_POINT ActualBaseEndPoint;
};
typedef struct L_OcrWord L_OcrWord;

struct L_OcrWords
{
   L_UINT StructSize;
   L_OcrWord* Words;
   L_UINT WordCount;
};
typedef struct L_OcrWords L_OcrWords;

struct L_OcrMICRData
{
   L_UINT StructSize;
   L_WCHAR Auxiliary[32];
   L_WCHAR EPC;
   L_WCHAR Routing[16];
   L_WCHAR Account[32];
   L_WCHAR CheckNumber[16];
   L_WCHAR Amount[32];
};
typedef struct L_OcrMICRData L_OcrMICRData;

struct L_OcrRecognizeStatistic
{
   L_UINT StructSize;
   L_UINT RecognizedCharacters;
   L_UINT RecognizedWords;
   L_UINT RejectedCharacters;
};
typedef struct L_OcrRecognizeStatistic L_OcrRecognizeStatistic;

struct L_OcrPageAutoPreprocessValues
{
   L_UINT StructSize;
   L_BOOL IsInverted;
   L_INT RotationAngle;
   L_INT DeskewAngle;
};
typedef struct L_OcrPageAutoPreprocessValues L_OcrPageAutoPreprocessValues;

#if defined(L_OCRDOCUMENTSUPPORTED)
typedef L_VOID (pEXT_CALLBACK L_OcrAutoRecognizeTraceWriteLineCallback)(L_OcrAutoRecognizeJob job, L_OcrTraceCategory category, const L_TCHAR* message, L_VOID* userData);

struct L_OcrAutoRecognizeManagerOptions
{
   L_UINT StructSize;
   L_BOOL UseThreads;
   L_OcrAutoRecognizeTraceWriteLineCallback TraceCallback;
   L_VOID* TraceCallbackUserData;
   L_OcrAutoRecognizeManagerJobErrorMode JobErrorMode;
   L_OcrAutoPreprocessPageCommands PreprocessPageCommands;
};
typedef struct L_OcrAutoRecognizeManagerOptions L_OcrAutoRecognizeManagerOptions;

struct L_OcrAutoRecognizeManagerJobError
{
   L_UINT StructSize;
   L_UINT ImagePageNumber;
   L_OcrAutoRecognizeManagerJobOperation Operation;
   L_INT ErrorCode;
};
typedef struct L_OcrAutoRecognizeManagerJobError L_OcrAutoRecognizeManagerJobError;

struct L_OcrAutoRecognizeJobDataA
{
   L_UINT StructSize;
   L_CHAR ImageFileName[MAX_PATH];
   L_UINT FirstPageNumber;
   L_INT LastPageNumber;
   L_CHAR DocumentFileName[MAX_PATH];
   DOCWRTFORMAT Format;
   L_CHAR ZonesFileName[MAX_PATH];
   L_CHAR JobName[80];
   L_VOID* UserData;
};
typedef struct L_OcrAutoRecognizeJobDataA L_OcrAutoRecognizeJobDataA;
#if defined(FOR_UNICODE)
struct L_OcrAutoRecognizeJobData
{
   L_UINT StructSize;
   L_TCHAR ImageFileName[MAX_PATH];
   L_UINT FirstPageNumber;
   L_INT LastPageNumber;
   L_TCHAR DocumentFileName[MAX_PATH];
   DOCWRTFORMAT Format;
   L_TCHAR ZonesFileName[MAX_PATH];
   L_TCHAR JobName[80];
   L_VOID* UserData;
};
typedef struct L_OcrAutoRecognizeJobData L_OcrAutoRecognizeJobData;
#else
typedef L_OcrAutoRecognizeJobDataA L_OcrAutoRecognizeJobData;
#endif // #if defined(FOR_UNICODE)

struct L_OcrAutoRecognizeJobOperationCallbackData
{
   L_UINT StructSize;
   L_INT Status;
   L_OcrAutoRecognizeJob Job;
   L_BOOL IsPostOperation;
   L_OcrAutoRecognizeManagerJobOperation Operation;
   BITMAPHANDLE* PageBitmap;
   L_OcrDocument Document;
   L_OcrPage Page;
   L_UINT ImagePageNumber;
   DOCWRTFORMAT Format;
};
typedef struct L_OcrAutoRecognizeJobOperationCallbackData L_OcrAutoRecognizeJobOperationCallbackData;

struct L_OcrAutoRecognizeRunJobCallbackData
{
   L_UINT StructSize;
   L_INT Status;
   L_OcrAutoRecognizeJob Job;
   L_BOOL IsCompleted;
};
typedef struct L_OcrAutoRecognizeRunJobCallbackData L_OcrAutoRecognizeRunJobCallbackData;
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)

struct L_OcrPageAreaOptions
{
   L_UINT StructSize;
   L_RECT Area;
   L_UINT IntersectPercentage;
   L_BOOL UseTextZone;
};
typedef struct L_OcrPageAreaOptions L_OcrPageAreaOptions;

struct L_OcrRuntimeFileA
{
   L_UINT StructSize;
   const L_CHAR* FileName;
   const L_CHAR* Guid;
   L_OcrRuntimeFileMode Mode;
   L_CHAR FullPath[MAX_PATH];
};
typedef struct L_OcrRuntimeFileA L_OcrRuntimeFileA;
#if defined(FOR_UNICODE)
struct L_OcrRuntimeFile
{
   L_UINT StructSize;
   const L_TCHAR* FileName;
   const L_TCHAR* Guid;
   L_OcrRuntimeFileMode Mode;
   L_TCHAR FullPath[MAX_PATH];
};
typedef struct L_OcrRuntimeFile L_OcrRuntimeFile;
#else
typedef struct L_OcrRuntimeFileA L_OcrRuntimeFile;
#endif // #if defined(FOR_UNICODE)

struct L_OcrPageSortedZonesIndexMapOptions
{
   L_UINT StructSize;
   L_OcrPageSortedZonesIndexMapFlags Flags;
};
typedef struct L_OcrPageSortedZonesIndexMapOptions L_OcrPageSortedZonesIndexMapOptions;

// ----------------------------------------------
// Callbacks
// ----------------------------------------------
typedef L_INT (pEXT_CALLBACK L_OcrProgressCallback)(L_OcrProgressData* data, L_VOID* userData);
typedef L_VOID (pEXT_CALLBACK L_OcrPageBitmapChangedCallback)(L_OcrPage page, L_OcrAutoPreprocessPageCommands commands, L_VOID* userData);

#if defined(L_OCRDOCUMENTSUPPORTED)
typedef L_INT (pEXT_CALLBACK L_OcrAutoRecognizeJobOperationCallback)(const L_OcrAutoRecognizeJobOperationCallbackData* data, L_VOID* userData);
typedef L_INT (pEXT_CALLBACK L_OcrAutoRecognizeRunJobCallback)(const L_OcrAutoRecognizeRunJobCallbackData* data, L_VOID* userData);
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)

typedef L_INT (pEXT_CALLBACK L_OcrRuntimeFileCallbackA)(L_OcrEngine engine, L_OcrRuntimeFileA* runtimeFile, L_VOID* userData);
#if defined(FOR_UNICODE)
typedef L_INT (pEXT_CALLBACK L_OcrRuntimeFileCallback)(L_OcrEngine engine, L_OcrRuntimeFile* runtimeFile, L_VOID* userData);
#else
#define L_OcrRuntimeFileCallback L_OcrRuntimeFileCallbackA
#endif // #if defined(FOR_UNICODE)

// ----------------------------------------------
// Functions
// ----------------------------------------------

// L_OcrMemory functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrMemory_Free(L_VOID* value);

// L_OcrEngineManager functions
// 'engine' must be freed using L_OcrEngine_Destroy
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngineManager_CreateEngine(L_OcrEngineType engineType, L_OcrEngine* engine);

// L_OcrEngine functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_Destroy(L_OcrEngine engine);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_Shutdown(L_OcrEngine engine);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_IsStarted(L_OcrEngine engine);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetEngineType(L_OcrEngine engine, L_OcrEngineType* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetSettingManager(L_OcrEngine engine, L_OcrSettingManager* settingManager);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetLanguageManager(L_OcrEngine engine, L_OcrLanguageManager* languageManager);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetSpellCheckManager(L_OcrEngine engine, L_OcrSpellCheckManager* spellCheckManager);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetZoneManager(L_OcrEngine engine, L_OcrZoneManager* zoneManager);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetDocumentManager(L_OcrEngine engine, L_OcrDocumentManager* documentManager);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_StartupA(L_OcrEngine engine, const L_CHAR* workDirectory, const L_CHAR* engineDirectory);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetWorkDirectoryA(L_OcrEngine engine, L_CHAR* value, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetEngineDirectoryA(L_OcrEngine engine, L_CHAR* value, L_UINT count);

L_LTOCR_API L_INT EXT_CALLBACK L_OcrEngine_GetRuntimeFileCallbackA(L_OcrEngine engine, L_OcrRuntimeFileCallbackA* callback, L_VOID** userData);
L_LTOCR_API L_INT EXT_CALLBACK L_OcrEngine_SetRuntimeFileCallbackA(L_OcrEngine engine, L_OcrRuntimeFileCallbackA callback, L_VOID* userData);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_CALLBACK L_OcrEngine_GetRuntimeFileCallback(L_OcrEngine engine, L_OcrRuntimeFileCallback* callback, L_VOID** userData);
L_LTOCR_API L_INT EXT_CALLBACK L_OcrEngine_SetRuntimeFileCallback(L_OcrEngine engine, L_OcrRuntimeFileCallback callback, L_VOID* userData);
#else
#define L_OcrEngine_GetRuntimeFileCallback L_OcrEngine_GetRuntimeFileCallbackA
#define L_OcrEngine_SetRuntimeFileCallback L_OcrEngine_SetRuntimeFileCallbackA
#endif

#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_Startup(L_OcrEngine engine, const L_TCHAR* workDirectory, const L_TCHAR* engineDirectory);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetWorkDirectory(L_OcrEngine engine, L_TCHAR* value, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetEngineDirectory(L_OcrEngine engine, L_TCHAR* value, L_UINT count);
#else
#define L_OcrEngine_Startup L_OcrEngine_StartupA
#define L_OcrEngine_GetWorkDirectory L_OcrEngine_GetWorkDirectoryA
#define L_OcrEngine_GetEngineDirectory L_OcrEngine_GetEngineDirectoryA
#endif // #if defined(FOR_UNICODE)

#if defined(L_OCRDOCUMENTSUPPORTED)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEngine_GetAutoRecognizeManager(L_OcrEngine engine, L_OcrAutoRecognizeManager* autoRecognizeManager);
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)

// L_OcrSettingManager functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingCount(L_OcrSettingManager settingManager, L_UINT* value);
// value must hold enough space for the setting name size, which is 120 characters, count is the actual length of 'value'
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingNameA(L_OcrSettingManager settingManager, L_UINT index, L_CHAR* value, L_UINT count);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingDescriptorsA(L_OcrSettingManager settingManager, L_OcrSettingDescriptorA** value, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_IsSettingNameSupportedA(L_OcrSettingManager settingManager, const L_CHAR* settingName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingValueTypeA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_OcrSettingValueType* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingDescriptorA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_OcrSettingDescriptorA* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetIntegerValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_INT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetIntegerValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_INT value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetEnumValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_UINT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetEnumValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_UINT value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetEnumValueAsStringA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_CHAR** value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetEnumValueAsStringA(L_OcrSettingManager settingManager, const L_CHAR* settingName, const L_CHAR* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetDoubleValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_DOUBLE* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetDoubleValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_DOUBLE value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetBooleanValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_BOOL* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetBooleanValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_BOOL value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetStringValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_CHAR** value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetStringValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, const L_CHAR* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, const L_CHAR* value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetValueA(L_OcrSettingManager settingManager, const L_CHAR* settingName, L_CHAR** value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_LoadFileA(L_OcrSettingManager settingManager, const L_CHAR* fileName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SaveFileA(L_OcrSettingManager settingManager, const L_CHAR* fileName, const L_OcrWriteXmlOptionsA* xmlOptions);
#if defined(FOR_UNICODE)
// value must hold enough space for the setting name size, which is 120 characters, count is the actual length of 'value'
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingName(L_OcrSettingManager settingManager, L_UINT index, L_TCHAR* value, L_UINT count);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingDescriptors(L_OcrSettingManager settingManager, L_OcrSettingDescriptor** value, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_IsSettingNameSupported(L_OcrSettingManager settingManager, const L_TCHAR* settingName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingValueType(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_OcrSettingValueType* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetSettingDescriptor(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_OcrSettingDescriptor* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetIntegerValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_INT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetIntegerValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_INT value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetEnumValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_UINT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetEnumValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_UINT value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetEnumValueAsString(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_TCHAR** value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetEnumValueAsString(L_OcrSettingManager settingManager, const L_TCHAR* settingName, const L_TCHAR* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetDoubleValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_DOUBLE* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetDoubleValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_DOUBLE value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetBooleanValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_BOOL* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetBooleanValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_BOOL value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetStringValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_TCHAR** value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetStringValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, const L_TCHAR* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SetValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, const L_TCHAR* value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_GetValue(L_OcrSettingManager settingManager, const L_TCHAR* settingName, L_TCHAR** value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_LoadFile(L_OcrSettingManager settingManager, const L_TCHAR* fileName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSettingManager_SaveFile(L_OcrSettingManager settingManager, const L_TCHAR* fileName, const L_OcrWriteXmlOptions* xmlOptions);
#else
#define L_OcrSettingManager_GetSettingName L_OcrSettingManager_GetSettingNameA
#define L_OcrSettingManager_GetSettingDescriptors L_OcrSettingManager_GetSettingDescriptorsA
#define L_OcrSettingManager_IsSettingNameSupported L_OcrSettingManager_IsSettingNameSupportedA
#define L_OcrSettingManager_GetSettingValueType L_OcrSettingManager_GetSettingValueTypeA
#define L_OcrSettingManager_GetSettingDescriptor L_OcrSettingManager_GetSettingDescriptorA
#define L_OcrSettingManager_GetIntegerValue L_OcrSettingManager_GetIntegerValueA
#define L_OcrSettingManager_SetIntegerValue L_OcrSettingManager_SetIntegerValueA
#define L_OcrSettingManager_GetEnumValue L_OcrSettingManager_GetEnumValueA
#define L_OcrSettingManager_SetEnumValue L_OcrSettingManager_SetEnumValueA
#define L_OcrSettingManager_GetEnumValueAsString L_OcrSettingManager_GetEnumValueAsStringA
#define L_OcrSettingManager_SetEnumValueAsString L_OcrSettingManager_SetEnumValueAsStringA
#define L_OcrSettingManager_GetDoubleValue L_OcrSettingManager_GetDoubleValueA
#define L_OcrSettingManager_SetDoubleValue L_OcrSettingManager_SetDoubleValueA
#define L_OcrSettingManager_GetBooleanValue L_OcrSettingManager_GetBooleanValueA
#define L_OcrSettingManager_SetBooleanValue L_OcrSettingManager_SetBooleanValueA
#define L_OcrSettingManager_GetStringValue L_OcrSettingManager_GetStringValueA
#define L_OcrSettingManager_SetStringValue L_OcrSettingManager_SetStringValueA
#define L_OcrSettingManager_SetValue L_OcrSettingManager_SetValueA
#define L_OcrSettingManager_GetValue L_OcrSettingManager_GetValueA
#define L_OcrSettingManager_LoadFile L_OcrSettingManager_LoadFileA
#define L_OcrSettingManager_SaveFile L_OcrSettingManager_SaveFileA
#endif // #if defined(FOR_UNICODE)

// L_OcrLanguageManager functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetLanguageNameA(L_OcrLanguage value, L_CHAR* name, L_UINT nameCount);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetLanguageValueA(const L_CHAR* name, L_OcrLanguage* value);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetLanguageName(L_OcrLanguage value, L_TCHAR* name, L_UINT nameCount);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetLanguageValue(const L_TCHAR* name, L_OcrLanguage* value);
#else
#define L_OcrLanguageManager_GetLanguageName L_OcrLanguageManager_GetLanguageNameA
#define L_OcrLanguageManager_GetLanguageValue L_OcrLanguageManager_GetLanguageValueA
#endif // #if defined(FOR_UNICODE)

// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetSupportedLanguages(L_OcrLanguageManager languageManager, L_OcrLanguage** value, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_IsLanguageSupported(L_OcrLanguageManager languageManager, L_OcrLanguage value);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetAdditionalLanguages(L_OcrLanguageManager languageManager, L_OcrLanguage** value, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_EnableLanguages(L_OcrLanguageManager languageManager, const L_OcrLanguage* value, L_UINT count);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_GetEnabledLanguages(L_OcrLanguageManager languageManager, L_OcrLanguage** value, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrLanguageManager_DetectLanguage(L_OcrLanguageManager languageManager, L_OcrPage page, const L_OcrLanguage* languages, L_UINT count, L_INT* confidences, L_UINT minimumConfidence, L_UINT* maximumConfidenceIndex);

// L_OcrEncoding functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEncoding_ToUTF8(const L_WCHAR* source, L_UINT sourceCount, L_CHAR* dest, L_UINT destCount);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrEncoding_FromUTF8(const L_CHAR* source, L_UINT sourceCount, L_WCHAR* dest, L_UINT destCount);

// L_OcrSpellCheckManager functions
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSpellCheckManager_GetSupportedLanguages(L_OcrSpellCheckManager spellCheckManager, L_OcrLanguage** value, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSpellCheckManager_IsLanguageSupported(L_OcrSpellCheckManager spellCheckManager, L_OcrLanguage value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSpellCheckManager_GetSpellChecker(L_OcrSpellCheckManager spellCheckManager, L_OcrLanguage value, L_SpellChecker* spellChecker);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSpellCheckManager_GetSpellCheckEngine(L_OcrSpellCheckManager spellCheckManager, L_OcrSpellCheckEngine* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSpellCheckManager_SetSpellCheckEngine(L_OcrSpellCheckManager spellCheckManager, L_OcrSpellCheckEngine value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrSpellCheckManager_AddUserWords(L_OcrSpellCheckManager spellCheckManager, L_OcrLanguage language, const L_WCHAR* words);

#if defined(L_OCRDOCUMENTSUPPORTED)
// L_OcrDocumentManager functions
// 'document' must be freed using L_OcrDocument_Destroy
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_CreateDocumentA(L_OcrDocumentManager documentManager, L_OcrDocument* document, L_OcrCreateDocumentOptions options, const L_CHAR* fileName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_AppendDocumentFilesA(const L_CHAR* srcFileName, const L_CHAR* dstFileName);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_CreateDocument(L_OcrDocumentManager documentManager, L_OcrDocument* document, L_OcrCreateDocumentOptions options, const L_TCHAR* fileName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_AppendDocumentFiles(const L_TCHAR* srcFileName, const L_TCHAR* dstFileName);
#else
#define L_OcrDocumentManager_CreateDocument L_OcrDocumentManager_CreateDocumentA
#define L_OcrDocumentManager_AppendDocumentFiles L_OcrDocumentManager_AppendDocumentFilesA
#endif // #if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_AppendDocuments(L_OcrDocument srcDocument, L_OcrDocument dstDocument);

L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_GetFormatOptions(L_OcrDocumentManager documentManager, DOCWRTFORMAT format, DOCWRTOPTIONS* formatOptions);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_SetFormatOptions(L_OcrDocumentManager documentManager, DOCWRTFORMAT format, const DOCWRTOPTIONS* formatOptions);
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_GetFontNameA(L_OcrDocumentManager documentManager, L_OcrLanguage language, L_OcrDocumentFontType documentFontType, L_CHAR* value, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_SetFontNameA(L_OcrDocumentManager documentManager, L_OcrLanguage language, L_OcrDocumentFontType documentFontType, const L_CHAR* value);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_GetFontName(L_OcrDocumentManager documentManager, L_OcrLanguage language, L_OcrDocumentFontType documentFontType, L_TCHAR* value, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocumentManager_SetFontName(L_OcrDocumentManager documentManager, L_OcrLanguage language, L_OcrDocumentFontType documentFontType, const L_TCHAR* value);
#else
#define L_OcrDocumentManager_GetFontName L_OcrDocumentManager_GetFontNameA
#define L_OcrDocumentManager_SetFontName L_OcrDocumentManager_SetFontNameA
#endif // #if defined(FOR_UNICODE)

#if defined(L_OCRDOCUMENTSUPPORTED)
// L_OcrDocument functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_IsInMemory(L_OcrDocument document, L_BOOL* value);
// In memory based documents this function will free the document pages so you shouldn't call L_OcrPage_Destroy on the added pages since the OcrDocument owns them
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_Destroy(L_OcrDocument document);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_AddPage(L_OcrDocument document, L_OcrPage page);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_InsertPage(L_OcrDocument document, L_INT index, L_OcrPage page);
//L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_AddPageWithNumber(L_OcrDocument document, L_OcrPage page, L_UINT pageNumber);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_GetPageCount(L_OcrDocument document, L_UINT* value);
// Below functions only supported for memory based mode
// -------------------------- BEGIN --------------------------
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_IndexOfPage(L_OcrDocument document, L_OcrPage page, L_INT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_GetPageAt(L_OcrDocument document, L_INT index, L_OcrPage* page);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_RemovePage(L_OcrDocument document, L_OcrPage page);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_RemovePageAt(L_OcrDocument document, L_INT index);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_MovePage(L_OcrDocument document, L_OcrPage page, L_INT index);
// In memory based documents this function will free the document pages so you shouldn't call L_OcrPage_Destroy on the added pages since the OcrDocument owns them
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_ClearPages(L_OcrDocument document);
// -------------------------- END --------------------------
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_GetFileNameA(L_OcrDocument document, L_CHAR* value, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_SaveA(L_OcrDocument document, const L_CHAR* fileName, DOCWRTFORMAT format, L_OcrProgressCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_SaveXmlA(L_OcrDocument document, const L_CHAR* fileName, const L_OcrWriteXmlOptionsA* xmlOptions, L_OcrXmlOutputOptions outputOptions);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_GetFileName(L_OcrDocument document, L_TCHAR* value, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_Save(L_OcrDocument document, const L_TCHAR* fileName, DOCWRTFORMAT format, L_OcrProgressCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrDocument_SaveXml(L_OcrDocument document, const L_TCHAR* fileName, const L_OcrWriteXmlOptions* xmlOptions, L_OcrXmlOutputOptions outputOptions);
#else
#define L_OcrDocument_GetFileName L_OcrDocument_GetFileNameA
#define L_OcrDocument_Save L_OcrDocument_SaveA
#define L_OcrDocument_SaveXml L_OcrDocument_SaveXmlA
#endif // #if defined(FOR_UNICODE)

#endif // // #if defined(L_OCRDOCUMENTSUPPORTED)

// L_OcrZoneManager functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrZoneManager_GetOMROptions(L_OcrZoneManager zoneManager, L_OcrOMROptions* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrZoneManager_SetOMROptions(L_OcrZoneManager zoneManager, const L_OcrOMROptions* value);

// L_OcrPage functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_Destroy(L_OcrPage page);
// 'page' must be destroyed with L_OcrPage_Destroy
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_FromBitmap(L_OcrEngine engine, L_OcrPage* page, BITMAPHANDLE* bitmapHandle, L_OcrBitmapSharingMode sharingMode, L_OcrProgressCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetBitmap(L_OcrPage page, L_OcrPageBitmapType bitmapType, BITMAPHANDLE* bitmapHandle, L_UINT bitmapHandleSize);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetBitmap(L_OcrPage page, BITMAPHANDLE* bitmapHandle, L_BOOL freeOriginalBitmap);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetOverlayBitmap(L_OcrPage page, BITMAPHANDLE* bitmapHandle, L_UINT bitmapHandleSize);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetOverlayBitmap(L_OcrPage page, BITMAPHANDLE* bitmapHandle);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetBitmapChangedCallback(L_OcrPage page, L_OcrPageBitmapChangedCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_IsInverted(L_OcrPage page, L_BOOL* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetRotateAngle(L_OcrPage page, L_INT* value, L_INT* confidence);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetDeskewAngle(L_OcrPage page, L_INT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_AutoPreprocess(L_OcrPage page, L_OcrAutoPreprocessPageCommands commands, L_OcrProgressCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_AutoZone(L_OcrPage page, L_OcrProgressCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetZoneCount(L_OcrPage page, L_UINT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_InsertZoneA(L_OcrPage page, L_INT index, const L_OcrZoneA* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_AddZoneA(L_OcrPage page, const L_OcrZoneA* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_IndexOfZoneA(L_OcrPage page, const L_OcrZoneA* ocrZone, L_INT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetZoneAtA(L_OcrPage page, L_INT index, L_OcrZoneA* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetZoneAtA(L_OcrPage page, L_INT index, const L_OcrZoneA* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_RemoveZoneA(L_OcrPage page, const L_OcrZoneA* ocrZone);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_InsertZone(L_OcrPage page, L_INT index, const L_OcrZone* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_AddZone(L_OcrPage page, const L_OcrZone* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_IndexOfZone(L_OcrPage page, const L_OcrZone* ocrZone, L_INT* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetZoneAt(L_OcrPage page, L_INT index, L_OcrZone* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetZoneAt(L_OcrPage page, L_INT index, const L_OcrZone* ocrZone);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_RemoveZone(L_OcrPage page, const L_OcrZone* ocrZone);
#else
#define L_OcrPage_InsertZone L_OcrPage_InsertZoneA
#define L_OcrPage_AddZone L_OcrPage_AddZoneA
#define L_OcrPage_IndexOfZone L_OcrPage_IndexOfZoneA
#define L_OcrPage_GetZoneAt L_OcrPage_GetZoneAtA
#define L_OcrPage_SetZoneAt L_OcrPage_SetZoneAtA
#define L_OcrPage_RemoveZone L_OcrPage_RemoveZoneA
#endif // #if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_RemoveZoneAt(L_OcrPage page, L_INT index);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_ClearZones(L_OcrPage page);
// 'map' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetSortedZonesIndexMap(L_OcrPage page, const L_OcrPageSortedZonesIndexMapOptions* options, L_UINT** map, L_UINT* count);
// 'cells' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetZoneCells(L_OcrPage page, L_INT index, L_OcrZoneCell** cells, L_UINT* count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetZoneCells(L_OcrPage page, L_INT index, const L_OcrZoneCell* cells, L_UINT count);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_HitTestZone(L_OcrPage page, L_POINT point, L_INT* zoneIndex);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_IsRecognized(L_OcrPage page, L_BOOL* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_Recognize(L_OcrPage page, L_OcrProgressCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetAreaOptions(L_OcrPage page, const L_OcrPageAreaOptions* options);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetAreaOptions(L_OcrPage page, L_OcrPageAreaOptions* options);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_Copy(L_OcrPage page, L_OcrPage* targetPage);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_Unrecognize(L_OcrPage page);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetRecognizeStatistics(L_OcrPage page, L_OcrRecognizeStatistic* statistic);
// 'pageCharacters' must be freed with L_OcrPage_FreePageCharacters
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetRecognizedCharacters(L_OcrPage page, L_OcrPageCharacters* pageCharacters);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetRecognizedCharacters(L_OcrPage page, const L_OcrPageCharacters* pageCharacters);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_FreePageCharacters(L_OcrPageCharacters* pageCharacters);
// 'words' must be freed with L_OcrPage_FreeWords
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetZoneWords(const L_OcrPageCharacters* pageCharacters, L_UINT zoneIndex, L_OcrWords* words);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_FreeWords(L_OcrWords* words);
// 'text' must be freed with L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetText(L_OcrPage page, L_INT zoneIndex, L_WCHAR** text, L_UINT* textLength);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_ExtractZoneMICRData(L_OcrPage page, L_UINT zoneIndex, L_OcrMICRData* data);
// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_DetectLanguages(L_OcrPage page, const L_OcrLanguage* languages, L_UINT languageCount, L_OcrLanguage** detectedLanguages, L_UINT* detectedLanguageCount);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_LoadZonesFileA(L_OcrPage page, const L_CHAR* fileName, L_UINT pageNumber);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveZonesFileA(L_OcrPage page, const L_CHAR* fileName, L_UINT pageNumber, const L_OcrWriteXmlOptionsA* xmlOptions);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveXmlA(L_OcrPage page, const L_CHAR* fileName, L_UINT pageNumber, const L_OcrWriteXmlOptionsA* xmlOptions, L_OcrXmlOutputOptions outputOptions);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveSvgA(L_OcrPage page, const L_CHAR* fileName);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_LoadZonesFile(L_OcrPage page, const L_TCHAR* fileName, L_UINT pageNumber);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveZonesFile(L_OcrPage page, const L_TCHAR* fileName, L_UINT pageNumber, const L_OcrWriteXmlOptions* xmlOptions);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveXml(L_OcrPage page, const L_TCHAR* fileName, L_UINT pageNumber, const L_OcrWriteXmlOptions* xmlOptions, L_OcrXmlOutputOptions outputOptions);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveSvg(L_OcrPage page, const L_TCHAR* fileName);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SaveSvgMemory(L_OcrPage page, L_HANDLE* handle, L_SIZE_T* size);

#else
#define L_OcrPage_LoadZonesFile L_OcrPage_LoadZonesFileA
#define L_OcrPage_SaveZonesFile L_OcrPage_SaveZonesFileA
#define L_OcrPage_SaveXml L_OcrPage_SaveXmlA
#define L_OcrPage_SaveSvg L_OcrPage_SaveSvgA
#endif // #if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetAutoPreprocessValues(L_OcrPage page, L_OcrPageAutoPreprocessValues* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_SetZoneCustomData(L_OcrPage page, L_INT zoneIndex, L_VOID* data);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrPage_GetZoneCustomData(L_OcrPage page, L_INT zoneIndex, L_VOID**data);

// L_OcrZone functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrZone_DefaultA(L_OcrZoneA* ocrZone);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrZone_Default(L_OcrZone* ocrZone);
#else
#define L_OcrZone_Default L_OcrZone_DefaultA
#endif // #if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrCell_Default(L_OcrZoneCell* ocrCell);

#if defined(L_OCRDOCUMENTSUPPORTED)
// L_OcrAutoRecognizeManager functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_GetOptions(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeManagerOptions* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_SetOptions(L_OcrAutoRecognizeManager autoRecognizeManager, const L_OcrAutoRecognizeManagerOptions* value);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_GetJobOperationCallback(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeJobOperationCallback* callback, L_VOID** userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_SetJobOperationCallback(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeJobOperationCallback callback, L_VOID* userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_GetRunJobCallback(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeRunJobCallback* callback, L_VOID** userData);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_SetRunJobCallback(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeRunJobCallback callback, L_VOID* userData);
// 'autoRecognizeJob' must be freed with L_OcrAutoRecognizeJob_Destroy
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_CreateJobA(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeJob* autoRecognizeJob, const L_OcrAutoRecognizeJobDataA* jobData);
#if defined(FOR_UNICODE)
// 'autoRecognizeJob' must be freed with L_OcrAutoRecognizeJob_Destroy
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_CreateJob(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeJob* autoRecognizeJob, const L_OcrAutoRecognizeJobData* jobData);
#else
#define L_OcrAutoRecognizeManager_CreateJob L_OcrAutoRecognizeManager_CreateJobA
#endif // #if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_RunJob(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeJob autoRecognizeJob);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_RunJobAsync(L_OcrAutoRecognizeManager autoRecognizeManager, L_OcrAutoRecognizeJob autoRecognizeJob);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_AbortAllJobs(L_OcrAutoRecognizeManager autoRecognizeManager);
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_RunA(L_OcrAutoRecognizeManager autoRecognizeManager, const L_CHAR* imageFileName, const L_CHAR* documentFileName, DOCWRTFORMAT format, const L_CHAR* zonesFileName);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeManager_Run(L_OcrAutoRecognizeManager autoRecognizeManager, const L_TCHAR* imageFileName, const L_TCHAR* documentFileName, DOCWRTFORMAT format, const L_TCHAR* zonesFileName);
#else
#define L_OcrAutoRecognizeManager_Run L_OcrAutoRecognizeManager_RunA
#endif // #if defined(FOR_UNICODE)

// L_OcrAutoRecognizeJob functions
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeJob_GetJobDataA(L_OcrAutoRecognizeJob autoRecognizeJob, L_OcrAutoRecognizeJobDataA* value);
#if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeJob_GetJobData(L_OcrAutoRecognizeJob autoRecognizeJob, L_OcrAutoRecognizeJobData* value);
#else
#define L_OcrAutoRecognizeJob_GetJobData L_OcrAutoRecognizeJob_GetJobDataA
#endif // #if defined(FOR_UNICODE)
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeJob_Destroy(L_OcrAutoRecognizeJob autoRecognizeJob);

// 'value' must be freed using L_OcrMemory_Free
L_LTOCR_API L_INT EXT_FUNCTION L_OcrAutoRecognizeJob_GetErrors(L_OcrAutoRecognizeJob autoRecognizeJob, L_OcrAutoRecognizeManagerJobError** value, L_UINT* count);
#endif // #if defined(L_OCRDOCUMENTSUPPORTED)

#undef L_HEADER_ENTRY
#include "ltpck.h"

#endif // #if !defined(LTOCR_H)
