# # 任务4.1：lambda表达式（匿名函数，简化简单逻辑）
# print("=== lambda表达式测试 ===")
# # 案例1：定义简单lambda函数（计算平方）
# square = lambda x: x ** 2
# print(f"5的平方（lambda）：{square(5)}") # 预期25
# # 案例2：结合sorted()排序（按元组的第二个元素排序）
# students = [("张三", 20), ("李四", 19), ("王五", 21)]
# sorted_students = sorted(students, key=lambda x : x[1])    # key指定排序依据
# print(f"按年龄排序的学生：{sorted_students}") # 预期[("李四",19), ("张三",20), ("王五",21)]
# # 案例3：结合filter()筛选（筛选偶数）
# nums = [1, 2, 3, 4, 5, 6]
# even_nums = list(filter(lambda x : x % 2 == 0, nums))
# print(f"筛选后的偶数：{even_nums}") # 预期[2,4,6]
# # 任务4.2：生成器函数（用yield返回，惰性生成）
# print("\n=== 生成器函数测试 ===")
# # 案例1：生成1-n的奇数（对比列表生成，节省内存）
# def odd_generator(n):
#     """生成1-n的所有奇数（生成器函数）"""
#     for i in range(1, n+1, 2):
#         yield i # 暂停并返回当前值，下次调用从这里继续
# # 遍历生成器（生成器只能遍历一次）
# gen = odd_generator(10)
# print("1-10的奇数（生成器遍历）：", end="")
# for num in gen:
#     print(num, end=" ") # 预期1 3 5 7 9
# print()
# # 再次遍历（无结果，生成器已耗尽）
# print("生成器再次遍历：", end="")
# for num in gen:
#     print(num, end=" ") # 无输出
# print()
# # 案例2：无限生成器（按需求生成，不占内存）
# def infinite_fib():
#     """无限生成斐波那契数列（生成器函数）"""
#     a, b = 0, 1
#     while True:
#         yield a
#         a, b = b, a + b
# # 取斐波那契数列前10个元素
# fib_gen = infinite_fib()
# print("斐波那契数列前10个元素：", end="")
# for _ in range(10):
#     print(next(fib_gen), end=" ") # 预期0 1 1 2 3 5 8 13 21 34


# 任务5：递归函数（函数调用自身，解决分治问题）
print("\n=== 递归函数测试 ===")
# 案例1：计算n的阶乘（n! = n*(n-1)*...*1，边界条件n=1时返回1）
def factorial(n):
    if n == 1: # 递归边界（终止条件）
        return 1
    else:
        return n * factorial(n - 1) # 递归调用（问题规模缩小）
# 案例2：计算斐波那契数列第n项（递归实现，效率较低，仅作演示）
def fib_recursive(n):
    if n <= 2:
        return 1 # 边界条件：第1、2项为1
    else:
        return fib_recursive(n - 1) + fib_recursive(n - 2)
# 递归测试
print(f"5的阶乘（递归）：{factorial(5)}") # 预期120
print(f"斐波那契数列第10项（递归）：{fib_recursive(10)}") # 预期55