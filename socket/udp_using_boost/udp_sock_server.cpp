#include <boost/asio.hpp>
#include <boost/array.hpp>
#include <iostream>

std::string makeDaytimeString() {
    std::time_t now = std::time(0);
    return std::ctime(&now);
}

using boost::asio::ip::udp;

int main(int argc, char** argv) {
    try {
        boost::asio::io_context io_context;

        udp::socket socket(io_context, udp::endpoint(udp::v4(), 13));

        for(;;) {
            boost::array<char, 1> recv_buf;
            udp::endpoint remote_endpoint;
            socket.receive_from(boost::asio::buffer(recv_buf), remote_endpoint);

            std::string message = makeDaytimeString();
            boost::system::error_code ignored_error;
            socket.send_to(boost::asio::buffer(message), remote_endpoint, 0, ignored_error);
        }
    } catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}