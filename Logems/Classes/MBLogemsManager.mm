//
//  MBLogemsManager.m
//  LogemsDemo
//
//  Created by 李龙飞 on 2021/4/6.
//

#import "MBLogemsManager.h"
@interface MBLogemsManager ()
{
    LogemsConfig config;
    LogemsAppender *logemsAppender;
}
@end
@implementation MBLogemsManager
static dispatch_once_t onceToken;
static MBLogemsManager *instance = nil;
+ (instancetype)sharedManager {
        dispatch_once(&onceToken, ^{
        instance = [[MBLogemsManager alloc] init];
    });
    return instance;
}
- (instancetype)init {
    self = [super init];
    if (self) {
        NSDictionary *dic = [[NSBundle mainBundle] infoDictionary];//获取info－plist
        NSString *appVersion = [dic valueForKey:@"CFBundleShortVersionString"];
        NSString *basePath = @"test";//[NSString stringWithFormat:@"iOS-%@-%@",appVersion,@"4311072"];
        NSString *directoryPrefix = [NSString stringWithFormat:@"/Logems/%@",basePath];
        NSString *path = [[NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) lastObject] stringByAppendingString:directoryPrefix];
        config = LogemsConfig();
        config.log_dir =path.UTF8String;
        config.compress_mode = kZlib;
        config.is_compress = false;
        config.name_prefix = "test";//basePath.UTF8String;
        config.appender_mode = kAppenderAsync;
        logemsAppender = LogemsAppender::NewInstance(config);
    }
    return self;
}
- (void)clean {
    instance = nil;
    onceToken = 0;
}
- (void)mb_logems_setLogs:(NSDictionary *)logDic {
    [self mb_logems_setLogs:logDic logLevel:MBLogLevelError className:nil funcName:nil codeLine:0];
}
- (void)mb_logems_setLogs:(NSDictionary *)logDic logLevel:(MBLogLevel)logLevel {
    [self mb_logems_setLogs:logDic logLevel:logLevel className:nil funcName:nil codeLine:0];
}
- (void)mb_logems_setLogs:(NSDictionary *)logDic logLevel:(MBLogLevel)logLevel className:(nullable NSString *)className funcName:(nullable NSString *)funcName codeLine:(int)codeLine {
   
    LogInfo* info = new LogInfo();
    info->level = LogLevel::kLevelError;//(LogLevel)logLevel;
    info->func_name = "";// funcName?funcName.UTF8String:
    info->file_name = "";//className?className.UTF8String:
    info->line = codeLine;
    info->tag = "";
    info->process_id = 1;
    info->thread_id = 3;
    info->occur_time = timeval();
    NSString *jsonString = [self jsonStringEncodedWithDic:logDic];
    logemsAppender->Write(info, @"qqqqq".UTF8String);
    logemsAppender->Close();
}
- (NSString *)jsonStringEncodedWithDic:(NSDictionary *)dic {
    if ([NSJSONSerialization isValidJSONObject:dic]) {
        NSError *error;
        NSData *jsonData = [NSJSONSerialization dataWithJSONObject:dic options:0 error:&error];
        NSString *json = [[NSString alloc] initWithData:jsonData encoding:NSUTF8StringEncoding];
        if (!error) return json;
    }
    return nil;
}
@end
