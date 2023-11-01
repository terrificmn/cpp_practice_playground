#include <iostream>

int main() {

    int array_example[5] { 1, 2, 3, 4, 5 };
    // array자체가 주소이므로 & 없이 포인터 바로 넣어준다
    int* array_ptr = array_example;

    // array_ptr +2 를 해주면 주소가 이동(shift) (array는 연속된 메모리 주소 이므로)
    // 그리고 * dereferencing을 해주면 값을 넣어 줄 수가 있다
    *(array_ptr + 2) = 30;

    std::cout << "index 2: " << array_example[2] << std::endl;
    

    std::cout << "Press any key..to exit" << std::endl;
    std::cin.get();
    return 0;
}