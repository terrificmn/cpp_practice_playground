#include <iostream>

int main() {

    std::cout << "hello world\n";
    const char* string_literal = "hello2";
    std::cout.write(string_literal, sizeof(string_literal));

    std::cout << std::endl;

    // flags
    // hex, oct 등으로 변환 가능 (int)
    std::cout << "123 - hex: " << std::hex << 123 << std::endl;
    std::cout << "123 - oct: " << std::oct << 123 << std::endl;

    // bool 확인
    bool is_bool = false;
    std::cout << std::boolalpha << is_bool << std::endl;


}
// g++ -std=c++17 main.cpp -o main