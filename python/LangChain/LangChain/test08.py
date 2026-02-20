from typing import TypedDict, Annotated

from langchain_deepseek import ChatDeepSeek

model = ChatDeepSeek(model="deepseek-chat")

class Joke(TypedDict):
    """给用户讲一个笑话"""
    setup: Annotated[str, ..., "这个笑话的开头"]
    punchline: Annotated[str, ..., "这个笑话的妙语"]
    rating: Annotated[str, None, "从1到10分，给这个笑话评分"]
structred_model = model.with_structured_output(Joke, include_raw=True)
result = structred_model.invoke("给我讲一个关于唱歌的笑话")
print(result)
###################################
#
json_schema = {
    "title": "joke",
    "description": "给用户讲一个笑话。",
    "type": "object",
    "properties": {
        "setup": {
            "type": "string",
            "description": "这个笑话的开头"
        },
        "punchline": {
            "type": "string",
            "description": "这个笑话的妙语"
        },
        "rating": {
            "type": "integer",
            "description": "从1到10分，给这个笑话评分",
            "default": None
        }
    },
    "required": ["setup", "punchline"]
}

structred_model = model.with_structured_output(json_schema)
result = structred_model.invoke("给我讲一个关于唱歌的笑话")
print(result)

