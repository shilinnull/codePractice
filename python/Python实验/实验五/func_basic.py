def print_welcome():
    """打印程序欢迎信息（函数文档字符串） """
    print("=" * 30)
    print("使用Python函数练习")
    print("=" * 30)
def add(a, b):
    """计算两个数的和， 返回结果"""
    result = a + b
    return result
def add_sub(a, b):
    """返回两个数的和与差（元组形式） """
    sum_ab = a + b
    diff_ab = a - b
    return sum_ab, diff_ab
print_welcome() # 调用无参函数
sum_result = add(55, 66)
print(f"55 + 66 = {sum_result}")
sum_ab, diff_ab = add_sub(77, 88)
print(f"77 + 88 = {sum_ab}, 77 - 88 = {diff_ab}")
print(f"\nadd函数文档： {add.__doc__}")


def calculate_discount(price, discount=0.9):
    """
    计算商品折扣价
    price： 位置参数， 商品原价（必传）
    discount： 默认值参数， 折扣率（默认9折， 可选）
    """
    return price * discount
def print_student_info(name, age, major):
    """打印学生信息， 支持关键参数传递"""
    print(f"姓名： {name}， 年龄： {age}， 专业： {major}")
def print_args(*args, **kwargs):
    """打印不定长度参数： *args接收位置参数， **kwargs接收关键参数"""
    print(f"位置参数元组args： {args}")
    print(f"关键参数字典kwargs： {kwargs}")
def add_three(a, b, c):
    """计算三个数的和"""
    return a + b + c
print(f"原价100， 默认9折： {calculate_discount(100)}") # 预期90.0
print(f"原价200， 8折： {calculate_discount(200, 0.8)}")
print_student_info(major="计算机", name="梁仕林", age=21)
print_args(10, 20, "Python", name="张三", age=19)
nums = [10, 20, 30]
num_tuple = (5, 15, 25)
num_dict = {"a": 8, "b": 18, "c": 28}
print(f"\n列表解包求和： {add_three(*nums)}")
print(f"元组解包求和： {add_three(*num_tuple)}")
print(f"字典解包求和： {add_three(**num_dict)}")






