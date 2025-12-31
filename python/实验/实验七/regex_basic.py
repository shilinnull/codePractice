import re # 导入正则表达式模块
# 任务1.1： 元字符与字符集（匹配特定字符）
print("=== 元字符与字符集 ===")
# 元字符.： 匹配任意字符（除换行）
pattern1 = r"P.th.n" # r表示原始字符串， 避免转义符问题
print(f"匹配'Python'： {re.match(pattern1, 'Python')}") # 匹配成功（.匹配y）
print(f"匹配'Pythn'： {re.match(pattern1, 'Pythn')}") # 匹配失败（长度不足）
# 字符集[]： 匹配括号内任意一个字符
pattern2 = r"[Pp]ython" # 匹配Python或python
print(f"匹配'python'： {re.match(pattern2, 'python')}") # 成功
print(f"匹配'Java'： {re.match(pattern2, 'Java')}") # 失败
# 范围字符集[a-z0-9]： 匹配小写字母或数字
pattern3 = r"[a-z0-9]{6}" # {6}表示匹配6次
print(f"匹配'abc123'： {re.match(pattern3, 'abc123')}") # 成功（6位字母数字）
print(f"匹配'ABC123'： {re.match(pattern3, 'ABC123')}") # 失败（大写字母）
# 任务1.2： 量词（*+?） 与分组（()）
print("\n=== 量词与分组 ===")
# 量词*： 匹配0次或多次， +： 1次或多次， ?： 0次或1次
pattern4 = r"ab*c" # b出现0次或多次
print(f"匹配'ac'： {re.match(pattern4, 'ac')}") # 成功（b0次）
print(f"匹配'abbc'： {re.match(pattern4, 'abbc')}")# 成功（b2次）
# 分组()： 提取子匹配结果
pattern5 = r"(\d{4})-(\d{2})-(\d{2})" # 匹配日期（年-月-日）
match_obj = re.match(pattern5, "2025-10-07")
if match_obj:
    print(f"完整匹配： {match_obj.group()}") # 完整结果： 2025-10-07
    print(f"年： {match_obj.group(1)}") # 第1组： 2025
    print(f"月： {match_obj.group(2)}") # 第2组： 10
    print(f"日： {match_obj.group(3)}") # 第3组： 07
# 任务1.3： 预定义字符集（\d\w\s）
print("\n=== 预定义字符集 ===")
# \d： 匹配数字（0-9） ， \w： 匹配字母/数字/下划线， \s： 匹配空白（空格/制表符/换行）
pattern6 = r"\w+@\w+\.\w+" # 简单邮箱匹配（字母数字@字母数字.字母）
print(f"匹配'abc123@qq.com'： {re.match(pattern6, 'abc123@qq.com')}") # 成功
print(f"匹配'abc@.com'： {re.match(pattern6, 'abc@.com')}") # 失败（@后无字符）
pattern7 = r"^\d{11}$" # ^开头， $结尾， 匹配11位数字（手机号）
print(f"匹配'13812345678'： {re.match(pattern7, '13812345678')}") # 成功
print(f"匹配'1381234567'： {re.match(pattern7, '1381234567')}")

# 任务2.1： re.match() vs re.search()（开头匹配vs任意位置匹配）
print("\n=== re.match() vs re.search() ===")
text = "Python is easy, Python is fun"
# re.match()： 仅匹配字符串开头
match1 = re.match(r"Python", text)
match2 = re.match(r"is", text)
print(f"re.match('Python')： {match1.group() if match1 else '无匹配'}") # 成功
print(f"re.match('is')： {match2.group() if match2 else '无匹配'}") # 无匹配
# re.search()： 匹配任意位置（ 第一个匹配）
search1 = re.search(r"is", text)
search2 = re.search(r"fun", text)
print(f"re.search('is')： {search1.group()}， 位置： {search1.span()}") # 位置(7,9)
print(f"re.search('fun')： {search2.group()}， 位置： {search2.span()}") # 位置(21,24)
# 任务2.2： re.findall()（ 提取所有匹配结果）
print("\n=== re.findall()提取结果 ===")
# 提取所有Python
all_python = re.findall(r"Python", text)
print(f"提取所有'Python'： {all_python}") # 预期["Python","Python"]
# 提取所有单词（\b单词边界）
all_words = re.findall(r"\b\w+\b", text)
print(f"提取所有单词： {all_words}") # 预期["Python","is","easy","Python","is","fun"]
# 提取所有以s结尾的单词
s_words = re.findall(r"\b\w+s\b", text)
print(f"提取以's'结尾的单词： {s_words}") # 预期["is","is"]
# 任务2.3： re.sub()（ 替换匹配内容）
print("\n=== re.sub()替换内容 ===")
# 将Python替换为Java
new_text1 = re.sub(r"Python", "Java", text)
print(f"替换Python→Java： {new_text1}") # 预期"Java is easy, Java is fun"
# 替换所有空格为逗号（ 指定替换次数， count=2）
new_text2 = re.sub(r"\s", ",", text, count=2)
print(f"替换前2个空格→逗号： {new_text2}") # 预期"Python,is,easy, Python is fun"
# 任务2.4： re.compile()（ 编译正则对象， 重复使用提高效率）
print("\n=== re.compile()编译正则 ===")
# 编译日期正则（ 重复使用多次）
date_pattern = re.compile(r"(\d{4})-(\d{2})-(\d{2})")
dates = ["2025-10-07", "2025-12-31", "invalid-date"]
for date in dates:
    match = date_pattern.match(date)
    if match:
        print(f"有效日期： {date}， 年： {match.group(1)}")
    else:
        print(f"无效日期： {date}")







