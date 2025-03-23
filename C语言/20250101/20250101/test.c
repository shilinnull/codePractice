#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

//int Fib1(int n)
//{
//	if (n <= 2)
//		return 1;
//	else
//		return Fib1(n - 2) + Fib1(n - 1);
//}
//
//int main() {
//	
//	printf("%d ", Fib1(10));
//	return 0;
//}


//int main() {
//	char a[255];
//	scanf("%s", a);
//	for (int i = 0; i < sizeof(a) / sizeof(a[0]) - 1;i++) {
//		if (a[i] >= 'a' && a[i] <= 'z' || a[i] >= 'A' && a[i] <= 'Z')
//		{
//			a[i] += 4;
//			printf("%c", a[i]);
//		}
//		else
//		{
//			printf("%c", a[i]);
//		}
//			
//	}
//	return 0;
//}

#include <stdio.h> 
#include <math.h> 
//int main()
//{
//	int n[2], i, j;
//	for (i = 0;i < 2;i++) n[i] = 0;
//	for (i = 0;i < 2;i++)
//		for (j = 0;j < 2;j++) 
//			n[j] = n[i] + 1;
//	printf("%d\n", n[1]);
//}
//int main()
//{
//	//char ch[] = "abc", x[3][4];int i;
//	////for (i = 0;i < 3;i++) strcpy(x[i], ch);
//	////for (i = 0;i < 3;i++) printf("%s", x[i][i]);
//	//void* p = NULL;
//	//putchar()
//
//	//char s[256];
//	//scanf("%s", s);
//	//int len = 0;
//	//while (s[len++]);
//	//printf("%d", len);
//	//int n = 5, i, j,m = 1;
//	//for (i = 0;i < n;i++) {
//	//	for (j = 0;j < n;j++) {
//	//		printf("%3d  ", m++);
//	//	}
//	//	printf("\n");
//	//}
//
//	//int i = 1;
//	//float sum = 0.0;
//	//while (i <= 100) {
//	//	sum += (float)(i + 1) / i;
//	//	i++;
//	//}
//
////	printf("%lf", sum);
//
//	//float a = 2, b = 1, sum = 0;
//	//while (b <= 100) {
//	//	sum = sum + a / b;
//	//	a++;b++;
//	//}
//	//	printf("sum=%f", sum);
//
//	//float a = 1.1;
//	//a++;
//	//printf("%f", a);
//
//	//double pi = 0, a = 1, b = 1;
//	//while (fabs(a / b) >= 1e-6) {
//	//	pi = pi + a / b;
//	//	a = a * (-1);
//	//	b += 2;
//	//}
//	//printf("%.10lf", pi * 4);
//
//	//printf("s=%5.3s", "computer");
//
//
//}
//int main() {
//	int a[10] = { 10,3,18,23,15,12,100,78 }, b[10] = { 18,13,12,25,24,16,10,24 }, i, j;
//	for (i = 0;i < 8;i++)
//	{
//		for (j = 0;j < 8;j++)
//			if (a[i] == b[j]) break;
//		if (j < 8) printf("%d", a[i]);
//	}
//	printf("\n");
//	int printf = 1;
//
//}

//#include<stdio.h>
//#define pi 3.14
//int main() {
//	int i = 1, j = 3;
//	double area =	pi * j * j - i * j - pi * i * i;
//	printf("%3.1f", area);
//}
// 
// 
//#include<stdio.h>
//#define pi 3.14
//int main() {
//	double x, y;
//	x = 1.0;
//	printf("%f", y = x + 3 / 2);
//}


#include<stdio.h>

//int main()
//{
//	int count = 0;
//	for (int i = 1;i <= 118;i++) {
//		int j = i % 10;
//		if (i == 2)
//			printf(" ");
//		if(i == 116)
//			printf(" ");
//
//		if (j == 0|| j == 5 || j == 4 || j == 9 || i == 1 || i == 118)
//		{
//			if (i % 5 == 0)
//				printf("\n");
//			//if(i == 116)
//			//	printf(" ");
//
//			count++;
//			printf("%-3d", i);
//		}
//		printf(" ");
//	}
//
//	printf("\n总共有%d ", count);
//
//	return 0;
//}

//void main() {
//	int i;
//	for (i = 0x20;i <= 0x6f;i++)
//		printf("%d %c\n", i, i);
//	
//
//}
//void main() {
//	float e = 1;
//	int i, ret = 1;
//	for (i = 1;(1.0 / ret) > 1e-6;i++) {
//		ret *= i;
//		e += 1.0 / ret;
//	}
//	printf("%f", e);
//}

