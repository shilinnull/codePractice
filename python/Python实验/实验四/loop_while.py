sum_total = 0
x = 1
while x <= 100:
    sum_total += x
    x += 1
print(f"1-100的累加和：{sum_total}")
print("\n=== break语句（猜数字游戏） ===")

import random
target = random.randint(1, 100)
print("测试要猜的数字：", target)
guess_count = 0
print("欢迎参加猜数字游戏！数字范围1-100")

while True:
    guess = int(input("请输入你猜的数字："))
    guess_count += 1
    if guess == target:
        print(f"恭喜你猜对了！数字是{target}，你猜了{guess_count}次")
        break # 猜对，跳出循环
    elif guess > target:
        print("你猜的数字太大了，再试试！")
    else:
        print("你猜的数字太小了，再试试！")

print("1-20中的偶数：")
for num in range(1, 21):
    if num % 2 == 1:
        continue
    print(num, end=" ")
print()

y = 1
while y <= 5:
    print(y, end=" ")
    y += 1

print()

n = 5
for i in range(n):
    for j in range(n - i - 1):
        print(" ", end="")
    for k in range(2 * i + 1):
        print("*", end="")
    print()
for i in range(n - 1):
    for j in range(i + 1):
        print(" ", end="")
    for k in range(2 * (n - i - 1) - 1):
        print("*", end="")
    print()