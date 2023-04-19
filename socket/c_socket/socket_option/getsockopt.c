#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>

void error_handling(char* msg);

int main(int argc, char *argv[]) {
    int tcp_sock, udp_sock;
    int sock_type, state;
    socklen_t opt_len;
    
    opt_len = sizeof(sock_type);
    tcp_sock = socket(PF_INET, SOCK_STREAM, 0);
    udp_sock = socket(PF_INET, SOCK_DGRAM, 0);
    printf("defined SOCK_STREAM: %d\n", SOCK_STREAM);
    printf("defined SOCK_DGRAM: %d\n", SOCK_DGRAM);

    state = getsockopt(tcp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &opt_len);
    // socket의 타입정보를 얻을 수 있는데 이는 처음에 socket을 만들 때 파라미터 중 .TCP/ UDP를 선택해서 넣어준 값을 리턴해준다
    // SO_TYPE을 넣어서 socket 타입을 알 수 있다 
    

    if(state) {
        error_handling("getsockopt() error");
    }

    // 위의 getsockopt()함수로 리턴된 SOCK_STREAM 또는 SOCK_DGRAM 임을 알 수가 있다. 
    printf("first socket type: %d\n", sock_type);

    state = getsockopt(udp_sock, SOL_SOCKET, SO_TYPE, (void*)&sock_type, &opt_len);
    if(state) {
        error_handling("getsockopt() error");
    }
    printf("second socket type: %d\n", sock_type);
    return 0;
}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
