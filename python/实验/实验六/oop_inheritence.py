# 任务4.1： 定义父类（基类）
class Person:
    """人父类， 封装共同属性与方法"""
    def __init__(self, name, age):
        self.name = name
        self.age = age
    def eat(self):
        """共同方法： 吃饭"""
        print(f"{self.name}正在吃饭")
    def sleep(self):
        """共同方法： 睡觉"""
        print(f"{self.name}正在睡觉， 年龄{self.age}岁， 建议睡8小时")
# 任务4.2： 定义子类（派生类） Student， 继承Person
class Student(Person):
    """学生子类， 继承Person， 添加特有属性与方法， 重写父类方法"""# 子类构造方法（调用父类构造方法初始化共同属性）
    def __init__(self, name, age, student_id, major):
        # 方式1： 调用父类构造方法（推荐用super()， 无需传self）
        super().__init__(name, age) # 初始化父类的name和age
        # 子类特有属性
        self.student_id = student_id # 学号
        self.major = major # 专业
    # 子类特有方法
    def study(self, course):
        """学生特有行为： 学习"""
        print(f"{self.name}（学号： {self.student_id}） 正在学习《{course}》 ")
    # 方法重写（覆盖父类的sleep方法， 添加学生特有逻辑）
    def sleep(self):
        print(f"{self.name}（学生） 正在睡觉， 年龄{self.age}岁， 建议睡7小时（需早起上课） ")
# 任务4.3： 定义子类Teacher， 继承Person
class Teacher(Person):
    """教师子类， 继承Person， 添加特有属性与方法"""
    def __init__(self, name, age, teacher_id, course):
        super().__init__(name, age)
        self.teacher_id = teacher_id # 教师编号
        self.course = course # 教授课程
    # 子类特有方法
    def teach(self):
        """教师特有行为： 教学"""
        print(f"{self.name}（教师编号： {self.teacher_id}） 正在教授《{self.course}》 ")
    # 方法重写（覆盖父类的eat方法）
    def eat(self):
        print(f"{self.name}（ 教师） 正在吃饭， 注意饮食规律（ 避免上课迟到） ")
    # 继承与方法重写测试
print("=== 继承与方法重写测试 ===")
# 创建Student对象（ 子类对象）
stu1 = Student("张三", 20, "2023001", "计算机科学")
# 调用父类继承的方法
stu1.eat() # 父类Person的eat方法
# 调用重写后的方法
stu1.sleep() # 子类Student重写的sleep方法
# 调用子类特有方法
stu1.study("Python程序设计")
# 创建Teacher对象（ 子类对象）
tea1 = Teacher("王老师", 35, "T2023001", "数据结构")
tea1.eat() # 子类Teacher重写的eat方法 # 调用重写后的方法
# 调用父类继承的方法（ 未重写）
tea1.sleep() # 父类Person的sleep方法
tea1.teach() # 调用子类特有方法
print(f"\n=== 继承关系验证 ===") # 验证继承关系（isinstance()函数）
print(f"stu1是否是Student实例： {isinstance(stu1, Student)}")
print(f"stu1是否是Person实例： {isinstance(stu1, Person)}")
print(f"tea1是否是Student实例： {isinstance(tea1, Student)}")
# 任务5： 特殊方法（ 魔术方法， 以__开头和结尾， 实现对象的特殊操作）
class Book:
    """图书类， 演示特殊方法的使用"""
    def __init__(self, title, author, price):
        """构造方法： 初始化图书属性"""
        self.title = title # 书名
        self.author = author # 作者
        self.price = price # 价格
    def __str__(self):
        """字符串方法： print()或str()时调用， 返回友好的字符串表示"""
        return f"《{self.title}》 （ 作者： {self.author}， 价格： {self.price}元） "
    def __repr__(self):
        """ repr方法： 交互式环境或repr()时调用， 返回对象的官方表示"""
        return f"Book(title='{self.title}', author='{self.author}', price={self.price})"
    def __add__(self, other):
        """加法运算符重载： 实现两个Book对象的价格相加"""
        if isinstance(other, Book):
            return self.price + other.price
        else:
            raise TypeError("只能对两个Book对象进行加法操作")

    def __len__(self):
        """长度方法： len()时调用， 返回书名的长度"""
        return len(self.title)
# 特殊方法测试
print("\n=== 特殊方法测试 ===")
# 创建Book对象
book1 = Book("Python程序设计基础与应用", "董付国", 69.0)
book2 = Book("数据结构与算法", "严蔚敏", 59.0)
# 测试__str__（print()）
print(f"print(book1)： {book1}")  # 调用__str__， 预期友好格式
# 测试__repr__（repr()）
print(f"repr(book1)： {repr(book1)}")  # 调用__repr__， 预期官方格式
# 测试__add__（+运算符）
total_price = book1 + book2  # 调用__add__， 计算价格和
print(f"两本书总价： {total_price}元")  # 预期128.0
# 测试__len__（len()）
title_length = len(book1)  # 调用__len__， 返回书名长度
print(f"book1书名长度： {title_length}个字符")




