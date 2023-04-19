#include <iostream>
#include <thread>
#include <chrono>

int main() {
    
    std::cout << "string1 new line " << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "string2 new line :" << std::flush;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "string3 new line :\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "string4 new line :";
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    std::cout << "string5 new line :" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    // std::cout << "\rstring6 new line :" << std::flush; 
    std::cout << "\rstring6 new line :"; 
    // std::cout << "string6 new line :"; 
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // std::cout << "\rstring7 new line :" << std::flush;
    std::cout << "\rstring7 new line :";
    // std::cout << "string7 new line :";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    // std::cout << "\rstring8 new line :" << std::flush;
    std::cout << "\rstring8 new line :";
    // std::cout << "string8 new line :";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    
    return 0;
}