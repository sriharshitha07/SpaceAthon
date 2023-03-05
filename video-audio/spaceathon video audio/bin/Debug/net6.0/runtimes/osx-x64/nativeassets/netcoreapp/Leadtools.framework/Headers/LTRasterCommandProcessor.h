// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterCommandProcessor.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_ENUM(NSInteger, LTRasterCommandProcessorCancel) {
    LTRasterCommandProcessorCancelNone,
    LTRasterCommandProcessorCancelCommand,
    LTRasterCommandProcessorCancelImage,
    LTRasterCommandProcessorCancelAll
};

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Batch processes a collection of @p LTRasterCommand object on a collection of @p LTRasterImage objects.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterCommandProcessorEvent : NSObject

@property (nonatomic, assign, readonly) NSInteger percent;

@property (nonatomic, assign, readonly) NSInteger commandNumber;
@property (nonatomic, assign, readonly) NSInteger imageNumber;

@property (nonatomic, assign, readonly) NSUInteger commandCount;
@property (nonatomic, assign, readonly) NSUInteger imageCount;

@property (nonatomic, strong, readonly) LTRasterImage *image;
@property (nonatomic, strong, readonly) __kindof LTRasterCommand *command;

- (instancetype)init NS_UNAVAILABLE;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterCommandProcessor : NSObject

@property (nonatomic, strong, readonly) NSMutableArray<__kindof LTRasterCommand *> *commands;
@property (nonatomic, strong, readonly) NSMutableArray<LTRasterImage *> *images;

- (BOOL)run:(void (^ __nullable NS_NOESCAPE)(LTRasterCommandProcessorEvent *event, LTRasterCommandProcessorCancel *cancel))progress error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
