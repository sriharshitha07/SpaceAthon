// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTRasterImageDataCallbacks.h
//  Leadtools
//

#import <Leadtools/LTRasterDefaults.h>

typedef NS_ENUM(NSInteger, LTCopyRasterImageDataReason) {
    LTCopyRasterImageDataReasonCreateTemp,
    LTCopyRasterImageDataReasonCopy
};

NS_ASSUME_NONNULL_BEGIN

@class LTRasterImageDataCallbacks, LTRasterImage;

/**
 @brief A callback that is used to allocate proxy data for a @p LTRasterImage object.
 
 @param data The allocate data that describes various properties of the image that is being created.
 @param userData Optional user data.
 
 @returns @p LTErrorSuccessAbort to indicate that the proxy data was successfully allocated and should be used (use callbacks), @p LTErrorSuccess to indicate that the @p LTRasterImage should allocate and manage its own data (don't use callbacks), or any other @p LTError value to indicate that an error occurred and to abort the image allocation.
 */
typedef LTErrorCode (^LTRasterImageDataAllocateCallback)(LTRasterImageAllocateData *data, __nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.Allocate);

/**
 @brief A callback that is used to free and proxy data created for a particular @p LTRasterImage object
 
 @param userData Optional user data.
 
 @returns @p LTErrorSuccessAbort to indicate that the proxy data was successfully freed, @p LTErrorSuccess to indicate that the @p LTRasterImage should free its own data, or any other @p LTError value to indicate that an error occurred.
 */
typedef LTErrorCode (^LTRasterImageDataFreeCallback)(__nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.Free);

/**
 @brief A callback that is used to setup a new set of data callbacks to be used for a copy of a @p LTRasterImage object.
 
 @param reason The reason a copy is being created
 @param data The allocate data that describes various properties of the copy that is being created.
 @param callbacks The callbacks that will be used to create the copy of the @p LTRasterImage object.
 @param userData Optional user data.
 
 @returns @p LTErrorSuccess to indicate that the @p callbacks parameter should be used to allocate the new image, @p LTErrorSuccessAbort to indicate that the @p LTRasterImage should allocate and manage its own data, or any other @p LTError value to indicate that an error occurred and to abort the image allocation.
 */
typedef LTErrorCode (^LTRasterImageDataBeginCopyCallback)(LTCopyRasterImageDataReason reason, LTRasterImageAllocateData *data, LTRasterImageDataCallbacks *callbacks, __nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.BeginCopy);

/**
 @brief A callback that is used to indicate that copying has completed.
 
 @discussion If this reason that a copy was created was to create a temporary image, this callback will be called after the temporary image is finished being used, otherwise this callback will be called before the @p LTRasterImageDataAllocateCallback is called on the image copy
 
 @param reason The reason a copy was created
 @param userData Optional user data.
 
 @returns The return value is ignored.
 */
typedef LTErrorCode (^LTRasterImageDataEndCopyCallback)(LTCopyRasterImageDataReason reason, __nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.EndCopy);

/**
 @brief A callback that is used to indicate that the image data is about to be accessed. This is always called before the @p LTRasterImageDataGetRowColumnCallback or @p LTRasterImageDataSetRowColumnCallback callbacks are called.
 
 @param userData Optional user data.
 
 @returns @p LTErrorSuccessAbort to indicate that access is allowed to the image data and that no further preparation is needed, @p LTErrorSuccess to indicate that access is allowed to the image data allocated and managed by the @p LTRasterImage object (used when @p LTRasterImage allocated its own data), or any other @p LTError value to indicate that an error occurred and to abort the image data access.
 */
typedef LTErrorCode (^LTRasterImageDataAccessCallback)(__nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.Access);

/**
 @brief A callback that is used to indicate that the image data finished being accessed.
 
 @param userData Optional user data.
 
 @returns @p LTErrorSuccessAbort to indicate that access was successfully released and that no cleanup is needed, @p LTErrorSuccess to indicate that access was successfully released and that the @p LTRasterImage should perform any necessary cleanup for the data it manages (used when @p LTRasterImage allocated its own data), or any other @p LTError value to indicate that an error occurred.
 */
typedef LTErrorCode (^LTRasterImageDataReleaseCallback)(__nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.Release);

/**
 @brief A callback that is used to retrieve the data for a particular row/column of the image.
 
 @discussion The data that is written into @p buffer should always be in the format of the @p LTRasterImage that is using this callback. For example, if the data that you are managing is in YUV format but the @p LTRasterImage has an image format of BGR, you must first convert the YUV data to BGR before writing it into @p buffer.
 
 @param buffer The buffer to write the image data into
 @param row The row of the image data to retrieve
 @param column The column of the image data to retrieve
 @param bytes The total number of bytes to be copied into the buffer
 @param userData Optional user data.
 
 @returns The number of bytes that were written into @p buffer
 */
