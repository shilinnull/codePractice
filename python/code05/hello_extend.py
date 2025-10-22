# # 实验一：IDLE基础练习（单行注释）
# """
# 多行注释：
# 功能1：固定输出Hello World
# 功能2：接收用户姓名并个性化输出
# 功能3：计算1+2的结果并输出
# """
# # 功能1：固定输出
# print("Hello World！这是我的第一个Python程序")
# # 功能2：个性化输出（input()接收字符串）
# username = input("请输入你的姓名：")
# print(f"你好，{username}！欢迎学习Python") # f-string格式化
# # 功能3：简单计算（int()转换类型，避免字符串拼接错误）
# num1 = 1
# num2 = 2
# sum_result = num1 + num2
# print(f"{num1} + {num2} = {sum_result}") # 输出计算结果
#

# 单元格1：查看Python版本与已安装库
import sys
import pip
print(f"Python版本：{sys.version}")
# print(f"已安装库数量：{len(pip.get_installed_distributions())}")
# 单元格2：变量类型转换练习
# 接收用户输入的年龄（str→int）与身高（str→float）
age = int(input("请输入年龄："))
height = float(input("请输入身高（米）："))
print(f"年龄类型：{type(age)}, 身高类型：{type(height)}")
print(f"5年后年龄：{age + 5}，身高保留1位小数：{round(height, 1)}")



