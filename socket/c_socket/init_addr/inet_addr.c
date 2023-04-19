#include <stdio.h>
#include <arpa/inet.h>

// 문자열 정보를 네트워크 바이트 순서 정수 변환 (32bit integer로 변환해야함)
// ip주소는 32비트의 4바이트 이므로..
// inet_addr() 함수는 
// 문자열 32비트 형태를 32비트 integer로 변환해주는 함수가 되겠다. 그러면서 동시에 네트워크 바이트 순서로 맞춰준다  

int main(int argc, char* argv[]) {
    char* addr1 = "1.2.3.4";
    char* addr2 = "1.2.3.256";

    unsigned long conv_addr = inet_addr(addr1); // integer 로 변환하면서 network byte로 순서로 변환해줌
    if(conv_addr == INADDR_NONE) {
        printf("Error occured");
    } else {
        printf("Network ordeded integer addr: %#lx\n", conv_addr);
    }

    // 1byte 최대는 255 까지 표현
    // inet_addr()을 유효하지 않은 ip 주소 오류 검출도 하게 됨
    conv_addr = inet_addr(addr2);
    if(conv_addr == INADDR_NONE) {
        printf("Error occured\n");
    } else {
        printf("Network ordeded integer addr: %#lx\n", conv_addr);
    }

    return 0;
}