
# cpprestsdk
Microsoft cpprestsdk 설치 
```
sudo dnf install cpprest-devel
```

쉽게 설치 가능

예제도 꽤 있는 듯 하고,, 좀 더 어려운 듯 하지만 테스트 해봐야할 듯 하다.. 

아마도 이 정도가 cpp에서는 괜찮을 듯 하지만.. 아직은 모르겠다.

## CMakeLists.txt
현재 디렉토리에 있는 CMakeLists.txt 파일을 참고해서 프로젝트를 만들고 빌드 가능

아직은 좀 더 테스트를 해봐야 함



참고 
https://github.com/Microsoft/cpprestsdk/wiki/Samples

https://github.com/Meenapintu/Restweb/blob/master/include/handler.h


## json lib 설치하기
rapidjson을 사용해도 되나, 

다른 라이브러리를 시도해 보려고 함 (jsoncpp, nlohmann json 등 많음)  
이 중 nlohmann/json 시도

https://json.nlohmann.me/home/releases/ 
에서 다운로드 
zip파일 압축을 풀면 include 디렉토리가 생기는데 include 디렉토리의 nlohmann 디렉토리를 자신의 프로젝트 인쿠르드 디렉토리 이동 시켜준다  

find_package() 를 할 필요는 없고, include 디렉토리만 잘 지정해주고 헤더파일만 include 해주면 문제 없이 빌드 된다.

