// Lambda function, 


// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>



int main() {
    
    // function pointer를 사용하는 방법과 동일하며, 람다 스스로 함수를 정의하므로 따로 함수를 만들 필요는 없다. 
    auto functionLambda = [](int x) { 
        std::cout << "worker1 thread started." << std::endl;    
        for(int i=0; i < x; ++i) {
            std::cout << i << std::endl;    
        }
    };

    std::thread worker1(functionLambda, 10);  
    worker1.join(); // join 으로 만들면 트레드; 여기에서는 worker1 쓰레드가 끝날 때까지 기다린다. 

    std::cout << "Thread finished." << std::endl;
    return 0;
}