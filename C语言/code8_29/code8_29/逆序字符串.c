#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <string.h>
void revers(char* src, int left, int right)
{
    assert(src != NULL);
    while (left < right)
    {
        int tmp = src[left];
        src[left] = src[right];
        src[right] = tmp;
        right--;
        left++;
    }
}
int main()
{
    int arr[10000] = { 0 };
    //�������ʹ��scanf�������ո�Ͳ���ȡ�ˣ�����ʹ��gets
    while (gets(arr))
    {
        int len = strlen(arr);
        revers(arr, 0, len-1);
        printf("%s", arr);
        printf("\n");
    }
    return 0;
}
