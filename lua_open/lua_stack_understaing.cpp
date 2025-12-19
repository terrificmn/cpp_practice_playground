/*
lua 파라미터를 사용하게 되면 C API 로 stack 으로 하나씩 쌓아서 사용하게 된다.  
그래서 overflow가 되지 않게  pop 함수로 제거를 해줘야 한다. lua_pop()

Positive indices (from bottom)
1 = bottom of stack (first time)
2 = second item from bottom 
3= third time from bottom 
etc, and so on  

Negative indeices (from top)  
-1 = top of stack (most recent item)  
-2 = second from top  
-3 = second from top 
etc, and so on...


여기에서 lua 함수에서 -1를 파라미터로 사용하는 이유는 
최근 아이템을 보기 위해서임   

만약 postive 방식으로 사용하게 되면 1, 2 ,3... 계속 증가 하게 되어서  
카운트 하기가 힘들다 .  
*/

//예) 

// Stack: []
lua_getglobal(L, "MyObject");
// Stack: [MyObject]
// MyObject is at index 1 (from bottom) OR -1 (from top)

lua_getfield(L, -1, "product");  // -1 refers to MyObject
// Stack: [MyObject, product]
// MyObject is now at index 1 or -2
// product is at index 2 or -1

lua_rawgeti(L, -1, 1);  // -1 refers to product
// Stack: [MyObject, product, product[1]]
// MyObject is at index 1 or -3
// product is at index 2 or -2
// product[1] is at index 3 or -1



// negative 방식 
lua_getglobal(L, "MyObject");        // Stack: [MyObject]
lua_getfield(L, -1, "product");      // Stack: [MyObject, product]
lua_rawgeti(L, -1, 1);               // Stack: [MyObject, product, product[1]]
lua_getfield(L, -1, "vendor");       // Stack: [MyObject, product, product[1], vendor]
// Always use -1 for the top item!

positive 방식
lua_getglobal(L, "MyObject");        // Stack: [MyObject]
lua_getglobal(L, "SomeOtherTable");  // Stack: [MyObject, SomeOtherTable]
lua_getfield(L, 1, "product");       // Still works (MyObject is at 1)
// But if you were using 2, it would now be wrong!

