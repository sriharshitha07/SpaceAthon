// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTPremultiplyAlphaValuesCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Converts the image data to or from premultiplied alpha values.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTPremultiplyAlphaValuesCommand : LTRasterCommand

@property (nonatomic, assign) BOOL convertToPremultipliedValues;

- (instancetype)initWithConvertToPremultipliedValues:(BOOL)convertToPremultipliedValues NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
