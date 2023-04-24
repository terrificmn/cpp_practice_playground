#include <iostream>
#include <string>

// void Print(int value) {
//     std::cout << value << std::endl;
// }

// void Print(std::string value) {
//     std::cout << value << std::endl;
// }

// void Print(float value) {
//     std::cout << value << std::endl;
// }

// 위의 함수들을 오버로드해서 만드는 것이 아니라, template를 만들어서 그 것을 파라미터로 사용
// T 는 변수처럼 바뀔 수 있다 (T를 많이 사용함)
// typename 에 type이 아닌 class를 사용할 수 있다. --- class를 사용할 경우 
// 이때 main 함수 등에서 호출을 할 때에는 <typename> 으로 예 함수명<int>()  이렇게 호출하게 된다
template<typename T>
void Print(T value) {
    std::cout << value << std::endl;
}


int main(int argc, char* argv[]) {
    // 이렇게 숫자를 파라미터로 받는 함수가 있다고하면 당연히 숫자를 넘겨야함
    Print(5);
    // 하지만 다른 유형의 데이터를 넘겨서하고싶을 때에는 같은 함수를 파라미터 형태가 바뀐 것을 계속 만들어줘야함
    // 그러면 함수이름은 같지만 파라미터의 데이터 타입이 다르므로 오버로드가 된다 '
    Print("Hello World");
    Print(5.32f);
    

    // template 을 사용할 경우에는 함수 이름 뒤에 type을 지정해준다
    Print<int>(15); 

    // template를 사용할 경우 type을 생략해도 인자로 넘어간 값을 컴파일 하면서 파라미터의 타입이 결정
    Print(10); 

    Print<std::string>("Hello Again!");

    // template은 진짜 템플릿이다. 그래서 호출을 하기 전에는 존재하지 않는다.  이거는 참고만.. 
    // syntax 에러가 있더라도 컴파일러에서는 에러를 발생 시키지 않고 넘어가는 경우도 있음
    // g++ 컴파일러는 에러를 잡아내지만...;;
    

    std::cin.get();
}