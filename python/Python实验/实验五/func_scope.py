global_var = "全局变量"
def test_scope():
    local_var = "局部变量"
    print(f"函数内访问局部变量： {local_var}")
    print(f"函数内访问全局变量： 全局变量")
    global_var = "函数内修改的变量"
    print(f"函数内修改后的'global_var'（局部） ： {global_var}")
def modify_global():
    global global_var
    global_var = "通过global修改的全局变量"

print(f"函数外访问全局变量： {global_var}")
test_scope()
print(f"函数调用后， 函数外访问全局变量： {global_var}")
modify_global()
print(f"modify_global调用后， 全局变量： {global_var}")
def outer_func():
    outer_var = "外部函数变量"
    def inner_func():
        nonlocal outer_var
        outer_var = "内部函数修改的外部变量"
        print(f"内部函数访问外部变量： {outer_var}")
    inner_func()
    print(f"外部函数访问变量： {outer_var}")
outer_func()


