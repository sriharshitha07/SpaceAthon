// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsPageEventArgs.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTLeadStream.h>

typedef NS_ENUM(NSInteger, LTCodecsPageEventCommand) {
    LTCodecsPageEventCommandContinue,
    LTCodecsPageEventCommandSkip,
    LTCodecsPageEventCommandStop
};

typedef NS_ENUM(NSInteger, LTCodecsPageEventState) {
    LTCodecsPageEventStateBefore,
    LTCodecsPageEventStateAfter
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsPageEventArgs : NSObject

@property (nonatomic, assign, readonly)           NSUInteger page;
@property (nonatomic, assign, readonly)           NSUInteger pageCount;

@property (nonatomic, strong, readonly, nullable) LTRasterImage *image;
@property (nonatomic, strong, readonly, nullable) LTLeadStream *stream;

@property (nonatomic, assign, readonly)           LTCodecsPageEventState state;
@property (nonatomic, assign)                     LTCodecsPageEventCommand command;

@end

NS_ASSUME_NONNULL_END
