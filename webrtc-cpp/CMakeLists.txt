cmake_minimum_required(VERSION 3.10)
project(webrtc-cpp)
set(CMAKE_CXX_STANDARD 17)

# Set the path to your WebRTC build
set(WEBRTC_ROOT "/home/sgtubunamr/third_parties/webrtc-native-build/src")

ADD_DEFINITIONS(-DWEBRTC_POSIX=1)
ADD_DEFINITIONS(-D__STDC_CONSTANT_MACROS=1)

# Include directories for WebRTC headers
include_directories(
    ${WEBRTC_ROOT}
    ${WEBRTC_ROOT}/third_party/abseil-cpp
    ${WEBRTC_ROOT}/out/Release
)

# Add your source files
add_executable(${PROJECT_NAME} src/main.cpp)


# Link against WebRTC libraries
target_link_libraries(${PROJECT_NAME}
    ${WEBRTC_ROOT}/out/Release/obj/libwebrtc.a
)

# Link against system libraries
target_link_libraries(${PROJECT_NAME}
    pthread
)