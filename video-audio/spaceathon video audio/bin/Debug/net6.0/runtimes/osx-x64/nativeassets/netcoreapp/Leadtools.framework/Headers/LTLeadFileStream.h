// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLeadFileStream.h
//  Leadtools
//

#import <Leadtools/LTLeadStream.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The LTLeadFileStream class provides an implementation of the LTLeadStream class that operates on a disk file.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadFileStream : LTLeadStream

/** The name of the file associated with this LTLeadFileStream. */
@property (nonatomic, strong, readonly) NSString *fileName;

/**
 @brief Initializes this LTLeadStream instance using the specified file as storage.
 
 @param fileName The path to a file that will be used as storage.
 
 @returns The initialized LTLeadFileStream instance.
 */
- (instancetype)initWithFileName:(NSString *)fileName NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
