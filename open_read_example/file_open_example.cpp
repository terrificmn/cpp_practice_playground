#include <iostream>
#include <vector>
#include <iterator>
#include <charconv>
#include <fstream>
#include <string>

int main() {


    std::vector<int> ascii_vals {};
    std::vector<char> chars {'h', 'e', 'l', 'l', 'o'};

    std::fstream myFile;
    myFile.open("text", std::ios::out);  // ios::out write
    if (myFile.is_open()) {
        myFile << "Hello world\n";
        myFile << "this is second line\n";
        std::cout << "file created" << std::endl;
        myFile.close();
    }

    myFile.open("text", std::ios::app); //ios::app append
    if (myFile.is_open()) {
        myFile << "Third line inserted\n";
        std::cout << "file appended" << std::endl;
        myFile.close(); //once file opened, then close it
    }

    myFile.open("text", std::ios::in); //ios::in read
    if (myFile.is_open()) {
        std::string line;
        while (getline(myFile, line)) { // until no line, it loops
            std::cout << line << std::endl;
        }
        myFile.close();
    }

    ascii_vals.reserve(chars.size());

    for(auto &n : chars) {
        ascii_vals.push_back(n);
    }

    for(int i=0; i< ascii_vals.size(); i++) {
        std::cout << ascii_vals[i] << std::endl;
    }

    return 0;
}


