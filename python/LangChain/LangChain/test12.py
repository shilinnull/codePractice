from langchain_deepseek import ChatDeepSeek

model = ChatDeepSeek(model="deepseek-chat")

chunks = []
for chunk in model.stream("讲一个50字的笑话"):
    chunks.append(chunk)
    print(chunk.content, end="|", flush=True)

print()
print(chunks[0] + chunks[1] + chunks[2] + chunks[3] + chunks[4])
