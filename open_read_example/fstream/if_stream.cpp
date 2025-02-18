#include <iostream>
#include <fstream> /// write/ read 모두 포함 (ofstream / ifstream)
#include <filesystem>
// linear array 상의 file buffer에 있는 것을 읽어오는 것

int main() {
    {
        std::ofstream myFile("mydata");
        myFile << "Hi there\n";
        myFile << "hello world\n";
        myFile << "This is a text file\n";
    }
    /// FYI: 파일을 close를 이용해서 닫을 수도 있지만 그렇게 안해도 desctructor가 알아서 닫아주므로 close에 대해서 신경을 안 써도 됨
    /// 단!! 같은 파일을 또 사용하는 경우는 close() 을 사용하거나 { }을 이용해준다.
    
    /// Reading files
    std::ifstream myIFile("mydata");
    if(myIFile.is_open() && std::filesystem::exists("mydata") ) {
        /// IMPORTANT: ofstream 등에서 소멸될 때 알아서 파일을 close 해주지만 만약 같은 파일을 '쓰고', '읽는'다면 
        // 해당 filebuf 을 같은 곳을 보고 있거나 파일의 마지막을 가리키고 있을 수도 있다. 
        /// TODO: 위의 ostream 의 { } 을 주석 처리하고 확인해보기
        std::string a_line;
        std::getline(myIFile, a_line);
        std::cout << "read line 1: " << a_line << std::endl;
        std::getline(myIFile, a_line);
        std::cout << "read line 2: " << a_line << std::endl;

        /// TODO: 위의 getline을 주석처리 후 사용// 주로 while loop로 많이 처리한다. 
        // while(std::getline(myIFile, a_line)) {
        //     std::cout << "read line : " << a_line << std::endl;
        // }

    } else {
        std::cerr << "File does not exist." << std::endl;
    }


    std::ofstream myFile2("mydata2");
    myFile2 << "1 2 3\n";
    myFile2 << "10 20 30\n";
    myFile2 << "40 80 120\n";
    myFile2.close();

    // white space를 기준으로 알아서 한 글자씩 읽을 수가 있다. getline 대신 ifstream 와 >> 을 사용할 수가 있다.
    // filestream 자체를 사용하는 꽤 유용한 기능
    std::ifstream myIFile2("mydata2");
    int x, y, z;
    while(myIFile2 >> x >> y >> z ) {
        std::cout << "x: " << x << "\ty: " << y << "\tz: " << z << std::endl;
    }
    myIFile2.close();


    /// read 사용해서 char 형태로 만들기, seekg 을 사용해서 특정 부분에서 가져온다
    
    std::ifstream myIFile3("mydata");
    char myChar[6];
    if(myIFile3.is_open()) {
        myIFile3.seekg(-5, std::ios_base::end); // 끝으로부터 가져오기 
        myIFile3.read(myChar, 6);
        /// read 할 때는 마지막의 '\n' 도 포함
        std::cout << "char read: " << myChar << std::endl;
    }

    return 0;

}

// g++ -std=c++17 -o ifstream if_stream.cpp 