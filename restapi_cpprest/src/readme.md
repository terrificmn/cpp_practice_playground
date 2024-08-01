
# cpprestsdk
Microsoft cpprestsdk 설치 
```
sudo dnf install cpprest-devel
```

쉽게 설치 가능

우분투
```
sudo apt install libcpprest-dev
```

예제도 꽤 있는 듯 하고,, 좀 더 어려운 듯 하지만 테스트 해봐야할 듯 하다.. 

아마도 이 정도가 cpp에서는 괜찮을 듯 하지만.. 아직은 모르겠다.

## CMakeLists.txt
현재 디렉토리에 있는 CMakeLists.txt 파일을 참고해서 프로젝트를 만들고 빌드 가능

아직은 좀 더 테스트를 해봐야 함



참고 
https://github.com/Microsoft/cpprestsdk/wiki/Samples

https://github.com/Meenapintu/Restweb/blob/master/include/handler.h


## fedora 에서 에러 발생 시
```
CMake Error at /usr/share/cmake/Modules/FindPackageHandleStandardArgs.cmake:230 (message):
  Could NOT find ZLIB (missing: ZLIB_LIBRARY ZLIB_INCLUDE_DIR)
```

다행히 쉽게 설치 가능하다. zlib-ng-compat-devel 을 설치해준다.
```
sudo dnf install zlib-devel
```


### rapidjson
헤더파일만 넣어주고 사용 (/usr/local/include) 에 들어가 있으므로 파일 찾는데는 큰 문제 없다.   

> 공식 깃허브에서 클론 후 include 이하의 rapidjson 파일을 /usr/local/include/ 에 복사해서 사용

