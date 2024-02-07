#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
//
//find(int arr[], int sz)
//{
//	int ret = 0;
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		ret ^= arr[i];
//	}
//	return ret;
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = find(arr, sz);
//	printf("%d\n", ret);
//
//	return 0;
//}


//
//void find2(int arr[], int sz)
//{
//
//}
//
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,1,2,3,4 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int ret = find2(arr, sz);
//	printf("%d\n", ret);
//
//	return 0;
//}

//atoi
#include<stdio.h>
#include<assert.h>
#include<ctype.h>
#include<stdlib.h>
enum State
{
	VALID,
	INVALID
}sta = INVALID;

int my_atoi(const char* str){
	assert(str);
	if (*str == '\0')
		return 0;
	//跳过空白字符
	while (isspace(*str)){
		str++;
	}
	//判断正负号
	int flag = 1;
	if (*str == '+'){
		flag = 1;
		str++;
	}
	else if (*str == '-'){
		flag = -1;
		str++;
	}
	long long r = 0;
	while (*str) {
		if (isdigit(*str)) {
			r = r * 10 + *str - '0';
			if (r > INT_MAX || r < INT_MIN)
				if(flag ==1)
					return INT_MAX;
				else
					return INT_MIN;
			str++;
		}
		else{
			return (int)r;
		}
	}
	sta = VALID;
	return (int)r;
}

int main()
{
	char arr[] = "1234";
	int ret = my_atoi(arr);
	if (sta == VALID)
		printf("合法的转换%d\n", ret);
	else
		printf("非法的转换%d\n", ret);
	return 0;
}
