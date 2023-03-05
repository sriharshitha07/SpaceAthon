// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTEnums.h
//  Leadtools.Svg
//

typedef NS_ENUM(NSInteger, LTSvgElementType) {
    LTSvgElementTypeUnknown,
    LTSvgElementTypeDoc,
    LTSvgElementTypeSvg,
    LTSvgElementTypeG,
    LTSvgElementTypeDefs,
    LTSvgElementTypeDesc,
    LTSvgElementTypeTitle,
    LTSvgElementTypeSymbol,
    LTSvgElementTypeUse,
    LTSvgElementTypeImage,
    LTSvgElementTypeSwitch,
    LTSvgElementTypeStyle,
    LTSvgElementTypePath,
    LTSvgElementTypeRect,
    LTSvgElementTypeCircle,
    LTSvgElementTypeEllipse,
    LTSvgElementTypeLine,
    LTSvgElementTypePolyline,
    LTSvgElementTypePolygon,
    LTSvgElementTypeText,
    LTSvgElementTypeTSpan,
    LTSvgElementTypeTRef,
    LTSvgElementTypeTextPath,
    LTSvgElementTypeAltGlyph,
    LTSvgElementTypeAltGlyphDef,
    LTSvgElementTypeAltGlyphItem,
    LTSvgElementTypeGlyphRef,
    LTSvgElementTypeMarker,
    LTSvgElementTypeColorProfile,
    LTSvgElementTypeLinearGradient,
    LTSvgElementTypeRadialGradient,
    LTSvgElementTypeStop,
    LTSvgElementTypePattern,
    LTSvgElementTypeClipPath,
    LTSvgElementTypeFont,
    LTSvgElementTypeGlyph,
    LTSvgElementTypeMissingGlyph,
    LTSvgElementTypeHKern,
    LTSvgElementTypeVKern,
    LTSvgElementTypeFontFace,
    LTSvgElementTypeFontFaceSrc,
    LTSvgElementTypeFontFaceUri,
    LTSvgElementTypeFontFaceFormat,
    LTSvgElementTypeFontFaceName,
    LTSvgElementTypeDefinitionSrc,
    LTSvgElementTypeAnchor
};

typedef NS_ENUM(NSInteger, LTSvgVersion) {
    LTSvgVersionUnspecified,
    LTSvgVersionV10,
    LTSvgVersionV11,
};

typedef NS_ENUM(NSInteger, LTSvgEnumerateDirection) {
    LTSvgEnumerateDirectionTop,
    LTSvgEnumerateDirectionTopToBottom,
    LTSvgEnumerateDirectionBottomToTop
};

typedef NS_OPTIONS(NSUInteger, LTSvgLoadFlags) {
    LTSvgLoadFlagsDefault                = 0,
    LTSvgLoadFlagsDropShapes             = 1 << 0,
    LTSvgLoadFlagsDropImages             = 1 << 1,
    LTSvgLoadFlagsDropText               = 1 << 2,
    LTSvgLoadFlagsIgnoreXmlParsingErrors = 1 << 3
};

typedef NS_ENUM(NSInteger, LTSvgEncoding) {
    LTSvgEncodingUTF8,
    LTSvgEncodingUTF16
};

typedef NS_OPTIONS(NSUInteger, LTSvgTextCharacterFlags) {
    LTSvgTextCharacterFlagsNone      = 0,
    LTSvgTextCharacterFlagsEndOfWord = 1 << 0,
    LTSvgTextCharacterFlagsEndOfLine = 1 << 1,
    LTSvgTextCharacterFlagsLineBreak = 1 << 2,
};

typedef NS_OPTIONS(NSUInteger, LTSvgSortFlags) {
    LTSvgSortFlagsDefault     = 0,
    LTSvgSortFlagsLeftToRight = 0,
    LTSvgSortFlagsTopToBottom = 0,
    LTSvgSortFlagsRightToLeft = 1 << 0,
    LTSvgSortFlagsBottomToTop = 1 << 1,
};

typedef NS_OPTIONS(NSUInteger, LTSvgExtractText) {
    LTSvgExtractTextCharacter   = 0,
    LTSvgExtractTextWord        = 1 << 0,
    LTSvgExtractTextLine        = 1 << 1,
    LTSvgExtractTextExactBounds = 1 << 2,
};

typedef NS_ENUM(NSInteger, LTSvgCharacterDirection) {
    LTSvgCharacterDirectionLeftToRight,
    LTSvgCharacterDirectionRightToLeft
};

typedef NS_OPTIONS(NSUInteger, LTSvgDropFlags) {
    LTSvgDropFlagsNone   = 0,
    LTSvgDropFlagsShapes = 1 << 0,
    LTSvgDropFlagsImages = 1 << 2,
    LTSvgDropFlagsText   = 1 << 3,
};

typedef NS_ENUM(NSInteger, LTSvgFormat) {
    LTSvgFormatSvg,
    LTSvgFormatSvgz,
};
