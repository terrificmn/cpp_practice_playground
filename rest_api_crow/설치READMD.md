# REAS API with CrowCpp
Crow  
A Fast and Easy to use microframework for the web

## 디펜던시
(RHEL) Rocky Linux 기준
```
sudo dnf install asio-devel
```

우분투는 아마도 `sudo apt install libasio-dev` 테스트는 못 해봄

boost 는 패키지는 필요 없는 듯 하다  
~~sudo dnf install boost.x86_64~~
~~sudo dnf install boost-devel.x86_64~~

이유는 일단 Standalone ASIO 를 사용하는 것 같다.
non boost 버전과 boost 버전이 있는데(boost 버전은 boost/asio) 부스트 이하로 들어가는 듯 하다.  
일단 네임 스페이스를 달리해서 사용하므로 둘 다 있어도 가능은 하다고 하지만  
일단 asio 만 설치

> asio 가 없다면, cmake 에서 could not find asio (missing: asio_include_dir)  에러를 띄운다  

그냥 참고...  
> 빌드시 asio 압축파일을 받아서 빌드 하는 방법도 있는데 정확한 설명이 없어서 설치하기가 까다로운 듯 하다.  
./configure 후에 Makefile 을 만들어서 대충 make all? 식으로 하는 듯 한데,,,  
성공은 못했다. 괜히 어렵게 하지 말고 **pre빌드되어 바로 설치**해서 사용하자.



## 설치
[여기 공식 사이트crowcpp.org](https://crowcpp.org/master/getting_started/setup/linux/)

이 중 빌드하는 방법으로 설치
> 여기 cpp_practic 에 직접 설치하지 말고 다른 디렉토리에 설치하자  
예: /home/myuser/third_parties/crowcpp

깃허브 받은 곳으로 이동 후 빌드
```
cd ~/Crow
mkdir build; cd build
cmake ..
```
여기에서 Example, Unit Test가 필요 없다면 cmake 하는 부분을   
`cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF` 로 해서 실행해준다.

준비가 되었다면 컴파일 및 설치
```
sudo make install
```

> 빌드 후에 /usr/local/include/crow/ 경로로 설치된다.


## 이 후 없데이트






