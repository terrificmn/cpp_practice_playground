#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

// server는 기존의 echo_udp_server.c 의 udp_s 를 사용하면 된다 

void error_handling(char* msg);

int main(int argc, char* argv []) {
    int sock, str_len;
    char message[BUF_SIZE];
    socklen_t addr_size;

    struct sockaddr_in server_addr, from_addr;
    if(argc != 3) {
        printf("Usage : %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // connect함수로 연결해서 주소로 UDP도 주소 정보를 등록할 수 있다
    // connect를 사용하게 되면 함수가 호출될 때마다 전송의 과정만 있게 됨
    // sendto, recvfrom 대신 write, read 로도 데이터 송수신 가능함
    connect(sock, (struct sockaddr*)& server_addr, sizeof(server_addr));
    for(;;) {
        fputs("Insert message(q to quit): ", stdout);
        fgets(message, sizeof(message), stdin);
        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n")) {
            break;
        }

        // 기존의 sendto()방식, udp는 1. udp 소켓의 ip, port 등록, 2 데이터 전송. 3 udp소켓의 등록된 ip정보 삭제
        // 이 순서로 사용이 되어짐, 대신 위에서 connect 함수를 사용했기 때문에 tcp처럼 주소가 등록이 된다 
        // 그래서 ip,port 등록은 한번만 하고 바로 데이터 전송만 하게 됨
        // sendto(sock, message, strlen(message), 0, 
        //         (struct sockaddr*)&server_addr, sizeof(server_addr));

        write(sock, message, strlen(message));

            
        // addr_size = sizeof(from_addr);
        // str_len = recvfrom(sock, message, BUF_SIZE, 0, 
        //                     (struct sockaddr*)&from_addr, &addr_size);

        // 위오 마찬가지로 recvfrom 대신에 read()함수를 사용할 수 있게 된다 
        str_len = read(sock, message, sizeof(message)-1);
        
        message[str_len] = 0;
        printf("Message from UDP server: %s", message);
    }

    close(sock);
    return 0;

}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
