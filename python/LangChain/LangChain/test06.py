from langchain_core.messages import HumanMessage
from langchain_deepseek import ChatDeepSeek
from langchain_tavily import TavilySearch

model = ChatDeepSeek(model="deepseek-chat")

tool = TavilySearch(max_retries=4)
model_with_tools = model.bind_tools([tool])

messages = [
    HumanMessage("中国山西今天的天气怎么样")
]

ai_msg = model_with_tools.invoke(messages)
messages.append(ai_msg)

for tool_call in ai_msg.tool_calls:
    tool_msg = tool.invoke(tool_call)
    messages.append(tool_msg)

result = model_with_tools.invoke(messages)
print(result.content)

