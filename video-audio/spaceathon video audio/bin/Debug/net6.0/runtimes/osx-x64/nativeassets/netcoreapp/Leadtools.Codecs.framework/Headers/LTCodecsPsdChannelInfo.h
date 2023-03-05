// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsPsdChannelInfo.h
//  Leadtools.Codecs
//

typedef NS_ENUM(NSInteger, LTCodecsPsdChannelType) {
    LTCodecsPsdChannelTypeAlpha = 0,
    LTCodecsPsdChannelTypeRed,
    LTCodecsPsdChannelTypeGreen,
    LTCodecsPsdChannelTypeBlue,
    LTCodecsPsdChannelTypeCyan,
    LTCodecsPsdChannelTypeMagenta,
    LTCodecsPsdChannelTypeYellow,
    LTCodecsPsdChannelTypeKey,
    LTCodecsPsdChannelTypeGray,
    LTCodecsPsdChannelTypeBitmap,
    LTCodecsPsdChannelTypeLightness,
    LTCodecsPsdChannelTypeA,
    LTCodecsPsdChannelTypeB
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPsdChannelInfo : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, copy, readonly, nullable) NSString *name;
@property (nonatomic, assign, readonly)         LTCodecsPsdChannelType channelType;

@end

NS_ASSUME_NONNULL_END
