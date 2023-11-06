# REAS API with CrowCpp
Crow  
A Fast and Easy to use microframework for the web

## 디펜던시
(RHEL) Rocky Linux 기준
```
sudo dnf install asio-devel
```

우분투는 `sudo apt install libasio-dev` 로 설치해준다.

boost 는 패키지는 필요 없다.  
~~sudo dnf install boost.x86_64~~  
~~sudo dnf install boost-devel.x86_64~~

이유는 일단 Standalone ASIO 를 사용하는 것 같다.
non boost 버전과 boost 버전이 있는데(boost 버전은 boost/asio) 부스트 이하로 들어가는 듯 하다.  
일단 네임 스페이스를 달리해서 사용하므로 둘 다 있어도 가능은 하다고 하지만  
일단 asio 만 설치

> asio 가 없다면, cmake 에서  
:146 (message):  
  Could NOT find asio (missing: ASIO_INCLUDE_DIR)  
Call Stack (most recent call first):  
하고 에러가 발생한다.

그냥 참고...  
> 빌드시 asio 압축파일을 받아서 빌드 하는 방법도 있는데 정확한 설명이 없어서 설치하기가 까다로운 듯 하다.  
./configure 후에 Makefile 을 만들어서 대충 make all? 식으로 하는 듯 한데,,,  
성공은 못했다. 괜히 어렵게 하지 말고 **pre빌드되어 바로 설치**해서 사용하자.



## 설치
[여기 공식 사이트crowcpp.org](https://crowcpp.org/master/getting_started/setup/linux/)

이 중 빌드하는 방법으로 설치
> 여기 cpp_practic 에 직접 설치하지 말고 다른 디렉토리에 설치하자  
예: /home/myuser/third_parties/crowcpp

```
git clone https://github.com/CrowCpp/Crow.git
```

깃허브 받은 곳으로 이동 후 빌드
```
cd ~/Crow
mkdir build; cd build
```

cmake 옵션 설정해주기 -Crow 에서는 옵션을 주는 것이 있는데..  

여기에서 Example, Unit Test가 필요 없다면 cmake 하는 부분을   
`cmake .. -DCROW_BUILD_EXAMPLES=OFF -DCROW_BUILD_TESTS=OFF` 로 해서 실행해준다.

> 즉 아무 옵션을 안 주면 exmaple, unit test 등을 만들어 준다. 

또한  `-DCROW_FEATURES="ssl;compression"` 의 옵션은 ssl, compression 등을 가능하게 해주는 옵션   

결론은 다른 옵션은 필요없이 진행하면 될 듯 하다. 옵션 관련 문제는 아래 참고!

이어서 cmake 를 해준다.
```
cmake ..
```
을 해서 configuration 을 마무리 해준다. 의존성 잘 설치되어 있으면 무난하게 아래와 같은 메세지를 볼 수 있다   
```
-- Configuring done
-- Generating done
-- Build files have been written to: /home/myuser/third_paties_libs/Crow/build
```
컴파일 준비가 완료가 됨, 이제 설치한다. 


```
sudo make install
```

> 빌드 후에 /usr/local/include/crow/ 경로로 설치된다.








## dependencies 설치
dependencies 에 깃클론을 해준다.  
먼저 redis

```
git clone --recurse-submodules https://github.com/cpp-redis/cpp_redis.git
```


## new project
새로운 Crow을 이용해서 새로운 프로젝트를 만들려면  g++ 직접 빌드 및 cmake 활용이 있다

### g++ 빌드
일단 직접 빌드할 경우 현재 패키지가 있는 곳으로 이동
```
cd ~/rest_api_crow
g++ -o crow_test main.cpp -lpthread
```

바로 src 디렉토리에 실행 파일이 crow_test 로 만들어지고 실행은  
```
./crow_test
```
브라우저 endpoint에는 아래 참고

### CMakeLists 만들어서 cmake 빌드
또는 CMakeLists.txt를 만들어서 사용하는 경우에는 Crow 라이브러리를 넣어준다
```
find_package(Crow)
target_link_libraries(your_project PUBLIC Crow::Crow)
```

> rest_api_crow 패키지 아래의 CMakeLists.txt 파일을 참고하자

이후 build 디렉토리를 만들고 cmake 를 해주면 됨
```
mkdir build; cd build
cmake ..
```
Makefile를 만들어주는데 이후 빌드를 해준다.

```
make all
```

## 실행하기
이제 실행 파일은 rest_api_crow 프로젝트 이름으로 생성이 된다. 

> build 디렉토리에 생성이 된다.

실행
```
./rest_api_crow
```

이후 브라우저에 `localhost:8000/` 를 입력해주면 브라우저에 Hello, world 가 표시된다. 


굿!


## 새로운 프로젝트에서 cmake 로 빌드시 에러 발생
```
CMake Error at /usr/local/lib/cmake/Crow/CrowConfig.cmake:41 (if):
  if given arguments:

    "compression" "IN_LIST" "CROW_FEATURES"

  Unknown arguments specified
Call Stack (most recent call first):
  CMakeLists.txt:12 (find_package)
```

cmake 를 할 때 위의 CrowConfig.cmake 파일에서 참고를 해서 실행하는데   
자꾸 arguments 가 없다고 하면 에러가 발생한다. 


위에서 최초 Crow 라이브러리를 빌드할 때 DCROW_FEATURES 옵션을 넣거나 뺄 수가 있는데   
- 빼게 되면    
set(CROW_INSTALLED_FEATURES "OFF") 로 설정이 된다. 
- 넣게 되면   
set(CROW_INSTALLED_FEATURES "ssl;compression") 로 설정이 된다. 

그래서 잘 작동할 수 있게 되어 있는 듯 하다. 어쨋든 잘 되어 있음에도 불구하고 계속 없다고 에러 발생   

해결책은 CMakelists.txt 에서  cmake 최소 버전을 설정해줘야한다. (3.15 이상으로 설정)
```
cmake_minimum_required(VERSION 3.15.0)
```

기존 ROS Noetic 기준에서는 VERSION 3.0.2 정도 나오데, 이를 바탕으로 만들다보니   
버전이 낮아서 나오는 문제 인 듯하다.  

다행히 버전을 높여주니 문제 없이 잘 빌드 되었다.






