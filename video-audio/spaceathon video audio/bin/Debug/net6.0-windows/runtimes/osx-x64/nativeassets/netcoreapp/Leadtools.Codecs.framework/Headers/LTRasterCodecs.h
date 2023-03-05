// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterCodecs.h
//  Leadtools.Codecs
//

#import <Leadtools/LTRasterImageFormat.h>
#import <Leadtools/LTLeadtoolsDefines.h>
#import <Leadtools/LTRasterImage.h>
#import <Leadtools/LTLeadStream.h>
#import <Leadtools/LTSvgDocument.h>
#import <Leadtools/LTRasterTagMetadata.h>
#import <Leadtools/LTRasterCommentMetadata.h>
#import <Leadtools/LTRasterMarkerMetadata.h>

#import <Leadtools.Codecs/LTCodecsImageInfo.h>
#import <Leadtools.Codecs/LTCodecsOptions.h>
#import <Leadtools.Codecs/LTCodecsLoadImageEventArgs.h>
#import <Leadtools.Codecs/LTCodecsSaveImageEventArgs.h>
#import <Leadtools.Codecs/LTCodecsLoadInformationEventArgs.h>
#import <Leadtools.Codecs/LTCodecsPageEventArgs.h>
#import <Leadtools.Codecs/LTCodecsEnumTagsEventArgs.h>
#import <Leadtools.Codecs/LTCodecsEnumGeoKeysEventArgs.h>
#import <Leadtools.Codecs/LTCompressDataCallback.h>
#import <Leadtools.Codecs/LTCodecsStartDecompressOptions.h>
#import <Leadtools.Codecs/LTCodecsRasterPdfInfo.h>
#import <Leadtools.Codecs/LTCodecsExtension.h>
#import <Leadtools.Codecs/LTCodecsOverlayData.h>
#import <Leadtools.Codecs/LTCodecsThumbnailOptions.h>
#import <Leadtools.Codecs/LTCodecsTransformMarkerCallback.h>
#import <Leadtools.Codecs/LTCodecsLoadSvgOptions.h>
#import <Leadtools.Codecs/LTCodecsPsdChannelInfo.h>
#import <Leadtools.Codecs/LTCodecsPsdLayerInfo.h>
#import <Leadtools.Codecs/LTCodecsOptimizedLoadData.h>

@class LTRasterCodecs;

typedef NS_ENUM(NSInteger, LTCodecsFeedGetInformationStatus) {
    LTCodecsFeedGetInformationStatusMore,
    LTCodecsFeedGetInformationStatusFinished,
    LTCodecsFeedGetInformationStatusError
};

NS_ASSUME_NONNULL_BEGIN

@protocol LTRasterCodecsDelegate <NSObject>

@optional
- (void)rasterCodecsLoadInformation:(LTRasterCodecs *)codecs args:(LTCodecsLoadInformationEventArgs *)args;
- (void)rasterCodecsLoadPage:(LTRasterCodecs *)codecs args:(LTCodecsPageEventArgs *)args;
- (void)rasterCodecsLoadImage:(LTRasterCodecs *)codecs args:(LTCodecsLoadImageEventArgs *)args;
- (void)rasterCodecsSavePage:(LTRasterCodecs *)codecs args:(LTCodecsPageEventArgs *)args;
- (void)rasterCodecsSaveImage:(LTRasterCodecs *)codecs args:(LTCodecsSaveImageEventArgs *)args;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterCodecs : NSObject

@property (nonatomic, assign)         BOOL fastFileInfo;

@property (nonatomic, assign)         NSUInteger uriOperationBufferSize;

@property (nonatomic, weak, nullable) id<LTRasterCodecsDelegate> delegate;

@property (nonatomic, strong)         LTCodecsOptions *options;

@property (nonatomic, strong)         dispatch_queue_t asyncQueue; // Default is serial
@property (nonatomic, strong)         dispatch_group_t asyncGroup;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (ImageInformation)

- (nullable LTCodecsImageInfo *)imageInformationForFile:(NSString *)file totalPages:(BOOL)totalPages error:(NSError **)error NS_SWIFT_NAME(imageInformation(file:totalPages:));
- (nullable LTCodecsImageInfo *)imageInformationForFile:(NSString *)file totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(imageInformation(file:totalPages:pageNumber:));
- (nullable LTCodecsRasterPdfInfo *)rasterPdfInfoForFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(rasterPdfInfo(file:pageNumber:));

- (nullable LTCodecsImageInfo *)imageInformationForURL:(NSURL *)url totalPages:(BOOL)totalPages error:(NSError **)error NS_SWIFT_NAME(imageInformation(url:totalPages:));
- (nullable LTCodecsImageInfo *)imageInformationForURL:(NSURL *)url totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(imageInformation(url:totalPages:pageNumber:));
- (nullable LTCodecsRasterPdfInfo *)rasterPdfInfoForURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(rasterPdfInfo(url:pageNumber:));

- (nullable LTCodecsImageInfo *)imageInformationForStream:(LTLeadStream *)stream totalPages:(BOOL)totalPages error:(NSError **)error NS_SWIFT_NAME(imageInformation(stream:totalPages:));
- (nullable LTCodecsImageInfo *)imageInformationForStream:(LTLeadStream *)stream totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(imageInformation(stream:totalPages:pageNumber:));
- (nullable LTCodecsRasterPdfInfo *)rasterPdfInfoForStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(rasterPdfInfo(stream:pageNumber:));

- (nullable LTCodecsImageInfo *)imageInformationForData:(NSData *)data totalPages:(BOOL)totalPages error:(NSError **)error NS_SWIFT_NAME(imageInformation(data:totalPages:));
- (nullable LTCodecsImageInfo *)imageInformationForData:(NSData *)data totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(imageInformation(data:totalPages:pageNumber:));
- (nullable LTCodecsRasterPdfInfo *)rasterPdfInfoForData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(rasterPdfInfo(data:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)imageInformationForFile:(NSString *)file totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)imageInformationForFile:(NSString *)file totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)rasterPdfInfoForFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion;

- (void)imageInformationForURL:(NSURL *)url totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)imageInformationForURL:(NSURL *)url totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)rasterPdfInfoForURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion;

- (void)imageInformationForStream:(LTLeadStream *)stream totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)imageInformationForStream:(LTLeadStream *)stream totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)rasterPdfInfoForStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion;

- (void)imageInformationForData:(NSData *)data totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)imageInformationForData:(NSData *)data totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion;
- (void)rasterPdfInfoForData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (LTRasterImageFormat)formatOfFile:(NSString *)file error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(format(of:error:));
- (LTRasterImageFormat)formatOfURL:(NSURL *)url error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(format(of:error:));
- (LTRasterImageFormat)formatOfStream:(LTLeadStream *)stream error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(format(of:error:));
- (LTRasterImageFormat)formatOfData:(NSData *)data error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(format(of:error:));

- (void)formatOfFile:(NSString *)file completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion;
- (void)formatOfURL:(NSURL *)url completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion;
- (void)formatOfStream:(LTLeadStream *)stream completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion;
- (void)formatOfData:(NSData *)data completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForFile:(NSString *)file error:(NSError **)error;
- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForURL:(NSURL *)url error:(NSError **)error;
- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForStream:(LTLeadStream *)stream error:(NSError **)error;
- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForData:(NSData *)data error:(NSError **)error;

- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error;
- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error;
- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error;
- (nullable NSArray<NSValue/*CGSize*/ *> *)loadResolutionsForData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)loadResolutionsForFile:(NSString *)file completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;
- (void)loadResolutionsForURL:(NSURL *)url completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;
- (void)loadResolutionsForStream:(LTLeadStream *)stream completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;
- (void)loadResolutionsForData:(NSData *)data completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;

- (void)loadResolutionsForFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;
- (void)loadResolutionsForURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;
- (void)loadResolutionsForStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;
- (void)loadResolutionsForData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTCodecsExtensionList *)readExtensionsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readExtensions(from:pageNumber:));
- (nullable LTCodecsExtensionList *)readExtensionsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readExtensions(from:pageNumber:));
- (nullable LTCodecsExtensionList *)readExtensionsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readExtensions(from:pageNumber:));
- (nullable LTCodecsExtensionList *)readExtensionsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readExtensions(from:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)readExtensionsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion;
- (void)readExtensionsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion;
- (void)readExtensionsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion;
- (void)readExtensionsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (FeedInformation)

@property (nonatomic, assign, readonly) BOOL isFeedGetInformationDone;

- (BOOL)startFeedGetInformation:(BOOL)totalPages pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(startFeedGetInformation(totalPages:pageNumber:));
- (nullable LTCodecsImageInfo *)stopFeedGetInformation:(NSError **)error;
- (void)cancelFeedGetInformation;

