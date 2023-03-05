//*************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
//*************************************************************
#if !defined(LTOCR_ENUMS_H)
#define LTOCR_ENUMS_H

// OCR engine types
enum L_OcrEngineType
{
   L_OcrEngineType_LEAD = 0
};
typedef enum L_OcrEngineType L_OcrEngineType;

enum L_OcrXmlEncoding
{
   L_OcrXmlEncoding_UTF8,
   L_OcrXmlEncoding_UTF16
};
typedef enum L_OcrXmlEncoding L_OcrXmlEncoding;

enum
{
   L_OcrXmlOutputOptions_None = 0,
   L_OcrXmlOutputOptions_Characters = 1 << 0,
   L_OcrXmlOutputOptions_CharacterAttributes = 1 << 1,
};
typedef L_UINT L_OcrXmlOutputOptions;

enum L_OcrProgressOperation
{
   L_OcrProgressOperation_LoadImage,
   L_OcrProgressOperation_SaveImage,
   L_OcrProgressOperation_PreprocessImage,
   L_OcrProgressOperation_AutoZone,
   L_OcrProgressOperation_Recognize,
   L_OcrProgressOperation_SaveDocumentPrepare,
   L_OcrProgressOperation_SaveDocument,
   L_OcrProgressOperation_SaveDocumentConvertImage,
   L_OcrProgressOperation_Formatting,
   L_OcrProgressOperation_RecognizeOMR,
   L_OcrProgressOperation_Last = L_OcrProgressOperation_RecognizeOMR
};
typedef enum L_OcrProgressOperation L_OcrProgressOperation;

// Ocr languages
enum L_OcrLanguage
{
   // Special value means "no language"
   L_OcrLanguage_None = 0,

   L_OcrLanguage_EN,       // English
   L_OcrLanguage_ES,       // Spanish
   L_OcrLanguage_FR,       // French
   L_OcrLanguage_DE,       // German
   L_OcrLanguage_IT,       // Italian
   L_OcrLanguage_BG,       // Bulgarian
   L_OcrLanguage_CA,       // Catalan
   L_OcrLanguage_CS,       // Czech
   L_OcrLanguage_DA,       // Danish
   L_OcrLanguage_EL,       // Greek
   L_OcrLanguage_FI,       // Finnish
   L_OcrLanguage_HU,       // Hungarian
   L_OcrLanguage_ID,       // Indonesian
   L_OcrLanguage_LT,       // Lithuanian
   L_OcrLanguage_LV,       // Latvian
   L_OcrLanguage_NL,       // Dutch
   L_OcrLanguage_NO,       // Norwegian
   L_OcrLanguage_PL,       // Polish
   L_OcrLanguage_PT,       // Portuguese
   L_OcrLanguage_RO,       // Romanian
   L_OcrLanguage_RU,       // Russian
   L_OcrLanguage_SK,       // Slovak
   L_OcrLanguage_SL,       // Slovenian
   L_OcrLanguage_SR,       // Serbian
   L_OcrLanguage_SV,       // Swedish
   L_OcrLanguage_TR,       // Turkish
   L_OcrLanguage_UK,       // Ukrainian
   L_OcrLanguage_VI,       // Vietnamese
   L_OcrLanguage_JA,       // Japanese
   L_OcrLanguage_KO,       // Korean
   L_OcrLanguage_ZH_HANS,  // Chinese (Simplified)
   L_OcrLanguage_ZH_HANT,  // Chinese (Traditional)
   L_OcrLanguage_AF,       // Afrikaans
   L_OcrLanguage_AZ,       // Azerbaijani
   L_OcrLanguage_BE,       // Belarusian
   L_OcrLanguage_ET,       // Estonian
   L_OcrLanguage_EU,       // Basque
   L_OcrLanguage_GL,       // Galician
   L_OcrLanguage_HR,       // Croatian
   L_OcrLanguage_IS,       // Icelandic
   L_OcrLanguage_MK,       // Macedonian
   L_OcrLanguage_MT,       // Maltese
   L_OcrLanguage_MS,       // Malay
   L_OcrLanguage_SQ,       // Albanian
   L_OcrLanguage_SW,       // Swahili
   L_OcrLanguage_TH,       // Thai
   L_OcrLanguage_TE,       // Telugu
   L_OcrLanguage_Last = L_OcrLanguage_TE
};
typedef enum L_OcrLanguage L_OcrLanguage;

