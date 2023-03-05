// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTCodecsExcelOptions.h
//  Leadtools.Codecs
//

NS_ASSUME_NONNULL_BEGIN

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsExcelLoadOptions : NSObject

@property (nonatomic, assign) BOOL multiPageSheet;
@property (nonatomic, assign) BOOL disableCellClipping;
@property (nonatomic, assign) BOOL showHiddenSheet;
@property (nonatomic, assign) BOOL multiPageUseSheetWidth;
@property (nonatomic, assign) BOOL pageOrderDownTheOver;
@property (nonatomic, assign) BOOL multiPageEnableMargins;

- (instancetype)init __unavailable;

@end



NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTCodecsExcelOptions : NSObject

@property (nonatomic, strong, readonly) LTCodecsExcelLoadOptions *load;

- (instancetype)init __unavailable;

@end

NS_ASSUME_NONNULL_END
