#include <iostream>
#include <thread>
#include <iostream>
#include <vector>
#include <chrono>
#include <mutex>

std::mutex g_lock;

int main() {

    auto wrongMyLambda = [](int x) {
        /// thread 에는 id가 있어서 확인할 수가 있다. join되면서 thread가 막 실행이 된다. 순서 상관 없이
        std::cout << "Lambda Thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "argument passed in is " << x << std::endl;
    };

    auto goodMyLambda = [](int x) {
        /// thread 에는 id가 있어서 확인할 수가 있다. 
        std::lock_guard<std::mutex> lock(g_lock); // lock_guard 를 사용하면  thread 를 보다 안전하게 사용할 수가 있다.
        std::cout << "Lambda Thread: " << std::this_thread::get_id() << std::endl;
        std::cout << "argument passed in is " << x << std::endl;
        
    };

    int thread_number = 5;
    std::vector<std::thread> v_threads;

    std::cout << "======= a bad example thread...,\n";
    for(int i=0; i < thread_number; ++i) {
        v_threads.push_back(std::thread(wrongMyLambda, 100+i));
    }

    for(auto& thread : v_threads) {
        thread.join();
    }
    v_threads.clear();

    std::cout << "\n\n======= wait for a good example thread...,\n";

    for(int i=0; i < thread_number; ++i) {
        v_threads.push_back(std::thread(goodMyLambda, 100+i));
    }

    for(auto& thread : v_threads) {
        thread.join();
    }
    v_threads.clear();


    std::cout << "Now hello from main thread." << std::endl;

    return 0;
}

// g++ -std=c++17 -o multiple_thread multiple_thread.cpp -lpthread