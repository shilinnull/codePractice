# 导入核心模块
from flask import Flask, render_template, request
from flask.views import View, MethodView
from flask_wtf import FlaskForm
from wtforms import StringField, PasswordField, SubmitField
from wtforms.validators import DataRequired, Length

app = Flask(__name__)

# 配置CSRF密钥
app.config['SECRET_KEY'] = 'FGAEWGREHSHAGDZV'


# 方法类视图：继承MethodView类
class UserView(MethodView):
    # 处理GET请求：查询用户
    def get(self):
        user_id = request.args.get('user_id', 1, type=int)
        return f'[GET请求] 查询用户ID: {user_id} 的信息'

    # 处理POST请求：新增用户
    def post(self):
        username = request.form.get('username')
        return f'[POST请求] 新增用户成功，用户名: {username}'

# 方法类视图路由注册
app.add_url_rule('/user', view_func=UserView.as_view('user_api'))

# 标准类视图：继承View类
class AboutView(View):
    # 重写dispatch_request方法，实现业务逻辑
    def dispatch_request(self):
        return '<h1>标准类视图演示</h1><p>这是通过标准类视图返回的内容</p>'

# 类视图路由注册
app.add_url_rule('/about', view_func=AboutView.as_view('about_page'))


# Flask-WTF表单注册路由
@app.route('/register', methods=['GET', 'POST'])
def register():
    # 实例化表单类
    form = RegisterForm()
    # POST请求：校验表单数据
    if form.validate_on_submit():
        # 获取校验通过的数据
        username = form.username.data
        password = form.password.data
        return render_template('register.html', form=form, msg=f'注册成功! 用户名: {username}')
    # GET请求：渲染注册页面
    return render_template('register.html', form=form)

# 定义注册表单类，继承FlaskForm
class RegisterForm(FlaskForm):
    # 用户名字段：必填，长度2-20位
    username = StringField(
        label='用户名',
        validators=[
            DataRequired(message='用户名不能为空'),
            Length(min=2, max=20, message='用户名长度2-20位')
        ]
    )
    # 密码字段：必填，长度6-20位
    password = PasswordField(
        label='密码',
        validators=[
            DataRequired(message='密码不能为空'),
            Length(min=6, max=20, message='密码长度6-20位')
        ]
    )
    # 提交按钮
    submit = SubmitField(label='立即注册')

# 原生表单登录路由，支持GET/POST双方法
@app.route('/login', methods=['GET', 'POST'])
def login():
    # POST请求: 处理表单提交
    if request.method == 'POST':
        # 获取表单数据
        username = request.form.get('username')
        password = request.form.get('password')

        # 基础校验
        if not username or not password:
            return render_template('login.html', msg='用户名和密码不能为空')

        # 模拟用户校验
        if username == 'student' and password == '123456':
            return f'登录成功! 欢迎您, {username}'
        else:
            return render_template('login.html', msg='用户名或密码错误')

    # GET请求: 渲染登录页面
    return render_template('login.html')

# 应用启动入口
if __name__ == '__main__':
    app.run(debug=True, host="127.0.0.1", port=5000)