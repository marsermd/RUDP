//
// Created by marsermd on 3/8/17.
//

#include "Socket.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <cstdio>

Socket::Socket()
{
    _handle = -1;
}

Socket::~Socket()
{
    if (IsOpen())
    {
        Close();
    }
}

bool Socket::Open(uint16_t port)
{
    this->_handle = socket(AF_INET,
                           SOCK_DGRAM,
                           IPPROTO_UDP);

    if (this->_handle <= 0)
    {
        printf("failed to create socket\n");
        return false;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons((unsigned short) port);

    if (bind(this->_handle,
             (const sockaddr *) &address,
             sizeof(sockaddr_in)) < 0)
    {
        printf("failed to bind socket\n");
        Close();
        return false;
    }

    printf("Listening on port %d\n", port);

    if (!SetNonBlocking(true))
    {
        Close();
        return false;
    }

    return true;
}

void Socket::Close()
{
    close(this->_handle);
    _handle = -1;
}

bool Socket::Send(const IPTarget &destination, const void *data, size_t size)
{
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(destination.GetAddress());
    addr.sin_port = htons(destination.GetPort());

    ssize_t sent_bytes =
            sendto(this->_handle,
                   (const char *) data,
                   size,
                   0,
                   (sockaddr *) &addr,
                   sizeof(sockaddr_in));

    if (sent_bytes != size)
    {
        printf("failed to send packet\n");
        return false;
    }

    return true;
}

ssize_t Socket::Receive(IPTarget &sender,
                        void *packet_data,
                        size_t max_packet_size)
{

    sockaddr_in from;
    socklen_t fromLength = sizeof(from);

    ssize_t bytes = recvfrom(this->_handle,
                             (char *) packet_data,
                             max_packet_size,
                             0,
                             (sockaddr *) &from,
                             &fromLength);

    uint32_t from_address =
            ntohl(from.sin_addr.s_addr);

    uint16_t from_port =
            ntohs(from.sin_port);

    sender = IPTarget(from_address, from_port);

    return bytes;
}

bool Socket::IsOpen() const
{
    return _handle > 0;
}

bool Socket::SetNonBlocking(bool nonBlocking)
{
    int nonBlockingInt = nonBlocking ? 1 : 0;
    if (fcntl(this->_handle,
              F_SETFL,
              O_NONBLOCK,
              nonBlockingInt) == -1)
    {
        printf("failed to set non-blocking\n");
        return false;
    }
    return true;
}