// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsImageInfo.h
//  Leadtools.Codecs
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools/LTRasterColor.h>

#import <Leadtools.Codecs/LTCodecsGifImageInfo.h>
#import <Leadtools.Codecs/LTCodecsFaxImageInfo.h>
#import <Leadtools.Codecs/LTCodecsJpegImageInfo.h>
#import <Leadtools.Codecs/LTCodecsHeicImageInfo.h>
#import <Leadtools.Codecs/LTCodecsPsdImageInfo.h>
#import <Leadtools.Codecs/LTCodecsPstImageInfo.h>
#import <Leadtools.Codecs/LTCodecsTiffImageInfo.h>
#import <Leadtools.Codecs/LTCodecsVectorImageInfo.h>
#import <Leadtools.Codecs/LTCodecsDocumentImageInfo.h>

typedef NS_ENUM(NSInteger, LTCodecsColorSpaceType) {
    LTCodecsColorSpaceTypeBgr      = 0,
    LTCodecsColorSpaceTypeYuv      = 1,
    LTCodecsColorSpaceTypeCmyk     = 2,
    LTCodecsColorSpaceTypeCieLab   = 3
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsImageInfo : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, assign, readonly)           BOOL hasResolution;
@property (nonatomic, assign, readonly)           BOOL hasAlpha;
@property (nonatomic, assign, readonly)           BOOL hasStamp;
@property (nonatomic, assign, readonly)           BOOL hasBom;
@property (nonatomic, assign, readonly)           BOOL isRotated;
@property (nonatomic, assign, readonly)           BOOL isSigned;
@property (nonatomic, assign, readonly)           BOOL isLoading;
@property (nonatomic, assign, readonly)           BOOL isLink;

@property (nonatomic, assign, readonly)           NSInteger width;
@property (nonatomic, assign, readonly)           NSInteger height;
@property (nonatomic, assign, readonly)           NSInteger imageWidth;
@property (nonatomic, assign, readonly)           NSInteger imageHeight;
@property (nonatomic, assign, readonly)           NSInteger bitsPerPixel;
@property (nonatomic, assign, readonly)           NSInteger bytesPerLine;
@property (nonatomic, assign, readonly)           NSInteger totalPages;
@property (nonatomic, assign, readonly)           NSInteger xResolution;
@property (nonatomic, assign, readonly)           NSInteger yResolution;
@property (nonatomic, assign, readonly)           NSInteger pageNumber;
@property (nonatomic, assign, readonly)           NSInteger horizontalTiles;
@property (nonatomic, assign, readonly)           NSInteger verticalTiles;

@property (nonatomic, assign, readonly)           unsigned long sizeDisk;
@property (nonatomic, assign, readonly)           unsigned long sizeMemory;

@property (nonatomic, assign, readonly)           LTRasterViewPerspective viewPerspective;
@property (nonatomic, assign, readonly)           LTRasterByteOrder order;
@property (nonatomic, assign, readonly)           LTCodecsColorSpaceType colorSpace;
@property (nonatomic, assign, readonly)           LTRasterImageFormat format;

@property (nonatomic, copy, readonly, nullable)   NSString *name;
@property (nonatomic, copy, readonly, nullable)   NSString *compression;

@property (nonatomic, strong, readonly, nullable) NSArray<LTRasterColor *> *palette;

@property (nonatomic, strong, readonly)           LTCodecsGifImageInfo *gif;
@property (nonatomic, strong, readonly)           LTCodecsFaxImageInfo *fax;
@property (nonatomic, strong, readonly)           LTCodecsJpegImageInfo *jpeg;
@property (nonatomic, strong, readonly)           LTCodecsHeicImageInfo* heic;
@property (nonatomic, strong, readonly)           LTCodecsPsdImageInfo *psd;
@property (nonatomic, strong, readonly)           LTCodecsPstImageInfo *pst;
@property (nonatomic, strong, readonly)           LTCodecsTiffImageInfo *tiff;
@property (nonatomic, strong, readonly)           LTCodecsVectorImageInfo *vector;
@property (nonatomic, strong, readonly)           LTCodecsDocumentImageInfo *document;

@end

NS_ASSUME_NONNULL_END
