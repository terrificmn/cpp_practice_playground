# option 
cpp 소스파일에서 CMakeLists.txt 에서 변수를 셋팅해 줄 수가 있다. 

## option을 사용하기
```
option(ENABLE_SOMETHING "ENABLE_SOMETHING" ON)
```
> ON / OFF 

이후 이 조건을 걸어서 target_compile_definitions() 을 해주면 된다.   
예시

```
if(ENABLE_SOMETHING)
    target_compile_definitions(${PROJECT_NAME} 
        PRIVATE
        VARIABLE_IN_CPP
    )
endif()
```

> 중요한 것은 target_compile_definitions() 에서 변수를 설정할 때 아예 if문에서 안 걸리고  
target_compile_definitions으로 set이 안 되게 되면 해당 변수는 cpp 에서 false 로 처리가 된다.


> 변수는 DEBUG_MODE=0  # Set to 0 for false, 1 for true   
LOGGING_ENABLED=FALSE  # Can use FALSE/TRUE   
VERSION_STR="1.0.0"   
아래 처럼 사용할 수가 있다고 하나, 일단 TRUE/FALSE 는 잘 안되는 듯 했다.

그리고 변수 셋팅이 잘 안되면 build 디렉토리를 지우고 하면 도움이 될 수 있다.

## 빌드 할 경우에 변수가 셋팅
이제 CMakelists.txt 의 option으로 지정한 해당 조건에 따라서 예로는 ENABLE_SOMETHING  따라 변수가 셋팅되게 되고 

`cmake -DENABLE_SOMETHING=OFF ..` 로 직접 빌드 할 경우에도 선택해 줄 수가 있다.


## cpp 에서 사용
이렇게 되면 cpp 파일에서 `#ifdef` 로 사용할 수가 있다.

```cpp
#ifdef VARIABLE_IN_CPP
#include "특정헤더파일.hpp"
#endif

// 또는
#ifdef VARIABLE_IN_CPP
    std::cout << "VARIABLE_IN_CPP true" << std::endl;
#else
    std::cout << "VARIABLE_IN_CPP false" << std::endl;
#endif
```

