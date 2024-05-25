#include <iostream>
#include <future>

int square(int x) {
    return x*x;
}

int main() {
    std::future<int> asyncFunction = std::async(&square, 12);
    // 결과는 (return) future에 저장된다

    for(int i=0; i< 10; i++) {
        std::cout << square(i) << std::endl;
    }

    // we are blocked at the 'get()' operation, until our result has computed.. (thread 의 join() 과 비슷하다고 할 수 있다.)
    // 그 동안 async로 작업이 진행
    int result = asyncFunction.get();

    std::cout << "result: " << result << std::endl;

    return 0;
}