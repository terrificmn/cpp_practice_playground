#include <iostream>
#include <string>

int main () {
    // 보통 많이 사용하는 stoi 를 hex등도 사용할 수가 있다.

    std::string plus_str = "+100";
    std::string minus_str = "-100";
    std::string base16_str = "A0";

    int plus_int = std::stoi(plus_str);
    int minus_int = std::stoi(minus_str);
    // int base16_int = std::stoi(base16_str);  // 이렇게 처리하면 invalid_argument 에러를 발생한다.
    int base16_int = std::stoi(base16_str, nullptr, 16); // 마지막 int는 기본값이 10 임,
    
    /// 또 다른 파라미터는 pos가 있는데, 위에서 nullptr 값을 넘겼던 것
    // 아래처럼 사용할 수가 있다. 몇 개의 케릭터를 사용했는지 값을 알 수가 있다.
    size_t pos;
    int count_result = std::stoi(plus_str, &pos);

    std::cout << "result: \n";
    std::cout << "plus: " << plus_int << std::endl;
    std::cout << "minus: " << minus_int << std::endl;
    std::cout << "base16: " << base16_int << std::endl;

    std::cout << "characters processed: (count_result) " << pos << std::endl;


    return 0;
}


// c++ -std=c++17 -o stoi std_stoi.cpp 