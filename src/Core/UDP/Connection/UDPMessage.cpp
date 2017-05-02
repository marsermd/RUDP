//
// Created by marsermd on 4/29/17.
//

#include <assert.h>
#include "UDPMessage.h"

UDPMessage::UDPMessage(IPTarget target, const uint8_t *data, size_t size) :
    _data(data, data + size),
    _target(target)
{
    assert(size < 1200); // Sending a bigger packet would be a mistake, since MTU might drop it
}

std::vector<int8_t> UDPMessage::GetData()
{
    return _data;
}

const IPTarget &UDPMessage::GetTarget() const
{
    return _target;
}
