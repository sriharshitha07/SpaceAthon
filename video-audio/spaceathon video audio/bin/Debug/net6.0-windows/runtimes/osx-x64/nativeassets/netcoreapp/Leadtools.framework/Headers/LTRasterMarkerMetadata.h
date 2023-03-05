// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterMarketMetadata.h
//  Leadtools
//

#import <Leadtools/LTLeadtools.h>
#import <Leadtools/LTRasterMetadata.h>

typedef NSInteger LTRasterMetadataMarkerID NS_SWIFT_NAME(LTRasterMarkerMetadata.MarkerID);

/** @brief A constant which represents the SOS marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataSos NS_SWIFT_NAME(LTRasterMarkerMetadata.sos);

/** @brief A constant which represents the APP0 marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataApp0 NS_SWIFT_NAME(LTRasterMarkerMetadata.app0);

/** @brief A constant which represents the APP1 marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataApp1 NS_SWIFT_NAME(LTRasterMarkerMetadata.app1);

/** @brief A constant which represents the APP2 marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataApp2 NS_SWIFT_NAME(LTRasterMarkerMetadata.app2);

/** @brief A constant which represents the COM marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataCom NS_SWIFT_NAME(LTRasterMarkerMetadata.com);

/** @brief A constant which represents the RST0 marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataRst0 NS_SWIFT_NAME(LTRasterMarkerMetadata.rst0);

/** @brief A constant which represents the RST7 marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataRst7 NS_SWIFT_NAME(LTRasterMarkerMetadata.rst7);

/** @brief A constant which represents the SOI marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataSoi NS_SWIFT_NAME(LTRasterMarkerMetadata.soi);

/** @brief A constant which represents the EOI marker */
LEADTOOLS_EXPORT const LTRasterMetadataMarkerID LTRasterMarkerMetadataEoi NS_SWIFT_NAME(LTRasterMarkerMetadata.eoi);

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Extends the LTRasterMetadata class to provide functionality for dealing with marker metadata stored within various image file formats.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterMarkerMetadata : LTRasterMetadata <NSCopying, NSSecureCoding>

/** @brief The marker id. */
@property (nonatomic, assign) LTRasterMetadataMarkerID markerId;

/** @brief The marker data. */
@property (nonatomic, strong) NSData *data;


/**
 @brief Initializes a new LTRasterMarkerMetadata object with the specified values.
 
 @param markerId The marker id.
 @param data The data for the marker.
 
 @returns A LTRasterMarkerMetadata object initialized with the specified values.
 */
- (instancetype)initWithId:(LTRasterMetadataMarkerID)markerId data:(NSData *)data;

@end

NS_ASSUME_NONNULL_END
