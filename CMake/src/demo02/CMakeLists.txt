cmake_minimum_required(VERSION 3.20)
project(xlog)
include_directories("xlog") # 指定头文件搜索路径
add_library(xlog SHARED xlog/xlog.cpp) # 生成共享库
add_executable(test_xlog test_xlog/testxlog.cpp) # 生成可执行文件
target_link_libraries(test_xlog xlog) # 指定加载库
