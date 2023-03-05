// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterColorSpace.h
//  Leadtools
//

typedef NS_ENUM(NSInteger, LTRasterColorSpaceFormat8) {
    LTRasterColorSpaceFormat8Rgb  = 0x00,
    LTRasterColorSpaceFormat8Yuv  = 0x01,
    LTRasterColorSpaceFormat8Cmyk = 0x02,
    LTRasterColorSpaceFormat8Hsv  = 0x03,
    LTRasterColorSpaceFormat8Hls  = 0x04,
    LTRasterColorSpaceFormat8Yiq  = 0x05,
    LTRasterColorSpaceFormat8Cmy  = 0x06,
    LTRasterColorSpaceFormat8Lab  = 0x07,
    LTRasterColorSpaceFormat8Xyz  = 0x08,
    LTRasterColorSpaceFormat8Ycck = 0x0B,
    LTRasterColorSpaceFormat8Bgr  = 0x0C,
    LTRasterColorSpaceFormat8Y41p = 0x0D,
    LTRasterColorSpaceFormat8Uyvy = 0x0E,
    LTRasterColorSpaceFormat8Yuy2 = 0x09,
    LTRasterColorSpaceFormat8Yvu9 = 0x0A,
    LTRasterColorSpaceFormat8Ycc  = 0x0F
};

typedef NS_ENUM(NSInteger, LTRasterColorSpaceFormat16) {
    LTRasterColorSpaceFormat16Rgb  = 0x10,
    LTRasterColorSpaceFormat16Yuv  = 0x20,
    LTRasterColorSpaceFormat16Yiq  = 0x30,
    LTRasterColorSpaceFormat16Hsv  = 0x40,
    LTRasterColorSpaceFormat16Hls  = 0x50,
    LTRasterColorSpaceFormat16Cmy  = 0x60,
    LTRasterColorSpaceFormat16Cmyk = 0x70,
    LTRasterColorSpaceFormat16Ihs  = 0x80
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterColorSpace : NSObject

+ (BOOL)convert8:(const void *)inputBuffer inputBufferOffset:(uint64_t)ioffset outputBuffer:(void *)outputBuffer outputBufferOffset:(uint64_t)ooffset width:(NSInteger)width inputFormat:(LTRasterColorSpaceFormat8)inputFormat outputFormat:(LTRasterColorSpaceFormat8)outputFormat error:(NSError **)error;
+ (BOOL)convert16:(const void *)inputBuffer inputBufferOffset:(uint64_t)ioffset outputBuffer:(void *)outputBuffer outputBufferOffset:(uint64_t)ooffset width:(NSInteger)width inputFormat:(LTRasterColorSpaceFormat16)inputFormat outputFormat:(LTRasterColorSpaceFormat16)outputFormat error:(NSError **)error;

+ (BOOL)convert8:(NSData *)inputData outputData:(NSMutableData *)outputData width:(NSInteger)width inputFormat:(LTRasterColorSpaceFormat8)inputFormat outputFormat:(LTRasterColorSpaceFormat8)outputFormat error:(NSError **)error;
+ (BOOL)convert16:(NSData *)inputData outputData:(NSMutableData *)outputData width:(NSInteger)width inputFormat:(LTRasterColorSpaceFormat16)inputFormat outputFormat:(LTRasterColorSpaceFormat16)outputFormat error:(NSError **)error;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
