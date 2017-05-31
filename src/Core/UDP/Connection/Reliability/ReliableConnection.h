//
// Created by marsermd on 5/11/17.
//

#ifndef RUDP_RELIABLECONNECTION_H
#define RUDP_RELIABLECONNECTION_H


#include <tiff.h>
#include <Messages/ReliableMessage.pb.h>
#include "../Unreliable/UDPConnection.h"

template <class TMessage>
class ReliableConnection: public ConnectionBase<TMessage>
{
public:
    ReliableConnection(std::unique_ptr<ConnectionBase<ReliableMessage>> &connection);

    virtual ~ReliableConnection();

    void PushMessage(IPTarget target, std::shared_ptr<TMessage>& message) override;

    void Update() override;

private:
    void OnMessageReceived(IPTarget target, std::shared_ptr<ReliableMessage> message);

    void OnDisconnected(IPTarget target);

    void OnConnected(IPTarget target);

    std::unique_ptr<ConnectionBase<ReliableMessage>> _connection;
    std::map<uint32, ReliableMessage> _acksToMessages;
    uint32 _lastSentPacket = 0;
    uint32 _lastReceivedPacket = 0;
    uint32 _ackMask = 0;
};

template <class TMessage>
ReliableConnection<TMessage>::ReliableConnection(std::unique_ptr<ConnectionBase<ReliableMessage>> &connection):
        _connection(std::move(connection))
{
    auto onReceived = [=](IPTarget a, std::shared_ptr<ReliableMessage> b) {
        this->OnMessageReceived(a, b);
    };
    _connection->SetOnMessageReceived(onReceived);

    auto onDisconnected = [=](IPTarget a) {
        this->OnDisconnected(a);
    };
    _connection->SetOnDisconnected(onDisconnected);

    auto onConnected = [=](IPTarget a) {
        this->OnConnected(a);
    };
    _connection->SetOnConnected(onConnected);
}

template <class TMessage>
ReliableConnection<TMessage>::~ReliableConnection()
{
}

template <class TMessage>
void ReliableConnection<TMessage>::PushMessage(IPTarget target, std::shared_ptr<TMessage> &message)
{
    auto wrapper = std::make_shared<ReliableMessage>();
    wrapper->set_sequence(_lastSentPacket);
    wrapper->set_ack(_lastReceivedPacket);
    wrapper->set_ackbitmask(_ackMask);

    static uint8_t buffer[2048];
    wrapper->SerializeToArray(buffer, 2048);

    wrapper->set_payload(buffer, message->ByteSizeLong());

    _connection->PushMessage(target, wrapper);

    _lastSentPacket++;
}

template <class TMessage>
void ReliableConnection<TMessage>::Update()
{
    _connection->Update();
}

template <class TMessage>
void ReliableConnection<TMessage>::OnMessageReceived(IPTarget target, std::shared_ptr<ReliableMessage> message)
{
    if(this->_onMessageReceived)
    {
        auto payload = std::make_shared<TMessage>();
        payload->ParseFromString(message->payload());
        this->_onMessageReceived(target, payload);
    }
}

template <class TMessage>
void ReliableConnection<TMessage>::OnDisconnected(IPTarget target)
{
    if(this->_onDisconnected)
    {
        this->_onDisconnected(target);
    }
}

template <class TMessage>
void ReliableConnection<TMessage>::OnConnected(IPTarget target)
{
    if(this->_onConnected)
    {
        this->_onConnected(target);
    }
}

#endif //RUDP_RELIABLECONNECTION_H
