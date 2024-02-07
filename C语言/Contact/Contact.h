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

// 初始化和销毁
void ContactInit(contact* pcon);
void ContactDestory(contact* pcon);

//添加联系人
void ContactAdd(contact* pcon);

//修改联系人
void ContactModify(contact* pcon);

//查看通讯里
void ContactShow(contact* pcon);

//查找联系人
void ContactFind(contact* pcon);

//删除联系人
void ContactDel(contact* pcon);
