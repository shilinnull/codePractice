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
class Student(Person):
    """学生子类， 继承Person， 添加特有属性与方法， 重写父类方法"""
    def __init__(self, name, age, student_id, major):
        super().__init__(name, age)
        self.student_id = student_id
        self.major = major
    def study(self, course):
        """学生特有行为： 学习"""
        print(f"{self.name}（学号： {self.student_id}） 正在学习《{course}》 ")
    def sleep(self):
        print(f"{self.name}（学生） 正在睡觉， 年龄{self.age}岁， 建议睡7小时（需早起上课） ")
class Teacher(Person):
    """教师子类， 继承Person， 添加特有属性与方法"""
    def __init__(self, name, age, teacher_id, course):
        super().__init__(name, age)
        self.teacher_id = teacher_id
        self.course = course
    def teach(self):
        """教师特有行为： 教学"""
        print(f"{self.name}（教师编号： {self.teacher_id}） 正在教授《{self.course}》 ")
    def eat(self):
        print(f"{self.name}（教师） 正在吃饭， 注意饮食规律（ 避免上课迟到） ")
stu1 = Student("梁仕林", 20, "2025029", "计算机科学与技术")
stu1.eat()
stu1.sleep()
stu1.study("Python程序设计")
tea1 = Teacher("温老师", 40, "T2025001", "数据结构")
tea1.eat()
tea1.sleep()
tea1.teach()
print(f"\n=== 继承关系验证 ===")
print(f"stu1是否是Student实例： {isinstance(stu1, Student)}")
print(f"stu1是否是Person实例： {isinstance(stu1, Person)}")
print(f"tea1是否是Student实例： {isinstance(tea1, Student)}")





class Book:
    """图书类， 演示特殊方法的使用"""
    def __init__(self, title, author, price):
        """构造方法： 初始化图书属性"""
        self.title = title
        self.author = author
        self.price = price
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
book1 = Book("Python程序设计基础与应用", "董付国", 69.0)
book2 = Book("数据结构与算法", "严蔚敏", 59.0)
print(f"print(book1)： {book1}")
print(f"repr(book1)： {repr(book1)}")
total_price = book1 + book2
print(f"两本书总价： {total_price}元")
title_length = len(book1)
print(f"book1书名长度： {title_length}个字符")




