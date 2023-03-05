// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools/LTRasterImageDataCallbacks.h>

#import <Leadtools.Codecs/LTCodecsAbcOptions.h>
#import <Leadtools.Codecs/LTCodecsAnzOptions.h>
#import <Leadtools.Codecs/LTCodecsDocOptions.h>
#import <Leadtools.Codecs/LTCodecsEpsOptions.h>
#import <Leadtools.Codecs/LTCodecsFpxOptions.h>
#import <Leadtools.Codecs/LTCodecsGifOptions.h>
#import <Leadtools.Codecs/LTCodecsJbigOptions.h>
#import <Leadtools.Codecs/LTCodecsJbig2Options.h>
#import <Leadtools.Codecs/LTCodecsJpegOptions.h>
#import <Leadtools.Codecs/LTCodecsHeicOptions.h>
#import <Leadtools.Codecs/LTCodecsJpeg2000Options.h>
#import <Leadtools.Codecs/LTCodecsPdfOptions.h>
#import <Leadtools.Codecs/LTCodecsPngOptions.h>
#import <Leadtools.Codecs/LTCodecsPtokaOptions.h>
#import <Leadtools.Codecs/LTCodecsRawOptions.h>
#import <Leadtools.Codecs/LTCodecsRtfOptions.h>
#import <Leadtools.Codecs/LTCodecsTiffOptions.h>
#import <Leadtools.Codecs/LTCodecsTxtOptions.h>
#import <Leadtools.Codecs/LTCodecsVectorOptions.h>
#import <Leadtools.Codecs/LTCodecsVffOptions.h>
#import <Leadtools.Codecs/LTCodecsExcelOptions.h>
#import <Leadtools.Codecs/LTCodecsPowerPointOptions.h>
#import <Leadtools.Codecs/LTCodecsRasterizeDocumentOptions.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsLoadOptions : NSObject

@property (nonatomic, assign)           BOOL markers;
@property (nonatomic, assign)           BOOL tags;
@property (nonatomic, assign)           BOOL geoKeys;
@property (nonatomic, assign)           BOOL comments;
@property (nonatomic, assign)           BOOL allocateImage;
@property (nonatomic, assign)           BOOL storeDataInImage;
@property (nonatomic, assign)           BOOL allPages;
@property (nonatomic, assign)           BOOL rotated;
@property (nonatomic, assign)           BOOL isSigned;
@property (nonatomic, assign)           BOOL initAlpha;
@property (nonatomic, assign)           BOOL premultiplyAlpha;
@property (nonatomic, assign)           BOOL fixedPalette;
@property (nonatomic, assign)           BOOL noInterlace;
@property (nonatomic, assign)           BOOL compressed;
@property (nonatomic, assign)           BOOL superCompressed;
@property (nonatomic, assign)           BOOL tiledMemory;
@property (nonatomic, assign)           BOOL noTiledMemory;
@property (nonatomic, assign)           BOOL diskMemory;
@property (nonatomic, assign)           BOOL noDiskMemory;
@property (nonatomic, assign)           BOOL loadCorrupted;
@property (nonatomic, assign)           BOOL preferVector;
@property (nonatomic, assign)           BOOL autoFixImageResolution;
@property (nonatomic, assign)           BOOL ignoreEmbeddedIccProfile;

@property (nonatomic, assign)           LTRasterImageFormat format;

@property (nonatomic, strong, nullable) LTRasterImageDataCallbacks *dataCallbacks;

@property (nonatomic, assign)           uint64_t maximumConventionalMemorySize;

@property (nonatomic, copy, nullable)   NSString *name;

@property (nonatomic, assign)           NSInteger resolution;
@property (nonatomic, assign)           NSInteger xResolution;
@property (nonatomic, assign)           NSInteger yResolution;
@property (nonatomic, assign)           NSInteger passes;

- (instancetype)init __unavailable;

- (void)reset;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsSaveOptions : NSObject

@property (nonatomic, assign)         BOOL markers;
@property (nonatomic, assign)         BOOL tags;
@property (nonatomic, assign)         BOOL geoKeys;
@property (nonatomic, assign)         BOOL comments;
@property (nonatomic, assign)         BOOL retrieveDataFromImage;
@property (nonatomic, assign)         BOOL motorolaOrder;
@property (nonatomic, assign)         BOOL fixedPalette;
@property (nonatomic, assign)         BOOL optimizePalette;
@property (nonatomic, assign)         BOOL grayOutput;
@property (nonatomic, assign)         BOOL useImageDitheringMethod;
@property (nonatomic, assign)         BOOL initAlpha;

@property (nonatomic, copy, nullable) NSString *password;
@property (nonatomic, copy)           NSArray<NSValue /*CGSize*/ *> *resolutions;

- (instancetype)init __unavailable;

- (void)reset;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsOptions : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, strong, readonly) LTCodecsLoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsSaveOptions *save;

@property (nonatomic, strong, readonly) LTCodecsAbcOptions *abc;
@property (nonatomic, strong, readonly) LTCodecsAnzOptions *anz;
@property (nonatomic, strong, readonly) LTCodecsDocOptions *doc;
@property (nonatomic, strong, readonly) LTCodecsEpsOptions *eps;
@property (nonatomic, strong, readonly) LTCodecsFpxOptions *fpx;
@property (nonatomic, strong, readonly) LTCodecsGifOptions *gif;
@property (nonatomic, strong, readonly) LTCodecsJbigOptions *jbig;
@property (nonatomic, strong, readonly) LTCodecsJbig2Options *jbig2;
@property (nonatomic, strong, readonly) LTCodecsJpegOptions *jpeg;
@property (nonatomic, strong, readonly) LTCodecsJpeg2000Options *jpeg2000;
@property (nonatomic, strong, readonly) LTCodecsHeicOptions* heic;
@property (nonatomic, strong, readonly) LTCodecsPdfOptions *pdf;
@property (nonatomic, strong, readonly) LTCodecsPngOptions *png;
@property (nonatomic, strong, readonly) LTCodecsPtokaOptions *ptoka;
@property (nonatomic, strong, readonly) LTCodecsRawOptions *raw;
@property (nonatomic, strong, readonly) LTCodecsRtfOptions *rtf;
@property (nonatomic, strong, readonly) LTCodecsTiffOptions *tiff;
@property (nonatomic, strong, readonly) LTCodecsTxtOptions *txt;
@property (nonatomic, strong, readonly) LTCodecsVectorOptions *vector;
@property (nonatomic, strong, readonly) LTCodecsVffOptions *vff;
@property (nonatomic, strong, readonly) LTCodecsExcelLoadOptions *excel;
@property(nonatomic, strong, readonly)  LTCodecsPowerPointLoadOptions* powerPoint;
@property (nonatomic, strong, readonly) LTCodecsRasterizeDocumentOptions *rasterizeDocument;

@end

NS_ASSUME_NONNULL_END
