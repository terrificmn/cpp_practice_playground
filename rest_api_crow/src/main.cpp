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

    // 포트를 원하는 임의로 지정해준다.
    app.port(8000).run();

    return 0;
}