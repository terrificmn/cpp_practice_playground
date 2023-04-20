#include "tcp_listener.h"
#include "web_server.h"

int main(int argc, char *argv[]) {

    WebServer webS("127.0.0.1", 8080);
    if(webS.init() != 0) {
        return 1;
    }
    std::cout << "web init\n";
    webS.run();

    /// MultiClientChat 클래스 작동은 하나 멀티로는 작동하지 않고, 약간의 버그도 있는 듯 하다.. 
    /// 윈도우 버전과 비교해보면 수정해야할 듯 하다 -on Apr20 2023

    return 0;
}