// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterCommentMetadata.h
//  Leadtools
//

#import <Leadtools/LTLeadtools.h>
#import <Leadtools/LTRasterMetadata.h>

typedef NS_ENUM(NSInteger, LTRasterCommentMetadataDataType) {
    LTRasterCommentMetadataDataTypeAscii,
    LTRasterCommentMetadataDataTypeURational,
    LTRasterCommentMetadataDataTypeRational,
    LTRasterCommentMetadataDataTypeByte,
    LTRasterCommentMetadataDataTypeInt16,
} NS_SWIFT_NAME(LTRasterCommentMetadata.DataType);

typedef NS_ENUM(NSInteger, LTRasterCommentMetadataType) {
    LTRasterCommentMetadataTypeArtist = 0,
    LTRasterCommentMetadataTypeCopyright = 1,
    LTRasterCommentMetadataTypeDateTime = 2,
    LTRasterCommentMetadataTypeDescription = 3,
    LTRasterCommentMetadataTypeHostComputer = 4,
    LTRasterCommentMetadataTypeMake = 5,
    LTRasterCommentMetadataTypeModel = 6,
    LTRasterCommentMetadataTypeNameOfDocument = 7,
    LTRasterCommentMetadataTypeNameOfPage = 8,
    LTRasterCommentMetadataTypeSoftware = 9,
    LTRasterCommentMetadataTypePatientName = 10,
    LTRasterCommentMetadataTypePatientId = 11,
    LTRasterCommentMetadataTypePatientBirthdate = 12,
    LTRasterCommentMetadataTypePatientSex = 13,
    LTRasterCommentMetadataTypeStudyInstance = 14,
    LTRasterCommentMetadataTypeStudyDate = 15,
    LTRasterCommentMetadataTypeStudyTime = 16,
    LTRasterCommentMetadataTypeStudyReferringPhysician = 17,
    LTRasterCommentMetadataTypeSeriesModality = 18,
    LTRasterCommentMetadataTypeSeriesId = 19,
    LTRasterCommentMetadataTypeSeriesNumber = 20,
    LTRasterCommentMetadataTypeExifVersion = 21,
    LTRasterCommentMetadataTypeDateTimeOriginal = 22,
    LTRasterCommentMetadataTypeDateTimeDigitized = 23,
    LTRasterCommentMetadataTypeShutterSpeedValue = 24,
    LTRasterCommentMetadataTypeAperture = 25,
    LTRasterCommentMetadataTypeBrightness = 26,
    LTRasterCommentMetadataTypeExposureBias = 27,
    LTRasterCommentMetadataTypeMaxAperture = 28,
    LTRasterCommentMetadataTypeSubjectDistance = 29,
    LTRasterCommentMetadataTypeMeteringMode = 30,
    LTRasterCommentMetadataTypeLightSource = 31,
    LTRasterCommentMetadataTypeFlash = 32,
    LTRasterCommentMetadataTypeFocalLength = 33,
    LTRasterCommentMetadataTypeExposureTime = 34,
    LTRasterCommentMetadataTypeFNumber = 35,
    LTRasterCommentMetadataTypeMakerNote = 36,
    LTRasterCommentMetadataTypeUserComment = 37,
    LTRasterCommentMetadataTypeSubSecTime = 38,
    LTRasterCommentMetadataTypeSubSecTimeOriginal = 39,
    LTRasterCommentMetadataTypeSubSecTimeDigitized = 40,
    LTRasterCommentMetadataTypeSupportedFlashPixVersion = 158,
    LTRasterCommentMetadataTypeColorSpace = 159,
    LTRasterCommentMetadataTypeExposureProgram = 160,
    LTRasterCommentMetadataTypeSpectralSensitivity = 161,
    LTRasterCommentMetadataTypeIsoSpeedRatings = 162,
    LTRasterCommentMetadataTypeOptoElectricCoefficient = 163,
    LTRasterCommentMetadataTypeRelatedSoundFile = 164,
    LTRasterCommentMetadataTypeFlashEnergy = 165,
    LTRasterCommentMetadataTypeSpatialFrequencyResponse = 166,
    LTRasterCommentMetadataTypeFocalPlaneXResolution = 167,
    LTRasterCommentMetadataTypeFocalPlaneResolutionUnit = 245,
    LTRasterCommentMetadataTypeFocalPlaneYResolution = 168,
    LTRasterCommentMetadataTypeSubjectLocation = 169,
    LTRasterCommentMetadataTypeExposureIndex = 170,
    LTRasterCommentMetadataTypeSensingMethod = 171,
    LTRasterCommentMetadataTypeFileSource = 172,
    LTRasterCommentMetadataTypeSceneType = 173,
    LTRasterCommentMetadataTypeCfaPattern = 174,
    LTRasterCommentMetadataTypeSubjectArea = 227,
    LTRasterCommentMetadataTypeCustomRendered = 228,
    LTRasterCommentMetadataTypeExposureMode = 229,
    LTRasterCommentMetadataTypeWhiteBalance = 230,
    LTRasterCommentMetadataTypeDigitalZoomRatio = 231,
    LTRasterCommentMetadataTypeFocalLengthIn35MMFilm = 232,
    LTRasterCommentMetadataTypeSceneCaptureType = 233,
    LTRasterCommentMetadataTypeGainControl = 234,
    LTRasterCommentMetadataTypeContrast = 235,
    LTRasterCommentMetadataTypeSaturation = 236,
    LTRasterCommentMetadataTypeSharpness = 237,
    LTRasterCommentMetadataTypeDeviceSettingDescription = 238,
    LTRasterCommentMetadataTypeSubjectDistanceRange = 239,
    LTRasterCommentMetadataTypeImageUniqueId = 240,
    LTRasterCommentMetadataTypeGamma = 246,
    LTRasterCommentMetadataTypeOffsetOfDateTime = 247,
    LTRasterCommentMetadataTypeOffsetOfDateTimeOriginal = 248,
    LTRasterCommentMetadataTypeOffsetOfDateTimeDigitized = 249,
    LTRasterCommentMetadataTypeDateTimeSubSeconds = 250,
    LTRasterCommentMetadataTypeDateTimeOriginalSubSeconds = 251,
    LTRasterCommentMetadataTypeDateTimeDigitizedSubSeconds = 252,
    LTRasterCommentMetadataTypeOwnerName = 253,
    LTRasterCommentMetadataTypeBodySerialNumber = 254,
    LTRasterCommentMetadataTypeLensSpecification = 255,
    LTRasterCommentMetadataTypeLensMake = 256,
    LTRasterCommentMetadataTypeLensModel = 257,
    LTRasterCommentMetadataTypeLensSerialNumber = 258,
    LTRasterCommentMetadataTypeCompositeImage = 259,
    LTRasterCommentMetadataTypeSourceImageNumberOfCompositeImage = 260,
    LTRasterCommentMetadataTypeSourceExposureTimesOfCompositeImage = 261,

    LTRasterCommentMetadataTypeGpsVersionId = 41,
    LTRasterCommentMetadataTypeGpsLatitudeRef = 42,
    LTRasterCommentMetadataTypeGpsLatitude = 43,
    LTRasterCommentMetadataTypeGpsLongitudeRef = 44,
    LTRasterCommentMetadataTypeGpsLongitude = 45,
    LTRasterCommentMetadataTypeGpsAltitudeRef = 46,
    LTRasterCommentMetadataTypeGpsAltitude = 47,
    LTRasterCommentMetadataTypeGpsTimestamp = 48,
    LTRasterCommentMetadataTypeGpsSatellites = 49,
    LTRasterCommentMetadataTypeGpsStatus = 50,
    LTRasterCommentMetadataTypeGpsMeasureMode = 51,
    LTRasterCommentMetadataTypeGpsDop = 52,
    LTRasterCommentMetadataTypeGpsSpeedRef = 53,
    LTRasterCommentMetadataTypeGpsSpeed = 54,
    LTRasterCommentMetadataTypeGpsTrackRef = 55,
    LTRasterCommentMetadataTypeGpsTrack = 56,
    LTRasterCommentMetadataTypeGpsImageDirectionRef = 57,
    LTRasterCommentMetadataTypeGpsImageDirection = 58,
    LTRasterCommentMetadataTypeGpsMapDatum = 59,
    LTRasterCommentMetadataTypeGpsDestinationLatitudeRef = 60,
    LTRasterCommentMetadataTypeGpsDestinationLatitude = 61,
    LTRasterCommentMetadataTypeGpsDestinationLongitudeRef = 62,
    LTRasterCommentMetadataTypeGpsDestinationLongitude = 63,
    LTRasterCommentMetadataTypeGpsDestinationBearingRef = 64,
    LTRasterCommentMetadataTypeGpsDestinationBearing = 65,
    LTRasterCommentMetadataTypeGpsDestinationDistanceRef = 66,
    LTRasterCommentMetadataTypeGpsDestinationDistance = 67,
    LTRasterCommentMetadataTypeGpsProcessingMethod = 241,
    LTRasterCommentMetadataTypeGpsAreaInformation = 242,
    LTRasterCommentMetadataTypeGpsDateStamp = 243,
    LTRasterCommentMetadataTypeGpsDifferential = 244,
    LTRasterCommentMetadataTypeTitle = 175,
    LTRasterCommentMetadataTypeDisclaimer = 176,
    LTRasterCommentMetadataTypeWarning = 177,
    LTRasterCommentMetadataTypeMisc = 178,
    LTRasterCommentMetadataTypeJpeg2000Binary = 179,
    LTRasterCommentMetadataTypeJpeg2000Latin = 180,
    LTRasterCommentMetadataTypeIptcFirst = 181,
    LTRasterCommentMetadataTypeIptcVersion = 181,
    LTRasterCommentMetadataTypeIptcObjectTypeReference = 182,
    LTRasterCommentMetadataTypeIptcObjectAttributeReference = 183,
    LTRasterCommentMetadataTypeIptcObjectName = 184,
    LTRasterCommentMetadataTypeIptcEditStatus = 185,
    LTRasterCommentMetadataTypeIptcEditorialUpdate = 186,
    LTRasterCommentMetadataTypeIptcUrgency = 187,
    LTRasterCommentMetadataTypeIptcSubjectReference = 188,
    LTRasterCommentMetadataTypeIptcCategory = 189,
    LTRasterCommentMetadataTypeIptcSupplementalCategory = 190,
    LTRasterCommentMetadataTypeIptcFixtureIdentifier = 191,
    LTRasterCommentMetadataTypeIptcKeywords = 192,
    LTRasterCommentMetadataTypeIptcContentLocationCode = 193,
    LTRasterCommentMetadataTypeIptcContentLocationName = 194,
    LTRasterCommentMetadataTypeIptcReleaseDate = 195,
    LTRasterCommentMetadataTypeIptcReleaseTime = 196,
    LTRasterCommentMetadataTypeIptcExpirationDate = 197,
    LTRasterCommentMetadataTypeIptcExpirationTime = 198,
    LTRasterCommentMetadataTypeIptcSpecialInstructions = 199,
    LTRasterCommentMetadataTypeIptcActionAdvised = 200,
    LTRasterCommentMetadataTypeIptcReferenceService = 201,
    LTRasterCommentMetadataTypeIptcReferenceDate = 202,
    LTRasterCommentMetadataTypeIptcReferenceNumber = 203,
    LTRasterCommentMetadataTypeIptcDateCreated = 204,
    LTRasterCommentMetadataTypeIptcTimeCreated = 205,
    LTRasterCommentMetadataTypeIptcDigitalCreationDate = 206,
    LTRasterCommentMetadataTypeIptcDigitalCreationTime = 207,
    LTRasterCommentMetadataTypeIptcOriginatingProgram = 208,
    LTRasterCommentMetadataTypeIptcProgramVersion = 209,
    LTRasterCommentMetadataTypeIptcObjectCycle = 210,
    LTRasterCommentMetadataTypeIptcByline = 211,
    LTRasterCommentMetadataTypeIptcBylineTitle = 212,
    LTRasterCommentMetadataTypeIptcCity = 213,
    LTRasterCommentMetadataTypeIptcSubLocation = 214,
    LTRasterCommentMetadataTypeIptcProvinceState = 215,
    LTRasterCommentMetadataTypeIptcPrimaryLocationCode = 216,
    LTRasterCommentMetadataTypeIptcPrimaryLocationName = 217,
    LTRasterCommentMetadataTypeIptcOriginalTransmissionReference = 218,
    LTRasterCommentMetadataTypeIptcHeadline = 219,
    LTRasterCommentMetadataTypeIptcCredit = 220,
    LTRasterCommentMetadataTypeIptcSource = 221,
    LTRasterCommentMetadataTypeIptcCopyright = 222,
    LTRasterCommentMetadataTypeIptcContact = 223,
    LTRasterCommentMetadataTypeIptcCaption = 224,
    LTRasterCommentMetadataTypeIptcAuthor = 225,
    LTRasterCommentMetadataTypeIptcLanguageIdentifier = 226,
    LTRasterCommentMetadataTypeIptcLast = 226
} NS_SWIFT_NAME(LTRasterCommentMetadata.Type);

