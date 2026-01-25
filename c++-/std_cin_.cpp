
// std::cin 과 std::getline 을 같이 사용할 경우, 특히 cin을 먼저 사용하고 
// 이후 getline을 사용할 경우에는 getline이 무시가 되버린다.  

// cin 은 스페이스바 허용 안되며 한 글자를 받는다
// getline은 엔터가 입력 되기 전까지의 글자 모두를 받음

std::cin >> input;
여기에서 operator >> 가 whitespace 에서는 멈추게 되는데 이때 '\n' 을 input buffer 에 남김

그래서 이어 오는 getline에서 newline 까지 기다려야 하는데 이미 \n가 있는 상태여서  
바로 입력이 된것으로 처리가 된다.  이때는 "" 빈값이 들어간다. 

1. 아예 getline 으로만 사용하는 방법이 있고 

2. cin 과 같이 사용할 경우에는  

std::string input;
std::cin >> input;

std::string user_robot_id;
std::getline(std::cin >> std::ws, user_robot_id);

처럼 사용하는데 std::ws가 whitespace (\n포함) 해서 처리해준다. 그래서 getline이 정상 작동할 수 있게 된다. 


