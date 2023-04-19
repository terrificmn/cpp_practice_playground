#include <memory>
#include <iostream>

/// 배열로 smartpointer 인 shared_ptr를 만들었을 경우에는 
// 처음 만들 때 삭제시킬 수 있는 함수를 만들어서 같이 등록해준다

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


// share_ptr를 삭제하기 위해서 함수를 만들어서 실제 클래스 주소를 넘겨서 delete할 수 있다
void removePointer(PointerTest *ptrPointerTest) {
    std::cout << "removePointer() has been called" << std::endl;

    // delete array
    delete [] ptrPointerTest;
}

int main(int argc, char* argv[]) {

    // array로 선언된 인스턴스는 삭제할 수 있도록 , 별도록 함수를 같이 넘겨준다 
    // 깔끔하게 array를 삭제해준다 
    std::shared_ptr<PointerTest> ptr1(new PointerTest[3], removePointer);

    
    // std::shared_ptr<PointerTest> ptr1(new PointerTest[3]);
    // std::cout << "Counter: " << ptr1.use_count() << std::endl;
    // 카운터는 여전히 1 이지만, 배열로 선언이 되었기 때문에 destructor가 한번 수행 한 후   
    // core dumped 하며 치명적 에러가 발생한다
    // munmap_chunk(): invalid pointer
    // Aborted (core dumped)


    // 직접 삭제할 경우에는 reset()함수를 사용한다
    // main 함수가 끝나기 전에 깔끔하게 즉시 삭제해준다
    // ptr1.reset();

    std::cout << "main end-------." << std::endl;

    return 0;
}

