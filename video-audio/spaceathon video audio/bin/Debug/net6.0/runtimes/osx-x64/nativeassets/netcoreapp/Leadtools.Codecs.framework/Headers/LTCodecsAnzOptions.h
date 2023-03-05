// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsAnzOptions.h
//  Leadtools.Codecs
//

typedef NS_ENUM(NSInteger, LTCodecsAnzView) {
    LTCodecsAnzViewTransverse,
    LTCodecsAnzViewSagittal,
    LTCodecsAnzViewCoronal
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsAnzLoadOptions : NSObject

@property (nonatomic, assign) LTCodecsAnzView view;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsAnzOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsAnzLoadOptions *load;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
