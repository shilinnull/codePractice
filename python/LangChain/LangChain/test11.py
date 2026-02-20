from langchain_deepseek import ChatDeepSeek
from pydantic import BaseModel, Field
from langchain_core.tools import tool
from langchain_core.messages import HumanMessage

# 定义大模型
model = ChatDeepSeek(model="deepseek-chat")

# 结构化输出对象
class SearchResult(BaseModel):
    """结构化搜索结果。"""
    query: str = Field(description="搜索查询")
    findings: str = Field(description="调查结果摘要")

@tool
def web_search(query: str) -> str:
    """在网上搜索信息。
    Args:
        query: 搜索查询
    """
    return "山西今天多云转小雨，气温18-23度，东南风2级，空气质量良好"

# 第一步：使用工具获取信息
model_with_search = model.bind_tools([web_search])
messages = [
    HumanMessage("搜索当前最新的山西的天气")
]

ai_msg = model_with_search.invoke(messages)
messages.append(ai_msg)

# 执行工具调用
for tool_call in ai_msg.tool_calls:
    tool_msg = web_search.invoke(tool_call)
    messages.append(tool_msg)

# 第二步：使用基础模型（不是绑定了工具的模型）进行结构化输出
structured_model = model.with_structured_output(SearchResult)
result = structured_model.invoke(messages)

print(result)