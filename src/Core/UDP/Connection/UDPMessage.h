//
// Created by marsermd on 4/29/17.
//

#ifndef RUDP_UDPMESSAGE_H
#define RUDP_UDPMESSAGE_H


#include <vector>
#include <cstddef>
#include "../IPTarget.h"

/**
 * Message class represents a single UDP packet that should be sent over UDP
 */
class UDPMessage
{
public:
    /**
     * Create a new UDP packet.
     * Size MUST be less than 1200, since most MTU's are in range from 1200 to 1500
     * @param target target to send to
     * @param data UDP payload
     * @param size size of data on bytes
     */
    UDPMessage(IPTarget target, const uint8_t* data, size_t size);

    /**
     * @return stored UDP payload
     */
    std::vector<int8_t> GetData();

    /**
     * @return target to send message to
     */
    const IPTarget &GetTarget() const;

private:
    std::vector<int8_t> _data;
    IPTarget _target;
};


#endif //RUDP_UDPMESSAGE_H
