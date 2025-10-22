# 模块A：定义函数与测试代码
def add(a, b):
    """计算两数之和"""
    return a + b
def subtract(a, b):
    """计算两数之差"""
    return a - b
# 模块内部测试代码（仅直接运行时执行）
if __name__ == "__main__":
    print("直接运行模块A")
print(f"3+5={add(3,5)}")
print(f"10-4={subtract(10,4)}")