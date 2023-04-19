#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

// udp는 입출력 함수의 호출 횟수를 일치시켜야 한다  
// sendto()를 통해서 3번을 보냄


void error_handling(char* msg);

int main(int argc, char* argv []) {
    int sock;
    char msg1[] = "Hi";
    char msg2[] = "I'm another UDP host!";
    char msg3[] = "Hello world";

    char message[BUF_SIZE];

    struct sockaddr_in your_addr;
    socklen_t addr_size;
    
    if(argc != 3) {
        printf("Usage : %s <ip> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }

    memset(&your_addr, 0, sizeof(your_addr));
    your_addr.sin_family = AF_INET;
    your_addr.sin_addr.s_addr = inet_addr(argv[1]);
    your_addr.sin_port = htons(atoi(argv[2]));

    sendto(sock, msg1, sizeof(msg1), 0, 
            (struct sockaddr*)& your_addr, sizeof(your_addr));
    
    sendto(sock, msg2, sizeof(msg2), 0,
            (struct sockaddr*)& your_addr, sizeof(your_addr));

    sendto(sock, message, sizeof(msg3), 0,
            (struct sockaddr*)&your_addr, sizeof(your_addr));

    close(sock);

    printf("all message have been sent");
    return 0;

}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}