enum
{
   L_OcrZoneCharacterFilters_None           = 0,
   L_OcrZoneCharacterFilters_Digit          = 1 << 0,
   L_OcrZoneCharacterFilters_Uppercase      = 1 << 1,   // for future use.
   L_OcrZoneCharacterFilters_Lowercase      = 1 << 2,   // for future use.
   L_OcrZoneCharacterFilters_Punctuation    = 1 << 3,   // for future use.
   L_OcrZoneCharacterFilters_Miscellaneous  = 1 << 4,   // for future use.
   L_OcrZoneCharacterFilters_Plus           = 1 << 5,
   L_OcrZoneCharacterFilters_All            = L_OcrZoneCharacterFilters_Digit | L_OcrZoneCharacterFilters_Uppercase | L_OcrZoneCharacterFilters_Lowercase | L_OcrZoneCharacterFilters_Punctuation | L_OcrZoneCharacterFilters_Miscellaneous,    // for future use.
   L_OcrZoneCharacterFilters_Alpha          = L_OcrZoneCharacterFilters_Uppercase | L_OcrZoneCharacterFilters_Lowercase,   // for future use.
   L_OcrZoneCharacterFilters_Numbers        = L_OcrZoneCharacterFilters_Digit | L_OcrZoneCharacterFilters_Plus,
};
typedef L_UINT L_OcrZoneCharacterFilters;

// Text direction
enum L_OcrTextDirection
{
   L_OcrTextDirection_LeftToRight,
   L_OcrTextDirection_RightToLeft,
   L_OcrTextDirection_TopToBottom,
   L_OcrTextDirection_BottomToTop,
};
typedef enum L_OcrTextDirection L_OcrTextDirection;

// Text style
// A zone might have this. Default is Normal
enum L_OcrTextStyle
{
   L_OcrTextStyle_Normal,  // Normal (flow text)
   L_OcrTextStyle_Header,  // In header section of the page. Usually smaller font
   L_OcrTextStyle_Footer,  // In footer section of the page. Usually smaller font
   L_OcrTextStyle_Heading, // Heading is a text by itself. You can use FontRatio to calculate the type of the heading (h1, h2, h3, etc)
};
typedef enum L_OcrTextStyle L_OcrTextStyle;

// Settings value type
enum L_OcrSettingValueType
{
   L_OcrSettingValueType_BeginCategory,
   L_OcrSettingValueType_EndCategory,
   L_OcrSettingValueType_Integer,
   L_OcrSettingValueType_Enum,
   L_OcrSettingValueType_Double,
   L_OcrSettingValueType_Boolean,
   L_OcrSettingValueType_String,
};
typedef enum L_OcrSettingValueType L_OcrSettingValueType;

// Character font styles
enum
{
   L_OcrCharacterFontStyles_Regular = 0,
   L_OcrCharacterFontStyles_Bold = 1 << 0,
   L_OcrCharacterFontStyles_Italic = 1 << 1,
   L_OcrCharacterFontStyles_Underline = 1 << 2,
   L_OcrCharacterFontStyles_SansSerif = 1 << 3,
   L_OcrCharacterFontStyles_Serif = 1 << 4,
   L_OcrCharacterFontStyles_Proportional = 1 << 5,
   L_OcrCharacterFontStyles_Superscript = 1 << 6,
   L_OcrCharacterFontStyles_Subscript = 1 << 7,
   L_OcrCharacterFontStyles_Strikeout = 1 << 8,
};
typedef L_UINT L_OcrCharacterFontStyles;

// Character position flags
enum
{
   L_OcrCharacterPositions_None = 0,
   L_OcrCharacterPositions_EndOfLine = 1 << 0,
   L_OcrCharacterPositions_EndOfParagraph = 1 << 1,
   L_OcrCharacterPositions_EndOfWord = 1 << 2,
   L_OcrCharacterPositions_EndOfZone = 1 << 3,
   L_OcrCharacterPositions_EndOfPage = 1 << 4,
   L_OcrCharacterPositions_EndOfCell = 1 << 5,
};
typedef L_UINT L_OcrCharacterPositions;

