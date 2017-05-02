//
// Created by marsermd on 3/8/17.
//

#ifndef RUDP_IPTARGET_H
#define RUDP_IPTARGET_H

#include <stdint-gcc.h>

class IPTarget
{
public:
    IPTarget();

    IPTarget(uint8_t a,
             uint8_t b,
             uint8_t c,
             uint8_t d,
             uint16_t port);

    IPTarget(uint32_t address,
             uint16_t port);

    uint32_t GetAddress() const;

    uint16_t GetPort() const;

    bool operator<(const IPTarget &rhs) const;

    bool operator>(const IPTarget &rhs) const;

    bool operator<=(const IPTarget &rhs) const;

    bool operator>=(const IPTarget &rhs) const;

private:
    uint32_t _address;
    uint16_t _port;
};


#endif //RUDP_IPTARGET_H
