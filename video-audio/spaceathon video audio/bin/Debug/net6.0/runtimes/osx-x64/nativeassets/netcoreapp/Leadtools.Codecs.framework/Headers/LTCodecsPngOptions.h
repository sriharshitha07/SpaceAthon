// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsPngOptions.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPngLoadOptions : NSObject

@property (nonatomic, strong, null_resettable) NSData *trnsChunk;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPngSaveOptions : NSObject

@property (nonatomic, assign) NSInteger qualityFactor;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPngOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsPngLoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsPngSaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
