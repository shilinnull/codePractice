# 综合案例：个人信息与简易计算器
print("===== 个人信息录入 =====")
# 1. 个人信息录入与BMI计算
name = input("请输入姓名：")
age = int(input("请输入年龄："))
height = float(input("请输入身高（米）："))
weight = float(input("请输入体重（公斤）："))
# 补充1：计算BMI（体重/身高的平方）
bmi = weight / (height * height)
bmi = round(bmi, 1) # 保留1位小数
# 补充2：判断BMI等级（多分支选择）
if bmi < 18.5:
    bmi_level = "偏瘦"
elif 18.5 <= bmi < 25:
    bmi_level = "正常"
else:
    bmi_level = "超重"
# 格式化输出个人信息
print(f"\n=== {name}的个人信息 ===")
print(f"年龄：{age}岁")
print(f"身高：{height}米，体重：{weight}公斤")
print(f"BMI指数：{bmi}，等级：{bmi_level}")
print("\n===== 简易计算器 =====")
# 2. 简易计算器（处理输入与运算）
num1 = float(input("请输入第一个数字："))
num2 = float(input("请输入第二个数字："))
op = input("请输入运算符（+、-、*、/）：")
# 补充3：根据运算符执行对应运算
result = 0
if op == "+":
    result = num1 + num2
elif op == "-":
    result = num1 - num2
elif op == "*":
    result = num1 * num2
elif op == "/":
# 补充4：处理除数为0的情况
    if num2 == 0:
        print("错误：除数不能为0！")
        exit() # 退出程序
    result = num1 / num2
else:
    print("错误：无效运算符！")
    exit()
# 输出计算结果
print(f"\n计算结果：{num1} {op} {num2} = {result}")