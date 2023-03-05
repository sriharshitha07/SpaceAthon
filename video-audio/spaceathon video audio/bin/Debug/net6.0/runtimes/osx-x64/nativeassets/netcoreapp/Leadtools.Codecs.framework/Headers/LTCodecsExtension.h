// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsExtension.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImage.h>

typedef NS_OPTIONS(NSUInteger, LTCodecsExtensionListFlags) {
    LTCodecsExtensionListFlagsNone  = 0,
    LTCodecsExtensionListFlagsStamp = 0x0001,
    LTCodecsExtensionListFlagsAudio = 0x0002
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsExtension : NSObject

@property (nonatomic, copy, readonly, nullable)   NSString *name;
@property (nonatomic, assign, readonly)           NSData *data;
@property (nonatomic, assign, readonly, nullable) NSUUID *clsid;
@property (nonatomic, assign, readonly)           unsigned char ucDefault;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsExtensionList : NSObject

@property (nonatomic, assign, readonly)           LTCodecsExtensionListFlags flags;
@property (nonatomic, strong, readonly, nullable) NSArray<LTCodecsExtension *> *extensions;

- (nullable LTRasterImage *)createStamp:(NSError **)error;
- (nullable NSData *)getAudioData:(NSInteger)stream error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
