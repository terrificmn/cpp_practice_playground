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


    /// out of range. 이를 함수 등에 만들어 놓고 이 함수를 try catch 로 받아서 사용하면 된다.
    if (/*something*/ >= my_array.size()) {
        throw std::out_of_range("Index out of bounds");
    }

    try {
        // Check for out-of-bounds access
        // 위의 코드를 함수로 만들어 호출하거나 
        
    } catch (std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl; 
    }

    return 0;
}