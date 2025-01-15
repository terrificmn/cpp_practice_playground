1. don't use it

contiguous memory 

stack and heap

array 는 stack
vector 는 heap

heap는 stack보다 느리다

대개 컴파일러마다 다르지만 push_back 등으로 확장할 때 메모리 allocation이 두 배씩 늘어남


reserve()로 할당하는 것이 좋다.


emplace_back()를 사용해서 파라미터로 바로 넘긴다. // 연구 필요 - push_back과 다른점
만약 emplace_back(data(i)) 식으로 사용하면 push_back과 다를게 없다고 함
emplace_back(i) 처럼 사용