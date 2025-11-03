# 任务3：序列与集合操作
# 3.1 列表创建与修改（新增更多方法）
lst = [10, 20, 30, 40, 50] # 列表(可变)
print("列表操作：")
lst[2] = 35             # 修改索引2的元素
print(f"修改后的链表：{lst}")
lst.append(60)
print(f"追加后的列表：{lst}")
lst.insert(1, 15)   # 新增：在索引1插入15
print(f"插入后的列表：{lst}")
lst.remove(40)          # 新增：删除值为40的元素
print(f"删除40后的列表：{lst}")
print(f"列表排序（升序）：{sorted(lst)}")    # 新增：排序

# 3.2 元组创建（不可变）
tpl = (10, 20, 30, 20)
print("\n 元组操作：")
print(f"元组第2个元素：{tpl[1]}") # 索引访问
print(f"元组中20的出现次数：{tpl.count(20)}") # 新增：统计元素次数
print(f"元组中30的索引：{tpl.index(30)}") # 新增：查找元素索引
# 尝试修改元组（注释掉，否则报错）
# tpl[1] = 25 # 元组不可变，运行会抛异常

# 3.3 集合创建与集合运算符（新增更多运算）
set1 = {1, 2, 3, 4, 5}
set2 = {4, 5, 6, 7, 8}
print("\n集合运算：")
print(f"并集（|）：{set1 | set2}") # 所有元素
print(f"交集（&）：{set1 & set2}") # 共同元素
print(f"差集（&）：{set1 - set2}") # set1有、set2无的元素
print(f"对称差（^）：{set1 ^ set2}") # 仅一个集合有的元素
set1.add(6)     # 新增：向set1添加元素6
print(f"set1添加6后：{set1}")
print(f"set1是否为set2的子集：{set1.issubset(set2)}") # 新增：判断子集

# 3.4 内置函数应用（max/min/sum/len）
print("\n内置函数：")
print(f"列表最大值：{max(lst)}")
print(f"元组最小值：{min(tpl)}")
print(f"集合求和：{sum(set1)}")
print(f"列表长度：{len(lst)}") # 新增：列表长度

