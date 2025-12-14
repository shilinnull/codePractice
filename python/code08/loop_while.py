# # 任务4.1：while循环（条件满足时持续执行）
# print("=== while循环（累加求和） ===")
# # 案例：计算1-100的累加和（用while实现）
# sum_total = 0
# x = 1 # 初始值
# while x <= 100: # 循环条件：x≤100
#     sum_total += x
#     x += 1 # 更新变量（避免死循环）
# print(f"1-100的累加和：{sum_total}") # 预期5050
# # 任务4.2：break语句（跳出当前循环）
# print("\n=== break语句（猜数字游戏） ===")
# # 案例：猜数字（1-100），猜对用break退出
# import random # 导入随机数模块
# target = random.randint(1, 100) # 生成1-100的随机数
# guess_count = 0 # 猜的次数
# print("欢迎参加猜数字游戏！数字范围1-100")
# while True: # 无限循环，用break退出
#     guess = int(input("请输入你猜的数字："))
#     guess_count += 1
#     if guess == target:
#         print(f"恭喜你猜对了！数字是{target}，你猜了{guess_count}次")
#         break # 猜对，跳出循环
#     elif guess > target:
#         print("你猜的数字太大了，再试试！")
#     else:
#         print("你猜的数字太小了，再试试！")
# # 任务4.3：continue语句（跳过当前轮次，进入下一轮）
# print("\n=== continue语句（筛选偶数） ===")
# # 案例：打印1-20中的偶数，用continue跳过奇数
# print("1-20中的偶数：")
# for num in range(1, 21):
#     if num % 2 == 1: # 如果是奇数，跳过当前轮次
#         continue
#     print(num, end=" ") # 仅偶数会执行这行，预期2 4 ... 20
# print()
#
# # 正确案例：变量更新在循环内
# y = 1
# while y <= 5:
#     print(y, end=" ")
#     y += 1 # 正确：每次循环更新y，预期1 2 3 4 5


# 任务5：循环嵌套（打印菱形图案）
print("\n=== 循环嵌套（打印菱形） ===")
# 案例：打印5行菱形（上3行递增，下2行递减）
n = 3 # 菱形上半部分的行数（含中间行）
# 上半部分（3行，每行星星数：1→3→5）
for i in range(n):
    # 打印空格（每行空格数：2→1→0）
    for j in range(n - i - 1):
        print(" ", end="")
    # 打印星星（每行星星数：2i+1）
    for k in range(2 * i + 1):
        print("*", end="")
    print() # 换行
# 下半部分（2行，每行星星数：3→1）
for i in range(n - 1):
    # 打印空格（每行空格数：1→2）
    for j in range(i + 1):
        print(" ", end="")
    # 打印星星（每行星星数：2*(n-i-1)-1）
    for k in range(2 * (n - i - 1) - 1):
        print("*", end="")
    print() # 换行