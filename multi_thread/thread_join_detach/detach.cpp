// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>
#include <chrono>

void threadRun(int x) {
    std::cout << "worker1 thread started." << std::endl;    
    for(int i=0; i < x; ++i) {
        std::cout << i << " worker1 thread working" << std::endl;    
    }
    
    std::this_thread::sleep_for(std::chrono::seconds(5));
}

int main() {
    
    std::thread worker1(threadRun, 5);  
    std::cout << "here main thread" << std::endl;

    // detach 는 parent thread 에 붙일 때 사용하며, join과 다르게 끝날 때까지 기다려 주지 않는다.
    // 여기에서 parent thread는 main 함수가 되겠다. 
    worker1.detach();
    // 위의 함수에서 5초를 기다려야 하는데, 5초는 고사하고, main 함수가 마지막의 return 0를 만나기 전에   
    // 시작이 안 될 경우에는 아예 thread로 만든 worker1의 기능은 볼 수 조차 없게 된다.

    /////////////////////////////////////참고 1
    // std::this_thread::sleep_for(std::chrono::seconds(5)); // 오히려 main 이 끝나기 전에 딜레이를 주면 thread worker1 이 제대로 작동

    /////////////////////////////////////참고 2
    // join 과 마찬가지로 double detach()는 에러를 발생시킴
    // worker1.joinable()를 사용한다. if(worker1.joinable())

    /////////////////////////////////////참고 3
    // join(), detach() 이든 destructor가 작동을 하면서 처음 std::thread 로 만들어지는 순간, thread가 joinable 인지 체크 하기 때문에 
    // thread가 만들어지는 순간 joinable로 상태가 된다. 이후 join/detach를 하게 되면 non-joinable이 된다. 
    // non-joinable 이라면 바로 terminate가 된다.
    std::cout << "Main Thread finished." << std::endl;
    return 0;
}