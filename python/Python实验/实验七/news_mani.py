import re
import jieba
from collections import Counter
raw_news = """
【科技新闻】 2025年10月07日
Python技术峰会将于下月召开！ 本次峰会将邀请行业专家分享Python在AI领域的应用，
报名邮箱： python_summit@tech.com， 咨询电话： 13812345678、 13987654321。
会议地址： 北京市海淀区中关村科技园区（详细路线见官网） 。
温馨提示： 报名截止日期为2025年10月20日， 逾期不再受理！
"""
print("=== 步骤1： 文本清洗 ===")
clean_step1 = re.sub(r"【|】 |\(|\)|\\n", "", raw_news)
clean_step2 = re.sub(r"\s+", " ", clean_step1).strip()
print(f"清洗前长度： {len(raw_news)}字符")
print(f"清洗后文本： {clean_step2}")
print(f"清洗后长度： {len(clean_step2)}字符")
print("\n=== 步骤2： 提取关键信息 ===")
date_pattern = re.compile(r"(\d{4}年\d{2}月\d{2}日)")
dates = date_pattern.findall(clean_step2)
print(f"提取到的日期： {dates}")
phone_pattern = re.compile(r"1\d{10}")
all_numbers = re.findall(r"\d+", clean_step2)
phones = [num for num in all_numbers if phone_pattern.match(num)]
print(f"提取到的手机号： {phones}")
email_pattern = re.compile(r"\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*")
emails = email_pattern.findall(clean_step2)
email_pattern_fix = re.compile(r"\w+([-+.]\w+)*@\w+([-.]\w+)*\.\w+([-.]\w+)*")
emails_fix = [match.group() for match in email_pattern_fix.finditer(clean_step2)]
print(f"提取到的邮箱： {emails_fix}")
print("\n=== 步骤3： 统计分析 ===")
chinese_chars = re.findall(r"[\u4e00-\u9fa5]", clean_step2)
chinese_count = len(chinese_chars)
print(f"中文汉字总数： {chinese_count}")
words = re.findall(r"\b[a-zA-Z]+\b", clean_step2)
word_count = len(words)
print(f"英文单词总数： {word_count}， 单词列表： {words}")
stop_words = {"的", "在", "将", "为", "于", "见", "本次", "本次", "详细", "温馨", "提示", "逾期","不再", "受理"}
segments = jieba.lcut(clean_step2)
filtered_segments = [
    seg for seg in segments
    if seg not in stop_words and re.match(r"[\u4e00-\u9fa5]+", seg) and len(seg) >= 2
]
word_freq = Counter(filtered_segments).most_common(3)
print(f"出现频率最高的3个中文词语： {word_freq}")
print("\n=== 步骤4： 写入文件 ===")
with open("clean_news.txt", "w", encoding="utf-8") as f:
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