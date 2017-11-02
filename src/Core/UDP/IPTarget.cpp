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

bool IPTarget::operator<(const IPTarget &rhs) const
{
    if (_address < rhs._address)
        return true;
    if (rhs._address < _address)
        return false;
    return _port < rhs._port;
}

bool IPTarget::operator>(const IPTarget &rhs) const
{
    return rhs < *this;
}

bool IPTarget::operator<=(const IPTarget &rhs) const
{
    return !(rhs < *this);
}

bool IPTarget::operator>=(const IPTarget &rhs) const
{
    return !(*this < rhs);
}

bool IPTarget::operator==(const IPTarget &rhs) const
{
    return _address == rhs._address && _port == rhs._port;
}

static IPTarget ANY;
const IPTarget& IPTarget::Any()
{
    return ANY;
}

bool IPTarget::Includes(const IPTarget &rhs) const
{
    if (_address == 0 && _port == 0)
    {
        return true;
    }
    return rhs._address == _address && rhs._port == _port;
}

size_t IPTarget::GetHashcode() const
{
    //todo: not the best way to combine hashes
    return std::hash<uint32_t>()(_address) ^ std::hash<uint16_t>()(_port);
}

