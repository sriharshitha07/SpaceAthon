// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsDefines.h
//  Leadtools.Codecs
//

typedef NS_ENUM(NSInteger, LTCodecsLoadByteOrder) {
    LTCodecsLoadByteOrderRgb             = 0,
    LTCodecsLoadByteOrderBgr             = 1,
    LTCodecsLoadByteOrderGray            = 2,
    LTCodecsLoadByteOrderRgbOrGray       = 3,
    LTCodecsLoadByteOrderBgrOrGray       = 4,
    LTCodecsLoadByteOrderRomm            = 5,
    LTCodecsLoadByteOrderBgrOrGrayOrRomm = 6,
};

typedef NS_ENUM(NSInteger, LTCodecsPlanarConfiguration) {
    LTCodecsPlanarConfigurationChunky       = 1,
    LTCodecsPlanarConfigurationPlanarFormat = 2
};

typedef NS_ENUM(NSInteger, LTCodecsSavePageMode) {
    LTCodecsSavePageModeAppend,
    LTCodecsSavePageModeInsert,
    LTCodecsSavePageModeReplace,
    LTCodecsSavePageModeOverwrite
};

typedef NS_ENUM(NSInteger, LTCodecsOverlayCallbackMode) {
    LTCodecsOverlayCallbackModeLoadCall = 1,
    LTCodecsOverlayCallbackModeCallLoad = 2,
    LTCodecsOverlayCallbackModeCallOnly = 3,
    LTCodecsOverlayCallbackModeLoadOnly = 4
};

typedef NS_ENUM(NSInteger, LTCodecsTiffPhotometricInterpretation) {
    LTCodecsTiffPhotometricInterpretationMinimumIsWhite = 0,
    LTCodecsTiffPhotometricInterpretationMinimumIsBlack = 1,
    LTCodecsTiffPhotometricInterpretationRgb            = 2,
    LTCodecsTiffPhotometricInterpretationPalette        = 3,
    LTCodecsTiffPhotometricInterpretationMask           = 4,
    LTCodecsTiffPhotometricInterpretationSeparated      = 5,
    LTCodecsTiffPhotometricInterpretationYcbCr          = 6,
    LTCodecsTiffPhotometricInterpretationCieLab         = 8
};

typedef NS_ENUM(NSInteger, LTCodecsRasterizeDocumentUnit) {
    LTCodecsRasterizeDocumentUnitPixel       = 0,
    LTCodecsRasterizeDocumentUnitInch        = 1,
    LTCodecsRasterizeDocumentUnitMillimeter  = 2
};

typedef NS_ENUM(NSInteger, LTCodecsRasterizeDocumentSizeMode) {
    LTCodecsRasterizeDocumentSizeModeNone        = 0,
    LTCodecsRasterizeDocumentSizeModeFit         = 1,
    LTCodecsRasterizeDocumentSizeModeFitAlways   = 2,
    LTCodecsRasterizeDocumentSizeModeFitWidth    = 3,
    LTCodecsRasterizeDocumentSizeModeStretch     = 4
};

typedef NS_ENUM(NSInteger, LTCodecsRasterPdfVersion) {
    LTCodecsRasterPdfVersionV12,
    LTCodecsRasterPdfVersionV14,
    LTCodecsRasterPdfVersionPdfA,
    LTCodecsRasterPdfVersionV15,
    LTCodecsRasterPdfVersionV16,
    LTCodecsRasterPdfVersionV13,
    LTCodecsRasterPdfVersionV17,
};
