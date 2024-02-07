#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


//������
void Createdata()
{
	srand((unsigned int)time(0));
	int n = 100;
	const char* file = "SortData.txt";
	FILE* fin = fopen("SortData.txt", "w");
	if (fin == NULL)
	{
		perror("fopen fail\n");
		exit(-1);
	}

	for (int i = 0; i < n; i++)
	{
		int x = (rand() + i) % 100;
		fprintf(fin, "%d\n", x);
	}

	fclose(fin);
}

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

int GetMidIndex(int* a, int begin, int end)
{
	int mid = (begin + end) / 2;
	if (a[begin] < a[mid])
	{
		if (a[mid] < a[end])
			return mid;
		else if (a[begin] > a[end])
			return begin;
		else
			return end;
	}
	else // a[begin] > a[mid]
	{
		if (a[mid] > a[end])
			return mid;
		else if (a[begin] < a[end])
			return begin;
		else
			return end;
	}
}

void QuickSort(int* a, int left, int right)
{
	assert(a);
	if (left >= right)
		return;

	int midIndex = GetMidIndex(a, left, right);
	Swap(&a[midIndex], &a[right]);

	int prev = left - 1;
	int cur = left;
	int keyindex = right;

	while (cur < right)
	{
		if (a[cur] < a[keyindex] && ++prev != cur)
			Swap(&a[prev], &a[cur]);

		++cur;
	}
	Swap(&a[++prev], &a[keyindex]);

	int div = prev;

	QuickSort(a, left, div - 1);
	QuickSort(a, div + 1, right);

}

void _MergeFile(const char* file1, const char* file2, const char* mfile)
{
	FILE* fout1 = fopen(file1, "r");
	if (fout1 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fout2 = fopen(file2, "r");
	if (fout2 == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	FILE* fin = fopen(mfile, "w");
	if (fin == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	int num1, num2;
	int ret1 = fscanf(fout1, "%d\n", &num1);
	int ret2 = fscanf(fout2, "%d\n", &num2);
	while (ret1 != EOF && ret2 != EOF)
	{
		if (num1 < num2)
		{
			fprintf(fin, "%d\n", num1);
			ret1 = fscanf(fout1, "%d\n", &num1);
		}
		else
		{
			fprintf(fin, "%d\n", num2);
			ret2 = fscanf(fout2, "%d\n", &num2);
		}
	}

	while (ret1 != EOF)
	{
		fprintf(fin, "%d\n", num1);
		ret1 = fscanf(fout1, "%d\n", &num1);
	}

	while (ret2 != EOF)
	{
		fprintf(fin, "%d\n", num2);
		ret2 = fscanf(fout2, "%d\n", &num2);
	}

	fclose(fout1);
	fclose(fout2);
	fclose(fin);
}

void MergeSortFile(const char* file)
{
	// ���ļ�
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}

	// �ָ��һ��һ�����ݣ��ڴ������д����С�ļ���
	int n = 10; // ÿ��д������θ���
	int a[10]; // С�ļ���С
	int i = 0; // �ڷ����ݵ�С�ļ��У�ÿ�μ�¼һ��λ��
	int num = 0; // ÿ�ηŵ�ֵ
	char subfile[20]; // 
	int filei = 1; // 

	// �����ݽ��г�ʼ��������ʼ����n��С��Ҳ����10������
	memset(a, 0, sizeof(int) * n);
	
	// ������
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		// ���η����ݵ�С�ļ���
		if (i < n - 1)
		{
			a[i++] = num;
		}
		else
		{
			// ��С�ļ����й鲢
			a[i] = num;
			// ��ÿ��С�ļ��е����ݽ�������
			QuickSort(a, 0, n - 1);
			// �鲢����С�ļ�
			sprintf(subfile, "%d", filei++);
			// Ȼ����������ϲ�����ļ�
			FILE* fin = fopen(subfile, "w");
			if (fin == NULL)
			{
				printf("���ļ�ʧ��\n");
				exit(-1);
			}

			// д���ݵ�subfile,ֱ��д��
			for (int j = 0; j < n; j++)
			{
				fprintf(fin, "%d\n", a[j]);
			}
			fclose(fin);

			// ÿ���±���Ϊ0
			i = 0;
			// Ȼ���ٳ�ʼ��һ��
			memset(a, 0, sizeof(int) * n);
		}
	}

	// ���û���鲢���ļ���ʵ����������
	char mfile[100] = "12";
	char file1[100] = "1";
	char file2[100] = "2";
	for (int i = 2; i <= n; ++i)
	{
		// ��ȡfile1��file2,���й鲢��mfile
		_MergeFile(file1, file2, mfile);

		strcpy(file1, mfile);
		sprintf(file2, "%d", i + 1);
		sprintf(mfile, "%s%d", mfile, i + 1);
	}

	printf("%s�ļ�����ɹ�\n", file);
	fclose(fout);
}

int main()
{
	// �����������
	Createdata();
	// �����ݽ��з��ļ�����
	MergeSortFile("SortData.txt");

	return 0;
}