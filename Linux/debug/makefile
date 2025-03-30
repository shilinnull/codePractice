BIN=a.out                 # 定义变量
CC=gcc       
SRC=$(wildcard *.c)       # 或者使⽤ wildcard 函数，获取当前所有.c⽂件名
OBJ=$(SRC:.c=.o)          # 将SRC的所有同名.c 替换 成为.o 形成⽬标⽂件列表
LFLAGS=-o                 # 链接选项
CFLAGS=-c                 # 编译选项
RM=rm -f                  # 引命令
STD=-std=c11
$(BIN):$(OBJ)    
	@$(CC) $(LFLAGS) $@ $^ $(STD) 
	@echo "链接$^ 成为 $@"    
%.o:%.c                    # %.c 展开当前⽬录下所有的.c。 %.o: 同时展开同 名.o 
	@$(CC) $(CFLAGS) $< $(STD)   # %<: 对展开的依赖.c⽂件，⼀个⼀个的交给gcc
	@echo "编译$< 成为 $@"  # @：不回显命令

.PHONY:clean                
clean:
	@$(RM) $(OBJ) $(BIN)
	@echo "清理工程完毕"
