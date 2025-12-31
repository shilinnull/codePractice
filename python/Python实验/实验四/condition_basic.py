num = 22
result = f"{num}是奇数" if num % 2 == 1 else f"{num}是偶数"
print(result)
a, b = 23, 18
max_num = a if a > b else b
print(f"{a}和{b}中较大的数是：{max_num}")
age = int(input("请输入年龄："))
if age < 18:
    print("你是未成年人，需监护人陪同！")
score = int(input("请输入考试成绩："))
if score >= 60:
    print(f"成绩{score}，结果及格")
else:
    print(f"成绩{score}，结果不及格，需要补考")




grade = int(input("请输入成绩（0-100）："))
if grade >= 90 and grade <= 100:
    level = "A"
elif grade >= 80:
    level = "B"
elif grade >= 70:
    level = "C"
elif grade >= 60:
    level = "D"
elif grade >= 0:
    level = "E"
else:
    level = "无效成绩"
print(f"成绩等级：{level}")
is_vip = input("是否为会员（y/n）").lower()
total = float(input("购物总金额（元）："))
discount = 0
if is_vip == "y":
    if total >= 200:
        discount = 50
    print("会员满200，享受50元折扣")
else:
    if total >= 300:
        discount = 30
    print("非会员满300，享受30元折扣")
final_pay = total - discount
print(f"支付金额：{final_pay:.2f}元")