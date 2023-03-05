// *************************************************************
// Copyright (c) 1991-2022 LEAD Technologies, Inc.
// All Rights Reserved.
// *************************************************************
//
//  LTLeadStream.h
//  Leadtools
//

#import <Leadtools/LTLeadtools.h>

typedef NS_ENUM(NSInteger, LTLeadStreamMode) {
    LTLeadStreamModeOpen,
    LTLeadStreamModeCreate,
    LTLeadStreamModeTruncate
};

typedef NS_ENUM(NSInteger, LTLeadStreamAccess) {
    LTLeadStreamAccessRead,
    LTLeadStreamAccessWrite,
    LTLeadStreamAccessReadWrite
};

typedef NS_ENUM(NSInteger, LTLeadStreamShare) {
    LTLeadStreamShareNone,
    LTLeadStreamShareRead,
    LTLeadStreamShareWrite,
    LTLeadStreamShareReadWrite
};

typedef NS_ENUM(NSInteger, LTLeadSeekOrigin) {
    LTLeadSeekOriginBegin,
    LTLeadSeekOriginCurrent,
    LTLeadSeekOriginEnd
};

NS_ASSUME_NONNULL_BEGIN

/**
 @brief The LTLeadStream class defines methods similar to the operating system file functions.
 */
NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadStream : NSObject

/** Indicates whether or not this LTLeadStream supports seeking. */
@property (nonatomic, assign, readonly) BOOL canSeek;

/** Indicates whether or not this LTLeadStream supports reading. */
@property (nonatomic, assign, readonly) BOOL canRead;

/** Indicates whether or not this LTLeadStream supports writing. */
@property (nonatomic, assign, readonly) BOOL canWrite;

/** Indicates whether or not this LTLeadStream is started. */
@property (nonatomic, assign, readonly) BOOL isStarted;

/** The name of the file associated with this LTLeadStream. */
@property (nonatomic, strong, readonly) NSString *fileName;

/** The current position of this LTLeadStream, or -1 if seeking is not supported. */
@property (nonatomic, assign, readonly) NSInteger position;



/** 
 @brief Starts this LTLeadStream instance.
 
 @returns YES if the LTLeadStream started correct, otherwise NO.
 */
- (BOOL)start;

/**
 @brief Stops this stream.
 
 @param resetPosition If YES, the position of this LTLeadStream is set the original value.
 */
- (void)stop:(BOOL)resetPosition NS_SWIFT_NAME(stop(resetPosition:));

/**
 @brief Creates, opens, or reopens the specified file.
 
 @param fileName The path for the file that this LTLeadStream will be associated with.
 @param mode A constant that determines how to open or create the file.
 @param access A constant that determines how the files can be accessed by this LTLeadStream object.
 @param share A constant that determines how the file will be shared by processes.
 
 @returns YES if the file was opened, otherwise NO
 */
- (BOOL)openFile:(NSString *)fileName mode:(LTLeadStreamMode)mode access:(LTLeadStreamAccess)access share:(LTLeadStreamShare)share NS_SWIFT_NAME(open(file:mode:access:share:));

/**
 @brief Reads a specified number of bytes from this LTLeadStream and writes the data into the specified buffer.
 
 @param buffer The buffer to write the data into.
 @param count The maximum number of bytes to read.
 
 @returns The total number of bytes read into the buffer.
 */
- (NSUInteger)read:(unsigned char *)buffer count:(NSUInteger)count NS_SWIFT_NAME(read(buffer:count:));

/**
 @brief Writes the specified number of bytes from buffer to this LTLeadStream instance.
 
 @param buffer The buffer containing the data to write to the stream.
 @param count The maximum number of bytes to write.
 
 @returns The total number of bytes written into this LTLeadStream instance.
 */
- (NSUInteger)write:(const unsigned char *)buffer count:(NSUInteger)count NS_SWIFT_NAME(write(buffer:count:));

/**
 @brief Sets the current position of this LTLeadStream instance to the specified value.
 
 @param origin Specifies the beginning, the end, or the current position as a reference point for origin.
 @param offset The pont relative to the origin from which to begin seeking.
 
 @returns The new position in the stream.
 */
- (NSInteger)seek:(LTLeadSeekOrigin)origin offset:(NSUInteger)offset;

/**
 @brief Closes this LTLeadStream instance and releases any resources associated with it.
 */
- (void)closeFile;

@end

NS_CLASS_AVAILABLE(10_10, 8_0)
@interface LTLeadStreamFactory : NSObject

/** @brief The dispatch queue that's used when loading an URL asynchronously */
@property (class, atomic, strong) dispatch_queue_t asyncQueue;

/** @brief The dispatch group that's used when loading an URL asynchronously */
@property (class, atomic, strong) dispatch_group_t asyncGroup;

/**
 @brief Creates a new LTLeadStream instance using the specified file as storage.
 
 @param fileName The path to a file that will be used as storage.
 
 @returns The initialized LTLeadFileStream instance.
 */
+ (LTLeadStream *)streamWithFileName:(NSString *)fileName;

/**
 @brief Creates a new LTLeadStream instance using the specified URL. If the URL is a file URL a file stream will be created for the corresponding file. Otherwise, this method will block, download the data for the specified URL and return a data stream.
 
 @param url The URL to initialize this stream with.
 @param error If an error occurs, upon returns contains an @p NSError object that describes the problem. If you are not interested in possible errors, pass in nil.
 
 @returns The initialized stream upon success, @p nil otherwise.
 */
+ (nullable LTLeadStream *)streamWithURL:(NSURL *)url error:(NSError **)error;

/**
 @brief Creates a new LTLeadStream instance using the specified URL. If the URL is a file URL a file stream will be created for the corresponding file. Otherwise, this method will download the data for the specified URL and create a data stream.
 
 @param url The URL to initialize this stream with.
 @param completion The handler that provides the initialized stream on success, or error upon failure
 */
+ (void)streamWithURL:(NSURL *)url completion:(void (^)(LTLeadStream * __nullable, NSError * __nullable))completion;

/**
 @brief Creates a new LTLeadStream instance using the specified data as storage.
 
 @param data The data that will be used as storage.
 
 @returns The initialized LTLeadDataStream instance.
 */
+ (LTLeadStream *)streamWithData:(NSData *)data;

/**
 @brief Creates a new LTLeadStream instance using the specified data as storage.
 
 @param data The data that will be used as storage.
 @param range A range that specifies a subset of the data to be used as storage.
 
 @returns The initialized LTLeadDataStream instance.
 */
+ (LTLeadStream *)streamWithData:(NSData *)data inRange:(NSRange)range;

@end

@interface LTLeadStreamFactory (Deprecated)

+ (nullable LTLeadStream *)createFromFileName:(NSString *)fileName LT_DEPRECATED_USENEW(19_0, "streamWithFileName:");
+ (nullable LTLeadStream *)createFromData:(NSData *)data LT_DEPRECATED_USENEW(19_0, "streamWithData:");
+ (nullable LTLeadStream *)createFromData:(NSData *)data length:(size_t)length offset:(size_t)offset LT_DEPRECATED_USENEW(19_0, "streamWithData:inRange:");

@end

NS_ASSUME_NONNULL_END
