//  참고로... UPD 는 TCP처럼 연결 요청/수락이 없기 때문에 서버/클라이언트라고만 볼 수도 없다 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#define BUF_SIZE 30

// udp는 입출력 함수의 호출 횟수를 일치시켜야 한다  
// sendto()를 통해서 보내온 (bound_host2)에서 온 것은 recvfrom()으로 역시 3번 반복하고 있다  


void error_handling(char* msg);

int main(int argc, char* argv []) {
    int sock, str_len;
    char message[BUF_SIZE];
    socklen_t addr_size;

    struct sockaddr_in my_addr, your_addr;
    if(argc != 2) {
        printf("Usage : %s <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(PF_INET, SOCK_DGRAM, 0);
    if(sock == -1) {
        error_handling("socket() error");
    }

    memset(&my_addr, 0, sizeof(my_addr));
    my_addr.sin_family = AF_INET;
    my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    my_addr.sin_port = htons(atoi(argv[1]));

    if(bind(sock, (struct sockaddr*)&my_addr, sizeof(my_addr)) == -1) {
        error_handling("bind() error");
    }

    for(int i=0; i<3; i++) {
        sleep(5);
        addr_size = sizeof(your_addr);
        str_len = recvfrom(sock, message, BUF_SIZE, 0, 
                            (struct sockaddr*)&your_addr, &addr_size);

        printf("Message: %d, %s \n", i+1, message);

    }

    close(sock);
    return 0;

}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
