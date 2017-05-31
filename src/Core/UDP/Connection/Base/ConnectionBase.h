//
// Created by marsermd on 5/11/17.
//

#ifndef RUDP_CONNECTIONBASE_H
#define RUDP_CONNECTIONBASE_H


#include <functional>
#include <google/protobuf/message.h>
#include "Core/UDP/IPTarget.h"

template <class TMessage>
class ConnectionBase
{
public:

    virtual ~ConnectionBase(){}

    /**
     * Set messageReceived callback function
     * @param onMessageReceived is called after message is received from IPTarget
     */
    void SetOnMessageReceived(const std::function<void(IPTarget, std::shared_ptr<TMessage>)> &onMessageReceived);

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
    virtual void PushMessage(IPTarget target, std::shared_ptr<TMessage>& message) = 0;

    /**
     * Receive messages, Update connections and send messages.
     */
    virtual void Update() = 0;

protected:

    /// callback functions. Called in Update()
    std::function<void(IPTarget, std::shared_ptr<TMessage>)> _onMessageReceived;
    std::function<void(IPTarget)> _onDisconnected;
    std::function<void(IPTarget)> _onConnected;

};


template <class TMessage>
void ConnectionBase<TMessage>::SetOnMessageReceived(const std::function<void(IPTarget, std::shared_ptr<TMessage>)> &onMessageReceived)
{
    _onMessageReceived = onMessageReceived;
}

template <class TMessage>
void ConnectionBase<TMessage>::SetOnDisconnected(const std::function<void(IPTarget)> &onDisconnected)
{
    _onDisconnected = onDisconnected;
}

template <class TMessage>
void ConnectionBase<TMessage>::SetOnConnected(const std::function<void(IPTarget)> &onConnected)
{
    _onConnected = onConnected;
}


#endif //RUDP_CONNECTIONBASE_H
