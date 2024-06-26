#include <iostream>

class MyClass {
public:
    MyClass() {
        my_array = new int[5];
        for(int i=0; i< 5; i++) {
            my_array[i] = i*i;
        }
    }

    ~MyClass() {
        delete[] my_array; // array로 만들어진 것은 []으로 지워준다.
    }

    void printArray() {
        for(int i=0; i<5; i++) {
            std::cout << this->my_array[i] << " ";
        }
        std::cout << std::endl;
    }
    
private:
    int* my_array;
};

int main() {
    MyClass myClass;
    myClass.printArray();

    MyClass myClass2 = myClass; // copy 
    // cpp 에서는 constructor, destructor, copy constructor 를 자동으로 생성.,(생략했을 경우) default compiler generated..

    myClass2.printArray();
    // 이렇게 까지 하면  myClass2를 복사한 후 print를 한 후에 
    /*
    free(): double free detected in tcache 2
    Aborted (core dumped)
    이렇게 에러가 발생한다.
    */

   /// TODO::이어서..하기
}

// g++ -std=c++17 copy_constructor.cpp -o copy