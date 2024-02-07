#define _CRT_SECURE_NO_WARNINGS 1

#include"add.h"

void menu(){
	printf("\n");
	printf("----------------------------------------\n");
	printf("            欢迎进入六合彩系统            \n");
	printf("请选择您的操作：1.开始选号 2. 现在开奖  3.退出\n");
	printf("----------------------------------------\n");
	printf("\n");
}


int select(){
	int n = 0;
	int userNum = 0;
ag:
	printf("请输入您的号码，号码最多不能超过两位数:");
	scanf("%d", &n);//输入号码
	if (n > 9 && n < 100){
		menu();//打印菜单
		printf("输入完毕，请选择:");
		scanf("%d", &userNum);
		return n;//返回输入的号码
	}
	else{
		printf("输入的数字不和法，请重新输入!!!\n");
		goto ag;//再次输入
	}

}

void lottery(int rets,int winNum)
{
	if (rets == winNum) {//如果输入的数字和开奖的号码一样就中奖
		printf("恭喜你获得100w\n");
	}
	else{
		char n = 0;
		printf("很遗憾，您没有获奖,是否重新选择y/n:");
		getchar();
		scanf("%c", &n);
		if (n == 'y'){
			NumManage();
		}
		else{
			printf("退出程序\n");
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
		menu();//打印菜单
		printf("请输入您的选择：");
		scanf("%d", &input);//输入选择

		winNum = rand() % 100 + 1;//随机生成两位数,要开奖的号码
		//random_num = 98;//设置固定的开奖号码
		//printf("%d\n", random_num);//测试随机生成的数字
		if (3 == input) {	//如果选择了3，则退出系统
			printf("退出系统\n");
			break;
		}
		switch (input){ //进入分支
		case 1:
			ret = select();//调用函数，进行选择号码
		case 2:
			lottery(ret, winNum);
			break;
		default:
			printf("输入错误，请重新选择\n");
			break;
		}
	} while (input);
}


