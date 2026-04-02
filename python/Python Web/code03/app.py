# import flask
# print(flask.__version__)

# from flask import Flask
# app = Flask(__name__)
# app.config["DEBUG"] = True
# app.config['SECRET_KEY'] = b'_5#y2L"F4Q8z\n\xec]/'
# @app.route('/')
# def hello_world():
#     return 'Hello World! Debug模式开启'
# if __name__ == '__main__':
#     app.run()

# from flask import Flask
# app = Flask(__name__)
# app.config.from_pyfile('config.py')
# @app.route('/')
# def hello_world():
#     return 'Hello World! 配置文件生效'
# if __name__ == '__main__':
#     app.run(port=app.config['PORT'])

# from flask import Flask
# app = Flask(__name__)
# class DevConfig:
#     DEBUG = True
#     SECRET_KEY = 'development key'
#     TESTING = False
# app.config.from_object(DevConfig)
# @app.route('/')
# def hello_world():
#     return 'Hello World! 配置类生效'
# if __name__ == '__main__':
#     app.run()

from flask import Flask
from flask_sqlalchemy import SQLAlchemy
app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///mydatabase.db'
db = SQLAlchemy(app)

@app.route('/')
def hello_world():
    return 'Flask扩展包初始化成功'
if __name__ == '__main__':
    app.run(debug=True)