
std::array<char, 128> buffer;
std::string result;

std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd_str.c_str(), "r"), pclose);

if(!pipe) {
        std::cerr << "popen() failed!" << std::endl;
    }

    while(fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        // cmd_result_data.push_back(var);
        result += buffer.data(); // append
        //// result = buffer.data(); // (It replaces each time. maybe saving for the last result. )
    }
    
    if(!result.empty()) {
        std::cout << "ls result: " << result << std::endl;
        
    }

이렇게 사용할 때 워닝 메세지 

src/usb_info_confirmer.cpp: In member function ‘bool UsbInfoConfirmer::executePopen(const std::string&)’:
src/usb_info_confirmer.cpp:96:44: warning: ignoring attributes on template argument ‘int (*)(FILE*)’ [-Wignored-attributes]
   96 |     std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd_str.c_str(), "r"), pclose);
      |                                  


pclose가 function pointer 인데, std::unique_ptr 은 attributes 를 처리를 안되기 때문에 (compiler version에 따라 다를 수 있다고 함) 
warning 메세지가 나온다. 물론 사용하는데 문제는 없다 .


위 대신에 커스텀 operator 사용, shared_ptr 를 사용하거나 
람다를 사용하거나 
Custom Deleter struct 를 만들어서 사용 


예) 
struct PipeCloser {
    void operator()(FILE* fp) const {
        if (fp) pclose(fp);
    }
};

std::array<char, 128> buffer;
std::string result;
std::unique_ptr<FILE, PipeCloser> pipe(popen(cmd_str.c_str(), "r"));

if (!pipe) {
    std::cerr << "popen() failed!" << std::endl;
    return result;
}

while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();  // Note: += to append, not = to replace
}

PipeCloser 로 unique_ptr 에 넣어주는 방식 


아니면 람다

std::array<char, 128> buffer;
std::string result;

auto pipe_deleter = [](FILE* fp) { if (fp) pclose(fp); };
std::unique_ptr<FILE, decltype(pipe_deleter)> pipe(popen(cmd_str.c_str(), "r"), pipe_deleter);

if (!pipe) {
    std::cerr << "popen() failed!" << std::endl;
    return result;
}

while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
}


아니면 unique_ptr이 아닌 shared_ptr 를 사용한다 

예제

std::array<char, 128> buffer;
std::string result;
std::shared_ptr<FILE> pipe(popen(cmd_str.c_str(), "r"), pclose);

if (!pipe) {
    std::cerr << "popen() failed!" << std::endl;
    return result;
}

while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    result += buffer.data();
}