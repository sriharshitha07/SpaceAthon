// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsStartDecompressOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterImageFormat.h>

#import <Leadtools.Codecs/LTCodecsDefines.h>

typedef NS_ENUM(NSInteger, LTCodecsStartDecompressDataType) {
    LTCodecsStartDecompressDataTypeStrips,
    LTCodecsStartDecompressDataTypeTiles
};

typedef NS_OPTIONS(NSUInteger, LTCodecsDecompressDataFlags) {
    LTCodecsDecompressDataFlagsNone     = 0,
    LTCodecsDecompressDataFlagsStart    = 1,
    LTCodecsDecompressDataFlagsEnd      = 2,
    LTCodecsDecompressDataFlagsComplete = (LTCodecsDecompressDataFlagsStart | LTCodecsDecompressDataFlagsEnd)
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsStartDecompressOptions : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, assign)           BOOL leastSignificantBitFirst;
@property (nonatomic, assign)           BOOL pad4;
@property (nonatomic, assign)           BOOL usePalette;

@property (nonatomic, assign)           NSInteger width;
@property (nonatomic, assign)           NSInteger height;
@property (nonatomic, assign)           NSInteger bitsPerPixel;
@property (nonatomic, assign)           NSInteger xResolution;
@property (nonatomic, assign)           NSInteger yResolution;

@property (nonatomic, assign)           LTRasterImageFormat format;
@property (nonatomic, assign)           LTRasterViewPerspective viewPerspective;
@property (nonatomic, assign)           LTRasterByteOrder rawOrder;
@property (nonatomic, assign)           LTCodecsStartDecompressDataType dataType;
@property (nonatomic, assign)           LTCodecsLoadByteOrder loadOrder;
@property (nonatomic, assign)           LTCodecsTiffPhotometricInterpretation tiffPhotometricInterpretation;
@property (nonatomic, assign)           LTCodecsPlanarConfiguration planarConfiguration;

@property (nonatomic, strong, nullable) NSArray<LTRasterColor *> *palette;
@property (nonatomic, strong, nullable) NSArray<LTRasterColor *> *colorMask;

@end

NS_ASSUME_NONNULL_END
