# cpp basic rule. 
사실 CPU 입장에서는 이런것들이 전혀 큰 이슈가 아니지만,  
사람이 코드를 입는 입장에서는 중요한 것 같다. cpp 코딩을 할 때 좋은 습관 방식을 참고하자. 

1.  std::unique_ptr<> 을 사용하기 보다는 (heap영역) stack영역에 만들어 주자
    예: std::unique_ptr<MyClass> myClass = std::maek_unique<MyClass>();
그냥 MyClass myClass;
이유는 stack으로 always prefer a stack allocation 만들어주자, 메모리 접근할 때 문제가 적어진다.
현실적으로 stack, heap 영역으로 만든다면 체감상으로 다른점이 거의 느끼져지 않을 것임. (raw 포인터를 쓰는 경우 제외)  
즉, 프로그램 실행 부터 종료 될 때까지 lifetime에 별다른 것이 없다면 구지 스마트 포인터로 안 만들어도 된다. 


2. main 함수에서는 int 가 리턴값으로 되어 있어도, 스페셜 케이스이므로 사실 리턴값을 정하지 않아도 된다.

3. public, private 을 변수와 함수로 구분해서 만들어주자, 나도 그 동안 섞어서 사용했는데 나누는게 훨씬 좋은 듯 하다.
    public:
        int robot = 1;
        bool running = false;
    public:
        void isRunning();

4. class constructor 시작이 될 때에 initialize을 : 이후 멤버변수(value) 이런식으로 해주는 것이 좋다  
MyClass::MyClass() {
    robot = std::make_shared<PtrExample>();
}

헤더
class MyClass {
private:
    std::shared_ptr<int> robot; // =로 할당하지 않고, constructor에서 다시 할당하는 경우

}

이런식이라면 파라미터가 없는 robot으로 shared_ptr로 만들고, 다시 다시 한번 constructor에서 복사해서 다시 만드는 과정이 있게 된다.
하지만, 컨트스트럭터에서 :으로 바로 연결하면 default 컨스트럭터가 한번만 발생한다고 한다.

MyClass::MyClass() : robot(std::make_shared<PtrExample>() ) {
}
헤더
private:
    std::shared_ptr<int> robot;

즉, 헤더의  private 영역에서 바로 할당을 해주거나 예: int robot = 1;  컨스트럭터 함수에서는 다시 재할당하기 보다는 :으로 변수를 넘겨서 
초기화 시키는 것이 좋다.


5. define으로 지정해주는 것은 디버깅 할 때에도 사용을 못하고, 변수로 역활도 못하며, pre processer에서 상수로 넣어주는 것인데  
아예 struct으로 지정해서 변수로 지정하는 게 좋다 
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 320

struct WindowSettings {
    int width = 640;
    int height = 640;
    const char* title = "hello";
}

6. vector를 파라미터로 넘길 때 copy로 넘기는 것을 지양하자.
함수가 실행할 때 마다 복사가 되므로 낭비
void run(std::vector<std::string> v_str) {
    //
}

run(my_v_str);

벡터는 heap으로 만들어진 것을 계속 복사
그러므로 const reference로 넘길 수 있게 하자. 
void run(const std::vector<std::string>& v_str) {
    //
}

run(my_v_str);


7. 모든 변수를 public으로 해야하는 경우에는 calss 보다는 struct을 사용

8. h/ cpp 파일 나눠서 만들자

9. 무조건은 아니지만 raw pointer 보다는 weak_ptr를 사용하자. 액세스 하기전에 상태도 체크할 수도 있음  









