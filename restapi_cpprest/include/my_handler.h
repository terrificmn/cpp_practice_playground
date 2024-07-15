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


class MyHandler {
public:
    MyHandler();
    MyHandler(utility::string_t url);
    virtual ~MyHandler();


private:
    void handler_get(web::http::http_request message);
    void handler_put(web::http::http_request message);
    void handle_error(pplx::task<void>& t); 
    web::http::experimental::listener::http_listener m_listener;

};

#endif