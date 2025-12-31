# 任务1.1： 定义Student类（包含实例属性、 实例方法）
class Student:
    """学生类， 封装学生的基本信息与行为"""
    # 构造方法（初始化实例属性， 创建对象时自动调用）
    def __init__(self, name, age, major):
        # 实例属性（每个对象独有的属性）
        self.name = name # 姓名
        self.age = age # 年龄
        self.major = major # 专业
    # 实例方法（访问实例属性， 需self参数）
    def introduce(self):
        """打印学生的自我介绍"""
        print(f"大家好！ 我叫{self.name}， 今年{self.age}岁， 专业是{self.major}。 ")
        # 实例方法（修改实例属性）
    def update_age(self, new_age):
        """更新学生年龄， 验证年龄合法性（15-40之间） """
        if 15 <= new_age <= 40:
            self.age = new_age
            print(f"{self.name}的年龄已更新为{new_age}岁")
        else:
            print("年龄输入无效！ 需在15-40之间")
# 任务1.2： 创建对象（实例化） 并调用方法
print("=== 类与对象实例化测试 ===")
# 创建第一个学生对象
stu1 = Student("张三", 20, "计算机科学")
# 调用实例方法
stu1.introduce()  # 预期打印自我介绍
stu1.update_age(21)  # 合法年龄， 更新
stu1.update_age(45)  # 非法年龄， 提示错误
# 创建第二个学生对象（属性独立）
stu2 = Student("李四", 19, "软件工程")
print(f"\n李四的原始年龄： {stu2.age}")  # 预期19
stu2.update_age(20)
print(f"李四的更新后年龄： {stu2.age}")  # 预期20

# 任务2.1： 类属性（所有对象共享的属性， 属于类， 而非单个对象）
class Teacher:
    # 类属性（定义在类内， 方法外）
    school = "北京大学" # 所有教师所属学校相同
    teacher_count = 0 # 统计教师数量（所有对象共享）
    # 构造方法（初始化实例属性， 同时更新类属性）
    def __init__(self, name, course):
        self.name = name # 实例属性： 姓名
        self.course = course # 实例属性： 教授课程
        Teacher.teacher_count += 1 # 每创建一个对象， 教师数量+1
    # 实例方法（访问实例属性和类属性）
    def teach(self):
        """打印教学信息"""
        print(f"{self.name}老师在{Teacher.school}教授《{self.course}》 课程")
        # 任务2.2： 类方法（用@classmethod装饰， 接收cls参数， 操作类属性）
    @classmethod
    def get_school(cls):
        """获取学校名称（类方法， 操作类属性） """
        return f"教师所属学校： {cls.school}"
    @classmethod
    def update_school(cls, new_school):
        """更新学校名称（所有对象共享修改） """
        cls.school = new_school
        print(f"学校名称已更新为： {cls.school}")

    # 任务2.3： 静态方法（用@staticmethod装饰， 无self/cls， 类似普通函数）
    @staticmethod
    def calculate_salary(hours, rate):
        """计算课时费（静态方法， 与类/对象属性无关， 仅作工具） """
        return hours * rate  # 课时费=课时数×每课时费率
# 类属性、 类方法、 静态方法测试
print("\n=== 类属性、 类方法、 静态方法测试 ===")
# 创建教师对象
tea1 = Teacher("王老师", "Python程序设计")
tea2 = Teacher("李老师", "数据结构")
# 调用实例方法（访问类属性school）
tea1.teach()  # 预期“王老师在北京大学教授《Python程序设计》 ”
# 访问类属性（类名直接访问， 或对象访问）
print(f"通过类名访问学校： {Teacher.school}")  # 预期北京大学
print(f"通过对象访问学校： {tea2.school}")  # 预期北京大学
print(f"教师总数量： {Teacher.teacher_count}")  # 预期2（两个对象）
# 调用类方法（类名调用或对象调用）
print(f"\n类方法获取学校： {Teacher.get_school()}")  # 预期北京大学
Teacher.update_school("清华大学")  # 更新类属性
tea2.teach()  # 再次调用， 学校已更新为清华大学
# 调用静态方法（类名调用或对象调用）
salary1 = Teacher.calculate_salary(40, 150)  # 40课时， 每课时150元
salary2 = tea1.calculate_salary(30, 180)  # 30课时， 每课时180元
print(f"\n王老师课时费： {salary1}元")  # 预期6000
print(f"李老师课时费： {salary2}元")  # 预期5400