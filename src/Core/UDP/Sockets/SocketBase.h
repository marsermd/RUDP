#ifndef RUDP_SOCKETBASE_H
#define RUDP_SOCKETBASE_H

#include <cstddef>
#include <stdio.h>
#include "../IPTarget.h"

class SocketBase
{
public:
    SocketBase(){}
    virtual ~SocketBase(){}

    /**
     * Makes socket listen to specified port in non-blocking mode.
     * @param port
     * @return true on success
     */
    virtual bool Open(uint16_t port) = 0;

    /**
     * Frees it's port
     */
    virtual void Close() = 0;

    /**
     * Sends packet to destination
     * @param destination desired IP adress + port
     * @param data message's contents
     * @param size size of message in bytes
     * @return true on success
     */
    virtual bool Send(const IPTarget &destination,
                      const void *data,
                      size_t size) = 0;

    /**
     * Receives packet from target.
     * If socket is blocking and there are no unread packets,
     * program will stop it's execution until packet is received.
     * If in the same situation socket is non-blocking, receive will just return 0 immediately.
     *
     * @param sender port we are trying to get packets from
     * @param data data buffer to which packets are read
     * @param size buffer size in bytes
     * @return size of read data. If error occurred, result is < 0
     */
    virtual ssize_t Receive(IPTarget &sender,
                            void *data,
                            size_t size) = 0;


    /**
     * Sets socket blocking mode.
     * If socket is blocking and Receive is called while there are no unread packets,
     * program will stop it's execution until packet is received.
     * If in the same situation socket is non-blocking, receive will just return 0 immediately.
     *
     * If there are packets waiting to be read, it doesn't matter if socket is in blocking mode or not.
     *
     * @param nonBlocking
     * @return true on success
     */
    virtual bool SetNonBlocking(bool nonBlocking) = 0;

    virtual bool IsOpen() const = 0;
};

#endif //RUDP_SOCKETBASE_H