//void main() {
//	float y = 0;int r = 1, n;
//	while ((1.0 / (r * r + 1)) > 1e-6) {
//		y += 1.0 / (r * r + 1);
//		r++;
//	}
//	printf("%f", y);
//}

//void main() {
//	float y = 0,r=1;
//	do {
//		y += 1 / (r * r + 1);
//		r++;
//	} while ((1 / r * r + 1) < 1e-6);
//	printf("y=%7.2f\n", y);
//}


//#include <stdio.h>
//
//int main() {
//    char ch;
//    while (~scanf("%c", &ch)) {
//        getchar();
//        if (ch == 'A' || ch == 'a' ||
//            ch == 'E' || ch == 'e' ||
//            ch == 'I' || ch == 'i' ||
//            ch == 'O' || ch == 'o' ||
//            ch == 'U' || ch == 'u'
//            )
//            printf("Vowel\n");
//        else
//            printf("Consonant\n");
//    }
//    return 0;
//}

//int main() {
//	int i;
//	for (i = 1000;i <= 9999;i++) {
//		int sum = i / 100 + i % 100;
//		if (sum * sum == i) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}
//int main() {
//	int i;
//	for (i = 1000;i <= 9999;i++) {
//		// 2025
//		int sum = i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000;
//		if (i % sum == 0) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}


//int main() {
//	int i,s1,s2=0,j;
//	for (i = 1000;i <= 9999;i++) {
//		// 2025
//		s1 = i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000;
//		s2 = 0;
//		for (j = 1;j <= s1;j++) {
//			s2 += j;
//		}
//		if (s2 * s2 == i) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}



//int main() {
//	int i, s1, s2 = 0, j;
//	for (i = 1000;i <= 9999;i++) {
//		// 2025
//		s1 = i % 10 + i / 10 % 10 + i / 100 % 10 + i / 1000;
//		s2 = 0;
//		for (j = 1;j <= s1;j++) {
//			s2 += j * j * j;
//		}
//		if (s2 == i) {
//			printf("%d ", i);
//		}
//	}
//	return 0;
//}

//int main() {
//	int i, s1, s2 = 0, j, k;
//	for (i = 2025;i <= 9999;i++) {
//		// 2025
//		s1 = i % 100 + i / 100;
//		for (j = 1; j <= 100;j++) {
//			for (k = 1;k <= 100;k++) {
//				if (j * j + k * k == s1 * s1 && j + 9 == k && k + 9 == s1)
//					printf("勾股数：%d^2+%d^2=%d^2=%d\n", j, k, s1, i);
//			}
//		}
//	}
//	return 0;
//}


//#include <stdio.h>
//#include <math.h>
//
//int main() {
//    double a, b, c;
//    while (scanf("%lf%lf%lf", &a, &b, &c) != EOF) {
//        double x1, x2, disc, real, imag;
//        if (fabs(a) < 1e-6) {
//            printf("Not quadratic equation\n");
//        }
//        else {
//            disc = b * b - 4 * a * c; // △
//            if (disc == 0) {
//                double root = (-b + sqrt(disc)) / (2 * a);
//                if (root == -0.0) {
//                    root = 0.0;
//                }
//                printf("x1=x2=%.2lf\n", root);
//            }
//            else if (disc > 0) {
//                x1 = (-b + sqrt(disc)) / (2 * a);
//                x2 = (-b - sqrt(disc)) / (2 * a);
//                if (x1 < x2)
//                    printf("x1=%.2lf;x2=%.2lf\n", x1, x2);
//                else
//                    printf("x1=%.2lf;x2=%.2lf\n", x2, x1);
//            }
//            else if (disc < 0) {
//                real = -b / (2 * a); // 实部
//                imag = sqrt(-disc) / (2 * a); // 虚部
//                printf("x1=%.2lf-%.2lfi;x2=%.2lf+%.2lfi\n", real, imag, real, imag);
//
//            }
//        }
//    }
//    return 0;
//}

//int f(int n) { // 12
//	if (n> 9)
//		f(n / 10);
//	printf("%d,", n % 10);
//}
//
//int main() {
//
//	//printf("%d", strlen("ats\no12\1\\"));
//	//printf("%o", '\1');
//
//	//int a[][3] = { 1,2,3,4,5,6 };
//	//printf("%d", a[1][2]);
//
//	//int n = printf("%d",1);
//	//scanf("%d", &n);
//	//f(1234);
//	char* c;
//	c = "a123456";
//	printf("%s", c);
//	return 0;
//}