- (LTCodecsFeedGetInformationStatus)feedGetInformation:(const unsigned char *)buffer length:(NSUInteger)length error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(feedGetInformation(buffer:length:error:));
- (LTCodecsFeedGetInformationStatus)feedGetInformationData:(NSData *)data length:(NSUInteger)length error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(feedGetInformation(data:length:error:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Load)

@property (nonatomic, assign, readonly) LTErrorCode loadStatus;

- (nullable LTRasterImage *)loadFile:(NSString *)file error:(NSError **)error NS_SWIFT_NAME(load(file:));
- (nullable LTRasterImage *)loadFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(load(file:pageNumber:));
- (nullable LTRasterImage *)loadFile:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(file:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadFile:(NSString *)file tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(file:tile:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadFile:(NSString *)file width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(file:width:height:bitsPerPixel:flags:order:firstPage:lastPage:));

- (nullable LTRasterImage *)loadURL:(NSURL *)url error:(NSError **)error NS_SWIFT_NAME(load(file:));
- (nullable LTRasterImage *)loadURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(load(file:pageNumber:));
- (nullable LTRasterImage *)loadURL:(NSURL *)url bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(file:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadURL:(NSURL *)url tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(file:tile:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadURL:(NSURL *)url width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(file:width:height:bitsPerPixel:flags:order:firstPage:lastPage:));

- (nullable LTRasterImage *)loadStream:(LTLeadStream *)stream error:(NSError **)error NS_SWIFT_NAME(load(stream:));
- (nullable LTRasterImage *)loadStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(load(stream:pageNumber:));
- (nullable LTRasterImage *)loadStream:(LTLeadStream *)stream bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(stream:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadStream:(LTLeadStream *)stream tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(stream:tile:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadStream:(LTLeadStream *)stream width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(stream:width:height:bitsPerPixel:flags:order:firstPage:lastPage:));

- (nullable LTRasterImage *)loadData:(NSData *)data error:(NSError **)error NS_SWIFT_NAME(load(data:));
- (nullable LTRasterImage *)loadData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(load(data:pageNumber:));
- (nullable LTRasterImage *)loadData:(NSData *)data bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(data:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadData:(NSData *)data tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(data:tile:bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)loadData:(NSData *)data width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(load(data:width:height:bitsPerPixel:flags:order:firstPage:lastPage:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)loadFile:(NSString *)file completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:completion:));
- (void)loadFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:pageNumber:completion:));
- (void)loadFile:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadFile:(NSString *)file tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:tile:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadFile:(NSString *)file width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:));

- (void)loadURL:(NSURL *)url completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:completion:));
- (void)loadURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:pageNumber:completion:));
- (void)loadURL:(NSURL *)url bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadURL:(NSURL *)url tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:tile:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadURL:(NSURL *)url width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(file:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:));

- (void)loadStream:(LTLeadStream *)stream completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(stream:completion:));
- (void)loadStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(stream:pageNumber:completion:));
- (void)loadStream:(LTLeadStream *)stream bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(stream:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadStream:(LTLeadStream *)stream tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(stream:tile:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadStream:(LTLeadStream *)stream width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(stream:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:));

- (void)loadData:(NSData *)data completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(data:completion:));
- (void)loadData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(data:pageNumber:completion:));
- (void)loadData:(NSData *)data bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(data:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadData:(NSData *)data tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(data:tile:bitsPerPixel:order:firstPage:lastPage:completion:));
- (void)loadData:(NSData *)data width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion NS_SWIFT_NAME(load(data:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTRasterImage *)readThumbnailFromFile:(NSString *)file options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readThumbnail(from:options:pageNumber:));
- (nullable LTRasterImage *)readStampFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readStamp(from:pageNumber:));

- (nullable LTRasterImage *)readThumbnailFromURL:(NSURL *)url options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readThumbnail(from:options:pageNumber:));
- (nullable LTRasterImage *)readStampFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readStamp(from:pageNumber:));

- (nullable LTRasterImage *)readThumbnailFromStream:(LTLeadStream *)stream options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readThumbnail(from:options:pageNumber:));
- (nullable LTRasterImage *)readStampFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readStamp(from:pageNumber:));

- (nullable LTRasterImage *)readThumbnailFromData:(NSData *)data options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readThumbnail(from:options:pageNumber:));
- (nullable LTRasterImage *)readStampFromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readStamp(from:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)readThumbnailFromFile:(NSString *)file options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;
- (void)readStampFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;

- (void)readThumbnailFromURL:(NSURL *)url options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;
- (void)readStampFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;

- (void)readThumbnailFromStream:(LTLeadStream *)stream options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;
- (void)readStampFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;

- (void)readThumbnailFromData:(NSData *)data options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;
- (void)readStampFromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (BOOL)isSvgFile:(NSString *)svgFile error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(isSvg(_:error:));
- (BOOL)isSvgURL:(NSURL *)svgURL error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(isSvg(_:error:));
- (BOOL)isSvgData:(NSData *)svgData error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(isSvg(_:error:));
- (BOOL)isSvgStream:(LTLeadStream *)svgStream error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(isSvg(_:error:));

- (BOOL)canLoadSvgFile:(NSString *)svgFile error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(canLoadSvg(_:error:));
- (BOOL)canLoadSvgURL:(NSURL *)svgURL error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(canLoadSvg(_:error:));
- (BOOL)canLoadSvgData:(NSData *)svgData error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(canLoadSvg(_:error:));
- (BOOL)canLoadSvgStream:(LTLeadStream *)svgStream error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(canLoadSvg(_:error:));

- (nullable id<ISvgDocument>)loadSvgFile:(NSString *)file page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options error:(NSError **)error NS_SWIFT_NAME(loadSvg(_:page:options:));
- (nullable id<ISvgDocument>)loadSvgURL:(NSURL *)url page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options error:(NSError **)error NS_SWIFT_NAME(loadSvg(_:page:options:));
- (nullable id<ISvgDocument>)loadSvgData:(NSData *)data page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options error:(NSError **)error NS_SWIFT_NAME(loadSvg(_:page:options:));
- (nullable id<ISvgDocument>)loadSvgStream:(LTLeadStream *)stream page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options error:(NSError **)error NS_SWIFT_NAME(loadSvg(_:page:options:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)isSvgFile:(NSString *)svgFile completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion NS_SWIFT_NAME(isSvg(_:completion:));
- (void)isSvgURL:(NSURL *)svgURL completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion NS_SWIFT_NAME(isSvg(_:completion:));
- (void)isSvgData:(NSData *)svgData completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion NS_SWIFT_NAME(isSvg(_:completion:));
- (void)isSvgStream:(LTLeadStream *)svgStream completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion NS_SWIFT_NAME(isSvg(_:completion:));

- (void)canLoadSvgFile:(NSString *)svgFile completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion NS_SWIFT_NAME(canLoadSvg(_:completion:));
- (void)canLoadSvgURL:(NSURL *)svgURL completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion NS_SWIFT_NAME(canLoadSvg(_:completion:));
- (void)canLoadSvgData:(NSData *)svgData completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion NS_SWIFT_NAME(canLoadSvg(_:completion:));
- (void)canLoadSvgStream:(LTLeadStream *)svgStream completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion NS_SWIFT_NAME(canLoadSvg(_:completion:));

- (void)loadSvgFile:(NSString *)file page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion NS_SWIFT_NAME(loadSvg(_:page:options:completion:));
- (void)loadSvgURL:(NSURL *)url page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion NS_SWIFT_NAME(loadSvg(_:page:options:completion:));
- (void)loadSvgData:(NSData *)data page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion NS_SWIFT_NAME(loadSvg(_:page:options:completion:));
- (void)loadSvgStream:(LTLeadStream *)stream page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion NS_SWIFT_NAME(loadSvg(_:page:options:completion:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
- (void)startOptimizedLoad;
- (void)startOptimizedLoad:(nullable LTCodecsOptimizedLoadData*)data;
- (void)stopOptimizedLoad;
- (LTCodecsOptimizedLoadData*)getOptimizedLoadData;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (FeedLoad)

@property (nonatomic, assign, readonly) BOOL isFeedLoadDone;

- (BOOL)startFeedLoad:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order error:(NSError **)error NS_SWIFT_NAME(startFeedLoad(bitsPerPixel:order:));
- (BOOL)startFeedLoad:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage error:(NSError **)error NS_SWIFT_NAME(startFeedLoad(bitsPerPixel:order:firstPage:lastPage:));
- (nullable LTRasterImage *)stopFeedLoad:(NSError **)error;
- (void)cancelFeedLoad;

- (BOOL)feedLoad:(const unsigned char *)buffer length:(NSUInteger)length error:(NSError **)error NS_SWIFT_NAME(feedLoad(buffer:length:));
- (BOOL)feedLoadData:(NSData *)data length:(NSUInteger)length error:(NSError **)error NS_SWIFT_NAME(feedLoad(data:length:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Save)

- (BOOL)save:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error;
- (BOOL)save:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image file:(NSString *)file error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image file:(NSString *)file firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

// Only file URLs are supported
- (BOOL)save:(LTRasterImage *)image url:(NSURL *)url format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error;
- (BOOL)save:(LTRasterImage *)image url:(NSURL *)url format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image url:(NSURL *)url error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image url:(NSURL *)url firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

- (BOOL)save:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error;
- (BOOL)save:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image stream:(LTLeadStream *)stream error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image stream:(LTLeadStream *)stream firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

- (BOOL)save:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error;
- (BOOL)save:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image data:(NSMutableData *)data error:(NSError **)error;
- (BOOL)saveStamp:(LTRasterImage *)image data:(NSMutableData *)data firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)save:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)save:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image file:(NSString *)file completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image file:(NSString *)file firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;

// Only file URLs are supported
- (void)save:(LTRasterImage *)image url:(NSURL *)url format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)save:(LTRasterImage *)image url:(NSURL *)url format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image url:(NSURL *)url completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image url:(NSURL *)url firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;

- (void)save:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)save:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image stream:(LTLeadStream *)stream completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image stream:(LTLeadStream *)stream firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;

