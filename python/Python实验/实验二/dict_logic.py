student = {
    "name": "梁仕林",
    "age": 21,
    "major": "计算机科学与技术",
    "score": {"数学": 85, "C语言": 80, "英语": 90}
}
print(f"学生姓名：{student['name']}")
print(f"学生C语言成绩：{student['score']['C语言']}")
print(f"学生年龄（get方法）：{student.get('age')}")
print(f"是否有'gender'键：{'gender' in student}")
student["grade"] = "大三"
print(f"添加年级后的字典：{student}")
print(f"字典所有键：{student.keys()}")
print(f"字典所有值：{student.values()}")
a = 15
b = 25
c = 0
print(f"a>5 and b<25：{a>5 and b<25}")
print(f"a<5 or b>15：{a<5 or b>15}")
print(f"not (c==0)：{not (c==0)}")
age = 21
print(f"是否在18-22之间：{age >= 18 and age <= 22}")
result = (a + b) > 25 and (b - a) < 15 or not (c == 0)
print(f"复杂表达式结果：{result}")
bmi = 21.2
bmi_normal = 18.5 <= bmi < 24
print(f"BMI是否正常：{bmi_normal}")