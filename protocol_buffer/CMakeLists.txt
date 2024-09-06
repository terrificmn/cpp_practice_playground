

cmake_minimum_required(VERSION 3.8)

project(protocol_buffer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Protobuf REQUIRED)

include_directories(
    ${PROJECT_SOURCE_DIR}
    # ${Protobuf_INCLUDE_DIRS}
)

add_library(proto
    ${PROJECT_SOURCE_DIR}/addressbook.pb.cc
    ${PROJECT_SOURCE_DIR}/addressbook.pb.h
)

add_executable(${PROJECT_NAME}
    main.cpp
    addressbook.pb.cc
)

# Declare dependency on the absl::strings library
target_link_libraries(${PROJECT_NAME} 
    proto
    ${Protobuf_LIBRARIES}
)

# Include protobuf headers
target_include_directories(${PROJECT_NAME} PUBLIC
    ${Protobuf_INCLUDE_DIRS}
)