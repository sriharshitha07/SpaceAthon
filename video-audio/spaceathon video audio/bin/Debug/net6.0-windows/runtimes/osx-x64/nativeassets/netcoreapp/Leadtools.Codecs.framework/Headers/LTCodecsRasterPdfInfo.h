// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsRasterPdfInfo.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools.Codecs/LTCodecsDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsRasterPdfInfo : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, assign) BOOL isLeadPdf;

@property (nonatomic, assign) NSInteger bitsPerPixel;
@property (nonatomic, assign) NSInteger width;
@property (nonatomic, assign) NSInteger height;
@property (nonatomic, assign) NSInteger xResolution;
@property (nonatomic, assign) NSInteger yResolution;

@property (nonatomic, assign) LTRasterImageFormat format;
@property (nonatomic, assign) LTCodecsRasterPdfVersion version;

@end

NS_ASSUME_NONNULL_END
