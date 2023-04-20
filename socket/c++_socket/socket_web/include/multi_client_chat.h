#ifndef MULTI_CLIENT_CHAT_H
#define MULTI_CLIENT_CHAT_H
#include "tcp_listener.h"
#include <string>

class MultiClientChat : public TcpListener {
public:
    MultiClientChat(const char* ip_address, int port);
    void broadcastToClients(int sending_client, const char* msg, int length);

protected:
    // Handler for client connections
    virtual void onClientConnected(int client_socket);
    // handlr for client disconnections
    virtual void onClientDisconnected(int client_socket);
    // handler for when a message is received from the client
    virtual void onMessageReceived(int client_socket, const char* msg, int byte_recv_in);

    
};

#endif