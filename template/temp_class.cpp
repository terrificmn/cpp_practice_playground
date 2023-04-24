#include <iostream>
#include <string>

// typename 대신에 data type인 int로 지정할 수도 있음
/*
template<int N>
class Array {
private:
    int m_array_[N];

public:
    int getSize() {
        return N;
    }
};
*/

// 위의 코드는 요렇게 되게 된다 
// 호출을 메인함수에서 요렇게 Array<5> array; 만들었다면....
// class Array {
// private:
//     int m_array_[5];

// public:
//     int getSize() {
//         return 5;
//     }
// };

template<typename T, int N>
class Array {
private:
    T m_array_[N];

public:
    int getSize() {
        return N;
    }
};



int main(int argc, char* argv[]) {

    // int
    Array<int, 5> array;
    // T 로 typename으로 만들어져 있으므로 데이터 타입을 바꿀 수 있다
    // Array<std::string, 5> array;
    
    // template가 너무 복잡하면 이해하기 힘들어지는 단점이 있다. 적당히 사용하는게 좋다.

    std::cout << array.getSize() << std::endl;

    std::cin.get();
}