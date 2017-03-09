//
// Created by marsermd on 3/8/17.
//

#ifndef RUDP_SOCKET_H
#define RUDP_SOCKET_H


#include <cstddef>
#include <unistd.h>
#include "IPTarget.h"

class Socket
{
public:
    Socket();
    ~Socket();

    /**
     * Makes socket listen to specified port in non-blocking mode.
     * @param port
     * @return
     */
    bool Open(uint16_t port);

    /**
     * Frees it's port
     */
    void Close();

    /**
     * Sends packet to destination
     * @param destination desired IP adress + port
     * @param data message's contents
     * @param size size of message in bytes
     * @return true on success
     */
    bool Send(const IPTarget &destination,
              const void *data,
              size_t size);

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
    ssize_t Receive(IPTarget &sender,
                    void *data,
                    size_t size);


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
    bool SetNonBlocking(bool nonBlocking);

    bool IsOpen() const;

private:
    int _handle;
};


#endif //RUDP_SOCKET_H
