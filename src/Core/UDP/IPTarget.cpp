//
// Created by marsermd on 3/8/17.
//

#include "IPTarget.h"

IPTarget::IPTarget()
{
    _address = 0;
    _port = 0;
}

IPTarget::IPTarget(uint32_t address, uint16_t port)
{
    _address = address;
    _port = port;
}

IPTarget::IPTarget(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint16_t port)
{
    _address = a;
    _address <<= 8;
    _address += b;
    _address <<= 8;
    _address += c;
    _address <<= 8;
    _address += d;

    _port = port;
}

uint32_t IPTarget::GetAddress() const
{
    return _address;
}

uint16_t IPTarget::GetPort() const
{
    return _port;
}