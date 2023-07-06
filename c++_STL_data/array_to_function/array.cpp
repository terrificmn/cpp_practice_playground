#include <iostream>

// 빌드   g++ -o test_array array.cpp 

// 포인터로 받아서 배열을 계속 사용할 수가 있다. 단, 사이즈도 넘겨 받아야 한다 
void myArray(int *my_array, int my_array_size) {
    for(int i=0; i < my_array_size; i++) {
        std::cout << "my array's index " << i << ": " << my_array[i] << std::endl;  // 포이터 자체가 어레이주소 이어서 * 사용안해도 됨
    }
}

int main() {

    int array_[5] = { 10, 20, 30, 40, 50 };
    std::cout << sizeof(array_) << std::endl;
    std::cout << sizeof(array_[0]) << std::endl;
    int size = sizeof(array_) / sizeof(array_[0]);  // 배열의 크기를 구해 준다.
    
    myArray(array_, size); // array_ 자체가 첫 번쨰 주소가 되므로 

    return 0;
}
