// /// shared_ptr를 다른 클래스에서 사용하고 싶을 경우에는 위 처럼 main 함수내에서 딱히 포인팅으로 만들기가 어려운 듯 하다  
// 특정 클래스에서 스마트 포인터를 사용하고 싶지만 메인에서 사용하는게 아니라면  이런 방법을 사용할 수가 있다  
// 클래스 A와 B가 있다고 가정했을 경우에, 물론 메인에서 뭔가를 get하거나 set등으로 처리하려고 하려면  
// 각 인스턴스 변수에서 특정 메소드를 콜 해서 사용을 하면 되지만   
// 예를 들어 B 클래스 내에서 A클래스의 메소드를 사용하려고 하면, A 클래스를 B클래스에서는 전혀 알지 못하므로 사용을 못함  
// 그래서 클래스를 생성할 때 주소를 넘겨줘서 사용할 수가 있다. 
// 이때 smart pointer와 raw pointer로 파라미터로 넘겨주는 방식이 문법만 다를 뿐 비슷하게 보이는 듯 하다
// (오히려 raw 포인터로 하는 방식이 더 편해보이기도 하지만)
// 그냥 포인터일 경우에는  null 이거나 invaild 할 경우 프로그램이 죽어버리겠지만,   
// 스마트 포인터이면 적어도 B클래스가 문제가 있더라도 A클래스는 계속 살아 있을 수 있다. 

#include <memory>
#include <iostream>

class A {
public:
    void methodA() {
        std::cout << "Hello from A::methodA()" << std::endl;
    }
};

class B {
private:
    std::shared_ptr<A> a_ptr;
public:
    B(std::shared_ptr<A> a) : a_ptr(a) {}

    void methodB() {
        std::cout << "Hello from B::methodB()" << std::endl;
        a_ptr->methodA();
    }
};

int main() {
    std::shared_ptr<A> a_ptr = std::make_shared<A>();
    B b(a_ptr);
    b.methodB();
    return 0;
}


// 그냥 포인터를 사용하면 

// class A {
// public:
//     void methodA() {
//         std::cout << "Hello from A::methodA()" << std::endl;
//     }
// };

// class B {
// private:
//     A* a_ptr;
// public:
//     B(A* a) : a_ptr(a) {}

//     void methodB() {
//         std::cout << "Hello from B::methodB()" << std::endl;
//         a_ptr->methodA();
//     }
// };

// int main() {
//     A* a_ptr = new A();
//     B b(a_ptr);
//     b.methodB();

//     delete a_ptr;
//     return 0;
// }


// > 하지만 이 때  꼭 new 키워드로 만들지 않고 nullptr로 아예 만들어버릴 수도 있는데 이럴 경우에도 메모리 누수의 문제가 있는지는   
// 잘 모르겠다   


// 예

// class B {
// private:
//     A* a_ptr = nullptr;
// public:
//     B(A *a) : a_ptr(a) {}

// }
// int main() {
    
//     A a;
//     B b(&a);
//     b.methodB();
// }


// 이럴 경우에는 stack 메모리에 할당되어서 만들어진다. 그래서 메모리에서 자동으로 관리가 되는 경우이다 (컴파일 하면서)  
// 즉 블럭을 빠져나가거나, return 되거나 등등.. 알아서 deallocated 된다   

// 하지만, 스택 방식으로 할당된 object를 즉 a 변수를 다른 오브젝트에 포인터로 넘기는 것을 위험할 수가 있다  
// 이유는 원래 처음 ojbect가 종료되고 (A class의 오브젝트 a), B 클래스 내에서 A class를 접근하려고 하면 당연히 프로그램을 
// crash 되거나, 원치않은 방향으로 흘러갈 수가 있다.  

// 그래서 dynamic memory 로 할당하는 것이 더 좋지만, new 키워드로 만들면 또 관리하기가 어려울 수 있으니,  
// shared_ptr로 만들면 더 좋다

// > 물론 해당 인스턴스가 main 함수 끝날 때까지 살아 있다면 문제는 없을 것 같다.  

