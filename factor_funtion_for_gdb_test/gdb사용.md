gcc, g++ 사용 중에 -g 옵션을 넣어서 컴파일을 해준다   

gdb 실행파일

layout next

break main (또는 b main (함수 이름))

run  을 해주면 실행이 되면서 바로 break가 걸린다  

next 를 하면 다음으로 넘어가짐

특정 변수를 보고 싶으면 print 변수명   (또는 p 변수명)

특정 함수로 보고싶으면 step 을 (s)  함수코드 라인에서 눌러준다   

다시 run 을 눌러주면 처음부터 다시 실행시킬 수가 있다  (y or n를 물어본다)


watch 변수명  을 해주면 해당 변수를 계속 추적해준다   

for문이나 while문에서 특정 break point를 지정하고 싶을 경우에는 

break 라인넘버   

그리고 continue (c) 를 입력해서 loop 진행 (break point에서 멈춘다)

종료할 때에는 q


