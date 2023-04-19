#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
    try {
        if (argc != 2) {
            std::cerr << "Usage: client <ip>" << std::endl;
            return 1;
        }

        boost::asio::io_context io_context;
        tcp::resolver resolver(io_context);
        
        tcp::resolver::results_type endpoints = resolver.resolve(argv[1], "daytime");
        // daytime 은 protocol 중에 하나로, port 13을 사용한다 -- 
        
        tcp::socket socket(io_context);
        boost::asio::connect(socket, endpoints);

        for(;;) {
            boost::array<char, 128> buf;
            boost::system::error_code error;

            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            if(error == boost::asio::error::eof) {
                std::cout << "error 1: connection closed" << std::endl; 
                break; // connection closed cleanly by peer

            } else if(error) {
                std::cout << "some other error " << std::endl;
                throw boost::system::system_error(error);
            }   

            std::cout.write(buf.data(), len);
        }

    } catch (std::exception& e){
        std::cout << "exception error: ";
        std::cerr << e.what() << std::endl;
    }
    return 0;
}