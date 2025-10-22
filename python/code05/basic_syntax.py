# # 练习1：注释与变量类型
# # 单行注释：定义不同类型变量
# num_int = 100 # 整数
# num_float = 3.14 # 浮点数
# is_student = True # 布尔值
# course_list = ["Python", "数学", "英语"] # 列表
# print("=== 变量类型 ===")
# print(f"num_int类型：{type(num_int)}，值：{num_int}")
# print(f"course_list类型：{type(course_list)}，第2门课：{course_list[1]}")

# 练习2：输入输出与类型转换
# print("\n=== 输入输出练习 ===")
# # 接收两个数字，计算和与积
# num_a = input("请输入第一个数字：")
# num_b = input("请输入第二个数字：")
# # 转换为float（兼容整数与小数输入）
# num_a = float(num_a)
# num_b = float(num_b)
# print(f"两数之和：{num_a + num_b}")
# print(f"两数之积：{num_a * num_b}")

# # 练习3：多行字符串与转义字符
# print("\n=== 转义字符练习 ===")
# multi_line = "第一行\n第二行\t（制表符）\n第三行\"双引号\""
# print(multi_line)

# 练习4：Python编程规范检查（自行修正以下代码错误）
# 错误1：变量命名不规范（中文）
# 学生_分数 = 85 # 修正为：student_score = 85
student_score = 85
# 错误2：缩进不统一（混合空格与制表符）
# if 学生_分数 >= 60:
if student_score >= 60:
    print("及格")
else:
    print("不及格")