
# f = open('test.txt','r')
# print(f)
# print(type(f))

# flist = []
# count = 0
# while True:
#     f = open('test.txt','r')
#     flist.append(f)
#
#     count += 1
#     print(f'打开的文件个数：{count}');


# f = open('test.txt','w')
# f.write('hello\n')
# f.write('world')
# f.close()


# f = open('test.txt','w')
# f.write('hello\n')
# f.close()
#
# f = open('test.txt','a')
# f.write('world')
# f.close()
#
# f.write('world')
# f.close()


# f = open('test.txt', 'r', encoding='utf8')
# result = f.read(2)
# print(result)
# f.close()
#


# f = open('test.txt', 'r', encoding='utf8')
# i = 0
# for line in f:
#     print(f'line : {i} > {line}', end=' ')
#     i += 1
# f.close()


# f = open('test.txt', 'r', encoding='utf8')
# lenses = f.readlines()
# print(lenses)
# f.close()


# 上下文管理器
# with open('test.txt', 'r', encoding='utf8') as f:
#     lines = f.readlines()
#     print(lines)

