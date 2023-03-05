// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsJpeg2000Options.h
//  Leadtools.Codecs
//

#import <Leadtools/LTPrimitives.h>

typedef NS_ENUM(NSInteger, LTCodecsJpeg2000CompressionControl) {
    LTCodecsJpeg2000CompressionControlLossless       = 0,
    LTCodecsJpeg2000CompressionControlRatio          = 1,
    LTCodecsJpeg2000CompressionControlTargetSize     = 2,
    LTCodecsJpeg2000CompressionControlQualityFactor  = 3
};

typedef NS_ENUM(NSInteger, LTCodecsJpeg2000ProgressionsOrder) {
    LTCodecsJpeg2000ProgressionsOrderLayerResolutionComponentPosition = 0,
    LTCodecsJpeg2000ProgressionsOrderResolutionLayerComponentPosition = 1,
    LTCodecsJpeg2000ProgressionsOrderResolutionPositionComponentLayer = 2,
    LTCodecsJpeg2000ProgressionsOrderPositionComponentResolutionLayer = 3,
    LTCodecsJpeg2000ProgressionsOrderComponentPositionResolutionLayer = 4
};

typedef NS_ENUM(NSInteger, LTCodecsJpeg2000RegionOfInterest) {
    LTCodecsJpeg2000RegionOfInterestUseLeadRegion        = 0,
    LTCodecsJpeg2000RegionOfInterestUseOptionRectangle   = 1
};

typedef NS_ENUM(NSInteger, LTCodecsJpeg2000PrecinctSize) {
    LTCodecsJpeg2000PrecinctSizeFull                 = 0,
    LTCodecsJpeg2000PrecinctSizeUniform64            = 1,
    LTCodecsJpeg2000PrecinctSizeUniform128           = 2,
    LTCodecsJpeg2000PrecinctSizeUniform256           = 3,
    LTCodecsJpeg2000PrecinctSizeUniform512           = 4,
    LTCodecsJpeg2000PrecinctSizeUniform1024          = 5,
    LTCodecsJpeg2000PrecinctSizeUniform2048          = 6,
    LTCodecsJpeg2000PrecinctSizeHierarchicalOne64    = 7,
    LTCodecsJpeg2000PrecinctSizeHierarchicalOne128   = 8,
    LTCodecsJpeg2000PrecinctSizeHierarchicalOne256   = 9,
    LTCodecsJpeg2000PrecinctSizeHierarchicalOne512   = 10,
    LTCodecsJpeg2000PrecinctSizeHierarchicalTwo64    = 11,
    LTCodecsJpeg2000PrecinctSizeHierarchicalTwo128   = 12,
    LTCodecsJpeg2000PrecinctSizeHierarchicalTwo256   = 13,
    LTCodecsJpeg2000PrecinctSizeHierarchicalTwo512   = 14
};

NS_ASSUME_NONNULL_BEGIN

LEADTOOLS_EXPORT const NSUInteger LTCodecsJpeg2000MaximumComponentsNumber;
LEADTOOLS_EXPORT const NSUInteger LTCodecsJpeg2000MaximumDecompressionLevels;

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpeg2000LoadOptions : NSObject

@property (nonatomic, assign) LeadSize jp2Resolution;
@property (nonatomic, assign) LeadSize j2kResolution;
@property (nonatomic, assign) LeadSize cmwResolution;

- (instancetype)init __unavailable;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpeg2000SaveOptions : NSObject

@property (nonatomic, assign) BOOL useColorTransform;
@property (nonatomic, assign) BOOL derivedQuantization;
@property (nonatomic, assign) BOOL useSopMarker;
@property (nonatomic, assign) BOOL useEphMarker;
@property (nonatomic, assign) BOOL useRegionOfInterest;
@property (nonatomic, assign) BOOL alphaChannelLossless;

@property (nonatomic, assign) NSUInteger targetFileSize;
@property (nonatomic, assign) NSUInteger imageAreaHorizontalOffset;
@property (nonatomic, assign) NSUInteger imageAreaVerticalOffset;
@property (nonatomic, assign) NSUInteger referenceTileWidth;
@property (nonatomic, assign) NSUInteger referenceTileHeight;
@property (nonatomic, assign) NSUInteger tileHorizontalOffset;
@property (nonatomic, assign) NSUInteger tileVerticalOffset;
@property (nonatomic, assign) NSUInteger decompositionLevels;
@property (nonatomic, assign) NSUInteger alphaChannelActiveBits;

@property (nonatomic, assign) LTCodecsJpeg2000CompressionControl compressionControl;
@property (nonatomic, assign) LTCodecsJpeg2000ProgressionsOrder progressingOrder;
@property (nonatomic, assign) LTCodecsJpeg2000RegionOfInterest regionOfInterest;
@property (nonatomic, assign) LTCodecsJpeg2000PrecinctSize precinctSize;

@property (nonatomic, assign) float compressionRatio;
@property (nonatomic, assign) float regionOfInterestWeight;

@property (nonatomic, assign) LeadRect regionOfInterestRectangle;

- (instancetype)init __unavailable;

- (void)getHorizontalSubSamplingValues:(NSUInteger[__nonnull LTCodecsJpeg2000MaximumComponentsNumber])values;
- (void)setHorizontalSubSamplingValues:(const NSUInteger[__nonnull LTCodecsJpeg2000MaximumComponentsNumber])values;
- (void)getVerticalSubSamplingValues:(NSUInteger[__nonnull LTCodecsJpeg2000MaximumComponentsNumber])values;
- (void)setVerticalSubSamplingValues:(const NSUInteger[__nonnull LTCodecsJpeg2000MaximumComponentsNumber])values;

- (void)reset;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsJpeg2000Options : NSObject

@property (nonatomic, strong, readonly) LTCodecsJpeg2000LoadOptions *load;
@property (nonatomic, strong, readonly) LTCodecsJpeg2000SaveOptions *save;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
