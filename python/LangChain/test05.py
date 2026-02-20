from langchain_core.messages import HumanMessage
from langchain_core.tools import tool
from langchain_deepseek import ChatDeepSeek
from langchain_openai import ChatOpenAI
from typing_extensions import Annotated

@tool
def add(
        a : Annotated[int, ..., "第一个整数"],
        b : Annotated[int, ..., "第二个整数"],
) -> int:
    """两数相加"""
    return a + b

@tool
def multiply(
        a : Annotated[int, ..., "第一个整数"],
        b : Annotated[int, ..., "第二个整数"],
) -> int:
    """两数相乘"""
    return a * b

model = ChatDeepSeek(model="deepseek-chat")

# 绑定工具
tools = [add, multiply]
# model_with_tools = model.bind_tools(tools=tools)
# 强制选择工具
model_with_tools = model.bind_tools(tools=tools)

# 调用工具
print(model_with_tools.invoke("2乘3等于多少？"))
print(model_with_tools.invoke("你是谁？"))

# 定义消息列表，添加要传递给聊天模型的消息
message = [
    HumanMessage("2乘3等于多少？6加6等于多少？")
]
ai_msg = model_with_tools.invoke(message)

message.append(ai_msg)

# 构造ToolMessage, 并添加到消息列表中去
for tool_call in ai_msg.tool_calls:
    selected_tool = {"add": add, "multiply": multiply}[tool_call["name"].lower()]
    tool_msg = selected_tool.invoke(tool_call)
    message.append(tool_msg)

print(message)
print(model_with_tools.invoke(message).content)


tool_result = multiply.invoke(ai_msg.tool_calls[0])
print(tool_result)