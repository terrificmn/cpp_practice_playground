#include <iostream>
#include <sstream>

// c++ 14 버전에서 사용

// Base case for a single argument
template <typename T>
void myPrintHelper(std::ostringstream& stream, const T& arg) {
    stream << arg;
}

// Recursive variadic template // for the general case with multiple arguments
template <typename T, typename... Args>
void myPrintHelper(std::ostringstream& stream, const T& first, const Args&... rest) {
    stream << first << " ";
    myPrintHelper(stream, rest...); // Recursive call for the remaining arguments
    // args의 argument가 Base case 가 될 때까지 myPrintHelper()를 call하게 된다. (recursive로 작동)
}

// Main myPrint function
template <typename... Args>
void myPrint(const Args&... args) {
    std::ostringstream stream;
    myPrintHelper(stream, args...); // Expand the arguments using recursion
    std::cout << stream.str() << " " << std::endl;
}



//// initializer_list 버전
template <typename... Args>
void myPrint2(const Args&... args) {
    std::ostringstream stream;
    (void)std::initializer_list<int> {
        (stream << args, 0) ...
    };
    std::cout << stream.str() << std::endl;
}

int main() {
    myPrint("hello world", 10, 10.123, "test", 0.5);

    myPrint2("hello world2 ", 20, " test2", 0.5);
    return 0;
}