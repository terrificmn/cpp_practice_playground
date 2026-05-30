/// /etc/hosts 같은 파일을 퍼미션 때문에 읽기가 어렵다. -rw-r-r 옵션이 있어서 읽기는 가능해야하나, 
// docker 등과 같은 환경에서는 읽게 불가능 해질 수가 있다. 
#include <iostream>
#include <fstream>
#include <cstring> // Required for strerror

int main() {
    std::ifstream hostsFile("/etc/hosts");
    if (!hostsFile.is_open()) {
        std::cerr << "Error: Could not open /etc/hosts. Check your permissions." << std::endl;
        /// 확실하게 에러를 확인하려면 
        std::cerr << "Error: " << std::strerror(errno) << std::endl;
        return 1;
    }

    std::string line;
    // Read the file line by line
    while (std::getline(hostsFile, line)) {
        std::cout << line << std::endl;
    }

}

