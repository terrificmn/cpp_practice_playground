#include <iostream>
#include <asio.hpp> /// standalone 으로 사용
#include <asio/ts/buffer.hpp>
#include <asio/ts/internet.hpp>

int main() {
    /// error 코드를 확인할 때 사용, 여러 함수에서 ec를 파라미터로 넘겨줄 수가 있다.
    asio::error_code ec;

    // create a "context"
    asio::io_context context;

    // ip address we wish to connect to  // tcp 형태로 make_address() 사용, 
    asio::ip::tcp::endpoint endpoint(asio::ip::make_address("127.0.0.1", ec), 80);

    // create a socket, the context will deliver the implementation
    asio::ip::tcp::socket socket(context);

    // socket을 이용해서 연결
    socket.connect(endpoint, ec);

    if(!ec) {
        std::cout << "connected" << std::endl;
    } else {
        std::cout << "failed to connect to address:\n" << ec.message() << std::endl;
    }

    return 0;
}