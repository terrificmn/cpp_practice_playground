#include <iostream>
// std::move is used to indicate that an object t may be "moved from", i.e. allowing the effient transfer
// of resources from t to another object

std::string s1 = "long long long string...";
// 여기에서 s1 은 lvalue 이고, "long long long string..."은 rvalue
std::string s2 = s1;
// 여기에서 s2는 lvluae 이지만, s1은 rvalue 이다. 
// 그래서 copy constructor가 작동을 해서 내용을 복사 하게 된다.

// 만약 함수를 호출 한다고 해도 같은 상황이 발생한다.
void mystring(std::string s3) {
    s2 = s3;
}
// 파라미터로 받을 때 s3를 카피해서 사용하게 된다.

// 하지만 만약 s2 = s1 을 복사하지 않고 , mystring 에서 s3를 복사하지 않고 object를 이동할 수 있다면
// move sematic이 상요할 수 있게 된다
// 위의 mystring 함수에서 std::string s3 는 rvalue가 된다. 그러므로 이를 rvalue reference로 사용할 수가 있다.
void mystring(std::string&& s3) {
    /// do something
}



int main() {
    // rvalue "copy construct me" 를 할당하기 위해서 copy constructor가 작동해서 my_str 에 카피해주게 된다.
    std::string my_str = "copy consturct me";
    std::string new_str;
    std::string new_new_str;

    std::cout << "my_str : " << my_str << std::endl;
    std::cout << "new_str : " << new_str << std::endl;

    //1.  rvalue reference를 사용하는 방법도 있다.
    // 마치 함수에서 파라미터에서 && 를 사용해서 rvalue reference로 사용하듯이 사용이 가능하다
    // new_str = (std::string&&)my_str;  // c style
    new_str = static_cast<std::string&&>(my_str); // This is the equivalent move assignment.

    std::cout << std::endl;
    std::cout << "use r value reference && " << std::endl;
    std::cout << "my_str : " << my_str << std::endl; /// && (r밸류 레퍼런스)를 이용하면 std::move와 같은 효과이므로,, my_str 이 empty가 된것을 확인할 수가 있다.
    std::cout << "new_str : " << new_str << std::endl;


    std::cout << std::endl;
    //2. std::move allows us to 'adopt' or 'streal' the value
    // rvalue로 카피를 하는게 아니라 copy constructor 를 사용하지 않고 아예 무브를 시켜준다.
    /// 이 경우에 my_str 이 valid 형태로 남아 있을 수도 있다. // 그렇다고 object가 crash하거나 하지는 않는다.
    new_new_str = std::move(new_str);
    std::cout << "my_str : " << my_str << std::endl;
    std::cout << "new_str : " << new_str << std::endl;
    std::cout << "new_new_str : " << new_new_str << std::endl;



    return 0;
}