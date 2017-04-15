#include <iostream>
#include <cstring>
#include "Core/UDP/Sockets/Socket.h"

uint16_t listenPort = 0;
IPTarget target;
bool sending = false;
SocketBase *sock;

void CreateSocket()
{
    sock = new Socket();
    if (!sock->Open(listenPort))
    {
        printf("failed to open socket!\n");
    }
}

void RemoveSoket()
{
    sock->Close();
    delete sock;
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

int main(int argc, char **argv)
{
    if (!ParseCmdLine(argc, argv))
    {
        return 1;
    }

    CreateSocket();

    if (sending)
    {
        SendPackets();
    }
    else
    {
        ReceivePackets();
    }

    return 0;
}