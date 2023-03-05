// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsPsdImageInfo.h
//  Leadtools.Codecs
//

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPsdImageInfo : NSObject

@property (nonatomic, assign, readonly) NSInteger layers;
@property (nonatomic, assign, readonly) NSInteger channels;

- (instancetype)init __unavailable;

@end
