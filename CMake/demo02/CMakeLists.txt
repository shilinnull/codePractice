cmake_minimum_required(VERSION 3.20)
project(CALC)
set(CMAKE_C_STANDARD 11) # 指定标准
#set(SRC_LIST add.c;div.c;main.c;mult.c;sub.c)
include_directories(${PROJECT_SOURCE_DIR}/include)
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)

# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) # 设置可执行文件生成的路径
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib) # 设置库的生成路径

add_library(calc STATIC ${SRC_LIST}) # 静态库
# add_library(calc SHARED ${SRC_LIST}) # 动态库
add_executable(app ${SRC_LIST} ${CMAKE_CURRENT_SOURCE_DIR}/main.c)
