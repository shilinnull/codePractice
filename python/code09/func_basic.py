# # 任务1.1：无参函数（打印欢迎信息）
# def print_welcome():
#     """打印程序欢迎信息（函数文档字符串）"""
#     print("=" * 30)
#     print("欢迎使用Python函数练习程序")
#     print("=" * 30)
#
# # 任务1.2：有参函数（计算两数之和）
# def add(a, b):
#     """计算两个数的和，返回结果"""
#     result = a + b
#     return result # 返回计算结果
#
# # 任务1.3：多返回值函数（计算两数的和与差）
# def add_sub(a, b):
#     """返回两个数的和与差（元组形式）"""
#     sum_ab = a + b
#     diff_ab = a - b
#     return sum_ab, diff_ab # 多个返回值自动封装为元组
#
# # 函数调用测试
# print("=== 基本函数调用测试 ===")
# print_welcome() # 调用无参函数
# sum_result = add(15, 23) # 调用有参函数，接收返回值
# print(f"15 + 23 = {sum_result}") # 预期38
# sum_ab, diff_ab = add_sub(30, 12) # 多返回值解包
# print(f"30 + 12 = {sum_ab}, 30 - 12 = {diff_ab}") # 预期42, 18
# # 查看函数文档字符串（help()函数）
# print(f"\nadd函数文档：{add.__doc__}")

# 任务2.1：位置参数与默认值参数（计算商品折扣价）
def calculate_discount(price, discount=0.9):
    """
    计算商品折扣价
    price：位置参数，商品原价（必传）
    discount：默认值参数，折扣率（默认9折，可选）
    """
    return price * discount
# 任务2.2：关键参数（指定参数名传递，顺序可灵活）
def print_student_info(name, age, major):
    """打印学生信息，支持关键参数传递"""
    print(f"姓名：{name}，年龄：{age}，专业：{major}")
# 任务2.3：不定长度参数（*args接收元组，**kwargs接收字典）
def print_args(*args, **kwargs):
    """打印不定长度参数：*args接收位置参数，**kwargs接收关键参数"""
    print(f"位置参数元组args：{args}")
    print(f"关键参数字典kwargs：{kwargs}")
# 任务2.4：传递参数时的序列解包（列表/元组解包给位置参数，字典解包给关键参数）
def add_three(a, b, c):
    """计算三个数的和"""
    return a + b + c
# 参数类型测试
print("\n=== 函数参数类型测试 ===")
# 2.1 默认值参数测试（不传折扣、传折扣）
print(f"原价100，默认9折：{calculate_discount(100)}") # 预期90.0
print(f"原价200，8折：{calculate_discount(200, 0.8)}") # 预期160.0
# 2.2 关键参数测试（打乱顺序）
print("\n关键参数传递（打乱顺序）：")
print_student_info(major="计算机", name="李四", age=20) # 预期正常打印
# 2.3 不定长度参数测试
print("\n不定长度参数测试：")
print_args(10, 20, "Python", name="张三", age=19) # args=(10,20,"Python"), kwargs={"name":"张三",...}
# 2.4 序列解包测试
nums = [10, 20, 30] # 列表
num_tuple = (5, 15, 25) # 元组
num_dict = {"a": 8, "b": 18, "c": 28} # 字典