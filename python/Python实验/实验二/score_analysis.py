scores = {
    "梁仕林": [85, 92, 88],
    "李四": [90, 88, 95],
    "王五": [76, 95, 82]
}
chinese_scores = []
total_scores = {}
for name, sub_scores in scores.items():
    total = sum(sub_scores)
    total_scores[name] = total
    chinese_scores.append(sub_scores[0])
    avg = round(total / 3, 1)
    print(f"{name}: 总分{total}, 平均分{avg}")
max_math_student = max(scores.items(), key = lambda x : x[1][1])
print(f"姓名：{max_math_student[0]}, 数学成绩：{max_math_student[1][1]}")
count_english = 0
for sub_scores in scores.values():
    if sub_scores[2] >= 80:
        count_english += 1
print(f"人数：{count_english}")
chinese_avg = round(sum(chinese_scores) / len(chinese_scores), 1)
print(f"所有学生语文平均分：{chinese_avg}")
min_total_student = min(total_scores.items(), key = lambda x : x[1])
print(f"姓名: {min_total_student[0]}, 总分: {min_total_student[1]}")