#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Swap(int* p1,int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

//造数据
void Createdata()
{
	srand((unsigned int)time(0));
	int n = 1000000;
	const char* file = "data.txt";
	FILE* fin = fopen("data.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail\n");
		exit(-1);
	}
	
	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 1000000;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void AdjustDown(int* a,int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child + 1] < a[child])
		{
			++child;
		}

		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

void AdjustUp(int* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void PrintTopK(const char* file,int k)
{
	//读数据
	FILE* fout = fopen("data.txt", "r");
	if (fout == NULL)
	{
		perror("fopen fail\n");
		exit(-1);
	}

	//边读边建立一个k个数的小堆
	int* minheap = (int*)malloc(sizeof(int) * k);
	if (minheap == NULL)
	{
		perror("fopen fail\n");
		exit(-1);
	}

	for (int i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &minheap[i]);
		AdjustUp(minheap, i);
	}

	//取剩余的数进堆
	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (minheap[0] < x)
		{
			minheap[0] = x;
			AdjustDown(minheap, k, 0);
		}
	}

	for (int i = 0; i < k; i++)
	{
		printf("%d ", minheap[i]);
	}

	free(minheap);
	fclose(fout);
}


int main()
{
	Createdata();
	PrintTopK("data.txt",5);
	return 0;
}	