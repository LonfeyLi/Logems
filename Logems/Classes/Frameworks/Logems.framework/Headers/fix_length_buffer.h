//
// Created by bingo on 2021/3/18.
//

#ifndef LOGEMS_FIX_LENGTH_BUFFER_H
#define LOGEMS_FIX_LENGTH_BUFFER_H

#include <string>

#ifndef max
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef min
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

class FixLengthBuffer {
public:
    enum TSeek {
        kSeekStart,
        kSeekCur,
        kSeekEnd,
    };

public:
    FixLengthBuffer(unsigned char* _buffer, size_t _length, size_t _max_length);

    FixLengthBuffer();

    ~FixLengthBuffer();

    void Write(const void* _buffer, size_t _length);

    void Write(const void* _buffer, size_t _length, off_t _position);

    unsigned char* Buffer();

    unsigned char* PositionedBuffer();

    size_t Length() const;

    size_t MaxLength() const;

    off_t Position() const;

    void Attach(unsigned char* _buffer, size_t _length, size_t _max_length);

    void Attach(unsigned char* _buffer, size_t _length);

    void Length(size_t _length, off_t _position);

    void Clear();
private:
    void FixLength(off_t _len, TSeek _type = kSeekCur);

private:
    unsigned char* buffer_;
    //当前写入位置偏移量
    off_t position_;
    //已存储数据长度
    size_t length_;
    //最大存储数据长度
    size_t max_length_;
};

#endif
