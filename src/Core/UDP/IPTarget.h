//
// Created by marsermd on 3/8/17.
//

#ifndef RUDP_IPTARGET_H
#define RUDP_IPTARGET_H

#include <stdint-gcc.h>

class IPTarget
{
public:
    /**
     * Sets address and port to be zero.
     * Listening to this target means listening to all targets.
     * Sending to this address is invalid.
     * Use IPTarget::ANY if it is really what you are intended to do
     */
    IPTarget();

    /**
     * Sets address and port to be zero.
     * Listening to this target means listening to all targets.
     * Sending to this address is invalid.
     * @return IPTarget with given parameters
     */
    static const IPTarget & Any();

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

    /**
     * Checks if receiving from this IPTarget also means receiving from rhs.
     * That is when they are equal or when current adress and port are zero
     * @param rhs
     * @return
     */
    bool Includes(const IPTarget &rhs) const;

private:
    uint32_t _address;
    uint16_t _port;
};


#endif //RUDP_IPTARGET_H