//#include <stdio.h>
//
//int main() {
//    int i, j, n, m, arr[10][10];
//    scanf("%d %d", &n, &m);
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < m; j++)
//            scanf("%d", &arr[i][j]);
//    }
//    int k;
//    scanf("%d", &k);
//    while (k--) {
//        char t;
//        int a, b;
//        getchar();
//        scanf("%c %d %d", &t, &a, &b); // a和b为需要互换的行或者列
//        if (t == 'r') { // 行变换
//            // 先保存
//            int tmp[10];
//            for (i = 0; i < n; i++)
//                tmp[i] = arr[a - 1][i];
//            // 将b中的数字拷贝到a中
//            for (i = 0; i < n; i++)
//                arr[b - 1][i] = arr[a - 1][i];
//            // 最后将tmp的数字拷贝到b中
//            for (i = 0; i < n; i++)
//                arr[a - 1][i] = tmp[i];
//        }
//        if (t == 'c') { // 列变换
//            // 先保存
//            int tmp[10];
//            for (i = 0; i < m; i++)
//                tmp[i] = arr[a - 1][i];
//            // 将b中的数字拷贝到a中
//            for (i = 0; i < n; i++)
//                arr[b - 1][i] = arr[a - 1][i];
//            // 最后将tmp的数字拷贝到b中
//            for (i = 0; i < n; i++)
//                arr[a - 1][i] = tmp[i];
//        }
//    }
//    for (i = 0; i < n; i++) {
//        for (j = 0; j < m; j++)
//            printf("%d ", arr[i][j]);
//        printf("\n");
//    }
//    return 0;
//}


//int main() {
//	//printf("%x", 25);
//	//int a = 128, b = 256;
//	//printf("%d", a = b-- == 255);
//	// printf("%d", strlen("\0178"));
//
//	//int a[5] = { 5,4,3,2,1 };
//	//int* p = a;
//	// printf("%d", p - &a[4]);
//
//	//for (int i = 1;i <= 100;i++) {
//	//	for (int j = 1;j <= 100;j++) {
//	//		if (i + j == 100 && i * 4 + j * 2 == 284)
//	//			printf("兔子%d 鸡%d", i, j);
//	//	}
//	//}
//	//char str[14] = "China";
//
//	////printf("%d", 1 % -2);
//	//printf("%s", str);
//
//	//int i,j, a[4][4] = {0};
//	//for (i = 0;i <= 3 ;i++) {
//	//	for (j = 0;j <= 3-i;j++) {
//	//		printf("%d ", a[i][j]);
//	//	}
//	//	printf("\n");
//	//}
//	//printf("%d", (int)((double)(7 / 2) + 3.5));
//
//	return 0;
//}



//int main() {
//	int a = 3;
//	int b = 5;
//	int c = 0;
//	int d;
//	d = a += 2, b = b - c + a, c = a + b;
//	printf("d = %d\n", d);
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}

#include <stdio.h>

//int main() {
//    int n, i, s, t;
//    scanf("%d", &n);
//    for (i = 1; i <= n; i++) {
//        t = i;
//        s = 1;
//        while (t) {
//            s = t % 10;
//            s *= 10;
//            t /= 10;
//        } 
//        if (i == t)
//            printf("%d\n", i);
//    }
//    return 0;
//}

//#define MIN(x,y) (x)<(y)?(x):(y)
//
//int main() {
//	int i = 10, j = 15, k;
//	k = 10 * MIN(i, j);
//	return 0;
//}

//typedef struct book {
//    char writer[20];
//    double price;
//}st;
//
//int main()
//{
//    st s1 = { "zhangsan", 50 };
//    st* ps = &s1;
//
//    printf("name = %s\n", (*ps).writer);
//    printf("price = %f\n", (*ps).price);//*(结构体指针).结构体成员名
//
//    printf("name = %s\n", ps->writer);	//结构体指针->结构体成员名
//    printf("price = %f\n", ps->price);
//
//
//    //printf("name = %s\n", s1.writer);
//    //printf("price = %f\n", s1.price);  //结构体变量.结构体成员名
//    return 0;
//}


//int gcd(int x, int y) {
//	return y ? gcd(y, x % y) : x;
//}
//
//int main() {
//	int n, m;
//	scanf("%d %d", &n, &m);
//
//	// 最小公倍数=两个数相乘 / 最大公约数
//	int tmp = (m * n) / gcd(n, m);
//	printf("最大公约数为%d,最小公倍数为%d", gcd(n, m), tmp);
//	return 0;
//}
#include<stdio.h>
//
//int main()
//{
//    int m, n, r;
//    scanf("%d %d", &m, &n);
//    int x = m, y = n;
//    r = m % n;
//    while (r != 0) {
//        m = n;
//        n = r;
//        r = m % n;
//    }
//    // 最小公倍数=两个数相乘 / 最大公约数
//    int tmp = (x * y) / n;
//    printf("最大公约数为%d,最小公倍数为%d", n, tmp);
//    return 0;
//}


