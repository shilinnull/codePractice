# while True:
#     choice = input('输入1表示认真学习，输入2表示躺平>')
#     if choice == '1':
#         print("好工作")
#     elif choice == '2':
#         print("失业")
#     else:
#         print("输入有误")

# for i in range(10, 0, -2):
#     print(i)

# sum = 0;
# for i in range(10):
#     sum += i
#
# print(sum)

# def calcSum(begin, end):
#     sum = 0
#     for i in range(begin, end):
#         sum += i
#     print(sum)
#
# calcSum(1, 100)
# calcSum(5, 6)

def factor(n):
    if n == 1:
        return 1
    return n * factor(n-1)

result = factor(5)
print(result)





