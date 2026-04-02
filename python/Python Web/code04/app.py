from flask import Flask, request, redirect, url_for
app=Flask(__name__)
# 1. 根路径
@app.route('/')
def index():
    return '<h1>实验⼆ Flask路由与请求响应处理</h1><p>项⽬环境运⾏正常！</p>'
# 2. 同⼀个视图函数绑定
@app.route('/home')
@app.route('/index')
def home():
    return '⾸⻚：⽀持 /home 和 /index 两个路径访问'

# 3. 带参数
@app.route('/user/<int:user_id>')
def user_info(user_id):
    return f'⽤⼾ID：{user_id} 的个⼈主⻚'

# 4. ⽀持GET和POST双⽅法
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'GET':
        return '【GET请求】请输⼊账号密码完成登录'
    elif request.method == 'POST':
        return '【POST请求】登录请求已接收处理'


# 5. 获取GET请求的URL查询参数
@app.route('/search')
def search():
    keyword = request.args.get('keyword', '⽆搜索关键词')
    page = request.args.get('page', 1, type=int)
    return f'搜索关键词：{keyword} | 当前⻚码：{page}'
# 6. 获取POST请求的表单数据
@app.route('/form', methods=['POST'])
def form_handle():
    username = request.form.get('username')
    password = request.form.get('password')
    if not username or not password:
        return '⽤⼾名和密码不能为空', 400
    return f'表单提交成功！⽤⼾名：{username}'
# 7. 重定向响应
@app.route('/redirect')
def redirect_test():
    # 通过视图函数名⽣成URL，重定向到根路径
    return redirect(url_for('index'))

# 8. ⾃定义404错误⻚⾯
@app.errorhandler(404)
def page_not_found(e):
    return '您访问的⻚⾯不存在，请检查URL地址是否正确', 404

if __name__ == '__main__':
    app.run(debug=True, host='127.0.0.1', port=5000)