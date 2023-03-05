// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCombineFastCommand.h
//  Leadtools
//

#import <Leadtools/LTRasterCommand.h>

typedef NS_OPTIONS(NSUInteger, LTCombineFastCommandFlags) {
    LTCombineFastCommandFlagsNone                          = 0,
    LTCombineFastCommandFlagsSourceNot                     = 0x00000001,
    LTCombineFastCommandFlagsSource0                       = 0x00000002,
    LTCombineFastCommandFlagsSource1                       = 0x00000003,
    LTCombineFastCommandFlagsDestinationNot                = 0x00000010,
    LTCombineFastCommandFlagsDestination0                  = 0x00000020,
    LTCombineFastCommandFlagsDestination1                  = 0x00000030,
    LTCombineFastCommandFlagsOperationOr                   = 0x00000100,
    LTCombineFastCommandFlagsOperationXor                  = 0x00000200,
    LTCombineFastCommandFlagsOperationAdd                  = 0x00000300,
    LTCombineFastCommandFlagsOperationSubtractSource       = 0x00000400,
    LTCombineFastCommandFlagsOperationSubtractDestination  = 0x00000500,
    LTCombineFastCommandFlagsOperationMultiply             = 0x00000600,
    LTCombineFastCommandFlagsOperationDivideSource         = 0x00000700,
    LTCombineFastCommandFlagsOperationDivideDestination    = 0x00000800,
    LTCombineFastCommandFlagsOperationAverage              = 0x00000900,
    LTCombineFastCommandFlagsOperationMinimum              = 0x00000A00,
    LTCombineFastCommandFlagsOperationMaximum              = 0x00000B00,
    LTCombineFastCommandFlagsResultNot                     = 0x00001000,
    LTCombineFastCommandFlagsResult0                       = 0x00002000,
    LTCombineFastCommandFlagsResult1                       = 0x00003000,
    LTCombineFastCommandFlagsSourceCopy                    = LTCombineFastCommandFlagsDestination0 | LTCombineFastCommandFlagsOperationOr
} NS_SWIFT_NAME(LTCombineFastCommand.Flags);

NS_ASSUME_NONNULL_BEGIN

/**
 @brief Combines image data from two images (source and destination), letting you specify the areas to be combined and the operations to be performed when combining the data.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCombineFastCommand : LTRasterCommand

/** @brief The destination image. */
@property (nonatomic, strong, nullable) LTRasterImage *destinationImage;

/** @brief The rectangle in the destination image. */
@property (nonatomic, assign)           LeadRect destinationRectangle;

/** @brief The origin of the source rectangle. */
@property (nonatomic, assign)           LeadPoint sourcePoint;

/** @brief The flags which control the combine command. */
@property (nonatomic, assign)           LTCombineFastCommandFlags flags;


/**
 @brief Initializes a new LTCombineFastCommand with explicit parameters.
 
 @param destinationImage The destination image for the command.
 @param destinationRectangle The rectangle for the destination image.
 @param sourcePoint The origin point for the source rectangle.
 @param flags Flags which control the combine command.
 
 @returns A LTCombineFastCommand object initialized with specific values.
 */
- (instancetype)initWithDestinationImage:(LTRasterImage *)destinationImage destinationRectangle:(LeadRect)destinationRectangle sourcePoint:(LeadPoint)sourcePoint flags:(LTCombineFastCommandFlags)flags NS_DESIGNATED_INITIALIZER;

@end

NS_ASSUME_NONNULL_END
