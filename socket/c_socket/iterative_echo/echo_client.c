#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 1024

void error_handling(char *msg);

int main(int argc, char* argv[]) {
    int sock;
    char message[BUF_SIZE];
    int str_len;
    struct sockaddr_in server_addr;

    if(argc != 3) {
        printf("Usage: %s <IP> <Port>\n", argv[0]);
        return 1;
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock, (struct sockaddr *)& server_addr, sizeof(server_addr)) == -1) {
        error_handling("connect() error");
    } else {
        puts("Conected...");
    }

    while(1) {
        fputs("Input mesage(Q to quit): ", stdout);
        fgets(message, BUF_SIZE, stdin);

        if(!strcmp(message, "q\n") || !strcmp(message, "Q\n")) {
            break;
        }

        write(sock, message, strlen(message));
        str_len =read(sock, message, strlen(message));
        message[str_len] =0;
        printf("Mesage from server: %s", message);
    }
    close(sock);

    return 0;
}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
