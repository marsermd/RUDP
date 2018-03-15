#include "FakeSocket.h"
#include "FakeNetwork.h"

FakeNetwork connection;
bool FakeSocket::Open(uint16_t port)
{
    target = IPTarget(127, port);
    return true;
}

void FakeSocket::Close()
{

}

bool FakeSocket::Send(const IPTarget &to,
                      const void *data,
                      size_t size)
{
    return connection.Send(target, to, data, size);
}

ssize_t FakeSocket::Receive(IPTarget &sender,
                            void* data,
                            size_t size)
{
    return connection.TryRead(target, sender, data, size);
}

bool FakeSocket::SetNonBlocking(bool nonBlocking)
{
    return nonBlocking;
}

bool FakeSocket::IsOpen() const
{
    return true;
}