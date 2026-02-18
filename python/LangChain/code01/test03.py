from langchain.chat_models import init_chat_model

model = init_chat_model("deepseek-chat",
                        model_provider="deepseek",
                        configurable_fields="any",
                        config_prefix="first")

# print(model.invoke("你好").content + "\n")
result = model.invoke(
    input="你好",
    config={
        "configurable" :{
            "first_max_tokens": 10,
            "first_model" : "deepseek-chat",
            "first_model_provider": "deepseek"
        }
    }
)

print(result)
