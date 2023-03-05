// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsRasterizeDocumentOptions.h
//  Leadtools.Codecs
//

#import <Leadtools.Codecs/LTCodecsDefines.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsRasterizeDocumentLoadOptions : NSObject

@property (nonatomic, assign) NSUInteger xResolution;
@property (nonatomic, assign) NSUInteger yResolution;

@property (nonatomic, assign) double pageWidth;
@property (nonatomic, assign) double pageHeight;
@property (nonatomic, assign) double leftMargin;
@property (nonatomic, assign) double topMargin;
@property (nonatomic, assign) double rightMargin;
@property (nonatomic, assign) double bottomMargin;

@property (nonatomic, assign) LTCodecsRasterizeDocumentUnit unit;
@property (nonatomic, assign) LTCodecsRasterizeDocumentSizeMode sizeMode;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsRasterizeDocumentOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsRasterizeDocumentLoadOptions *load;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
