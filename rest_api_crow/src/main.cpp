#include <iostream>
#include <crow.h>
// #include "cpp_redis/core/client.hpp"


int main(int argc, char *argv[]) {
    crow::SimpleApp app;

    // redis는 아직 테스트 안 해봄
    // cpp_redis::client redisClient;
    // redisClient.connect();

    // exmaple 코드는 Crow 깃허브 패키지에서 찾을 수 있다. - 그 중 가장 간단한 example
    // 브라우저에 localhost:8000 으로 테스트 해볼 수 있다.
    CROW_ROUTE(app, "/")
    ([]() {
        return "Hello, world";
    });

    // 마지막 <int> 부분은 주소 끝에 int값을 넣어서 요청.
    // 요청 시 주소창에 http://localhost:8000/api/test/1 이런식으로 한다
    CROW_ROUTE(app, "/api/test/<int>")
    ([](int number) {
        std::ostringstream os;
        if (number < 10) {
            os << "<h3> " <<  number << ": smaller! </h3>";
        } else {
            os << "<h1>" << number << ": bigger! </h1>";
        }
        
        return crow::response(os.str());
    });


    CROW_ROUTE(app, "/api/v1/slam/slam")
        .methods("PUT"_method)([](const crow::request& req) {
            auto x = crow::json::load(req.body);

            if (!x) {
                return crow::response(400);
            } else if(!x.has("enable")) {
                return crow::response(401);
            }

            // int로는 변환이 됨 (int/string으로 보냈을 경우. 단, bool은 안됨)
            // std::cout << "[enable]:  " << x["enable"] << std::endl;
            int enable = (int)x["enable"];

            std::ostringstream os; // 웹페이지 표시
            if (enable == 1) {
                std::cout << " true" << std::endl;
                os << "slam enable-request : true";
            } else {
                std::cout << " false" << std::endl;
                os << "slam enable-request : false";
            }
            
            return crow::response{os.str()};
    });


    CROW_ROUTE(app, "/api/v1/slam/localization")
        .methods("PUT"_method)([](const crow::request& req) {
            auto x = crow::json::load(req.body);

            if (!x) {
                return crow::response(400);
            } else if(!x.has("enable")) {
                return crow::response(401);
            }

            // int로는 변환이 됨 (int/string으로 보냈을 경우. 단, bool은 안됨)
            // std::cout << "[enable]:  " << x["enable"] << std::endl;
            int enable = (int)x["enable"];

            std::ostringstream os; // 웹페이지 표시
            if (enable == 1) {
                std::cout << " true" << std::endl;
                os << "slam enable-request : true";
            } else {
                std::cout << " false" << std::endl;
                os << "slam enable-request : false";
            }
            
            return crow::response{os.str()};
    });


    // 메소드를 "PUT"_method 식으로 넣거나? 아래처럼 enum을 사용할 수 있다.
    CROW_ROUTE(app, "/api/v1/test").methods(crow::HTTPMethod::POST)
        ([](const crow::request& req) {
        
        auto body = crow::json::load(req.body);

        std::string title, type;
        try {
            title = body["title"].s(); // s funtion: string변환
            type = body["title"].s();
            body["coordinate"].d(); // double 변환
            body["number"].i(); // int 변환
            body["is_enable"].b(); // boolean 변환
            // body["state"].
        } catch(const std::runtime_error &ex) {
            return crow::response(400, "Invalid value");
            // 리스펀스도 enum을 사용할 수가 있다.
            // or return crow::response(crow::status::BAD_REQUEST);
        }

        // json만들기
        std::vector<crow::json::wvalue> tests;
        crow::json::wvalue write_value {
                                            { "title", "New title" },
                                            { "is_enable", true }, 
                                            { "number", 10 } 
                                        };
        // wvalue 만들기 예
        //  {"first", "Hello world!"},                     /* stores a char const* hence a json::type::String */
        //   {"second", std::string("How are you today?")}, /* stores a std::string hence a json::type::String. */
        //   {"third", std::int64_t(54)},                   /* stores a 64-bit int hence a std::int64_t. */
        //   {"fourth", std::uint64_t(54)},                 /* stores a 64-bit unsigned int hence a std::uint64_t. */
        //   {"fifth", 54},                                 /* stores an int (as 54 is an int literal) hence a std::int64_t. */
        //   {"sixth", 54u},                                /* stores an unsigned int (as 54u is a unsigned int literal) hence a std::uint64_t. */
        //   {"seventh", 2.f},                              /* stores a float (as 2.f is a float literal) hence a double. */
        //   {"eighth", 2.},                                /* stores a double (as 2. is a double literal) hence a double. */
        //   {"ninth", nullptr},                            /* stores a std::nullptr hence json::type::Null . */
        //   {"tenth", true}                                /* stores a bool hence json::type::True . */
        tests.push_back(write_value); // 직접 wvalue rvalue 스타일로 넣어도 된다.

        // 리턴하기 json 그대로 리턴
        // return crow::json::wvalue{ { "data", tests }};

        // 아래 처럼 array형태로 만들어서 리턴해줄 수가 있다.
        // {
        //     "data" : [
        //         {
        //             "title" : "New title",
        //             // ...
        //         }
        //     ]
        // }

        // 리스트로 만들어서 리턴하기 예
        // crow::json::wvalue x(crow::json::wvalue::list({1, 2, 3}));
        // return x;

    });

    // gRPC c++ 에 대해서 알아보기. json이 아닌것으로 만들어주는 것 같다...정확히 모름
    // protobuf 를 이용해서 커뮤니케이션을 한다고 한다.(JSON 보다 효율적??)

    
    //get 방식에서 ? 이후로 받는 변수 처리할경우
    CROW_ROUTE(app, "/api/v1/params")
    ([](const crow::request& req) {
        
        std::cout << (req.url_params.get("foo") == nullptr ? "Not found" : "") << std::endl;
        //if로 처리할 경우
        if(req.url_params.get("foo1") != nullptr) {
            // type casting하기
            double coordinate = crow::utility::lexical_cast<double>(req.url_params.get("foo1"));
            // 아래 처럼 이용 
            // crow::utility::lexical_cast<int>;
            // crow::utility::lexical_cast<bool>;
            std::cout << "receviced coordite: " << coordinate << std::endl;
        }
        // 이 외에 list형태도 받아올 수 있는데 get방식으로 list까지 만들어서 보내는 경우는 많지 않을 듯하다. 어쨋든..
        // http://localhost:8000/api/v1/params?count[]=a&count[]=b
        // auto count = req.url_params.get_list("count");
        // // 이후 for loop으로 처리
        // for(const auto& count_value : count) {
        //     std::cout << count_value << std::endl;
        // }
        // dictationary형태도 가능하다고 함. Crow 라이브러리 example확인하기

        return crow::response(200, "ok");
    });


    // enables all log
    // app.loglevel(crow::LogLevel::Debug);

    // 포트를 원하는 임의로 지정해준다.
    // app.port(8000).run();

    // 포트 지정과, 멀티 쓰레드 가능
    app.port(8000).multithreaded().run();

    return 0;
}