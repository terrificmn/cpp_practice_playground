#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
    struct sockaddr_in addr1, addr2;
    char* str_ptr;
    char str_arr[20];

    addr1.sin_addr.s_addr = htonl(0x1020304);
    addr2.sin_addr.s_addr = htonl(0x1010101);

    str_ptr = inet_ntoa(addr1.sin_addr);
    // 변환된 값은 포인터 주소 이므로, 다음에 inet_ntoa가 호출되면 다른 주소로 바뀔 수도 있다 
    // 그래서 strcpy()를 해준다
    strcpy(str_arr, str_ptr);
    printf("Dotted-Decimal notation1: %s \n", str_ptr);

    inet_ntoa(addr2.sin_addr);
    // 한번 더 호출이 되어서 다른 값으로 저장이 됨
    printf("Dotted-Decimal notation2 -ptr: %s \n", str_ptr);

    // 포인터에 받은 값을 미리 저장해뒀기 때문에 위의 str_ptr의 주소값이 변경되어도 상관이 없다 (char형 포인터)
    printf("Dotted-Decimal notation3 -str_arr: %s \n", str_arr);

    return 0;
}