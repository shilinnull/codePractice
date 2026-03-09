# 导入 Flask 类
from logging import DEBUG

from aiohttp.hdrs import SEC_WEBSOCKET_KEY
from flask import Flask
from langchain_core.indexing import index

# 实例化 Flask 类
app = Flask(__name__)

# 定义视图函数，注册路由
# @app.route("/index")
# def index():
#     return '<p>Hello World</p>'

def index():
    return '<p>Hello World</p>'

app.add_url_rule(rule="/index", view_func=index)

# @app.route('/<page>')
# def page_num(page):
#     return f'当前为{page}页'

@app.route('/<int:page>')
def page_num(page):
    return f'当前为{page}页'

if __name__ == "__main__":
    app.run() # 启动开发服务器
