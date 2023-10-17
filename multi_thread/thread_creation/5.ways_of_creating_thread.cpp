// class 함수를 연결해주기, (Non-static member function)

// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>

class TestThread {
public:
    TestThread() { 
        std::cout << "TestThread created" << std::endl;
    }

    void threadTestFunction(int x) {
        std::cout << "worker1 (using Class::memberFunction) thread started." << std::endl;    
        for(int i=0; i < x; ++i) {
            std::cout << i << std::endl;    
        }
    }
};

int main() {
    
    // 클래스내의 멤버 메소드를 주소로 연결해주는 방법
    // 먼저 클래스 instance를 만들어준다.
    TestThread th;
    // ros의 콜백 함수 연결하는 방식과 비슷, 클래스 메소드 주소를 넘겨주고, 2번째 인자는 인스턴스(object) 주소를 넘겨준다. 
    // 그 이후는 계속 파라미터를 추가해줄 수가 있다(물론 클래스에서 정의 해줘야함)
    std::thread worker1(&TestThread::threadTestFunction, &th, 10);  
    worker1.join(); // join 으로 만들면 트레드; 여기에서는 worker1 쓰레드가 끝날 때까지 기다린다. 

    std::cout << "Thread finished." << std::endl;
    return 0;
}