- (void)save:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)save:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image data:(NSMutableData *)data completion:(nullable void (^)(NSError * __nullable error))completion;
- (void)saveStamp:(LTRasterImage *)image data:(NSMutableData *)data firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Pages)

- (NSInteger)totalPagesInFile:(NSString *)file error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(totalPages(in:error:));
- (NSInteger)totalPagesInURL:(NSURL *)url error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(totalPages(in:error:));
- (NSInteger)totalPagesInStream:(LTLeadStream *)stream error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(totalPages(in:error:));
- (NSInteger)totalPagesInData:(NSData *)data error:(NSError **)error NS_SWIFT_NOTHROW NS_SWIFT_NAME(totalPages(in:error:));

- (void)totalPagesInFile:(NSString *)file completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion NS_SWIFT_NAME(totalPages(in:completion:));
- (void)totalPagesInURL:(NSURL *)url completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion NS_SWIFT_NAME(totalPages(in:completion:));
- (void)totalPagesInStream:(LTLeadStream *)stream completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion NS_SWIFT_NAME(totalPages(in:completion:));
- (void)totalPagesInData:(NSData *)data completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion NS_SWIFT_NAME(totalPages(in:completion:));

- (BOOL)deletePageInFile:(NSString *)file page:(NSInteger)page error:(NSError **)error NS_SWIFT_NAME(deletePage(in:page:));
// Only file URLs are supported
- (BOOL)deletePageInURL:(NSURL *)url page:(NSInteger)page error:(NSError **)error NS_SWIFT_NAME(deletePage(in:page:));
- (BOOL)deletePageInStream:(LTLeadStream *)stream page:(NSInteger)page error:(NSError **)error NS_SWIFT_NAME(deletePage(in:page:));
- (BOOL)deletePageInData:(NSData *)data page:(NSInteger)page error:(NSError **)error NS_SWIFT_NAME(deletePage(in:page:));

- (void)deletePageInFile:(NSString *)file page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(deletePage(in:page:completion:));
// Only file URLs are supported
- (void)deletePageInURL:(NSURL *)url page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(deletePage(in:page:completion:));
- (void)deletePageInStream:(LTLeadStream *)stream page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(deletePage(in:page:completion:));
- (void)deletePageInData:(NSData *)data page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(deletePage(in:page:completion:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Convert)

- (BOOL)convertFile:(NSString *)srcFile destinationFile:(NSString *)dstFile format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:));
- (BOOL)convertFile:(NSString *)srcFile destinationFile:(NSString *)dstFile format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:pageNumber:info:));

- (BOOL)convertURL:(NSURL *)srcURL destinationURL:(NSURL *)dstURL format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:)); // 'dstURL' must be a file URL
- (BOOL)convertURL:(NSURL *)srcURL destinationURL:(NSURL *)dstURL format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:pageNumber:info:)); // 'dstURL' must be a file URL

- (BOOL)convertStream:(LTLeadStream *)srcStream destinationStream:(LTLeadStream *)dstStream format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:));
- (BOOL)convertStream:(LTLeadStream *)srcStream destinationStream:(LTLeadStream *)dstStream format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:pageNumber:info:));

- (BOOL)convertData:(NSData *)srcData destinationData:(NSMutableData *)dstData format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:));
- (BOOL)convertData:(NSData *)srcData destinationData:(NSMutableData *)dstData format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info error:(NSError **)error NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:pageNumber:info:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)convertFile:(NSString *)srcFile destinationFile:(NSString *)dstFile format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:));
- (void)convertFile:(NSString *)srcFile destinationFile:(NSString *)dstFile format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:pageNumber:info:));

- (void)convertURL:(NSURL *)srcURL destinationURL:(NSURL *)dstURL format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:)); // 'dstURL' must be a file URL
- (void)convertURL:(NSURL *)srcURL destinationURL:(NSURL *)dstURL format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:pageNumber:info:)); // 'dstURL' must be a file URL

- (void)convertStream:(LTLeadStream *)srcStream destinationStream:(LTLeadStream *)dstStream format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:));
- (void)convertStream:(LTLeadStream *)srcStream destinationStream:(LTLeadStream *)dstStream format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:pageNumber:info:));

- (void)convertData:(NSData *)srcData destinationData:(NSMutableData *)dstData format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:));
- (void)convertData:(NSData *)srcData destinationData:(NSMutableData *)dstData format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber info:(nullable LTCodecsImageInfo *)info completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(convert(source:destination:format:width:height:bitsPerPixel:completion:pageNumber:info:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Compact)

- (BOOL)compactFile:(NSString *)sourceFile destinationFile:(NSString *)destinationFile pages:(NSUInteger)pages error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:));
- (BOOL)compactFile:(NSString *)sourceFile destinationFile:(NSString *)destinationFile pages:(NSUInteger)pages sourceStartPage:(NSInteger)sourceStartPage destinationStartPage:(NSInteger)destinationStartPage useSourceIFD:(BOOL)useSourceIFD sourceIFD:(NSInteger)sourceIFD useDestinationIFD:(BOOL)useDestinationIFD destinationIFD:(NSInteger)destinationIFD pageMode:(LTCodecsSavePageMode)pageMode noSubFileType:(BOOL)noSubFileType motorolaOrder:(BOOL)motorolaOrder bigTiff:(BOOL)bigTiff error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:sourceStartPage:destinationStartPage:useSourceIFD:sourceIFD:useDestinationIFD:destinationIFD:pageMode:noSubFileType:motorolaOrder:bigTiff:));

- (BOOL)compactURL:(NSURL *)sourceURL destinationURL:(NSURL *)destinationURL pages:(NSUInteger)pages error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:)); // 'dstURL' must be a file URL
- (BOOL)compactURL:(NSURL *)sourceURL destinationURL:(NSURL *)destinationURL pages:(NSUInteger)pages sourceStartPage:(NSInteger)sourceStartPage destinationStartPage:(NSInteger)destinationStartPage useSourceIFD:(BOOL)useSourceIFD sourceIFD:(NSInteger)sourceIFD useDestinationIFD:(BOOL)useDestinationIFD destinationIFD:(NSInteger)destinationIFD pageMode:(LTCodecsSavePageMode)pageMode noSubFileType:(BOOL)noSubFileType motorolaOrder:(BOOL)motorolaOrder bigTiff:(BOOL)bigTiff error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:sourceStartPage:destinationStartPage:useSourceIFD:sourceIFD:useDestinationIFD:destinationIFD:pageMode:noSubFileType:motorolaOrder:bigTiff:)); // 'dstURL' must be a file URL

- (BOOL)compactStream:(LTLeadStream *)sourceStream destinationStream:(LTLeadStream *)destinationStream pages:(NSUInteger)pages error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:));
- (BOOL)compactStream:(LTLeadStream *)sourceStream destinationStream:(LTLeadStream *)destinationStream pages:(NSUInteger)pages sourceStartPage:(NSInteger)sourceStartPage destinationStartPage:(NSInteger)destinationStartPage useSourceIFD:(BOOL)useSourceIFD sourceIFD:(NSInteger)sourceIFD useDestinationIFD:(BOOL)useDestinationIFD destinationIFD:(NSInteger)destinationIFD pageMode:(LTCodecsSavePageMode)pageMode noSubFileType:(BOOL)noSubFileType motorolaOrder:(BOOL)motorolaOrder bigTiff:(BOOL)bigTiff error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:sourceStartPage:destinationStartPage:useSourceIFD:sourceIFD:useDestinationIFD:destinationIFD:pageMode:noSubFileType:motorolaOrder:bigTiff:));

