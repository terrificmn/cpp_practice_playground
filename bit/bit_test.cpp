#include <iostream>
#include <bitset>
#include <bit> // algorithms
#include <cstdint>

int main() {
    using binary_cast8 = std::bitset<8>;

    uint8_t bin = 0b1111'0001;

    std::cout << "original: \t  " << binary_cast8(bin) << std::endl;
    std::cout << "rotation left, 1: " << binary_cast8(std::rotl(bin, 1)) << std::endl;
    std::cout << "rotation left, 2: " << binary_cast8(std::rotl(bin, 2)) << std::endl;

    std::cout << std::endl;
    std::cout << "original: \t   " << binary_cast8(bin) << std::endl;
    std::cout << "rotation right, 1: " << binary_cast8(std::rotr(bin, 1)) << std::endl;

    // Check if we hav a power of 2 -- could be useful for optimization multiply/divide
    uint8_t pow2 = 0b000'0100;
    uint8_t pow2_not = 0b001'1001;
    std::cout << std::has_single_bit(pow2) << std::endl;
    std::cout << std::has_single_bit(pow2_not) << std::endl;

    ///TODO: c++23 기능들도 있어서.. 하다가 중단 추후 다시..
}

// std=c++20 부터 가능
// g++ -std=c++20 -o bit_test bit_test.cpp 