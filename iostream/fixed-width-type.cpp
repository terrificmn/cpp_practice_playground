#include <iostream>
#include <cstdint>


int main() {

    // https://en.cppreference.com/w/cpp/types/integer 참고

    // static_assert(sizeof(int)==4, "must be a 32-bit architechture");
    // static_assert(sizeof(int32_t)==4, "needs a 32-bit fixed width types");

    // int primitaive_int = 5;
    // int32_t fixed32_int = 7;
    /// int 의 c++ standard 는 16 bit
    std::printf("%zu\n", sizeof(int));
    std::printf("%zu\n", sizeof(int32_t));


    /// When to use fixed-type?
    // 사용할 range를 정확히 알 경우에 사용 예: pixel 등
    int8_t red = 255;
    int8_t blue = 5;
    int8_t green = 0;
    int8_t alpha = 100;

    /// 정확한 값이 나오지 않는다.
    /// IMPORTANT: cast 를 하는 이유는 int8_t 는 alias 일 뿐이고 실제로는 signed char 이므로 
    // std::cout 을 할 때에 number숫자가 아닌 character 로 표현을 하기 때문에 이상한 값이 나오는 것.
    /// ASCII character 로 표현을 하기 때문
    std::cout << red << " " << blue << " " << green << " " << alpha << std::endl;
    
    // cast type 을 통해서 변경을 해줘야지 프린트가 된다. 그래도 정확한 값이 안나오는 것은 signed 형태 때문
    /// (short) 또는 (int)로 해주게 되면 확실하게 char가 아닌 std::cout understands numerically.
    std::cout << (short)red << " " << (short)blue << " " << (short)green << " " << (short)alpha << std::endl;
    // 이렇게 출력을 하게 되면 정확한 값을 사용할 수가 없다. 이유는 
    // int8_t 는 typedef 로 signed char로 정의되어 있기 때문이다.
    // typedef signed char __int8_t;
    // typedef unsigned char __uint8_t;
    // 매크로를 사용해서 확인해보면 사이즈를 알 수가 있다.
    std::cout << "INT_8 min : "  << INT8_MIN << std::endl;
    std::cout << "INT_8 max : "  << INT8_MAX << std::endl;
    // -127 ~ 127 까지 이다.


    // 그러므로 signed 형식이 아닌 unsigned 를 사용해 줘야 하는데 쉽게 사용할 경우에는 uint8_t 이다
    uint8_t u_red = 255;
    uint8_t u_blue = 5;
    uint8_t u_green = 0;
    uint8_t u_alpha = 100;

    std::cout << std::endl;
    std::cout << "uint8_t max : "  << UINT8_MAX << std::endl;
    std::cout << static_cast<short>(u_red) << " " << static_cast<short>(u_blue) << " " << static_cast<short>(u_green) << " " << static_cast<short>(u_alpha) << std::endl;
}

//  g++ -std=c++17 -o fiexd fixed-width-type.cpp