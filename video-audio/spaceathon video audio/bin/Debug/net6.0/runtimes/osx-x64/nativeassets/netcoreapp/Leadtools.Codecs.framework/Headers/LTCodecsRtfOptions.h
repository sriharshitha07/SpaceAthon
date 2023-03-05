// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsRtfOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsRtfLoadOptions : NSObject

@property (nonatomic, copy) LTRasterColor *backColor;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsRtfOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsRtfLoadOptions *load;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
