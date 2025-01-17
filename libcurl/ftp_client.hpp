#ifndef FTP_CLIENT_HPP
#define FTP_CLIENT_HPP

#include <iostream>
#include <fstream>
#include <curl/curl.h>


class FtpClient {
public:
    FtpClient();
    ~FtpClient();
    bool uploadFile(const std::string& remote_filename);
    bool downloadFile(const std::string& remote_filename);
    std::string buildUrl(const std::string& path);
    void setupCommonOptions();
    static size_t readCallback(void* buffer, size_t size, size_t nmemb, void* userp);
    static size_t writeCallback(void* buffer, size_t size, size_t nmemb, void* userp);

private:
    CURL* curl;
    bool passive_ = true;
};

#endif