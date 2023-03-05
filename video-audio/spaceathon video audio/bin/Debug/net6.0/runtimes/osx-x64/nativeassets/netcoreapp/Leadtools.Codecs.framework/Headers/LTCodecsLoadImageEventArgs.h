// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsLoadImageEventArgs.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTLeadStream.h>
#import <Leadtools/LTPrimitives.h>

#import <Leadtools.Codecs/LTCodecsImageInfo.h>

typedef NS_OPTIONS(NSUInteger, LTCodecsLoadImageFlags) {
    LTCodecsLoadImageFlagsNone        = 0,
    LTCodecsLoadImageFlagsFirstPass   = 0x0001,
    LTCodecsLoadImageFlagsLastPass    = 0x0002,
    LTCodecsLoadImageFlagsFirstRow    = 0x0004,
    LTCodecsLoadImageFlagsLastRow     = 0x0008,
    LTCodecsLoadImageFlagsCompressed  = 0x0010
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsLoadImageEventArgs : NSObject

@property (nonatomic, assign, readonly)           BOOL tileValid;
@property (nonatomic, assign)                     BOOL cancel;

@property (nonatomic, assign, readonly)           NSInteger firstPage;
@property (nonatomic, assign, readonly)           NSInteger page;
@property (nonatomic, assign, readonly)           NSInteger lastPage;
@property (nonatomic, assign, readonly)           NSInteger imagePage;
@property (nonatomic, assign, readonly)           NSInteger pagePercent;
@property (nonatomic, assign, readonly)           NSInteger totalPercent;
@property (nonatomic, assign, readonly)           NSInteger row;
@property (nonatomic, assign, readonly)           NSInteger lines;

@property (nonatomic, assign, readonly)           LeadRect tile;

@property (nonatomic, strong, readonly, nullable) LTCodecsImageInfo *info;
@property (nonatomic, assign, readonly)           LTCodecsLoadImageFlags flags;

@property (nonatomic, assign, readonly, nullable) unsigned char *buffer;
@property (nonatomic, assign, readonly)           NSUInteger bufferLength;

@property (nonatomic, strong, readonly, nullable) LTRasterImage *image;
@property (nonatomic, strong, readonly, nullable) LTLeadStream *stream;

@end

NS_ASSUME_NONNULL_END
