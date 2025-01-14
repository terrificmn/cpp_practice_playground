#include <iostream>

/// struct 의 2개가 조금씩 다르나 컨버젼에서 사용하고 싶을 경우에 copy constructor 또는 operator 를 사용해서 
// 컨버젼을 사용할 수가 있다.

// lkie vec2
struct Pair {
    float x, y;

    Pair(float _x, float _y) : x(_x), y(_y) {}
};

/// like vec3
struct Triple {
    float values[3];

    Triple() {
        std::cout << "Triple constructor" << std::endl;
    }
    
    // explicit을 사용하지 않으면 자동으로 만들어 준다. 하지만 explicit을 사용하는 것이 추천이라고 한다.
    explicit Triple(const Pair& p) {
        std::cout << "Triple(Pair) constructor" << std::endl;
        values[0] = p.x;
        values[1] = p.y;
    }

    // operator도 마찬가지
    explicit operator Pair() const {
        return Pair(values[0], values[1]);
    }
};


int main() {
    
    Pair p(10.0f, 20.0f);
    
    Triple t;
    t.values[0] = 1.1f;
    t.values[1] = 2.2f;
    t.values[2] = 3.3f;

    // 만약 Triple 에서 Pair로 카피를 하려고 하면 constructor가 없다면 진행이 안된다. 
    // conversion 에러가 발생
    // 따로 Triple에 default 컨스트럭터 외에 카피할 수 있게 만들어 준다.
    // 여기에서는 Triple(const Pair& p) 생성자가 사용되어서 아래 코드 처럼 사용될 수가 있다.
    // 여기에서는 implicit 방식으로 작동해서 알아서 컨버젼이 되지만 (확인하려면 explicit Triple(const Pair& p) 에서 explicit 을 빼고 테스트 해본다)
    /*
        t = p; // copy constroctor 작동
        Triple t2 = p; // copy constroctor 작동
    */
    
    // explicit 을 넣어주면 바로 에러가 발생한다. 
    // 아래처럼 타입을 정의를 해주면 에러가 발생하지 않는다. 
    t = static_cast<Triple>(p);
    // t = (Triple)p; ///c style



    // 만약 이런 코드가 사용하고 싶다고 할 경우에는 Triple을 pair로 전환해서 x 또는 y로만 접근하고 싶을 경우에는
    // 위의 컨스트럭터 코드로는 사용이 안됨. 그래서 operator 를 사용해서 정의해 줄 수가 있다.
    std::cout << ((Pair)t).x << std::endl;
    // 이것도 c++ 스타일로 해주면 좋다.
    std::cout << static_cast<Pair>(t).x << std::endl;

    /// operator Pair() 가 작동한다.
    // Pair p2 = t; /// 이것도 마찬가지로 operator에서 explicit를 빼면 가능하다.
    Pair p2 = static_cast<Pair>(t);
    std::cout << "x: " << p2.x << ", y: " << p2.y << std::endl;
    return 0;

}

// c++ -std=c++17 -o conversion conversion.cpp         