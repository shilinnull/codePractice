name = input("请输入姓名：")
age = int(input("请输入年龄："))
height = float(input("请输入身高（米）："))
weight = float(input("请输入体重（公斤）："))
bmi = weight / (height * height)
bmi = round(bmi, 1)
if bmi < 18.5:
    bmi_level = "偏瘦"
elif 18.5 <= bmi < 25:
    bmi_level = "正常"
else:
    bmi_level = "超重"
print(f"\n=== {name}的个人信息 ===")
print(f"年龄：{age}岁")
print(f"身高：{height}米，体重：{weight}公斤")
print(f"BMI指数：{bmi}，等级：{bmi_level}")
print("\n===== 简易计算器 =====")
num1 = float(input("请输入第一个数字："))
num2 = float(input("请输入第二个数字："))
op = input("请输入运算符（+、-、*、/）：")
result = 0
if op == "+":
    result = num1 + num2
elif op == "-":
    result = num1 - num2
elif op == "*":
    result = num1 * num2
elif op == "/":
    if num2 == 0:
        print("错误")
        exit()
    result = num1 / num2
else:
    print("错误：无效运算符！")
    exit()
print(f"\n计算结果：{num1} {op} {num2} = {result}")