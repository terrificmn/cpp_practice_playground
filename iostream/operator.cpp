#include <iostream>


// A vector3 data type, storing floats
class Vector3f {
    public:

    // custom 생성자를 만들면 cpp에는 rule of three가 있는데, copy 컨스트럭터, 디스트럭터도 만들어준다. (여기에서는 생략)
    Vector3f() {
        x = 0.0f;
        y = 0.0f;
        z = 0.0f;
    }

    /// overload binary operator
    // operator + 를 overload를 하고 있는데 + 의 공식 class definition은 T T::operator+(const T2 &b); 인데 이를 사용해서 똑같은 방식으로 만들어 줄 수가 있다.
    // rhs 는 right hand side 를 의미함 -- 오른쪽으로 들어가는 파라미터를 의미
    Vector3f operator+(const Vector3f& rhs) const {  // 함수에 const가 들어가게 되면 멤버변수 x,y,z 를 변경되지 않는다.
        Vector3f result;
        result.x = x + rhs.x;
        result.y = y + rhs.y;
        result.z = z + rhs.z;
        return result;
    }

    //overload prefix increment ++ 오퍼레이터, 그 중에서도 prefix 증가하는 ++x 방식을 의미 , x++ 방식은 cpp reference 페이지에서 찾아보기
    Vector3f& operator++() {
        x = x+1;
        y = y+1;
        z = z+1;
        return *this; // return new value by reference
    }

    // class 안에서 operator==()를 하려고 하면 하나의 argument 만 필요하다. 즉 lhs 는 멤버변수로 대체, rhs 만 필요하게 된다.
    bool operator==(const Vector3f& rhs) {
        std::cout << "part of class function\n";
        if(x == rhs.x &&
            y == rhs.y &&
            z == rhs.z) {
            return true;
        }
        return false;
    }

    float x,y,z;
};

// stream extraction , stream operator, arrow operator 라고 부름
std::ostream& operator<<(std::ostream& os, const Vector3f& obj) {
    os << obj.x << "," << obj.y << "," << obj.z;
    return os;
}

/// operator== 의 파라미터 형태 inline bool operator==(const X& lhs, const X& rhs) { /* do actual comparison */ }
bool operator==(const Vector3f& lhs, const Vector3f& rhs) {
    std::cout << "free function used\n";
    /// IMPOTANT: 여기에서 주의할 점은 == 을 사용해서 0.99999999f 와 1.f 를 비교하게 되면 true를 리턴하게 된다는 것이다.
    /// 원래 ==가 그런듯 하다. 이럴 경우에 std::abs(lhs.x - rhs.x) < 0.00001 이런식으로 비교하게 할 수가 있다. (참고이지만, 잘 되는지 모르겠음;;;)
    if(lhs.x == rhs.x &&
        lhs.y == rhs.y &&
        lhs.z == rhs.z) {
        return true;
    }

    return false;
}

int main() {
    Vector3f myVector;
    myVector.x = 1.f;
    myVector.y = 2.f;
    myVector.z = 3.f;

    Vector3f myVector2;
    myVector2.x = 4.f;
    myVector2.y = 5.f;
    myVector2.z = 6.f;

    /// operator==
    std::cout << std::boolalpha << (myVector == myVector2) << std::endl;

    // if(0.99999999999f == 1.0f) {
    //     std::cout << "oh true\n";
    // }

    Vector3f resultVector;
    resultVector = myVector + myVector2;
    std::cout << resultVector.x << "\t" << resultVector.y << "\t" << resultVector.z << std::endl;

    myVector =  myVector + myVector2;
    std::cout << myVector.x << "\t" << myVector.y << "\t" << myVector.z << std::endl;

    //overload prefix increment
    ++myVector;
    std::cout << myVector.x << "\t" << myVector.y << "\t" << myVector.z << std::endl;


    // operator<< 를 사용
    std::cout << myVector << std::endl;

    
    return 0;
}


// g++ -std=c++17 -o operator operator.cpp 