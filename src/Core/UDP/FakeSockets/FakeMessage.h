#ifndef RUDP_FAKEMESSAGE_H
#define RUDP_FAKEMESSAGE_H

#include <cstdint>
#include <vector>
#include <cstdio>
#include <ctime>
#include "../IPTarget.h"

class FakeMessage
{
public:
    uint64_t  timeSent;
    virtual void Give(std::vector <uint8_t> &tobuffer, size_t bufferSize);
    virtual bool isEmpty();

    FakeMessage()
    {
        timeSent = 0;
        _buffer = std::vector <uint8_t>();
        _size = 0;
    }

    FakeMessage(IPTarget sender, const void* buff, size_t size)
    {
        _from = sender;
        timeSent = time(NULL);
        _buffer.assign(static_cast<const uint8_t*>(buff), static_cast<const uint8_t*>(buff) + size);
        _size = size;
    }

    const IPTarget &get_from() const;

    ~FakeMessage()
    {
        _buffer.clear();
    }
private:
    IPTarget _from;
    std::vector <uint8_t> _buffer;
    size_t _size;
};

#endif //RUDP_FAKEMESSAGE_H