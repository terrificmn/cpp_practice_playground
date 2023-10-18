// Functor (Function Object)
// class 자체를 연결해줄 수가 있음. 람다와도 비슷하며, operator를 사용
// operator() 는 funtion call operator 라고 하며  함수를 콜 할 때 하는 기능을 overload 해서 사용하게 해준다. 

// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>

class TestThread {
public:
    // 이 아래 operator () 를 이용해서 object를 만들게 되면 이는 callable object가 된다.
    void operator ()(int x) {
        std::cout << "worker1 (using Functor) thread started." << std::endl;    
        for(int i=0; i < x; ++i) {
            std::cout << i << std::endl;    
        }
    }
};

int main() {
    
    // thread를 만들 때, functor를 넘겨준다.
    std::thread worker1(TestThread(), 10);  
    worker1.join(); // join 으로 만들면 트레드; 여기에서는 worker1 쓰레드가 끝날 때까지 기다린다. 

    std::cout << "Thread finished." << std::endl;
    return 0;
}