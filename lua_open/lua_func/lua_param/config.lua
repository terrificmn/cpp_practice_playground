-- lua에서는 여러개의 파라미터를 넘겨주면 되고, cpp 함수에서 정의는 포인터로 정의하게 되어 있다 (lua_State* L)
model1_name = 'cylinder'
model1_x = -1.0 
model1_y = -1.0
model1_z = 0.0

--
model2_name = 's100_dummy'
model2_x = -2.0
model2_y = -1.0
model2_z = 0.0


-- print(num1)

passParamToCpp(
    model1_name, model1_x, model1_y, model1_z, 
    model2_name, model2_x, model2_y, model2_z
)
