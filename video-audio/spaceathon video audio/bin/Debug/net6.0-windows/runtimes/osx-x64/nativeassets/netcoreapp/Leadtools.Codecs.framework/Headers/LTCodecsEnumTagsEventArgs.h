// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsEnumTagsEventArgs.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterTagMetadata.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsEnumTagsEventArgs : NSObject

@property (nonatomic, assign)           BOOL cancel;

@property (nonatomic, assign, readonly) NSInteger tagId;

@property (nonatomic, assign, readonly) NSUInteger count;

@property (nonatomic, assign, readonly) LTRasterTagMetadataDataType metadataType;

@end

NS_ASSUME_NONNULL_END
