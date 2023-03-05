// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSvgElementInfo.h
//  Leadtools.Svg
//

#import <Leadtools/LTPrimitives.h>
#import <Leadtools.Svg/LTSvgTextData.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgElementInfo : NSObject

@property (nonatomic, assign)           LTSvgElementType elementType;

@property (nonatomic, assign)           LeadRectD bounds;

@property (nonatomic, strong, nullable) LTSvgTextData *textData;

@end

NS_ASSUME_NONNULL_END
