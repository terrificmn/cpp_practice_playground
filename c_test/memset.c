#include <stdio.h>
#include <string.h>

int main() {
    char str[40] = "Hello world, Hi there, again~ Hello";
    printf("---plain str print: %s\n", str);

    memset(str + 13, '.', 8*sizeof(char));
    printf("---after memset: %s\n", str);
    return 0;
}

// char 자체가 포인터 이므로 그 값을 줄 수가 있고, 0 부터 +13번째로 부터 '.'을 넣어주는데    
// char는 1byte 이므로 총 8개의 값을 block 으로 지정해준다 