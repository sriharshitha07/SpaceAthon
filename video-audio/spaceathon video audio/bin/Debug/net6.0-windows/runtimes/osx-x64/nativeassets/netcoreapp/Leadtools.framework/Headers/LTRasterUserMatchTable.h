// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterUserMatchTable.h
//  Leadtools
//

#import <Leadtools/LTRasterColor.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Maintains a predefined table to speed conversion with a user palette when using @p LTColorResolutionCommand.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterUserMatchTable : NSObject

/** @brief Gets the user match table data. */
@property (nonatomic, strong, readonly, nullable) NSData *data;

/**
 @brief Creates a table that speeds color conversion when using a palette that you create.
 
 @param palette The palette to use when creating the table
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns YES if the table was created successfully, otherwise NO.
 */
- (BOOL)createWithPalette:(NSArray<LTRasterColor *> *)palette error:(NSError **)error;

/** Selects a table that speeds conversion when using a palette that you create. */
- (void)use;

/** Frees the table that is used to speed conversion when using a palette that you create. */
- (void)unuse;

@end

NS_ASSUME_NONNULL_END
