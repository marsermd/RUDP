#ifndef RUDP_FAKEMESSAGE_H
#define RUDP_FAKEMESSAGE_H

#include <cstdint>
#include <vector>
#include <cstdio>
#include <ctime>
#include <iostream>
#include "../IPTarget.h"
#include <chrono>

using namespace std::chrono;

class FakeMessage
{
public:
    milliseconds timeSent;
    virtual void Give(std::vector <uint8_t> &tobuffer, size_t bufferSize);
    virtual bool isEmpty();
    size_t getSize();

    FakeMessage()
    {
        timeSent = milliseconds(0);
        _buffer = std::vector <uint8_t>();
        _size = 0;
    }

    FakeMessage(IPTarget sender, const void* buff, size_t size)
    {
        _from = sender;
        timeSent = duration_cast< milliseconds >(
                system_clock::now().time_since_epoch()
        );
        _buffer.assign(static_cast<const uint8_t*>(buff), static_cast<const uint8_t*>(buff) + size);
        _size = size;
    }

    const IPTarget &get_from() const;

    ~FakeMessage()
    {
        _buffer.clear();
    }

    const milliseconds &getPing() const;

    void setPing(const milliseconds &ping);

    void giveMessage() const;
private:
    IPTarget _from;
    std::vector <uint8_t> _buffer;
    size_t _size;
    milliseconds ping = milliseconds(0);
};

#endif //RUDP_FAKEMESSAGE_H