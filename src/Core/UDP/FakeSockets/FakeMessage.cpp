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

bool FakeMessage::isEmpty()
{
    return _buffer.empty();
}

const IPTarget &FakeMessage::get_from() const {
    return _from;
}
