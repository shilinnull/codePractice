# 任务3.1：for循环遍历序列（列表/字典/字符串）
print("=== for循环遍历序列 ===")
# 3.1.1 遍历列表（计算列表元素总和）
nums = [12, 25, 36, 48, 51]
total = 0
for num in nums:
    total += num
print(f"列表[{nums}]的总和：{total}") # 预期12+25+36+48+51=172
# 3.1.2 遍历字典（统计学生总分）
student_scores = {"语文": 85, "数学": 92, "英语": 78}
sum_score = 0
print("\n学生各科成绩：")
for subj, score in student_scores.items():
    print(f"{subj}：{score}分")
sum_score += score
print(f"学生总分：{sum_score}分") # 预期255
# 3.1.3 遍历字符串（统计元音字母个数）
s = "Python is a powerful programming language"
vowels = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"}
count = 0
for char in s:
    if char in vowels:
        count += 1
print(f"\n字符串'{s[:20]}...'中的元音字母个数：{count}") # 预期统计所有元音
# 任务3.2：for循环+range()生成序列（打印指定格式内容）
print("\n=== for+range()生成序列 ===")
# 3.2.1 打印1-10的平方（range(1,11)生成1-10）
print("1-10的平方：")
for x in range(1, 11):
    print(f"{x}² = {x**2}", end="\t") # 制表符分隔，一行显示
print() # 换行
# 3.2.2 打印10-1的倒序（range(10,0,-1)，步长-1）
print("10-1倒序：")
for x in range(10, 0, -1):
    print(x, end=" ") # 预期10 9 8 ... 1
print()
# 3.2.3 打印九九乘法表前5行（range(1,6)控制行数）
print("\n九九乘法表前5行：")
for i in range(1, 6): # i控制行数（1-5）
    for j in range(1, i+1): # j控制每行的列数（1-i）
        print(f"{j}×{i}={i*j}", end="\t")
    print() # 每行结束换行