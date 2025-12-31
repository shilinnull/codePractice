students = [
    {"name": "梁仕林", "scores": {"计算机": 100, "数学": 92, "英语": 78}},
    {"name": "李四", "scores": {"计算机": 88, "数学": 88, "英语": 95}},
    {"name": "王五", "scores": {"计算机": 43, "数学": 99, "英语": 77}}
]
print("=== 平均分>=85 ===")
excellent_students = [
    stu["name"]
    for stu in students
    if sum(stu["scores"].values()) / len(stu["scores"]) > 85
]
print(f"优秀学生{excellent_students}")
print("\n=== 每科最高分 ===")
subjects = list(students[0]["scores"].keys())
max_scores = {subj: [0, ""] for subj in subjects}
for stu in students:
    name = stu["name"]
    for subj, score in stu["scores"].items():
        if score > max_scores[subj][0]:
            max_scores[subj][0] = score
            max_scores[subj][1] = name
max_result = {k: f"{v[0]}分（{v[1]}）" for k, v in max_scores.items()}
print(f"每科最高分{max_result}")
print("\n=== 不及格的学生 ===")
fail_students = set()
for stu in students:
    name = stu["name"]
    for score in stu["scores"].values():
        if score < 60:
            fail_students.add(name)
            break
print(f"不及格{fail_students}")
print("\n=== 姓名+总分 ===")
for stu in students:
    name = stu["name"]
    total = sum(stu["scores"].values())
    info = (name, total)
    stu_name, stu_total = info
    print(f"{stu_name}：总分{stu_total}分")