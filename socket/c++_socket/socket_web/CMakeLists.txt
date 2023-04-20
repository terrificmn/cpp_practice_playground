cmake_minimum_required(VERSION 3.16)
project(socket_web)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
    # src/multi_client_chat.cpp 
    src/tcp_listener.cpp
    src/web_server.cpp
)

# by gunther