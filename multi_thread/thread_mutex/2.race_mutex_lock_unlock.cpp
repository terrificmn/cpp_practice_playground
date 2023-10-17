// Mutext : Mutual Exclusion
// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>
#include <chrono>
#include <mutex>

// mutex를 만들어준다
std::mutex mu;
int global_count = 0;

void add() {
    mu.lock();  // lock 을 한 후에  이후 unlock 을 해준다.
    // 다른 방식으로 unique_lock, lock_guard 등이 있다.
    std::cout << "worker thread started." << std::endl;    
    ++global_count; 
    mu.unlock();
}

int main() {
    // race condition . 자동차 경주 처럼; 같은 시간에 thread에 같은 데이터에 접근 하는 경우 (열심히 달려가는 상황)
    // 같은 데이터를 같은 시간에 접근해서 내용을 바꾸면 원치않은 결과가 나오거나 에러 발생할 수 있는데 
    // 이를 방지해주는 게 mutex 의 lock(), unlock() 을 이용해서 race condition를 방지해준다.

    // 여기에서는 전역변수 global_count 를 동시 접근하는 경우 발생
    // cpu 자체에서는 거의 동시에 접근한다고 해도 예를 1/1000000 등으로 차이가 나기 때문에 그 부분에 mutex 에서 lock, unlock을 해주게 된다
    // 쓰레드가 lock이 되어 있으면 다른 thread는 waiting을 하게 된다.
    std::thread worker1(add);  
    std::thread worker2(add);


    worker1.join();
    worker2.join();

    std::cout << "after joining thread finished, global_count: " << global_count << std::endl;
    std::cout << "Main Thread finished." << std::endl;
    return 0;
}