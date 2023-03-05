// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSvgDocument.h
//  Leadtools.Svg
//

#import <Leadtools/LTSvgDocument.h>
#import <Leadtools/LTLeadStream.h>
#import <Leadtools/LTRasterImage.h>

#import <Leadtools.Svg/LTSvgOptions.h>
#import <Leadtools.Svg/LTSvgElementInfo.h>
#import <Leadtools.Svg/LTSvgNodeHandle.h>
#import <Leadtools.Svg/LTSvgBounds.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgDocument : NSObject <ISvgDocument, NSCopying, NSCoding>

@property (nonatomic, assign, getter=isFlat) BOOL flat;

@property (nonatomic, assign)                LTSvgVersion version;

@property (nonatomic, assign, readonly)      BOOL isRenderOptimized;

- (nullable instancetype)initWithFile:(NSString *)file options:(nullable LTSvgLoadOptions *)options error:(NSError **)error;
- (nullable instancetype)initWithData:(NSData *)data options:(nullable LTSvgLoadOptions *)options error:(NSError **)error;
- (nullable instancetype)initWithStream:(LTLeadStream *)stream options:(nullable LTSvgLoadOptions *)options error:(NSError **)error;
- (instancetype)init __unavailable;

- (BOOL)saveToFile:(NSString *)file options:(nullable LTSvgSaveOptions *)options error:(NSError **)error NS_SWIFT_NAME(save(to:options:));
- (BOOL)saveToData:(NSMutableData *)data options:(nullable LTSvgSaveOptions *)options error:(NSError **)error NS_SWIFT_NAME(save(to:options:));
- (BOOL)saveToStream:(LTLeadStream *)stream options:(nullable LTSvgSaveOptions *)options error:(NSError **)error NS_SWIFT_NAME(save(to:options:));



- (BOOL)flattenWithOptions:(nullable LTSvgFlatOptions *)options error:(NSError **)error NS_SWIFT_NAME(flatten(options:));
- (nullable instancetype)flatCopyWithOptions:(nullable LTSvgFlatOptions *)options error:(NSError **)error NS_SWIFT_NAME(flatCopy(options:));

- (BOOL)applyViewPerspective:(LTRasterViewPerspective)viewPerspective apply:(BOOL)apply error:(NSError **)error NS_SWIFT_NAME(applyViewPerspective(_:apply:));



- (BOOL)resize:(double)scaleFactor error:(NSError **)error NS_SWIFT_NAME(resize(scaleFactor:));

- (BOOL)addElementIDs:(NSError **)error;
- (BOOL)calculateBounds:(BOOL)trimmed error:(NSError **)error NS_SWIFT_NAME(calculateBounds(trimmed:));

- (nullable LTSvgBounds *)bounds:(NSError **)error;
- (BOOL)setBounds:(LTSvgBounds *)bounds error:(NSError **)error;



- (void)beginUpdate;
- (void)endUpdate;

- (BOOL)beginRenderOptimize:(NSError **)error;
- (BOOL)endRenderOptimize:(NSError **)error;



- (BOOL)rasterizeToImage:(LTRasterImage *)image options:(nullable LTSvgRenderOptions *)options error:(NSError **)error;

- (BOOL)sortElementsWithOptions:(nullable LTSvgSortOptions *)options userData:(nullable id)userData callback:(BOOL (^)(LTSvgDocument *document, LTSvgElementInfo *info, id _Nullable userData))callback error:(NSError **)error NS_SWIFT_NAME(sortElements(options:userData:callback:));
- (BOOL)enumerateElementsWithOptions:(nullable LTSvgEnumerateOptions *)options userData:(nullable id)userData callback:(BOOL (^)(LTSvgDocument *document, LTSvgNodeHandle *node, id _Nullable userData))callback error:(NSError **)error NS_SWIFT_NAME(enumerateElements(options:userData:callback:));
- (BOOL)setFilterElementsUserData:(nullable id)userData callback:(nullable LTSvgFilterElementsCallback)callback error:(NSError **)error;

- (BOOL)optimizeView:(NSError **)error;

- (BOOL)hasElement:(LTSvgElementType)elementType;

- (BOOL)mergeWithDocument:(LTSvgDocument *)document options:(nullable LTSvgMergeOptions *)options error:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
