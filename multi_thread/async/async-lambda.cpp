#include <iostream>
#include <future>
#include <thread>
#include <chrono>

// asyncMessage()를 호출하면 asycn로 실행됨
class MyAsync {
public:
    std::future<void> asyncMessage(const std::string& msg) {
        // 람다 함수로 바로 async 실행 리턴
        return std::async(std::launch::async, [msg]() {
            std::cout << "msg from main thread: " << msg << std::endl;
            std::cout << "asyncMessage method started\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        });
    }
};

/// 람다 함수를 사용하면서 호출처럼 사용할 수 있다.



// 첨고: 쓰레드 람다
// std::thread([msg]() {
    // do something
// }).detach();

int main() {

    /// 만약 람다함수에서 std::future<> 없이 사용을 하게 된다면...
    /// std::async(std::launch::async, []() { /*do something*/ });
    /// asyncronous 로 작동을 하지 않고 blocking을 함에 주의하자

    // async로 실행을 하면 std::future를 리턴해주는데 이를 없이 사용하게 되면 block 이 되는 것 같다. async가 thread policy로 제대로 작동이 안되는 듯 함
    std::future<void> future = std::async(std::launch::async, []() {
        std::cout << "asynchronous thread started\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
        std::cout << "asynchronous thread ended\n";
    });

    while(true) {
        std::cout << "main thread: while loop started..." << std::endl;
        MyAsync myAsync;

        /// [중요] 여기 클래스도 마찬가지이다. std::future를 받지 않는다면 함수 안에서는 바로 async로 실행되어 리턴을 하지만
        // 리턴을 받지않고 아래 처럼 사용하면 block이 된다
        // myAsync.asyncMessage("async method call"); // 다시 확인할 때 주석풀고 테스트해보자
        std::future<void> asynMessageFuture = myAsync.asyncMessage("async method call");

        std::this_thread::sleep_for(std::chrono::milliseconds(3000));
        std::cout << "3 seconds passed." << std::endl;
        break;
    }

    std::cout << "main thread end" << std::endl;
    return 0;
}

// g++ -std=c++14 -o async-lambda async-lambda.cpp 