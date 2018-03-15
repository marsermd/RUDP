#include "FakeNetwork.h"
#include <ctime>
#include <vector>

uint16_t FakeNetwork::TakePort(IPTarget port)
{
    if (port.GetPort() == 0)
    {
        auto it = _portToMessageQueue.end();
        --it;
        return it->first.GetPort() + 1;
    }

}

ssize_t FakeNetwork::TryRead(IPTarget listenport, IPTarget &sender, void* buffer, size_t bufferSize)
{
    std::vector <uint8_t> buff;
    buff.assign(static_cast<uint8_t*>(buffer), static_cast<uint8_t*>(buffer) + bufferSize);
    if (_portToMessageQueue[listenport].empty())
    {
        return 0;
    }
    FakeMessage& mess = _portToMessageQueue[listenport].front();
    time_t current = time(NULL);
    if (mess.timeSent + ping >= current)
    {
        mess.Give(buff, bufferSize);
        sender = mess.get_from();
        if (mess.isEmpty())
        {
            _portToMessageQueue[listenport].pop();
        }
    }
}

bool FakeNetwork::Send(IPTarget sender, IPTarget to, const void *buffer, size_t size)
{
    _portToMessageQueue[to].push(FakeMessage(sender ,buffer, size));
    return true;
}