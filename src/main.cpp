#include <iostream>
#include <cstring>
#include <Messages/ReliableMessage.pb.h>
#include <Core/UDP/Connection/Reliability/ReliableConnection.h>
#include "Messages/StringMessage.pb.h"

uint16_t listenPort = 0;
IPTarget target;
bool sending = false;
std::shared_ptr<SocketBase> sock;

void CreateSocket()
{
    sock = std::make_shared<Socket>();
    if (!sock->Open(listenPort))
    {
        printf("failed to open socket!\n");
    }
}

void RemoveSoket()
{
    sock->Close();
}

void SendPackets()
{
    char data[2048];
    while (true)
    {
        memset(data, 0, 2048);
        scanf("%s", data);
        sock->Send(target, data, strlen(data));
        printf("Sent data: %s\n", data);
    }
}

void ReceivePackets()
{
    while (true)
    {
        IPTarget sender;
        char buffer[2048];
        memset(buffer, 0, 2048);
        ssize_t bytes_read =
                sock->Receive(sender,
                              buffer,
                              sizeof(buffer));
        if (bytes_read <= 0)
        {
            continue;
        }

        // process packet
        printf("%ld: %s\n", bytes_read, buffer);
    }
}

bool ParseCmdLine(int argc, char **argv)
{
    for (int i = 0; i < argc; i++)
    {
        std::string argStr = std::string(argv[i]);
        if (argStr == "--port" || argStr == "-p")
        {
            std::string portStr = std::string(argv[i + 1]);
            listenPort = (uint16_t) std::stoi(portStr);
        }
        else if (argStr == "--sendto" || argStr == "-st")
        {
            std::string portStr = std::string(argv[i + 1]);
            target = IPTarget(127, 0, 0, 1, (uint16_t) std::stoi(portStr));
        }
        else if (argStr == "--send" || argStr == "-s")
        {
            sending = true;
        }
    }
    return true;
}

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
    std::cout << "A received " << message->value() << "from " << target.GetPort() << std::endl;
}
void OnMessageReceivedB(IPTarget target, std::shared_ptr<StringMessage> message)
{
    std::cout << "B received " << message->value() << "from " << target.GetPort() << std::endl;
}


int main(int argc, char **argv)
{
//    if (!ParseCmdLine(argc, argv))
//    {
//        return 1;
//    }
//
//    CreateSocket();
//
//    if (sending)
//    {
//        SendPackets();
//    }
//    else
//    {
//        ReceivePackets();
//    }

    IPTarget a(127, 0, 0, 1, 8092);
    IPTarget b(127, 0, 0, 1, 8094);

    auto socketA = std::unique_ptr<SocketBase>(new Socket());
    if (!socketA->Open(a.GetPort()))
    {
        printf("failed to open socket!\n");
    }

    auto socketB = std::unique_ptr<SocketBase>(new Socket());
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

    while (true)
    {
        auto message = std::make_shared<StringMessage>();
        message->set_value("hello", 5);

        A.PushMessage(b, message);
        B.PushMessage(a, message);
        A.Update();
        B.Update();

        sleep(1);
    }

    return 0;
}