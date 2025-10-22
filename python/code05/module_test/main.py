# 主程序：导入模块A并使用
import module_a
print("运行主程序main.py")
print(f"模块A的__name__属性：{module_a.__name__}") # 输出模块名
print(f"7+2={module_a.add(7,2)}")
print(f"15-6={module_a.subtract(15,6)}")