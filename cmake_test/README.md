# cmake test 
build 디렉토리를 만들고 build 디렉토리내에서 cmake를 하는데 
```
cd build
cmake ..
```
cmake를 하는데 상위 경로의 CMakeLists.txt 파일을 의미하게 되는 것 

그리고 완료되면 build 디렉토리 내에서 make를 하면 된다  

src와 include로 cpp, h 파일 등으로 나눠져 있을 때에도 
`include_directories(  include )` 만 해주면 무난하게 되고, 
실제 cpp파일에서 include 할 때에도 include 디렉토리는 생략하고 파일명만 적어주면된다

```cpp
#include class_a.hpp
```

## cakin 또는 Qt 사용시는 
조금 다른 방법들을 사용해야하는데.. codingClass 의 build_cmake 디렉토리 참고하자   

(가장 쉬운 방법은 qt에서는 executable을 지정하는 곳에 직접 header파일 위치를 적어주는 것)

## 새로운 에디터 
codelite
```
sudo apt install codelite
```

코드::block 이랑 차이점이 있는지 확인해보기


