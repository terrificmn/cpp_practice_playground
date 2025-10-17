//#include <cmath>
#include <iostream>

int main() {
    float num1 = 1.5;
    float num2 = -1.4;
    double num3 = 2.55;
    double num4 = -2.110;
    int num5 = 2;
    int num6 = -4;
    // double과 float 에서는 <cmath> 의 abs 함수를 쓴다고 하는데
    
    // <cmath>를 include를 하지않고 테스트를 하니 
    // float, double도 사용은 되고
    // 반대로 <cmath>를 사용해도 int에도 사용은 가능한가 보다;;
    std::cout << "num1 :" << std::abs(num1) << std::endl;
    std::cout << "num2 :" << std::abs(num2) << std::endl;
    std::cout << "num3 :" << std::abs(num3) << std::endl;
    std::cout << "num4 :" << std::abs(num4) << std::endl;
    std::cout << "num5+int :" << std::abs(num5) << std::endl;
    std::cout << "num6-int :" << std::abs(num6) << std::endl;

    return 0;
}