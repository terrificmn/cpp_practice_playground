-- lua function
function myLuaFunction(num, str)
    print("===== here, lua script =====")
    print("This is lua, num = "..tostring(num)..", str = " ..str)
    -- 여기에서 .. 이 굉장히 중요하다 .. 을 빼면 실행이 안된다, 문자열과 문자열을 이어주는 놈인듯 하다
end


-- call C++ function from lua
-- lua에서는 cpp 펑션 이름만 있으면 바로 호출할 수 있다. 물론 cpp에서 lua_register(L, "lua펑션", cpp펑션)으로 지정해야함
passParamExample(10, 'function from Lua to C++')

-- 위의 passParamExample(), 그리고 아래의 passParamToCpp() 함수는 cpp와 연결된 함수임
-- 함수에서 cpp 함수로 파라미터가 넘어가게 된다 
-- lua에서는 여러개의 파라미터를 넘겨주면 되고, cpp 함수에서 정의는 포인터로 정의하게 되어 있다 (lua_State* L)

--- 사실 위의 방법과 동일
-- 5개의 파라미터 넘기기로 함 double 2개, int2개, string
-- 함수임
passParamToCpp(
    10.5, 
    20.5,
    7,
    8,
    'hello world lua'
    -- 111
)