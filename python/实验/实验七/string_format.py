# 任务1.1： %运算符格式化（适合简单场景）
print("=== %运算符格式化 ===")
name = "张三"
age = 20
score = 89.5
print("姓名： %s， 年龄： %d岁， 成绩： %.1f分" % (name, age, score))
print("左对齐： %-10s 右对齐： %10s" % ("Python", "Java"))
# 任务1.2： format()方法格式化（支持位置参数、 关键字参数、 复杂格式）
print("\n=== format()方法格式化 ===")
print("姓名： {}， 年龄： {}岁， 成绩： {:.2f}分".format(name, age, score)) # .2f保留2位小数
print("姓名： {n}， 年龄： {a}岁， 成绩： {s:.0f}分".format(n=name, a=age, s=score)) # .0f取整
num = 123456.789
print("千位分隔符： {:,}， 百分比： {:.2%}".format(num, 0.85)) # 预期123,456.789和85.00%
# 任务1.3： f-string格式化（Python 3.6+， 简洁高效）
print("\n=== f-string格式化 ===")
print(f"姓名： {name}， 年龄： {age}岁， 成绩： {score:.1f}分")
print(f"明年年龄： {age + 1}岁， 成绩等级： {'优秀' if score >= 90 else '良好'}")
from datetime import datetime
now = datetime.now()
print(f"当前时间： {now:%Y年%m月%d日 %H:%M:%S}")
# 任务2.1： 字符串分割与拼接（split()/join()）
print("\n=== 字符串分割与拼接 ===")
# split()： 按指定字符分割， 返回列表（默认按空格分割）
text = "Python,Java,C++,JavaScript"
languages = text.split(",") # 按逗号分割
print(f"分割结果： {languages}") # 预期["Python","Java","C++","JavaScript"]
# join()： 用指定字符拼接列表为字符串
new_text = " | ".join(languages) # 用" | "拼接
print(f"拼接结果： {new_text}") # 预期"Python | Java | C++ | JavaScript"
# 任务2.2： 字符串清洗（strip()/replace()）
print("\n=== 字符串清洗 ===")
dirty_str = " Hello Python！ \t\n" # 含空格、 制表符、 换行符
clean_str1 = dirty_str.strip()
print(f"去除两端空白： '{clean_str1}'") # 预期"'Hello Python！ '"
clean_str2 = clean_str1.replace("Python", "Python 3.9").replace("！ ", "!")
print(f"替换后： '{clean_str2}'") # 预期"'Hello Python 3.9!'"
# 任务2.3： 字符串查找与判断（find()/startswith()）
print("\n=== 字符串查找与判断 ===")
test_str = "Python程序设计基础与应用"
pos1 = test_str.find("程序")
pos2 = test_str.find("Java")
print(f"'程序'位置： {pos1}， 'Java'位置： {pos2}")
print(f"是否以'Python'开头： {test_str.startswith('Python')}") # 预期True
print(f"是否以'应用'结尾： {test_str.endswith('应用')}") # 预期True
# 任务2.4： 中文处理（分词、 拼音转换， 需安装第三方库）
print("\n=== 中文处理 ===")
# 安装库： 命令行执行pip install pypinyin jieba
import jieba # 中文分词库
import pypinyin # 汉字转拼音库
# 中文分词
chinese_text = "我爱Python编程"
words = jieba.lcut(chinese_text) # 精确分词
print(f"中文分词结果： {words}") # 预期["我","爱","Python","编程"]
# 汉字转拼音（without tone无音调）
pinyin_list = pypinyin.lazy_pinyin(chinese_text)
pinyin_str = " ".join(pinyin_list)
print(f"汉字转拼音： {pinyin_str}") # 预期"wo ai Python bian cheng"

# 任务3： 字符串编码与解码（解决中文乱码）
print("\n=== 字符串编码与解码 ===")
# 编码： str → bytes（默认UTF-8， 可指定GBK）
str_utf8 = "中文编码测试"
bytes_utf8 = str_utf8.encode("utf-8") # UTF-8编码
bytes_gbk = str_utf8.encode("gbk") # GBK编码
print(f"UTF-8编码（bytes） ： {bytes_utf8}") # 长度12（UTF-8每个中文3字节）
print(f"GBK编码（bytes） ： {bytes_gbk}") # 长度8（GBK每个中文2字节）
# 解码： bytes → str（需与编码格式一致， 否则乱码）
decode_utf8 = bytes_utf8.decode("utf-8") # 正确解码
decode_gbk = bytes_gbk.decode("gbk") # 正确解码
print(f"UTF-8解码： {decode_utf8}")
print(f"GBK解码： {decode_gbk}")
# 错误演示： 编码与解码格式不一致（会乱码或抛异常）
try:
    wrong_decode = bytes_utf8.decode("gbk") # UTF-8编码用GBK解码
    print(f"错误解码（UTF-8→GBK） ： {wrong_decode}") # 预期乱码
except UnicodeDecodeError as e:
    print(f"解码异常： {e}")