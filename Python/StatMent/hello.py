# while True:
#     choice = input("输入：")
#     if choice == '1':
#         print("1")
#     elif choice == '2':
#         print("2")
#     else:
#         print("0")

# a = int(input("输入："))
# if a % 2 == 1:
#     print("1")
# else:
#     print("0")
#

# a = int(input("输入："))
# if(a == 1):
#     print("hello")

# pass空语句
# a = int(input("输入："))
# if a != 1:
#     pass
# else:
#     print("hello")

# 循环
# num = 1
# while num <= 10:
#     print(num)
#     num += 1
#

# num = 1
# sum = 0
# while num <= 100:
#     sum += num
#     num += 1
#     print(sum);

# num = 1
# result = 1
# while num <= 5:
#     result *= num
#     num += 1
# print(result)


# num = 1
# sum = 0
# while num <= 5:
#     factorResult = 1
#     i = 1
#     while i <= num:
#         factorResult *= i
#         i += 1
#     sum += factorResult
#     num += 1
# print(sum)

# for循环
# for i in range(1,11):
#     print(i)
# range是一个内联函数

# 第三个参数是步长
# for i in range(2,12,2):
#     print(i)

# for i in range(10,0,-1):
#     print(i)
#
# sum = 0
# for i in range(1,101):
#     sum += i
# print(f'sum = {sum}')

# continue break

# for i in range(1,6):
#     if i == 3:
#         continue
#     print(f"吃{i}个")


# for i in range(1,6):
#     if i == 3:
#         break
#     print(f"吃{i}个")

# theSum = 0
# count = 0
# while True:
#     num = input("请输入(分号';'结尾)：")
#     if num == ';':
#         break
#     num = float(num)
#     theSum += num
#     count += 1
# print(f'平均值为{theSum / count}')

