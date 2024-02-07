#define _CRT_SECURE_NO_WARNINGS 1

//
//#include<stdio.h>
//#include<assert.h>
//
//char* my_strcat(char* dest, const char* src)
//{
//	assert(dest && src);
//	char* ret = dest;
//	while (*dest != '\0')
//	{
//		dest++;
//	}
//	while (*dest++ = *src++);
//	return ret;
//}
//
//
//int main()
//{
//	char arr1[20] = "abc";
//	char arr2[] = "def";
//	my_strcat(arr1, arr2);
//	printf("%s", arr1);
//	return 0;
//}

//
//#include<stdio.h>
//#include<assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//
//int main()
//{
//	char arr1[] = "abz";
//	char arr2[] = "abc";
//	if (my_strcmp(arr1, arr2) > 0)
//		printf(">\n");
//	else
//		printf("<=\n");
//	return 0;
//}

//
//#include<stdio.h>
//#include<assert.h>
//
//int my_strcmp(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	while (*str1 == *str2)
//	{
//		if (*str1 == '\0')
//			return 0;
//		str1++;
//		str2++;
//	}
//	if (*str1 > *str2)
//		return 1;
//	else
//		return -1;
//}
//
//
//int main()
//{
//	char arr1[] = "abz";
//	char arr2[] = "abc";
//	if (my_strcmp(arr1, arr2) > 0)
//		printf(">\n");
//	else
//		printf("<=\n");
//	return 0;
//}
//

//
//#include<stdio.h>
//#include<assert.h>
//const char* my_strstr(const char* str1, const char* str2)
//{
//	assert(str1 && str2);
//	const char* s1 = str1;
//	const char* s2 = str2;
//	const char* p = str1;
//
//	while (*p)
//	{
//		s1 = p;
//		s2 = str2;
//		while (s1 != '\0' && s2 != '\0' && *s1 == *s2)
//		{
//			s1++;
//			s2++;
//		}
//		if (*s2 == '\0')
//		{
//			return p;		
//		}
//		p++;
//	}
//	return NULL;		
//}
//
//
//int main()
//{
//	char arr1[] = "abcdefghi";
//	char arr2[] = "def";
//	char* ret = my_strstr(arr1, arr2);
//	if (ret == NULL)
//		printf("找不到\n");
//	else
//		printf("%s", ret);
//	return 0;
//}
//#include<stdio.h>
//#include<ctype.h>
//int main()
//{
//	//char ch = 'Q';
//	//if (islower(ch))
//	//	printf("小写\n");
//	//else
//	//	printf("大写\n");
//
//	//int ret1 = toupper('a');
//	//int ret2 = tolower('A');
//	//printf("%c\n", ret1);
//	//printf("%c\n", ret2);
//
//	//char arr[] = "AbCekdF";
//	//char* p = arr;
//	//while (*p)
//	//{
//	//	if (isupper(*p))
//	//		*p = tolower(*p);
//	//	p++;
//	//}
//	//printf("%s", arr);
//
//	int arr1[10] = { 0 };
//	int arr2[] = { 1,2,3,4,5 };
//	memcpy(arr1, arr2,20);
//
//	return 0;
//}
//
//#include<stdio.h>
//#include<assert.h>
//void* my_memcpy(void* dest, const void* src, size_t sz)
//{
//	assert(dest && src);
//	while (sz)
//	{
//		*(char*)dest = *(char*)src;
//		dest = (char*)dest + 1;
//		src = (char*)src + 1;
//		sz--;
//	}
//}
//
//int main()
//{
//	int arr1[10] = { 0 };
//	int arr2[] = { 1,2,3,4,5 };
//	my_memcpy(arr1, arr2, 20);
//	
//	return 0;
//}

//#include<stdio.h>
//#include<assert.h>
//
//void* my_memmove(void* dest, void* src, size_t sz)
//{
//	assert(dest && src);
//	void* ret = dest;
//	if(dest < src)
//	{
//		while (sz--)
//		{
//			*(char*)dest = *(char*)src;
//			dest = (char*)dest + 1;
//			src = (char*)src + 1;
//		}
//	}
//	else
//	{
//		while (sz--)
//		{
//			*((char*)dest + sz) = *((char*)src + sz);
//		}
//	}
//	return ret;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	my_memmove(arr,arr + 2, 20);
//	for (int i = 0; i < 10; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//
//struct stu
//{
//	char name[20];
//	int age;
//	char sex[5];
//	float score;
//};

#include<stdio.h>
#include<string.h>
//int main()
//{
//	//char arr[] = "abcdef";
//	char arr[] = { 'a','b','c' };
//	int len = strlen(arr);
//	printf("len = %d\n", len);
//	return 0;
//}
//int main()
//{
//	//size_t
//	//if (strlen("abc") - strlen("abcdef") > 0)
//	//{
//	//	printf(">\n");
//	//}
//	//else
//	//{
//	//	printf("<=\n");
//	//}
//	return 0;
//}

//int main()
//{
//	char arr1[20] = { 0 };
//	char arr2[] = "abcdef";
//	strcpy(arr1, arr2);
//	printf("%s\n", arr1);
//	return 0;
//}
//int main()
//{
//	char* p = "abcdef";
//	char* str = "bit";
//	strcpy(p, str);
//	printf("%s\n", p);
//	return 0;
//}
#include<assert.h>
char* my_strcpy(char* dest,const char* src)
{
	assert(dest && src);
	//while (*dest++ = *src++)
	while (*src++ = *dest++)
	{
		;
	}
}

int main()
{
	char str1[10] = "xxxxxxxxx";
	char str2[] = "hello";

	my_strcpy(str1, str2);

	printf("%s\n", str1);
	return 0;
}
