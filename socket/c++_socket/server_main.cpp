#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    if(argc != 2) {
        std::cerr << "you need to input port: " << argv[0] << " <port>" << std::endl;
        return 1;
    }
    // 1. create a socket
    int listening = socket(AF_INET, SOCK_STREAM, 0);
    if(listening  == -1) {
        std::cerr << "socket() error -- can't create a socket\n";
        return -1;
    }

    // 2. bind the socket to a IP /PORT
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(atoi(argv[1]));  // it stands for Host To Network Short 
    // inet_pton() : string to integer , 마지막 파라미터는 pointer로 sin_addr을 넘겨준다
    inet_pton(AF_INET, "0.0.0.0", &hint.sin_addr);  /// 0.0.0.0 은 any 이고, 자신으로 한정할려면 127.0.0.1 loop
    // 다른 방법으로 hint.sin_addr.s_addr 에 값을 지정하는 방법도 있다 
    // 예: hint.sin_addr.s_addr = htonl(INADDR_ANY);  // address to accept any incoming messages
    
    // bind의 첫번째 파라미터는 fd (file descriptor)
    if(bind(listening, (struct sockaddr*)&hint, sizeof(hint)) == -1) {
        std::cerr << "bind() error: Can't bind to IP/PORT";
        return -2;
    }

    std::cout << "Now listening..." << std::endl;
    
    // 3. Mark the socket for listening in
    // 두번 째 파라미터는 몇개의 connection을 지정 -- SOMAXCONN 은 4096
    if(listen(listening, SOMAXCONN) == -1) {
        std::cerr << "listen() error: Can't listen";
        return -3;
    }

    // 4 Accept a call
    sockaddr_in client;
    socklen_t client_size = sizeof(client);
    char host[NI_MAXHOST];
    char svc[NI_MAXSERV];

    int client_socket = accept(listening, (struct sockaddr*)&client, &client_size);
    if(client_socket == -1) {
        std::cerr << "accept() error: client problem";
        return 4;
    }

    close(listening);

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
    while(1) {
        // clear the buffer
        memset(buf, 0, 4096);

        // wait for a message
        int bytes_recv = recv(client_socket, buf, 4096, 0);
        if(bytes_recv == -1) {
            std::cerr << "There was a connection issue" << std::endl;
            break;
        } 

        if(bytes_recv == 0) {
            std::cout << "The client disconneted" << std::endl;
            break;
        }

        // while receiving - display and echo message.
        // display message
        std::cout << "Received message: " <<  std::string(buf, 0, bytes_recv) << std::endl;
        
        // echo --- to send a message 
        send(client_socket, buf, bytes_recv + 1, 0);
    }

    // 5. close th listening socket
    close(client_socket);
    
    /// man socker 터미널에 입력해서 볼수가 있다 (터미널에서 메뉴얼로 제공하는 것은)
    /// getnameinfo, memset 등이 있다 -- 굿!! 도움이 많이 된다 
    /// 최종적으로 클라이언트는 telnet으로 대신할 수가 있다  
    /// 다른 터미널을 열어서  telnet localhost <포트번호> 를 입력하면 된다 
    return 0;
}