#include <iostream>

void foo() {
    /// do nothing
}

int main() {
    int x = 10;
    float y = 10.123;
    char a = 'a';
    signed char b = 'b';
    unsigned char c = 'c';
    std::string str = "hello";

    std::cout << "address..." << std::endl;
    std::cout << "x: " << &x << std::endl;
    /// FYI: 당연히 같은 코드이나, &를 함수처럼 사용한다는 느낌으로 좀 더 명확한 느낌이 들 수도 있다. 물론 생략이 가능하다.
    std::cout << "x: " << &(x) << std::endl; 

    std::cout << "x's size : " << sizeof(x) << " byte" << std::endl;
    // std::cout << "int size : " << sizeof(int) << std::endl; // 같은 타입이므로 사이즈가 같다

    std::cout << "y: " << &y << std::endl;
    std::cout << "y's size : " << sizeof(y) << " byte" << std::endl;
    // std::cout << "float size : " << sizeof(float) << std::endl;// 마찬가지, 단 double은 8byte

    //// char 등은 &만 붙이게 되면 스트링을 인식하기 때문에 타입을 변경해서 출력한다.
    std::cout << "a: " << &a << std::endl;
    std::cout << "b: " << &b << std::endl;
    std::cout << "c: " << &c << std::endl;

    /// pointer를 리턴
    std::cout << "a: " << (void*)&a << std::endl;
    std::cout << "b: " << (void*)&b << std::endl;
    std::cout << "c: " << (void*)&c << std::endl;

    /// string은 &가 잘 작동 // (void*) 생략해도 크게 문제가 없다.
    std::cout << "str: " << &str << std::endl;

    // function 주소도 확인할 수가 있다. 마찬가지로 *를 받는다.
    // std::cout << "foo function: " << &foo << std::endl;
    
    std::cout << "foo function: " << (void*)&foo << std::endl;


    return 0;
}

// g++ -std=c++17 -o basic_address basic_address.cpp 