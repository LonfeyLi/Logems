//
// Created by bingo on 2021/3/18.
//

#ifndef LOGEMS_LOG_CRYPT_H
#define LOGEMS_LOG_CRYPT_H

#include "variable_length_buffer.h"
#include <cstdint>
#include <string>

class LogCrypt {
public:
    LogCrypt(const char *_pub_key);

    static uint32_t GetLogLength(const char *_data, size_t _len);

    static bool GetLogLength(const char *_data, size_t _len, uint32_t& _raw_log_length);

    static void UpdateLogHour(unsigned char *_data);

    static void UpdateLogLength(char *_data, uint32_t _add_len);

    static void SetLogTail(unsigned char *_data, char _tail);

    static uint32_t GetTailLen();

    static uint32_t GetHeaderLen();

    void SetHeaderInfo(char* _data, bool _is_async, char _magic_start);

    static void SetTailInfo(char* _data, char _magic_end);

    void CryptSyncLog(const char* _data, size_t _data_length, VariableLengthBuffer& _out_buffer, char _magic_start, char _magic_end);

    void CryptAsyncLog(const char* _data, size_t _data_length, VariableLengthBuffer& _out_buffer, size_t& _remain_not_encrypt_length) const;

private:
    //是否加密
    bool is_crypt_;

    char client_pubkey_[64];
};

#endif
