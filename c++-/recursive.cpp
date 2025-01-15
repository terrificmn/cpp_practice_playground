#include <iostream>

int myCountdown(int n) {
    
    // 1. recursive을 하려면 base 컨디션이 있어야 한다. 그래서 최종 마무리가 될 수 있게 한다.
    if(n == 0) {
        std::cout << "countdown done. " << std::endl;
        return 0;
    }

    /// 2. recuresive 로 다시 한번 함수를 실행한다.
    std::cout << n << std::endl;
    return myCountdown(n-1);
}


int main() {

    myCountdown(10);

    /// IMPORTANT:
    // recursive function으로 사용할 때는 주의해야하는 것이 너무 큰 수를 넘기게 되면
    // stackoverflow가 발생한다. 함수들은 stack frame 에 쌓이게 되는데 recursive로 계속 함수를 call 하게 되면 계속 쌓이게 되면서 stack이 꽉 차게 된다.
    // 주석 해제해서 확인
    // myCountdown(1000000);

    return 0;
}

// g++ -std=c++17 -o recursive recursive.cpp