//
// Created by marsermd on 4/15/17.
//

#ifndef RUDP_UDPCONNECTION_H
#define RUDP_UDPCONNECTION_H


#include <functional>
#include <map>
#include <memory>
#include <chrono>
#include <queue>
#include <iostream>

#include "../../Sockets/Socket.h"
#include "../Base/ConnectionBase.h"

/**
 * This class represents connections to other sockets
 */
 template <class TMessage>
class UDPConnection: public ConnectionBase<TMessage>
{
public:
    /**
     * Create a new connection that is listening to messages from target
     * And sending messages to it.
     * @param socket socket to operate on
     * @param target target to communicate with
     */
    UDPConnection(std::unique_ptr<SocketBase> &socket, IPTarget target);

    virtual ~UDPConnection();

    /**
     * Register message for sending. It is sent in the update function.
     * @param message message to send
     */
    void PushMessage(IPTarget target, std::shared_ptr<TMessage>& message) override;

    /**
     * Receive messages, Update connections and send messages.
     */
    void Update() override;

private:


    /// receive all messages and call OnMessageReceived.
    void ReceiveMessages();

    /// accept message from current target that is already written in _buffer and has size messageSize
    void ReceiveMessage(const IPTarget &currentTarget, ssize_t messageSize);

    /// find all connections with their last action time has timed out and remove them(and call onDisconnected)
    void RemoveTimedoutConnections();

    void SendMessages();

    std::queue<std::shared_ptr<TMessage>> * getMessageQueue(IPTarget target);

    /// socket to operate on
    std::unique_ptr<SocketBase> _socket;
    /// target to communicate with
    IPTarget _target;

    /// messages that are registered for sending, but not sent yet
    std::map<IPTarget, std::queue<std::shared_ptr<TMessage>>*> _messagesToSend;

    /// buffer to read to during ReceiveMssages()
    static const size_t _bufferSize = 2048;
    uint8_t _buffer[_bufferSize];

    typedef std::chrono::steady_clock default_clock;
    typedef std::chrono::time_point<default_clock, std::chrono::nanoseconds> time_point;

    /// map to store last client's activity
    std::map<IPTarget, time_point> _lastClientMessage;
    /// timeout after which connection is dropped.
    std::chrono::milliseconds _connectionTimeout;
};


template <class TMessage>
UDPConnection<TMessage>::UDPConnection(std::unique_ptr<SocketBase> &socket, IPTarget target):
        _socket(std::move(socket)),
        _target(target),
        _connectionTimeout(10000)
{
}

template <class TMessage>
UDPConnection<TMessage>::~UDPConnection()
{
    for (auto it:_messagesToSend)
    {
        delete it.second;
    }
    _messagesToSend.clear();
}

template <class TMessage>
void UDPConnection<TMessage>::Update()
{
    ReceiveMessages();
    RemoveTimedoutConnections();
    SendMessages();
}

template <class TMessage>
void UDPConnection<TMessage>::RemoveTimedoutConnections()
{
    auto now = std::chrono::steady_clock::now();
    for (auto item = _lastClientMessage.begin(); item != _lastClientMessage.end();)
    {
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(now - item->second);
        if (duration > _connectionTimeout)
        {
            IPTarget target = item->first;
            item = _lastClientMessage.erase(item);
            if (this->_onDisconnected)
            {
                this->_onDisconnected(target);
            }
        }
        else
        {
            item++;
        }
    }
}

template <class TMessage>
void UDPConnection<TMessage>::ReceiveMessages()
{
    IPTarget sender;
    ssize_t read;
    while ((read = _socket->Receive(sender, _buffer, _bufferSize)) > 0)
    {
//        if (read > 0)
//        {
//            std::cout << "UDP ReceiveMessage ";
//        }
//        for (int i = 0; i < read; i++) {
//            if ((_buffer[i] >= 'A' && _buffer[i] <= 'Z') || (_buffer[i] >= 'a' && _buffer[i] <= 'z') ||
//                (_buffer[i] >= '0' && _buffer[i] <= '9'))
//                std::cout << _buffer[i] << ' ';
//            else
//                std::cout << 'B' << (int)_buffer[i] << ' ';
//        }
//        std::cout << "\n";
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

template <class TMessage>
void UDPConnection<TMessage>::ReceiveMessage(const IPTarget &currentTarget, ssize_t messageSize)
{
    auto targetTimeIter = _lastClientMessage.find(currentTarget);

    // first packet from this IPTarget
    if (targetTimeIter == _lastClientMessage.end())
    {
        if (this->_onConnected)
        {
            this->_onConnected(currentTarget);
        }
    }

    _lastClientMessage[currentTarget] = std::chrono::steady_clock::now();

    if (this->_onMessageReceived)
    {
        auto message = std::make_shared<TMessage>();
        message->ParseFromArray(_buffer, messageSize);
//        std::cout << "Payload in UDPConnection: '''" << message->payload() << "'''" << std::endl;
//        if (message->payload() == "\n\bhello ")
//        {
//            for (int i = 0; i < messageSize; i++) {
//                if ((_buffer[i] >= 'A' && _buffer[i] <= 'Z') || (_buffer[i] >= 'a' && _buffer[i] <= 'z') ||
//                    (_buffer[i] >= '0' && _buffer[i] <= '9'))
//                    std::cout << _buffer[i] << ' ';
//                else
//                    std::cout << 'B' << (int)_buffer[i] << ' ';
//            }
//            std::cout << "\n";
//            std::cout << "WTF" << std::endl;
//        }
        this->_onMessageReceived(currentTarget, message);
    }
}

template <class TMessage>
void UDPConnection<TMessage>::PushMessage(IPTarget target, std::shared_ptr<TMessage>& data)
{
    getMessageQueue(target)->push(data);
}

template <class TMessage>
void UDPConnection<TMessage>::SendMessages()
{
    for (auto it : _messagesToSend)
    {
        const IPTarget& target = it.first;
        std::queue<std::shared_ptr<TMessage>>* messages = it.second;
        while (!messages->empty())
        {
            std::shared_ptr<TMessage> message = messages->front();

            message->SerializeToArray(_buffer, _bufferSize);

            _socket->Send(target, _buffer, message->ByteSizeLong());

            messages->pop();
        }
    }
}

template <class TMessage>
std::queue<std::shared_ptr<TMessage>> * UDPConnection<TMessage>::getMessageQueue(IPTarget target)
{
    auto it = _messagesToSend.find(target);
    if (it != _messagesToSend.end())
    {
        return it->second;
    }
    else
    {
        return _messagesToSend[target] = new std::queue<std::shared_ptr<TMessage>>();
    }
}
#endif //RUDP_UDPCONNECTION_H
