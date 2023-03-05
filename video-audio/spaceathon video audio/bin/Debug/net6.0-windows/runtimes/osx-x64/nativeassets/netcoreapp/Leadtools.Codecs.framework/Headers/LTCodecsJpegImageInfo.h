// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsJpegImageInfo.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpegImageInfo : NSObject

@property (nonatomic, assign, readonly) BOOL hasStamp;
@property (nonatomic, assign, readonly) BOOL isProgressive;
@property (nonatomic, assign, readonly) BOOL isLossless;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
