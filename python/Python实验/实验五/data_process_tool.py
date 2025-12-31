def calculate_stats(nums):
    """
    计算数值列表的统计信息
    参数： nums - 数值列表
    返回： 字典， 包含sum（总和） 、 avg（平均值） 、 max（最大值） 、 min（最小值）
    """
    if not nums: # 判断列表是否为空
        return {"sum": 0, "avg": 0, "max": None, "min": None}
    total = sum(nums)
    avg = round(total / len(nums), 2) # 平均值保留2位小数
    max_val = max(nums)
    min_val = min(nums)
    return {"sum": total, "avg": avg, "max": max_val, "min": min_val}
def filter_by_condition(nums, condition):
    """
    根据条件筛选列表元素
    参数： nums - 列表， condition - 筛选函数（返回bool）
    返回： 筛选后的列表
    """
    return [num for num in nums if condition(num)] # 列表推导式筛选
def map_operation(nums, operation):
    """
    对列表每个元素执行指定操作
    参数： nums - 列表， operation - 操作函数（接收一个元素， 返回处理后的值）
    返回： 处理后的列表
    """
    return [operation(num) for num in nums] # 列表推导式执行操作
def generate_sequence(n, func):
    """
    生成1-n的序列， 每个元素按func处理（生成器实现）
    参数： n - 序列最大值， func - 处理函数
    返回： 生成器对象
    """
    for i in range(1, n+1):
        yield func(i) # 惰性生成处理后的元素
if __name__ == "__main__":
    raw_data = [21, 4, 5, 89, 5, 64]
    print("===== 数据处理工具测试 =====")
    print(f"原始数据列表： {raw_data}")
    stats = calculate_stats(raw_data)
    print(f"\n1. 统计信息： ")
    print(f"总和： {stats['sum']}， 平均值： {stats['avg']}， 最大值： {stats['max']}， 最小值：{stats['min']}")
    filtered_data = filter_by_condition(raw_data, lambda x: x>10)
    print(f"\n2. 筛选大于10的元素： {filtered_data}")
    doubled_data = map_operation(raw_data, lambda x: x*2)
    print(f"\n3. 原始数据翻倍后： {doubled_data}")
    even_generator = generate_sequence(20, lambda x: x if x % 2 == 0 else None)
    even_sequence = [num for num in even_generator if num is not None]
    print(f"\n4. 1-20的偶数序列： {even_sequence}")
    avg_val = stats["avg"]
    above_avg = filter_by_condition(raw_data, lambda x: x > avg_val)
    above_avg_square = map_operation(above_avg, lambda x: x ** 2)
    square_sum = sum(above_avg_square)
    print(f"\n5. 综合应用： ")
    print(f"原始数据平均值： {avg_val}")
    print(f"大于平均值的元素： {above_avg}")
    print(f"这些元素的平方和： {square_sum}")