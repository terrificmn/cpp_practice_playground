/*
header file 만으로 (또는 cpp) template 함수를 지정하게 되면 해당 template 함수에 어떤 type 등이 들어와도 잘 대응이 된다. 
예:
template_with_type_and_args.cpp 파일을 확인 및 ./temp_type_and_args_17 실행  


하지만 만약 cpp, hpp 파일로 나눠서 만들게 되면  
undefined reference error가 발생하게 된다. 해당 함수를 호출할 때 각각에 어떤 파라미터로 들어갈 지가 알 수가 없어서 그렇다. 
컴파일러가 코드를 생성하지 못하고 (initialize가 안되서 그렇다고 함)  

그래서 하나의 파일로 생성이 되게 되면 template에 이 잘 작동

1. 대신에 이렇게 하게 되면   
header 파일의 역활보다는 하나의 파일로만 되게 된다.   

2. 대신에 cpp/h 파일로 나누되, 가능한 type 등을 다 지정해 준다. 
예를 들어  cpp 파일에 파라미터로 들어올 경우를 다 지정해준다. 
template void stdError(const float& msg);
template void stdError(const int& msg);
template void stdError(const bool& msg);

explicit instantiations 해준다고 할 수 있다.  
몇개의 type만 가능하게 한다고 하면 이런식으로 하는 것도 나쁘지 않다. 
왜냐하면 문제가 있을 경우 컴파일 단계에서 에러가 발생하게 된다. 


3. tpp 파일을 사용한다. 
h 파일과 cpp파일을 평소 처럼 사용을 하고 header 파일안에 tpp 파일을 사용할 수 있게 하는 것   
단, cpp 파일에서는 해당 template 함수의 내용을 만들지 않고 -> tpp 파일에 넣어주게 된다. 
그리고 h 파일에서 tpp 파일을 include 한다.

이렇게 하면  cpp /h 파일을 나누고도 undefined reference error가 발생하지 않는다.  
explicit 하게 정의를 다 하지 않아도 된다.  

*/


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