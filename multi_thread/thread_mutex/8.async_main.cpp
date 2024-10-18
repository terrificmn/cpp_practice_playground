#include <iostream>
#include <future>
#include <thread>
#include <chrono> 

bool bufferedFileLoader() {
    size_t bytes_loaded = 0;
    while(bytes_loaded < 20000) {
        std::cout << "thread: loading file..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
        bytes_loaded += 1000;
    }
    return true;

}
int main() {
    // policy를 async 로 만듬..
    std::future<bool> backgroundThread = std::async(std::launch::async, bufferedFileLoader);

    std::future_status status;

    // 결과는 (return) future에 저장된다

    while(true) {
        std::cout << "main thread is running" << std::endl;
        // artificial sleep for our program
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        status = backgroundThread.wait_for(std::chrono::milliseconds(1));  // literally, wait for the result

        // if our data is ready, that is, our background thread has completed..
        if(status == std::future_status::ready) {
            std::cout << "Our data is ready..." << std::endl;
            break;
        }
    }

    std::cout << "Programd is complete" << std::endl;

    return 0;
}

/// backgroundThread 가 future로 받아지면, .get() 함수를 이용해서 결과 값을 받을 수 있다. 
// 예: if(backgroundThread.get())

// g++ -o async async_main.cpp -lpthread