#define _CRT_SECURE_NO_WARNINGS 1

#include"add.h"

void menu(){
	printf("\n");
	printf("----------------------------------------\n");
	printf("            ��ӭ�������ϲ�ϵͳ            \n");
	printf("��ѡ�����Ĳ�����1.��ʼѡ�� 2. ���ڿ���  3.�˳�\n");
	printf("----------------------------------------\n");
	printf("\n");
}


int select(){
	int n = 0;
	int userNum = 0;
ag:
	printf("���������ĺ��룬������಻�ܳ�����λ��:");
	scanf("%d", &n);//�������
	if (n > 9 && n < 100){
		menu();//��ӡ�˵�
		printf("������ϣ���ѡ��:");
		scanf("%d", &userNum);
		return n;//��������ĺ���
	}
	else{
		printf("��������ֲ��ͷ�������������!!!\n");
		goto ag;//�ٴ�����
	}

}

void lottery(int rets,int winNum)
{
	if (rets == winNum) {//�����������ֺͿ����ĺ���һ�����н�
		printf("��ϲ����100w\n");
	}
	else{
		char n = 0;
		printf("���ź�����û�л�,�Ƿ�����ѡ��y/n:");
		getchar();
		scanf("%c", &n);
		if (n == 'y'){
			NumManage();
		}
		else{
			printf("�˳�����\n");
			exit(-1);
		}
	}
}


void NumManage()
{
	int input = 0;
	int ret = 0;
	int winNum = 0;
	do{
		menu();//��ӡ�˵�
		printf("����������ѡ��");
		scanf("%d", &input);//����ѡ��

		winNum = rand() % 100 + 1;//���������λ��,Ҫ�����ĺ���
		//random_num = 98;//���ù̶��Ŀ�������
		//printf("%d\n", random_num);//����������ɵ�����
		if (3 == input) {	//���ѡ����3�����˳�ϵͳ
			printf("�˳�ϵͳ\n");
			break;
		}
		switch (input){ //�����֧
		case 1:
			ret = select();//���ú���������ѡ�����
		case 2:
			lottery(ret, winNum);
			break;
		default:
			printf("�������������ѡ��\n");
			break;
		}
	} while (input);
}


