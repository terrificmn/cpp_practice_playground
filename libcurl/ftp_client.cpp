#include <iostream>
#include <curl/curl.h>

int main() {

    CURL* curl;
    curl = curl_easy_init();
    if (!curl) {
            throw std::runtime_error("Failed to initialize CURL");
    } else {
        std::cout << "easy init!\n";
    }

    return 0;
}

// 의존성 설치 - 페도라 sudo dnf install libcurl-devel
// c++ -std=c++17 -o ftp ftp_client.cpp -lcurl