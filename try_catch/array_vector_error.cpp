#include <iostream>
#include <exception>
#include <array>
#include <vector>

///FYI: array는 아니지만 vector 나 array 를 사용할 때 at() 메소드를 사용할 때   
/// 위처럼 [] 배열로 만들었을 때는 사용할 수가 없지만, std::array<> 등으로 만들었을 때는 at() 메소드를 사용할 수가 있다.  

// vector<bool>::_M_range_check: __n (which is 1) >= this->size() (which is 1)
// 이런 에러는 배열에 잘 못 접근했을 때 발생한다.  clear() 를 시켰거나, initialization이 안되었을 때 접근했는지 체크하자

// terminate called after throwing an instance of 'std::out_of_range'
//   what():  array::at: __n (which is 10) >= _Nm (which is 3)
// Aborted (core dumped)

/// 아예 try catch 를 활용하는 것도 좋은 방법인데, 
/// [] 인덱스에 직접 접근할 경우에는 catch 안되고 프로그램 강종, at() 메소드를 사용할 경우에는 catch 가 가능하다 

int main() {
    std::array<int, 3> my_array { 1, 2, 3};
    std::cout << "my_array[0]: " << my_array[0] << std::endl;
    std::cout << "my_array[1]: " << my_array[1] << std::endl;
    std::cout << "my_array[2]: " << my_array[2] << std::endl;

    try {
        my_array.at(0) = 3;
        my_array.at(1) = 2;
        my_array.at(10) = 1;
        /// 10 인덱스는 없으므로 catch 에서 걸러주게 된다.
    } catch (const std::exception& e) {
        std::cout << "std::exception error occured " << e.what() << std::endl;
    }

    std::cout << "my_array[0]: " << my_array[0] << std::endl;
    std::cout << "my_array[1]: " << my_array[1] << std::endl;
    std::cout << "my_array[2]: " << my_array[2] << std::endl;

    /// 단 직접 [] 인덱스 접근시 catch 하지 못함
    try {
        my_array[10] = 10;
    } catch (const std::exception& e) {
        std::cout << "std::exception error occured " << e.what() << std::endl;
    }

    ////FYI: vector도 같은 방식으로 접근 가능

    return 0;
}

// g++ -std=c++17 -o array_vector_err array_vector_error.cpp 