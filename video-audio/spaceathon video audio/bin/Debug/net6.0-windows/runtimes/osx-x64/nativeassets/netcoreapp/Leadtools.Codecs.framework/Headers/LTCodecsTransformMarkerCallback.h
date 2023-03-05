// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsTransformMarkerCallback.h
//  Leadtools.Codecs
//

typedef NS_OPTIONS(NSUInteger, LTCodecsTransformFlags) {
    LTCodecsTransformFlagsNone        = 0,
    LTCodecsTransformFlagsFlip        = 0x0001,
    LTCodecsTransformFlagsReverse     = 0x0002,
    LTCodecsTransformFlagsRotate90    = 0x0004,
    LTCodecsTransformFlagsRotate180   = 0x0008,
    LTCodecsTransformFlagsRotate270   = 0x000C
};

typedef NS_OPTIONS(NSInteger, LTCodecsTransformMarkerAction) {
    LTCodecsTransformMarkerActionDefault  = 0,
    LTCodecsTransformMarkerActionIgnore   = 1,
    LTCodecsTransformMarkerActionAbort    = 2
};

NS_ASSUME_NONNULL_BEGIN

typedef LTCodecsTransformMarkerAction (^LTCodecsTransformMarkerCallback)(NSInteger markerId, unsigned char *buffer, NSUInteger length, LTCodecsTransformFlags transform);

NS_ASSUME_NONNULL_END
