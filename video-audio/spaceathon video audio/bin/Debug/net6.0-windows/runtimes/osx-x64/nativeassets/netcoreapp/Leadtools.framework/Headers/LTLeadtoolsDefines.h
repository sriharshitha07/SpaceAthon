// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLeadtoolsDefines.h
//  Leadtools
//

#if !defined(LTLEADTOOLSDEFINES_H)
#define LTLEADTOOLSDEFINES_H

typedef NS_ENUM(NSInteger, LTRasterRegionCombineMode) {
    LTRasterRegionCombineModeAnd          = 0,
    LTRasterRegionCombineModeSet          = 1,
    LTRasterRegionCombineModeAndNotImage  = 2,
    LTRasterRegionCombineModeAndNotRegion = 3,
    LTRasterRegionCombineModeOr           = 4,
    LTRasterRegionCombineModeXor          = 5,
    LTRasterRegionCombineModeSetNot       = 6
};

typedef NS_ENUM(NSInteger, LTRasterViewPerspective) {
    LTRasterViewPerspectiveTopLeft       = 1,
    LTRasterViewPerspectiveBottomLeft    = 4,
    LTRasterViewPerspectiveTopRight      = 2,
    LTRasterViewPerspectiveBottomLeft180 = 2,
    LTRasterViewPerspectiveBottomRight   = 3,
    LTRasterViewPerspectiveTopLeft180    = 3,
    LTRasterViewPerspectiveRightTop      = 6,
    LTRasterViewPerspectiveTopLeft90     = 6,
    LTRasterViewPerspectiveLeftBottom    = 8,
    LTRasterViewPerspectiveTopLeft270    = 8,
    LTRasterViewPerspectiveLeftTop       = 5,
    LTRasterViewPerspectiveBottomLeft90  = 5,
    LTRasterViewPerspectiveRightBottom   = 7,
    LTRasterViewPerspectiveBottomLeft270 = 7
};

typedef NS_ENUM(NSInteger, LTRasterGrayscaleMode) {
    LTRasterGrayscaleModeNone           = 0,
    LTRasterGrayscaleModeOrderedNormal  = 1,
    LTRasterGrayscaleModeOrderedInverse = 2,
    LTRasterGrayscaleModeNotOrdered     = 3
};

typedef NS_OPTIONS(NSUInteger, LTRasterImageChangedFlags) {
    LTRasterImageChangedFlagsNone                = 0x00000000,
    LTRasterImageChangedFlagsData                = 0x00000001,
    LTRasterImageChangedFlagsSize                = 0x00000002,
    LTRasterImageChangedFlagsBitsPerPixel        = 0x00000004,
    LTRasterImageChangedFlagsViewPerspective     = 0x00000008,
    LTRasterImageChangedFlagsOrder               = 0x00000010,
    LTRasterImageChangedFlagsPalette             = 0x00000020,
    LTRasterImageChangedFlagsLookupTablePalette  = 0x00000040,
    LTRasterImageChangedFlagsRegion              = 0x00000080,
    LTRasterImageChangedFlagsResolution          = 0x00000100,
    LTRasterImageChangedFlagsLowHighBit          = 0x00000200,
    LTRasterImageChangedFlagsMinMaxValue         = 0x00000400,
    LTRasterImageChangedFlagsNoRegionClip        = 0x00000800,
    LTRasterImageChangedFlagsPaintLookupTable    = 0x00001000,
    LTRasterImageChangedFlagsPaintParameters     = 0x00002000,
    LTRasterImageChangedFlagsDitheringMethod     = 0x00004000,
    LTRasterImageChangedFlagsUseLookupTable      = 0x00008000,
    LTRasterImageChangedFlagsUsePaintLookupTable = 0x00010000,
    LTRasterImageChangedFlagsTransparentColor    = 0x00020000,
    LTRasterImageChangedFlagsOverlaysInfo        = 0x00040000,
    LTRasterImageChangedFlagsPlayParameters      = 0x00080000,
    LTRasterImageChangedFlagsPage                = 0x00200000,
    LTRasterImageChangedFlagsPageCount           = 0x00400000,
    LTRasterImageChangedFlagsTag                 = 0x00800000,
    LTRasterImageChangedFlagsComment             = 0x01000000,
    LTRasterImageChangedFlagsMarker              = 0x02000000,
    LTRasterImageChangedFlagsGeoKey              = 0x04000000,
    LTRasterImageChangedFlagsFormat              = 0x08000000,
    LTRasterImageChangedFlagsAnimationProperties = 0x10000000,
    LTRasterImageChangedFlagsPremultiplyAlpha    = 0x20000000,
};

typedef NS_ENUM(NSInteger, LTRasterByteOrder) {
    LTRasterByteOrderRgb    = 0,
    LTRasterByteOrderBgr    = 1,
    LTRasterByteOrderGray   = 2,
    LTRasterByteOrderRomm   = 5,
    LTRasterByteOrderRgb565 = 7,
};

typedef NS_ENUM(NSInteger, LTRasterDitheringMethod) {
    LTRasterDitheringMethodNone          = 0,
    LTRasterDitheringMethodFloydStein    = 1,
    LTRasterDitheringMethodStucki        = 2,
    LTRasterDitheringMethodBurkes        = 3,
    LTRasterDitheringMethodSierra        = 4,
    LTRasterDitheringMethodStevensonArce = 5,
    LTRasterDitheringMethodJarvis        = 6,
    LTRasterDitheringMethodOrdered       = 7,
    LTRasterDitheringMethodClustered     = 8,
};

