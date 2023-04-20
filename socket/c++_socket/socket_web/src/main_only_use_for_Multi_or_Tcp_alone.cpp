#include "tcp_listener.h"
#include "multi_client_chat.h"

/// 컴파일 시 main으로 수정하던가- CMakeLists.txt 파일의 src 경로를 변경해서 컴파일 해야함

int main(int argc, char *argv[]) {

    // TcpListener만 사용할 경우
    // TcpListener tcpListener("127.0.0.1", 9190);
    // if(tcpListener.init() == 0) {
    //     std::cout << "Now tcp started" << std::endl;
    //     tcpListener.run();
    // }

    MultiClientChat multiCC("127.0.0.1", 9190);
    if(multiCC.init() != 0) {
        return 1;
    }

    multiCC.run();

    /// MultiClientChat 클래스 작동은 하나 멀티로는 작동하지 않ㄹ고, 약간의 버그도 있는 듯 하다.. 
    /// 윈도우 버전과 비교해보면 수정해야할 듯 하다 -on Apr20 2023

    return 0;
}