- (BOOL)compactData:(NSData *)sourceData destinationData:(NSMutableData *)destinationData pages:(NSUInteger)pages error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:));
- (BOOL)compactData:(NSData *)sourceData destinationData:(NSMutableData *)destinationData pages:(NSUInteger)pages sourceStartPage:(NSInteger)sourceStartPage destinationStartPage:(NSInteger)destinationStartPage useSourceIFD:(BOOL)useSourceIFD sourceIFD:(NSInteger)sourceIFD useDestinationIFD:(BOOL)useDestinationIFD destinationIFD:(NSInteger)destinationIFD pageMode:(LTCodecsSavePageMode)pageMode noSubFileType:(BOOL)noSubFileType motorolaOrder:(BOOL)motorolaOrder bigTiff:(BOOL)bigTiff error:(NSError **)error NS_SWIFT_NAME(compact(source:destination:pages:sourceStartPage:destinationStartPage:useSourceIFD:sourceIFD:useDestinationIFD:destinationIFD:pageMode:noSubFileType:motorolaOrder:bigTiff:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Overlay)

- (BOOL)startOverlay:(nullable LTCodecsOverlayCallback)callback mode:(LTCodecsOverlayCallbackMode)mode error:(NSError **)error;
- (void)stopOverlay;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Metadata)

- (BOOL)enumerateTagsInFile:(NSString *)file pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:));
- (BOOL)enumerateGeoKeysInFile:(NSString *)file pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:));

- (BOOL)enumerateTagsInURL:(NSURL *)url pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:));
- (BOOL)enumerateGeoKeysInURL:(NSURL *)url pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:));

- (BOOL)enumerateTagsInStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:));
- (BOOL)enumerateGeoKeysInStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:));

- (BOOL)enumerateTagsInData:(NSData *)data pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:));
- (BOOL)enumerateGeoKeysInData:(NSData *)data pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler error:(NSError **)error NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)enumerateTagsInFile:(NSString *)file pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:completion:));
- (void)enumerateGeoKeysInFile:(NSString *)file pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:completion:));

- (void)enumerateTagsInURL:(NSURL *)url pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:completion:));
- (void)enumerateGeoKeysInURL:(NSURL *)url pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:completion:));

- (void)enumerateTagsInStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:completion:));
- (void)enumerateGeoKeysInStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:completion:));

- (void)enumerateTagsInData:(NSData *)data pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateTags(in:pageNumber:callback:completion:));
- (void)enumerateGeoKeysInData:(NSData *)data pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(enumerateGeoKeys(in:pageNumber:callback:completion:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTRasterTagMetadata *)readTag:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(tag:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:offsets:));
- (BOOL)writeTag:(nullable LTRasterTagMetadata *)tag toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tag:to:pageNumber:));
- (BOOL)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tags:to:pageNumber:));
- (BOOL)deleteTag:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(tags:from:pageNumber:));

- (nullable LTRasterTagMetadata *)readTag:(NSUInteger)tagId fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(tag:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:offsets:));
- (BOOL)writeTag:(nullable LTRasterTagMetadata *)tag toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tag:to:pageNumber:)); // 'url' must be a file URL
- (BOOL)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tags:to:pageNumber:)); // 'url' must be a file URL
- (BOOL)deleteTag:(NSUInteger)tagId fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(tags:from:pageNumber:)); // 'url' must be a file URL

- (nullable LTRasterTagMetadata *)readTag:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(tag:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:offsets:));
- (BOOL)writeTag:(nullable LTRasterTagMetadata *)tag toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tag:to:pageNumber:));
- (BOOL)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tags:to:pageNumber:));
- (BOOL)deleteTag:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(tags:from:pageNumber:));

- (nullable LTRasterTagMetadata *)readTag:(NSUInteger)tagId fromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(tag:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readTagsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets error:(NSError **)error NS_SWIFT_NAME(readTags(from:pageNumber:offsets:));
- (BOOL)writeTag:(nullable LTRasterTagMetadata *)tag toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tag:to:pageNumber:));
- (BOOL)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(tags:to:pageNumber:));
- (BOOL)deleteTag:(NSUInteger)tagId fromData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(tags:from:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)readTag:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(read(tag:from:pageNumber:completion:));
- (void)readTagsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:completion:));
- (void)readTagsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:offsets:completion:));
- (void)writeTag:(nullable LTRasterTagMetadata *)tag toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tag:to:pageNumber:completion:));
- (void)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tags:to:pageNumber:completion:));
- (void)deleteTag:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(tags:from:pageNumber:completion:));

- (void)readTag:(NSUInteger)tagId fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(read(tag:from:pageNumber:completion:));
- (void)readTagsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:completion:));
- (void)readTagsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:offsets:completion:));
- (void)writeTag:(nullable LTRasterTagMetadata *)tag toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tag:to:pageNumber:completion:)); // 'url' must be a file URL
- (void)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tags:to:pageNumber:completion:)); // 'url' must be a file URL
- (void)deleteTag:(NSUInteger)tagId fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(tags:from:pageNumber:completion:)); // 'url' must be a file URL

- (void)readTag:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(read(tag:from:pageNumber:completion:));
- (void)readTagsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:completion:));
- (void)readTagsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:offsets:completion:));
- (void)writeTag:(nullable LTRasterTagMetadata *)tag toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tag:to:pageNumber:completion:));
- (void)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tags:to:pageNumber:completion:));
- (void)deleteTag:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(tags:from:pageNumber:completion:));

- (void)readTag:(NSUInteger)tagId fromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(read(tag:from:pageNumber:completion:));
- (void)readTagsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:completion:));
- (void)readTagsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion NS_SWIFT_NAME(readTags(from:pageNumber:offsets:completion:));
- (void)writeTag:(nullable LTRasterTagMetadata *)tag toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tag:to:pageNumber:completion:));
- (void)writeTags:(nullable NSArray<LTRasterTagMetadata *> *)tags toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(tags:to:pageNumber:completion:));
- (void)deleteTag:(NSUInteger)tagId fromData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(tags:from:pageNumber:completion:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTRasterTagMetadata *)readGeoKey:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(geoKey:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readGeoKeysFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readGeoKeys(from:pageNumber:));
- (BOOL)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKey:to:pageNumber:));
- (BOOL)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKeys:to:pageNumber:));

- (nullable LTRasterTagMetadata *)readGeoKey:(NSUInteger)tagId fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(geoKey:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readGeoKeysFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readGeoKeys(from:pageNumber:));
- (BOOL)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKey:to:pageNumber:)); // 'url' must be a file URL
- (BOOL)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKeys:to:pageNumber:)); // 'url' must be a file URL

- (nullable LTRasterTagMetadata *)readGeoKey:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(geoKey:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readGeoKeysFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readGeoKeys(from:pageNumber:));
- (BOOL)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKey:to:pageNumber:));
- (BOOL)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKeys:to:pageNumber:));

- (nullable LTRasterTagMetadata *)readGeoKey:(NSUInteger)tagId fromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(read(geoKey:from:pageNumber:));
- (nullable NSArray<LTRasterTagMetadata *> *)readGeoKeysFromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readGeoKeys(from:pageNumber:));
- (BOOL)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKey:to:pageNumber:));
- (BOOL)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(geoKeys:to:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)readGeoKey:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion NS_SWIFT_NAME(read(geoKey:from:pageNumber:completion:));
- (void)readGeoKeysFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion NS_SWIFT_NAME(readGeoKeys(from:pageNumber:completion:));
- (void)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKey:to:pageNumber:completion:));
- (void)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKeys:to:pageNumber:completion:));

- (void)readGeoKey:(NSUInteger)tagId fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion NS_SWIFT_NAME(read(geoKey:from:pageNumber:completion:));
- (void)readGeoKeysFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion NS_SWIFT_NAME(readGeoKeys(from:pageNumber:completion:));
- (void)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKey:to:pageNumber:completion:)); // 'url' must be a file URL
- (void)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKeys:to:pageNumber:completion:)); // 'url' must be a file URL

- (void)readGeoKey:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion NS_SWIFT_NAME(read(geoKey:from:pageNumber:completion:));
- (void)readGeoKeysFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion NS_SWIFT_NAME(readGeoKeys(from:pageNumber:completion:));
- (void)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKey:to:pageNumber:completion:));
- (void)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKeys:to:pageNumber:completion:));

- (void)readGeoKey:(NSUInteger)tagId fromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion NS_SWIFT_NAME(read(geoKey:from:pageNumber:completion:));
- (void)readGeoKeysFromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion NS_SWIFT_NAME(readGeoKeys(from:pageNumber:completion:));
- (void)writeGeoKey:(nullable LTRasterTagMetadata *)geoKey toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKey:to:pageNumber:completion:));
- (void)writeGeoKeys:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(geoKeys:to:pageNumber:completion:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTRasterCommentMetadata *)readCommentFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type error:(NSError **)error NS_SWIFT_NAME(readComment(from:pageNumber:type:));
- (nullable NSArray<LTRasterCommentMetadata *> *)readCommentsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readComments(from:pageNumber:));
- (BOOL)writeComment:(nullable LTRasterCommentMetadata *)comment toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comment:to:pageNumber:));
- (BOOL)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comments:to:pageNumber:));
- (BOOL)deleteComment:(LTRasterCommentMetadataType)comment fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(comment:from:pageNumber:));

