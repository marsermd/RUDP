//
// Created by marsermd on 5/11/17.
//

#ifndef RUDP_RELIABLECONNECTION_H
#define RUDP_RELIABLECONNECTION_H

#include <cstdint>
#include <Messages/ReliableMessage.pb.h>
#include <unordered_map>
#include <bitset>
#include "Core/UDP/Connection/Unreliable/UDPConnection.h"

template <class TMessage>
class ReliableConnection: public ConnectionBase<TMessage>
{
public:
    ReliableConnection(std::unique_ptr<ConnectionBase<ReliableMessage>> &connection);

    virtual ~ReliableConnection();

    void PushMessage(IPTarget target, std::shared_ptr<TMessage>& message) override;

    void Update() override;

private:
    class TargetInfo
    {
    public:
        std::map<uint32_t, std::shared_ptr<ReliableMessage>> m_acksToUnconfirmedMessages;

        /**
         * ID of next packet that will be created, starting from 1
         */
        uint32_t m_nextPacketId = 32;

        /**
         * Greatest ID of all received by this computer
         */
        uint32_t m_lastReceivedPacket = 31;

        /**
         * Bitmask for all received packets.<br/>
         * m_ackMask[n]  = is packet with ID m_lastReceivedPacket - (32 - n) received?<br/>
         * m_ackMask[31] = is packet with ID m_lastReceivedPacket - 1 received?<br/>
         * m_ackMask[0]  = is packet with ID m_lastReceivedPacket - 32 received?<br/>
         */
        uint32_t m_ackMask = 0xFFFFFFFF;
    };

    void OnMessageReceived(IPTarget target, std::shared_ptr<ReliableMessage> message);

    void OnDisconnected(IPTarget target);

    void OnConnected(IPTarget target);

    void SendMessage(IPTarget target, std::shared_ptr<ReliableMessage> &message);

    TargetInfo& GetTargetInfo(IPTarget target);

    std::unique_ptr<ConnectionBase<ReliableMessage>> _connection;

    std::unordered_map<IPTarget, TargetInfo> _targets;
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
    const uint32_t MAX_PAYLOAD_SIZE = 2048;
    assert(message->ByteSizeLong() <= MAX_PAYLOAD_SIZE);

    TargetInfo& targetInfo = GetTargetInfo(target);

    static uint8_t buffer[MAX_PAYLOAD_SIZE];
    message->SerializeToArray(buffer, MAX_PAYLOAD_SIZE);

    auto reliableMsg = std::make_shared<ReliableMessage>();

    reliableMsg->set_sequence(targetInfo.m_nextPacketId);
    reliableMsg->set_payload(buffer, message->ByteSizeLong());

    targetInfo.m_acksToUnconfirmedMessages[targetInfo.m_nextPacketId] = reliableMsg;
    targetInfo.m_nextPacketId++;
}

template <class TMessage>
void ReliableConnection<TMessage>::Update()
{
    for (auto &it: _targets)
    {
        IPTarget target = it.first;
        TargetInfo& targetInfo = it.second;

        if (targetInfo.m_acksToUnconfirmedMessages.empty())
        {
            continue;
        }

        uint32_t lastUnconfirmedPacket = targetInfo.m_acksToUnconfirmedMessages.begin()->first;
        for (auto &jt: targetInfo.m_acksToUnconfirmedMessages)
        {
            const uint32_t &ack = jt.first;
            std::shared_ptr<ReliableMessage> &message = jt.second;

            if (ack > lastUnconfirmedPacket + 32)
            {
                break;
            }
            SendMessage(target, message);
        }
    }
    _connection->Update();
}

template <class TMessage>
void ReliableConnection<TMessage>::SendMessage(IPTarget target, std::shared_ptr<ReliableMessage> &message)
{
    TargetInfo& targetInfo = GetTargetInfo(target);

    message->set_ack(targetInfo.m_lastReceivedPacket);
    message->set_ack_bitmask(targetInfo.m_ackMask);
    _connection->PushMessage(target, message);
}

template <class TMessage>
void ReliableConnection<TMessage>::OnMessageReceived(IPTarget target, std::shared_ptr<ReliableMessage> message)
{
    TargetInfo& targetInfo = GetTargetInfo(target);

    uint32_t sequence = message->sequence();
    bool isDuplicated = sequence == targetInfo.m_lastReceivedPacket;

    if (sequence < targetInfo.m_lastReceivedPacket)
    {
        uint32_t delta = targetInfo.m_lastReceivedPacket - sequence;
        if (delta <= 32)
        {
            uint32_t messageBit = 1u << (delta - 1);
            isDuplicated = (targetInfo.m_ackMask & messageBit) != 0;
            targetInfo.m_ackMask |= messageBit;
        }
    }
    else if (sequence > targetInfo.m_lastReceivedPacket)
    {
        uint32_t delta = sequence - targetInfo.m_lastReceivedPacket;
        assert(delta <= 32); // we didn't jump too far
        assert(((targetInfo.m_ackMask >> (32 - delta)) | 0xFFFFFFFF << delta) == 0xFFFFFFFF); // all previous packets were received
        targetInfo.m_ackMask <<= delta;
        targetInfo.m_ackMask |= 1 << (delta - 1);

        targetInfo.m_lastReceivedPacket = sequence;
    }

    uint32_t bitmask = message->ack_bitmask();
    uint32_t ack = message->ack();
    targetInfo.m_acksToUnconfirmedMessages.erase(ack);
    for (uint32_t i = 1; i <= std::max(32u, ack); i++)
    {
        if (bitmask % 2 == 1)
        {
            targetInfo.m_acksToUnconfirmedMessages.erase(ack - i);
        }
        bitmask >>= 1;
    }

    if(!isDuplicated && this->_onMessageReceived)
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
        _targets.erase(target);
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

template <class TMessage>
typename ReliableConnection<TMessage>::TargetInfo& ReliableConnection<TMessage>::GetTargetInfo(IPTarget target)
{
    auto it = _targets.find(target);
    if (it == _targets.end())
    {
        return _targets[target] = TargetInfo();
    }

    return it->second;
}

#endif //RUDP_RELIABLECONNECTION_H
