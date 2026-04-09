from flask import Flask, render_template

app = Flask(__name__)

@app.route("/about")
def about():
    return render_template("about.html")

@app.route("/list")
def show_list():
    return render_template("list.html",
                           score = 99,
                           book_list = ["Python基础", "Web开发"])

@app.route('/')
def index():
    # 定义要传递给模板的动态数据
    data = {
        "project_name" : "实验三",
        "flask_version" : "2.3.3",
        "student" : {
            "name" : "梁仕林",
            "class" : "web开发"
        }
    }
    return render_template("index.html", **data)

if __name__ == '__main__':
    app.run(debug=True, host='127.0.0.1', port=5000)

