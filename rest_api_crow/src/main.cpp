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

    // 마지막 <int> 부분은 주소 끝에 int값을 넣어서 요청
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


    // 포트를 원하는 임의로 지정해준다.
    app.port(8000).run();

    return 0;
}