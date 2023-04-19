#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

void error_handling(char* msg);

int main(int argc, char* argv[]) {
    char* addr = "127.232.124.79";
    struct sockaddr_in addr_inet;

    // 변환된 ip주소를 구조체 sockaddr_in 의 in_addr 구조체 변수에 대입해줘야 하는데
    // inet_aton() 함수는 대입 과정을 가질 필요가 없다. arg로 in_addr 구조체 변수를 주소값을 전달해주면 된다 
    if(!inet_aton(addr, &addr_inet.sin_addr)) {
        error_handling("Conversion error");
    } else {
        printf("Network ordered integer addr: %#x\n", addr_inet.sin_addr.s_addr);
        return 0;
    }
}

void error_handling(char* msg) {
    fputs(msg, stderr);
    fputc('\n', stderr);
    exit(1);
}
