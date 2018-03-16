#include "FakeNetwork.h"
#include <ctime>
#include <vector>
#include <iostream>
#include <ctime>

int PACKETLOSSPERCENT = 99;

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
    FakeMessage mess = _portToMessageQueue[listenport].front();
    milliseconds current = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );
    if (mess.timeSent + mess.getPing() <= current)
    {
        mess.Give(buff, bufferSize);
        sender = mess.get_from();
//        std::cout << "I get! " << sender.GetPort() << ' ';
//        mess.giveMessage();
        _portToMessageQueue[listenport].pop();

        for (size_t i = 0; i < mess.getSize(); i++) {
            static_cast<uint8_t *>(buffer)[i] = buff[i];
        }

//        std::cout << "Size is " << mess.getSize() << std::endl;
        return mess.getSize();
    }
//    std::cout << "(left " << (mess.timeSent + mess.getPing() - current).count() << " ms)" << std::endl;
    return 0;
}

bool FakeNetwork::Send(IPTarget sender, IPTarget to, const void *buffer, size_t size)
{
    if (rand() % 100 < PACKETLOSSPERCENT){
       return true;
    }
    FakeMessage m = FakeMessage(sender , buffer, size);
    srand(time(NULL));
    m.setPing(milliseconds(rand() % 100));
    _portToMessageQueue[to].push(m);
//    std::cout << "I send " << sender.GetPort() << ' ';
//    m.giveMessage();
    return true;
}