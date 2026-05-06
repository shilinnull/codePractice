cmake_minimum_required(VERSION 3.20)
project(CALC)
set(CMAKE_CXX_STANDARD 11) # 指定标准
#set(SRC_LIST add.c;div.c;main.c;mult.c;sub.c)
include_directories(${PROJECT_SOURCE_DIR}/include)
#aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR}/src SRC_LIST)
file(GLOB SRC_LIST ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c)
add_executable(app ${SRC_LIST})
