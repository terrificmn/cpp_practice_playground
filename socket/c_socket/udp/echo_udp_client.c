//  참고로... UPD 는 TCP처럼 연결 요청/수락이 없기 때문에 서버/클라이언트라고만 볼 수도 없다 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

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

    for(;;) {
        fputs("Insert message(q to quit): ", stdout);
        fgets(message, sizeof(message), stdin);
        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n")) {
            break;
        }

        sendto(sock, message, strlen(message), 0, 
                (struct sockaddr*)&server_addr, sizeof(server_addr));
            
        addr_size = sizeof(from_addr);
        str_len = recvfrom(sock, message, BUF_SIZE, 0, 
                            (struct sockaddr*)&from_addr, &addr_size);
        
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
