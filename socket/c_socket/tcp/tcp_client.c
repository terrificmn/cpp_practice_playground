#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

// 전송되는 데이터의 경계가 (Boundary)가 존재하지 않는다

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char message[30];
    int str_len = 0;
    int idx=0, read_len=0;

    if(argc !=3) {
        printf("Usage : %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    // socket 생성  //Sock_stream 연결지향형
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }


    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family=AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    // client 에는 connect()가 있음
    if(connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        error_handling("connect() error");
    }

    // 서버에서 보내주는 데이터를 읽는다. 메세지의 카운트로 하나씩 read해보면 바이트만큼 함수가 호출되서 사용된다 
    while(read_len = read(sock, &message[idx++], 1)) {
        if(read_len == -1) {
            error_handling("read() error");
        }
        str_len += read_len;
    }

    printf("Message from server: %s \n", message);
    printf("Fuction read call count: %d \n", str_len);
    close(sock);

    return 0;
}

void error_handling(char* message) {
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}