enum L_OcrZoneType
{
   L_OcrZoneType_Text,
   L_OcrZoneType_Table,
   L_OcrZoneType_Graphic,
   L_OcrZoneType_OMR,
   L_OcrZoneType_Micr,
   L_OcrZoneType_Icr,   // for future use, setting zone type to ICR currently ignores it and recognize zone as Text zone.
   L_OcrZoneType_Mrz,   // setting zone type to MRZ.
   L_OcrZoneType_Barcode,   // for future use, setting zone type to Barcode currently ignores it and does not recognize zone.
   L_OcrZoneType_None,
   L_OcrZoneType_FieldData,   //setting zone type to FieldData.
   L_OcrZoneType_Micr_Cmc7,   //setting zone type to MICR with CMC7 font.
   L_OcrZoneType_OcrA,   //setting zone type to MICR with CMC7 font.
   L_OcrZoneType_Last = L_OcrZoneType_OcrA,
};
typedef enum L_OcrZoneType L_OcrZoneType;

enum L_OcrOMRSensitivity
{
   L_OcrOMRSensitivity_Highest,
   L_OcrOMRSensitivity_High,
   L_OcrOMRSensitivity_Low,
   L_OcrOMRSensitivity_Lowest,
   L_OcrOMRSensitivity_Last = L_OcrOMRSensitivity_Lowest
};
typedef enum L_OcrOMRSensitivity L_OcrOMRSensitivity;

enum L_OcrOMRFrameDetectionMethod
{
   L_OcrOMRFrameDetectionMethod_Auto,
   L_OcrOMRFrameDetectionMethod_WithoutFrame,
   L_OcrOMRFrameDetectionMethod_WithFrame,
   L_OcrOMRFrameDetectionMethod_Last = L_OcrOMRFrameDetectionMethod_WithFrame
};
typedef enum L_OcrOMRFrameDetectionMethod L_OcrOMRFrameDetectionMethod;

enum L_OcrBorderLineStyle
{
   L_OcrBorderLineStyle_None,
   L_OcrBorderLineStyle_Solid,
   L_OcrBorderLineStyle_Double,
   L_OcrBorderLineStyle_Dashed,
   L_OcrBorderLineStyle_Dotted,
   L_OcrBorderLineStyle_Last = L_OcrBorderLineStyle_Dotted
};
typedef enum L_OcrBorderLineStyle L_OcrBorderLineStyle;

enum L_OcrBackgroundFillStyle
{
   L_OcrBackgroundFillStyle_None,
   L_OcrBackgroundFillStyle_Solid,
   L_OcrBackgroundFillStyle_Hatch,
   L_OcrBackgroundFillStyle_Last = L_OcrBackgroundFillStyle_Hatch
};
typedef enum L_OcrBackgroundFillStyle L_OcrBackgroundFillStyle;

enum
{
   L_OcrAutoPreprocessPageCommands_None = 0x00,
   L_OcrAutoPreprocessPageCommands_Deskew = 0x01,
   L_OcrAutoPreprocessPageCommands_Rotate = 0x02,
   L_OcrAutoPreprocessPageCommands_Invert = 0x04,
   L_OcrAutoPreprocessPageCommands_Internal = 0x08,
   L_OcrAutoPreprocessPageCommands_All = 0xFF
};
typedef L_UINT L_OcrAutoPreprocessPageCommands;

enum L_OcrPageBitmapType
{
   L_OcrPageBitmapType_Original, // Get the original image, a reference is returned and you should not free it (do not call L_FreeBitmap)
   L_OcrPageBitmapType_Processing  // Get the processing image, a copy is returned and its your responsibility to free it with L_FreeBitmap
};
typedef enum L_OcrPageBitmapType L_OcrPageBitmapType;

enum L_OcrBitmapSharingMode
{
   // The page will not free the BITMAPHANDLE when it is freed (the page does not own the BITMAPHANDLE)
   L_OcrBitmapSharingMode_None,
   // The page will free the BITMAPHANDLE when it is freed (the page owns the BITMAPHANDLE)
   L_OcrBitmapSharingMode_AutoFree,
};
typedef enum L_OcrBitmapSharingMode L_OcrBitmapSharingMode;