- (nullable LTRasterCommentMetadata *)readCommentFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type error:(NSError **)error NS_SWIFT_NAME(readComment(from:pageNumber:type:));
- (nullable NSArray<LTRasterCommentMetadata *> *)readCommentsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readComments(from:pageNumber:));
- (BOOL)writeComment:(nullable LTRasterCommentMetadata *)comment toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comment:to:pageNumber:)); // 'url' must be a file URL
- (BOOL)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comments:to:pageNumber:)); // 'url' must be a file URL
- (BOOL)deleteComment:(LTRasterCommentMetadataType)comment fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(comment:from:pageNumber:)); // 'url' must be a file URL

- (nullable LTRasterCommentMetadata *)readCommentFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type error:(NSError **)error NS_SWIFT_NAME(readComment(from:pageNumber:type:));
- (nullable NSArray<LTRasterCommentMetadata *> *)readCommentsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readComments(from:pageNumber:));
- (BOOL)writeComment:(nullable LTRasterCommentMetadata *)comment toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comment:to:pageNumber:));
- (BOOL)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comments:to:pageNumber:));
- (BOOL)deleteComment:(LTRasterCommentMetadataType)comment fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(comment:from:pageNumber:));

- (nullable LTRasterCommentMetadata *)readCommentFromData:(NSData *)data pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type error:(NSError **)error NS_SWIFT_NAME(readComment(from:pageNumber:type:));
- (nullable NSArray<LTRasterCommentMetadata *> *)readCommentsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(readComments(from:pageNumber:));
- (BOOL)writeComment:(nullable LTRasterCommentMetadata *)comment toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comment:to:pageNumber:));
- (BOOL)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(comments:to:pageNumber:));
- (BOOL)deleteComment:(LTRasterCommentMetadataType)comment fromData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(delete(comment:from:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)readCommentFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion NS_SWIFT_NAME(readComment(from:pageNumber:type:completion:));
- (void)readCommentsFromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion NS_SWIFT_NAME(readComments(from:pageNumber:completion:));
- (void)writeComment:(nullable LTRasterCommentMetadata *)comment toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comment:to:pageNumber:completion:));
- (void)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comments:to:pageNumber:completion:));
- (void)deleteComment:(LTRasterCommentMetadataType)comment fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(comment:from:pageNumber:completion:));

- (void)readCommentFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion NS_SWIFT_NAME(readComment(from:pageNumber:type:completion:));
- (void)readCommentsFromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion NS_SWIFT_NAME(readComments(from:pageNumber:completion:));
- (void)writeComment:(nullable LTRasterCommentMetadata *)comment toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comment:to:pageNumber:completion:)); // 'url' must be a file URL
- (void)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comments:to:pageNumber:completion:)); // 'url' must be a file URL
- (void)deleteComment:(LTRasterCommentMetadataType)comment fromURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(comment:from:pageNumber:completion:)); // 'url' must be a file URL

- (void)readCommentFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion NS_SWIFT_NAME(readComment(from:pageNumber:type:completion:));
- (void)readCommentsFromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion NS_SWIFT_NAME(readComments(from:pageNumber:completion:));
- (void)writeComment:(nullable LTRasterCommentMetadata *)comment toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comment:to:pageNumber:completion:));
- (void)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comments:to:pageNumber:completion:));
- (void)deleteComment:(LTRasterCommentMetadataType)comment fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(comment:from:pageNumber:completion:));

- (void)readCommentFromData:(NSData *)data pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion NS_SWIFT_NAME(readComment(from:pageNumber:type:completion:));
- (void)readCommentsFromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion NS_SWIFT_NAME(readComments(from:pageNumber:completion:));
- (void)writeComment:(nullable LTRasterCommentMetadata *)comment toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comment:to:pageNumber:completion:));
- (void)writeComments:(nullable NSArray<LTRasterCommentMetadata *> *)comments toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(comments:to:pageNumber:completion:));
- (void)deleteComment:(LTRasterCommentMetadataType)comment fromData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(delete(comment:from:pageNumber:completion:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable NSArray<LTRasterMarkerMetadata *> *)readMarkersFromFile:(NSString *)file error:(NSError **)error NS_SWIFT_NAME(readMarkers(from:));
- (BOOL)writeMarker:(nullable LTRasterMarkerMetadata *)marker toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(marker:to:pageNumber:));
- (BOOL)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toFile:(NSString *)file pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(markers:to:pageNumber:));

- (nullable NSArray<LTRasterMarkerMetadata *> *)readMarkersFromURL:(NSURL *)url error:(NSError **)error NS_SWIFT_NAME(readMarkers(from:));
- (BOOL)writeMarker:(nullable LTRasterMarkerMetadata *)marker toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(marker:to:pageNumber:)); // 'url' must be a file URL
- (BOOL)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(markers:to:pageNumber:)); // 'url' must be a file URL

- (nullable NSArray<LTRasterMarkerMetadata *> *)readMarkersFromStream:(LTLeadStream *)stream error:(NSError **)error NS_SWIFT_NAME(readMarkers(from:));
- (BOOL)writeMarker:(nullable LTRasterMarkerMetadata *)marker toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(marker:to:pageNumber:));
- (BOOL)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(markers:to:pageNumber:));

- (nullable NSArray<LTRasterMarkerMetadata *> *)readMarkersFromData:(NSData *)data error:(NSError **)error NS_SWIFT_NAME(readMarkers(from:));
- (BOOL)writeMarker:(nullable LTRasterMarkerMetadata *)marker toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(marker:to:pageNumber:));
- (BOOL)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(write(markers:to:pageNumber:));

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)readMarkersFromFile:(NSString *)file completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion NS_SWIFT_NAME(readMarkers(from:completion:));
- (void)writeMarker:(nullable LTRasterMarkerMetadata *)marker toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(marker:to:pageNumber:completion:));
- (void)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(markers:to:pageNumber:completion:));

- (void)readMarkersFromURL:(NSURL *)url completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion NS_SWIFT_NAME(readMarkers(from:completion:));
- (void)writeMarker:(nullable LTRasterMarkerMetadata *)marker toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(marker:to:pageNumber:completion:)); // 'url' must be a file URL
- (void)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toURL:(NSURL *)url pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(markers:to:pageNumber:completion:)); // 'url' must be a file URL

- (void)readMarkersFromStream:(LTLeadStream *)stream completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion NS_SWIFT_NAME(readMarkers(from:completion:));
- (void)writeMarker:(nullable LTRasterMarkerMetadata *)marker toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(marker:to:pageNumber:completion:));
- (void)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(markers:to:pageNumber:completion:));

- (void)readMarkersFromData:(NSData *)data completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion NS_SWIFT_NAME(readMarkers(from:completion:));
- (void)writeMarker:(nullable LTRasterMarkerMetadata *)marker toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(marker:to:pageNumber:completion:));
- (void)writeMarkers:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion NS_SWIFT_NAME(write(markers:to:pageNumber:completion:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Compression)

- (BOOL)startCompress:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel order:(LTRasterByteOrder)order viewPerspective:(LTRasterViewPerspective)viewPerspective inputDataLength:(NSUInteger)inputDataLength outputData:(unsigned char *)outputData outputDataLength:(NSUInteger)outputDataLength compression:(LTCodecsCompression)compression callback:(nullable LTCodecsCompressDataCallback)callback error:(NSError **)error NS_SWIFT_NAME(startCompress(width:height:bitsPerPixel:order:viewPerspective:inputDataLength:outputData:outputDataLength:compression:callback:));
- (BOOL)compress:(unsigned char *)data error:(NSError **)error;
- (void)stopCompress;

- (nullable id)startDecompress:(LTCodecsStartDecompressOptions *)decompressOptions error:(NSError **)error NS_SWIFT_NAME(startDecompress(options:));
- (BOOL)decompress:(id)decompressContext data:(const unsigned char *)data dataOffset:(NSUInteger)dataOffset dataLength:(size_t)dataLength width:(NSInteger)width height:(NSInteger)height row:(NSInteger)row column:(NSInteger)column flags:(LTCodecsDecompressDataFlags)flags error:(NSError **)error NS_SWIFT_NAME(decompress(context:data:offset:length:width:height:row:column:flags:));
- (nullable LTRasterImage *)stopDecompress:(id)decompressContext error:(NSError **)error NS_SWIFT_NAME(stopDecompress(context:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (PSD)

- (nullable LTRasterImage *)loadPsdLayerFromFile:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order layer:(NSInteger)layer layerInfo:(nullable LTCodecsPsdLayerInfo *)layerInfo error:(NSError **)error NS_SWIFT_NAME(loadPsdLayer(file:bitsPerPixel:order:layer:layerInfo:));
- (nullable LTRasterImage *)loadPsdChannelFromFile:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order channelIndex:(NSInteger)channelIndex channelInfo:(nullable LTCodecsPsdChannelInfo *)channelInfo error:(NSError **)error NS_SWIFT_NAME(loadPsdChannel(file:bitsPerPixel:order:channelIndex:channelInfo:));

- (BOOL)savePsdWithLayers:(LTRasterImage *)layerImages image:(LTRasterImage *)image file:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel layerInfos:(nullable NSArray<LTCodecsPsdLayerInfo *> *)layerInfos error:(NSError **)error;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (CMYK)

- (nullable LTRasterImage *)loadCmykPlanesFromFile:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:));
- (BOOL)saveCmykPlanes:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

- (nullable LTRasterImage *)loadCmykPlanesFromURL:(NSURL *)url bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:));
- (BOOL)saveCmykPlanes:(LTRasterImage *)image url:(NSURL *)url format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error; // 'url' must be a file URL

