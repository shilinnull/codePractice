print("=== try-except捕获指定异常 ===")
file_path = "nonexistent.txt"
try:
    with open(file_path, "r", encoding="utf-8") as f:
        content = f.read()
        print(f"文件内容: {content}")
except FileNotFoundError as e:
    print(f"错误: 文件'{file_path}'不存在 - {e}")
except UnicodeDecodeError as e:
    print(f"错误: 文件编码错误 - {e}")

print("\n=== try-except-else ===")
def divide(a, b):
    try:
        result = a / b
    except ZeroDivisionError as e:
        print(f"除法错误: {e}")
        return None
    else:
        print(f"除法成功: {a} / {b} = {result}")
        return result

divide(10, 2)
divide(10, 0)

print("\n=== try-except-finally ===")
def read_file_safe(file_path):
    f = None
    try:
        f = open(file_path, "r", encoding="utf-8")
        return f.read()
    except FileNotFoundError as e:
        print(f"错误: {e}")
        return None
    finally:
        if f:
            f.close()
            print("文件已手动关闭")

content1 = read_file_safe("test_write.txt")
content2 = read_file_safe("nonexistent.txt")

print("\n=== assert断言语句 ===")
def check_age(age):
    assert 15 <= age <= 40, f"年龄无效: {age} (需在15-40之间)"
    print(f"年龄验证通过: {age}岁")

check_age(20)
try:
    check_age(10)
except AssertionError as e:
    print(f"断言失败: {e}")