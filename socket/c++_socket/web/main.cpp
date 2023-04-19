#include "tcp_listener.h"

int main(int argc, char *argv[]) {

    TcpListener tcpListener("127.0.0.1", 9190);

    if(tcpListener.init() == 0) {
        std::cout << "Now tcp started" << std::endl;
        tcpListener.run();
    }
    
    return 0;
}