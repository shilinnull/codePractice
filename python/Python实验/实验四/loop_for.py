nums = [36, 25, 55, 48, 51]
total = 0
for num in nums:
    total += num
print(f"列表[{nums}]的总和：{total}")
student_scores = {"计算机": 99, "数学": 88, "英语": 78}
sum_score = 0
print("\n学生各科成绩：")
for subj, score in student_scores.items():
    print(f"{subj}：{score}分")
sum_score += score
print(f"学生总分：{sum_score}分")

s = "Python is good"
vowels = {"a", "e", "i", "o", "u", "A", "E", "I", "O", "U"}
count = 0
for char in s:
    if char in vowels:
        count += 1
print(f"\n字符串'{s[:20]}...'中的元音字母个数：{count}")
print("\n=== for+range() ===")
print("1-10的平方：")
for x in range(1, 11):
    print(f"{x}² = {x**2}", end="\t")
print("10-1倒序：")
for x in range(10, 0, -1):
    print(x, end=" ")
print("\n九九乘法表：")
for i in range(1, 6):
    for j in range(1, i+1):
        print(f"{j}×{i}={i*j}", end="\t")
    print()