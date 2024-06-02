#include <iostream>
#include <future>
#include <thread>
#include <chrono>

class MyAsync {
public:
    void sub() {
        std::cout << "Starting sub method" << std::endl;

        // Launch the serve method asynchronously
        auto serveFuture = std::async(std::launch::async, &MyAsync::serve, this);

        // Do some other work in sub method if needed
        std::this_thread::sleep_for(std::chrono::seconds(5));  // Simulate a long-running task

        // Wait for the serve method to finish
        serveFuture.get();

        std::cout << "Finished sub method" << std::endl;
    }

    void serve() {
        std::cout << "Starting serve method" << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));  // Simulate a long-running task
        std::cout << "Finished serve method" << std::endl;
    }
};

int main() {
    MyAsync myAsync;
    std::future mySubAsync = std::async(std::launch::async, &MyAsync::sub, &myAsync);
    // myAsync.sub();

    /// myAsync 클래스의 sub 함수를 먼저 async로 실행을 시키고 
    // sub 함수에서는 다시 serve 함수를 async로 실행을 시키는데, 이 둘 다 모두 blocking 없이 둘 다 asynchronously 작동
    // main에서도 위의 둘이 끝날 때까지 기다리는 것이 아니라 바로 while 바로 시작 됨.
    
    while(true) {
        std::cout << "main thread: while loop started..." << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));  // Simulate a long-running task
        break;
    }

    return 0;
}

// g++ -std=c++14 -o two-async-async two-async-async.cpp 