// Document font types
enum L_OcrDocumentFontType
{
   L_OcrDocumentFontType_ProportionalSerif,
   L_OcrDocumentFontType_ProportionalSansSerif,
   L_OcrDocumentFontType_FixedSerif,
   L_OcrDocumentFontType_FixedSansSerif,
   L_OcrDocumentFontType_ICR,    // For future use
   L_OcrDocumentFontType_MICR,
   L_OcrDocumentFontType_ProportionalSerifWide,
   L_OcrDocumentFontType_ProportionalSansSerifWide,
   L_OcrDocumentFontType_FixedSerifWide,
   L_OcrDocumentFontType_FixedSansSerifWide,
   L_OcrDocumentFontType_ProportionalSerifNarrow,
   L_OcrDocumentFontType_ProportionalSansSerifNarrow,
   L_OcrDocumentFontType_FixedSerifNarrow,
   L_OcrDocumentFontType_FixedSansSerifNarrow,
   L_OcrDocumentFontType_Last = L_OcrDocumentFontType_FixedSansSerifNarrow
};
typedef enum L_OcrDocumentFontType L_OcrDocumentFontType;

enum
{
   L_OcrCreateDocumentOptions_None = 0,
   L_OcrCreateDocumentOptions_InMemory = 1 << 0,
   L_OcrCreateDocumentOptions_AutoDeleteFile = 1 << 1,
   L_OcrCreateDocumentOptions_LoadExisting = 1 << 2
};
typedef L_UINT L_OcrCreateDocumentOptions;

enum L_OcrAutoRecognizeManagerJobOperation
{
   L_OcrAutoRecognizeManagerJobOperation_Other,
   L_OcrAutoRecognizeManagerJobOperation_CreateDocument,
   L_OcrAutoRecognizeManagerJobOperation_LoadPage,
   L_OcrAutoRecognizeManagerJobOperation_PreprocessPage,
   L_OcrAutoRecognizeManagerJobOperation_ZonePage,
   L_OcrAutoRecognizeManagerJobOperation_RecognizePage,
   L_OcrAutoRecognizeManagerJobOperation_SavePage,
   L_OcrAutoRecognizeManagerJobOperation_Append,
   L_OcrAutoRecognizeManagerJobOperation_ConvertDocument
};
typedef enum L_OcrAutoRecognizeManagerJobOperation L_OcrAutoRecognizeManagerJobOperation;

enum L_OcrAutoRecognizeManagerJobErrorMode
{
   L_OcrAutoRecognizeManagerJobErrorMode_Abort,      // Default, abort the recognition process
   L_OcrAutoRecognizeManagerJobErrorMode_Continue,   // Continue next page, depends on operation:
};
typedef enum L_OcrAutoRecognizeManagerJobErrorMode L_OcrAutoRecognizeManagerJobErrorMode;

enum L_OcrTraceCategory
{
   L_OcrTraceCategory_Info,
   L_OcrTraceCategory_Warning,
   L_OcrTraceCategory_Error
};
typedef enum L_OcrTraceCategory L_OcrTraceCategory;

enum L_OcrSpellCheckEngine
{
   L_OcrSpellCheckEngine_None,
   L_OcrSpellCheckEngine_Native,
   L_OcrSpellCheckEngine_OS,
   L_OcrSpellCheckEngine_Hunspell
};
typedef enum L_OcrSpellCheckEngine L_OcrSpellCheckEngine;

enum L_OcrRuntimeFileMode
{
   L_OcrRuntimeFileMode_Exists,
   L_OcrRuntimeFileMode_Open,
   L_OcrRuntimeFileMode_Close
};
typedef enum L_OcrRuntimeFileMode L_OcrRuntimeFileMode;

// OcrPage Sorted Zones Index MapFlags
enum
{
   L_OcrPageSortedZonesIndexMapFlags_None = 0,
   L_OcrPageSortedZonesIndexMapFlags_TableCellsAsOne = 1 << 0,
};
typedef L_UINT L_OcrPageSortedZonesIndexMapFlags;

#endif // #if !defined(LTOCR_ENUMS_H)
