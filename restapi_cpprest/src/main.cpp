#include <iostream>
#include <memory>
#include "my_handler.h"

void init(const std::string& address) {
    web::http::uri_builder uri(address);
    
    auto addr = uri.to_uri().to_string();
    std::unique_ptr<MyHandler> g_http_handler = std::make_unique<MyHandler>(addr);
    // std::unique_ptr<MyHandler> g_http_handler = std::unique_ptr<MyHandler>(new MyHandler(addr));
    g_http_handler->open().wait();
    std::cout << addr << std::endl;

    std::cout << utility::string_t(U("Listening for requests at: ")) << addr << std::endl;

}


int main(int argc, char *argv[]) {
    utility::string_t port = U("8888");
    utility::string_t address = U("http://192.168.10.22:");
    address.append(port);

    // init(address);

    std::unique_ptr<MyHandler> g_http_handler = std::make_unique<MyHandler>(address);
    g_http_handler->open().wait();

    std::string test;
    std::cout << "press any keys to exit\n";
    std::cin >> test;


}