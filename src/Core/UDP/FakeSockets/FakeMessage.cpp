#include <vector>
#include "FakeMessage.h"
#include <algorithm>

void FakeMessage::Give(std::vector<uint8_t> &toBuffer, size_t bufferSize)
{
    if (_size <= bufferSize)
    {
        toBuffer = _buffer;
    }
    else
    {
        std::copy(_buffer.begin(), _buffer.begin() + bufferSize, toBuffer.begin());
        _buffer.erase(_buffer.begin(), _buffer.begin() + bufferSize);
        _size = _buffer.size();
        _buffer.clear();
    }
}

size_t FakeMessage::getSize()
{
    return _buffer.size();
}

bool FakeMessage::isEmpty()
{
    return _buffer.empty();
}

void FakeMessage::giveMessage() const
{
    for (int i = 0; i < _buffer.size(); i++) {
        if ((_buffer[i] >= 'A' && _buffer[i] <= 'Z') || (_buffer[i] >= 'a' && _buffer[i] <= 'z') ||
                (_buffer[i] >= '0' && _buffer[i] <= '9'))
            std::cout << _buffer[i] << ' ';
        else
            std::cout << 'B' << (int)_buffer[i] << ' ';
    }
    std::cout << "\n";
}

const IPTarget &FakeMessage::get_from() const {
    return _from;
}

const milliseconds &FakeMessage::getPing() const {
    return ping;
}

void FakeMessage::setPing(const milliseconds &ping) {
    FakeMessage::ping = ping;
}
