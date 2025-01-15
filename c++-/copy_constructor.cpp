#include <iostream>

class MyVector3 {
    public:
        float x,y,z; // primitive data 이기 때문에 assignment에 큰 문제가 없다. (default로 처리가능)
};

class MyArray {
public:
    MyArray() {
        std::cout << "Constructor!\n";
        my_array = new int[5];
        for(int i=0; i< 5; i++) {
            my_array[i] = i*i;
        }
    }

    ~MyArray() {
        delete[] my_array; // array로 만들어진 것은 []으로 지워준다.
    }

    // copy constructor : 새로 오브젝트를 만들 때에만 작동한다. copy assignment operator와 그 점에서 다르다. 
    MyArray(const MyArray& rhs) { // right hand side 또는 copy object라고 해주면 좋다 
        std::cout << "Copy Constructor!\n";
        /// new로 새로 할당
        my_array = new int[5];
        for(int i=0; i<5; i++) {
            my_array[i] = rhs.my_array[i];
        }
    }

    /// Copy Assignment operator
    /// Objsect is already consturcted, we are just making a copy later
    /// (e.g. myArray2 = myArray) 즉 기존에 있는 인스턴스에서 복사를 할 경우 
    MyArray& operator=(const MyArray& rhs) {
        std::cout << "Copy Assignment Operator!\n";

        if(&rhs == this) {
            // 같은 주소라면 아무것도 안하게 한다. 예를 들어서 myArray3 = myArray3 이런 경우이다.
            return *this;  // The keyword 'this' is a pointer of the current object, and de-referencing this pointer retrieves the object itself.
        }
        // 오른쪽의 rhs 오브젝트 내용을 복사할 것 이므로 my_arry가 있으면 지워준다.
        if(my_array != nullptr) {
            delete[] this->my_array;
        }
        /// 새로 할당해준다.
        this->my_array = new int[5];
        for(int i=0; i<5; i++) {
            this->my_array[i] = rhs.my_array[i];
        }
        return *this;
    }


    void printArray() {
        for(int i=0; i<5; i++) {
            std::cout << this->my_array[i] << " ";
        }
        std::cout << std::endl;
    }

    void setArray(int index, int value) {
        this->my_array[index] = value;
    }
    
private:
    int* my_array;
};


int main() {
    /// default constructor가 작동하며,  보통 멤버 변수 (float이므로)4byte 씩 할당하게 됨
    // cpp compiler가 constructor, destructor, copy constrocutor 를  copy-assignment operator 만들어줌
    MyVector3 myVector;
    myVector.x = 10.0;
    myVector.y = 20.0;
    myVector.z = 30.0;

    MyVector3 myVector2 = myVector; // copy-assignment operator

    std::cout << myVector2.x << ", " << myVector2.y << ", " << myVector2.z << std::endl;

    std::cout << std::endl;

    MyArray myArray;
    myArray.printArray();

    myArray.setArray(0, 1000);
    myArray.printArray();

    /// C++ gives us a "free" copy constructor, copy assignment operator. But It does a shallow copy.
    // 예를 들어서 pointer 등은 해당 주소만 복사하게 된다.
    // 그래서 아래에서 desctuct이 될 때 두 번 delete가 일어나서 free(): double free detected in tcache 2 에러가 발생한다.
    // MyArray myArray2 = myArray;

    /// 물론 copy constructor를 만들게 되면 rhs 즉 =의 오른쪽 오브젝트를 아규먼트로 copy constructor가 작동하므로 에러 없어진다.
    /// new로 새롭게 복사가 된다.
    MyArray myArray2 = myArray;
    myArray2.printArray();

    std::cout << std::endl;


    /// copy assignment operator 작동
    /// 먼저 서로 주소가 다르게 되면 left hand side 의 myArray2 의 내용을 지우고 right hand side 인 myArray 내용을 카피하게 된다.
    myArray2 = myArray;
    myArray2.printArray();

    return 0;
}

// g++ -std=c++17 -o copy copy_constructor.cpp 