#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int next[100];			//把next[]数组定义为全局变量
typedef struct String {
	char ch[100];
	size_t len = 0;
} String;

//找到与T->[i]相同的字符的next值
//辅助函数递归实现获取Next数字
int Get_NextNum(String* T, int j, int i) {
	if (j == 0) {
		return 0;
	}
	if (T->ch[j - 1] == T->ch[i - 1]) {
		return j;
	}
	else {
		return Get_NextNum(T, next[j], i);
	}
}

//初始化Next数组
void Get_Next(String* T) {
	next[1] = 0;
	next[2] = 1;
	int i = 3;
	for (i = 3; i <= T->len; i++) {
		next[i] = Get_NextNum(T, next[i - 1], i - 1) + 1;
	}
}

//从pos位置开始KMP模式匹配并返回成功匹配时的下标
size_t Index_KMP(String* S, int pos, String* T) {

	size_t i = pos;//注意主串从1开始
	size_t j = 1;//模式串从头开始匹配

	while (i <= S->len && j <= T->len) {
		if (j == 0 || S->ch[i - 1] == T->ch[j - 1]) {
			i++;
			j++;
		}
		else
			j = next[j];//只需要j回退即可
	}
	if (j > T->len)
		return i - T->len;
	//匹配失败
	return 0;
}


int main() 
{
	while (1) 
	{
		String T;
		printf("输入模式串：");
		scanf("%s", T.ch);
		T.len = strlen(T.ch);
		Get_Next(&T);

		String S;
		printf("输入字符串：");
		scanf("%s", S.ch);
		S.len = strlen(S.ch);
		printf("%s\n", T.ch);
		printf("%s\n", S.ch);

		size_t Index = Index_KMP(&S, 1, &T);
		printf("匹配成功的下标：%zu\n", Index);
	}

	return 0;
}