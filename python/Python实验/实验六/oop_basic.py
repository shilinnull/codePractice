class Student:
    """学生类， 封装学生的基本信息与行为"""
    def __init__(self, name, age, major):
        self.name = name
        self.age = age
        self.major = major
    def introduce(self):
        """打印学生的自我介绍"""
        print(f"大家好！ 我叫{self.name}， 今年{self.age}岁， 专业是{self.major}。 ")
    def update_age(self, new_age):
        """更新学生年龄， 验证年龄合法性（15-40之间） """
        if 15 <= new_age <= 40:
            self.age = new_age
            print(f"{self.name}的年龄已更新为{new_age}岁")
        else:
            print("年龄输入无效！ 需在15-40之间")
stu1 = Student("梁仕林", 21, "计算机科学与技术")
stu1.introduce()
stu1.update_age(21)
stu1.update_age(45)
stu2 = Student("李四", 19, "软件工程")
print(f"\n李四的原始年龄： {stu2.age}")
stu2.update_age(20)
print(f"李四的更新后年龄： {stu2.age}")



class Teacher:
    school = "山西电子科技学院"
    teacher_count = 0
    def __init__(self, name, course):
        self.name = name
        self.course = course
        Teacher.teacher_count += 1
    def teach(self):
        """打印教学信息"""
        print(f"{self.name}老师在{Teacher.school}教授《{self.course}》 课程")
    @classmethod
    def get_school(cls):
        """获取学校名称（类方法， 操作类属性） """
        return f"教师所属学校： {cls.school}"
    @classmethod
    def update_school(cls, new_school):
        cls.school = new_school
        print(f"学校名称已更新为： {cls.school}")
    @staticmethod
    def calculate_salary(hours, rate):
        """计算课时费（静态方法， 与类/对象属性无关， 仅作工具） """
        return hours * rate
tea1 = Teacher("温老师", "Python程序设计")
tea2 = Teacher("李老师", "数据结构")
tea1.teach()
print(f"通过类名访问学校： {Teacher.school}")
print(f"通过对象访问学校： {tea2.school}")
print(f"教师总数量： {Teacher.teacher_count}")
print(f"\n类方法获取学校： {Teacher.get_school()}")
Teacher.update_school("山西电子科技大学")
tea2.teach()
salary1 = Teacher.calculate_salary(60, 150)
salary2 = tea1.calculate_salary(50, 180)
print(f"\n温老师课时费： {salary1}元")
print(f"李老师课时费： {salary2}元")