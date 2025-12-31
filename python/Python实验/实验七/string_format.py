print("=== %运算符格式化 ===")
name = "梁仕林"
age = 21
score = 99.5
print("姓名： %s， 年龄： %d岁， 成绩： %.1f分" % (name, age, score))
print("左对齐： %-10s 右对齐： %10s" % ("Python", "Java"))
print("\n=== format()方法格式化 ===")
print("姓名： {}， 年龄： {}岁， 成绩： {:.2f}分".format(name, age, score))
print("姓名： {n}， 年龄： {a}岁， 成绩： {s:.0f}分".format(n=name, a=age, s=score))
num = 123456.789
print("千位分隔符： {:,}， 百分比： {:.2%}".format(num, 0.85))
print("\n=== f-string格式化 ===")
print(f"姓名： {name}， 年龄： {age}岁， 成绩： {score:.1f}分")
print(f"明年年龄： {age + 1}岁， 成绩等级： {'优秀' if score >= 90 else '良好'}")
from datetime import datetime
now = datetime.now()
print(f"当前时间： {now:%Y年%m月%d日 %H:%M:%S}")


print("\n=== 字符串分割与拼接 ===")
text = "Python,Java,C++,JavaScript"
languages = text.split(",")
print(f"分割结果： {languages}")
new_text = " | ".join(languages)
print(f"拼接结果： {new_text}")
print("\n=== 字符串清洗 ===")
dirty_str = " Hello Python！ \t\n"
clean_str1 = dirty_str.strip()
print(f"去除两端空白： '{clean_str1}'")
clean_str2 = clean_str1.replace("Python", "Python 3.9").replace("！ ", "!")
print(f"替换后： '{clean_str2}'")
print("\n=== 字符串查找与判断 ===")
test_str = "Python程序设计基础与应用"
pos1 = test_str.find("程序")
pos2 = test_str.find("Java")
print(f"'程序'位置： {pos1}， 'Java'位置： {pos2}")
print(f"是否以'Python'开头： {test_str.startswith('Python')}")
print(f"是否以'应用'结尾： {test_str.endswith('应用')}")
print("\n=== 中文处理 ===")
import jieba # 中文分词库
import pypinyin # 汉字转拼音库
chinese_text = "我爱Python编程"
words = jieba.lcut(chinese_text)
print(f"中文分词结果： {words}")
pinyin_list = pypinyin.lazy_pinyin(chinese_text)
pinyin_str = " ".join(pinyin_list)
print(f"汉字转拼音： {pinyin_str}")



print("\n=== 字符串编码与解码 ===")
str_utf8 = "中文编码测试"
bytes_utf8 = str_utf8.encode("utf-8")
bytes_gbk = str_utf8.encode("gbk")
print(f"UTF-8编码（bytes） ： {bytes_utf8}")
print(f"GBK编码（bytes） ： {bytes_gbk}")
decode_utf8 = bytes_utf8.decode("utf-8")
decode_gbk = bytes_gbk.decode("gbk")
print(f"UTF-8解码： {decode_utf8}")
print(f"GBK解码： {decode_gbk}")
try:
    wrong_decode = bytes_utf8.decode("gbk")
    print(f"错误解码（UTF-8→GBK） ： {wrong_decode}")
except UnicodeDecodeError as e:
    print(f"解码异常： {e}")










