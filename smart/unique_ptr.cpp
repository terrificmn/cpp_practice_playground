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


int main() {
    std::unique_ptr<PointerTest> myUniquePtr(new PointerTest);

    // shared_ptr 방식으로 다른 인스턴스에 포인팅 해줄 수 없다 -- 바로 컴파일 에러
    // std::unique_ptr<PointerTest> myUniquePtr2(myUniquePtr2);

    // unique_ptr은 하나의 인스턴스에 하나의 포인터만 존재한다.
    // 그래서 애초에 여러 포인터가 하나의 대상을 가리킬 수 없게 되어 있다 

    return 0;
}