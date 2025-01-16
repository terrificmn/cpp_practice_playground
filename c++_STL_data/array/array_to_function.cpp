#include <iostream>
#include <array>

// 빌드 시에 포함 된다.
constexpr int std_array_size = 5;

/// array를 함수로 보내게 되면... 
/// 원래 void myArray(int my_array[]); <---- 이렇게 사용이 되면 이는 int* 로 변환되어 받아지므로 함수내에서 sizeof() 등을 사용할 수가 없다.
/// int my_array[] 하면 실제로는 int* my_array 로 사용이 된다. 그러므로 포인터 이므로 size를 알 수 없게 됨 (함수 내에서 실행할 때에)
/// 그래서 array를 넘겨줄 때에는 아예 해당 타입의 (e.g int)포인터와 사이즈도 같이 넘겨줘야 한다. 

// 1. raw array 를 사용할 경우 // 포인터로 받아서 배열을 계속 사용할 수가 있다. 단, 사이즈도 넘겨 받아야 한다 
void myArray(int *array_, size_t array_size_) {
    for(int i=0; i < array_size_; i++) {
        std::cout << "my array's index " << i << ": " << array_[i] << std::endl;  // 포이터 자체가 어레이주소 이어서 * 사용안해도 됨
    }
}

// 2. std::array 를 사용할 경우
/// 파라미터로 넘길 때 그냥 array[] 와는 다르게 size() 자체를 알 수가 있지만, 함수를 정의할 때 파라미터에서 std::array의 크기를 지정해줘야 한다. 
/// 그래서 배열의 수를 직접 넣어주거나 constexpr로 사용된 std_array_size 등을 사용(위에서 전역으로 선언) 를 사용할 수도 있다.
void myStdArray(const std::array<int, 5>& std_array) {    /// void myArray(const std::array<int, std_array_size>& std_array) {
    std::cout << "std_array's size: " << std_array.size() << std::endl;
    for(int i=0; i < std_array_size; i++) {
        std::cout << "my array's index " << i << ": " << std_array[i] << std::endl;  // 포이터 자체가 어레이주소 이어서 * 사용안해도 됨
    }
}

int main() {

    int my_array[5] = { 10, 20, 30, 40, 50 };
    std::cout << sizeof(my_array) << std::endl;
    std::cout << sizeof(my_array[0]) << std::endl;

    // 해당 array가 int type 이므로 int로 sizeof()를 해서 나눠준다.
    size_t size = sizeof(my_array) / sizeof(int); // 배열의 크기를 구해 준다.  // 또는 한개의 배열로 나눠준다.

    myArray(my_array, size); // array_ 자체가 첫 번쨰 주소가 되므로 
    std::cout << "---------" << std::endl;
    

    /// array는 사이즈가 지정되어 있으므로, constextr 를 사용하거나 사이즈 변경시에 잘 적어준다.
    // 다른 방법으로 크기에 영향이 없는 vector를 사용하는 것도 한 방법이다.
    std::array<int, 5> std_array = { 1, 2, 3, 4, 5};
    
    myStdArray(std_array); // array_ 자체가 첫 번쨰 주소가 되므로 
    return 0;
}

// g++ -std=c++17 -o array_to_function array_to_function.cpp 