#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30
// 전송되는 데이터의 경계가 (Boundary)가 존재하지 않는다

void error_handling(char *msg);

int main(int argc, char *argv[]) {
    int server_sd, client_sd;
    FILE* fp;
    char buf[BUF_SIZE];
    int read_cnt;

    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    if(argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    // file open
    fp = fopen("send_file", "rb");
    // socket 생성  //Sock_stream 연결지향형
    server_sd = socket(PF_INET, SOCK_STREAM, 0);

    if(server_sd == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    bind(server_sd, (struct sockaddr*)& server_addr, sizeof(server_addr));
    listen(server_sd, 5);

    client_addr_size = sizeof(client_addr);
    client_sd = accept(server_sd, (struct sockaddr*)& client_addr, &client_addr_size);

    while(1) {
        read_cnt = fread((void*)buf, 1, BUF_SIZE, fp);
        if(read_cnt < BUF_SIZE) {
            write(client_sd, buf, read_cnt);
            break;
        }
        write(client_sd, buf, BUF_SIZE);
    }

    printf("shutdown write stream...\n");
    shutdown(client_sd, SHUT_WR);  // 출력 스트림 닫기 
    // 클라이언트 쪽에는 종료를 알리는 EOF가 전송되게 된다 단, 아직 입력 스트림 열려 있으므로   
    // 클라이언트에서 파일을 받고 나서 메세지를 보내면 서버는 그 메세지를 받을 수 있게 된다 
    read(client_sd, buf, BUF_SIZE);
    printf("Message from client: %s\n", buf);

    fclose(fp);
    close(client_sd);
    close(server_sd);

    return 0;
}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
