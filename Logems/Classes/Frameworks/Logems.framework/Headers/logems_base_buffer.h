//
// Created by bingo on 2021/3/17.
//

#ifndef LOGEMS_LOGEMS_BASE_BUFFER_H
#define LOGEMS_LOGEMS_BASE_BUFFER_H

#include <cstddef>
#include "fix_length_buffer.h"
#include "log_crypt.h"
#include "variable_length_buffer.h"

class LogemsBaseBuffer {
public:
    LogemsBaseBuffer(unsigned char *_buffer, size_t _len, bool _is_compress, const char *_pub_key);

    virtual ~LogemsBaseBuffer();

public:
    FixLengthBuffer &GetData();

    virtual size_t Compress(const void* _data, size_t _in_len, void* _dest, size_t _out_len) = 0;

    virtual void Flush(VariableLengthBuffer& _buffer);

    bool WriteAsync(const void* _data, size_t _length);

    bool WriteSync(const void* _data, size_t _length, VariableLengthBuffer& _out_buffer);

protected:
    void Clear();

    void Flush();

    char GetMagicEnd();

    void FixLength();

    virtual char GetMagicSyncStart() = 0;

    virtual char GetMagicAsyncStart() = 0;

    virtual bool Reset();


protected:
    FixLengthBuffer buffer_;
    LogCrypt* log_crypt_;
    bool is_compress_;
    bool is_crypt_;
    size_t remain_not_crypt_len_;
};

#endif