typedef uint64_t (^LTRasterImageDataGetRowColumnCallback)(void *buffer, NSInteger row, NSInteger column, uint64_t bytes, __nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.GetRowColumn);

/**
 @brief A callback that is used to write new data to a particular row/column of the image.
 
 @discussion The data that is provided by buffer is always in the format of the @p LTRasterImage that is using this callback. For example, if the data that you are managing is in YUV format but the @p LTRasterImage has an image format of BGR, you will need to convert the BGR data in @p buffer to YUV before writing it into your image data.
 
 @param buffer The buffer containing the new image data
 @param row The row of the image data to write to
 @param column The column of the image data to write to
 @param bytes The total number of bytes contained in buffer
 @param userData Optional user data.
 
 @returns The number of bytes that were copied from @p buffer.
 */
typedef uint64_t (^LTRasterImageDataSetRowColumnCallback)(const void *buffer, NSInteger row, NSInteger column, uint64_t bytes, __nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.SetRowColumn);

/**
 @brief A callback that is used to provide a scratch buffer to the toolkit.
 
 @discussion If the toolkit needs a scratch buffer and this callback isn't provided, the toolkit allocates its own scratch buffer and frees it at the end of whatever function created it. If you are calling multiple functions that use scratch buffers, it may be faster to implement this callback and provide a single scratch buffer that these functions can use to avoid alloc/free performance costs.
 
 @param bytes The total number of bytes that should be allocated for the scratch buffer
 @param userData Optional user data.
 
 @returns The pointer to the scratch buffer
 */
typedef void * __nonnull (^LTRasterImageDataGetScratchBufferCallback)(uint64_t bytes, __nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.GetScratchBuffer);

/**
 @brief A callback that is used to indicate that these callbacks are being deallocated.
 
 @discussion This callback can be used to perform any necessary cleanup work.
 
 @param userData Optional user data.
 */
typedef void (^LTRasterImageDataDestroyCallback)(__nullable id userData) NS_SWIFT_NAME(LTRasterImageDataCallbacks.Destroy);


/// A class that can be used to allow a @p LTRasterImage object to act as a proxy for data that you provide
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTRasterImageDataCallbacks : NSObject

/// A callback that is called whenever a @p LTRasterImage object is being allocated. You should use this callback to create this @p LTRasterImage's data. This callback is expected to be set.
@property (nonatomic, strong, null_unspecified) LTRasterImageDataAllocateCallback allocateCallback;

/// A callback that is called whenever a @p LTRasterImage object is being freed. You should use this callback to free the data that you created in the allocateCallback callback. This callback is expected to be set.
@property (nonatomic, strong, null_unspecified) LTRasterImageDataFreeCallback freeCallback;

/// A callback that is called whenever a copy of a @p LTRasterImage is being created. You can use this callback to copy over or specify new data callbacks. This callback is expected to be set.
@property (nonatomic, strong, null_unspecified) LTRasterImageDataBeginCopyCallback beginCopyCallback;

/// A callback that is called whenever a copy of a @p LTRasterImage has completed. This callback is expected to be set.
@property (nonatomic, strong, null_unspecified) LTRasterImageDataEndCopyCallback endCopyCallback;

/// A callback that is called whenever the data of a @p LTRasterImage is about to be accessed.
@property (nonatomic, strong, nullable)         LTRasterImageDataAccessCallback accessCallback;

/// A callback that is called whenever the data of a @p LTRasterImage is finished being accessed.
@property (nonatomic, strong, nullable)         LTRasterImageDataReleaseCallback releaseCallback;

/// A callback that is called whenever image data is needed from your data source. This callback is expected to be set.
@property (nonatomic, strong, null_unspecified) LTRasterImageDataGetRowColumnCallback getRowColumnCallback;

/// A callback that is called whenever image data is needed to be written into your data source. This callback is expected to be set.
@property (nonatomic, strong, null_unspecified) LTRasterImageDataSetRowColumnCallback setRowColumnCallback;

/// A callback that is called whenever the toolkit needs a scratch buffer for whatever function that is executing. If not specified, the toolkit will allocate and manage its own scratch buffer internally.
@property (nonatomic, strong, nullable)         LTRasterImageDataGetScratchBufferCallback getScratchBufferCallback;

/// A callback this is called whenever the @p LTRasterImageDataCallbacks object is being freed. You can use this callback to perform any necessary cleanup work.
@property (nonatomic, strong, nullable)         LTRasterImageDataDestroyCallback destroyCallback;



/// Optional data that is passed to each of the callbacks.
@property (nonatomic, strong, nullable)         id userData;

/// The @p LTRasterImage object that was initialized using these callbacks, if any.
@property (nonatomic, weak, nullable)           LTRasterImage *rasterImage;


/**
 @returns An initialized instance of a @p LTRasterImageDataCallbacks object.
 */
+ (instancetype)callbacks;

@end

NS_ASSUME_NONNULL_END
