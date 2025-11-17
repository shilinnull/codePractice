# 任务3.1：字典常用方法(items()/keys()/values())
student = {
    "name" : "张三",
    "age" : 20,
    "major" : "计算机",
    "scores" : {"语文" : 85, "数学" : 92, "英语" : 78} # 嵌套字典
}

print("=== 字典常用方法 ===")
# 遍历字典的键-值对（items()）
print("学生信息（键-值对）：")
for key, value in student.items():
    print(f"{key} : {value}")
# 遍历字典的键(keys())与值(values())
print(f"字典所有键：{list(student.keys())}")  # 转换为列表便于查看
print(f"字典所有值：{list(student.values())}")
# 任务3.2：嵌套字典的访问与修改
print("\n=== 嵌套字典操作 ===")
# 访问嵌套字典的数学成绩
math_score = student["scores"]["数学"]
print(f"张三数学成绩：{math_score}") # 预期92
# 修改嵌套字典的英语成绩（从78改为88）
student["scores"]["英语"] = 88
print(f"修改后英语成绩：{student['scores']['英语']}") # 预期88
# 任务3.3：字典推导式（生成键值对）
print("\n=== 字典推导式 ===")
# 3.3.1 从两个列表生成字典（键：科目，值：满分100）
subjects = ["语文", "数学", "英语", "物理"]
full_scores = [100, 100, 100, 90]
subject_full = {subj : score for subj, score in zip(subjects, full_scores)}
print(f"科目-满分字典：{subject_full}") # 预期{"语文":100, ..., "物理":90}
# 3.3.2 筛选字典（保留满分100的科目）
full_100 = {k : v for k, v in subject_full.items() if v == 100}
print(f"满分100的科目：{full_100}") # 预期{"语文":100, "数学":100, "英语":100}