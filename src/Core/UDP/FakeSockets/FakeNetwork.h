#ifndef RUDP_FAKECONNECTION_H
#define RUDP_FAKECONNECTION_H

#include <stdio.h>
#include <queue>
#include <map>
#include <vector>
#include "../IPTarget.h"
#include "FakeMessage.h"

class FakeNetwork
{
public:
    virtual uint16_t TakePort(IPTarget);
    virtual ssize_t TryRead(IPTarget port, IPTarget &sender, void* buffer, size_t size);
    virtual bool Send(IPTarget sender, IPTarget to, const void* buffer, size_t size);
private:
    std::map<IPTarget, std::queue<FakeMessage>> _portToMessageQueue;
};


#endif //RUDP_FAKECONNECTION_H