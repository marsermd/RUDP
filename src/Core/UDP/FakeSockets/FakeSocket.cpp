#include "FakeSocket.h"
#include "FakeNetwork.h"

FakeNetwork connection;
bool FakeSocket::Open(uint16_t port)
{
    target = IPTarget(127, 0, 0, 1, port);
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
    ssize_t i = connection.TryRead(target, sender, data, size);
    return i;
}

bool FakeSocket::SetNonBlocking(bool nonBlocking)
{
    return nonBlocking;
}

bool FakeSocket::IsOpen() const
{
    return true;
}