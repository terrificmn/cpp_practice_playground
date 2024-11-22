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