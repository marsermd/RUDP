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
    ssize_t I = connection.TryRead(target, sender, data, size);
//    if (I > 0) {
//        std::cout << "I is " << I << std::endl;
//    }
    uint8_t *_buffer = static_cast<uint8_t*>(data);
//    if (I > 0) {
//        std::cout << "FakeReceive ";
//    }
//    for (int i = 0; i < I; i++) {
//        if ((_buffer[i] >= 'A' && _buffer[i] <= 'Z') || (_buffer[i] >= 'a' && _buffer[i] <= 'z') ||
//            (_buffer[i] >= '0' && _buffer[i] <= '9'))
//            std::cout << _buffer[i] << ' ';
//        else
//            std::cout << 'B' << (int)_buffer[i] << ' ';
//    }
//    std::cout << "\n";
    return I;
}

bool FakeSocket::SetNonBlocking(bool nonBlocking)
{
    return nonBlocking;
}

bool FakeSocket::IsOpen() const
{
    return true;
}