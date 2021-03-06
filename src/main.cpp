#include <iostream>
#include <cstring>
#include <Messages/ReliableMessage.pb.h>
#include <Core/UDP/Connection/Reliability/ReliableConnection.h>
#include <Core/UDP/FakeSockets/FakeSocket.h>
#include <Core/UDP/FakeSockets/FakeNetwork.h>
#include "Messages/StringMessage.pb.h"

uint16_t listenPort = 0;
IPTarget target;
std::map <std::string, milliseconds> time_sent;
std::shared_ptr<SocketBase> sock;

void OnConnectedA(IPTarget target)
{
    std::cout << target.GetPort() << " Connected to A" << std::endl;
}
void OnConnectedB(IPTarget target)
{
    std::cout << target.GetPort() << " Connected to B" << std::endl;
}

void OnDisconnectedA(IPTarget target)
{
    std::cout << target.GetPort() << " Disonnected from A" << std::endl;
}
void OnDisconnectedB(IPTarget target)
{
    std::cout << target.GetPort() << " Disonnected from B" << std::endl;
}

void OnMessageReceivedA(IPTarget target, std::shared_ptr<StringMessage> message)
{
    milliseconds current = duration_cast< milliseconds >(
            system_clock::now().time_since_epoch()
    );
    std::cout << "A received " << message->value() << " from " << target.GetPort() << " time " <<
              (current - time_sent[message->value()]).count() << std::endl;
}
void OnMessageReceivedB(IPTarget target, std::shared_ptr<StringMessage> message)
{
    std::cout << "B received " << message->value() << " from " << target.GetPort() << std::endl;
}

extern FakeNetwork connection;

int main(int argc, char **argv)
{

    IPTarget a(127, 0, 0, 1, 8092);
    IPTarget b(127, 0, 0, 1, 8094);

    auto socketA = std::unique_ptr<SocketBase>(new FakeSocket());
    if (!socketA->Open(a.GetPort()))
    {
        printf("failed to open socket!\n");
    }

    auto socketB = std::unique_ptr<SocketBase>(new FakeSocket());
    if (!socketB->Open(b.GetPort()))
    {
        printf("failed to open socket!\n");
    }

    auto unreliableA = std::unique_ptr<ConnectionBase<ReliableMessage>>(new UDPConnection<ReliableMessage>(socketA, IPTarget::Any()));
    auto unreliableB = std::unique_ptr<ConnectionBase<ReliableMessage>>(new UDPConnection<ReliableMessage>(socketB, IPTarget::Any()));

    ReliableConnection<StringMessage> A(unreliableA);
    ReliableConnection<StringMessage> B(unreliableB);

    A.SetOnConnected(OnConnectedA);
    B.SetOnConnected(OnConnectedB);

    A.SetOnDisconnected(OnDisconnectedA);
    B.SetOnDisconnected(OnDisconnectedB);

    A.SetOnMessageReceived(OnMessageReceivedA);
    B.SetOnMessageReceived(OnMessageReceivedB);

    for (uint32_t i = 0; true; i++)
    {
        auto message = std::make_shared<StringMessage>();

        std::string content("hello " + std::to_string(i));

        message->set_value(content);
        A.PushMessage(b, message);
        milliseconds current = duration_cast< milliseconds >(
                system_clock::now().time_since_epoch()
        );
        time_sent[content] = current;
        B.PushMessage(a, message);
        A.Update();
        B.Update();

        uint32_t milliseconds = 100;
        struct timespec ts;
        ts.tv_sec = milliseconds / 1000;
        ts.tv_nsec = (milliseconds % 1000) * 1000000;
        nanosleep(&ts, NULL);
    }
}