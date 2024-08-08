#include <iostream>
#include "api/peer_connection_interface.h"
#include "api/create_peerconnection_factory.h"
#include <websocketpp/config/asio_no_tls_client.hpp>
#include <websocketpp/client.hpp>

// #include "api/media_stream_interface.h"


typedef websocketpp::client<websocketpp::config::asio_client> client;

using websocketpp::lib::placeholders::_1;
using websocketpp::lib::placeholders::_2;
using websocketpp::lib::bind;

// pull out the type of messages sent by our config
typedef websocketpp::config::asio_client::message_type::ptr message_ptr;

// This message handler will be invoked once for each incoming message. It
// prints the message and then sends a copy of the message back to the server.
void on_message(client* client, websocketpp::connection_hdl hdl, message_ptr msg) {
    std::cout << "on_message called with hdl: " << hdl.lock().get()
              << " and message: " << msg->get_payload()
              << std::endl;


    websocketpp::lib::error_code ec;

    //create a data channel

    client->send(hdl, msg->get_payload(), msg->get_opcode(), ec);
    if (ec) {
        std::cout << "Echo failed because: " << ec.message() << std::endl;
    }
}



///TODO: 클라이언트로 예제로 잘 작동한다. 
/// 람다함수 등으로 만들 수가 있는데, 다음번에는 테스트 해봐야겠다.

int main() {
    std::cout << "hello webrtc!" << std::endl;

    client ws_client;
    std::string uri = "ws://localhost:3000";

    try {
        // Set logging to be pretty verbose (everything except message payloads)
        ws_client.set_access_channels(websocketpp::log::alevel::all);
        ws_client.clear_access_channels(websocketpp::log::alevel::frame_payload);

        // Initialize ASIO
        ws_client.init_asio();

        // Register our message handler
        ws_client.set_message_handler(bind(&on_message, &ws_client, ::_1, ::_2));

        websocketpp::lib::error_code ec;
        client::connection_ptr con = ws_client.get_connection(uri, ec);
        if (ec) {
            std::cout << "could not create connection because: " << ec.message() << std::endl;
            return 0;
        }

        // Note that connect here only requests a connection. No network messages are
        // exchanged until the event loop starts running in the next line.
        ws_client.connect(con);

        // Start the ASIO io_service run loop
        // this will cause a single connection to be made to the server. c.run()
        // will exit when this connection is closed.
        ws_client.run();

    } catch (websocketpp::exception const & e) {
        std::cout << e.what() << std::endl;
        std::cout << "Please check if websocket server is initialized" << std::endl;
    }


}
