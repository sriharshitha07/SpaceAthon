// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterImageResize.h
//  Leadtools
//

#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImageResizeData : NSObject

@property (nonatomic, strong, readonly) LTRasterImage *image;

@property (nonatomic, assign, readonly) NSInteger row;
@property (nonatomic, assign, readonly) NSInteger column;
@property (nonatomic, assign, readonly) NSInteger bytes;

@property (nonatomic, assign, readonly) void *buffer;

- (instancetype)init NS_UNAVAILABLE;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImageResize : NSObject

- (BOOL)startResize:(LTRasterImage *)image width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order ditheringMethod:(LTRasterDitheringMethod)ditheringMethod sizeFlags:(LTRasterSizeFlags)sizeFlags palette:(NSArray<LTRasterColor *> *)palette callback:(void (^ __nullable)(LTRasterImageResizeData *, BOOL *))callback error:(NSError **)error;
- (BOOL)stop:(NSError **)error;

- (BOOL)resizeDataBuffer:(NSMutableData *)data row:(NSInteger)row column:(NSInteger)column error:(NSError **)error;
- (BOOL)resizeBuffer:(void *)buffer bytes:(NSUInteger)bytes row:(NSInteger)row column:(NSInteger)column error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
