#include <iostream>

void  setSomethingTo100(int& change) {
    change = 100;
}


int main () {

    // lvalue : something with a memory location . &(i) 이 사용할 경우에도 적용이 된다. 
    // on the left hand side 로 취급하기도 한다. 다만 이 경우에는 기억하기는 좋지만 다 맞는 경우는 아닐 수 있다. 
    int i = 10;

    // rvalue : Does not not poinst anywhre. 그래서 어드레스, location이 없다. 위에서는 10에 해당 
    // (위의 10 같은 경우를 prvalue : pure rvalue 라고도 한다.)
    // on the right side of an assignment

    // 10 = i;
    // 처럼 하게 되면 error: lvalue required as left operand of assignment 발생하는데 

    int a=1;
    int b=2;
    int c= (a+b);
    // lvalue 는 a, b, c
    // rvalue 는 1, 2 , (a+b) 가 된다.  (a + c)는 rvalue로 취급되며 xvalue (expiring value 라고도 함) 
    // (a + b)는 temp 로 생성되었기 때문

    int array[10];
    array[1+b]; // 1+b 로 따로 저장하지 않기 때문에 rvalue


    /// lvalue reference 는  int& i 등을 의미
    /// alias 또는 reference the location or memory를 의미
    i = 20;
    int& ref_i = i;  // lvalue reference

    /// 아래의 코드는 에러가 발생한다.
    // int& ref = 10;
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    /// lvalue reference 이므로 lvalue가 필요한데 10은 rvalue 일 뿐이이서 reference로 사용할 수가 없다.
    
    /// 단,
    /// 컴파일 단계에서 10을 어딘가에 저장해서 ref 가 lvalue로 참조할 수 있게 해준다. 그래서 const 를 붙이면 에러가 발생하지 않는다.
    const int& ref = 10;

    int something = 1;
    setSomethingTo100(something);
    
    // setSomethingTo100(100);
    // error: cannot bind non-const lvalue reference of type ‘int&’ to an rvalue of type ‘int’
    /// 역시 함수에서 파라미터가 lvalue reference 인 경우에는 같은 에러가 발생하게 된다. 


    //// rvalue
    // int& rvref = 10;
    // 이렇게 하면 lvalue reference 에러가 발생한다. rvalue에 bind 할 수 없다고 에러
    
    // 다만 rvalue reference 로 사용하고 싶을 경우에는 
    int&& rvref = 10; // 마치 move sematic 처럼 사용
    // 실제 rvalue reference 로 사용이 가능
    std::cout << "rvalue reference: " << rvref << std::endl;

    std::string str1 = "hello ";
    std::string str2 = "a long long long string example";
    
    // std::string& str3 = str1 + str2;
    // 위의 경우에는 lvalue reference 로는 사용할 수가 없다. 이유는 right side 가 rvalue 이므로  // 물론 그냥 lvalue 로 만들면 되긴 한다 

    std::string&& str3 = str1 + str2;
    // 위 경우에는 rvlaue로 사용되는 str1, str2 는 rvalue 인데, 
    // 어차피 rvlaue로 사용되는 것을 rvalue reference로 사용할 수 있게 할 수가 있다.
    std::cout << "rvlaue reference: " << str3 << std::endl;
    // rvalue reference 는 많이 사용하지는 않을 듯 하지만, 알면 좋다고 생각.

    /// 이를 이해하면 디버깅 에러 메세지 이해가 잘 될 듯 하다. ㅋ

    return 0;

}