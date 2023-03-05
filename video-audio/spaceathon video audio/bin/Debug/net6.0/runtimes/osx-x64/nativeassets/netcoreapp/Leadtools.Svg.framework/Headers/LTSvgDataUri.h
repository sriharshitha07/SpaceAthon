// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSvgDataUri.h
//  Leadtools.Svg
//

#import <Leadtools/LTRasterImageFormat.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgDataUri : NSObject

@property (nonatomic, assign)         BOOL isDataUri;
@property (nonatomic, assign)         BOOL isBase64;

@property (nonatomic, assign)         NSUInteger mediaOffset;
@property (nonatomic, assign)         NSUInteger mediaLength;
@property (nonatomic, assign)         NSUInteger charSetOffset;
@property (nonatomic, assign)         NSUInteger charSetLength;
@property (nonatomic, assign)         NSUInteger valueOffset;
@property (nonatomic, assign)         NSUInteger valueLength;

@property (nonatomic, assign)         LTRasterImageFormat imageFormat;

@property (nonatomic, copy, nullable) NSString *hRef;
@property (nonatomic, copy, nullable) NSString *extension;

+ (nullable instancetype)parseHRef:(NSString *)hRef error:(NSError **)error;

+ (nullable NSString *)encodeFromData:(NSData *)data error:(NSError **)error NS_SWIFT_NAME(encode(from:));
+ (nullable NSString *)encodeFromFile:(NSString *)file error:(NSError **)error NS_SWIFT_NAME(encode(from:));

- (BOOL)decodeToData:(NSMutableData *)data error:(NSError **)error NS_SWIFT_NAME(decode(to:));
- (BOOL)decodeToFile:(NSString *)file error:(NSError **)error NS_SWIFT_NAME(decode(to:));

@end

NS_ASSUME_NONNULL_END
