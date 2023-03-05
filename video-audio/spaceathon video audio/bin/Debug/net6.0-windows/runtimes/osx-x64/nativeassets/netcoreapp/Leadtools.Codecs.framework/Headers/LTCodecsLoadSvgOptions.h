// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsLoadSvgOptions.h
//  Leadtools.Codecs
//

#import <Leadtools/LTLeadtools.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsLoadSvgOptions : NSObject <NSCopying, NSSecureCoding>

@property (nonatomic, assign) BOOL dropShapes;
@property (nonatomic, assign) BOOL dropImages;
@property (nonatomic, assign) BOOL dropText;
@property (nonatomic, assign) BOOL forConversion;
@property (nonatomic, assign) BOOL ignoreXmlParsingErrors;
@property (nonatomic, assign) BOOL forceTextPath;
@property (nonatomic, assign) BOOL forceRealText;

@property (nonatomic, assign) NSInteger maximumElements;

@property (nonatomic, assign) BOOL allowPolylineText LT_DEPRECATED(19_0);

@end

NS_ASSUME_NONNULL_END
