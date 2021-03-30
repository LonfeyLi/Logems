//
// Created by bingo on 2021/3/18.
//

#ifndef LOGEMS_VARIABLE_LENGTH_BUFFER_H
#define LOGEMS_VARIABLE_LENGTH_BUFFER_H

#include <string>

class VariableLengthBuffer {
public:
    enum TSeek {
        vSeekStart,
        vSeekCur,
        vSeekEnd,
    };
public:
    explicit VariableLengthBuffer(size_t _unit_size = 128);

    explicit VariableLengthBuffer(unsigned char *_buffer, size_t _length, size_t _unit_size = 128);

    ~ VariableLengthBuffer();

    void AllocWrite(size_t _len);

    void AddCapacity(size_t _len);

    void ChangeLength(size_t _len);

    void Write(void *_buffer, size_t _length);

    void Write(void *_buffer, size_t _length, off_t _position);

    void Attach(void *_buffer, size_t _length);

    void Clear();

    void* Data(off_t _offset = 0);
public:

    off_t Position() const;

    size_t Length() const;

    size_t Capacity() const;

private:
    void FixLength(off_t _len, TSeek _type = vSeekCur);

    void FitSize(size_t _length);

private:
    unsigned char *buffer_;
    off_t position_;
    size_t length_;
    size_t capacity_;
    size_t malloc_unit_size_;
};


#endif //LOGEMS_VARIABLE_LENGTH_BUFFER_H
