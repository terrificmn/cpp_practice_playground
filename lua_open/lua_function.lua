function passTableToCpp() 
    return {
        my_param1 = "test",
        my_param2 = 10,
        my_param3 = 10.5,
        my_param4 = true
    }
end


-- ### sol2 를 이용하는 경우에는, 더 심플하게 table만 넘기려면.. 아래 처럼 할 수가 있다.
-- function 으로 구성을 했지만 단순하게 table로 구성을 한 후에  
-- c++코드에서 함수 이름으로 받아오던 것 처럼 변수 이름으로 받을 수 있다.  sol::function 으로 불러오지 않아도 되게 된다.
-- in a lua file...
-- myTable {
--     my_param1 = "test", 
--     my_param2 = 123
-- }

-- in a c++ code...
-- 생략.. script_file()로 오픈 한 후에   
-- sol::table myTable = lua["myTable"]; // sol::state lua 

-- 이후에는 sol::table 파싱해서 사용하게 된다.
