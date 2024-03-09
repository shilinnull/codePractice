
# theSum = 0
# for i in range(1,101):
#     theSum += i
# print(theSum)
#
# theSum = 0
# for i in range(300,401):
#     theSum += i
# print(theSum)
#
# theSum = 0
# for i in range(1,1001):
#     theSum += i
# print(theSum)
#
# 定义一个求和函数

# def calcSum(beg,end):
#     theSum = 0
#     for i in range(beg,end + 1):
#         theSum += i
#     print(theSum)
#
# # 调用函数
# calcSum(1,100)
# calcSum(300,400)
# calcSum(1,1000)


# def getPoint():
#     x = 10
#     y = 20
#     return x,y
#
#
# a,b = getPoint()
# # 不要x，只要y
# _,b = getPoint()


def factor(n):
    if n == 1:
        return 1
    return n * factor(n - 1)

print(factor(5))
