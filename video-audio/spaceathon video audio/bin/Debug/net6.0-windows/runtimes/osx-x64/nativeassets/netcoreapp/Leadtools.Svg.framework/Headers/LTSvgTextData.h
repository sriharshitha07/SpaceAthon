// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSvgTextData.h
//  Leadtools.Svg
//

#import <Leadtools/LTPrimitives.h>
#import <Leadtools.Svg/LTEnums.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgTextData : NSObject

@property (nonatomic, copy, nullable)           NSString *text;

@property (nonatomic, strong, null_unspecified) NSArray<NSValue *> *bounds; //LeadRectD

@property (nonatomic, strong, null_unspecified) NSArray<NSNumber *> *characterFlags; //LTSvgTextCharacterFlags
@property (nonatomic, strong, null_unspecified) NSArray<NSNumber *> *directions; //LTSvgCharacterDirection

@end

NS_ASSUME_NONNULL_END
