cmake_minimum_required(VERSION 3.0.0)
project(cmake_test VERSION 0.1.0)

add_executable(${PROJECT_NAME} src/main.cpp src/class_a.cpp)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
)

# target_link_libraries(${PROJECT_NAME} )
