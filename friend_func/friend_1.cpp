#include <iostream>

class Box {
    double length, width, height;

public:
    Box(double l, double w, double h) : length{l}, width{w}, height{h} {

    }

    // friend 키워드를 사용해서 클래스의 전용 멤버에 접근이 가능하다 
    friend void printfBox(Box box);
};

// 위의 경우에는 펑션을 friend로 했지만 클래스로도 가능한다 
// 예: 
// class A {
// private: ....
// public: ...

// friend class B; 
// }
// 클래스 B는 클래스 A의 멤버에 접근이 가능하게 된다. (private도 접근 가능)
// 사실 중요한 것은 friend 자체는 좋은 기능이나, 객체 지향의 중요한 원칙을 어기는 것이므로 꼭 필요한 간단한 경우가 아니면   
// 사용을 안하는 것이 좋다. friend를 못 본것 같기는 하다..

void printfBox(Box box) {
    std::cout << "Box( " << box.length << ", " << box.width << ", " << box.height << ") " << std::endl;
}


int main() {
    Box box(10, 20, 30);

    printfBox(box);

    return 0;
}