//
// Created by marsermd on 4/15/17.
//

#include <iostream>
#include <cstring>
#include "UDPConnection.h"

using namespace std::chrono;

UDPConnection::UDPConnection(std::shared_ptr<SocketBase> socket, IPTarget target):
    _connectionTimeout(10000)
{
    _socket = socket;
    _target = target;

}

void UDPConnection::SetOnMessageReceived(const std::function<void(IPTarget, std::vector<uint8_t>)> &onMessageReceived)
{
    _onMessageReceived = onMessageReceived;
}

void UDPConnection::SetOnDisconnected(const std::function<void(IPTarget)> &onDisconnected)
{
    _onDisconnected = onDisconnected;
}

void UDPConnection::SetOnConnected(const std::function<void(IPTarget)> &onConnected)
{
    _onConnected = onConnected;
}

void UDPConnection::Update()
{
    ReceiveMessages();
    RemoveTimedoutConnections();
    SendMessages();
}

void UDPConnection::RemoveTimedoutConnections()
{
    auto now = steady_clock::now();
    for (auto item = _lastClientMessage.begin(); item != _lastClientMessage.end();)
    {
        auto duration = duration_cast<std::chrono::milliseconds>(now - item->second);
        if (duration > _connectionTimeout)
        {
            IPTarget target = item->first;
            item = _lastClientMessage.erase(item);
            if (_onDisconnected)
            {
                _onDisconnected(target);
            }
        }
        else
        {
            item++;
        }
    }
}

void UDPConnection::ReceiveMessages()
{
    IPTarget sender;
    ssize_t read;
    while ((read = _socket->Receive(sender, _buffer, _bufferSize)) > 0)
    {
        if (_target.Includes(sender))
        {
            //We don't want accidentally get some messages from targets we are not communicating with.
            ReceiveMessage(sender, read);
        }
    }

    // if read == 0, there is just nothing to read
    // But EAGAIN just means that we haven't received any data yet. It's not really an error for us.
    if (read != 0 && errno != EAGAIN)
    {
        // error occurred

        std::cerr << "error while reading on socket! " << read << std::endl;
        std::cerr << "socket() failed: " << strerror(errno) << std::endl;
    }
}

void UDPConnection::ReceiveMessage(const IPTarget &currentTarget, ssize_t messageSize)
{
    auto targetTimeIter = _lastClientMessage.find(currentTarget);

    // first packet from this IPTarget
    if (targetTimeIter == _lastClientMessage.end())
    {
        if (_onConnected)
        {
            _onConnected(currentTarget);
        }
    }

    _lastClientMessage[currentTarget] = steady_clock::now();

    if (_onMessageReceived)
    {
        _onMessageReceived(currentTarget, std::vector<uint8_t>(_buffer, _buffer + messageSize));
    }
}

void UDPConnection::PushMessage(UDPMessage message)
{
    _messagesToSend.push(message);
}

void UDPConnection::SendMessages()
{
    while (!_messagesToSend.empty())
    {
        UDPMessage message = _messagesToSend.front();
        _messagesToSend.pop();
        _socket->Send(message.GetTarget(), &message.GetData()[0], message.GetData().size());
    }
}

