// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLeadDataStream.h
//  Leadtools
//

#import <Leadtools/LTLeadStream.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The LTLeadDataStream class provides an implementation of the LTLeadStream class that operates on raw data.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadDataStream : LTLeadStream

/** @brief The data used as storage for this LTLeadDataStream. */
@property (nonatomic, strong, readonly) NSData *data;

/** @brief The range specifying the subset of data used for storage. */
@property (nonatomic, assign, readonly) NSRange dataRange;

/** The name of the file associated with this LTLeadDataStream. */
@property (nonatomic, strong, readonly) NSString *fileName;

/**
 @brief Initializes this LTLeadStream instance using the specified data as storage.
 
 @param data The data that will be used as storage.
 @param range A range that specifies a subset of the data to be used as storage.
 
 @returns The initialized LTLeadDataStream instance.
 */
- (instancetype)initWithData:(NSData *)data dataRange:(NSRange)range NS_DESIGNATED_INITIALIZER;

@end


@interface LTLeadDataStream (Deprecated)

@property (nonatomic, assign, readonly) NSUInteger dataLength LT_DEPRECATED_USENEW(19_0, "dataRange.length");
@property (nonatomic, assign, readonly) NSUInteger offset LT_DEPRECATED_USENEW(19_0, "dataRange.location");

- (nullable instancetype)initWithData:(NSData *)data dataLength:(NSUInteger)length offset:(NSUInteger)offset LT_DEPRECATED_USENEW(19_0, "initWithData:dataRange:");

@end

NS_ASSUME_NONNULL_END
