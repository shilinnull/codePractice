from typing import Optional, List

from langchain_deepseek import ChatDeepSeek
from pydantic import BaseModel, Field

model = ChatDeepSeek(model="deepseek-chat")

class Joke(BaseModel):
    """给用户讲一个笑话"""
    setup: str = Field(description="这个笑话的开头")
    punchline: str = Field(description="这个笑话的妙语")
    rating: Optional[int] = Field(
        default=None, description="从1到10分，给这个笑话评分"
    )
structed_model = model.with_structured_output(Joke)
result = structed_model.invoke("给我讲一个关于唱歌的笑话")
print(result)

######################
# 嵌套
class Joke(BaseModel):
    """给用户讲一个笑话"""
    setup: str = Field(description="这个笑话的开头")
    punchline: str = Field(description="这个笑话的妙语")
    rating: Optional[int] = Field(
        default=None, description="从1到10分，给这个笑话评分"
    )

class Data(BaseModel):
    """获取关于笑话的数据"""
    jokes: List[Joke]

structed_model = model.with_structured_output(Data)
result = structed_model.invoke("分别给我讲一个关于唱歌和跳舞的笑话")
print(result)

