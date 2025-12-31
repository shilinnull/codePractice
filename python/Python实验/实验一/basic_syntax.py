num_int = 100
num_float = 3.14
is_student = True
course_list = ["Python", "计算机", "数学"]
print("=== 变量类型 ===")
print(f"num_int类型：{type(num_int)}，值：{num_int}")
print(f"course_list类型：{type(course_list)}，第2门课：{course_list[1]}")
num_a = input("请输入第一个数字：")
num_b = input("请输入第二个数字：")
num_a = float(num_a)
num_b = float(num_b)
print(f"两数之和：{num_a + num_b}")
print(f"两数之积：{num_a * num_b}")
multi_line = "第一行\n第二行\t（制表符）\n第三行\"双引号\""
print(multi_line)
student_score = 99
if student_score >= 60:
    print("及格")
else:
    print("不及格")