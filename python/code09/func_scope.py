# 任务3.1：局部变量与全局变量（局部变量仅在函数内有效）
global_var = "全局变量" # 全局变量（函数外定义）
def test_scope():
    local_var = "局部变量" # 局部变量（函数内定义）
    print(f"函数内访问局部变量：{local_var}")
    # print(f"函数内访问全局变量：{global_var}") # 函数内可访问全局变量
    # 尝试修改全局变量（未用global，实际创建局部变量）
    global_var = "函数内修改的变量" # 此处是局部变量，非全局变量
    print(f"函数内修改后的'global_var'（局部）：{global_var}")
# 任务3.2：用global关键字修改全局变量
def modify_global():
    global global_var # 声明使用全局变量
    global_var = "通过global修改的全局变量" # 实际修改全局变量
# 作用域测试
print("=== 变量作用域测试 ===")
print(f"函数外访问全局变量：{global_var}") # 预期"全局变量"
test_scope()
print(f"函数调用后，函数外访问全局变量：{global_var}") # 预期仍为"全局变量"（test_scope内未用global)
modify_global()
print(f"modify_global调用后，全局变量：{global_var}") # 预期"通过global修改的全局变量"

# 任务3.3：嵌套函数的作用域（内部函数访问外部函数变量，nonlocal关键字）
def outer_func():
    outer_var = "外部函数变量"
    def inner_func():
        nonlocal outer_var # 声明使用外部函数的变量（非全局）
        outer_var = "内部函数修改的外部变量"
        print(f"内部函数访问外部变量：{outer_var}")
    inner_func()
    print(f"外部函数访问变量：{outer_var}") # 预期被内部函数修改

print("\n=== 嵌套函数作用域测试 ===")
outer_func()