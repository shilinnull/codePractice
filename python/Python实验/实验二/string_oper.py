s1 = "Python程序设计"
s2 = '基础与应用'
s3 = """多行
字符串"""

print("字符串基本信息：")
print(f"s1: { s1 }, 长度：{len(s1)}")
print(f"s2: { s2 }, 类型：{type(s2)}")

print("\n字符串切片：")
print(f"s1的前3个字符：{s1[:3]}")
print(f"s1的逆序：{s1[::-1]}")
print(f"s1的第2-5个字符（索引1-4）：{s1[1:5]}")

print("\n成员测试：")
print(f"'C'是否在s1中：{'C' in s1}")
print(f"'Java'是否在s1中：{'Java' in s1}")
print(f"'应用'是否在s2中：{'应用' in s2}")
print("\n字符串方法：")
print(f"s1大写：{s1.upper()}")
print(f"s2小写: {s2.lower()}")
print(f"s1替换: {s1.replace('Python', 'Py')}")
print(f"s3去除两端空白：{s3.strip()}")
print(f"s1是否以'Py'开头：{s1.startswith('Py')}")