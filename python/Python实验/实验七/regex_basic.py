import re
print("=== 元字符与字符集 ===")
pattern1 = r"P.th.n"
print(f"匹配'Python'： {re.match(pattern1, 'Python')}")
print(f"匹配'Pythn'： {re.match(pattern1, 'Pythn')}")
pattern2 = r"[Pp]ython" # 匹配Python或python
print(f"匹配'python'： {re.match(pattern2, 'python')}")
print(f"匹配'Java'： {re.match(pattern2, 'Java')}")
pattern3 = r"[a-z0-9]{6}"
print(f"匹配'abc123'： {re.match(pattern3, 'abc123')}")
print(f"匹配'ABC123'： {re.match(pattern3, 'ABC123')}")
print("\n=== 量词与分组 ===")
pattern4 = r"ab*c"
print(f"匹配'ac'： {re.match(pattern4, 'ac')}")
print(f"匹配'abbc'： {re.match(pattern4, 'abbc')}")
pattern5 = r"(\d{4})-(\d{2})-(\d{2})"
match_obj = re.match(pattern5, "2025-10-07")
if match_obj:
    print(f"完整匹配： {match_obj.group()}")
    print(f"年： {match_obj.group(1)}")
    print(f"月： {match_obj.group(2)}")
    print(f"日： {match_obj.group(3)}")
print("\n=== 预定义字符集 ===")
pattern6 = r"\w+@\w+\.\w+"
print(f"匹配'abc123@qq.com'： {re.match(pattern6, 'abc123@qq.com')}")
print(f"匹配'abc@.com'： {re.match(pattern6, 'abc@.com')}")
pattern7 = r"^\d{11}$"
print(f"匹配'1654111'： {re.match(pattern7, '1654111')}")
print(f"匹配'25646111264'： {re.match(pattern7, '25646111264')}")




print("\n=== re.match() vs re.search() ===")
text = "Python is easy, Python is fun"
match1 = re.match(r"Python", text)
match2 = re.match(r"is", text)
print(f"re.match('Python')： {match1.group() if match1 else '无匹配'}")
print(f"re.match('is')： {match2.group() if match2 else '无匹配'}")
search1 = re.search(r"is", text)
search2 = re.search(r"fun", text)
print(f"re.search('is')： {search1.group()}， 位置： {search1.span()}")
print(f"re.search('fun')： {search2.group()}， 位置： {search2.span()}")
print("\n=== re.findall()提取结果 ===")
all_python = re.findall(r"Python", text)
print(f"提取所有'Python'： {all_python}")
all_words = re.findall(r"\b\w+\b", text)
print(f"提取所有单词： {all_words}")
s_words = re.findall(r"\b\w+s\b", text)
print(f"提取以's'结尾的单词： {s_words}") # 预期["is","is"]
print("\n=== re.sub()替换内容 ===")
new_text1 = re.sub(r"Python", "Java", text)
print(f"替换Python→Java： {new_text1}")
new_text2 = re.sub(r"\s", ",", text, count=2)
print(f"替换前2个空格→逗号： {new_text2}")
print("\n=== re.compile()编译正则 ===")
# 编译日期正则（ 重复使用多次）
date_pattern = re.compile(r"(\d{4})-(\d{2})-(\d{2})")
dates = ["2025-11-26", "2025-12-31", "invalid-date"]
for date in dates:
    match = date_pattern.match(date)
    if match:
        print(f"有效日期： {date}， 年： {match.group(1)}")
    else:
        print(f"无效日期： {date}")






