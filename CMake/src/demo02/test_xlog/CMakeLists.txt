cmake_minimum_required(VERSION 3.18)
project(test_xlog)
include_directories("../xlog") # 添加头文件搜索路径，指向xlog目录
link_directories("../xlog/build") # 指定库查找路径
add_executable(test_xlog testxlog.cpp)
target_link_libraries(test_xlog xlog) # 指定加载库