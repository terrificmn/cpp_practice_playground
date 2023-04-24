#include <stdio.h>

// 컴파일 
// gcc -o factor factor.c 

// sum all digits of a number
int sumDigits(int n) {
    int sum = 0;
    while(n > 0) {
        int m = n % 10;
        sum = sum + m;
        n = n /10;
    }

    return sum;
}


// sum all factors of a number
int sumFactors(int n) {
    int sum = 0;

    for(int i =1; i < n; ++i) {    /// 여기가 오류  마지막 n 값을 포함하지 않고 있다  (i <= n 이 되어야 함)
        if( n % i == 0) {
            sum += i;
        }
    }
    return sum;
}


int main(int argc, char** argv) {
    int number = 60;

    int sumf = sumFactors(number);
    int sumd = sumDigits(number);

    printf("sum of all factors: %d\n", sumf);
    printf("sum of all digits: %d\n", sumd);

    return 0;
}