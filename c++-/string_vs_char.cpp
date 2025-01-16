
array로 string literal 을 해놓을 경우에 전혀 프로그램 내에서 변경할 필요가 없는 경우에는  
const char * 로 만드는 것이 좋다고 함. (c style)

std::string은 mutable 이어서 변경할 수 있게 되는데  (변경 가능한 스트링)
const char* 로 먄들면 변경할 수 없게 되는 경우에 사용할 수가 있다.

컴파일 할 때 executable에 만들어 지는데 프로그램을 시작하면 char* 는 메모리에 프로그램이 올라가면 
다른 곳에 할당하는 것이 아니라(예를 들어 다이나믹 heap할당 등), 
메모리에 올라간 그 프로그램 자체내에 string literal을 포인팅 하게 되어서 좋다고 함

단점은 char 를 사용하면 길이를 알 수 없어서 strlen 등을 사용해야한다

std::string 이 15 bytes (charcter) 라면 heap alocation이 된다.



헤더에서는 using namespace 를 사용하지 말자. 

constexpr 키워드를 사용하게 되면  complile time 에 만들어지게 된다.