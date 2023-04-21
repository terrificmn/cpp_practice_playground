#ifndef WEB_SERVER_H
#define WEB_SERVER_H
#include "tcp_listener.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <filesystem>
#include <vector>
#include <iterator>

class WebServer : public TcpListener {
private:
    std::string pkg_path;
    std::string www_path = "wwwroot/index.html"; // fixed

protected:
     // Handler for client connections
    virtual void onClientConnected(int client_socket);
    // handlr for client disconnections
    virtual void onClientDisconnected(int client_socket);
    // handler for when a message is received from the client
    virtual void onMessageReceived(int client_socket, const char* msg, int length) override;


public:
    WebServer(const char* ip_address, int port);
    ~WebServer();

    bool makeHeader(std::string context, std::ostringstream* ptr_os);
    // void broadcastToClients(int sending_client, const char* msg, int length);

};
#endif