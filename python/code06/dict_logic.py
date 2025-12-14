# 任务4：字典与逻辑运算
# 4.1 字典创建与元素访问（新增更多方法）
student = {
    "name": "李四",
    "age": 21,
    "major": "软件工程",
    "score": {"语文": 85, "数学": 92, "英语": 78} # 嵌套字典（新增）
} # 字典（键值对）
print("字典操作：")
print(f"学生姓名：{student['name']}") # 按键访问
print(f"学生数学成绩：{student['score']['数学']}") # 新增：嵌套字典访问
print(f"学生年龄（get方法）：{student.get('age')}") # 用get()方法访问
print(f"是否有'gender'键：{'gender' in student}") # 成员测试（键）
student["grade"] = "大三"     # 新增：添加键值对
print(f"添加年级后的字典：{student}")
print(f"字典所有键：{student.keys()}") # 新增：获取所有键
print(f"字典所有值：{student.values()}") # 新增：获取所有值

# 4.2 逻辑运算符（and/or/not，惰性求值）
print("\n逻辑运算：")
a = 10
b = 20
c = 0
print(f"a>5 and b<25：{a>5 and b<25}") # 两个条件都成立
print(f"a<5 or b>15：{a<5 or b>15}") # 至少一个条件成立
print(f"not (c==0)：{not (c==0)}")  # 否定条件
# 新增：复杂逻辑判断（年龄是否在18-22之间）
age = 21
print(f"年龄是否在18-22之间：{age >= 18 and age <= 22}")
# 4.3 复杂表达式（结合运算符优先级）
# 优先级：算术 > 关系 > 逻辑
result = (a + b) > 25 and (b - a) < 15 or not (c == 0)
print(f"复杂表达式结果：{result}") # 先算算术，再算关系，最后算逻辑
# 新增：计算BMI是否正常（18.5 ≤ BMI < 24）
bmi = 21.2
bmi_normal = 18.5 <= bmi < 24
print(f"BMI是否正常：{bmi_normal}")

