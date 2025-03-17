

find_package(CURL REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE CURL::libcurl)


의존성 설치 - 페도라 sudo dnf install libcurl-devel
우분투 sudo apt install libcurl4-openssl-dev