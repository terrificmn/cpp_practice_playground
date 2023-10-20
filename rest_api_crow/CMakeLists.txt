cmake_minimum_required(VERSION 3.15.0)
project(rest_api_crow)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# set(CROW_FEATURES ssl compression)
find_package(Crow REQUIRED)

## 의존성 패키지 
# add_subdirectory(dependencies/cpp_redis) (아직 테스트 전)
## boost를 인쿠르드 함 - 테스트 안 해봄 (기본예제는 필요 없음)

## 현재 Crow는 /usr/local/include/crow 설치되어 있으나, include는 안해도 된다.1
include_directories(
    # include
    # /usr/local/include/crow/
)

# include_directories(${CMAKE_CURRENT_SOURCE_DIR}/dependencies/cpp_redis/includes)


add_executable(${PROJECT_NAME} 
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    Crow::Crow
    pthread
    # cpp_redis
)

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)