# 综合案例：学生成绩筛选与统计系统
# 步骤1：定义学生列表（每个元素是字典，含姓名和成绩）
students = [
    {"name": "张三", "scores": {"语文": 85, "数学": 92, "英语": 78}},
    {"name": "李四", "scores": {"语文": 90, "数学": 88, "英语": 95}},
    {"name": "王五", "scores": {"语文": 58, "数学": 72, "英语": 65}}
]
# 步骤2：筛选平均分>85的优秀学生（列表推导式）
print("=== 优秀学生（平均分≥85） ===")
# 先计算每名学生的平均分，再筛选
excellent_students = [
    stu["name"] # 最终保留姓名
    for stu in students
    if sum(stu["scores"].values()) / len(stu["scores"]) > 85 # 平均分条件
]

print(f"优秀学生：{excellent_students}") # 预期["李四"]
# 步骤3：统计每科最高分及对应学生（字典推导式+遍历）
print("\n=== 每科最高分统计 ===")
# 初始化科目列表（从第一个学生的成绩中获取）
subjects = list(students[0]["scores"].keys())
# 初始化最高分字典（键：科目，值：[最高分, 学生姓名]）
max_scores = {subj: [0, ""] for subj in subjects}
# 遍历所有学生，更新最高分
for stu in students:
    name = stu["name"]
    for subj, score in stu["scores"].items():
        # 补充条件：如果当前成绩>已存最高分，更新
        if score > max_scores[subj][0]:
            max_scores[subj][0] = score
            max_scores[subj][1] = name

# 打印结果（字典推导式格式化输出）
max_result = {k: f"{v[0]}分（{v[1]}）" for k, v in max_scores.items()}
print(f"每科最高分：{max_result}") # 预期语文90（李四），数学92（张三），英语95（李四）
# 步骤4：找出至少有一科不及格（<60）的学生（集合）
print("\n=== 不及格学生（至少一科<60） ===")
fail_students = set() # 用集合去重（避免同一学生多次添加）
for stu in students:
    name = stu["name"]
    # 补充条件：遍历成绩，若有<60的，添加到集合
    for score in stu["scores"].values():
        if score < 60:
            fail_students.add(name)
            break # 找到一科不及格即可，跳出循环
print(f"不及格学生：{fail_students}") # 预期{"王五"}

# 步骤5：用序列解包打印姓名+总分
print("\n=== 学生姓名+总分 ===")
for stu in students:
    name = stu["name"]
    total = sum(stu["scores"].values())
    # 序列解包（将姓名和总分赋值给变量，再打印）
    info = (name, total)
    stu_name, stu_total = info
    print(f"{stu_name}：总分{stu_total}分")
