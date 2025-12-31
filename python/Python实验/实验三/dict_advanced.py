student = {
    "name" : "梁仕林",
    "age" : 21,
    "major" : "计算机",
    "scores" : {"数学" : 88, "计算机" : 100, "408" : 140}
}
for key, value in student.items():
    print(f"{key} : {value}")
print(f"字典所有键：{list(student.keys())}")
print(f"字典所有值：{list(student.values())}")
print("\n=== 嵌套字典操作 ===")
math_score = student["scores"]["计算机"]
print(f"乔乾峰计算机成绩：{math_score}")
student["scores"]["408"] = 120
print(f"修改后408成绩：{student['scores']['408']}")
print("\n=== 字典推导式 ===")
subjects = ["计算机", "数学", "政治", "408"]
full_scores = [100, 80, 100, 90]
subject_full = {subj : score for subj, score in zip(subjects, full_scores)}
print(f"满分字典：{subject_full}")
full_100 = {k : v for k, v in subject_full.items() if v == 100}
print(f"满分100的科目：{full_100}")