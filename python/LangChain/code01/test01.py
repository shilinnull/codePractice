from langchain_core.messages import HumanMessage, SystemMessage
from langchain_core.output_parsers import StrOutputParser
from langchain_deepseek import ChatDeepSeek


model = ChatDeepSeek(model="deepseek-chat")

messages = [
    SystemMessage(content = "翻译下面句子，从英文翻译成中文"),
    HumanMessage(content = "hello")
]

parser = StrOutputParser()
# 定义链
chain = model | parser
result = chain.invoke(messages)
print(result)