- (nullable LTRasterImage *)loadCmykPlanesFromStream:(LTLeadStream *)stream bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:));
- (BOOL)saveCmykPlanes:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

- (nullable LTRasterImage *)loadCmykPlanesFromData:(NSData *)data bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber error:(NSError **)error NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:));
- (BOOL)saveCmykPlanes:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode error:(NSError **)error;

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (void)loadCmykPlanesFromFile:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:completion:));
- (void)saveCmykPlanes:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion NS_SWIFT_NAME(saveCmykPlanes(_:file:format:bitsPerPlane:pageNumber:pageMode:completion:));

- (void)loadCmykPlanesFromURL:(NSURL *)url bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:completion:));
- (void)saveCmykPlanes:(LTRasterImage *)image url:(NSURL *)url format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion NS_SWIFT_NAME(saveCmykPlanes(_:file:format:bitsPerPlane:pageNumber:pageMode:completion:)); // 'url' must be a file URL

- (void)loadCmykPlanesFromStream:(LTLeadStream *)stream bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:completion:));
- (void)saveCmykPlanes:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion NS_SWIFT_NAME(saveCmykPlanes(_:stream:format:bitsPerPlane:pageNumber:pageMode:completion:));

- (void)loadCmykPlanesFromData:(NSData *)data bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion NS_SWIFT_NAME(loadCmykPlanes(from:bitsPerPixel:pageNumber:completion:));
- (void)saveCmykPlanes:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion NS_SWIFT_NAME(saveCmykPlanes(_:data:format:bitsPerPlane:pageNumber:pageMode:completion:));

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Support)

+ (NSString *)mimeTypeForFormat:(LTRasterImageFormat)format;
+ (NSString *)extensionForFormat:(LTRasterImageFormat)format;
+ (NSString *)mimeTypeForExtension:(NSString *)extension;
+ (NSString *)extensionForMimeType:(NSString *)mimeType;

+ (BOOL)formatSupportsMultipageSave:(LTRasterImageFormat)format;

+ (BOOL)tagsSupported:(LTRasterImageFormat)format;
+ (BOOL)geoKeysSupported:(LTRasterImageFormat)format;
+ (BOOL)commentsSupported:(LTRasterImageFormat)format;
+ (BOOL)markersSupported:(LTRasterImageFormat)format;

+ (BOOL)isTiff:(LTRasterImageFormat)format;
+ (BOOL)isPdf:(LTRasterImageFormat)format;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

typedef BOOL (^LTRasterCodecsRedirectOpenCallback)(NSString *filename, LTLeadStreamMode mode, LTLeadStreamAccess access, LTLeadStreamShare share);
typedef NSUInteger (^LTRasterCodecsRedirectReadCallback)(void *buffer, NSUInteger count);
typedef NSUInteger (^LTRasterCodecsRedirectWriteCallback)(const void *buffer, NSUInteger count);
typedef NSInteger (^LTRasterCodecsRedirectSeekCallback)(LTLeadSeekOrigin origin, NSInteger offset);
typedef void (^LTRasterCodecsRedirectCloseCallback)(void);

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Redirect)

- (BOOL)startRedirectingWithOpenHandler:(nullable LTRasterCodecsRedirectOpenCallback)openHandler readHandler:(nullable LTRasterCodecsRedirectReadCallback)readHandler writeHandler:(nullable LTRasterCodecsRedirectWriteCallback)writeHandler seekHandler:(nullable LTRasterCodecsRedirectSeekCallback)seekHandler closeHandler:(nullable LTRasterCodecsRedirectCloseCallback)closeHandler error:(NSError **)error;
- (void)stopRedirecting;

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (Deprecated)

- (nullable LTCodecsImageInfo *)getInformation:(LTLeadStream *)stream totalPages:(BOOL)totalPages error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "imageInformationForStream:totalPages:error:");
- (nullable LTCodecsImageInfo *)getInformation:(LTLeadStream *)stream totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "imageInformationForStream:totalPages:pageNumber:error:");
- (nullable LTCodecsRasterPdfInfo *)getRasterPdfInfo:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "rasterPdfInfoForStream:pageNumber:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable NSArray *)readLoadResolutions:(LTLeadStream *)stream error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "loadResolutionsForStream:error:");

- (nullable LTRasterImage *)readThumbnail:(LTLeadStream *)stream options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readThumbnailFromStream:options:pageNumber:error:");
- (nullable LTRasterImage *)readStamp:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readStampFromStream:pageNumber:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (BOOL)convert:(LTLeadStream *)srcStream destStream:(LTLeadStream *)dstStream format:(LTRasterImageFormat)format width:(NSUInteger)width height:(NSUInteger)height bitsPerPixel:(NSUInteger)bitsPerPixel info:(nullable LTCodecsImageInfo *)info error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "convert:destinationStream:format:width:height:bitsPerPixel:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (BOOL)deletePage:(LTLeadStream *)stream page:(NSUInteger)page error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "deletePageInStream:page:error:");

- (NSUInteger)getTotalPages:(LTLeadStream *)stream error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "totalPagesInStream:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable NSArray *)readMarkers:(LTLeadStream*)stream error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readMarkersFromStream:error:");

- (BOOL)enumTags:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "enumerateTagsInStream:pageNumber:callback:error:");
- (BOOL)EnumGeoKeys:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "enumerateGeoKeysInStream:pageNumber:callback:error:");

- (BOOL)deleteTag:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber tagId:(int)tagId error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "deleteTag:fromStream:pageNumber:error:");
- (nullable LTRasterTagMetadata *)readTag:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber tagId:(int)tagId error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readTag:fromStream:pageNumber:error:");
- (nullable NSArray *)readTags:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readTags:fromStream:pageNumber:error:");
- (nullable NSArray *)readTagsWithOffsets:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber offsets:(NSMutableArray *)offsets error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readTags:fromStream:pageNumber:offsets:error:");

- (nullable LTRasterTagMetadata *)readGeoKey:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber tagId:(int)tagId error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readGeoKey:fromStream:pageNumber:error:");
- (nullable NSArray *)readGeoKeys:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readGeoKeysFromStream:pageNumber:error:");

- (BOOL)writeTag:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber tag:(nullable LTRasterTagMetadata *)tag error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeTag:toStream:pageNumber:error:");
- (BOOL)writeTags:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber tags:(nullable NSArray *)tags error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeTags:toStream:pageNumber:error:");

- (BOOL)writeGeoKey:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber geoKey:(nullable LTRasterTagMetadata *)geoKey error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeGeoKey:toStream:pageNumber:error:");
- (BOOL)writeGeoKeys:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber geoKeys:(nullable NSArray *)geoKeys error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeGeoKeys:toStream:pageNumber:error:");

- (nullable LTRasterCommentMetadata *)readComment:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber type:(LTRasterCommentMetadataType)type error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readComment:fromStream:pageNumber:error:");
- (nullable NSArray *)readComments:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readComments:fromStream:pageNumber:error:");

- (BOOL)writeComment:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber comment:(nullable LTRasterCommentMetadata *)comment error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeComment:toStream:pageNumber:error:");
- (BOOL)writeComments:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber comments:(nullable NSArray *)comments error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeComments:toStream:pageNumber:error:");

- (BOOL)writeMarker:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber marker:(nullable LTRasterMarkerMetadata *)marker error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeMarker:toStream:pageNumber:error:");
- (BOOL)writeMarkers:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber markers:(nullable NSArray *)markers error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "writeMarkers:toStream:pageNumber:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTRasterImage *)loadCmykPlanes:(LTLeadStream *)stream bitsPerPixel:(NSUInteger)bitsPerPixel pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "loadCmykPlanesFromStream:bitsPerPixel:pageNumber:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

- (nullable LTCodecsExtensionList *)readExtensions:(LTLeadStream *)stream pageNumber:(NSUInteger)pageNumber error:(NSError **)error LT_DEPRECATED_USENEW(19_0, "readExtensionsFromStream:pageNumber:error:");

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

+ (NSString *)getMimeType:(LTRasterImageFormat)format LT_DEPRECATED_USENEW(19_0, "mimeTypeForFormat:");

@end

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

@interface LTRasterCodecs (AsyncDeprecated)

// All of these have been renamed to reflect common naming conventions for asynchronous methods with completion handlers

- (void)imageInformationForFileAsync:(NSString *)file totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForFile:totalPages:completion:");
- (void)imageInformationForFileAsync:(NSString *)file totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForFile:totalPages:pageNumber:completion:");
- (void)rasterPdfInfoForFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForFile:pageNumber:completion:");

