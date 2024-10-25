#include <filesystem>
#include <iostream>

int main() {

    std::filesystem::path p = std::filesystem::current_path();
    if(!std::filesystem::exists(p) ) {
        std::cout << p << " dir not found" << std::endl;
    } else {
        std::cout << p << " dir found" << std::endl;
    }

    /// string 형식이나  path type 도 exists() 파라미터로 가능
    std::string str_path = "/home/sgtubunamr/abc";
    if(!std::filesystem::exists(str_path) ) {
        std::cout << str_path << " dir not found" << std::endl;
        std::filesystem::create_directory(str_path);
        std::cout << str_path << "created! " << std::endl;
    } else {
        std::cout << str_path << " dir found" << std::endl;
    }

}


// g++ -std=c++17 -o filepath filepath_exists_then_create.cpp