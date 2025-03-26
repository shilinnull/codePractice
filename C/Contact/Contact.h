#define _CRT_SECURE_NO_WARNINGS 1
#pragma once




#define NAME_MAX 100
#define SEX_MAX 10
#define TEL_MAX 15
#define ADDR_MAX 100


typedef struct ContactInfo
{
	char name[NAME_MAX];
	char gender[SEX_MAX];
	int age;
	char tel[TEL_MAX];
	char addr[ADDR_MAX];
}CInfo;


typedef struct SeqList contact;

// ��ʼ��������
void ContactInit(contact* pcon);
void ContactDestory(contact* pcon);

//�����ϵ��
void ContactAdd(contact* pcon);

//�޸���ϵ��
void ContactModify(contact* pcon);

//�鿴ͨѶ��
void ContactShow(contact* pcon);

//������ϵ��
void ContactFind(contact* pcon);

//ɾ����ϵ��
void ContactDel(contact* pcon);
