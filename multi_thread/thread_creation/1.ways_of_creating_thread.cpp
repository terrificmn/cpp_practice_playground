// function pointer, lambda function, class functor?
// 등으로 만들 수가 있다. 

// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>

void function1(int x) {
    std::cout << "worker1 thread started." << std::endl;    
    for(int i=0; i < x; ++i) {
        std::cout << i << std::endl;    
    }
}

int main() {
    // function pointer 방식, 첫 번째 아규먼트는 펑션포인터(이름), 그리고 그 함수에 들어가는 파라미터가 되겠다.
    std::thread worker1(function1, 10);  
    worker1.join(); // join 으로 만들면 트레드; 여기에서는 worker1 쓰레드가 끝날 때까지 기다린다. 

    std::cout << "Thread finished." << std::endl;
    return 0;
}