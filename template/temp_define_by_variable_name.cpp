#include <iostream>
#include <unordered_map>

/// 특정 MyData 라는 클래스를 사용하는데 여기의 my_id 라는 variable에는 myData.my_id = 1; 
// 이런식으로 사용할 수가 있다. 만약 이 my_id 라는 변수를 특정 스트링과 같다고 할 경우에   
// "my_id" 라는 스트링이 있다면 이 스트링에 해당하는 게 variable 로 연결해서 알아서 해당 variable에 넣어줄 때 
// template 기능을 사용할 수 가 있다. 대충 과정은 사용할 class 를 만들고 이후 copy template를 만들고 
// 여기에서는 TempReflector가 되고 여기에 unordered_map 으로 <키, 벨류> 로 변수를 만들어서 실제 MyData 클래스의 실제 주소를 넣어서 
// 값을 변경할 수 있게 하는 방식이다. 즉, TempReflector를 반영시키면 실제 벨류가 바뀌게 되고, 
// "my_id" = "my_id" 가 될 수 있다.

class MyData {
public:
    int my_id;
    std::string my_name;

private:    
};

template <typename T>
class TempReflector {
private:

public:
    /// T type으로 들어온 클래스에 대한 멤버들의 포인터 이며, 이를 별칭(alias)로 사용할 수 있다. 바로 아래 주석 참고 (using PtrMember)
    std::unordered_map<std::string, int T::*> member_map;

    /// 실제 참조할 MyData의 variable의 type을 잘 확인해야한다. 
    void addMember(const std::string& name, int T::* member_ptr) {  
        this->member_map[name] = member_ptr;
    }

    using PtrMember = int T::*;  // 이제 이 별칭을 int T::* 대신에 사용할 수 있다. 장점은 이렇게 별칭으로 만들어놓으면 type처럼 사용할 수 있게 된다.
    // 위에서 사용된 int T::* 대신에 사용할 수 있게 된다. 아래 주석 코드 처럼.. 사용
    // void addMember(const std::string& name, PtrMember member_ptr) {
    //     this->member_map[name] = member_ptr;
    // }

    void setMember(T& obj, const std::string& name, int value) {
        auto it = member_map.find(name);
        if(it != member_map.end()) {
            std::cout << "work.. " << value << std::endl;
            obj.*(it->second) = value;
        } else {
            std::cout << "There no member: " << value << std::endl;
        }
    }
    

};


int main() { 
    MyData myData;
    TempReflector<MyData> tempReflector;

    std::string key_value = "my_id";
    tempReflector.addMember(key_value, &MyData::my_id);

    std::cout << "TempReflector's variable member_map's key is " << key_value << std::endl;
    std::cout << "and its value is " << tempReflector.member_map[key_value] << std::endl;

    tempReflector.setMember(myData, key_value, 10);
    std::cout << "TempReflector can reflect the myData's variale." << std::endl;
    std::cout << "and its value is " << myData.my_id << std::endl;
    return 0;
}


// g++ -std=c++17 -o temp_reflector temp_define_by_variable_name.cpp 