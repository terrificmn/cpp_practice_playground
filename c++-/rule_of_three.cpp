#include <iostream>
#include <vector>

// 1. rule of three / rule of thumb 이라고도 부르는데, 
// Constructor, Destructor, Copy constructor, (copy assignment operator포함) 해서 3개를 만들어줘야한다.  

// trivial data type 인  int, float 등은 전혀 문제가 없기 때문에 (메모리할당 등.., 카피 등)
// copy constructor 는 기본으로 컴파일러가 만들어주는것을 사용하면 된다.

/// IMPONRTANT:
// 단 pointer 등을 사용할 경우에는 copy 등을 하게 되면 shallow copy가 되어서 완전하게 카피가 되지 않고 복사된 객체가 같은 주소를 가리키게 되고 , 그래서 deep copy가 필요
// 소멸이 될 때 중복삭제 되면서 에러가 발생할 수가 있다.
// 이때에 rule of three 를 적용하면 된다.

// 2. Law of the Big Two
// 이는 Constructor,  Copy constructor, (copy assignment operator포함) 2개를 말 하는데,
// container 등의 std::vector 등을 사용하거나, smart_pointer 등을 사용하거나 할 경우에는 
// Destructor 가 딱히 정의해 줄 필요가 없다. 각 vector 나 스마트 포인터 등은 내부적으로 알아서 잘 소멸하기 때문이다.
// 그래서 Constructor,  Copy constructor 만 사용하는 것을 말한다.
/// 맨 아래에 pointer가 아닌 vector를 사용할 경우의 예제를 참고하자


class MyArray {
public:
    // 1. Constructor
    MyArray() {
        std::cout << "Constructor!\n";
        data = new int[10];
        for(int i=0; i<10; i++) {
            data[i] = i*i; // just set value. no meaning.
        }
    }

    // 2. Destructor
    ~MyArray() {
        std::cout << "Destructor!\n";
        delete[] data;
    }

    /// 3. copy constructor
    /// constructor과 거의 똑같은 기능으로 만들면 된다. (붙여넣기).
    /// IMPORTANT: 단, const reference로 들어온 값, 즉 아규먼트로 들어온 벨류를 새로운 data에 넣어주게 된다.
    /// copy 생성자가 사용될 경우에는 새로운 인스턴스를 만드는데 기존에 있던 것으로 =을 이용해서 할당하는 경우이다.
    // 예를 들어
    // MyArray myArray2 = myArray; // myArray는 이미 생성되었다고 가정. 이런 경우에 myArray2 를 생성하게되는데 이때 그냥 생성자가 아닌 copy constructor가 작동하게 됨
    MyArray(const MyArray& rhs) {
        std::cout << "Copy Constructor!\n";
        data = new int[10];
        for(int i=0; i<10; i++) {
            data[i] = rhs.data[i];
        }
    }

    /// 3. (or 4) copy assignment operator
    /// 생성이 된 이후에 =을 이용해서 다시 할당하는 경우에 사용된다.
    // 예:
    // myArray2 = myArray;
    MyArray& operator=(const MyArray& rhs) {
        std::cout << "Copy assignment operator!\n";

        // 주소 비교 후 같다면, 그냥 현재 Array를 리턴하게 됨  , 예: myArray = myArray;
        if(&rhs == this) {
            return *this;
        }
        
        // 기존에 있는 것을 새로 copy assignment 하므로 지워준다.
        delete[] data;
        // 이하는 copy constructor와 같은 기능으로 만들어진다.
        data = new int[10];
        for(int i=0; i<10; i++) {
            data[i] = rhs.data[i];
        }

        return *this;
    }

    
    void setData(int index, int value) {
        data[index] = value;
    }

    void printData() {
        std::cout << "print\n";
        for(int i=0; i<10; i++) {
            std::cout << "[" << i << "]: " << data[i] << std::endl;
        }
    }

private:
    int* data;

};






// Law of the Big Two 예, vector 등을 멤버변수로 사용할 경우에 예제
class MyVector {
public:
    // 1. Constructor
    MyVector() {
        std::cout << "MyVector Constructor!\n";
        for(int i=0; i<10; i++) {
            data.push_back(i*i); // just set value. no meaning.
        }
    }

    // 2. Destructor
    // 멤버 data는 vector 인데 따로 delete를 하거나 할 필요가 없으므로 기본 destructor를 사용하게 된다.

    /// 3. copy constructor
    /// constructor과 거의 똑같은 기능으로 만들면 된다. (붙여넣기).
    /// IMPORTANT: 단, const reference로 들어온 값, 즉 아규먼트로 들어온 벨류를 새로운 data에 넣어주게 된다.
    /// copy 생성자가 사용될 경우에는 새로운 인스턴스를 만드는데 기존에 있던 것으로 =을 이용해서 할당하는 경우이다.
    // 예를 들어
    // MyVector myVector2 = myVector; // myVector 이미 생성되었다고 가정. 이런 경우에 myVector2 를 생성하게되는데 이때 그냥 생성자가 아닌 copy constructor가 작동하게 됨
    MyVector(const MyVector& rhs) {
        std::cout << "MyVector Copy Constructor!\n";
        for(int i=0; i<10; i++) {
            data.push_back(rhs.data[i]);
        }
    }

    /// 3. (or 4) copy assignment operator
    /// 생성이 된 이후에 =을 이용해서 다시 할당하는 경우에 사용된다.
    // 예:
    // myVector2 = myVector;
    MyVector& operator=(const MyVector& rhs) {
        std::cout << "MyVector Copy assignment operator!\n";
        // 주소 비교 후 같다면, 그냥 현재 Array를 리턴하게 됨  , 예: myArray = myArray;
        if(&rhs == this) {
            return *this;
        }
        
        data.clear();
        // 이하는 copy constructor와 같은 기능으로 만들어진다.
        for(int i=0; i<10; i++) {
            data.push_back(rhs.data[i]);
        }

        return *this;
    }

    void printMyVector() {
        std::cout << "print vector\n";
        for(int i=0; i<10; i++) {
            std::cout << "[" << i << "]: " << data[i] << std::endl;
        }
    }

    void setData(int index, int value) {
        data[index] = value;
    }

private:
    std::vector<int> data;

};




int main() {
    MyArray myArray;

    myArray.setData(0, 10);

    myArray.printData();
    
    std::cout << std::endl;

    MyArray myArray2; // constructor
    myArray2 = myArray; // copy assignement operator
    MyArray myArray3 = myArray2; // copy constructor

    myArray2.printData();

    std::cout << "\n\n==========================" <<  std::endl;
    MyVector myVector; // constructor
    myVector.printMyVector();
    myVector.setData(5, 1000);
    MyVector myVector2 = myVector; // copy constructor
    myVector2.printMyVector();
    myVector2.setData(5, 1);
    myVector = myVector2; // copy assignement operator
    myVector.printMyVector();


    return 0;
}