- (void)imageInformationForStreamAsync:(LTLeadStream *)stream totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForStream:totalPages:completion:");
- (void)imageInformationForStreamAsync:(LTLeadStream *)stream totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForStream:totalPages:pageNumber:completion:");
- (void)rasterPdfInfoForStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForStream:pageNumber:completion:");

- (void)imageInformationForDataAsync:(NSData *)data totalPages:(BOOL)totalPages completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForData:totalPages:completion:");
- (void)imageInformationForDataAsync:(NSData *)data totalPages:(BOOL)totalPages pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsImageInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForData:totalPages:pageNumber:completion:");
- (void)rasterPdfInfoForDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsRasterPdfInfo * __nullable info, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "imageInformationForData:pageNumber:completion:");

- (void)formatOfFileAsync:(NSString *)file completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "formatOfFile:completion:");
- (void)formatOfStreamAsync:(LTLeadStream *)stream completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "formatOfStream:completion:");
- (void)formatOfDataAsync:(NSData *)data completion:(void (^)(LTRasterImageFormat format, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "formatOfData:completion:");

- (void)loadResolutionsForFileAsync:(NSString *)file completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadResolutionsForFile:completion:");
- (void)loadResolutionsForStreamAsync:(LTLeadStream *)stream completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadResolutionsForStream:completion:");
- (void)loadResolutionsForDataAsync:(NSData *)data completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadResolutionsForData:completion:");

- (void)loadResolutionsForFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadResolutionsForFile:pageNumber:completion:");
- (void)loadResolutionsForStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadResolutionsForStream:pageNumber:completion:");
- (void)loadResolutionsForDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<NSValue *> * __nullable resolutions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadResolutionsForData:pageNumber:completion:");

- (void)readExtensionsFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readExtensionsFromFile:pageNumber:completion:");
- (void)readExtensionsFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readExtensionsFromStream:pageNumber:completion:");
- (void)readExtensionsFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTCodecsExtensionList * __nullable extensions, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readExtensionsFromData:pageNumber:completion:");

- (void)loadFileAsync:(NSString *)file completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadFile:completion:");
- (void)loadFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadFile:pageNumber:completion:");
- (void)loadFileAsync:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadFile:bitsPerPixel:order:firstPage:lastPage:completion:");
- (void)loadFileAsync:(NSString *)file tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadFile:tile:bitsPerPixel:order:firstPage:lastPage:completion:");
- (void)loadFileAsync:(NSString *)file width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadFile:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:");

- (void)loadStreamAsync:(LTLeadStream *)stream completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadStream:completion:");
- (void)loadStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadStream:pageNumber:completion:");
- (void)loadStreamAsync:(LTLeadStream *)stream bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadStream:bitsPerPixel:order:firstPage:lastPage:completion:");
- (void)loadStreamAsync:(LTLeadStream *)stream tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadStream:tile:bitsPerPixel:order:firstPage:lastPage:completion:");
- (void)loadStreamAsync:(LTLeadStream *)stream width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadStream:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:");

- (void)loadDataAsync:(NSData *)data completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadData:completion:");
- (void)loadDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadData:pageNumber:completion:");
- (void)loadDataAsync:(NSData *)data bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadData:bitsPerPixel:order:firstPage:lastPage:completion:");
- (void)loadDataAsync:(NSData *)data tile:(LeadRect)tile bitsPerPixel:(NSInteger)bitsPerPixel order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadData:tile:bitsPerPixel:order:firstPage:lastPage:completion:");
- (void)loadDataAsync:(NSData *)data width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel flags:(LTRasterSizeFlags)flags order:(LTCodecsLoadByteOrder)order firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadData:width:height:bitsPerPixel:flags:order:firstPage:lastPage:completion:");

- (void)readThumbnailFromFileAsync:(NSString *)file options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readThumbnailFromFile:options:pageNumber:completion:");
- (void)readStampFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readStampFromFile:pageNumber:completion:");

- (void)readThumbnailFromStreamAsync:(LTLeadStream *)stream options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readThumbnailFromStream:options:pageNumber:completion:");
- (void)readStampFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readStampFromStream:pageNumber:completion:");

- (void)readThumbnailFromDataAsync:(NSData *)data options:(LTCodecsThumbnailOptions *)thumbnailOptions pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readThumbnailFromData:options:pageNumber:completion:");
- (void)readStampFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable image, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readStampFromData:pageNumber:completion:");

- (void)isSvgFileAsync:(NSString *)svgFile completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "isSvgFile:completion:");
- (void)isSvgDataAsync:(NSData *)svgData completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "isSvgData:completion:");
- (void)isSvgStreamAsync:(LTLeadStream *)svgStream completion:(void (^)(BOOL isSvg, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "isSvgStream:completion:");

- (void)canLoadSvgFileAsync:(NSString *)svgFile completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "canLoadSvgFile:completion:");
- (void)canLoadSvgDataAsync:(NSData *)svgData completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "canLoadSvgData:completion:");
- (void)canLoadSvgStreamAsync:(LTLeadStream *)svgStream completion:(void (^)(BOOL canLoadSvg, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "canLoadSvgStream:completion:");

- (void)loadSvgFileAsync:(NSString *)file page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadSvgFile:page:options:completion:");
- (void)loadSvgDataAsync:(NSData *)data page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadSvgData:page:options:completion:");
- (void)loadSvgStreamAsync:(LTLeadStream *)stream page:(NSInteger)pageNumber options:(nullable LTCodecsLoadSvgOptions *)options completion:(void (^)(id<ISvgDocument> __nullable svgDocument, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "loadSvgStream:page:options:completion:");

- (void)saveAsync:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "save:file:format:bitsPerPixel:completion:");
- (void)saveAsync:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "save:file:format:bitsPerPixel:firstPage:lastPage:firstSavePageNumber:pageMode:completion:");
- (void)saveStampAsync:(LTRasterImage *)image file:(NSString *)file completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "saveStamp:file:completion:");
- (void)saveStampAsync:(LTRasterImage *)image file:(NSString *)file firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "saveStamp:file:firstPage:lastPage:firstSavePageNumber:pageMode:completion:");

- (void)saveAsync:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "save:stream:format:bitsPerPixel:completion:");
- (void)saveAsync:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "save:stream:format:bitsPerPixel:firstPage:lastPage:firstSavePageNumber:pageMode:completion:");
- (void)saveStampAsync:(LTRasterImage *)image stream:(LTLeadStream *)stream completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "saveStamp:stream:completion:");
- (void)saveStampAsync:(LTRasterImage *)image stream:(LTLeadStream *)stream firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "saveStamp:stream:firstPage:lastPage:firstSavePageNumber:pageMode:completion:");

- (void)saveAsync:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "save:data:format:bitsPerPixel:completion:");
- (void)saveAsync:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPixel:(NSInteger)bitsPerPixel firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "save:data:format:bitsPerPixel:firstPage:lastPage:firstSavePageNumber:pageMode:completion:");
- (void)saveStampAsync:(LTRasterImage *)image data:(NSMutableData *)data completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "saveStamp:data:completion:");
- (void)saveStampAsync:(LTRasterImage *)image data:(NSMutableData *)data firstPage:(NSInteger)firstPage lastPage:(NSInteger)lastPage firstSavePageNumber:(NSInteger)firstSavePageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "saveStamp:data:firstPage:lastPage:firstSavePageNumber:pageMode:completion:");

- (void)totalPagesInFileAsync:(NSString *)file completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "totalPagesInFile:completion:");
- (void)totalPagesInStreamAsync:(LTLeadStream *)stream completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "totalPagesInStream:completion:");
- (void)totalPagesInDataAsync:(NSData *)data completion:(void (^)(NSInteger totalPages, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "totalPagesInData:completion:");

- (void)deletePageInFileAsync:(NSString *)file page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "deletePageInFile:page:completion:");
- (void)deletePageInStreamAsync:(LTLeadStream *)stream page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "deletePageInStream:page:completion:");
- (void)deletePageInDataAsync:(NSData *)data page:(NSInteger)page completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "deletePageInData:page:completion:");

- (void)convertFileAsync:(NSString *)srcFile destinationFile:(NSString *)dstFile format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "convertFile:destinationFile:format:width:height:bitsPerPixel:completion:");
- (void)convertStreamAsync:(LTLeadStream *)srcStream destinationStream:(LTLeadStream *)dstStream format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "convertStream:destinationStream:format:width:height:bitsPerPixel:completion:");
- (void)convertDataAsync:(NSData *)srcData destinationData:(NSMutableData *)dstData format:(LTRasterImageFormat)format width:(NSInteger)width height:(NSInteger)height bitsPerPixel:(NSInteger)bitsPerPixel completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "convertData:destinationData:format:width:height:bitsPerPixel:completion:");

- (void)enumerateTagsInFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "enumerateTagsInFile:pageNumber:callback:completion:");
- (void)enumerateGeoKeysInFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "enumerateGeoKeysInFile:pageNumber:callback:completion:");

