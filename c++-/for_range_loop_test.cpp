#include <iostream>
#include <vector>

int main() {
    std::vector<std::string> animals {"tiger", "lion", "cat", "dog"};
    
    for (auto& animal : animals) {
        std::cout << animal << " ";
    }
    std::cout << std::endl;
}