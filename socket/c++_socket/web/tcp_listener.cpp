#include "tcp_listener.h"
#include "iostream"

TcpListener::TcpListener(const char* ip_address, int port) : m_ip_address(ip_address), m_port(port) {

}

TcpListener::~TcpListener() {
}

int TcpListener::init() {
    // 1. create a socket
    this->m_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(this->m_socket  == -1) {
        std::cerr << "socket() error -- can't create a socket\n";
        return 1;
    }

     // 2. bind the socket to a IP /PORT
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(this->m_port);  // it stands for Host To Network Short 
    // inet_pton() : string to integer , 마지막 파라미터는 pointer로 sin_addr을 넘겨준다
    // pointer to number (inet_pton)
    inet_pton(AF_INET, this->m_ip_address, &hint.sin_addr);  
    
    // bind의 첫번째 파라미터는 fd (file descriptor)
    if(bind(this->m_socket, (struct sockaddr*)&hint, sizeof(hint)) == -1) {
        std::cerr << "bind() error: Can't bind to IP/PORT";
        return 2;
    }

    // 3. Mark the socket for listening in
    // 두번 째 파라미터는 몇개의 connection을 지정 -- SOMAXCONN 은 4096
    if(listen(this->m_socket, SOMAXCONN) == -1) {
        std::cerr << "listen() error: Can't listen";
        return 3;
    }

    // create the master file descriptor set and zero it
    FD_ZERO(&this->m_master);

    // add our first socket that we're interested in interacting with, the listening socket.
    // It's important that this socket is added for our server or else we won't 'hear' incoming connections
    FD_SET(this->m_socket, &this->m_master);

    return 0;
}

int TcpListener::run() {
    bool is_running = true;

    while(is_running) {
        // fd_set copy = this->m_master;

        // int socket_count = select(0, &copy, nullptr, nullptr, nullptr);

        // for(int i=0; i < socket_count; i++) {

        // }
        sockaddr_in client;
        socklen_t client_size = sizeof(client);
        char host[NI_MAXHOST];
        char svc[NI_MAXSERV];

        int client_socket = accept(this->m_socket, (struct sockaddr*)&client, &client_size);
        if(client_socket == -1) {
            std::cerr << "accept() error: client problem";
            return 4;
        }

        this->onClientConnected(client_socket);

        // clean 시키기. 이럴 때도 사용할 수가 있다
        memset(host, 0, NI_MAXHOST);
        memset(svc, 0, NI_MAXSERV);

        int result = getnameinfo( (struct sockaddr*)& client,
                                    sizeof(client),
                                    host,
                                    NI_MAXHOST,
                                    svc,
                                    NI_MAXSERV,
                                0);
        
        if(result) {
            std::cout << host << " connected on " << svc << std::endl;
        } else {
            // nemeric to string
            inet_ntop(AF_INET, &client.sin_addr, host, NI_MAXHOST);
            std::cout << host << " connected on " << ntohs(client.sin_port) << std::endl;
        }

        char buf[4096];
        // clear the buffer
        memset(buf, 0, 4096);

        for(;;) {
            // wait for a message
            int byte_recv_in = recv(client_socket, buf, 4096, 0);
            if(byte_recv_in == -1) {
                std::cerr << "There was a connection issue" << std::endl;
            } 

            if(byte_recv_in == 0) {
                std::cout << "The client disconneted" << std::endl;
                this->onClientDisconnected(client_socket);

            } else {
                this->onMessageReceived(client_socket, buf, byte_recv_in);
                // while receiving - display and echo message.
                
            
                // echo --- to send a message 
                send(client_socket, buf, byte_recv_in + 1, 0);

            }
        }

        // 5. close th listening socket
        close(client_socket);

    }

    return 0;
}


void TcpListener::sendToClient(int client_socket, const char* msg, int length) {
    send(client_socket, msg, length, 0);
}


void TcpListener::onClientConnected(int client_socket) {


}

// handlr for client disconnections
void TcpListener::onClientDisconnected(int client_socket) {

}

// handler for when a message is received from the client
void TcpListener::onMessageReceived(int client_socket, const char* msg, int byte_recv_in) {
    // display message
    std::cout << "Received message: " <<  std::string(msg, 0, byte_recv_in) << std::endl;
}