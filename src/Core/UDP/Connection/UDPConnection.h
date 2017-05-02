//
// Created by marsermd on 4/15/17.
//

#ifndef RUDP_UDPCONNECTION_H
#define RUDP_UDPCONNECTION_H


#include <functional>
#include <vector>
#include <map>
#include <memory>
#include <chrono>
#include <queue>

#include "../Sockets/Socket.h"
#include "UDPMessage.h"

/**
 * This class represents connections to other sockets
 */
class UDPConnection
{
public:
    /**
     * Create a new connection that is listening to messages from target
     * And sending messages to it.
     * @param socket socket to operate on
     * @param target target to communicate with
     */
    UDPConnection(std::shared_ptr<SocketBase> socket, IPTarget target);

    /**
     * Set messageReceived callback function
     * @param onMessageReceived is called after message is received from IPTarget
     */
    void SetOnMessageReceived(const std::function<void(IPTarget, std::vector<uint8_t>)> &onMessageReceived);

    /**
     * Set disconnected callback function
     * @param onDisconnected is called after IPTarget is removed from active connections(this happens after timeout)
     */
    void SetOnDisconnected(const std::function<void(IPTarget)> &onDisconnected);

    /**
     * Set connected callback function
     * @param onConnected is called after IPTarget is added to active connections(this happens after message is received from it)
     */
    void SetOnConnected(const std::function<void(IPTarget)> &onConnected);

    /**
     * Register message for sending. It is sent in the update function.
     * @param message message to send
     */
    void PushMessage(UDPMessage message);

    /**
     * Receive messages, Update connections and send messages.
     */
    void Update();

private:
    /// socket to operate on
    std::shared_ptr<SocketBase> _socket;
    /// target to communicate with
    IPTarget _target;

    /// messages registered for sending, but not sent yet
    std::queue<UDPMessage> _messagesToSend;

    /// callback functions. Called in Update()
    std::function<void(IPTarget, std::vector<uint8_t> data)> _onMessageReceived;
    std::function<void(IPTarget)> _onDisconnected;
    std::function<void(IPTarget)> _onConnected;

    /// buffer to read to during ReceiveMssages()
    static const size_t _bufferSize = 1024;
    uint8_t _buffer[_bufferSize];

    typedef std::chrono::steady_clock default_clock;
    typedef std::chrono::time_point<default_clock, std::chrono::nanoseconds> time_point;

    /// map to store last client's activity
    std::map<IPTarget, time_point> _lastClientMessage;
    /// timeout after which connection is dropped.
    std::chrono::milliseconds _connectionTimeout;

    /// receive all messages and call OnMessageReceived.
    void ReceiveMessages();

    /// accept message from current target that is already written in _buffer and has size messageSize
    void ReceiveMessage(const IPTarget &currentTarget, ssize_t messageSize);

    /// find all connections with their last action time has timed out and remove them(and call onDisconnected)
    void RemoveTimedoutConnections();

    void SendMessages();
};


#endif //RUDP_UDPCONNECTION_H
