#include "my_handler.h"

MyHandler::MyHandler() { }
MyHandler::~MyHandler() { }

MyHandler::MyHandler(utility::string_t url) : m_listener(url) {
    this->m_listener.support(web::http::methods::GET, std::bind(&MyHandler::getHandler, this, std::placeholders::_1));
    this->m_listener.support(web::http::methods::PUT, std::bind(&MyHandler::putHandler, this, std::placeholders::_1));
    // 다른 메소드는 추후 테스트
}


void MyHandler::errorHandler(pplx::task<void>& t) {
    try {
        std::cout << "error::::::\t";
        t.get();

    } catch (...) {
        //
    }
}

pplx::task<void> MyHandler::open() {
    return this->m_listener.open();
}

pplx::task<void> MyHandler::close() {
    return this->m_listener.close();

}

void MyHandler::getHandler(web::http::http_request message) {
    std::cout << message.to_string() << std::endl;
}

void MyHandler::putHandler(web::http::http_request message) {
    std::cout <<  message.to_string() << std::endl;
    std::string str_msg = message.to_string();
    // using json = nlohmann::json;
    // 어떤식으로 사용하는지 아직 잘 파악이 안됨
    // auto parsed = nlohmann::json::parse(str_msg);
    
    // if(parsed.is_number()) {
    //     std::cout << parsed << std::endl;
    // }
    


    
    // response
    std::string rep = U("AMR Labs PUT method test. OK!");
    message.reply(web::http::status_codes::OK, rep);
}