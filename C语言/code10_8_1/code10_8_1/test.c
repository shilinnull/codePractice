#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	//写文件
//	fputs("hello word", pf);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	char arr[10] = "abcdef";
//	//读文件
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//typedef struct Stu
//{
//	char name[20];
//	int hight;
//	float score;
//}stu;
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	char arr[10] = "abcdef";
//	//写文件
//
//	stu s = { "zhangsan",175,65.5f };
//	fprintf(pf, "%s %d %f", s.name, s.hight, s.score);
//	printf("%s %d %f", s.name, s.hight, s.score);
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//typedef struct Stu
//{
//	char name[20];
//	int hight;
//	float score;
//}stu;
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	stu s = { "zhangsan",175,65.5f };
//
//	//二进值的写
//	fwrite(&s, sizeof(s), 1, pf);
//	
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//typedef struct Stu
//{
//	char name[20];
//	int hight;
//	float score;
//}stu;
//
//int main()
//{
//	//打开文件
//	FILE* pf = fopen("data.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	stu s = { "zhangsan",175,65.5f };
//
//	//二进值的读
//	fread(&s, sizeof(s), 1, pf);
//	printf("%s %d %f", s.name, s.hight, s.score);
//	
//
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//typedef struct Stu
//{
//	char name[20];
//	int height;
//	float score;
//}stu;
//
//int main2()
//{
//	//int ch = fgetc(stdin);
//	//fputc(ch, stdout);
//	//int ch = 0;
//	//fscanf(stdin, "%c", &ch);
//	//fprintf(stdout, "%c", ch);
//
//	char buf[100] = { 0 };
//	stu s = { "zhangsan", 175, 65.5f };
//	stu tmp = { 0 };
//
//	//将这个结构体的成员转化为字符串
//	sprintf(buf, "%s %d %f", s.name, s.height, s.score);
//	printf("%s\n", buf);
//
//	//将这个字符串中内容还原为一个结构体数据呢
//	sscanf(buf, "%s %d %f", tmp.name, &(tmp.height), &(tmp.score));
//
//	printf("%s %d %f", tmp.name, tmp.height, tmp.score);
//
//	return 0;
//}

//typedef struct Stu
//{
//	char name[20];
//	int height;
//	float score;
//}stu;
//
//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fail fopen!");
//		return 1;
//	}
//
//	//int ch = fgetc(pf);
//	//printf("%c\n", ch);
//	//fseek(pf, 3, SEEK_SET);
//
//	//ch = fgetc(pf);
//	//printf("%c", ch);
//
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//	fseek(pf, 2, SEEK_CUR);
//
//	ch = fgetc(pf);
//	printf("%c", ch);
//
//	return 0;
//}


//int main()
//{
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fail fopen!");
//		return 1;
//	}
//
//
//	int ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	fseek(pf, 2, SEEK_CUR);
//	ch = fgetc(pf);
//	printf("%c\n", ch);
//
//	int pos = ftell(pf);
//	printf("%d\n", pos);
//	
//	rewind(pf);
//	ch = fgetc(pf);
//	printf("%c", ch);
//	return 0;
//}

//int main()
//{
//	FILE* pFile;
//	long size;
//	pFile = fopen("data.txt", "rb");
//	if (pFile == NULL) perror("Error opening file");
//	else
//	{
//		fseek(pFile, 0, SEEK_END); //non-portable
//		size = ftell(pFile);
//		fclose(pFile);
//		printf("Size of myfile.txt: %ld bytes.\n", size);
//	}
//	return 0;
//}
//int main()
//{
//	int n;
//	FILE* pFile;
//	char buffer[27];
//	pFile = fopen("data.txt", "w+");
//	for (n = 'A'; n <= 'Z'; n++)
//		fputc(n, pFile);
//
//	rewind(pFile);	 //当文件指针pFile重新回到起始位置
//	fread(buffer, 1, 26, pFile);	//通过文件指针读入26个字母到buffer字符数组中
//	fclose(pFile);
//	buffer[26] = '\0';		//'\0'表示字符串的结束位置
//	puts(buffer);
//	return 0;
//}

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//二进制的形式写到文件中
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

void MergeSortFile(const char* file)
{
	FILE* fout = fopen(file, "r");
	if (!fout)
	{
		perror("fopen fail");
		exit(-1);
	}

	int num = 0;
	int n = 10;
	int i = 0;
	int b[10];
	char subfile[20];
	int filei = 1;
	//1.读取大文件，然后将其平均分成N份，加载到内存中后对每份进行排序，然后再写回小文件
	memset(b, 0, sizeof(int) * n);
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			b[i++] = num;	//首先读9个数据到数组中
		}
		else
		{
			b[i] = num;		//再将第十个输入放入数组
			QuickSort(b, 0, n - 1);		//对其进行排序

			sprintf(subfile, "%d", filei++);

			FILE* fin = fopen(subfile, "w");
			if (!fin)
			{
				perror("fopen fail");
				exit(-1);
			}
			//再进本轮排好序的10个数以单个小文件的形式写到工程文件下
			for (int j = 0; j < n; ++j)
			{
				fprintf(fin, "%d\n", b[j]);
			}
			fclose(fin);

			i = 0;		//i重新置0，方便下一次的读取
			memset(b, 0, sizeof(int) * n);
		}
	}
}