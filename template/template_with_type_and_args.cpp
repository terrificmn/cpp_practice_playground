#include <iostream>
#include <sstream>


// c++ 17 이상

template<typename T>
void myPrint(const T& msg) {
    std::cout <<  msg << std::endl;
}

// this template<typename... Args> allows the function to accept any number of arguments of any type.
/// Variadic Template 이라고 한다
template<typename... Args>
void myPrint(const Args&... args) {
    std::ostringstream stream; // to concatenate the argumnents into 'a single string'
    /// fold expression 이라고 한다. parament pack을 concise(clearly)하게 이용할 수 있게 해준다.(17의 기능)
    // (stream <<  ... << args );  // 이 부분은 << operation이 args의 each argument 로 확장해줌 - c++17 기능임

    /// space를 추가하려면 아래와 같은 형식으로 사용해야함, every args 가 들어온 것 만큼 (stream << args << " ")이 수행된다.
    ((stream << args << " "), ...); // Add a space after each argument

    std::string stream_str = std::move(stream.str());
    // remove the last space
    if(!stream_str.empty() && stream_str.back() == ' ') {
        // std::cout << "removed the last space\n";
        stream_str.pop_back();
    }

    std::cout << stream_str << std::endl;
}

/*
추가!!!!!!!
fold expression은 c++17 이상에서 가능한 기능이며, parameter pack이라고 불리는 (Args...) 로   
여러개의 아규먼트를 의미하게 된다.   

  ((stream << args << " "), ...);
이는  
  stream << args1 << " ";
  stream << args2 << " ";
  stream << args3 << " ";
이런 느낌이 된다.  

자동으로 모든 아규먼트에 대해서 처리를 해주게 된다.  

만약 해당 Args로 넘어오는 것을 따로 확인하고 싶으면  
args 부분에서 다른 함수를 만들어서 넘겨주면 된다.   
이때는 args를 넘겨줄 때에는 typename T 로 받을 수가 있다.  

예:
template <typename T>;
std::string isBool(const T& value) {
    if constexpr (std::is_same_v<std::decay_t<T>, bool>) { // compile 단계에서 확인하면 T가 bool 인지 확인하는 작업
        // std::decay_t<T>, bool 은 bool 로 처리될 수 있게 해준다.
        return value ? "TRUE" : "FALSE";  // Convert bool to string
    } else {
        std::ostringstream oss;
        oss << value;
        return oss.str(); //다른 타입이라면 어차피 스트링으로 출력해야하므로 string으로 리턴 해주게 된다.
    }
}

 // fold expression 활용
 ((stream << isBool(args) << " "), ...);

*/



int main() {

    myPrint("hello");

    myPrint("hello world", 10, "test", 3.1415, "haha", true);

    return 0;

}