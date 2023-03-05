// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsPsdLayerInfo.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImage.h>

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPsdLayerInfo : NSObject

@property (nonatomic, assign)           NSInteger left;
@property (nonatomic, assign)           NSInteger top;

@property (nonatomic, assign)           unsigned char opacity;
@property (nonatomic, assign)           unsigned char clipping;

@property (nonatomic, assign)           uint32_t blendModeKey;

@property (nonatomic, assign, readonly) BOOL transparencyProtected;
@property (nonatomic, assign, readonly) BOOL visible;
@property (nonatomic, assign, readonly) BOOL obsolete;
@property (nonatomic, assign, readonly) BOOL psd5OrLater;
@property (nonatomic, assign)           BOOL loadMaskImage;

@property (nonatomic, strong, nullable) LTRasterImage *maskImage;

@property (nonatomic, copy, nullable)   NSString *name;

@end