typedef NSInteger LTRasterMetadataCommentType NS_SWIFT_NAME(LTRasterCommentMetadata.CommentType);

/** @brief The separator when a file has two or more IPTC comments. */
LEADTOOLS_EXPORT const LTRasterMetadataCommentType LTRasterCommentMetadataTypeIptcSeparator NS_SWIFT_NAME(LTRasterCommentMetadata.iptcSeparator);

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Extends the LTRasterMetadata class to provide functionality for dealing with comment metadata stored within various image file formats.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterCommentMetadata : LTRasterMetadata <NSCopying, NSSecureCoding>

/** @brief The type of comment. */
@property (nonatomic, assign)           LTRasterCommentMetadataType type;

/** @brief The data for this comment. */
@property (nonatomic, strong)           NSData *data;

/** @brief The data type for this comment. */
@property (nonatomic, assign, readonly) LTRasterCommentMetadataDataType dataType;


/**
 @brief Initializes a new LTRasterCommentMetadata object with the specified values.
 
 @param type The type of comment to create.
 @param data The data for the comment.
 
 @returns A LTRasterCommentMetadata object initialized with the specified values.
 */
- (instancetype)initWithType:(LTRasterCommentMetadataType)type data:(nullable NSData *)data;


/**
 @brief Gets the size of the specified LTRasterTagMetadataDataType.
 
 @param dataType The LTRasterTagMetadataDataType for whic to get the size.
 
 @returns The size in bytes of the specified LTRasterTagMetadataDataType.
 */
