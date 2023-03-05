// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterBufferConverter.h
//  Leadtools
//

#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterColor.h>
#import <Leadtools/LTRasterColor16.h>

typedef NS_OPTIONS(NSUInteger, LTRasterConvertBufferFlags) {
    LTRasterConvertBufferFlagNone               = 0x0000,
    LTRasterConvertBufferFlagSourceGray         = 0x0001,
    LTRasterConvertBufferFlagDestinationGray    = 0x0002,
    LTRasterConvertBufferFlagSourceUseBits      = 0x0004,
    LTRasterConvertBufferFlagDestinationUseBits = 0x0008,
    LTRasterConvertBufferFlagUseAlpha           = 0x0010,
    LTRasterConvertBufferFlagAlphaInit          = 0x0020
} NS_SWIFT_NAME(LTRasterBufferConverter.Flags);

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterBufferConverter : NSObject

+ (NSInteger)calculateConvertSize:(NSInteger)inWidth inBitsPerPixel:(NSInteger)inBitsPerPixel outWidth:(NSInteger)outWidth outBitsPerPixel:(NSInteger)outBitsPerPixel NS_SWIFT_NAME(calculateConvertSize(inWidth:inBitsPerPixel:outWidth:outBitsPerPixel:));

+ (BOOL)convert:(void *)buffer offset:(NSInteger)offset width:(NSInteger)width inBitsPerPixel:(NSInteger)inBitsPerPixel outBitsPerPixel:(NSInteger)outBitsPerPixel inOrder:(LTRasterByteOrder)inOrder outOrder:(LTRasterByteOrder)outOrder inPalette:(nullable NSArray<LTRasterColor *> *)inPalette outPalette:(nullable NSArray<LTRasterColor *> *)outPalette alpha:(NSInteger)alpha error:(NSError **)error NS_SWIFT_NAME(convert(buffer:offset:width:inBitsPerPixel:outBitsPerPixel:inOrder:outOrder:inPalette:outPalette:alpha:));

+ (BOOL)convert:(void *)buffer offset:(NSInteger)offset width:(NSInteger)width inBitsPerPixel:(NSInteger)inBitsPerPixel outBitsPerPixel:(NSInteger)outBitsPerPixel inOrder:(LTRasterByteOrder)inOrder outOrder:(LTRasterByteOrder)outOrder inPalette:(nullable NSArray<LTRasterColor *> *)inPalette outPalette:(nullable NSArray<LTRasterColor *> *)outPalette lowBit:(NSInteger)lowBit highBit:(NSInteger)highBit alpha:(NSInteger)alpha flags:(LTRasterConvertBufferFlags)flags error:(NSError **)error NS_SWIFT_NAME(convert(buffer:offset:width:inBitsPerPixel:outBitsPerPixel:inOrder:outOrder:inPalette:outPalette:lowBit:highBit:alpha:flags:));

+ (BOOL)convert:(void *)buffer offset:(NSInteger)offset width:(NSInteger)width inBitsPerPixel:(NSInteger)inBitsPerPixel outBitsPerPixel:(NSInteger)outBitsPerPixel inOrder:(LTRasterByteOrder)inOrder outOrder:(LTRasterByteOrder)outOrder inPalette:(nullable NSArray<LTRasterColor *> *)inPalette outPalette:(nullable NSArray<LTRasterColor *> *)outPalette inPalette16:(nullable NSArray<LTRasterColor16 *> *)inPalette16 outPalette16:(nullable NSArray<LTRasterColor16 *> *)outPalette16 lowBit:(NSInteger)lowBit highBit:(NSInteger)highBit alpha:(NSInteger)alpha flags:(LTRasterConvertBufferFlags)flags error:(NSError **)error NS_SWIFT_NAME(convert(buffer:offset:width:inBitsPerPixel:outBitsPerPixel:inOrder:outOrder:inPalette:outPalette:inPalette16:outPalette16:lowBit:highBit:alpha:flags:));

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
