lst = [10, 20, 30, 40, 50]
print("列表操作：")
lst[2] = 35
print(f"修改后的链表：{lst}")
lst.append(60)
print(f"追加后的列表：{lst}")
lst.insert(1, 15)
print(f"插入后的列表：{lst}")
lst.remove(40)
print(f"删除40后的列表：{lst}")
print(f"列表排序（升序）：{sorted(lst)}")

tpl = (10, 20, 30, 20)
print("\n 元组操作：")
print(f"元组第2个元素：{tpl[1]}")
print(f"元组中20的出现次数：{tpl.count(20)}")
print(f"元组中30的索引：{tpl.index(30)}")

set1 = {1, 2, 3, 4, 5}
set2 = {4, 5, 6, 7, 8}
print("\n集合运算：")
print(f"并集（|）：{set1 | set2}")
print(f"交集（&）：{set1 & set2}")
print(f"差集（&）：{set1 - set2}")
print(f"对称差（^）：{set1 ^ set2}")
set1.add(6)
print(f"set1添加6后：{set1}")
print(f"set1是否为set2的子集：{set1.issubset(set2)}")
print("\n内置函数：")
print(f"列表最大值：{max(lst)}")
print(f"元组最小值：{min(tpl)}")
print(f"集合求和：{sum(set1)}")
print(f"列表长度：{len(lst)}")