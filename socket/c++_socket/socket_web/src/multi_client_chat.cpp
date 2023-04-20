#include "tcp_listener.h"
#include "multi_client_chat.h"

MultiClientChat::MultiClientChat(const char* ip_address, int port) : 
                                            TcpListener(ip_address, port) {

}


// Handler for client connections
void MultiClientChat::onClientConnected(int client_socket) {
    // send a welcome message to the conencted client
    std::string welcome_msg = "Welcome to the Awesome Chat Server!\n";
    this->sendToClient(client_socket, welcome_msg.c_str(), welcome_msg.size()+1); // parent client's method
    
}

// handlr for client disconnections
void MultiClientChat::onClientDisconnected(int client_socket) {

}

// handler for when a message is received from the client
// void MultiClientChat::onMessageReceived(int client_socket, const char* msg, int byte_recv_in) {
void MultiClientChat::onMessageReceived(int client_socket, const char* msg, int length) {  /// 파라미터 확인 필요!
    this->broadcastToClients(client_socket, msg, length);
}

    // Broadcast a message from a client
void MultiClientChat::broadcastToClients(int sending_client, const char* msg, int length) {

}
