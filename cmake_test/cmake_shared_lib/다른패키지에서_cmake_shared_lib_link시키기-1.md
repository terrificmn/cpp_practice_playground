# 
1.cmake_shared_lib_만들기.md 를 참고하자


그냥 간단하게 so 파일 및 include 디렉토리 지정하기
```
### 내 so 파일이 있는 경로를 지정하고 변수로 셋팅해준다.
find_library(LIB_CUSTOM_COUT NAMES custom_cout PATHS /usr/local/lib/custom_cout)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    /usr/local/include/custom_cout/include
)

##내 파일이 있는 경로 ## target_link_libraries() 했을 때 필요 없을 수도 있다. 테스트 못 해봄
link_directories(
    /usr/loca/lib/custom_cout
)

target_link_libraries(my_new_pkg
    PRIVATE
    ssh
    ${LIB_CUSTOM_COUT}
)
```



2.cmake_shared_lib_find_package_만들기.md 를 사용해서 CMake 파일이 있어서   
find_package()가 가능한 경우 사용 예
```
cmake_minimum_required(VERSION 3.10)
project(my_new_program)


find_package(mylib REQUIRED)
add_executable(my_new_program main.cpp)

target_link_libraries(my_program PRIVATE ${MYLIB_LIBRARIES})
target_include_directories(my_program PRIVATE ${MYLIB_INCLUDE_DIR})
```

#### 실제로는 아래 처럼 사용함
```
find_package(custom_cout REQUIRED)
target_link_libraries(my_new_program
    ${LUA_LIBRARIES}
    ${CUSTOM_COUT_LIBRARIES}
)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${LUA_INCLUDE_DIR}
    ${CUSTOM_COUT_INCLUDE_DIR}
)
```

그리고 새로운 프로그램인 my_new_program 의 main.cpp 등에서는 
```cpp
#include <custom_cout/custom_cout.hpp>
// 이런식으로 사용해서 코드를 작성하면 된다
```