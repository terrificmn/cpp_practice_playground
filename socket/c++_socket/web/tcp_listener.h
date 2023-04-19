#ifndef TCP_LISTENER_H
#define TCP_LISTENER_H

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <arpa/inet.h>

class TcpListener {
private:
    const char* m_ip_address;
    const int m_port;
    int m_socket;  // internal socket File Descriptor for the listening socket
    fd_set m_master; // master File Descriptor set

protected:
    // Handler for client connections
    virtual void onClientConnected(int client_socket);
    // handlr for client disconnections
    virtual void onClientDisconnected(int client_socket);
    // handler for when a message is received from the client
    virtual void onMessageReceived(int client_socket, const char* msg, int byte_recv_in);

    // send a message to a client
    void sendToClient(int client_socket, const char* msg, int legnth);
    // Broadcast a message from a client
    void broadcastToClients(int sending_client, const char* msg, int length);
    

public:
    TcpListener(const char* ip_address, int port);
    ~TcpListener();

    // initialize the listener
    int init();
    // run the listener
    int run();
};

#endif