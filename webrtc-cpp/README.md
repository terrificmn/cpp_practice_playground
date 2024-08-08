# webrtc-cpp
[참고 깃허브webrtcexample](https://github.com/Tohntobshi/webrtcexample)   

[읽을거리 블로그](https://velog.io/@devdynam0507/WebRTC-Native-C-API%EB%A1%9C-SFU-%EB%B0%A9%EC%8B%9D1N-%EA%B5%AC%ED%98%84%ED%95%98%EA%B8%B0)



### depot_tools
Chromium 을 설치하는데 도움을 주는 툴.  
[webrtc-org-빌드참고문서](https://webrtc.github.io/webrtc-org/native-code/development/)

fetch, gn 빌드 시스템, gclient 등을 사용
먼저 webrtc-native 빌드하려면 depot_tools가 필요

클론을 원하는 장소에 해준다. 
```
git clone https://chromium.googlesource.com/chromium/tools/depot_tools.git
```

export를 해서 depot_tools 경로를 넣어준다.
```
export PATH="$PATH:`$HOME/depot_tools`"
```
계속 사용하려면 ~/.bashrc 에 넣어주자.

> 이제 fetch 등의 명령어를 사용할 수가 있다.


원하는 경로에 디렉토리를 만들어 준다.
```
mkdir webrtc-native-build
cd webrtc-native-build
```

이후 fetch 명령을 사용해서 실행
```
fetch --nohooks webrtc
```

약 5~10분 정도 걸렸으며, 파일들이 클론된 듯 하다. 

src 디렉토리에서 
```
gclient sync
```

소스 코드를 synchronizing 하는 작업을 해준다.


## 빌드 WebRTC 라이브러리
빌드는 ninja를 사용, GN 을 이용함  

src 디렉토리 (release 빌드)
```
gn gen out/Release --args='is_debug=false is_component_build=false rtc_include_tests=false'
```

> out/Release 디렉토리가 생김    
out/Default 이런식으로 정할 수가 있다.  
`gn gen out/Default --args='is_debug=false'` 해도 큰 문제는 없는 듯 하다.  


빌드하기전에 현재 args.gn 파일의  
```
gn clean out/Release
```

컴파일
src 디렉토리에서 
```
ninja -C out/Release
```


## obj 디렉토리에 .a파일
out/Release 디렉토리에 라이브러리 및 header 등이 생김

out/Release/obj 이하에 `libwebrtc.a`

header 파일은 src 디렉토리, 즉 webrtc-native-build/src 안에 보면 있음   

예를 들어 
peer_connection_interface.h 파일은 "api/peer_connection_interface.h"   


## CMakeLists.txt
위에 까지의 과정은 이제 libwebrtc 를 빌드하기 위한 과정이었고,   

내 프로젝트에 넣어줄 때에는 include 패스와 , libwebrtc.a 파일 target_link 해주고  
하면 빌드할 수 있다.


CMakeLists.txt 파일을 참고하자

아직 이게 뭔지는 잘 모르겠지만, 이게 안들어가면 빌드 실패
```
ADD_DEFINITIONS(-DWEBRTC_POSIX=1)
ADD_DEFINITIONS(-D__STDC_CONSTANT_MACROS=1)
```

webrtc-native-build/src/out/Release/obj  이하에 있는 a 파일을 link 해준다.   
target_link_libraries() 에 libwebrtc.a

include_directories() 잘 지정해주면   


## 최종 빌드 및 실행
프로젝트 root에서 build 디렉토리 만들고 `cmake ..` 해주기   
```
mkdir build; cd build
cmake ..
make
```
빌드가 된다.

이후 build 디렉토리에서 실행
```
./webrtc-cpp
```


