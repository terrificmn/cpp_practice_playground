#include <iostream>
#include <exception>

int main() {
    try {
        int x = 10;
        int y = 0;
        int z = x / y;
    }
    catch (const std::exception& e) {
        std::cout << "std::exception error occured " << e.what() << std::endl;
    }

    return 0;
}