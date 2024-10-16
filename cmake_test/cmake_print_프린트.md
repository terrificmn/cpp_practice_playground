# CMakeList.txt 프린트 로그

```
message(FATAL_ERROR ${CMAKE_CURRENT_BINARY_DIR})
```
이 message를 만나면 에러 메세지를 띄우고 빌드가 종료 된다.   단순히 변수 확인할 경우에 좋을 듯   
> 사실은 문제가 생겼을 때 로그 띄우고 종료로 많이 사용하는 듯 하다.



cmake_print_variables() 사용
```
include(CMakePrintHelpers)
 cmake_print_variables(${CMAKE_CURRENT_SOURCE_DIR})
```



