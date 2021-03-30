//
// Created by bingo on 2021/3/15.
//

#ifndef LOGEMS_LOGEMS_CONFIG_H
#define LOGEMS_LOGEMS_CONFIG_H

#include <string>
#include <ctime>

#define LOGEMS_CACHE_FILE_EXTRA_TYPE "mmap4"

//单个文件最大大小
#define LOGEMS_MAX_FILE_SIZE        10 * 1024 * 1024
//文件最长保存时间
#define LOGEMS_MAX_FILE_ALIVE_TIME  10 * 24 * 60 * 60

//映射文件大小
static const long kBufferBlockLength = 150 * 1024;

enum LogLevel {
    kLevelVerbose = 0,
    kLevelDebug = 1,    // Detailed information on the flow through the system.
    kLevelInfo = 2,     // Interesting runtime events (startup/shutdown), should be conservative and keep to a minimum.
    kLevelWarn = 3,     // Other runtime situations that are undesirable or unexpected, but not necessarily "wrong".
    kLevelError = 4,    // Other runtime errors or unexpected conditions.
    kLevelFatal = 5,    // Severe errors that cause premature termination.
    kLevelNone = -1,     // Special level used to disable all log messages.
};

enum CompressMode {
    kZlib
};

enum AppenderMode {
    kAppenderAsync,
    kAppenderSync,
};

struct LogInfo {
    LogLevel level;
    const char *file_name;
    const char *func_name;
    const char *tag;
    int line;

    struct timeval occur_time;
    intmax_t process_id;
    intmax_t thread_id;
};

struct LogemsConfig {
    AppenderMode appender_mode = kAppenderAsync;
    CompressMode compress_mode = kZlib;
    bool is_compress = false;
    //日志文件前缀
    std::string name_prefix;
    //日志文件存放位置
    std::string log_dir;
    //加密模式下使用的公钥
    std::string pub_key;
    //日志文件本地存放时间，0则不主动清理
    int cache_days = 0;
};

#endif
