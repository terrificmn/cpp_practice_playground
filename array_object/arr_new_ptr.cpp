#include <iostream>

int main() {

    int array_example[5] { 1, 2, 3, 4, 5 };
    
    // 위의 array_example은 블럭을 벗어나면 자동 소멸됨

    // 하지만 아래의 array_ptr_new는 new키워드로생성해서 힙 메모리에 할당 되므로 없어지지 않으므로  
    // delete를 해야한다
    int* array_ptr_new = new int[5];

    delete[] array_ptr_new;

    // 또 다른 단점은 ptr로 new키워드로 동적으로 만들게 되면 주소를 한번에 찾아가는 것이 아니고  
    // 만약 클래스 안에 넣었다면 클래스 주소에서 어레이 주소 까지 주소를 찾아가는 방식이 사용된다고 하므로 효율적이지 못할 수 있다.
    // 소멸되기 (delete로)지워지기 전까지는 남아있어서 여러모로 사용할 때는 유용하겠지만 꼭 delete로 소멸 시켜야 메모리leak가 없다

    std::cout << "Press any key..to exit" << std::endl;
    std::cin.get();
    return 0;
}