//#include <stdio.h>
//
//#include <stdio.h>
//
//int main() {
//    int n;
//    char a[100], a1, a2, a3, a4;
//    scanf("%d %c %c %c %c", &n, &a1, &a2, &a3, &a4);
//    scanf("%s", a);
//    int i;
//    for (i = 0; i < n; i++) {
//        if (a[i] == a1)
//            a[i] = a2;
//        if (a[i] == a2)
//            a[i] = a3;
//    }
//    printf("%s", a);
//    return 0;
//}

//void fun(int m, int* x, int *n) {
//	int i,j;
//	for (i = 2;i <= m;i++) {
//		for (j = 2;j <= i - 1;j++) {
//			if (i % j == 0) {
//				(*n)++;
//				*(x++) = i;
//				break;
//			}
//		}
//	}
//}


//int main() {
//	int a[100],n = 0;
//	fun(17, a, &n);
//	int i;
//	for (i = 0; i < n;i++) {
//		printf("%d ", a[i]);
//	}
//
//	printf("\n");
//	printf("%d", n);
//	return 0;
//}


//int fun(char* s) {
//	if (strlen(s) == 1) return *s;
//	else return (*s - '0') * 10 + fun(s+1);
//}

//#include <stdio.h>
//int main()
//{
//    //union
//    //{
//    //    short k;	// 2/4 = 2
//    //    char i[2];	// 1/4 = 1
//    //    // 大小：2
//    //}*s, a;
//    //s = &a;
//    //s->i[0] = 0x39;
//    //s->i[1] = 0x38;
//    //printf("%x\n", a.k);
//    //int a[1][3];
//    // printf("%i\n", 1);
//    //int a, b;
//    //for (a = 1,b = 1;a <= 100;a++) {
//    //    if (b >= 20) break;
//    //    if (b % 3 == 1) {
//    //        b += 3;
//    //        continue;
//    //    }
//    //    b -= 5;
//    //}
//    //printf("a = %d", a);
//
//    int year, month, day, a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
//    scanf("%d %d %d", &year, &month, &day);
//    int i, sum = 0;
//    for (i = 1;i <= month - 1;i++)
//        sum += a[i];
//    sum += day;
//    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
//        sum++;
//    printf("%d", sum);
//    return 0;
//}
//int main() {
//	char a[] = "wofaaabdafnaanla";
//	char* p = a,*q = a;
//	while (*p) {
//		if (*p == 'a')
//		{
//			p++;
//		}
//		else
//		{
//			*q = *p;
//			p++;
//			q++;
//		}
//	}
//	*q = '\0';
//	printf("%s", a);
//	return 0;
//}
//

//
//main() {
//	//double y = 3.1415926;
//	//printf("%10.3lf", y);
//
//	//do 2; while (1);
//	int i, sum, t;
//	for (i = 1;i <= 1999;i++) {
//		sum = 0;
//		t = i;
//		while (t) {
//			sum = sum * 10 + t % 10;
//			t /= 10;
//		}
//		if (sum == i) printf("%d ", i);
//	}
//}
//
//
//main() {
//	int x = 1234567;
//	long res, base = 10;
//	res = x % 10;
//	while (x > 0) {
//		x /= 100;
//		res = x % 10 * base + res;
//		base *= 10;
//	}
//	printf("%d", res);
//
//}

//int fun(int day) {
//	if (day == 10) return 1;
//	else return (1 + fun(day + 1)) * 2;
//}
//
//main() {
//	printf("%d", fun(1));
//}


//#include<stdio.h>
//
//int main() {
//    int day;
//    int peach = 1; // 第十天的桃
//    for (day = 9; day >= 1; day--) {
//        peach = (peach + 1) * 2;
//    }
//    printf("第一天共摘：%d", peach);
//    return 0;
//}



#include <stdio.h>
#include <math.h>

