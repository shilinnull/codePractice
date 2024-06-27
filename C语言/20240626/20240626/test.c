#include <stdio.h>
#include <assert.h>


// 1,2,3,4,5,6,7,8,9,10
void* my_memmove(void* dest,const void* src, size_t num)
{
	assert(dest && src);
	void* ret = dest;
	if (dest < src)
	{
		// 从前向后拷贝
		while (num--)
		{
			*((char*)dest) = *((char*)src);
			((char*)dest)++;
			((char*)src)++;
		}
	}
	else
	{
		// 从后向前拷贝
		while (num--)
		{
			// 19
			*((char*)dest + num) = *((char*)src + num);
		}
	}
	return ret;
}

int main()
{
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };

	my_memmove(arr1 + 2, arr1, 20);
	for (int i = 0; i < 10; ++i)
	{
		printf("%d ", arr1[i]);
	}


	//int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	//int arr2[10] = { 0 };

	//my_memcpy(arr2, arr1, 17);
	//for (int i = 0; i < 10; ++i)
	//{
	//	printf("%d ", arr2[i]);
	//}

	return 0;
}