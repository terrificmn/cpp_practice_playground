#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <string>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {

    /// port check
    if(argc != 3) {
        std::cerr << "you need to input ip and port: " << argv[0] << " <ip> <port>" << "\r\n";
        return 1;
    }

    /// create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        return 1;
    }

    /// create a hint structure for the server we're connecting with 
    std::string ip_address = argv[1];
    int port = atoi(argv[2]);
    
    sockaddr_in hint;
    hint.sin_family = AF_INET;
    hint.sin_port = htons(port);
    inet_pton(AF_INET, ip_address.c_str(), &hint.sin_addr);

    /// connect to the server on the socket
    int connect_result = connect(sock, (struct sockaddr*)&hint, sizeof(hint));
    if(connect_result == -1) {
        std::cerr << "connect() error: connection failed";
        return 1;
    }

    /// while loop
    char buf[4096];
    std::string user_input;

    do {
        /// 1. enter lines of text
        std::cout << "input> ";
        std::getline(std::cin, user_input); /// cin은 white 스페이스가 들어가도 입력이 끝이나게 됨
        // 그래서 전체 라인을 받는다. 한줄
        
        /// 2. send to server
        int send_result = send(sock, user_input.c_str(), user_input.size() +1, 0);  // +1을 더하는 이유는 c_str()로 변환하게 되면 마지막에 0이 포함되기 때문
        if(send_result == -1) {
            std::cerr << "send() error occured";
            continue;  // 프로그램 종료는 하지 않고, 다시 loop 진행
        }

        /// 3. wait for responese
        memset(buf, 0, 4096);
        int bytes_received = recv(sock, buf, 4096, 0);
        if(bytes_received == -1) {
            std::cerr << "error occured while receiving a message" << std::endl;
        } else {
            /// 4. display response
            std::cout << "SERVER> " << std::string(buf, bytes_received) << "\r\n";
        }

    } while(true);

    /// close the socket
    close(sock);

    return 0;
}