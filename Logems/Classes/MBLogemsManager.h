//
//  MBLogemsManager.h
//  LogemsDemo
//
//  Created by 李龙飞 on 2021/4/6.
//

#import <Foundation/Foundation.h>
#import "logems_appender.h"
NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM(long ,MBLogLevel) {
    MBLogLevelVerbose = 0,
    MBLogLevelDebug = 1, // Detailed information on the flow through the system.
    MBLogLevelInfo = 2, // Interesting runtime events (startup/shutdown), should be conservative and keep to a minimum.
    MBLogLevelWarn = 3, // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    MBLogLevelError = 4, // Other runtime errors or unexpected conditions.
    MBLogLevelFatal = 5, // Severe errors that cause premature termination.
    MBLogLevelNone = -1,
};
@interface MBLogemsManager : NSObject
+ (instancetype)sharedManager;
- (void)clean;
- (void)mb_logems_setLogs:(NSDictionary *)logDic;
- (void)mb_logems_setLogs:(NSDictionary *)logDic logLevel:(MBLogLevel)logLevel;
/**
 *logDic 日志信息
 *logLevel 日志级别
 *className 类名
 *funcName 方法名
 *codeLine 第几行
 */
- (void)mb_logems_setLogs:(NSDictionary *)logDic logLevel:(MBLogLevel)logLevel className:(nullable NSString *)className funcName:(nullable NSString *)funcName codeLine:(int)codeLine;
@end

NS_ASSUME_NONNULL_END
