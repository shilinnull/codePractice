# student_name = "梁仕林"
# student_age = 21
# student_major = "计算机科学与技术"
#
# if student_age >= 18:
#     print(f"{student_name}是成年人")
#     print(f"专业：{student_major}")
# else:
#     print(f"{student_name}是未成年人")
# sum_age = student_age + 5
# print(f"5年后年龄：{sum_age}")

import sys
import pip
print(f"Python版本：{sys.version}")
# print(f"已安装库数量：{len(pip.get_installed_distributions())}")
age = int(input("请输入年龄："))
height = float(input("请输入身高（米）："))
print(f"年龄类型：{type(age)}，身高类型：{type(height)}")
print(f"5年后年龄：{age + 5}，身高保留1位小数：{round(height, 1)}")
name = input("请输入姓名：")
major = input("请输入专业：")
info = f"姓名：{name}\n专业：{major}\n年龄：{age}\n身高：{height}米"
print("\n=== 个人信息 ===")
print(info)

