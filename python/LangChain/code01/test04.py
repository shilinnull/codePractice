from typing import Tuple, List

from typing_extensions import Annotated

from langchain_core.tools import tool, StructuredTool
from pydantic import BaseModel, Field


@tool
def multiply(a: int, b: int)->int:
    """ 乘法
    Args:
        a: 第一个参数
        b: 第二个参数
    Returns:
        两数相乘的和
    """
    return a * b

print(multiply.invoke({"a": 2, "b": 3}))
print(multiply.name)
print(multiply.description)
print(multiply.args)

########################
# pydantic
class addInput(BaseModel):
    """两数相加"""
    a: int = Field(..., description="第一个参数")
    b: int = Field(..., description="第二个参数")

@tool(args_schema=addInput)
def add(a: int, b: int)->int:
    return  a + b

print(add.invoke({"a": 1, "b": 2}))

##################################
# Annotated

@tool
def add1(
    a: Annotated[int, ..., "第一个参数"],
    b: Annotated[int, ..., "第二个参数"]
)->int:
    """两数相加"""
    return a + b
print(add1.invoke({"a": 1, "b": 2}))

####################################
# StructuredTool
def multiply1(a: int, b: int)->int:
    """ 乘法
    Args:
        a: 第一个参数
        b: 第二个参数
    Returns:
        两数相乘的和
    """
    return a * b
calculator_tool = StructuredTool.from_function(func=multiply1)
print(calculator_tool.invoke({"a": 2, "b": 3}))

####

class CalculatorInput(BaseModel):
    a: int = Field(description="第一个参数")
    b: int = Field(description="第二个参数")

def multiply2(a: int, b: int)->int:
    return a * b

calculator_tool1 = StructuredTool.from_function(
    func=multiply2,
    name="Calculator",
    description="两数相乘",
    args_schema=CalculatorInput,
)

print(calculator_tool1.invoke({"a": 1, "b": 9}))
print(calculator_tool1.name)
print(calculator_tool1.description)
print(calculator_tool1.args)

##########################################
# response_format


def multiply3(a: int, b: int)->Tuple[str, List[int]]:
    nums = [a, b]
    content = f"{nums}相乘的结果是{a + b}"
    return content, nums

calculator_tool1 = StructuredTool.from_function(
    func=multiply3,
    name="Calculator",
    description="两数相乘",
    args_schema=CalculatorInput,
    response_format="content_and_artifact"
)

print(calculator_tool1.invoke({"a": 2, "b": 3}))






