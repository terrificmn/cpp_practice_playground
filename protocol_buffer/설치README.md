# Protocol Buffer

[protobuf-c++-installation](https://github.com/protocolbuffers/protobuf/blob/main/src/README.md)

## 의존성
g++, bazel, abseil-cpp 등이 있다. 


## bazel 설치 (fedora 설치는 참고만 하자. 실패 로그)
맨 아래 참고.. 필요도 없을 듯 하다.;;

### ubuntu bazel 설치
~~sudo apt install bazel~~

우분투의 경우에는 bazel apt에 바로 등록이 안 되어 있어서 바로 사용은 못 할 수가 있다.   
googlle depot tool에 포함이 되어 있어도 제대로 실행이 안 된다. 

```
sudo apt install apt-transport-https curl gnupg -y
curl -fsSL https://bazel.build/bazel-release.pub.gpg | gpg --dearmor >bazel-archive-keyring.gpg
sudo mv bazel-archive-keyring.gpg /usr/share/keyrings
echo "deb [arch=amd64 signed-by=/usr/share/keyrings/bazel-archive-keyring.gpg] https://storage.googleapis.com/bazel-apt stable jdk1.8" | sudo tee /etc/apt/sources.list.d/bazel.list

```
이후 업데이트 이후 

```
sudo apt update
sudo apt install bazel
```

## fedora cmake 사용하자
아놔, cmake로 사용이 가능한 것을 엄청 돌아왔다;;; bazel 이고 java고 뭐고;; 필요 없다. ;;;

깃허브에서  protobuf 를 클론 받은 후에 cmake 해주면 된다.

[아래 protocol buffer 에서 설명](#protocol-buffer-빌드)



## abseil-cpp 설치
여기에서 클론 후 빌드 

[abseil-cpp](https://github.com/abseil/abseil-cpp)

[quick cmake 참고하자- 잘나와있음](https://abseil.io/docs/cpp/quickstart-cmake) 

깃클론
```
git clone https://github.com/abseil/abseil-cpp
```

```
 cd abseil-cpp/
mkdir build; cd build
cmake ..
```
> cmake 할 때   
Abseil test를 안하게 할려면 -DBUILD_TESTING=OFF 나  -DABSL_BUILD_TESTING=OFF 를  cmake 할 때 넣어준다.
예 camke .. -DBUILD_TESTING=OFF

빌드
```
make
```

/usr/local/ 이하의 경로에 (default로 되어 있음)  설치
```
sudo make install
```

자세한 설치 경로는 완료 로그를 봐서 알 수 있고, /usr/local/include/absl 등에 설치됨     
> 또는 install_manifest.txt 파일에 설치된 것을 보고 확인 가능하다 .

argument -std=c++17
CMake Error: Run 'cmake --help' for all supported options.
[myuser@fedora build]$ cmake .. -DCMAKE_CXX_FLAGS=-std=c++17
-- Configuring done (0.2s)



#### abseil 프로젝트에서 사용할 경우
프로젝트에서 사용할 경우에는 abseil-cpp 디렉토리를 자신이 사용할 프로젝트에 이동 시키거나  
또는 CMakeLists.txt 에서 set으로 경로 지정해도 될 듯 하다. 

권장은
abseil-cpp 을 자신의 프로젝트로 옮긴 후에 git submoudle 로 등록해서 사용  

이후 add_subdirectory() 를 통해서 include 를 해주고,  target_link_libraries() 로 라이브러리를 target 링크해주기  
이때 absl::으로 사용하게 된다 

예
```
cmake_minimum_required(VERSION 3.16)
project(my_app_project)

# Pick the C++ standard to compile with.
# Abseil currently supports C++14, C++17, and C++20.
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(abseil-cpp)

add_executable(my_exe source.cpp)
target_link_libraries(my_exe absl::base absl::synchronization absl::strings)
```

좀 더 자세한 내용은 아래를 참고하자

[abseil설치 READMD 참고](https://github.com/abseil/abseil-cpp/blob/master/CMake/README.md)



 undefined reference to `absl::lts_20240116
 에러


### protocol buffer 빌드
클론 
```
git clone https://github.com/protocolbuffers/protobuf.git
```

> 또는 release된 tar파일을 받는다.


이동 및 submodule update
```
cd protobuf
git submodule update --init --recursive
```
> 기존에 있던 third_party 이하를 다시 클론해주면서 업데이트 해준다.

빌드 하기. 우분투에서는 bazel 을 쉽게 받을 수 있으므로 이 방법도 괜찮다.  
fedora에서는 bazel pre빌드된 버전이 낮아서 cmake로 직접 빌드한다. 

```
bazel build :protoc :protobuf
```

만들어진 실행파일 bazel-bin 이하에 생긴다. /usr/local/bin 에 복사해준다.
```
sudo cp bazel-bin/protoc /usr/local/bin
```

### fedora cmake
이동 후 진행
```
cd protobuf
mkdir build; cd build
cmake ..
cmake --build . --parallel 10
```
> 빌드를 진행

빌드 후 설치(테스트 없이)
```
make
sudo make install
```



공식 문서에서 는 cmake를 protobuf 루트 경로에서 진행을 해서 같은 디렉토리에 만들어진다.   
위 처럼 build 디렉토리 만들고 하는게 더 나은 듯 하다. 
> 하긴 한번 빌드 하고 말꺼라서 큰 의미는 없다. 
```
cmake .
cmake --build . --parallel 10
```

테스트 바로 Makefiles 만들고 install
```
make VERBOSE=1 test
sudo make install 
```







### bazel 설치 그냥 참고만 하자. 성공하지 못함. fedora에 설치 시
protocol buffer 를 설치하려고 할 때 build 를 bazel로 하게 된다.  
Java 와 관계가 있는 듯 하다. 

> 그냥 Java 설치가 필요할 때나 참고하자;;

dnf 에 vbatts/bazel 리포지터리를 등록한 후 사용할 수 있다고 나와 있지만   
공식으로 지원하는 라이브러리가 아니라, 버전은 5 까지 지원 되는 듯 하다.  
결론 부터 말하면 bazel 버전 7.3 이랑 openjdk가 21버전이 필요. (버전5는 openjdk가 11버전)   

리포지터리 추가하는 방법은 참고로 알고 있자...   
```
sudo dnf copr enable vbatts/bazel
sudo dnf install bazel5
```

/etc/yum.repos.d 이하에 _copr:copr.fedorainfracloud.org:vbatts:bazel.repo 파일이 생기고 파일에 repo관련 내용이 있음  
fedora 40에도 작동하나, 

proto버프를 설치하는데  빌드를 하려고 하면 에러 발생 한다.
```
Unrecognized option: --noenable_bzlmod
``` 
에러가 발생하고, 예전 버전이라서 그렇다고 한다.  
아무래도 빌드를 해야하는 듯 하다. 

openjdk-21-jdk 가 필요한데...

`dnf search openjdk` 로 검색을 한 후에 dnf로 <openjdk-package-name> 로 설치를 해주면 된다 .

~~sudo dnf install java-21-openjdk.x86_64~~

OpenJDK 21 Runtime Environment 만 설치가 되어서 java 만 있고 javac 를 포함한 다양한 실행파일이 없다.  이런;;;
1시간을 소비했다. Java를 전혀 몰라서;; 오래걸림;;

search 했을 때 나오는 **devel** 버전으로 깔아준다.
```
sudo dnf install java-21-openjdk-devel.x86_64
```

/etc/alternatives/java_sdk 이하에 설치가 된다.


소스파일을 받아준다.  
https://github.com/bazelbuild/bazel/releases


bazel-7.3.1-dist.zip  다운

적당한 곳에 압축 해제
```
unzip -d bazel-build 파일이름
cd bazel-build
```

이곳에서 env 및 실행
```
export JAVA_HOME=/etc/alternatives/java_sdk
export PATH=$JAVA_HOME/bin:$PATH
env EXTRA_BAZEL_ARGS="--tool_java_runtime_version=local_jdk"

./compile.sh
```

java 빌드 실패;;; 특정 라이브러리를 못 찾는 게 아니라 컴파일 에러 처럼 보인다. 뭐가 없어서 일 수도 있으나  
protocol buffer를 사용하기 위해서 빌드에 빌드... 별로 좋지 않은 듯 해서, 도커로 사용하거나   
다른 방법을 사용해야 할 듯 하다.
