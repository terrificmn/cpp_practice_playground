cmake_minimum_required(VERSION 3.9)
project(restapi_cpprest)

find_package(cpprestsdk REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(${PROJECT_NAME} src/main.cpp src/my_handler.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)