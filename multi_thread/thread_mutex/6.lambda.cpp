#include <iostream>
#include <thread>

int main() {
    auto myLambda = [](int x) {
        std::cout << "lambda thread" << std::endl;
        std::cout << "argument passed in: " << x << std::endl;
    };

    std::thread myThread(myLambda, 100);
    myThread.join();

    std::cout << "hello from my main thread" << std::endl;
    
    return 0;
}