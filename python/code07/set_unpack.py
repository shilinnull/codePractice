# 任务4.1：集合实际应用（数据去重、元素筛选）
print("=== 集合应用 ===")
# 4.1.1 列表去重（重复成绩）
scores = [85, 92, 78, 85, 90, 92, 88]
unique_scores = set(scores)
print(f"原始成绩列表（含重复）：{scores}")
print(f"去重后成绩集合：{unique_scores}") # 预期{78,85,88,90,92}
# 4.1.2 筛选共同元素（两个班级的共同学生）
class1 = {"张三", "李四", "王五", "赵六"}
class2 = {"王五", "赵六", "孙七", "周八"}
common_students = class1 & class2 # 交集
print(f"两个班级共同学生：{common_students}") # 预期{"王五","赵六"}
# 4.1.3 筛选仅在一个班级的学生（对称差）
only_one_class = class1 ^ class2
print(f"仅在一个班级的学生：{only_one_class}") # 预期{"张三","李四","孙七","周八"}

# 任务4.2：序列解包（列表/元组/字典）
print("\n=== 序列解包 ===")
# 4.2.1 列表解包（多变量赋值）
lst = [10, 20, 30]
a, b, c = lst
print(f"列表解包：a={a}, b={b}, c={c}") # 预期a=10,b=20,c=30
# 4.2.2 元组解包（函数返回多值时常用）
def get_info():
    return "李四", 21, "软件工程" # 自动封装为元组
name, age, major = get_info()
print(f"元组解包（函数返回）：{name}, {age}岁, {major}") # 预期李四...

# 4.2.3 字典解包（*解键，**解键值对）
dict1 = {"a": 1, "b": 2}
dict2 = {"c": 3, "d": 4}
# *解包键，合并为列表
keys = [*dict1, *dict2]
print(f"字典键解包：{keys}") # 预期["a","b","c","d"]
# **解包键值对，合并字典（Python 3.5+支持）
merged_dict = {**dict1, **dict2}
print(f"字典键值对解包（合并）：{merged_dict}") # 预期{"a":1,"b":2,"c":3,"d":4}
# 4.2.4 不定长解包（用*接收多个元素）
nums = [1, 2, 3, 4, 5]
first, *middle, last = nums
print(f"不定长解包：first={first}, middle={middle}, last={last}") # 预期first=1, middle=[2,3,4], last=5


