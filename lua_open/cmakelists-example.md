# lua - CMakelists.txt example
보통, 우분투 20.04 기준으로는 lua 5.2 버전이 설치 되어 있는데,   
기존에 설치되어 있는 것으로는 find_package() 등이 잘 안되는 듯 하다.   
패키지를 잘 못 찾는 듯 하다.

https://www.lua.org/download.html 다운로드 페이지에서 binaries 를 클릭해서 다운을 받는다. 

lua-5.4.2_Linux54_64_lib   우분투 20.04 에는 linux54_64 버전이라고 함  
압축을 풀어서 헤더파일은 아래 경로로 이동  
`/usr/include/lua54`

.so파일과 .a 파일은 아래 경로로 이동  
`/usr/local/lib`

이후 아래의 CMakeLists.txt 파일 내용을 참고해서 find_package 및 include, target_link_libraries 를 해주면 잘 찾는다.   

추후 다시 시도할 경우, 기존에 깔려있는 상태에서 아래 CMakeLists.txt 파일 참고해서 빌드 시도 및 테스트 필요!   
그래도 안되면 5.4 버전 받아서 진행

```py
cmake_minimum_required(VERSION 3.0.2)
project(myProject)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++14)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(Lua REQUIRED)

###########
## Build ##
################## 이하 ROS 로 빌드하려면 ##########################
################## catkin 관련을 추가해야한다 ##########################
## 아래의 catkin_package(), include_directories(), target_link_libraries()등을 아래처럼 추가해준다.
## ros 없이 빌드할 경우는 아래는 생략하면 된다.
# catkin_package(
# #  LIBRARIES myProject
#     CATKIN_DEPENDS roscpp
# #  DEPENDS system_lib
# )
# include_directories(
#     ${catkin_INCLUDE_DIRS}
# )
# target_link_libraries(${PROJECT_NAME}
#     ${catkin_LIBRARIES}
# )
# target_link_libraries은 한개 밖에 안 되므로 ${catkin_LIBRARIES} 만 넣어서 사용해주면 된다.
#############################################################

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
    # inclue
    ${PROJECT_SOURCE_DIR}/include
    ${LUA_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME} 
    src/main.cpp 
)

target_link_libraries(${PROJECT_NAME}
    ${LUA_LIBRARIES}
)
```

lua 헤더파일과, target_link_libraries를 해주는 것이 중요

