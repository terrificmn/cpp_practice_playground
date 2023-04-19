#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    unsigned short host_port = 0x1234;
    unsigned short net_port;
    unsigned long host_addr = 0x12345678;
    unsigned long net_addr;

    // 값을 메모리에 저장할 때
    // intel amd 계열은 리틀 엔디안 기준 - 최상위 바이트에(처음) 마지막 데이터가 저장됨
    // 위의 경우라면 0x34, 0x12 . 최하위 바이트(마지막)
    // 벡 엔디안으로 통일하기로 함 (빅 엔디안은 최상위 바이트(처음) 0x12, 처음 데이터가 저장되는 순서..)

    // 그래서 바이트를 변환해줄 수 있다
    // host byte 순서에서 network byte 순서 방식으로 변환 short
    net_port = htons(host_port);
    // host byte 순서에서 network byte 순서 방식으로 변환 long
    net_addr = htonl(host_addr);

    printf("Host ordered port: %#x\n", host_port);
    printf("Converted Network ordered port: %#x\n", net_port);
    printf("Host ordered address: %#lx\n", host_addr);
    printf("Converted Network ordered address: %#lx\n", net_addr);

    // 다행히 변환 과정은 자동으로 이뤄진다고 함. 그래서 sockadd_in 구조체 변수에 값을 넣어줄 때 바이트 순서가 상관없다
    return 0;
}