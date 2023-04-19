#include <regex>
#include <string>
#include <iostream>

int main(int argc, char** argv) {


    std::string test_string = "origin: [-28.126819, -27.423724, 0.000000]";
    std::string ph = "010-123-1234";
    
    
    // std::regex reg("[01]{3}-(\\d{3,4})-\\d{4}");  /////space is problem
    std::regex reg("[\\d\\.,- ]+");  /////space is problem
    std::smatch mat;

    std::cout << "match: " << std::regex_match(test_string, reg) << std::endl;

    if (std::regex_search(test_string, mat, reg)) {
        std::cout << "ok found it" << std::endl;
        for(auto x: mat) {
            std::cout << x << " \n";
        }
    }

    return 0;
}