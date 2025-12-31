# 综合案例： 文本数据提取与清洗工具
import re
import jieba
from collections import Counter # 用于统计词频
# 步骤1： 定义原始新闻文本（含冗余信息）
raw_news = """
【科技新闻】 2025年10月07日
Python技术峰会将于下月召开！ 本次峰会将邀请行业专家分享Python在AI领域的应用，
报名邮箱： python_summit@tech.com， 咨询电话： 13812345678、 13987654321。
会议地址： 北京市海淀区中关村科技园区（详细路线见官网） 。
温馨提示： 报名截止日期为2025年10月20日， 逾期不再受理！
"""
# 步骤2： 清洗文本（去除特殊符号、 多余空格）
print("=== 步骤1： 文本清洗 ===")
# 2.1 去除特殊符号（【】 、 （） 、 换行符）
clean_step1 = re.sub(r"【|】 |\(|\)|\\n", "", raw_news) # 替换特殊符号为空
# 2.2 去除多余空格（多个空格转为1个）
clean_step2 = re.sub(r"\s+", " ", clean_step1).strip() # \s+匹配多个空白， strip()去两端
print(f"清洗前长度： {len(raw_news)}字符")
print(f"清洗后文本： {clean_step2}")
print(f"清洗后长度： {len(clean_step2)}字符")
# 步骤3： 提取关键信息（日期、 手机号、 邮箱）
print("\n=== 步骤2： 提取关键信息 ===")
# 3.1 提取日期（YYYY年MM月DD日）
date_pattern = re.compile(r"(\d{4}年\d{2}月\d{2}日)")
dates = date_pattern.findall(clean_step2)
print(f"提取到的日期： {dates}") # 预期["2025年10月07日", "2025年10月20日"]
# 3.2 提取手机号（11位数字， 可能含分隔符）
# 先去除手机号中的非数字字符， 再匹配11位数字
phone_pattern = re.compile(r"1\d{10}") # 1开头， 后续10位数字
# 先提取所有数字序列， 再筛选11位
all_numbers = re.findall(r"\d+", clean_step2)
phones = [num for num in all_numbers if phone_pattern.match(num)]
print(f"提取到的手机号： {phones}") # 预期["13812345678", "13987654321"]
# 3.3 提取邮箱（复杂正则， 支持字母、 数字、 下划线、 点）
email_pattern = re.compile(r"\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*")
emails = email_pattern.findall(clean_step2)
# 注意： findall匹配分组时返回分组结果， 需调整正则或提取完整匹配
# 修正方案： 用search提取完整匹配， 或调整正则为非捕获分组
email_pattern_fix = re.compile(r"\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*")
emails_fix = [match.group() for match in email_pattern_fix.finditer(clean_step2)]
print(f"提取到的邮箱： {emails_fix}") # 预期["python_summit@tech.com"]
# 步骤4： 统计分析（单词数、 汉字数、 词频）
print("\n=== 步骤3： 统计分析 ===")
# 4.1 统计中文汉字数（匹配中文字符[\u4e00-\u9fa5]）
chinese_chars = re.findall(r"[\u4e00-\u9fa5]", clean_step2)
chinese_count = len(chinese_chars)
print(f"中文汉字总数： {chinese_count}")
# 4.2 统计单词数（英文单词， \b\w+\b， 排除纯数字）
words = re.findall(r"\b[a-zA-Z]+\b", clean_step2)
word_count = len(words)
print(f"英文单词总数： {word_count}， 单词列表： {words}")
# 4.3 统计中文词语词频（分词后， 排除停用词如“的、 在、 将”）
stop_words = {"的", "在", "将", "为", "于", "见", "本次", "本次", "详细", "温馨", "提示", "逾期","不再", "受理"}
# 分词
segments = jieba.lcut(clean_step2)
# 过滤停用词和非中文字符
filtered_segments = [
    seg for seg in segments
    if seg not in stop_words and re.match(r"[\u4e00-\u9fa5]+", seg) and len(seg) >= 2
] #统计词频， 取前3
word_freq = Counter(filtered_segments).most_common(3)
print(f"出现频率最高的3个中文词语： {word_freq}") # 预期如[("Python",2), ("峰会",2), ("报名",2)]
# 步骤5： 写入清洗后的文本到文件
print("\n=== 步骤4： 写入文件 ===")
with open("clean_news.txt", "w", encoding="utf-8") as f: # 指定utf-8编码， 避免中文乱码
    f.write("清洗后的新闻文本： \n")
    f.write(clean_step2)
    f.write("\n\n提取的关键信息： \n")
    f.write(f"日期： {dates}\n")
    f.write(f"手机号： {phones}\n")
    f.write(f"邮箱： {emails_fix}\n")
    f.write(f"\n统计结果： \n")
    f.write(f"中文汉字数： {chinese_count}\n")
    f.write(f"英文单词数： {word_count}\n")
    f.write(f"高频词语： {word_freq}\n")
print("文件写入完成！ 已生成clean_news.txt")