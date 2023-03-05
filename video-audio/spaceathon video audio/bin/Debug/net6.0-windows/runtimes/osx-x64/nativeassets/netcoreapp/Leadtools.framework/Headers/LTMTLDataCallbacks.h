// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTMTLDataCallbacks.h
//  Leadtools
//

#if __has_include(<Metal/Metal.h>)

#import <Metal/Metal.h>
#import <Leadtools/LTRasterImageDataCallbacks.h>


NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_11, 8_0)
@interface LTMTLBufferDataCallbacks : LTRasterImageDataCallbacks

@property (nonatomic, strong, readonly, nullable) id<MTLBuffer> buffer;
@property (nonatomic, assign, readonly)           NSUInteger offset;

- (instancetype)initWithDevice:(id<MTLDevice>)device resourceOptions:(MTLResourceOptions)resourceOptions;
- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_11, 8_0)
@interface LTMTLTextureDataCallbacks : LTRasterImageDataCallbacks

@property (nonatomic, strong, readonly, nullable) id<MTLTexture> texture;

- (instancetype)initWithDevice:(id<MTLDevice>)device resourceOptions:(MTLResourceOptions)resourceOptions;
- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END

#endif // #if __has_include(<Metal/Metal.h>)
