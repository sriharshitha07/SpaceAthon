// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsHeicOptions.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsHeicLoadOptions : NSObject

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsHeicSaveOptions : NSObject

@property (nonatomic, assign) NSInteger qualityFactor;
@property (nonatomic, assign) NSUInteger stampWidth;
@property (nonatomic, assign) NSUInteger stampHeight;
@property (nonatomic, assign) NSUInteger stampBitsPerPixel;

@property (nonatomic, assign) BOOL saveWithStamp;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsHeicOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsHeicLoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsHeicSaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
