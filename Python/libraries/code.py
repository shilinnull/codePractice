# import datetime
# from datetime import datetime
import  datetime as dt

# data1 = datetime.datetime(2005, 10, 9)
# data2 = datetime.datetime(2024, 3, 12)
# print(data2 - data1)

# data1 = datetime(2005, 10, 9)
# data2 = datetime(2024, 3, 12)
# print(data2 - data1)

# data1 = dt.datetime(2005, 10, 9)
# data2 = dt.datetime(2024, 3, 12)
# print(data2 - data1)

import os

inputPath = input('请输入要搜索的路径：')
pattern = input('请输入要搜索的文件关键词：')

for dirpath, _, filenames in os.walk(inputPath):
    for f in filenames:
        if pattern in f:
            print(f'{dirpath} / {f}')


