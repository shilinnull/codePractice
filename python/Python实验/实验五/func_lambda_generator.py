square = lambda x: x ** 2
print(f"5的平方（lambda） ： {square(5)}")
students = [("梁仕林", 21), ("李四", 20), ("王五", 21)]
sorted_students = sorted(students, key=lambda x: x[1])
print(f"按年龄排序的学生： {sorted_students}")
nums = [1, 2, 3, 4, 5, 6]
even_nums = list(filter(lambda x: x % 2 == 0, nums))
print(f"筛选后的偶数： {even_nums}")
def odd_generator(n):
    """生成1-n的所有奇数（生成器函数） """
    for i in range(1, n+1, 2):
        yield i
gen = odd_generator(10)
print("1-10的奇数（生成器遍历） ： ", end="")
for num in gen:
    print(num, end=" ")
print("生成器再次遍历： ", end="")
for num in gen:
    print(num, end=" ") #无
print()
def infinite_fib():
    """无限生成斐波那契数列（生成器函数） """
    a, b = 0, 1
    while True:
        yield a
        a, b = b, a + b
fib_gen = infinite_fib()
print("斐波那契数列前10个元素： ", end="")
for _ in range(10):
    print(next(fib_gen), end=" ")

def factorial(n):
    if n == 1:
        return 1
    else:
        return n * factorial(n - 1)
def fib_recursive(n):
    if n <= 2:
        return 1
    else:
        return fib_recursive(n - 1) + fib_recursive(n - 2)
print(f"5的阶乘（递归） ： {factorial(5)}")
print(f"斐波那契数列第10项（递归） ： {fib_recursive(10)}")








