# # 任务1.1：条件表达式（替代简单if-else）
# print("=== 条件表达式 ===")
# # 案例1：判断奇偶并返回对应字符串
# num = 17
# result = f"{num}是奇数" if num % 2 == 1 else f"{num}是偶数"
# print(result) # 预期"17是奇数"
# # 案例2：比较两个数的大小，返回较大值
# a, b = 23, 18
# max_num = a if a > b else b
# print(f"{a}和{b}中较大的数是：{max_num}") # 预期23
# # 任务1.2：单分支结构（仅满足条件时执行）
# print("\n=== 单分支结构 ===")
# # 案例：判断输入的年龄是否小于18，提示“未成年”
# age = int(input("请输入年龄："))
# if age < 18:
#     print("提示：你是未成年人，需监护人陪同！") # 输入15时执行，输入20时不执行
# # 任务1.3：双分支结构（二选一执行）
# print("\n=== 双分支结构 ===")
# # 案例：判断成绩是否及格（≥60）
# score = int(input("请输入考试成绩："))
# if score >= 60:
#     print(f"成绩：{score}，结果：及格")
# else:
#     print(f"成绩：{score}，结果：不及格，需补考")

# 任务2.1：多分支结构（if-elif-else，多选一）
print("\n=== 多分支结构（成绩等级） ===")
# 案例：根据成绩划分等级（90-100:A，80-89:B，70-79:C，60-69:D，<60:E）
grade = int(input("请输入成绩（0-100）："))
if grade >= 90 and grade <= 100:
    level = "A（优秀）"
elif grade >= 80: # 隐含条件：<90
    level = "B（良好）"
elif grade >= 70: # 隐含条件：<80
    level = "C（中等）"
elif grade >= 60: # 隐含条件：<70
    level = "D（及格）"
elif grade >= 0: # 隐含条件：<60
    level = "E（不及格）"
else:
    level = "无效成绩（输入需在0-100之间）"
print(f"成绩等级：{level}") # 测试输入95→A，55→E，105→无效
# 任务2.2：嵌套选择结构（选择内部套选择）
print("\n=== 嵌套选择结构（会员折扣） ===")
# 案例：商场折扣规则：会员满200减50，非会员满300减30；不满不减免
is_vip = input("是否为会员？（y/n）：").lower() # 转为小写，统一输入格式
total = float(input("购物总金额（元）："))
discount = 0 # 折扣金额，初始为0
if is_vip == "y":
# 会员：满200减50
    if total >= 200:
        discount = 50
    print("会员满200，享受50元折扣！")
else:
# 非会员：满300减30
    if total >= 300:
        discount = 30
    print("非会员满300，享受30元折扣！")
final_pay = total - discount
print(f"最终支付金额：{final_pay:.2f}元") # 保留2位小数，测试会员250→200，非会员350→320

