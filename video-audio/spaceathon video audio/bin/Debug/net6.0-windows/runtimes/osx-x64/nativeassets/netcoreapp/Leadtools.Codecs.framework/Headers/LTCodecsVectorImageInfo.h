// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsVectorImageInfo.h
//  Leadtools.Codecs
//

typedef NS_ENUM(NSInteger, LTCodecsVectorUnit) {
    LTCodecsVectorUnitInches = 0,
    LTCodecsVectorUnitFeet,
    LTCodecsVectorUnitYards,
    LTCodecsVectorUnitMiles,
    LTCodecsVectorUnitMicrometers,
    LTCodecsVectorUnitMilimeters,
    LTCodecsVectorUnitCentimeters,
    LTCodecsVectorUnitMeters,
    LTCodecsVectorUnitKilometers,
    LTCodecsVectorUnitTwips,
    LTCodecsVectorUnitPoints,
    LTCodecsVectorUnitPixels,
    LTCodecsVectorUnitDummy = -1
};

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsVectorImageInfo : NSObject

@property (nonatomic, assign, readonly) BOOL isVectorFile;

@property (nonatomic, assign, readonly) double parallelogramMinX;
@property (nonatomic, assign, readonly) double parallelogramMinY;
@property (nonatomic, assign, readonly) double parallelogramMinZ;

@property (nonatomic, assign, readonly) double parallelogramMaxX;
@property (nonatomic, assign, readonly) double parallelogramMaxY;
@property (nonatomic, assign, readonly) double parallelogramMaxZ;

@property (nonatomic, assign, readonly) LTCodecsVectorUnit unit;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
