#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

static std::atomic<int> shared_value = 0;

/// mutex 의 lock/ unlock / lock_guard 없이 shared_value를 증가시킬 수 있다.
void sharedValueIncrement() {
    shared_value++;  // 중요 atomic 벨류는 ++ , += operator를 사용해야지 원하는 값이 나온다. 
    // shared_value = shared_value + 1; 
    // 대신 shared_value = shared_value +1 식으로 사용하면 안됨, 정확한 값이 안나오게 된다. (하지만, 업데이트가 되었는지 1000 의 값이 일정하게 나온다.)
}

int main() {
    std::vector<std::thread> threads;
    for(int i=0; i < 1000; i++) {
        threads.push_back(std::thread(sharedValueIncrement));
    }

    for(int i=0; i < 1000; i++) {
        threads[i].join();
    }

    std::cout << "shared_value: " << shared_value << std::endl;
    
    return 0;
}

// g++ -std=c++17 atomic.cpp -o atomic -l pthread