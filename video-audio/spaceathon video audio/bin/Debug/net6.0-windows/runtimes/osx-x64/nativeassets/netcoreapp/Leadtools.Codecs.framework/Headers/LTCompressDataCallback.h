// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCompressDataCallback.h
//  Leadtools.Codecs
//

#import <Leadtools/LTLeadtoolsDefines.h>

typedef NS_ENUM(NSInteger, LTCodecsCompression) {
    LTCodecsCompressionCmp                  = 0,
    LTCodecsCompressionJpeg444              = 1,
    LTCodecsCompressionTifJpeg444           = 2,
    LTCodecsCompressionJpeg411              = 3,
    LTCodecsCompressionTifJpeg411           = 4,
    LTCodecsCompressionJpeg422              = 5,
    LTCodecsCompressionTifJpeg422           = 6,
    LTCodecsCompressionLead0                = 0,
    LTCodecsCompressionLead1                = 1,
    LTCodecsCompressionTiffCcitt            = 3,
    LTCodecsCompressionTiffCcittG3Fax1Dim   = 4,
    LTCodecsCompressionTiffCcittG3Fax2Dim   = 5,
    LTCodecsCompressionTiffCcittG4Fax       = 6,
    LTCodecsCompressionJ2k                  = 7,
    LTCodecsCompressionJp2                  = 8,
};

NS_ASSUME_NONNULL_BEGIN

typedef BOOL (^LTCodecsCompressDataCallback)(NSUInteger width, NSUInteger height, NSUInteger bitsPerPixel, LTRasterByteOrder order, LTRasterViewPerspective viewPerspective, unsigned char *data, NSUInteger dataLength);

NS_ASSUME_NONNULL_END