//int main() {
//    double x1, x0, fd, f1;
//    x0 = 1.5;
//    do {
//        x1 = x0;
//        f1 = ((2 * x1 - 4) * x1 + 3) * x0 - 6;
//        fd = (6 * x1 - 8) * x1 + 3;
//        x0 = x1 - f1 / fd;
//    } while (fabs(x1 - x0) >= 1e-5);
//    printf("The root is %lf\n", x0);
//    return 0;
//}
//int main() {
//    void Fun(char* s);
//    char s[] = "1234ABCD444adcv1243";
//    Fun(s);
//    printf("%s", s);
//    return 0;
//}
//void Fun(char* s) {
//    char* t = s;
//    while (*s >= '0' && *s <= '9') {
//        s++, t++;
//    }
//    while (*s != '\0') {
//        if (*s >= '0' && *s <= '9') {
//            s++;
//        }
//        else
//        {
//            *t = *s;
//            s++;
//            t++;
//        }
//    }
//    *t = '\0';
//}



//int main() {
//    char a[] = { "I love  C " };
//    int i = 0, num = 0;
//    char c1, c2 = ' ';
//    while (a[i] != '\0') {
//        c1 = a[i];
//        if (c1 != ' ' && c2 == ' ')
//            num++;
//        i++;
//        c2 = c1;
//    }
//    printf("单词个数为：%d\n", num);
//    return 0;
//}

//int main() {
//    char* s = "\"hel0x11lo\741world\"";
//    printf("%d", strlen(s));
//    return 0;
//}


//int main() {
//    int i = 0, j = 0;
//    while (++i) {
//        if (i % 3 == 0) continue;
//        else j += i;
//        if (i > 5) break;
//    }
//    printf("%d", j);
//    return 0;
//}
//

//#include <stdio.h>
//#include <math.h>
//int main() {
//	double x1, x2;
//	x1 = 1.5;
//	do {
//		x2 = x1;
//		x1 = x2 - (2 * pow(x2, 3) - 4 * pow(x2, 2) + 3 * x2 - 6) / (6 * pow(x2, 2) - 8 * x2 + 3);
//	} while (fabs(x1 - x2) >= 1e-5);
//	printf("%f", x2);
//	return 0;
//}
//
//int main() {
//	printf("%d", sizeof("\\141\141abc\t"));
//	return 0;
//}

//int main() {
//
//	int a[10] = { 1,3,5,7,9,2,4,6,8,10 };
//	int i, j, loc;
//	int n = 10;
//	for (i = 0;i < n - 1;i++) {
//		loc = i; // 定位
//		for (j = i + 1;j < n;j++) { // 找小的那个数的下标
//			if (a[j] < a[loc])
//				loc = j;
//		}
//		if (loc != i) { // 交换
//			int tmp = a[loc];
//			a[loc] = a[i];
//			a[i] = tmp;
//		}
//	}
//
//	for (i = 0;i < n;i++) {
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


//#include<stdio.h>
//
//void fun(int n, int* ret) {
//    if (n == 0)
//        return;
//    else {
//        ++(*ret);
//        printf("%d ", n % 10);
//        fun(n / 10, ret);
//    }
//}
//
//int main() {
//    int n = 0;
//    scanf("%d", &n);
//    int ret = 0;
//    fun(n, &ret);
//    printf("\n该数是%d位\n", ret);
//    return 0;
//}


#include<stdio.h>

//
//int main() {
//    //int x = 10;
//    //int a[32] = {0}, k = 0;
//    //while (x) {
//    //    a[31 - k++] = x % 2;
//    //    x /= 2;
//    //}
//    //for (size_t i = 0; i < 32; i++)
//    //{
//    //    printf("%d", a[i]);
//    //}
//    int i = 017;
//    printf("%d", i>>2);
//
//    return 0;
//}
#include <stdio.h>
//int main()
//{
//    int a[3][2] = { (0, 1), (2, 3), (4, 5) };
//    int* p;
//    p = a[0];
//    printf("%d", p[0]);
//    return 0;
//}
//

//
//int main()
//{
//    int i = 1, sum = 1;
//    double e = 1;
//    while (1.0 / sum >= 1e-6) {
//        sum *= i;
//        i++;
//        e += 1.0 / sum;
//    }
//    printf("%lf", e);
//    return 0;
//}
//
//main()
//{
//    int i, n[] = { 0, 0, 0, 0,0 };
//    for (i = 1; i <= 4; i++)
//    {
//        n[i] = n[i - 1] * 2 + 1;
//        printf("%d", n[i]);
//    }
//}
//main()
//{
//	char ch = getchar();
//	while (ch) {
//		if(ch == 'b')
//		printf("*");
//		ch = getchar();
//	}
//}
main()
{
	char a[] = "abc", b[20] = "def";
	char* src = a, * dest = b + strlen(b);
	while (*dest++ = *src++);
	puts(b);
}




































































































































































































































