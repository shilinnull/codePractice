students = []
while True:
    print("\n===== 学生成绩统计系统 =====")
    print("1. 录入学生成绩")
    print("2. 统计成绩信息")
    print("3. 显示所有成绩")
    print("4. 退出系统")
    choice = input("请输入你的选择（1-4） ： ")
    if choice == "1":
        print("\n--- 录入学生成绩（输入'q'结束录入） ---")
        while True:
            name = input("请输入学生姓名（或输入'q'退出） ： ")
            if name.lower() ==  "q":
                break
        while True:
            chinese = input("请输入语文成绩（0-100） ： ")
            if chinese.isdigit():
                chinese = int(chinese)
                if 0 <= chinese <= 100:
                    break
            print("输入错误！ 成绩需为0-100的整数， 请重新输入。 ")
        while True:
            math = input("请输入数学成绩（0-100） ： ")
            if math.isdigit():
                math = int(math)
                if 0 <= math <= 100:
                    break
            print("输入错误！ 成绩需为0-100的整数， 请重新输入。 ")
        while True:
            english = input("请输入英语成绩（0-100） ： ")
            if english.isdigit():
                english = int(english)
                if 0 <= english <= 100:
                    break
            print("输入错误！ 成绩需为0-100的整数， 请重新输入。 ")
        total = chinese + math + english
        students.append({"name": name, "chinese": chinese, "math": math, "english":english, "total": total})
        print(f"{name}的成绩录入成功！ ")
    elif choice == "2":
        print("\n--- 成绩统计信息 ---")
        if len(students) == 0:
            print("暂无学生成绩数据， 请先录入成绩！ ")
            continue
        count = len(students)
        sum_chinese = sum_math = sum_english = 0
        max_total = 0
        fail_count = 0
        for stu in students:
            sum_chinese += stu["chinese"]
            sum_math += stu["math"]
            sum_english += stu["english"]
            if stu["total"] > max_total:
                max_total = stu["total"]
            if stu["chinese"] < 60 or stu["math"] < 60 or stu["english"] < 60:
                fail_count += 1
        avg_chinese = round(sum_chinese / count, 1)
        avg_math = round(sum_math / count, 1)
        avg_english = round(sum_english / count, 1)
        print(f"学生总数： {count}人")
        print(f"语文平均分： {avg_chinese}分")
        print(f"数学平均分： {avg_math}分")
        print(f"英语平均分： {avg_english}分")
        print(f"总分最高分： {max_total}分")
        print(f"不及格学生数（至少一科<60） ： {fail_count}人")
    elif choice == "3":
        print("\n--- 所有学生成绩 ---")
        if len(students) == 0:
            print("暂无学生成绩数据， 请先录入成绩！ ")
            continue
        for idx, stu in enumerate(students, start=1):
            print(f"{idx}. {stu['name']}： 语文 : {stu['chinese']}， 数学 : {stu['math']}， 英语 : {stu['english']}， 总分 : {stu['total']}")
    elif choice == "4":
        print("再见！ ")
        break
    else:
        print("输入错误！ 请选择1-4之间的数字。 ")