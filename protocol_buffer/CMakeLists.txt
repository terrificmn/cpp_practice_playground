

cmake_minimum_required(VERSION 3.8)

project(protocol_buffer)

# Abseil requires C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(ABSL_PROPAGATE_CXX_STD ON)

find_package(Protobuf REQUIRED)

# Process Abseil's CMake build system
add_subdirectory(abseil-cpp)

add_executable(${PROJECT_NAME}
    main.cpp
    addressbook.pb.cc
)

# Declare dependency on the absl::strings library
target_link_libraries(${PROJECT_NAME} 
    ${Protobuf_LIBRARIES}
    absl::base
    absl::strings
    absl::synchronization
)

# Include protobuf headers
target_include_directories(${PROJECT_NAME} PUBLIC
    ${Protobuf_INCLUDE_DIRS}
)