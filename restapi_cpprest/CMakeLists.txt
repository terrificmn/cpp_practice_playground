cmake_minimum_required(VERSION 3.9)
project(cpprestapi)

find_package(cpprestsdk REQUIRED)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE cpprestsdk::cpprest)

