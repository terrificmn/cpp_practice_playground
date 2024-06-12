// class 함수를 Static 연결해주기 (static member function) 

// static 함수는 메모리에 처음 한번 올라가면 계속 지속 되는 것을 말함. (키워드 static 을 맨 앞에 넣어준다)
// 하나의 object로 생각하면 될 듯하다.

// 이런 특징이 있다
    // A static member function is independent of any object of the class. 
    // A static member function can be called even if no objects of the class exist.
    // A static member function can also be accessed using the class name through the scope resolution operator.
    // A static member function can access static data members and static member functions inside or outside of the class.
    // Static member functions have a scope inside the class and cannot access the current object pointer.
    // You can also use a static member function to determine how many objects of the class have been created.

// thread를 여러개를 만들면 꼭 순서대로 실행되지는 않는다. 
#include <thread>
#include <iostream>

class TestThread {
public:
    TestThread() { 
        std::cout << "TestThread created" << std::endl;
    }

    static void threadStaticFunction(int x) {
        std::cout << "worker1 (static member of class) thread started." << std::endl;    
        for(int i=0; i < x; ++i) {
            std::cout << i << std::endl;    
        }
    }
};

int main() {
    
    // 클래스내의 static 멤버 메소드를 주소로 연결
    // static 이므로 인스턴스(오브젝트)를 만들어줄 필요는 없다.
    
    // 사용하려는 클래스의 static 멤버 함수 주소만 연결해주게 된다.
    // 그 이후는 계속 파라미터를 추가해줄 수가 있다(물론 클래스에서 정의 해줘야함)
    // static 멤버함수 이므로 다이렉트로 불러서 사용할 수가 있다
    std::thread worker1(&TestThread::threadStaticFunction, 10);  
    worker1.join(); // join 으로 만들면 트레드; 여기에서는 worker1 쓰레드가 끝날 때까지 기다린다. 

    std::cout << "Thread finished." << std::endl;
    return 0;
}