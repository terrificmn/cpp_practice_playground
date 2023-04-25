#include <string>
#include <iostream>
#include <array>
#include <functional>

// 원래 cpp에서는 리턴은 한가지 타입만 리턴할 수가 있지만..  
// 파이썬 처럼 값을 리턴을 여러가지 타입등으로 리턴해 준다던가는 허용이 안된다 

// 그래서 & 참조 연산자를 통해서 주소를전달하고 직접 수정하는 하는 방법이 있다

struct ReturnStruct {
    std::string number1;
    std::string number2;
};

void myFunction(int& num, std::string& str) {
    // ...생략
    int result1 = 10;
    std::string result2 = "hello";

    num = result1;
    str = result2;
}

void myFunctionPointer(int* num, std::string* str) {
    // ...생략
    int result1 = 100;
    std::string result2 = "by pointer";

    if(!num) {
        std::cout << "since it's nullptr, it won't change anything\n";
    } else {
        *num = result1;
    }
    *str = result2;
}

std::string* myFunctionReturnPointer() {
    // ...생략
    std::string result1 = "200";
    std::string result2 = "returning pointer~~";

    /// heap으로 new 로 할당. delete를 신경써야 하고, 퍼포먼스 면에서는 분리(거의 상관없지 싶다;;)
    return new std::string[] { result1, result2};
}


/// array는 stack으로 만들어짐,
// 반대로 vector로 할려면 std::vector<std::string> heap 방식이고, 사이즈를 지정할 필요가 없다
std::array<std::string, 2> myFunctionReturnArray() {
    std::string result1 = "100";
    std::string result2 = "array";

    std::array<std::string, 2> array = {result1, result2};
    return array;
}


/// 튜플을 이용하는 방법, 리턴 받은 데이터를 처리할 때 조금 번거로울 수도 있다
// functional 을 인크루드 한다
std::tuple<std::string, std::string> myFunctionTuple() {
    std::string result1 = "1000";
    std::string result2 = "tuple tuple tuple";

    return std::make_pair(result1, result2);
}


// struct 을 만들고 여러 값을 넘겨준다 
ReturnStruct myFunctionStruct() {

    std::string result1 = "500";
    std::string result2 = "this is struct";

    // 심플하게 {} 브래켓으로 리턴을 해주면 되고   함수 호출한 부분에서 struct로 만들어서 받으면 됨
    return {result1, result2};
}


int main() {
    int a = 20;
    std::string b = "hello world";

    std::cout << a << " " << b << std::endl;
    // 함수에서 reference를 받아서 string 카피가 없이 바로데이터를 바꿔버린다
    myFunction(a, b);

    
    
    std::cout << a << " " << b << std::endl;


    //또는 좀 더 확실하게 포인터로 대체해서 전닳하는 방법이 있다
    myFunctionPointer(&a, &b);
    std::cout << "pointer pass: " << a << " " << b << std::endl;
    // nullptr을 줄 경우에는 펑션에서 예외처리를 확실하게 해줘야한다
    myFunctionPointer(nullptr, &b);
    std::cout << "when nullptr pass: " << a << " " << b << std::endl;

    // 또 다른 방법으로는 list, array등의 포인터를 만들고 포인터를 리턴 받는다. 
    // 안 좋은 점은 pointer래서 사이즈를 알 수가 없다. 정확한 값이 안나온는 듯 하다;;
    std::string *result = myFunctionReturnPointer();
    std::cout << result->size() << std::endl;
    std::cout << "returned pointer: " << result[0] << "  " << result[1] << std::endl;

    // 아예 array를 받는 방법도 있다
    std::array<std::string, 2> result2 = myFunctionReturnArray();
    std::cout << "array returned: " << result2[0] << "  " << result2[1] << std::endl;


    // 튜플을 이용
    std::tuple<std::string, std::string> result_tuple = myFunctionTuple();
    // 대신에 튜플의 값은 인덱스로 가지고 와야한다 std::get<num>(변수)  를 사용
    // index로 구분하기 어려울 수도 있다
    std::cout << std::get<0>(result_tuple) << " " << std::get<1>(result_tuple) << std::endl;
    

    /// struct 을 이용한 방법. 확실하게 어떤 엘리먼트가 있는 지 확실하게 알 수 있고, index 등으로 접근할 필요가 없다  
    ReturnStruct result_struct = myFunctionStruct();
    std::cout << "return struct: " << result_struct.number1 << " " << result_struct.number2 << std::endl;
    return 0;
}