typedef NS_OPTIONS(NSUInteger, LTRasterMemoryFlags) {
    LTRasterMemoryFlagsNone            = 0x0000,
    LTRasterMemoryFlagsConventional    = 0x0001,
    LTRasterMemoryFlagsUser            = 0x0002,
    LTRasterMemoryFlagsTiled           = 0x0004,
    LTRasterMemoryFlagsNoTiled         = 0x0008,
    LTRasterMemoryFlagsDisk            = 0x0080,
    LTRasterMemoryFlagsNoDisk          = 0x0100,
    LTRasterMemoryFlagsCompressed      = 0x0200,
    LTRasterMemoryFlagsSuperCompressed = 0x0400,
    LTRasterMemoryFlagsWriteableBitmap = 0x0800,
};

typedef NS_ENUM(NSInteger, LTRasterWindowLevelMode) {
    LTRasterWindowLevelModePaint              = 0,
    LTRasterWindowLevelModePaintAndProcessing = 1
};

typedef NS_ENUM(NSInteger, LTRasterCompression) {
    LTRasterCompressionNone  = 0,
    LTRasterCompressionRle   = 1,
    LTRasterCompressionSuper = 2
};

typedef NS_OPTIONS(NSUInteger, LTRasterImageUnderlayFlags) {
    LTRasterImageUnderlayFlagsNone    = 0x00,
    LTRasterImageUnderlayFlagsStretch = 0x01
};

typedef NS_OPTIONS(NSUInteger, LTRasterMetadataFlags) {
    LTRasterMetadataFlagsNone     = 0,
    LTRasterMetadataFlagsComments = 0x0001,
    LTRasterMetadataFlagsTags     = 0x0002,
    LTRasterMetadataFlagsMarkers  = 0x0004,
    LTRasterMetadataFlagsGeoKeys  = 0x0008,
    LTRasterMetadataFlagsAll      = LTRasterMetadataFlagsComments | LTRasterMetadataFlagsTags | LTRasterMetadataFlagsMarkers | LTRasterMetadataFlagsGeoKeys
} NS_SWIFT_NAME(LTRasterMetadata.Flags);

typedef NS_ENUM(NSInteger, LTRasterGetSetOverlayImageMode) {
    LTRasterGetSetOverlayImageModeCopy   = 0,
    LTRasterGetSetOverlayImageModeNoCopy = 1,
    LTRasterGetSetOverlayImageModeMove   = 3
};

typedef NS_OPTIONS(NSUInteger, LTRasterUpdateOverlayBitsFlags) {
    LTRasterUpdateOverlayBitsFlagsNone        = 0,
    LTRasterUpdateOverlayBitsFlagsFromOverlay = 0x0001,
    LTRasterUpdateOverlayBitsFlagsFromImage   = 0x0002,
    LTRasterUpdateOverlayBitsFlagsClear       = 0x0004
};

typedef NS_OPTIONS(NSUInteger, LTRasterGetSetOverlayAttributesFlags) {
    LTRasterGetSetOverlayAttributesFlagsNone     = 0,
    LTRasterGetSetOverlayAttributesFlagsOrigin   = 0x0001,
    LTRasterGetSetOverlayAttributesFlagsColor    = 0x0002,
    LTRasterGetSetOverlayAttributesFlagsFlags    = 0x0004,
    LTRasterGetSetOverlayAttributesFlagsBitIndex = 0x0008,
    LTRasterGetSetOverlayAttributesFlagsDicom    = 0x0010
};

typedef NS_ENUM(NSInteger, LTRasterPaintSizeMode) {
    LTRasterPaintSizeModeNormal    = 0,
    LTRasterPaintSizeModeFit       = 1,
    LTRasterPaintSizeModeFitAlways = 2,
    LTRasterPaintSizeModeFitWidth  = 3,
    LTRasterPaintSizeModeStretch   = 4
};

typedef NS_ENUM(NSInteger, LTRasterPaintAlignMode) {
    LTRasterPaintAlignModeNear         = 0,
    LTRasterPaintAlignModeCenter       = 1,
    LTRasterPaintAlignModeCenterAlways = 2,
    LTRasterPaintAlignModeFar          = 3
};

typedef NS_OPTIONS(NSUInteger, LTRasterSizeFlags) {
    LTRasterSizeFlagsNone        = 0x0000,
    LTRasterSizeFlagsFavorBlack  = 0x0001,
    LTRasterSizeFlagsResample    = 0x0002,
    LTRasterSizeFlagsBicubic     = 0x0004,
    LTRasterSizeFlagsScaleToGray = 0x0008
};

typedef NS_ENUM(NSInteger, LTRasterImageAnimationDisposalMethod) {
    LTRasterImageAnimationDisposalMethodNone              = 0,
    LTRasterImageAnimationDisposalMethodLeave             = 1,
    LTRasterImageAnimationDisposalMethodRestoreBackground = 2,
    LTRasterImageAnimationDisposalMethodRestorePrevious   = 3
};

typedef NS_ENUM(NSInteger, LTRasterConvertToDibType) {
    LTRasterConvertToDibTypeBitmapInfoHeader = 0,
    LTRasterConvertToDibTypeBitmapV4Header = 1,
    LTRasterConvertToDibTypeBitmapV5Header = 2
};

typedef NS_ENUM(NSInteger, LTLeadFillMode) {
    LTLeadFillModeAlternate,
    LTLeadFillModeWinding
};

typedef NS_ENUM(NSInteger, LTRasterYUVFormat) {
    LTRasterYUVFormatYV12,
    LTRasterYUVFormatNV12,
    LTRasterYUVFormatNV21,
    LTRasterYUVFormatYUY2
};

#endif // #if !defined(LTLEADTOOLSDEFINES_H)
