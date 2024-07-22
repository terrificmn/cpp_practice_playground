#ifndef MY_HANDLER_H
#define MY_HANDLER_H

#include <iostream>
#include "cpprest/json.h"
#include "cpprest/http_listener.h"
#include "cpprest/uri.h"
#include "cpprest/asyncrt_utils.h"
#include "cpprest/json.h"
#include "cpprest/filestream.h"
#include "cpprest/containerstream.h"
#include "cpprest/producerconsumerstream.h"
#include "rapidjson/document.h"

class MyHandler {
public:
    MyHandler();
    MyHandler(utility::string_t url);
    virtual ~MyHandler();

    pplx::task<void> open();
    pplx::task<void> close();


private:
    // 우선 get/ put 방식 시도
    void getHandler(web::http::http_request message);
    void putHandler(web::http::http_request message);
    void errorHandler(pplx::task<void>& t);
    web::http::experimental::listener::http_listener m_listener;

};

#endif