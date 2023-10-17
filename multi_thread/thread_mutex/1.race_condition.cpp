// Mutext : Mutual Exclusion
// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>
#include <chrono>

int global_count = 0;

void add() {
    std::cout << "worker thread started." << std::endl;    
    ++global_count;
}

int main() {
    // race condition . 자동차 경주 처럼; 같은 시간에 thread에 같은 데이터에 접근 하는 경우를 말한다 (열심히 달려가는 상황)
    // 같은 데이터를 같은 시간에 접근해서 내용을 바꾸면 원치않은 결과가 나오거나 에러 발생할 수 있는데 
    // 이를 방지해주는 게 mutex 의 lock(), unlock() 을 이용해서 race condition를 방지해준다.

    // 여기에서는 전역변수 global_count 를 동시 접근하는 경우 발생- 예제가 조금 애매하지만,,
    // 조금 더 상황에 대한 이해는 mutex_lock_guard.cpp 또는 mutex_unique_lock.cpp 를 보자.
    std::thread worker1(add);  
    std::thread worker2(add);

    worker1.join();
    worker2.join();

    std::cout << "after joining thread finished, global_count: " << global_count << std::endl;
    std::cout << "Main Thread finished." << std::endl;
    return 0;
}