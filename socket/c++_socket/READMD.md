# c++ socket
기본적으로는 c socket을 사용하는데,, c++적인 요소는   
string으로 만들어서 c_str() 로 변환하거나, printf 대신에 std::cout/cerr 등을 사용

기본적 설명은 c_socket도 참고하면 되고   
리눅스에서 man 페이지로 접근해서 메뉴얼을 볼 수 있다 - 이점은 꽤 좋은 듯 하다

c 에서 사용한 함수들을 거의 볼 수 있는 듯하다. 
```
man socket
```
등등. 이 밖에도 많이 가능하다 

## 빌드는 g++
g++ 로 빌드를 해주면 된다
```
g++ -o server server_main.cpp
```
