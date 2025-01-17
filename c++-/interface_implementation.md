# hpp 와 cpp파일

## inferface
h, hpp 파일들은 inferface 역할을 하며, class, function 등의 declaration 등을 하게 된다.
header 가드을 꼭 해줘야 한다. 이는 define이 안되어 있으면 define을 해서 header 파일이 여러번 사용이 안되게 한다.
```h
#ifndef MY_FUNCTION
#define MY_FUNCTION

int add(int a, int b);

#endif
```
> MY_FUNCTION 가 정의가 안 되어 있으면 define 해주고, 이하 내용을 사용



## implementation
실제 정의된 함수, 클래스 등이 어떤 일을 하는 지에 대한 코드이다.  

cpp, cc 등의 파일을 heaer 파일을 include 해서 사용을 하게 되는데, 이는 header 파일을 마치 cpp 위에 복사한 것 처럼 된다.   
거의 모든 경우에 hpp, h 파일, 헤더파일만 include을 해서 사용

컴파일 할 경우에는 모든 cpp 파일을 명시해줘야 한다. 
예를 들어
```
g++ main.cpp my_function.cpp -o prog
```

## The reason for separating files
interface 와 implementation 으로 나눠서 사용하는 이유는 코드를 숨길 수도 있고, 컴파일을 쉽게 할 수도 있게 하고,   

예를 들어 cpp 파일들만 따로 컴파일을 할 수가 있는데 
위의 예 처럼 한꺼번에 하는 것이 아니라 하나씩 해주게 된다. 그러면 o 파일이 생기는데 
```
g++ main.cpp
```
이렇게 하면 main.o 파일이 생기고
```
g++ my_function.cpp
```
역시 my_funtion.o 파일이 생기게 된다. 

최종적으로 
```
g++ main.o my_function.o -o prog
```
이렇게 작업을 할 수가 있다. 즉 코드가 늘어나서 특정 cpp 파일의 코드만 변경이 되었다면 컴파일을 따로 할 수 있는 것이다.
my_function.cpp 파일의 내용만 바뀌었다면 해당 코드만 컴파일을 진행할 수가 있다.


