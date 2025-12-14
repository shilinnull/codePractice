# 任务2：字符串操作与成员测试
# 2.1 字符串创建与基本属性
s1 = "Python程序设计" # 双引号
s2 = '基础与应用'     # 单引号
s3 = """多行
字符串"""            # 三引号（支持换行）
print("字符串基本信息：")
print(f"s1: { s1 }, 长度：{len(s1)}")
print(f"s2: { s2 }, 类型：{type(s2)}")

# 2.2 字符串切片（[起始:结束:步长]）
print("\n字符串切片：")
print(f"s1的前3个字符：{s1[:3]}") # 从开头到索引2（不含3)
print(f"s1的逆序：{s1[::-1]}")   # 步长为-1，逆序
print(f"s1的第2-5个字符（索引1-4）：{s1[1:5]}")

# 2.3 成员测试运算符（in / not in）
print("\n成员测试：")
print(f"'Python'是否在s1中：{'Python' in s1}") # 预期True
print(f"'Java'是否在s1中：{'Java' in s1}")     # 预期False
print(f"'应用'是否在s2中：{'应用' in s2}")      # 新增测试

# 2.4 字符串常用方法（参考菜鸟编程“Python3 字符串方法”）
print("\n字符串方法：")
print(f"s1大写：{s1.upper()}")     # 全大写
print(f"s2小写: {s2.lower()}")    # 全小写
print(f"s1替换: {s1.replace('Python', 'Py')}") # 替换子串
print(f"s3去除两端空白：{s3.strip()}") # 新增：去除换行与空格
print(f"s1是否以'Py'开头：{s1.startswith('Py')}") # 新增：判断开头



