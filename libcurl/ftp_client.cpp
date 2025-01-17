#include <iostream>
#include "ftp_client.hpp"

FtpClient::FtpClient() {
    this->curl = curl_easy_init();
    if (!this->curl) {
            throw std::runtime_error("Failed to initialize CURL");
    } else {
        std::cout << "easy init!\n";
    }

}    

FtpClient::~FtpClient() {
    if (this->curl) {
        curl_easy_cleanup(curl);
    }
    std::cout << "Bye~" << std::endl;
}

bool FtpClient::uploadFile(const std::string& remote_filename) {
    if (!this->curl) return false;

    // Construct FTP URL   // for remote ftp  // 그 외에 나머지 주소는 buildUrl 에서 처리
    /// buildUrl()에서는 ftp server쪽의 정보에 대해서 셋팅한다. 
    std::string url = this->buildUrl(remote_filename);

    // file path
    // "/home/docker_humble/amr_slam/map/13";
    /// 실제 local의 파일 경로
    std::string whole_file_path = "/home/myuser/Downloads/" + remote_filename;
    std::ifstream file(whole_file_path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Cannot open local file: " << std::endl;
        return false;
    }

    curl_easy_reset(this->curl);
    this->setupCommonOptions();

    // Set upload options
    curl_easy_setopt(this->curl, CURLOPT_UPLOAD, 1L);
    curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(this->curl, CURLOPT_READFUNCTION, readCallback);
    curl_easy_setopt(this->curl, CURLOPT_READDATA, &file);

    // Get file size
    file.seekg(0, std::ios::end);
    curl_off_t fileSize = file.tellg();
    file.seekg(0, std::ios::beg);
    curl_easy_setopt(this->curl, CURLOPT_INFILESIZE_LARGE, fileSize);

    // Perform the upload
    CURLcode res = curl_easy_perform(this->curl);
    
    if (res != CURLE_OK) {
        std::cerr << "Upload failed: " << curl_easy_strerror(res) << std::endl;
        return false;
    }

    return true;
}

bool FtpClient::downloadFile(const std::string& remote_filename) {
    if (!this->curl) return false;

    // Create directories if they don't exist
    // std::filesystem::path path(localPath);
    // std::filesystem::create_directories(path.parent_path());

    std::string whole_file_path = "/home/myuser/Downloads/" + remote_filename;

    /// local 파일 경로 및 파일이름 - 저장할 곳 및 파일이름을 지정한다., 
    /// 로컬에서 파일 저장할 곳에서 파일을 열어 준다. 
    std::ofstream file(whole_file_path, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Cannot open local file for writing: " << std::endl;
        return false;
    }

    // upload 할 때랑 마찬가지로 remote ftp의 파일 (다운받을 파일) 지정
    std::string url = buildUrl(remote_filename);

    curl_easy_reset(this->curl);
    this->setupCommonOptions();

    // Set download options
    curl_easy_setopt(this->curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(this->curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(this->curl, CURLOPT_WRITEDATA, &file);

    // Perform the download
    CURLcode res = curl_easy_perform(this->curl);
    
    if (res != CURLE_OK) {
        std::cerr << "Download failed: " << curl_easy_strerror(res) << std::endl;
        return false;
    }

    return true;
}

std::string FtpClient::buildUrl(const std::string& path) {
    std::string url = "ftp://ftp.address";
    
    /// 비교
    // if (port != 21) {
        url += ":2021";
    // }

    // url += "/MapData/" + (path[0] == '/' ? path.substr(1) : path);
    url += "/home/MapData/test-01";
    std::cout << "whole url >>> " << url << std::endl;
    return url;
}


/// @brief  id , password, debug, ssl 등의 옵션을 set
void FtpClient::setupCommonOptions() {
    // Set credentials
    std::string username = "username";
    std::string password = "password";
    std::string user_pwd_str = static_cast<std::string&&>(username) + ":" + static_cast<std::string&&>(password);
    std::cout << "user pwd >>> " << user_pwd_str << std::endl;

    curl_easy_setopt(this->curl, CURLOPT_USERPWD, user_pwd_str.c_str());

    // Set passive/active modes
    curl_easy_setopt(this->curl, CURLOPT_FTPPORT, this->passive_ ? nullptr : "-");

    // Enable verbose debug output if requested
    if (false) {
        curl_easy_setopt(this->curl, CURLOPT_VERBOSE, 1L);
    }

    // Set SSL options if using FTPS
    // curl_easy_setopt(curl_, CURLOPT_USE_SSL, CURLUSESSL_TRY);
    // curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYPEER, 0L);
    // curl_easy_setopt(curl_, CURLOPT_SSL_VERIFYHOST, 0L);
}


size_t FtpClient::readCallback(void* buffer, size_t size, size_t nmemb, void* userp) {
    auto* file = static_cast<std::ifstream*>(userp);
    file->read(static_cast<char*>(buffer), size * nmemb);
    return file->gcount();
}


size_t FtpClient::writeCallback(void* buffer, size_t size, size_t nmemb, void* userp) {
    auto* file = static_cast<std::ofstream*>(userp);
    file->write(static_cast<char*>(buffer), size * nmemb);
    return size * nmemb;
}



int main() {
    try {
        FtpClient ftpClient;

        // optional settings
        // passive setting 만들기

        // passive 모드에서 upload & download 정상 작동 OK
        /// TODO: 함수 에서 필요시 파라미터로 받아서 수행할 수 있게 하기, 현재는 모두 하드코딩

        // if(ftpClient.uploadFile("test-01")) {
        //     std::cout << "Yes uploaded.\n";
        // }
        // if(ftpClient.downloadFile("test-01")) {
        //     std::cout << "Yes downloaded.\n";
        // }


    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    

    return 0;
}

// 의존성 설치 - 페도라 sudo dnf install libcurl-devel
// 우분투 sudo apt install libcurl4-openssl-dev

/// FYI: cmake 할 경우
// find_package(CURL REQUIRED)
// target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)

// c++ -std=c++17 -o ftp ftp_client.cpp -lcurl