
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


# def factor(n):
#     if n == 1:
#         return 1
#     return n * factor(n - 1)
#
# print(factor(5))

# 缺省参数
# def add(x,y,debug = False):
#     if debug:
#         print(x,y)
#     return x +y
#
# result = add(10,20,True)
# result = add(10,20)
# print(result)

# 指定参数传参
# def test(x,y):
#     print(f'x = {x}')
#     print(f'x = {y}')
#
#
# test(x = 20,y = 10)
# test(y = 100,x = 200)


