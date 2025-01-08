

std::vector<std::thread> my_thread;

/// 람다 bind -- 대충 이런식인거 같은데 맞는지 모르겠다. 클래스를 instance로 만들었을 경우에
MyClassInstance myClassInstance; // 클래스가 있다고 치고..

my_thread.push_back ([myClassInstance]() {
    myClassInstance.myThreadMethod();
})


// class bind
push_back() 한 다고 가정했을 때
/// class 내에서 사용할 경우에는 this로 지정해주고, 클래스에서 사용하는 경우가 아닐 때에는 (ex: main등) instance 를 넘겨주면 된다.
my_thread.push_back(std::thread( std::bind(&MyClass::myThreadMethod, this)) );

