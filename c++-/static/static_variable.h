#ifndef STATIC_VARIABLE_H
#define STATIC_VARIABLE_H

#include <iostream>

class MyStatic {
public:
    MyStatic();
    ~MyStatic();

    static int s_variable; // static은 무조건 최초 define을 해줘야 한다.(물론 여기에서 초기화 할 수는 없다.)
    const static int s_const_var = 20; // 단 const 일 경우에는 클래스 안에서도 할 수가 있다.

    static void myStaticFunc();

};

#endif


