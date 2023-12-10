#include <iostream>
#include <algorithm>
#include <string>

// 간단하게 함수로 만들어서 사용할 수 있다.
void removeCharacter(std::string& str, char remove_char);

int main() {
    // 사용할 string을 넘겨주면 된다. 그러면 알아서 수정
    // 스페이스나, \n (new line character)등을 제거할 때 사용할 수 있다.
    // 함수는 removeCharacter()에서는 erase 함수를 이용하며, std::remove()를 사용하는 심플하게 되어 있다.

    std::string str_space = "  hello  ";
    std::string str_enter = "hello\n\n";
    // str_enter.append("\nenter");

    std::cout << "Before -----------------\n";
    std::cout << "string including space:" << str_space << "<<<- back and forth space" << std::endl;
    std::cout << "string including newline: " << str_enter << "with 2 newline..." << std::endl;


    removeCharacter(str_space, ' ');
    removeCharacter(str_enter, '\n');
    std::cout << "After -----------------\n";
    std::cout << "string including space:" << str_space << "<<<- no space" << std::endl;
    std::cout << "string including newline: " << str_enter << "without 2 newline..." << std::endl;
    
    return 0;
}

void removeCharacter(std::string& str, char remove_char) {
    str.erase(std::remove(str.begin(), str.end(), remove_char), str.cend());
}

// build 
// g++ -std=c++14 -o remove remove.cpp