# install 사용하기
`cpp에서 std::filesystem::copy()`를 사용할 경우에 퍼미션 때문에 사용하기가 어렵다.  
이럴 때 그냥 CMakeLists.txt 파일을 만들고 설치를 하게 할 수 있다.  
> 물론 sudo 로 실행 해야한다.  터미널 환경이라면 크게 문제 없다  
물론 shell script 를 만들어서 할 수도 있지만 cmake install도 활용 할 수 있다.

빌드 자체가 필요 없을 경우에는 
```
cmake_minimum_required(VERSION 3.10)
project(InstallOnly NONE)
```
project 에서 NONE을 해주면 build가 필요 없다는 의미로 사용  
이렇게 되면 `make` 키워드가 필요 없고


상위 디렉토리 알아내기
```
get_filename_component(PARENT_DIR "${CMAKE_CURRENT_SOURCE_DIR}" DIRECTORY)
```
근데 현재 CMakeLists.txt 파일이 있는 곳에서 상위 디렉토리가 나오고 

그냥 현재 디렉토리를 사용하려면 CMAKE_CURRENT_SOURCE_DIR 를 사용


인스톨 개별 파일 복사
```
install(FILES
    $copy_file_from_path/file.so
    DESTINATION lib
)
```

디렉토리 전체 recursive 로 설치할 경우
```
install(DIRECTORY ${OPEN3D_DIR}/share/resources
        DESTINATION share
        FILES_MATCHING PATTERN "*.hpp"
)
```

> 예   
share/resources/test.h, share/resources/test2.file 따위가 된다.  

주의할 점은 디렉토리를 전체를 복사 인스톨 하기 때문에 복사할 위치/resources 가   
system 디렉토리인 share 이하에 resources 상태로 복사가 된다.    
만약 share/test.h, share/test2.file 처럼 하고 싶을 경우에는   
resources 디렉토리 말고 안의 파일만 사용하려면 아마도 FILES 방식으로 사용해야할 수 있다.  

> 패턴 필요 없이 모두 복사 하려면 PATTERN 은 생략해준다.  
제외 시키려면 `PATTERN "*.hpp" EXCLUE`


# cmake
build 디렉토리를 만들고 `mkdir build&& cd build`  
```
cmake .. -DCMAKE_INSTALL_PREFIX=/usr
```
PREFIX 를 정해주면 install 시 DESIINATION 에 붙어서 경로가 정해진다. 

이후 인스토만 필요한 cmake 이므로 그냥 sudo 를 이용해서 cmake 실행

```
sudo cmake --install .
```
> 단, CMake 3.15 이상

일반적인 사용 방법 
```
make
sudo make install
```

