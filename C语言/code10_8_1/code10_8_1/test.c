#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	//д�ļ�
//	fputs("hello word", pf);
//
//	//�ر��ļ�
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

//int main()
//{
//	//���ļ�
//	FILE* pf = fopen("data.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	char arr[10] = "abcdef";
//	//���ļ�
//	fgets(arr, 5, pf);
//	printf("%s", arr);
//
//	//�ر��ļ�
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
//	//���ļ�
//	FILE* pf = fopen("data.txt", "w");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	char arr[10] = "abcdef";
//	//д�ļ�
//
//	stu s = { "zhangsan",175,65.5f };
//	fprintf(pf, "%s %d %f", s.name, s.hight, s.score);
//	printf("%s %d %f", s.name, s.hight, s.score);
//
//	//�ر��ļ�
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
//	//���ļ�
//	FILE* pf = fopen("data.txt", "wb");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	stu s = { "zhangsan",175,65.5f };
//
//	//����ֵ��д
//	fwrite(&s, sizeof(s), 1, pf);
//	
//	//�ر��ļ�
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
//	//���ļ�
//	FILE* pf = fopen("data.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fail fopen");
//		return 1;
//	}
//	stu s = { "zhangsan",175,65.5f };
//
//	//����ֵ�Ķ�
//	fread(&s, sizeof(s), 1, pf);
//	printf("%s %d %f", s.name, s.hight, s.score);
//	
//
//	//�ر��ļ�
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
//	//������ṹ��ĳ�Աת��Ϊ�ַ���
//	sprintf(buf, "%s %d %f", s.name, s.height, s.score);
//	printf("%s\n", buf);
//
//	//������ַ��������ݻ�ԭΪһ���ṹ��������
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
//	rewind(pFile);	 //���ļ�ָ��pFile���»ص���ʼλ��
//	fread(buffer, 1, 26, pFile);	//ͨ���ļ�ָ�����26����ĸ��buffer�ַ�������
//	fclose(pFile);
//	buffer[26] = '\0';		//'\0'��ʾ�ַ����Ľ���λ��
//	puts(buffer);
//	return 0;
//}

//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1, pf);//�����Ƶ���ʽд���ļ���
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
	//1.��ȡ���ļ���Ȼ����ƽ���ֳ�N�ݣ����ص��ڴ��к��ÿ�ݽ�������Ȼ����д��С�ļ�
	memset(b, 0, sizeof(int) * n);
	while (fscanf(fout, "%d\n", &num) != EOF)
	{
		if (i < n - 1)
		{
			b[i++] = num;	//���ȶ�9�����ݵ�������
		}
		else
		{
			b[i] = num;		//�ٽ���ʮ�������������
			QuickSort(b, 0, n - 1);		//�����������

			sprintf(subfile, "%d", filei++);

			FILE* fin = fopen(subfile, "w");
			if (!fin)
			{
				perror("fopen fail");
				exit(-1);
			}
			//�ٽ������ź����10�����Ե���С�ļ�����ʽд�������ļ���
			for (int j = 0; j < n; ++j)
			{
				fprintf(fin, "%d\n", b[j]);
			}
			fclose(fin);

			i = 0;		//i������0��������һ�εĶ�ȡ
			memset(b, 0, sizeof(int) * n);
		}
	}
}