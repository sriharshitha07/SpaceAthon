// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsTiffImageInfo.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsTiffImageInfo : NSObject

@property (nonatomic, assign, readonly) BOOL isBigTiff;
@property (nonatomic, assign, readonly) BOOL hasNoPalette;
@property (nonatomic, assign, readonly) BOOL isImageFileDirectoryOffsetValid;

@property (nonatomic, assign, readonly) unsigned long imageFileDirectoryOffset;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
