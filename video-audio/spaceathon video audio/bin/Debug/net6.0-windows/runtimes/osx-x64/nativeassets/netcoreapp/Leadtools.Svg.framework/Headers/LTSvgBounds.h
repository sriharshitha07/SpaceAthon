// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSvgBounds.h
//  Leadtools.Svg
//

#import <Leadtools/LTPrimitives.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgBounds : NSObject <NSCopying, NSCoding>

@property (nonatomic, assign) BOOL isValid;
@property (nonatomic, assign) BOOL isTrimmed;

@property (nonatomic, assign) LeadSizeD resolution;
@property (nonatomic, assign) LeadRectD bounds;

@end

NS_ASSUME_NONNULL_END
