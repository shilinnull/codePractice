BIN=process               # 定义变量    
CC=gcc
SRC=$(wildcard *.c)       # 使用 wildcard 函数，获取当前所有.c文件名    
OBJ=$(SRC:.c=.o)          # 将SRC的所有同名.c 替换成为.o形成目标文件列表    
LFLAGS=-o                 # 链接选项
CFLAGS=-c                 # 编译选项
RM=rm -f                  # 引入命令
STD=-std=c11

$(BIN):$(OBJ)
	@$(CC) $(LFLAGS) $@ $^ $(STD)   # $@:代表目标文件名 $^:代表依赖文件列表
	@echo "链接$^ 成为 $@"
%.o:%.c                             # %.c 展开当前目录下所有的.c  %.o:同时展开同名.o     
	@$(CC) $(CFLAGS) $< $(STD)      # %<:对展开的依赖.c文件,一个一个的交给gcc    
	@echo "编译$< 成为 $@"          # @:不回显命令

.PHONY:clean
clean: 
	@$(RM) $(OBJ) $(BIN) 
	@echo "清理工程完毕"


