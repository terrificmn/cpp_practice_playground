
#include <functional>

// function을 이용해서 람다 함수를 만들 수가 있다. 
// std::function<> 안의 type 에는 처음에는 리턴 타입 아래 예는 void, ()는 넘길 파라미터가 되겠다.  
// 람다와 같이 맞춰주면 된다.
// [] 안에 & 는 함수 밖에서 레퍼런스로 받아서 사용하겠다는 것
// 람다 함수 []() 여기에서 페런시스 부분은 파라미터가 되겠다.
// 추가로 리턴할 값이 있다면 -> int  이런식으로 사용할 수 있다.

std::function<void(bool)> recurLoop = [&]() {
    for(int i=0; i< 3; ++i) {
        /// do something

        if(/*특정 컨디션에서 람다를 작동 시켜준다.예 i 가 1일 경우에*/ i==1) {
            recurLoop();
        }
    }
};

// 대충 이런식인데...업데이트가 필요하다;;