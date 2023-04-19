#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024
#define OPSZ 4

void error_handling(char *msg);
int calculate(int op_num, int opnds[], char oprator);

int main(int argc, char* argv[]) {
    int server_sock, client_sock;
    char op_info[BUF_SIZE];
    int result, opnd_cnt, i;
    int recv_cnt, recv_len;

    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;

    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_sock = socket(PF_INET, SOCK_STREAM, 0);
    if(server_sock == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET,
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(atoi(argv[1]));

    if(bind(server_sock, (struct sockaddr*)& server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind() error");
    }

    if(listen(server_sock, 5) == -1) {
        error_handling("listen() error");
    }

    client_addr_size = sizeof(client_addr);

    // 5번 연결을 받음
    for(i = 0; i<5; i++) {
        client_sock = accept(server_sock, (struct sockaddr*)& client_addr, &client_addr_size);
        // read 개수
        read(client_sock, &opnd_cnt, 1);

        recv_len =0;

        if(client_sock == -1) {
            error_handling("accept() error");
        } else {
            printf("connected client %d\n", i+1);
        }

        while((opnd_cnt * OPSZ + 1) > recv_len) {
            recv_cnt = read(client_sock, &op_info[recv_len], BUF_SIZE -1);
            recv_len += recv_cnt;
        }

        result = calculate(opnd_cnt, (int*)op_info, op_info[recv_len -1]);
        write(client_sock, (char*)&result, sizeof(result)); 
        close(client_sock);
    }

    close(server_sock);
    return 0;

}

int calculate(int op_num, int opnds[], char oprator) {
    int result = opnds[0], i;
    
    switch(oprator) {
        case '+':
            for(i=1; i< op_num; i++) {
                result += opnds[i];
            }
            break;
        case '-':
            for(i=1; i< op_num; i++) {
                result -= opnds[i];
            }
            break;
        case '*':
            for(i=1; i< op_num; i++) {
                result *= opnds[i];
            }
            break;
    //     default:
    //         result = 0;
    }

    return result;
}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}


