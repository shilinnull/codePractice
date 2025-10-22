# PyCharm基础测试：变量命名与缩进规范
# 1. 合法变量命名（字母/数字/下划线，首字母非数字）
student_name = "张三" # 小驼峰命名（推荐）
student_age = 20
student_major = "计算机科学"

# 2. 缩进练习（4个空格，PyCharm自动缩进）
if student_age >= 18:
    print(f"{student_name}是成年人")
    print(f"专业：{student_major}")
else:
    print(f"{student_name}是未成年人")
# 3. 调试基础（设置断点）
# 点击代码行号左侧空白处（出现红色圆点）→ 右键“Debug 'pycharm_test'”
sum_age = student_age + 5
print(f"5年后年龄：{sum_age}")