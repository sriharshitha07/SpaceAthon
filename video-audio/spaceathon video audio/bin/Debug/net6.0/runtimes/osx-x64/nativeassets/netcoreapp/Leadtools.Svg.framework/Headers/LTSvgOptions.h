// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTSvgOptions.h
//  Leadtools.Svg
//

#import <Leadtools/LTPrimitives.h>
#import <Leadtools/LTRasterColor.h>

#import <Leadtools.Svg/LTEnums.h>

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgLoadOptions : NSObject

@property (nonatomic, assign) LTSvgLoadFlags loadFlags;

@property (nonatomic, assign) NSUInteger maximumElements;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgSaveOptions : NSObject

@property (nonatomic, assign) BOOL formatted;

@property (nonatomic, assign) LTSvgEncoding encoding;
@property (nonatomic, assign) LTSvgFormat format;

@property (nonatomic, copy)   NSString *indent;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgFlatOptions : NSObject

@property (nonatomic, assign) LeadSizeD size;

@property (nonatomic, assign) BOOL textOnly;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgRenderOptions : NSObject

@property (nonatomic, assign) BOOL useBackgroundColor;

@property (nonatomic, copy)   LTRasterColor *backgroundColor;

@property (nonatomic, assign) LeadRectD bounds;
@property (nonatomic, assign) LeadRectD clipBounds;
@property (nonatomic, assign) LeadMatrix transform;

@end



@class LTSvgDocument, LTSvgNodeHandle;
typedef BOOL (^LTSvgFilterElementsCallback)(LTSvgDocument *document, LTSvgNodeHandle *node, id userData);

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgSortOptions : NSObject

@property (nonatomic, assign) LTSvgSortFlags sortFlags;
@property (nonatomic, assign) LTSvgExtractText extractText;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgMergeOptions : NSObject

@property (nonatomic, assign) LTSvgDropFlags destinationDropFlags;
@property (nonatomic, assign) LTSvgDropFlags sourceDropFlags;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgEnumerateOptions : NSObject

@property (nonatomic, assign) LTSvgEnumerateDirection enumerateDirection;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTSvgRedactOptions : NSObject

@property (nonatomic, copy) LTRasterColor *fillColor;

@property (nonatomic, strong) NSArray<NSValue *> *rectangles; //LeadRectD
@property (nonatomic, assign) char replaceChar;
@property (nonatomic, assign) NSInteger intersectionPercentage;

@end

NS_ASSUME_NONNULL_END
