print("=== 文本文件写入 ===")
try:
    f1 = open("test_write.txt", "w", encoding="utf-8")
    f1.write("第一行：Python文件操作\n")
    f1.write("第二行：文本文件写入测试\n")
    lines = ["第三行：writelines测试1\n","第四行：writelines测试2\n"]
    f1.writelines(lines)
    print("文件写入完成（手动关闭模式）")
finally:
    f1.close()
with open("test_write.txt", "a", encoding="utf-8") as f2:
    f2.write("第五行：追加模式写入\n")
    f2.write("第六行：with语句自动关闭文件\n")
print("文件追加完成（with语句模式）")

print("\n=== 文本文件读取 ===")
with open("test_write.txt", "r", encoding="utf-8") as f3:
    all_content = f3.read()
    print("=== read()读取全部内容 ===")
    print(all_content)

with open("test_write.txt", "r", encoding="utf-8") as f4:
    print("=== readline()逐行读取 ===")
    line1 = f4.readline()
    line2 = f4.readline()
    print(f"第一行: {line1.strip()}")
    print(f"第二行: {line2.strip()}")

with open("test_write.txt", "r", encoding="utf-8") as f5:
    lines = f5.readlines()
    print("\n=== readlines()读取所有行 ===")
    for idx, line in enumerate(lines, start=1):
        print(f"第{idx}行: {line.strip()}")

print("\n=== r+模式读写文件 ===")
with open("test_plus.txt", "w", encoding="utf-8") as f:
    f.write("Hello world!")
with open("test_plus.txt", "r+", encoding="utf-8") as f6:
    content = f6.read()
    print(f"初始内容: {content}")
    f6.write(" Python!")
    f6.seek(0)
    new_content = f6.read()
    print(f"追加后内容: {new_content}")