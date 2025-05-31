print("hello world");

print(1 + 2 / 7);

print( (67.5 + 89.0 + 12.9 + 32.2) / 4 )


avg = (67.5 + 89.0 + 12.9 + 32.2) / 4
# ** 2   为求平方
total = (67.5 - avg) ** 2 + (89.0 - avg) ** 2 + (12.9 - avg) ** 2 + (32.2 - avg) ** 2
result = total / 3
print(result)

a = 10
b = 0.01
print(type(a))
print(type(b))

a = '111'
print(type(a));

c = 'hello'
d = 'world'
print(c + d)

num = 0
num = input("Enter a number: ")
print(f'num：{num}')

a = input("Enter a number: ");
b = input("Enter a number: ");

# 转换
a = int(a)
b = int(b)

print(f'a + b = { a + b }')

# print(10 / 0)

print(2 ** 0.5)

print(4 // 3)
print(0.1 + 0.2 == 0.3)

f, g = 0, 1
print(f, g);
g, f = f, g
print(f, g);
