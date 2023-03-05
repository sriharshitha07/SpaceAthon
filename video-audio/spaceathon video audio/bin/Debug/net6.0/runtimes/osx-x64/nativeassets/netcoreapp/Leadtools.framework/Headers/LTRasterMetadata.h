// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterMetadata.h
//  Leadtools
//

/**
 @typedef LTRasterMetadataRational
 
 @brief Encapsulates a rational value, for use with classes derived from LTRasterMetadata.
 */
typedef struct LTRasterMetadataRational {
    int numerator;
    int denominator;
} LTRasterMetadataRational NS_SWIFT_NAME(LTRasterMetadata.Rational);

/**
 @typedef LTRasterMetadataURational
 
 @brief Encapsulates an unsigned rational value, for use with classes derived from LTRasterMetadata.
 */
typedef struct LTRasterMetadataURational {
    unsigned int numerator;
    unsigned int denominator;
} LTRasterMetadataURational NS_SWIFT_NAME(LTRasterMetadata.URational);

/**
 @brief Provides base functionality for dealing with metadata stored in various image file formats.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterMetadata : NSObject <NSCopying, NSSecureCoding>
@end
