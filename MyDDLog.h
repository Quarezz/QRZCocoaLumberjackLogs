//
//  MyDDLog.h
//  Prom
//
//  Created by Ruslan on 11/25/15.
//  Copyright © 2015 UAProm. All rights reserved.
//

@import CocoaLumberjack;

// We want to use the following log levels:
//
// Fatal
// Error
// Warn
// Notice
// Api
// Storage
// Info
// Debug
//
// All we have to do is undefine the default values,
// and then simply define our own however we want.

// First undefine the default stuff we don't want to use.

#undef LOG_FLAG_ERROR
#undef LOG_FLAG_WARN
#undef LOG_FLAG_INFO
#undef LOG_FLAG_DEBUG
#undef LOG_FLAG_VERBOSE

#undef LOG_LEVEL_ERROR
#undef LOG_LEVEL_WARN
#undef LOG_LEVEL_INFO
#undef LOG_LEVEL_DEBUG
#undef LOG_LEVEL_VERBOSE

#undef LOG_ERROR
#undef LOG_WARN
#undef LOG_INFO
#undef LOG_DEBUG
#undef LOG_VERBOSE

#undef DDLogError
#undef DDLogWarn
#undef DDLogInfo
#undef DDLogDebug
#undef DDLogVerbose

#undef DDLogCError
#undef DDLogCWarn
#undef DDLogCInfo
#undef DDLogCDebug
#undef DDLogCVerbose

// Now define everything how we want it

#define LOG_FLAG_FATAL   (1 << 0)  // 0...000001
#define LOG_FLAG_ERROR   (1 << 1)  // 0...000010
#define LOG_FLAG_WARN    (1 << 2)  // 0...000100
#define LOG_FLAG_INFO    (1 << 3)  // 0...001000
#define LOG_FLAG_STORAGE (1 << 4)  // 0...010000
#define LOG_FLAG_API     (1 << 5)  // 0...100000

#define LOG_LEVEL_FATAL   (LOG_FLAG_FATAL)
#define LOG_LEVEL_ERROR   (LOG_FLAG_ERROR)
#define LOG_LEVEL_WARN    (LOG_FLAG_WARN    | LOG_LEVEL_ERROR)
#define LOG_LEVEL_INFO    (LOG_FLAG_INFO)
#define LOG_LEVEL_STORAGE (LOG_FLAG_STORAGE)
#define LOG_LEVEL_API     (LOG_FLAG_API)

#define LOG_FATAL   (ddLogLevel & LOG_FLAG_FATAL )
#define LOG_ERROR   (ddLogLevel & LOG_FLAG_ERROR )
#define LOG_WARN    (ddLogLevel & LOG_FLAG_WARN  )
#define LOG_INFO    (ddLogLevel & LOG_FLAG_INFO  )
#define LOG_STORAGE (ddLogLevel & LOG_FLAG_STORAGE  )
#define LOG_API     (ddLogLevel & LOG_FLAG_API      )

#define DDLogFatal(frmt, ...)       LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_FATAL, LOG_FLAG_FATAL,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogError(frmt, ...)       LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_ERROR, LOG_FLAG_ERROR,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogWarn(frmt, ...)        LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_WARN, LOG_FLAG_WARN,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogInfo(frmt, ...)        LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_INFO, LOG_FLAG_INFO,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogStorage(frmt, ...)     LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_STORAGE, LOG_FLAG_STORAGE,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)
#define DDLogAPI(frmt, ...)         LOG_MAYBE(LOG_ASYNC_ENABLED, LOG_LEVEL_API, LOG_FLAG_API,    0, nil, __PRETTY_FUNCTION__, frmt, ##__VA_ARGS__)


static const DDLogLevel ddLogLevel = DDLogLevelAll;
