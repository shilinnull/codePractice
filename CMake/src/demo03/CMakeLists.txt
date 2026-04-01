cmake_minimum_required(VERSION 3.10)

project(message)

# 测试message
message("参数一")

# 使用#[[]]进行注释
#[[
message("参数二")
]]

message(arg1 arg2 arg3)

message([<mode>] "message text" ...)

# --log-level=<ERROR|WARNING|NOTICE|STATUS|VERBOSE|DEBUG|TRACE>


# 生成到此终止
# cmake -S . -B b --log-level ERROR

# 这些消息会根据不同的日志级别显示
# message(FATAL_ERROR "运行终止 生成终止 FATAL_ERROR")
message(SEND_ERROR "继续运行生成终止 SEND_ERROR")  
message(WARNING "WARNING 显示行号")
message(STATUS "STATUS 显示--")
message(VERBOSE "VERBOSE 默认不显--")
message(DEBUG "DEBUG 默认不显--")
message(TRACE "TRACE 默认不显--")

# 日志级别优先级: FATAL_ERROR > SEND_ERROR > WARNING > STATUS > VERBOSE > DEBUG > TRACE

# --------------------------------------------------------------

# 显示当前消息缩进
message("CMAKE_MESSAGE_INDENT = " ${CMAKE_MESSAGE_INDENT})

# 设置消息缩进为 " ## "
set(CMAKE_MESSAGE_INDENT " ## ")

# 开始检查 xcpp
message(CHECK_START "Finding xcpp")
unset(miss)

# 检查 xlog (假设找到)
message(CHECK_START "Finding xlog")
# ... 执行检查，假设找到了 xlog
message(CHECK_PASS "found")

# 检查 xthread (假设未找到)
message(CHECK_START "Finding xthread")
# ... 执行检查，假设未找到 xthread
set(miss ${miss}[xthread])
message(CHECK_FAIL "not found")

# 检查 xsocket (假设未找到)
message(CHECK_START "Finding xsocket")
# ... 执行检查，假设未找到 xsocket
set(miss ${miss}[xsocket])
message(CHECK_FAIL "not found")

# 恢复缩进
set(CMAKE_MESSAGE_INDENT "")

# 最终检查结果
if(miss)
    message(CHECK_FAIL "丢失组件: ${miss}")
else()
    message(CHECK_PASS "all components found")
endif()

