#include <iostream>
#include <memory>

class MClass {
public:
    MClass() {
        std::cout << "MClass created\n";
    }
    ~MClass() {
        std::cout << "MClass bye bye!\n";
    }
};


int main() {
    {
        // creating shared pointers.
        std::shared_ptr<MClass> ptr1 = std::make_shared<MClass>(); // heap memory 영역에 만들어진다.
        // 참고로 std::shared_ptr<MClass> ptr1(new MClass); 이렇게 new 키워드로 만드는 것과 동일하다. 위에 방법을 추천함
        {
            // in a new scope, in a pair of curl bracket, sharing the resource
            // 다른 shared_ptr을 만들고 공유할 ptr1을 지정해주면 된다. (unique_ptr은 이게 안됨)
            std::shared_ptr<MClass> ptr2 = ptr1;

            std::cout << "current use count :" << ptr2.use_count() << std::endl;
        }
        //ptr2 is freed. but ptr1 still survives
        std::cout << "current use count :" << ptr1.use_count() << std::endl;  // use_count()가 다 0이 되어야 없어진다.
    }   
    std::cout << "soon, the destructor call\n";

    return 0;
}