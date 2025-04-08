#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int HPDataType;

void Swap(HPDataType* p1, HPDataType* p2)
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}
void AdjustUp_Big(HPDataType* a, int child)
{
    int parent = (child - 1) / 2;
    while (child > 0)
    {
        if (a[child] > a[parent])
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
void AdjustDown_Big(HPDataType* a, int size, int parent)
{
    int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && a[child + 1] > a[child])
            ++child;

        if (a[child] > a[parent])
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

void HeapSort()
{
    //建大堆
    int a[] = { 4,6,2,1,5,8,2,9 };
    int sz = sizeof(a) / sizeof(a[0]);
    /*for (int i = 1; i < sz; i++)
    {
        AdjustUp_Big(a, i);
    }*/

    //向下调整建堆，这样效率更高，上面那个也可以
    for (int i = (sz - 1 - 1) / 2; i >= 0; --i)
    {
        AdjustDown_Big(a, sz, i);
    }

    //打印
    printf("排序前:");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n");

    //排序
    //end是在最后一个元素的下标-1
    int end = sz - 1;
    while (end > 0)
    {
        //根和最后一个值进行交换，最后一个数不看做堆里面的
        Swap(&a[0], &a[end]);
        AdjustDown_Big(a, end, 0);
        --end;
    }

    //打印
    printf("排序后:");
    for (int i = 0; i < sz; i++)
    {
        printf("%d ", a[i]);
    }
}

void AdjustUp(HPDataType* a, int child)
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
void AdjustDown(HPDataType* a, int size, int parent)
{
    int child = parent * 2 + 1;
    while (child < size)
    {
        if (child + 1 < size && a[child + 1] < a[child])
            ++child;

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

void CreateData()
{
    //造数据
    int n = 100000;
    srand((unsigned int)time(NULL));
    const char* file = "data.txt";
    FILE* fin = fopen(file, "w");
    if (fin == NULL)
    {
        perror("fopen error");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        int x = (rand() + i) % 100000;
        fprintf(fin, "%d\n", x);
    }
    fclose(fin);
}


void PrintTopK(const char* file, int k)
{
    //读文件
    FILE* fout = fopen(file, "r");
    if (fout == NULL)
    {
        perror("fopen error");
        return;
    }

    //建立一个k个数的小堆

    int* minheap = (int*)malloc(sizeof(int) * k);
    if (minheap == NULL)
    {
        perror("malloc error");
        return;
    }

    //读取前k个数
    for (int i = 0; i < k; i++)
    {
        fscanf(fout, "%d", &minheap[i]);
        //向上调整
        AdjustUp(minheap, i);
    }

    //边读边建小堆
    //读取剩余的值，读到x里
    int x = 0;
    while (fscanf(fout, "%d", &x) != EOF)
    {
        //如果堆里的元素小于x就继续调整
        if (minheap[0] < x)
        {
            //将x搞到堆顶
            minheap[0] = x;
            //向下调整
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
    // CreateData();
    PrintTopK("data.txt", 5);

    return 0;
}