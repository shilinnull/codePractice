# 综合案例：学生成绩数据分析（新增功能）
# 步骤1：定义学生成绩字典（键：姓名，值：[语文, 数学, 英语]）
scores = {
    "张三": [85, 92, 78],
    "李四": [90, 88, 95],
    "王五": [76, 95, 82]
}

# 步骤2：计算每名学生的平均分，同时收集语文成绩与总分
print("=== 学生平均分 ===")
chinese_scores = [] # 存储所有学生的语文成绩（新增）
total_scores = {}   # 存储每名学生的总分（新增）
for name, sub_scores in scores.items():
    total = sum(sub_scores)     # 总分
    total_scores[name] = total  # 新增：保存总分
    chinese_scores.append(sub_scores[0]) # 新增：收集语文成绩
    avg = round(total / 3, 1) # 平均分 （保留1位小数）
    print(f"{name}: 总分{total}, 平均分{avg}")

# 步骤3：找出数学成绩最高的学生（数学是列表第1个元素，索引1）
#提示：max（）的key参数指定“按数学成绩排序"
max_math_student = max(scores.items(), key = lambda x : x[1][1])
print(f"\n=== 数学成绩最高 ===")
print(f"姓名：{max_math_student[0]}, 数学成绩：{max_math_student[1][1]}")

# 步骤4：统计英语成绩≥80分的人数（英语是列表第2个元素，索引2）
count_english = 0
for sub_scores in scores.values():
    if sub_scores[2] >= 80:
        count_english += 1
print(f"\n=== 英语成绩≥80分人数 ===")
print(f"人数：{count_english}")

# 步骤5：新增功能1：计算所有学生的语文平均分
chinese_avg = round(sum(chinese_scores) / len(chinese_scores), 1)
print(f"\n=== 语文成绩统计 ===")
print(f"所有学生语文平均分：{chinese_avg}")

# 步骤6：新增功能2：找出总分最低的学生
# 提示：min()的key参数指定“按总分排序”
min_total_student = min(total_scores.items(), key = lambda x : x[1])
print(f"\n=== 总分最低 ===")
print(f"姓名: {min_total_student[0]}, 总分: {min_total_student[1]}")
