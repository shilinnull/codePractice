alist = [1, 2, 3]

# alist = list()
print(type(alist))
alist = [1, 'hello', 3.14]

print(alist[-1])
print(alist[2])
print(alist)
alist = [1, 2, 3, 4, 5]
print(alist[1:3])
print(alist[:3])
print(alist[:-1])
print(alist[:])
print(alist[1::2])
print(alist[::-1])
print(alist[::-2])
print(alist[::-3])

for elem in alist:
    print(elem)

for i in range(0, len(alist), 2):
    print(alist[i]);

i = 0
while i < len(alist):
    print(alist[i])
    i += 1

alist = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'];
alist.append('j');
print(alist)
alist.insert(1, 'j');
print(alist)

print('d' in alist);
print('x' in alist);

print(alist.index('e'));
# print(alist.index('x'));

print(alist)
alist.pop()
print(alist)
alist.pop(2)
print(alist)

alist = [1, 2, 3, 4, 5]
blist = [5, 6, 7]
# print(alist + blist)
alist.extend(blist)
print(alist)
print(blist)

atuple = ()
atuple = tuple()

def getPoint():
    return 10, 20

result = getPoint()
print(type(result))

a = { 'id': 1, 'name' : 'John', 'age': 20}
b = dict()
print(type(a))
print(type(b))

b = {
    'id' : 1,
    'name' : 'John',
    'age' : 20
}
print(b)
print('id' in b)

print(b['name'])

b['name'] = 'zhangsan'
print(b['name'])

b.pop('name')
print(b)

for key in b:
    print(key, b[key])
print(b.keys())
print(b.values())
print(b.items())

print(hash('hello'))
print(hash(3.14))
