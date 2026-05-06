cmake_minimum_required(VERSION 3.20)
project(CALC)
include_directories(${PROJECT_SOURCE_DIR}/include) # 需要包含的头文件
link_directories(${PROJECT_SOURCE_DIR}/lib) # 要链接库的目录
link_libraries(calc) # 要链接库的名字
add_executable(app main.c)