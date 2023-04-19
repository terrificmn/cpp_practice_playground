#include <iostream>
#include <thread>

void function1() {
    for(int i=0; i <200; i++) {
        std::cout << "+";
    }

    
}

void function2() {
    for(int i=0; i <200; i++) {
        std::cout << "-";
    }
}

int main() {
    // 파라미터로 funtion을 넘겨준다 
    std::thread worker1(function1);
    std::thread worker2(function2);

    // function1();
    // function2();

}