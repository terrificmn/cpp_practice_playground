#include <memory>
#include <iostream>

class PointerTest {
public:
    PointerTest() {
        std::cout << "init PointerTest class" << std::endl;
    }
    ~PointerTest() {
        std::cout << "destructed PointerTest class" << std::endl;
    }
    void TestCout() {
        std::cout << "TestCout is called" << std::endl;
    }
};

int main(int argc, char** argv) {
    
    // 최초 new로 클래스를 인스턴스로 생성
    std::shared_ptr<PointerTest> ptr1(new PointerTest);

    // 
    std::cout << "Counter: " << ptr1.use_count() << std::endl;

    {
        // 대상을 포인팅 (new로 만드는 것이 아니라, ptr1을 지정)
        std::shared_ptr<PointerTest> ptr2(ptr1);
        std::cout << "Counter: " << ptr1.use_count() << std::endl;
        ptr2->TestCout();
    }
    // 블럭을 벗어나면 소멸된다

    // counter도 1이 된다 
    std::cout << "Counter: " << ptr1.use_count() << std::endl;
    ptr1->TestCout();

    // 아직 포인터 포인트가 남아 있기 때문에, 0이 되기 전에는 아직 소멸이 안 된다

    std::cout << "======== main end." << std::endl;
    // 카운터가 0 이 되면 smart pointer가 소멸된다. 
    return 0;
}