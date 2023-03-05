// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterTagMetadata.h
//  Leadtools
//

#import <Leadtools/LTLeadtools.h>
#import <Leadtools/LTRasterMetadata.h>

typedef NS_ENUM(NSInteger, LTRasterTagMetadataDataType) {
    LTRasterTagMetadataDataTypeByte                       = 1,
    LTRasterTagMetadataDataTypeAscii                      = 2,
    LTRasterTagMetadataDataTypeSByte                      = 6,
    LTRasterTagMetadataDataTypeUndefined                  = 7,
    LTRasterTagMetadataDataTypeUInt16                     = 3,
    LTRasterTagMetadataDataTypeInt16                      = 8,
    LTRasterTagMetadataDataTypeUInt32                     = 4,
    LTRasterTagMetadataDataTypeInt32                      = 9,
    LTRasterTagMetadataDataTypeSingle                     = 11,
    LTRasterTagMetadataDataTypeURational                  = 5,
    LTRasterTagMetadataDataTypeRational                   = 10,
    LTRasterTagMetadataDataTypeDouble                     = 12,
    LTRasterTagMetadataDataTypeImageFileDirectoryOffset   = 13,
    LTRasterTagMetadataDataTypeImageFileDirectoryOffset64 = 18, // BigTiff
    LTRasterTagMetadataDataTypeUInt64                     = 16, // BigTiff
    LTRasterTagMetadataDataTypeInt64                      = 17, // BigTiff
} NS_SWIFT_NAME(LTRasterTagMetadata.DataType);

typedef NSInteger LTRasterMetadataTagID NS_SWIFT_NAME(LTRasterTagMetadata.TagID);

/** @brief A constant which represents the Copyright tag. */
LEADTOOLS_EXPORT const LTRasterMetadataTagID LTRasterTagMetadataCopyright NS_SWIFT_NAME(LTRasterTagMetadata.copyright);

/** @brief A constant which represents the General Exif tag. */
LEADTOOLS_EXPORT const LTRasterMetadataTagID LTRasterTagMetadataGeneralExif NS_SWIFT_NAME(LTRasterTagMetadata.generalExif);

/** @brief A constant which represents the Exif Gps tag. */
LEADTOOLS_EXPORT const LTRasterMetadataTagID LTRasterTagMetadataExifGps NS_SWIFT_NAME(LTRasterTagMetadata.exifGps);

/** @brief A constant which represents the Annotation tag. */
LEADTOOLS_EXPORT const LTRasterMetadataTagID LTRasterTagMetadataAnnotationTiff NS_SWIFT_NAME(LTRasterTagMetadata.annotationTiff);

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Extends the LTRasterMetadata class to provide functionality for dealing with tag metadata stored within various image file formats.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterTagMetadata : LTRasterMetadata <NSCopying, NSSecureCoding>

/** @brief The tag id. */
@property (nonatomic, assign)           LTRasterMetadataTagID tagId;

/** @brief The data type for the tag. */
@property (nonatomic, assign)           LTRasterTagMetadataDataType dataType;

/** @brief The tag data. */
@property (nonatomic, strong)           NSData *data;

/** @brief The size (in bytes) of the tag data. */
@property (nonatomic, assign, readonly) NSUInteger count;


/**
 @brief Initializes a new LTRasterTagMetadata object with the specified values.
 
 @param tagId The tag id.
 @param type The data type of the tag.
 @param data The data for the tag.
 
 @returns A LTRasterTagMetadata object initialized with the specified values.
 */
- (instancetype)initWithId:(LTRasterMetadataTagID)tagId type:(LTRasterTagMetadataDataType)type data:(nullable NSData *)data;


/**
 @brief Gets the size of the specified LTRasterTagMetadataDataType.
 
 @param dataType The LTRasterTagMetadataDataType for whic to get the size.
 
 @returns The size in bytes of the specified LTRasterTagMetadataDataType.
 */
+ (NSUInteger)sizeForDataType:(LTRasterTagMetadataDataType)dataType;
+ (unsigned int)getDataTypeSize:(LTRasterTagMetadataDataType)dataType LT_DEPRECATED_USENEW(19_0, "sizeForDataType:");


/**
 @brief Converts the tag data to an array of bytes.
 
 @param buffer The buffer to store the byte data.
 @param count The size of the buffer. This is the maximum number of bytes that will be copied over.
 */
- (void)toByte:(uint8_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of signed bytes.
 
 @param buffer The buffer to store the byte data.
 @param count The size of the buffer. This is the maximum number of bytes that will be copied over.
 */
- (void)toSByte:(int8_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of unsigned integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toUInt16:(uint16_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toInt16:(int16_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of unsigned integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toUInt32:(uint32_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toInt32:(int32_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of unsigned integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toUInt64:(uint64_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toInt64:(int64_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of unsigned integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toUInteger:(NSUInteger *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of integer values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toInteger:(NSInteger *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of single precision values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toSingle:(float *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of double precision values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toDouble:(double *)buffer itemCount:(NSUInteger)count;


/**
 @brief Sets the tag data to the specified byte values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromByte:(const uint8_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified unsigned byte values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromSByte:(const int8_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified unsigned integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromUInt16:(const uint16_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromInt16:(const int16_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified unsigned integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromUInt32:(const uint32_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromInt32:(const int32_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified unsigned integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromUInt64:(const uint64_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromInt64:(const int64_t *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified unsigned integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromUInteger:(const NSUInteger *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromInteger:(const NSInteger *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified single precision values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromSingle:(const float *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified double precision values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromDouble:(const double *)buffer itemCount:(NSUInteger)count;


/**
 @brief Converts the tag data to a string.
 
 @returns The tag data converted to a string.
 */
- (NSString *)toAscii;

/**
 @brief Sets the tag data to the specified string.
 
 @param value The data to set.
 */
- (void)fromAscii:(NSString *)value;


/**
 @brief Converts the tag data to an array of LTRasterMetadataURational values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toURational:(LTRasterMetadataURational *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of LTRasterMetadataRational values.
 
 @param buffer The buffer to store the values.
 @param count The size of the buffer. This is the maximum number of values that will be copied over.
 */
- (void)toRational:(LTRasterMetadataRational *)buffer itemCount:(NSUInteger)count;


/**
 @brief Sets the tag data to the specified LTRasterMetadataURational values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromURational:(const LTRasterMetadataURational *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified LTRasterMetadataRational values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromRational:(const LTRasterMetadataRational *)buffer itemCount:(NSUInteger)count;

@end

NS_ASSUME_NONNULL_END
