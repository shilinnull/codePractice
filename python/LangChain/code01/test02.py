from langchain_core.messages import HumanMessage, SystemMessage
from langchain_core.output_parsers import StrOutputParser
from langchain_deepseek import ChatDeepSeek


model = ChatDeepSeek(model="deepseek-chat",
                     temperature=0,  # 采样温度
                     max_tokens=10,
                     timeout=None,
                     max_retries=2,
                     )

messages = [
    SystemMessage(content = "补全故事50字："),
    HumanMessage(content = "一只猫正在__")
]
# print(model.invoke(messages))

parser = StrOutputParser()
# 定义链
chain = model | parser
result = chain.invoke(messages)
print(result)