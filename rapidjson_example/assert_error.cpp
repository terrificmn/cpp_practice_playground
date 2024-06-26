Size()를 적용해서 배열 크기를 확인할 경우에 
array와 object 인 경우에는 Size() 메소드를 사용할 수가 있다.

다만, debug 모드로 빌드를 하게 되면  
assert failed 에러가 발생한다. 

단순하게 release 빌드로 catkin build 식으로 진행을 하면 단순히 해결될 수 있으나

override 기능으로 define을 하게 되면  debug 모드에서도 사용가능


