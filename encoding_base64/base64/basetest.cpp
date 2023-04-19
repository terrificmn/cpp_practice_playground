#include <fstream>
#include <string>
#include <iostream>
#include "base64.h"

int main(int argc, char** argv) {
    bool all_tests_passed = true;
    std::string line;

    std::ifstream input("maps/mymap.pgm", std::ios::in | std::ios::binary);
    std::ofstream output("output.txt");

    if(input.is_open()) {
        while(getline(input, line)) {
            
            std::string encoded_str = base64_encode(reinterpret_cast<const unsigned char*>(line.c_str()), line.length());
            std::string decoded_str = base64_decode(encoded_str);
            
            if (decoded_str != line) {
                std::cout << "decoded != input line" << std::endl;
                all_tests_passed = false;
            }

            output << encoded_str;
            
        }
        input.close();
    }

    if (all_tests_passed) {
        std::cout << "\ntest PASSED" << std::endl;
    } else {
        std::cout << "\ntest FAILED" << std::endl;
    }

    ////// test /////////
    // const std::string orig =
    // "René Nyffenegger\n"
    // "http://www.renenyffenegger.ch\n"
    // "passion for data\n";

    // std::string encoded_str = base64_encode(reinterpret_cast<const unsigned char*>(orig.c_str()), orig.length());
    // std::string decoded = base64_decode(encoded_str);

    // std::cout << encoded_str << std::endl;
    // if (encoded_str != "UmVuw6kgTnlmZmVuZWdnZXIKaHR0cDovL3d3dy5yZW5lbnlmZmVuZWdnZXIuY2gKcGFzc2lvbiBmb3IgZGF0YQo=") {
    //     std::cout << "Encoding is wrong" << std::endl;
    //     all_tests_passed = false;
    // }

    // if (decoded != orig) {
    //     std::cout << "decoded != input line" << std::endl;
    //     all_tests_passed = false;
    // }

    // if (all_tests_passed) {
    //     std::cout << "test passed" << std::endl;
    // } else {
    //     std::cout << "test failed" << std::endl;
    // }

    return 0;
}