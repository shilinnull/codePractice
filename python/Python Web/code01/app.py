# 导入 Flask 类
from logging import DEBUG

from aiohttp.hdrs import SEC_WEBSOCKET_KEY
from flask import Flask

# 实例化 Flask 类
app = Flask(__name__)

# 设置单个配置
app.config['TESTING'] = True

# 设置多个配置
app.config.update(
    TESTING=True,
    DEBUG=True
)

# import json
# # from_file()方法：指定文件导入config.json文件中导入配置项
# app.config.from_file("config.json", load=json.load)
# # from_pyfile()方法：指定config.py文件中导入配置项
# app.config.from_pyfile("config.py")


class Settings:
    TESTING=True
    DEBUG=True

settings = Settings()
# from_object()方法：指定对象中导入配置项
app.config.from_object(settings)


# 定义视图函数，注册路由
@app.route("/")
def hello():
    return '<p>Hello World</p>'

if __name__ == "__main__":
    app.run() # 启动开发服务器
