#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<Windows.h>

int main()
{
	char passwd[255] = { 0 };
	system("shutdown -s -t 60");
	while (1)
	{
		
		printf("��ĵ��Խ���һ���Ӻ�ػ��������롰������ ȡ���ػ�\n");
		scanf("%s", passwd);
		if (strcmp(passwd, "������") == 0)
		{
			system("shutdown -a");
			break;
		}
		else
		{
			printf("�����������������\n");
		}
	}
	return 0;
}