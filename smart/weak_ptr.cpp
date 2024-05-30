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

/// weak 포인터는 non-woning pointer
// It does not increase the reference count.
// 'SAFER" way to have dargling pointer -- break cycles

int main() {
    std::weak_ptr<MClass> ptr2;
    {
        // creating shared pointers.
        std::shared_ptr<MClass> ptr1 = std::make_shared<MClass>(); // heap memory 영역에 만들어진다.
        // 참고로 std::shared_ptr<MClass> ptr1(new MClass); 이렇게 new 키워드로 만드는 것과 동일하다. 위에 방법을 추천함
        {
            // in a new scope, in a pair of curl bracket, sharing the resource
            // 이번에는 weak_ptr 만들고 공유할 ptr1을 지정해주면 된다.
            /// 공유는 되지만 use_count가 증가되지 않는다.
            ptr2 = ptr1;

            std::cout << "{ inside scope }current use count :" << ptr2.use_count() << std::endl;
        }
        //ptr2 is freed. but ptr1 still survives
        std::cout << "current use count :" << ptr1.use_count() << std::endl;  // use_count()가 다 0이 되어야 없어진다.
    }   
    std::cout << "weak_ptr expired check :" << ptr2.expired() << std::endl;
    std::cout << "soon, the destructor call\n";
    return 0;
}

// g++ -std=c++14 -o weak_ptr weak_ptr.cpp 