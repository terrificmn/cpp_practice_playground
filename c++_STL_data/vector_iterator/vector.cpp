// contiguous memory 

// stack and heap

// array 는 stack
// vector 는 heap
// heap는 stack보다 느리다. 아주 크고 복잡한 환경에서는 그러하겠지만, 이를 심각하게 받아들일 필요는 없을 듯 하다.


/// IMPORTANT:
/// 1. 꼭 vector를 사용해야하는 질문을 해보자. 가능하면 array로도 사용할 수가 있다.
///    물론 vector가 가진 확장성(?)으로 사용할 경우가 많은 듯 하다. 편하기도 하다;;;
/// 2. vector를 사용한다면 사이즈를 reserve() 등으로 사용하고, 
///     원래 push_back() 을 하면 메모리 할당을 하듯, 필요시 추후 사이즈를 스스로 변경해준다.
/// 3. emplace_back() 을 사용하자. 단 주의 할 점은 copy가 되는 객체를 넘기면 push_back() 과 비슷하게 작동, 
///     이 부분이 어려운 듯 하다. 


#include <iostream>
#include <vector>

static int s_allocation_count = 0;
static int s_copy_count = 0;
static int s_move_count = 0;


/// vector 에서 내부적으로 사용하는 new를 override 해서 사용해서 할당 되는 것을 확인할 수가 있음
void* operator new(size_t size) {
    std::cout << "now allocated " << size << " bytes" << std::endl;
    s_allocation_count++;
    return malloc(size);
}

struct MyData {
    int value = 0;

    MyData() = default;
    MyData(int value_) : value(value_) {
    }

    // copy constructor
    MyData(const MyData& rhs) : value(rhs.value) {
        s_copy_count++;
        std::cout << "now copied MyData" << std::endl;
    }

    // move constructor -- rvalue reference
    MyData(MyData&& rhs) : value(rhs.value) {
        s_move_count++;
        std::cout << "now moved MyData" << std::endl;
    }
};

// void printVector(std::vector<MyData> vector) { // pass by value 로 하면 allocation 을 한번 더 하게 된다.
void printVector(std::vector<MyData>& vector) { // pass by reference 로 하면 allocation 을 줄일 수 있다. -1
    std::cout << "size: " << vector.size() << std::endl;
    if(vector.empty())
        return;

    for(int i =0; i < vector.size(); i++) {
        std::cout << vector[i].value << " ";
    }
    std::cout << std::endl;

}


int main() {
    std::vector<MyData> vector;

    // 대개 컴파일러마다 다르지만 push_back 등으로 확장할 때 메모리 allocation이 두 배씩 늘어남 
    /// 1. blcok. 보통 하는 편하게 push_back() 을 많이 사용하니 아래 주석을 풀고 확인
    // { 
    //     for(int i=0; i<5; i++) {
    //         vector.push_back(MyData(i));
    //     }
    // }

    // vector를 미리 reserve를 하게 되면 allocation이 1번만 하게 된다. 그래서 reserve()로 할당하는 것이 좋다.
    /// 물론 vector는 확장을 용이하게 할 수 있는 장점이 있으니, 크기를 알 수 있는 경우에는 사용하면 좋을 듯 하다.
    /// 2. block : reserve와 copy 또는 move constructor 를 사용한 방법, emplace_back 
    { 
        vector.reserve(5);
        for(int i=0; i<5; i++) {
            // 여기에서 copy가 일어나게 된다. 파라미터로 전달될 때 또는 vector2 = vector 식으로 사용할 경우에도 copy가 일어난다.
            // vector.push_back(MyData(i)); 
            // 만약 move 관련 constructor 를 사용하게 되면 copy 대신에 move를 해서 사용하게 되는데, 그나마 copy 보다는 효과적이다.

            // vector.push_back(i); // 같은 결과 -- vector에 들어가 있는게 MyData 이므로 i를 넣어도 copy가 일어난다.

            /// emplace_back 을 사용하게 되면  MyData 의 copy, move constructor가 발생을 안하게 된다.
            vector.emplace_back(i);
            /// TODO: emplace_back 에 대해서 좀 더 알아보자.;; 
        }
    }

    printVector(vector);

    std::cout << "total allocation: " << s_allocation_count << std::endl;
    std::cout << "total copy: " << s_copy_count << std::endl;
    std::cout << "total move: " << s_move_count << std::endl;

    return 0;
}

//  g++ -std=c++17 -o vector vector.cpp