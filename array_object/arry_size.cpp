#include <iostream>

int main() {

    int array_[5] { 1, 2, 3, 4, 5 };
    
    // array에는 size()등의 함수를 사용할 수가 없다. ! stack 방식으로 할당된 것만 사용할 수 있다. (힙 메모리 포인터등은 안됨)
    // array_의 전체 사이즈 메모리 크기를 알아낸 후에  int 사이즈인 4byte로 나눠주면 크기가 나온다. 
    int count = sizeof(array_) / sizeof(int);

    // 단 주의 할점은 ptr로 함수에서 넘어가거하면 위의 기능 제대로 못 할 수 있으므로 []인덱스 사이즈를 미리 설정해주는 것이 좋다. 
    // 단, []사이즈는 컴파일 타임에 알 수 있게 상수여야 한다. 변수로 지정하면 에러발생
    // int size = 5;
    // int example[size]; // not work
    // 그래서 static const int 로 선언하면 사용할 수가 있다.
    static const int example_arr_size = 5;
    int arr_[example_arr_size];

    std::cout << "total sizeof array: " << sizeof(array_) << std::endl;
    std::cout << "int size: " << sizeof(int) << std::endl;
    std::cout << "array count: " << count << std::endl;
    std::cin.get();
    return 0;
}