+ (NSUInteger)sizeForDataType:(LTRasterCommentMetadataDataType)dataType;
+ (unsigned int)getDataTypeSize:(LTRasterCommentMetadataDataType)dataType LT_DEPRECATED_USENEW(19_0, "sizeForDataType:");

/**
 @brief Gets the LTRasterCommentMetadataDataType of the specified LTRasterCommentMetadataType.
 
 @param type The LTRasterCommentMetadataType for which to get its LTRasterCommentMetadataDataType.
 
 @returns The LTRasterCommentMetadataDataType for the specified LTRasterCommentMetadataType.
 */
+ (LTRasterCommentMetadataDataType)dataTypeForType:(LTRasterCommentMetadataType)type;


/**
 @brief Converts the tag data to an array of bytes.
 
 @param buffer The buffer to store the byte data.
 @param count The size of the buffer. This is the maximum number of bytes that will be copied over.
 */
- (void)toByte:(unsigned char *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of integer values.
 
 @param buffer The buffer to store the byte data.
 @param count The size of the buffer. This is the maximum number of bytes that will be copied over.
 */
- (void)toInt16:(unsigned short *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of LTRasterMetadataURational values.
 
 @param buffer The buffer to store the byte data.
 @param count The size of the buffer. This is the maximum number of bytes that will be copied over.
 */
- (void)toURational:(LTRasterMetadataURational *)buffer itemCount:(NSUInteger)count;

/**
 @brief Converts the tag data to an array of LTRasterMetadataRational values.
 
 @param buffer The buffer to store the byte data.
 @param count The size of the buffer. This is the maximum number of bytes that will be copied over.
 */
- (void)toRational:(LTRasterMetadataRational *)buffer itemCount:(NSUInteger)count;


/**
 @brief Sets the tag data to the specified byte values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromByte:(unsigned char *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified integer values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromInt16:(unsigned short *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified LTRasterMetadataURational values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromURational:(LTRasterMetadataURational *)buffer itemCount:(NSUInteger)count;

/**
 @brief Sets the tag data to the specified LTRasterMetadataRational values.
 
 @param buffer The array of values to set as the tag data.
 @param count The number of values in @p buffer to set as the tag data.
 */
- (void)fromRational:(LTRasterMetadataRational *)buffer itemCount:(NSUInteger)count;



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

@end

NS_ASSUME_NONNULL_END