- (void)enumerateTagsInStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "enumerateTagsInStream:pageNumber:callback:completion:");
- (void)enumerateGeoKeysInStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "enumerateGeoKeysInStream:pageNumber:callback:completion:");

- (void)enumerateTagsInDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumTagsEventArgs *tagInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "enumerateTagsInData:pageNumber:callback:completion:");
- (void)enumerateGeoKeysInDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber callback:(void (^)(LTCodecsEnumGeoKeysEventArgs *geoKeyInfo))handler completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "enumerateGeoKeysInData:pageNumber:callback:completion:");

- (void)readTagAsync:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTag:fromFile:pageNumber:completion:");
- (void)readTagsFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTagsFromFile:pageNumber:completion:");
- (void)readTagsFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTagsFromFile:pageNumber:offsets:completion:");
- (void)writeTagAsync:(nullable LTRasterTagMetadata *)tag toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeTag:toFile:pageNumber:completion:");
- (void)writeTagsAsync:(nullable NSArray<LTRasterTagMetadata *> *)tags toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeTags:toFile:pageNumber:completion:");
- (void)deleteTagAsync:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "deleteTag:fromFile:pageNumber:completion:");

- (void)readTagAsync:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTag:fromStream:pageNumber:completion:");
- (void)readTagsFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTagsFromStream:pageNumber:completion:");
- (void)readTagsFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTagsFromStream:pageNumber:offsets:completion:");
- (void)writeTagAsync:(nullable LTRasterTagMetadata *)tag toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeTag:toStream:pageNumber:completion:");
- (void)writeTagsAsync:(nullable NSArray<LTRasterTagMetadata *> *)tags toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeTags:toStream:pageNumber:completion:");
- (void)deleteTagAsync:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "deleteTag:fromStream:pageNumber:completion:");

- (void)readTagAsync:(NSUInteger)tagId fromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTag:fromData:pageNumber:completion:");
- (void)readTagsFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTagsFromData:pageNumber:completion:");
- (void)readTagsFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber offsets:(NSMutableArray<NSNumber *> *)offsets completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable tag, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readTagsFromData:pageNumber:offsets:completion:");
- (void)writeTagAsync:(nullable LTRasterTagMetadata *)tag toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeTag:toData:pageNumber:completion:");
- (void)writeTagsAsync:(nullable NSArray<LTRasterTagMetadata *> *)tags toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeTags:toData:pageNumber:completion:");
- (void)deleteTagAsync:(NSUInteger)tagId fromData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "deleteTag:fromData:pageNumber:completion:");

- (void)readGeoKeyAsync:(NSUInteger)tagId fromFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readGeoKey:fromFile:pageNumber:completion:");
- (void)readGeoKeysFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readGeoKeysFromFile:pageNumber:completion:");
- (void)writeGeoKeyAsync:(nullable LTRasterTagMetadata *)geoKey toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeGeoKey:toFile:pageNumber:completion:");
- (void)writeGeoKeysAsync:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeGeoKeys:toFile:pageNumber:completion:");

- (void)readGeoKeyAsync:(NSUInteger)tagId fromStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readGeoKey:fromStream:pageNumber:completion:");
- (void)readGeoKeysFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readGeoKeysFromStream:pageNumber:completion:");
- (void)writeGeoKeyAsync:(nullable LTRasterTagMetadata *)geoKey toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeGeoKey:toStream:pageNumber:completion:");
- (void)writeGeoKeysAsync:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeGeoKeys:toStream:pageNumber:completion:");

- (void)readGeoKeyAsync:(NSUInteger)tagId fromData:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterTagMetadata * __nullable geoKey, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readGeoKey:fromData:pageNumber:completion:");
- (void)readGeoKeysFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterTagMetadata *> * __nullable geoKeys, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readGeoKeysFromData:pageNumber:completion:");
- (void)writeGeoKeyAsync:(nullable LTRasterTagMetadata *)geoKey toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeGeoKey:toData:pageNumber:completion:");
- (void)writeGeoKeysAsync:(nullable NSArray<LTRasterTagMetadata *> *)geoKeys toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeGeoKeys:toData:pageNumber:completion:");

- (void)readCommentFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readCommentFromFile:pageNumber:type:completion:");
- (void)readCommentsFromFileAsync:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readCommentsFromFile:pageNumber:completion:");
- (void)writeCommentAsync:(nullable LTRasterCommentMetadata *)comment toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeComment:toFile:pageNumber:completion:");
- (void)writeCommentsAsync:(nullable NSArray<LTRasterCommentMetadata *> *)comments toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeComments:toFile:pageNumber:completion:");

- (void)readCommentFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readCommentFromStream:pageNumber:type:completion:");
- (void)readCommentsFromStreamAsync:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readCommentsFromStream:pageNumber:completion:");
- (void)writeCommentAsync:(nullable LTRasterCommentMetadata *)comment toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeComment:toStream:pageNumber:completion:");
- (void)writeCommentsAsync:(nullable NSArray<LTRasterCommentMetadata *> *)comments toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeComments:toStream:pageNumber:completion:");

- (void)readCommentFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber type:(LTRasterCommentMetadataType)type completion:(void (^)(LTRasterCommentMetadata * __nullable comment, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readCommentFromData:pageNumber:type:completion:");
- (void)readCommentsFromDataAsync:(NSData *)data pageNumber:(NSInteger)pageNumber completion:(void (^)(NSArray<LTRasterCommentMetadata *> * __nullable comments, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readCommentsFromData:pageNumber:completion:");
- (void)writeCommentAsync:(nullable LTRasterCommentMetadata *)comment toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeComment:toData:pageNumber:completion:");
- (void)writeCommentsAsync:(nullable NSArray<LTRasterCommentMetadata *> *)comments toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeComments:toData:pageNumber:completion:");

- (void)readMarkersFromFileAsync:(NSString *)file completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readMarkersFromFile:completion:");
- (void)writeMarkerAsync:(nullable LTRasterMarkerMetadata *)marker toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeMarker:toFile:pageNumber:completion:");
- (void)writeMarkersAsync:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toFile:(NSString *)file pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeMarkers:toFile:pageNumber:completion:");

- (void)readMarkersFromStreamAsync:(LTLeadStream *)stream completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readMarkersFromStream:completion:");
- (void)writeMarkerAsync:(nullable LTRasterMarkerMetadata *)marker toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeMarker:toStream:pageNumber:completion:");
- (void)writeMarkersAsync:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toStream:(LTLeadStream *)stream pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeMarkers:toStream:pageNumber:completion:");

- (void)readMarkersFromDataAsync:(NSData *)data completion:(void (^)(NSArray<LTRasterMarkerMetadata *> * __nullable, NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "readMarkersFromData:completion:");
- (void)writeMarkerAsync:(nullable LTRasterMarkerMetadata *)marker toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeMarker:toData:pageNumber:completion:");
- (void)writeMarkersAsync:(nullable NSArray<LTRasterMarkerMetadata *> *)markers toData:(NSMutableData *)data pageNumber:(NSInteger)pageNumber completion:(nullable void (^)(NSError * __nullable error))completion LT_DEPRECATED_USENEW(20_0, "writeMarkers:toData:pageNumber:completion:");

- (void)loadCmykPlanesFromFileAsync:(NSString *)file bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion LT_DEPRECATED_USENEW(20_0, "loadCmykPlanesFromFile:bitsPerPixel:pageNumber:completion:");
- (void)saveCmykPlanesAsync:(LTRasterImage *)image file:(NSString *)file format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion LT_DEPRECATED_USENEW(20_0, "saveCmykPlanes:file:format:bitsPerPlane:pageNumber:pageMode:completion:");

- (void)loadCmykPlanesFromStreamAsync:(LTLeadStream *)stream bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion LT_DEPRECATED_USENEW(20_0, "loadCmykPlanesFromStream:bitsPerPixel:pageNumber:completion:");
- (void)saveCmykPlanesAsync:(LTRasterImage *)image stream:(LTLeadStream *)stream format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion LT_DEPRECATED_USENEW(20_0, "saveCmykPlanes:stream:format:bitsPerPlane:pageNumber:pageMode:completion:");

- (void)loadCmykPlanesFromDataAsync:(NSData *)data bitsPerPixel:(NSInteger)bitsPerPixel pageNumber:(NSInteger)pageNumber completion:(void (^)(LTRasterImage * __nullable, NSError * __nullable))completion LT_DEPRECATED_USENEW(20_0, "loadCmykPlanesFromData:bitsPerPixel:pageNumber:completion:");
- (void)saveCmykPlanesAsync:(LTRasterImage *)image data:(NSMutableData *)data format:(LTRasterImageFormat)format bitsPerPlane:(NSInteger)bitsPerPlane pageNumber:(NSInteger)pageNumber pageMode:(LTCodecsSavePageMode)pageMode completion:(nullable void (^)(NSError * __nullable))completion LT_DEPRECATED_USENEW(20_0, "saveCmykPlanes:data:format:bitsPerPlane:pageNumber:pageMode:completion:");

@end

NS_ASSUME_NONNULL_END
