#ifndef RUDP_FAKESOCKET_H
#define RUDP_FAKESOCKET_H
#include <cstdint>
#include <cstdio>
#include <queue>
#include <map>
#include "../IPTarget.h"
#include "FakeMessage.h"
#include "../Sockets/SocketBase.h"

class FakeSocket : public SocketBase
{
public:
    IPTarget target;

    FakeSocket() {}
    virtual ~FakeSocket() {}

    virtual bool Open(uint16_t port);

    virtual void Close();

    virtual bool Send(const IPTarget &destination,
                      const void *data,
                      size_t size);

    virtual ssize_t Receive(IPTarget &sender,
                            void* data,
                            size_t size);

    virtual bool SetNonBlocking(bool nonBlocking);

    virtual bool IsOpen() const;
private:
    std::map<IPTarget, std::queue<FakeMessage>> _portToMessageQueue;
};


#endif //RUDP_FAKESOCKET_H