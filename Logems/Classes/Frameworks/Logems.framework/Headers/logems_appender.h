//
// Created by bingo on 2021/3/15.
//

#ifndef LOGEMS_LOGEMS_APPENDER_H
#define LOGEMS_LOGEMS_APPENDER_H

#include "logems_config.h"
#include "logems_base_buffer.h"
#include <thread>
#include <mutex>
#include <condition_variable>

class LogemsAppender {
public:
    static LogemsAppender* NewInstance(const LogemsConfig &_config);

    static void HandlerError(int _signal);

    static void AppenderSetConsoleLog(bool _is_open);

public:

    void DeleteTimeOutLogs(std::string& _dir_path) const;

    ~LogemsAppender();

    void Write(const LogInfo* _log_info, const char* _log);

    void Close();

private:
    explicit LogemsAppender(const LogemsConfig& _config);

    void Open(const LogemsConfig &_config);

    void AsyncLog();

    void Log2File(const void* _data, size_t _length);

    void CloseLogFile();

    bool OpenLogFile(std::string& _log_dir);

    void WriteAsync(const LogInfo* _log_info, const char* _log);

    void WriteSync(const LogInfo* _log_info, const char* _log);

    static bool WriteFile(FILE* _file, const void* _data, size_t _length);

    static std::string MakeLogFilePrefix(const timeval& _tv, const std::string& _prefix);

    void MakeLogFileName(const timeval& _tv, const std::string& _log_dir, const char* _prefix, const std::string& _file_ext, char* _file_path, unsigned int _len);

    long GetNextFileIndex(const std::string& _log_file_prefix, const std::string& _log_file_ext) const;
private:
    LogemsConfig config_;
    LogemsBaseBuffer* log_buffer_{};
    unsigned char* mmap_buffer_{};
    bool console_log_open = true;

    //当前写日志文件
    time_t open_file_time_ = 0;
    FILE* log_file_ = nullptr;
    //单个日志文件大小，为0则不拆分文件
    size_t max_file_size_ = 10 * 1024 * 1024;

    //日志文件最长保存时间
    long max_alive_time_ = 10 * 24 * 60 * 60;
    std::mutex mutex_log_file_;
    std::mutex mutex_buffer_async_;
    bool producer_blocked_ = false;

    std::condition_variable buffer_consume_;
    std::condition_variable buffer_produce_;
    //文件最大写入重试次数
    int write_max_retry_times = 3;
    //异步刷buffer到文件的线程
    std::thread async_thread_;
    bool async_thread_finish_ = false;
    bool log_close_ = false;
};
#endif
