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
    /// web::http::http_request 에는 다양한 메세지가 들어가 있다. 예를 들어 
        // HTTP/1.1
        // Accept: */*
        // Content-Length: 20
        // Content-Type: application/json
        // Host: localhost:8888
        // User-Agent: insomnia/9.3.2
    /// 그렇게 때문에 string으로 변환해서 json으로 처리하려고 하면 에러 발생하며 사용할 수 없다. 

    /// json 부분만 떼어 내기
    pplx::task<utility::string_t> json = message.extract_string();
    std::string str_json = utility::conversions::to_utf8string(json.get());

    /// parsing json
    rapidjson::Document docu;
    docu.Parse(str_json.c_str());

    if(docu.IsObject() && docu.HasMember("json")) {
        if(docu["json"].IsString()) {
            std::cout << "json: " << docu["json"].GetString() << std::endl;
        } else {
            std::cout << "not string, json ignored\n";
        }
    } else {
        std::cout << "json ignored\n";
    }

    // response
    std::string rep = U("AMR Labs PUT method test. OK!");
    message.reply(web::http::status_codes::OK, rep);
}