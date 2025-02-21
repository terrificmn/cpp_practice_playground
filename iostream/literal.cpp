#include <iostream>
#include <string>

int main() {

    // 스트링을 있는 그대로 표현해 줄려고 하면 \n 등으로 칸을 띄우고 다양하게 해줘야 하는데
    // 스페이스도 띄워주고 제대로 출력하기가 어렵다
    std::string print1 = " \
    int main() {\n  \
    \n  \
        return 0; \
    \n \
    }";

    std::cout << print1 << std::endl;

    // 이때 사용할 수 있는게 raw literal string for utf-8
    // 이모티콘도 사용할 수가 있음 
    /// R"(context)""
    std::string print2(R"(
    int main() {
        return 1;
    }
    )");
    
    std::cout << "\nRaw literal string" << std::endl;
    std::cout << print2 << std::endl;
}

// g++ -std=c++17 -o literal literal.cpp 