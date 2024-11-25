#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <atomic>

class AsyncWorker {
public:
    AsyncWorker() : running_(false) {}
    
    // Function that will run in async
    void asyncFunction() {
        running_ = true;
        while (running_) {
            std::cout << "Async function working...\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }
    
    // Start the async operation
    std::future<void> startAsync() {
        return std::async(std::launch::async, &AsyncWorker::asyncFunction, this);
    }
    
    // Stop the async operation
    void stop() {
        running_ = false;
    }

private:
    std::atomic<bool> running_;
};

// Function that will run in the separate thread
void threadFunction(AsyncWorker& worker) {
    // Start the async operation
    auto future = worker.startAsync();
    
    // Do other work in the thread
    for (int i = 0; i < 5; ++i) {
        std::cout << "Thread function working...\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    
    // Stop the async operation
    worker.stop();
    
    // Wait for the async operation to complete
    future.wait();
}

int main() {
    AsyncWorker worker;
    
    // Create and start the thread
    std::thread t(threadFunction, std::ref(worker));
    
    // Wait for the thread to complete
    t.join();
    
    std::cout << "All operations completed.\n";
    return 0;
}


// g++ -std=c++17 -o thread_n_async thread_and_async_example.cpp

// 아무래도 위의 예제에서는 thread 함수가 무한 루프가 아니고 std::future 로 async로 한번 함수를 실행하게 되면   
// 서로 block이 안되고 잘 작동이 된다. 
// 단 thread 가 무한루프이게 되면 async가 계속 또 실행이 될 수가 있으므로 이렇게 되면 제대로 결과가 안 나온다. 
// block 되거나 이상한 결과가 나오게 된다. 
// 그리고 async 함수를 실행할 때에는 std::future 로 결과를 받아 주는게 좋다. (void 라도)
// 단, future에서 .get() / .wait() 를 사용하게 되면 block이 된다. 
