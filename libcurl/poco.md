# libpoco 를 사용하는 경우

CMake 에는 
```
find_package(Poco REQUIRED Net)
```

target link는 
```
target_link_libraries(${PROJECT_NAME} Poco::Net )
```

이런식으로 해준다.


poco 라이브러리는 ftp 말고도 다른 기능들이 많다. 사용을 해보지는 못했지만...

ftp 도 당연히 잘 작동하지만,    
> 물론 poco 라이브러리가 문제가 아니고  *잘 사용을 못 한 탓이지만*   
그냥 libcurl 로도 해봤는데 좀 더 쉽게 된 듯 하다.