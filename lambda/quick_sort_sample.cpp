#include <iostream>

int CompareData(const void *p_left, const void *p_right) {
    // return *(int *)p_left - *(int *)p_right; // ascending
    return *(int *)p_right - *(int *)p_left; // descending
}

int main(int argc, char *argv[]) {
    int a_list[5] = { 45, 13, 25, 50, 35 };

    // 함수주소로 콜백 함수로 지정/전달 (CompareDate)
    // qsort() 함수에서 두 요소를 비교할 때 CompareData (함수주소) 가 호출된다
    qsort(a_list, 5, sizeof(int), CompareData);

    for(auto &n : a_list) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}