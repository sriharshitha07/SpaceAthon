// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsOptimizedLoadData.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsOptimizedLoadData : NSObject

@property (nonatomic, assign) NSInteger codecIndex;

@property (nonatomic, strong, nullable) NSData* data;

-(void)freeUnmanagedData;

@end

NS_ASSUME_NONNULL_END
