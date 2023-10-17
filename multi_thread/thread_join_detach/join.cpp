// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>
#include <chrono>

void threadRun(int x) {
    std::cout << "worker1 thread started." << std::endl;    
    for(int i=0; i < x; ++i) {
        std::cout << i << " worker1 thread working" << std::endl;    
    }

    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {
    
    std::thread worker1(threadRun, 5);  
    std::cout << "here main thread" << std::endl;

    // 위의 결과를 보면 thread에서 처리하는 내용을 기다려준다.
    worker1.join(); // join 으로 만들면 트레드; 여기에서는 worker1 쓰레드가 끝날 때까지 기다린다. 


    //// 추가사항
    // join를 여러번 할 경우도 있는 join 을 여러번 하게 되면 빌드는 잘 되지만 실행 중에 에러가 발생
    // std::system_error 로 발생함 -- two times join(double join)은 허용하지 않는다.
    // 그래서 join을 또 해야하는 경우(같은 함수를 사용하는 경우)
    // joinable() 함수를 사용해준다.

    //// after some code ...

    if(worker1.joinable()) {
        std::cout << "re join() now" << std::endl;
        worker1.join();
    }
    // 이렇게 하면 에러가 발생하지 않는다. (단, 새로 실행하게 해주는 것은 잘 모르겠음)

    std::cout << "Main Thread finished." << std::endl;
    return 0;
}