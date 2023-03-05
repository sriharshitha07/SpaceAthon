// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsTxtOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterColor.h>

typedef NS_ENUM(NSInteger, LTCodecsTxtEncoding) {
    LTCodecsTxtEncodingAuto      = 0,
    LTCodecsTxtEncodingAnsi      = 1,
    LTCodecsTxtEncodingUtf7      = 2,
    LTCodecsTxtEncodingUtf8      = 3,
    LTCodecsTxtEncodingUtf16LE   = 4,
    LTCodecsTxtEncodingUtf16BE   = 5,
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsTxtLoadOptions : NSObject

@property (nonatomic, assign) BOOL enabled;
@property (nonatomic, assign) BOOL bold;
@property (nonatomic, assign) BOOL italic;
@property (nonatomic, assign) BOOL underline;
@property (nonatomic, assign) BOOL strikethrough;
@property (nonatomic, assign) LTCodecsTxtEncoding defaultEncoding;

@property (nonatomic, assign) NSInteger fontSize;

@property (nonatomic, copy)   NSString *faceName;

@property (nonatomic, copy)   LTRasterColor *fontColor;
@property (nonatomic, copy)   LTRasterColor *highlight;
@property (nonatomic, copy)   LTRasterColor *backColor;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsTxtOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsTxtLoadOptions *load;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
