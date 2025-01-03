#include <iostream>
#include <stdexcept>

int main() {
    
    std::string err = "error message";
    throw std::runtime_error(err);
    
    return 0;
}