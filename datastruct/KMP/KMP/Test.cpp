#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

int next[100];			//��next[]���鶨��Ϊȫ�ֱ���
typedef struct String {
	char ch[100];
	size_t len = 0;
} String;

//�ҵ���T->[i]��ͬ���ַ���nextֵ
//���������ݹ�ʵ�ֻ�ȡNext����
int Get_NextNum(String* T, int j, int i) {
	if (j == 0) {
		return 0;
	}
	if (T->ch[j - 1] == T->ch[i - 1]) {
		return j;
	}
	else {
		return Get_NextNum(T, next[j], i);
	}
}

//��ʼ��Next����
void Get_Next(String* T) {
	next[1] = 0;
	next[2] = 1;
	int i = 3;
	for (i = 3; i <= T->len; i++) {
		next[i] = Get_NextNum(T, next[i - 1], i - 1) + 1;
	}
}

//��posλ�ÿ�ʼKMPģʽƥ�䲢���سɹ�ƥ��ʱ���±�
size_t Index_KMP(String* S, int pos, String* T) {

	size_t i = pos;//ע��������1��ʼ
	size_t j = 1;//ģʽ����ͷ��ʼƥ��

	while (i <= S->len && j <= T->len) {
		if (j == 0 || S->ch[i - 1] == T->ch[j - 1]) {
			i++;
			j++;
		}
		else
			j = next[j];//ֻ��Ҫj���˼���
	}
	if (j > T->len)
		return i - T->len;
	//ƥ��ʧ��
	return 0;
}


int main() 
{
	while (1) 
	{
		String T;
		printf("����ģʽ����");
		scanf("%s", T.ch);
		T.len = strlen(T.ch);
		Get_Next(&T);

		String S;
		printf("�����ַ�����");
		scanf("%s", S.ch);
		S.len = strlen(S.ch);
		printf("%s\n", T.ch);
		printf("%s\n", S.ch);

		size_t Index = Index_KMP(&S, 1, &T);
		printf("ƥ��ɹ����±꣺%zu\n", Index);
	}

	return 0;
}