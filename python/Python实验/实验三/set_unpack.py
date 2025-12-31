scores = [77, 99, 60, 85, 77, 66, 88]
unique_scores = set(scores)
print(f"原始成绩列表（含重复）：{scores}")
print(f"去重后成绩集合：{unique_scores}")
class1 = {"王五", "梁仕林", "王五", "赵六"}
class2 = {"王五", "赵六", "孙七", "周八"}
common_students = class1 & class2
print(f"两个班级共同学生：{common_students}")
only_one_class = class1 ^ class2
print(f"仅在一个班级的学生：{only_one_class}")
lst = [10, 20, 30]
a, b, c = lst
print(f"列表解包a={a}, b={b}, c={c}")
def get_info():
    return "梁仕林", 21, "Python"
name, age, major = get_info()
print(f"解包{name}, {age}岁, {major}")
dict1 = {"a": 1, "b": 2}
dict2 = {"c": 3, "d": 4}
keys = [*dict1, *dict2]
print(f"字典键解包{keys}")
merged_dict = {**dict1, **dict2}
print(f"字典键值对解包（合并）：{merged_dict}")
nums = [1, 2, 3, 4, 5]
first, *middle, last = nums
print(f"不定长解包：first={first}, middle={middle}, last={last}")