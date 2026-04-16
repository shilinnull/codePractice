# 导入核心模块
from flask import Flask
from flask_sqlalchemy import SQLAlchemy
from datetime import datetime

# 实例化Flask应用
app = Flask(__name__)

# -------------------- 数据库核心配置 --------------------
# 格式: mysql+pymysql://用户名:密码@localhost:3306/数据库名?charset=utf8mb4
app.config['SQLALCHEMY_DATABASE_URI'] = 'mysql+pymysql://root:123456@172.22.108.19:3306/flask_exp5_db?charset=utf8mb4'
# 关闭数据修改追踪，减少内存占用
app.config['SQLALCHEMY_TRACK_MODIFICATIONS'] = False
# 开启调试模式，打印SQL语句（开发阶段使用）
app.config['SQLALCHEMY_ECHO'] = True

# 实例化SQLAlchemy对象，绑定Flask应用
db = SQLAlchemy(app)

class Teacher(db.Model):
    __tablename__ = 'tb_teacher'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, comment='教师ID')
    name = db.Column(db.String(20), nullable=False, comment='教师姓名')
    teach_class = db.Column(db.String(50), comment='教授班级')
    create_time = db.Column(db.DateTime, default=datetime.now, comment='创建时间')
    students = db.relationship('Student', backref='teacher', lazy='dynamic')

    def __repr__(self):
        return f'Teacher(name={self.name})'


class Student(db.Model):
    __tablename__ = 'tb_student'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, comment='学生ID')
    name = db.Column(db.String(20), nullable=False, comment='学生姓名')
    student_class = db.Column(db.String(50), comment='所属班级')
    teacher_id = db.Column(db.Integer, db.ForeignKey('tb_teacher.id'), comment='关联教师ID')
    create_time = db.Column(db.DateTime, default=datetime.now, comment='创建时间')

    def __repr__(self):
        return f'Student(name={self.name})'


class StudentDetail(db.Model):
    __tablename__ = 'tb_student_detail'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, comment='详情ID')
    phone = db.Column(db.String(11), unique=True, comment='手机号')
    address = db.Column(db.String(100), comment='家庭住址')
    student_id = db.Column(db.Integer, db.ForeignKey('tb_student.id'), unique=True, comment='关联学生ID')
    student = db.relationship('Student', backref=db.backref('detail', uselist=False))
    def __repr__(self):
        return f'StudentDetail(student={self.student.name})'


class Course(db.Model):
    __tablename__ = 'tb_course'
    id = db.Column(db.Integer, primary_key=True, autoincrement=True, comment='课程ID')
    course_name = db.Column(db.String(50), nullable=False, comment='课程名称')
    course_score = db.Column(db.Float, comment='课程学分')
    students = db.relationship('Student', secondary='tb_student_course', backref='courses')

    def __repr__(self):
        return f'Course(name={self.course_name})'


tb_student_course = db.Table(
    'tb_student_course',
    db.Column('student_id', db.Integer, db.ForeignKey('tb_student.id'), primary_key=True),
    db.Column('course_id', db.Integer, db.ForeignKey('tb_course.id'), primary_key=True),
    comment='学生-课程关联中间表'
)

@app.route('/add')
def add_data():
    teacher1 = Teacher(name='张老师', teach_class='Python Web开发1班')
    teacher2 = Teacher(name='李老师', teach_class='Python Web开发2班')
    db.session.add(teacher1)
    db.session.add(teacher2)

    student_list = [
        Student(name='张三', student_class='Python Web开发1班', teacher_id=1),
        Student(name='李四', student_class='Python Web开发1班', teacher_id=1),
        Student(name='王五', student_class='Python Web开发2班', teacher_id=2),
        Student(name='赵六', student_class='Python Web开发2班', teacher_id=2)
    ]
    db.session.add_all(student_list)
    db.session.commit()
    return '数据添加成功！已添加2位教师、4位学生'


@app.route('/query')
def query_data():
    all_teacher = Teacher.query.all()
    student_by_id = Student.query.get(1)
    class1_students = Student.query.filter_by(student_class='Python Web开发1班').all()
    zhang_teacher = Teacher.query.filter(Teacher.name.like('%张%')).all()
    order_students = Student.query.order_by(Student.id.desc()).all()
    teacher_students = Teacher.query.get(1).students.all()

    result = f"""
    <h2>查询结果演示</h2>
    <p>所有教师: {all_teacher}</p>
    <p>ID为1的学生: {student_by_id}</p>
    <p>1班的学生: {class1_students}</p>
    <p>姓张的老师: {zhang_teacher}</p>
    <p>ID倒序排列的学生: {order_students}</p>
    <p>张老师的学生: {teacher_students}</p>
    """
    return result


# 3. 更新数据
@app.route('/update')
def update_data():
    student = Student.query.get(1)
    if not student:
        return '学生不存在！'
    student.name = '张三_已修改'
    student.student_class = 'Python Web开发1班_更新'
    db.session.commit()
    return f'数据更新成功！修改后学生信息：{student}'

@app.route('/delete')
def delete_data():
    student = Student.query.get(4)
    if not student:
        return '学生不存在，删除失败'
    db.session.delete(student)
    db.session.commit()
    return f'数据删除成功！已删除学生：{student}'

if __name__ == '__main__':
    with app.app_context():
        db.create_all()
    app.run(debug=True, host="127.0.0.1", port=5000)