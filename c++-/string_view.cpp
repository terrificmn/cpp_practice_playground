#include <iostream>
static int g_allocation_count = 0;

// new operator 를 override 해서 사용할 수가 있다. allocation 이 이뤄질 때 알 수가 있다.
void* operator new(size_t size) {
    std::cout << "allocation size: " << size << " bytes" << std::endl;
    g_allocation_count++;
    return malloc(size);
}

void printStr(const std::string& str) {
    std::cout << str << std::endl;
}

///FYI: 주의할 점은 string_view 는 레퍼런스 등이 이난 string_view 자체를 파라미터로 받는다.
void printStrView(std::string_view str_view) {
    std::cout << str_view << std::endl;
}

int main() {

    // 첫 번째로 일단 긴 스트링을 만들때 allocation 이 이뤄진다.  (heap)
    // 단, 짧은 스트링은 allocation이 안됨
    // 1. 주석 해제 후 확인
    {
        // std::string mystr = "hello world hello world hello world";
        
        // 2. 직접 const char 형태로 넘겨도 스티링 길이가 길면 heap 할당이 된다.
        // printStr("hello world hello world hello world hello world hello world");
    }

    /// substr을 해도 heap 할당이 되지 않는다. 강좌에서는 heap로 할당된다고 하는데 opimazation 이 되어서 짧은 스트링은 할당이 안되는 듯 하다.
    /// 주석 해제 후 확인
    {
        // std::string mystr = "hello world";
        // std::string hello = mystr.substr(0, 5);
        // std::string world = mystr.substr(6, 10);
        // printStr(world);

        // 단, std::string 자체를 만들때, 길게 하면 substr 을 사용했을 경우에도 할당이 될 수가 있다. 
        // std::string mystr = "hello world hello world hello world";
        // std::string world = mystr.substr(11, 20);
        // printStr(world);
    }
    


    // string_view 원래의 스트링 메모리를 view(윈도우)로 본다고 생각하면 된다. const char* 를 통해서 포인팅 한다.
    // 아마도 이 정도가 긴 스트링을 다룰 때 최선인 듯 하다. - 처음 만든 스트링을 계속 사용하는 경우라면..
    {
        // 주석 해제 후 확인
        std::string mystr = "hello world hello world hello world";
        std::string_view world(mystr.c_str(), 20); // 생략도 가능(뒤의 size(length))
        /// 길게 만들었음에도 불구하고 처음 mystr을 만들 때만 할당 된다. (물론 문자열이 긴 경우에만 해당하는 듯 하다)
        printStrView(world);

        /// FYI: string_view 컨스트럴터에는 const char* 와 사이즈를 지정하느데 이를 substr 처럼 사용할 수가 있다.
        /// 예를 들어서 std::string_view world(mystr.c_str() + 5, 10); 포인터 이므로 +로 시작점을 정할 수가 있다.
        // std::string_view hello(mystr.c_str() + 12, 5);
        // printStrView(hello);    
    }


    // 최종적으로 아예 스트링이 아닌 const char* 로 만들어 버리면 긴 문자열 자체도 allocation이 없다.
    /// 문자열이 바뀔 필요가 없을 때는 좋을 수도 있을 듯 하다.
    {
        // 주석 해제 후 확인
        // const char* my_char = "hello world hello world hello world";
        // std::string_view new_world(my_char, 20);
        // printStrView(new_world);
    }





    std::cout << "total allocation: " << g_allocation_count << std::endl;

    return 0;
}

//  g++ -std=c++17 -o string_view string_view.cpp 