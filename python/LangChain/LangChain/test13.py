from typing import List, Iterator

from langchain_core.output_parsers import StrOutputParser
from langchain_deepseek import ChatDeepSeek
import asyncio

model = ChatDeepSeek(model="deepseek-chat")
parser = StrOutputParser()

# async def async_stream():
#     print("=====异步调用=====")
#     async for chunk in model.astream("讲一个50字的笑话"):
#         print(chunk.content, end="|", flush=True)
#
# asyncio.run(async_stream())

def split_into_list(input: Iterator[str])-> Iterator[List[str]]:
    buffer=""
    for chunk in input:
        buffer += chunk
        while "。" in buffer:
            stop_index = buffer.index("。")
            yield [buffer[:stop_index].strip()]
            buffer = buffer[stop_index + 1 :]
    yield [buffer.strip()]

chain = model | parser | split_into_list
for chunk in chain.stream("写⼀份关于爱情的歌词，需要5句话，每句话⽤句号分割"):
    print(chunk, end="|", flush=True)

