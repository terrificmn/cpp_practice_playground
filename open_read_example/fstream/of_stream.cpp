// ofstream
// ifstream
// fstream 등이 있는데 

// out file stream 
// input file stream
// fstream 은 input/output 등을 포함

// https://en.cppreference.com/w/cpp/io#Stream-based_I.2FO
// 참고

// RAII 에서 처리해준다. (파일을 닫아준다.)
// 그러므로 close 를 꼭 해줘야 하는줄 알았는데, 꼭 그럴 필요가 없다.  

// file 이라고 하면 file handler가 포인팅 하고 있는 배열이라고 생각할 수가 있다. 

#include <fstream>  // read /write files stream
#include <iostream>

int main() {

    // std::ofstream myFile("myfile");  // 이렇게만 해줘도 파일을 만들어준다. // 기본 모드가 std:;ios_base::out 으로 되어 있다. (open for writing)
    /// FYI: std::ios 
    ///     app - seek to the end of stream before each write
    ///     binary - open in binary mode
    ///     in - open for reading
    ///     out - open for writing
    ///     trunc - discard the contents of the stream when opening
    ///     ate - seek to the end of stream immediately after open
    std::ofstream myFile("myfile", std::ios::app);  // 이렇게만 해줘도 파일을 만들어준다.

    if(myFile.is_open()) {
        std::cout << "File handler successfully created" << std::endl;
    }

    // Unformatted output
    myFile << "hello world\n"; // std::cout 실행하듯 간단하게 사용할 수가 있다.
    myFile.put('w'); // 바로 이러서 만들어줌

    char a = 48;
    myFile << a; // char로 아스키코드가 decimal 48 은 0 이어서 0으로 입력된다.

    myFile << (int)a; // int로 type을 바꿔주게 되면 48 그대로 입력이 되게 된다.

    
    myFile << "\nHello World\n";
    myFile << "Hello World\n";
    myFile << "Hello World\n";
    myFile << "Hello World\n";
    myFile << "Hello World\n";

    // Positioning
    myFile.seekp(0);  // array 의 첫 번째를 지정 후 아래에서 ' ' 를 넣으주면 한칸이 지워진다.
    myFile << ' ';

    /// 32번째를 바꾼다.
    myFile.seekp(32);
    myFile << "!!";

    // 마지막으로 이동 후 역으로 찾아서 바꿀 수가 있다.
    myFile.seekp(-2 , std::ios_base::end);
    myFile << 42;


    return 0;
}

//  g++ -std=c++17 -o ofstream of_stream.cpp