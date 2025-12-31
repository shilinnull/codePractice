lst = [10, 20, 30, 40, 50, 60, 70, 80,90]
print("=== 复杂切片 ===")
print(f"步长2切片：{lst[::2]}")
print(f"反向切片(取后三个): {lst[-3::-1]}")
lst[2:5] = [35, 45, 55]
print(f"切片修改后：{lst}")
print("=== 列表推导式 ===")
event_lst = [x for x in range(1, 11) if x % 2 == 0]
print(f"l-10偶数列表: {event_lst}")



matrix = [[i * 3 + j for j in range(1, 4)] for i in range(2)]
print(f"矩阵：{matrix}")
square_lst = []
for x in range(1, 11):
    square_lst.append(x ** 2)
print(f"列表（普通循环）：{square_lst}")
square_lst_comp = [x ** 2 for x in range(1, 11)]
print(f"列表（推导式）：{square_lst_comp}")
tpl = (10, 20, 30, 40, 50)
print(f"元组原始值：{tpl}")
list_comp = [x for x in range(1, 100001) if x % 2 == 1]
print(f"列表推导式占用内存（估算）：{len(list_comp) * 4}字节（假设int占4字节）")
gen_expr = (x for x in range(1, 100001) if x % 2 == 1)
print(f"生成器表达式类型：{type(gen_expr)}")
print(f"生成器前5个元素：", end="")
for _ in range(5):
    print(next(gen_expr), end=" ")