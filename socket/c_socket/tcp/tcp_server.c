#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int serv_sock;
    int client_sock;

    struct sockaddr_in serv_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    char message[]="Hello World";

    if(argc !=2) {
        printf("Usage : %s <port>\n", argv[0]);

        exit(1);
    }

    // socket 생성
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(serv_sock == -1) {
        error_handling("socket() error");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    // ip와 포트를 bind 해줌
    if(bind(serv_sock, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind() error");
    
    // listen 하고 있는 상태
    if(listen(serv_sock, 5) == -1)
        error_handling("listen() erorr");

    client_addr_size = sizeof(client_addr);
    // 연결 수락
    client_sock = accept(serv_sock, (struct sockaddr*)&client_addr, &client_addr_size);

    if(client_sock == -1) 
        error_handling("accept() error");

    write(client_sock, message, sizeof(message));
    close(client_sock);
    close(serv_sock);

    return 0;
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
