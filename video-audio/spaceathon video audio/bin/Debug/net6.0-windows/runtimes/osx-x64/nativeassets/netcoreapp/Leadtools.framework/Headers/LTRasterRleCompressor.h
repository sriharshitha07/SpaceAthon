// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterRleCompressor.h
//  Leadtools
//

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterRleCompressor : NSObject

+ (BOOL)compressRow:(uint16_t *)runBuffer buffer:(uint8_t *)buffer column:(NSInteger)column width:(NSInteger)width error:(NSError **)error;
+ (BOOL)compressRows:(uint16_t *)runBuffer buffer:(uint8_t *)buffer width:(NSInteger)width rows:(NSInteger)rows error:(NSError **)error;

+ (BOOL)expandRow:(uint16_t *)runBuffer buffer:(uint8_t *)buffer column:(NSInteger)column width:(NSInteger)width error:(NSError **)error;
+ (BOOL)expandRows:(uint16_t *)runBuffer buffer:(uint8_t *)buffer width:(NSInteger)width rows:(NSInteger)rows error:(NSError **)error;

- (instancetype)init NS_UNAVAILABLE;

@end
