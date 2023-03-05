// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsFaxImageInfo.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsFaxImageInfo : NSObject

@property (nonatomic, assign, readonly) BOOL isCompressed;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
