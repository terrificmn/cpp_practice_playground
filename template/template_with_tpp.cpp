#include "template_with_tpp.hpp"

// c++ 17 이상

void myFuntion() {
    myPrint("myFunction");
}


// tpp 파일의 내용을 복사 후 테스트 해보면 에러가 발생
// 물론 header에서 tpp를 주석처리 후 테스트 한다.
// template<typename... Args>
// void myPrint(const Args&... args) {
//     /*
    // template_with_tpp.tpp 에서 내용 복사
//     */
// }



int main() {

    myFuntion();
    myPrint("hello");

    myPrint("hello world", 10, "test", 3.1415, "haha", true);

    return 0;

}