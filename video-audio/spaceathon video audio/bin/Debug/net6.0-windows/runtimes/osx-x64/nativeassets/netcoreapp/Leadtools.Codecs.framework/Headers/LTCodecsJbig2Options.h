// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsJbig2Options.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJbig2LoadOptions : NSObject

@property (nonatomic, assign) BOOL loadOldFiles;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJbig2SaveOptions : NSObject

@property (nonatomic, assign) NSUInteger imageQualityFactor;
@property (nonatomic, assign) NSUInteger xResolution;
@property (nonatomic, assign) NSUInteger yResolution;

@property (nonatomic, assign) NSUInteger textMinimumSymbolArea;
@property (nonatomic, assign) NSUInteger textMinimumSymbolWidth;
@property (nonatomic, assign) NSUInteger textMinimumSymbolHeight;
@property (nonatomic, assign) NSUInteger textMaximumSymbolArea;
@property (nonatomic, assign) NSUInteger textMaximumSymbolWidth;
@property (nonatomic, assign) NSUInteger textMaximumSymbolHeight;
@property (nonatomic, assign) NSUInteger textDifferentialThreshold;
@property (nonatomic, assign) NSUInteger textQualityFactor;

@property (nonatomic, assign) BOOL imageTypicalPredictionOn;
@property (nonatomic, assign) BOOL textRemoveUnrepeatedSymbol;
@property (nonatomic, assign) BOOL textKeepAllSymbols;
@property (nonatomic, assign) BOOL removeMarker;
@property (nonatomic, assign) BOOL removeHeaderSegment;
@property (nonatomic, assign) BOOL removeEopSegment;
@property (nonatomic, assign) BOOL removeEofSegment;
@property (nonatomic, assign) BOOL enableDictionary;

@property (nonatomic, assign) NSUInteger imageTemplateType;
@property (nonatomic, assign) NSInteger imageGbatX1;
@property (nonatomic, assign) NSInteger imageGbatY1;
@property (nonatomic, assign) NSInteger imageGbatX2;
@property (nonatomic, assign) NSInteger imageGbatY2;
@property (nonatomic, assign) NSInteger imageGbatX3;
@property (nonatomic, assign) NSInteger imageGbatY3;
@property (nonatomic, assign) NSInteger imageGbatX4;
@property (nonatomic, assign) NSInteger imageGbatY4;

@property (nonatomic, assign) NSUInteger textTemplateType;
@property (nonatomic, assign) NSInteger textGbatX1;
@property (nonatomic, assign) NSInteger textGbatY1;
@property (nonatomic, assign) NSInteger textGbatX2;
@property (nonatomic, assign) NSInteger textGbatY2;
@property (nonatomic, assign) NSInteger textGbatX3;
@property (nonatomic, assign) NSInteger textGbatY3;
@property (nonatomic, assign) NSInteger textGbatX4;
@property (nonatomic, assign) NSInteger textGbatY4;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJbig2Options : NSObject

@property (nonatomic, strong, readonly) LTCodecsJbig2LoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsJbig2SaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
