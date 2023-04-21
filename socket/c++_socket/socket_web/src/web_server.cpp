#include "tcp_listener.h"
#include "web_server.h"

WebServer::WebServer(const char* ip_address, int port) : TcpListener(ip_address, port) {
    // current path: now it's in the build directory
    std::filesystem::path p = std::filesystem::current_path();
    this->pkg_path = std::filesystem::absolute(p.parent_path());
    // std::cout << "path: " << this->pkg_path << std::endl;
}

WebServer::~WebServer() {}

void WebServer::onClientConnected(int client_socket) {

}

// handlr for client disconnections
void WebServer::onClientDisconnected(int client_socket) {

}

// handler for when a message is received from the client
// void MultiClientChat::onMessageReceived(int client_socket, const char* msg, int byte_recv_in) {
void WebServer::onMessageReceived(int client_socket, const char* msg, int length) {  /// 파라미터 확인 필요!
    // GET /index.html HTTP/1.1     // HyperText Transform Protocol
    std::cout << "on Message function\n";
    // procedure
    // Parse out the document requested
    // std::istringstream iss(msg);
    // // 모든 스트링을 스페이스 별로 벡터로 만듬
    // std::vector<std::string> parsed( (std::istream_iterator<std::string>(iss)), std::istream_iterator<std::string>());   // include iterator를 해야함
    
    // // GET으로 넘어왔을 때만 수행하게 하면 실행되게 (블럭안으로 이동) 할 수 있지만,, 그냥 나둠 
    // // 넘어온 msg에서 vector로 만든 것의 [1]인덱스에 파일명이 들어가 있는데  
    // // 그렇지 않은 듯 하다. 그래서 일단은 생략.. 1번에는 파일명이 들어 있지 않다
    // if(parsed.size() >= 3 && parsed[0] == "GET") {
    //     std::cout << "parsed ok\n";
    // }

    // Open the document in the local file system
    // Write the document back to the client
    /// 이런 타입들은 MDN에서 검색해서 찾아 볼 수 있다 
    // HTTP 는 <CR><LF>로 사용된다고 한다. 그래서 
    // 윈도우가 \r\n 을 사용한다, http 메세지는 모든 라인의 끝은 \r\n 이 되어야 한다.
    // 하지만 리눅스 같은 경우에는 \n (즉 line feed)만 처리 해줘도 작동한다

    // 그냥 text/plain 일 경우 (작동 ok)
    // std::ostringstream os_http;
    // os_http << "HTTP/1.1 200 OK\r\n";
    // os_http << "Cache-Control: no-cache, private\r\n";
    // os_http << "Content-Type: text/plain\r\n";  
    // os_http << "Context-Length: 5\r\n";
    // os_http << "\r\n";
    // os_http << "hello";
    /// 여기 위까지는 정해짐 형식, 마지막 줄에서 실제 content의 길이는 Context-Lengh 의 길이가 된다
    ///  content의 길이는 순수 개수임

    /// parsed[1]는 GET 다음의 문자열인, 즉 파일명
    std::string file_full_path = this->pkg_path + "/" + this->www_path;    
    //  + "/" + parsed[1];// 위의 vector를 사용할 시 파일명으로 대체하나, 일단 1인덱스는 아닌듯 하다
    std::cout << file_full_path << std::endl;
    std::ifstream fs(file_full_path);
    std::string context;
    std::ostringstream os_http;
    
    if(fs.good()) {
        // 읽은 파일의 처음부터 끝까지 char로 만들어서 스트링으로 만듬
        // istreambuf_iterator는 <char>로 읽어서 스트링으로 만들어준다 (현재는 fs 열린 파일로부터..)
        // std::basic_streambuf 오브젝트로부터 single-pass로 입력을 해주는 iterator이고 케릭터를 읽어 카피를 한다
        // c++에서는 공식적으로는 streams를 이용하는 방법인데 그 중에 하나가 istreambuf_iterator를 이용 --codingClass c++ string부분 참고하기
        context = std::string( (std::istreambuf_iterator<char>(fs)), std::istreambuf_iterator<char>());
        std::cout << "context : " << context << std::endl;
        
    } else {
        // context = "<h1>Hello World</h1><h2>This is a web server over the TCP socket</h2><h3>Is is very interesting</h3>";
        context = "<h1>404 Not Found</h1>";
    }

    fs.close();
    this->makeHeader(context, &os_http);  // os_http는 일단 만들어지고 true 리턴됨, 포인터로 직접 수정하므로 주의

    std::string output = os_http.str();
    // std::cout << output << std::endl;
    // int size = output.size() +1; // 여기에서는 전체길이에 +1 사이즈를 해주면 안된다. 
    // 중요: 그냥 size()나 length()를 이용해서 구해준 값을 넘겨야 한다. 
    // string은 c_str()로 변환해서 넘기지만, 길이는 +1 해줄 필요가 없다. 오히려 +1을 해주면 send()는 하지만
    // 브라우저에서 +1값을 기다리는 꼴이 된다 . 그래서 브라우저에서는 반응이 없고 계속 기다리는 중인듯 하다

    // 길이를 넘겨줄 때에는 http 헤더까지 포함한 길이를 넘겨준다. 
    this->sendToClient(client_socket, output.c_str(), output.length());


}

bool WebServer::makeHeader(std::string context, std::ostringstream* ptr_os) {
    ptr_os->clear();
    int context_size = context.size();
    /// html header
    *ptr_os << "HTTP/1.1 200 OK\n";
    *ptr_os << "Cache-Control: no-cache, private\n";
    *ptr_os << "Content-Type: text/html\n";  
    *ptr_os << "Context-Length: " << std::to_string(context_size) << "\n";  
    *ptr_os << "\n";
    *ptr_os << context;

    return true;
}
//     // Broadcast a message from a client
// void WebServer::broadcastToClients(int sending_client, const char* msg, int length) {

// }

part2  36:00 부터.....