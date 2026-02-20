from langchain_deepseek import ChatDeepSeek
from pydantic import BaseModel, Field
from typing import Optional, Union

# 定义大模型
model = ChatDeepSeek(model="deepseek-chat")

class Joke(BaseModel):
    """给用户讲一个笑话。"""
    setup: str = Field(description="这个笑话的开头")
    punchline: str = Field(description="这个笑话的妙语")
    rating: Optional[int] = Field(
        default=None, description="从1到10分，给这个笑话评分"
    )

class ConversationalResponse(BaseModel):
    """以对话的方式回应。待人友善，乐于助人。"""
    response: str = Field(description="对用户查询的会话响应")

class FinalResponse(BaseModel):
    final_output: Union[Joke, ConversationalResponse]

structured_model = model.with_structured_output(FinalResponse)
result = structured_model.invoke("给我讲一个关于唱歌的笑话")
print(result)
result = structured_model.invoke("你好")
print(result)