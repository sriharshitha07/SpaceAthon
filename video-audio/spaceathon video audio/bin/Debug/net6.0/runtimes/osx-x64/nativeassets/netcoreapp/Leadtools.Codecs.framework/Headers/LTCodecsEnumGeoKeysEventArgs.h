// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsEnumGeoKeysEventArgs.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterTagMetadata.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsEnumGeoKeysEventArgs : NSObject

@property (nonatomic, assign)                     BOOL cancel;

@property (nonatomic, assign, readonly)           NSInteger tagId;

@property (nonatomic, assign, readonly)           NSUInteger count;

@property (nonatomic, assign, readonly)           LTRasterTagMetadataDataType metadataType;

@property (nonatomic, assign, readonly, nullable) const unsigned char *data;
@property (nonatomic, assign, readonly)           NSUInteger dataLength;

@property (nonatomic, strong, readonly)           LTRasterTagMetadata *rasterTagMetadata;

@end

NS_ASSUME_NONNULL_END
