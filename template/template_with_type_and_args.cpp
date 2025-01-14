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


int main() {

    myPrint("hello");

    myPrint("hello world", 10, "test", 3.1415, "haha", true);

    return 0;

}