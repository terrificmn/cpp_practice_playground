# cpp practice

해당 패키지에서 
```
g++ -o 실행할파일이름 소스.cpp -l다른라이브러리(필요할경우)
```

## CMakeList 로 cmake로 하려면 

```
cmake_minimum_required(VERSION 3.16)
project(프로젝트명)

set(CMAKE_CXX_STANDARD 17)

include_directories(
    include
)

add_executable(${PROJECT_NAME} 
    src/소스1.cpp 
    src/소스2.cpp
)
```
이런식으로 만들어 준다 

그리고 해당 패키지 내에 `mkdir build` 디렉토리를 만들고   
build 디렉토리로 이동 후 `cmake`, `make` 등을 해주면 된다  
```
cd build
cmake ..
make
```
