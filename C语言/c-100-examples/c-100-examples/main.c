#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>

#if 0

// - ��һ��
//��Ŀ���� 1��2��3��4 �ĸ����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
//��������������ڰ�λ��ʮλ����λ�����ֶ��� 1��2��3��4��������е����к���ȥ�����������������С�
int main() {
    int g, s, b;
    int count = 0; // ����ĸ���
    for (g = 1; g <= 4; g++) {
        for (s = 1; s <= 4; s++) {
            for (b = 1; b <= 4; b++) {
                if (g != s && g != b && s && b) {
                    printf("%d,%d,%d\n", g, s, b);
                    count++;
                }
            }
        }
    }
    printf("count : %d\n", count);
    return 0;
}


// - �ڶ���
/*
��Ŀ����ҵ���ŵĽ������������ɡ�

����(i)���ڻ����10��Ԫʱ���������10%��
�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��
20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��
60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%��
����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
�Ӽ������뵱������i����Ӧ���Ž���������

����������������������ֽ磬��λ��ע�ⶨ��ʱ��ѽ������˫���ȸ���(double)�͡�
*/

#include<stdio.h>
int main()
{

    double profit;
    double bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
    printf("��ľ������ǣ�");

    scanf("%lf", &profit);

    bonus1 = 100000 * 0.1;
    bonus2 = bonus1 + 100000 * 0.075;
    bonus4 = bonus2 + 200000 * 0.05;
    bonus6 = bonus4 + 200000 * 0.03;
    bonus10 = bonus6 + 400000 * 0.015;

    if (profit <= 100000) {
        bonus = profit * 0.1;
    }
    else if (profit <= 200000) {
        bonus = bonus1 + (profit - 100000) * 0.075;
    }
    else if (profit <= 400000) {
        bonus = bonus2 + (profit - 200000) * 0.05;
    }
    else if (profit <= 600000) {
        bonus = bonus4 + (profit - 400000) * 0.03;
    }
    else if (profit <= 1000000) {
        bonus = bonus6 + (profit - 600000) * 0.015;
    }
    else if (profit > 1000000) {
        bonus = bonus10 + (profit - 1000000) * 0.01;
    }
    printf("���Ϊ��bonus=%lf", bonus);

    printf("\n");
}



/*
// - ������

��Ŀ��һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
���������
�������Ϊ x��
1����x + 100 = n2, x + 100 + 168 = m2
2�������ʽ��m2 - n2 = (m + n)(m - n) = 168
3�����ã� m + n = i��m - n = j��i * j =168��i �� j ����һ����ż��
4���ɵã� m = (i + j) / 2�� n = (i - j) / 2��i �� j Ҫô����ż����Ҫô����������
5���� 3 �� 4 �Ƶ���֪����i �� j ���Ǵ��ڵ��� 2 ��ż����
6������ i * j = 168�� j>=2���� 1 < i < 168 / 2 + 1��
7���������� i ����������ѭ�����㼴�ɡ�
*/

#include <stdio.h>

int main()
{
    int  i, j, m, n, x;
    for (i = 1; i < 168 / 2 + 1; i++)
    {
        if (168 % i == 0)
        {
            j = 168 / i;
            if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
            {
                m = (i + j) / 2;
                n = (i - j) / 2;
                x = n * n - 100;
                printf("%d + 100 = %d * %d\n", x, n, n);
                printf("%d + 268 = %d * %d\n", x, m, m);
            }
        }
    }
    return 0;
}

/*
// - ������
 ��Ŀ������ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿
�����������3��5��Ϊ����Ӧ���Ȱ�ǰ�����µļ�������Ȼ���ټ���5�켴����ĵڼ��죬
 ��������������������·ݴ���3ʱ�迼�Ƕ��һ�졣
*/

int main()
{
    int year, month, day; int is_year(int);
    int m[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    printf("input year month day: ");
    fflush(stdout);
    scanf("%d %d %d", &year, &month, &day);
    int i;
    for (i = 1; i < month; i++)
        day += m[i];
    if (is_year(year) && month >= 2)
        day++;
    printf("��һ������һ��ĵ�%d��\n", day);

    return 0;
}

int is_year(int y) {
    return (((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0));
}

// - ������
/*
��Ŀ�������������� x��y��z���������������С���������

���������������취����С�����ŵ� x �ϣ��Ƚ� x �� y ���бȽϣ���� x>y �� x �� y ��ֵ���н�����Ȼ������ x �� z ���бȽϣ���� x>z �� x �� z ��ֵ���н�����������ʹ x ��С��

*/

int main()
{
    int x, y, z, t;
    scanf("%d %d %d", &x, &y, &z);

    if (x > y) { t = x; x = y; y = t; }
    if (x > z) { t = x; x = z; z = t; }
    if (y > z) { t = y; y = z; z = t; }
    printf("%d %d %d\n", x, y, z);

    return 0;
}




// - ������

/*
 ��Ŀ����*�������ĸc��ͼ����
���������������'*'����ֽ��д����ĸc���ٷ��������
*/

int main()
{
    int i, j, n;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("* ");
    }
    printf("\n");
    for (i = 1; i < n - 1; i++) {
        printf("*\n");
    }
    for (i = 0; i < n; i++) {
        printf("* ");
    }

    return 0;
}



// - ������
/*
��Ŀ���������ͼ��������c���������У���һ����very beautiful!

����������ַ�����256������ͬ�ַ���ͼ�β�һ����

vc6.0�³�����������(ԭ�� + �������) :

    176��16������b0��219��16������db��0xb0db��"��"�ֵ����룬��������ľ���"��"�ˡ�

    ��Ҫԭ�����ļ���Ϣ�Ĵ���ҳ��ͬ��������ʹ�õĲ���ϵͳ����״̬�µĴ���ҳ��Ҫ��ʾ��չ��ascii����Ҫ��437 oem - �������������ʾ�������Ϳ�����ʾ������ϣ���ġ������޸Ŀ���̨��Ĭ�ϴ���ҳ�������£�

    1.������н������ϽǱ�����ͼ�꡾c:\����ѡ��Ĭ��ֵһ��
    2.�޸�Ĭ�ϴ���ҳ��936��ansi / oem - ��������gbk��Ϊ437 oem - ����
    3���رպ���������һ�¼���

*/


#include<stdio.h>
int main()
{
    char a = 176, b = 219;
    printf("%c%c%c%c%c\n", b, a, a, a, b);
    printf("%c%c%c%c%c\n", a, b, a, b, a);
    printf("%c%c%c%c%c\n", a, a, b, a, a);
    printf("%c%c%c%c%c\n", a, b, a, b, a);
    printf("%c%c%c%c%c\n", b, a, a, a, b);
    return 0;
}



// c ��ϰʵ��8

/*��Ŀ����� 9*9 �ھ���
����������������п��ǣ��� 9 �� 9 �У�i �����У�j �����С�*/

int main()
{
    int n, i, j;
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d*%d=%d ", j, i, i * j);
        }
        printf("\n");
    }
    return 0;
}

// �����ӡ쳲��������е�ǰ20��
/*
��Ŀ���ŵ����⣨�������̣�����һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�
С���ӳ����������º�ÿ��������һ�����ӣ�
�������Ӷ���������ÿ���µ���������Ϊ���٣������ǰ40���¼��ɣ�*/
#include<stdio.h>

int main()
{
    int cnt;
    int cnt1 = 1, cnt2 = 1;
    printf("��1���£�%d\n", cnt1);
    printf("��2���£�%d\n", cnt2);

    for (int i = 3; i < 41; ++i)
    {
        cnt = cnt1 + cnt2;
        printf("��%d���£�%d\n", i, cnt);
        cnt1 = cnt2;
        cnt2 = cnt;
    }
    return 0;
}



/*
��Ŀ���ж� 101 �� 200 ֮���������

����������ж������ķ�������һ�����ֱ�ȥ�� 2 �� sqrt(�����)������ܱ�������
���������������������֮��������

*/


#include <stdio.h>
#include <math.h>
int main()
{
    int i, j;
    for (i = 101; i <= 200; i++) {
        for (j = 2; j <= sqrt(i); j++) {
            if (i % j == 0)
                break;
        }
        if (j > sqrt(i))
            printf("%d ", i);
    }
    return 0;
}


/*
13
��Ŀ����ӡ�����е�"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָһ����λ����
���λ���������͵��ڸ����������磺153��һ��"ˮ�ɻ���"����Ϊ153 = 1�����η���5�����η���3�����η���

*/

int main()
{
    int i, g,s,b;
    for (i = 100; i <= 999; i++) {
        g = i % 10;
        s = i / 10 % 10;
        b = i / 100 % 10;
        if (i == g * g * g + s * s * s + b * b * b) 
            printf("%d ", i);
    }
    return 0;
}



/*
14
��Ŀ����һ���������ֽ������������磺����90����ӡ��90=2*3*3*5��

��������n���зֽ���������Ӧ���ҵ�һ����С������k��Ȼ������������ɣ�
(1)n�ܱ�k��������Ӧ��ӡ��k��ֵ������n����k���̣���Ϊ�µ�������n���ظ�ִ�С�
(2)���n���ܱ�k����������k+1��Ϊk��ֵ���ظ�ִ�е�һ����

*/

    
int main()
{
    int i;
    int n = 90;
    printf("%d=", n);
    for (i = 2; i <= n; i++) {
        while (n % i == 0) {
            printf("%d", i);
            n = n / i;
            if (n != 1)
                printf("*");
        }
    }
    return 0;
}

/*
15
��Ŀ�����������������Ƕ������ɴ��⣺
ѧϰ�ɼ�>=90�ֵ�ͬѧ��A��ʾ��60-89��֮�����B��ʾ��60�����µ���C��ʾ��

���������(a>b)?a:b��������������Ļ������ӡ�
*/

#define GRAND(x) (x >= 90) ? 'A' : (x > 60 ? 'B' : 'C')

int main()
{
    int score;
    while (~scanf("%d", &score)) {
        printf("ѧϰ�ɼ�Ϊ��%c\n", GRAND(score));
    }
    return 0;
}



/*
16
��Ŀ����������������m��n���������Լ������С��������

���������

��1����С������ = �����������֮���������ǵ����Լ�����ؼ���������Լ����

��2�������Լ����շת�����������ŷ������㷨��

1��֤������c��a��b�����Լ������Ϊc = gcd(a, b), a >= b,
��r = a mod b
��a = kc��b = jc����k��j���أ�����c�������Լ��
���ϣ�r = a - mb = kc - mjc = (k - mj)c
��֪rҲ��c�ı�������k - mj��j���أ�������ǰ��k��j����ì��,
�ɴ˿�֪��b��r�����Լ��Ҳ��c����gcd(a, b) = gcd(b, a mod b)����֤��

2���㷨������

��һ����a �� b����rΪ����������0��r �ڶ������������� a��b��b��r�������ص�һ����
*/



int main()
{
	int m, n, r;
	scanf("%d %d", &m, &n);
	int tmp = m * n;
	r = m % n;
	while (r != 0) {
		m = n;
		n = r;
		r = m % n;
	}
	printf("���Լ��Ϊ%d,��С������Ϊ%d", n, tmp / n);

	return 0;
}



/*
* 17
��Ŀ������һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ�����

�������������while���,����Ϊ������ַ���Ϊ'\n'��
*/

int main()
{

    int letter = 0;
    int space = 0;
    int figure = 0;
    int other = 0;
    char ch;
    while ((ch = getchar()) != '\n') {
        if (ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z')
            letter++;
        else if (ch == ' ')
            space++;
        else if (ch >= '1' && ch <= '9')
            figure++;
        else
            other++;
    }
    printf("��ĸ = %d, ���� = %d, �ո� = %d, ���� = %d\n", letter, figure, space, other);
    return 0;
}


/*
* 18
��Ŀ���� s=a+aa+aaa+aaaa+aa...a ��ֵ������ a ��һ�����֣����� 2+22+222+2222+22222 (��ʱ����5�������)������������м��̿��ơ�

����������ؼ��Ǽ����ÿһ���ֵ��
*/

int main()
{
    int a, n;
    scanf("%d %d", &a, &n);
    int s = 0;
    int tmp = a;
    for (int i = 0; i < n; i++)
    {
        s += tmp;
        tmp = tmp * 10 + a;
    }
    printf("a+aa+...=%d", s);

    return 0;
}


/*
 19
��Ŀ��һ�������ǡ�õ�����������֮�ͣ�������ͳ�Ϊ"����"������ 6 = 1��2��3 �������ҳ� 1000 ���ڵ�����������
*/

int main()
{
    for (int i = 1; i <= 1000; i++) {
        int sum = 0;
        for (int j = 1; j <= i / 2; j++) {
            if (i % j == 0) {
                sum += j;
            }
        }
        if (i == sum)
            printf("�����У�%d ", sum);
    }

    return 0;
}

#include<stdio.h>

int main()
{
    int a[1000];
    for (int i = 1; i < 1000; ++i)
    {
        int sum = 0, k = 0;
        for (int j = 1; j <= i / 2; ++j)
        {
            if (i % j == 0)
            {
                sum += j;
                a[k++] = j;
            }
        }
        if (i == sum)
        {
            printf("%d = %d", i, a[0]);
            for (int m = 1; m < k; ++m)
            {
                printf(" + %d", a[m]);
            }
            printf("\n");
        }
    }

    return 0;
}

/*
 20
 ��Ŀ��һ���100�׸߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룻
 �����£������ڵ�10�����ʱ�������������ף���10�η�����ߣ�
*/


int main() {
    float m = 100.0; // ��
    int count = 10; //����10��
    float sum = m; count--; // ���������������Դ���Ҫ��һ��
    float f = 0;   // ��10�η����ĸ߶�
    while (count--) { // �Ѿ�������һ�Σ����Ծ���9��
        f = m / 2;  // ÿ������һ�γ�2
        sum += m;   // ��������
        m /= 2;
    }
    printf("��10�����ʱ��������%f�ף���10�η�����%f��\n", sum, f);
    return 0;
}



/*
 21
 ��Ŀ�����ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬����񫣬�ֶ����һ��
�ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ��
��һ����һ��������10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶��١�
�����������ȡ����˼ά�ķ������Ӻ���ǰ�ƶϡ�
1) ��x1Ϊǰһ������������x2Ϊ�ڶ����������� ��
x2=x1/2-1, x1=(x2+1)*2
x3=x2/2-1, x2=(x3+1)*2
�Դ����ƣ� xǰ=(x��+1)*2
2) �ӵ�10��������Ƶ���1�죬��һ��ѭ�����̡�
*/

int main() {
    int day;
    int peach = 1; // ��ʮ�����
    for (day = 9; day >= 1; day--) {
        peach = (peach + 1) * 2;
    }
    printf("��һ�칲ժ��%d", peach);
    return 0;
}

/*
 22
��Ŀ����ӡ������ͼ�������Σ���

   *
  ***
 *****
*******
 *****
  ***
   *
*/

int main() {
	int i, j;
	int n = 4;
	scanf("%d", &n);
	// �ϰ벿��
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - i - 1; j++)
			printf(" ");
		for (j = 0; j < 2 * i + 1; j++)
			printf("*");
		printf("\n");
	}
	// �°벿��
	for (i = n - 1; i > 0; i--) {
		for (j = n - 1; j >= i; j--)
			printf(" ");
		for (j = 2 * (i - 1); j >= 0; j--)
			printf("*");
		printf("\n");
	}
	return 0;
}
/*
 24
��Ŀ����һ�������У�2/1��3/2��5/3��8/5��13/8��21/13...���������е�ǰ20��֮�͡�
*/

int main() {
	int i;
	float sum = 0, a = 2, b = 1, t;
	for (i = 0; i < 20; i++) {
		sum += a / b;
		t = a;
		a = a + b;
        b = t;
	}

	printf("%f", sum);
	return 0;
}


/*
 25
��Ŀ���� 1 + 2! + 3! + ... + 20! �ĺ͡�
*/
int main() {
	int i, j;
	unsigned long long sum = 0, ret = 1;
	for (i = 1; i <= 20; i++) {
		ret = 1;
		for (j = 1; j <= i; j++) {
			ret *= j;
		}
		sum += ret;
	}
	printf("%llu", sum);
	return 0;
}

/*
 26
 ���õݹ鷽���� 5!��
*/

int fun(int n) {
    if (n == 1)
        return 1;
    else
        return n * fun(n - 1);
}
int main() {
    int n = 5;
    printf("5�Ľ׳�Ϊ��%d\n",fun(n));
    return 0;
}


/*
27
��Ŀ�����õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ������
*/


void fun(int n) {
	if (n == 1)
	{
		char tmp = getchar();
		putchar(tmp);
	}
	else
	{
		char tmp = getchar();
		fun(n - 1);
		putchar(tmp);
	}
}

int main() {
	fun(5);
	return 0;
}
/*
28
��Ŀ����5��������һ���ʵ�����˶����ꣿ
��˵�ȵ�4���˴�2�ꡣ�ʵ�4������������˵�ȵ�3���˴�2�ꡣ
�ʵ������ˣ���˵�ȵ�2�˴����ꡣ�ʵ�2���ˣ�˵�ȵ�һ���˴����ꡣ
����ʵ�һ���ˣ���˵��10�ꡣ���ʵ�����˶��*/


int age(int n) {
    if (n == 1)
        return 10;
    else
        return age(n - 1) + 2;
}

int main() {
    printf("��5�����ǣ�%d\n", age(5));
    return 0;
}


/*
29
��Ŀ����һ��������5λ����������Ҫ��һ�������Ǽ�λ�������������ӡ����λ���֡�

*/

void fun(int n, int* ret) {
	if (n == 0)
		return;
	else {
        ++(*ret);
		printf("%d ", n % 10);
        fun(n / 10, ret);
	}
}

int main() {
	int n = 0;
	scanf("%d", &n);
	int ret = 0;
	fun(n, &ret);
	printf("\n������%dλ\n", ret);
	return 0;
}


/*
29
��Ŀ��һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��
*/

int main() {
    int n;
    while (~scanf("%d", &n)) {
        if ((n / 10000 == n % 10) && (n / 1000 % 10 == n / 10 % 10))
            printf("����λ���ǻ�����\n");
        else
            printf("����λ�����ǻ�����\n");
    }
    return 0;
}


// ��Ŀ����һ���Ѿ��ź�������顣������һ������Ҫ��ԭ���Ĺ��ɽ������������С������ֲ��ң�
int main() {

	int arr[11] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, j, len, n;
	len = sizeof(arr) / sizeof(arr[0]) - 1;
	scanf("%d", &n);
	int left = 0, right = len, mid;
	for (i = 0;i < len;i++) {
		mid = left + (right - left) / 2;
		if (arr[mid] < n)
			left = mid + 1;
		else if (arr[mid] > n)
			right = mid - 1;
		else {
			// �ҵ���
			for (j = len;j >= mid;j--) {
				arr[j] = arr[j - 1];
			}
			break;
		}
	}
	for (i = 0;i < sizeof(arr) / sizeof(arr[0]);i++)
		printf("%d ", arr[i]);
	return 0;
}


// ��Ŀ����һ���������������
int main() {
	int arr[] = { 1,2,3,4,5,6,7,8,9 ,10 };
    int len = sizeof(arr) / sizeof(arr[0]);
	int i, j = len - 1, tmp;
	for (i = 0;i < len / 2;i++, j--) {
		tmp = arr[i];
		arr[i] = arr[j];
		arr[j] = tmp;
	}
	for (i = 0;i < len;i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}




// ��Ŀ������3����a, b, c������С˳�������



int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a < b) {
        b = a ^ b;
        a = a ^ b;
        b = a ^ b;
    }

    if (a < c) {
        c = a ^ c;
        a = a ^ c;
        c = a ^ c;
        
    }

    if (b < c) {
        c = b ^ c;
        b = b ^ c;
        c = b ^ c;
    }
    printf("%d %d %d\n", a, b, c);
    return 0;
}


#define SWAP(x,y) (x)^=(y);(y)^=(x);(x)^=(y);
int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
		SWAP(a, b);
	if (a < c)
		SWAP(a, c);
	if (b < c)
		SWAP(b, c);
	printf("%d %d %d\n", a, b, c);
	return 0;
}


// ��Ŀ���������飬�������һ��Ԫ�ؽ�������С�������һ��Ԫ�ؽ�����������顣

int main() {

	int arr[10] = { 7,2,8,1,5,10,4,3,9,6 };
	int i = 0, min = arr[0], max = arr[0], tmp, len = sizeof(arr) / sizeof(arr[0]);

	// ��¼��������С���±�
	int maxi, mini;
	for (i = 0; i < len;i++) {
		if (arr[i] > max) {
			max = arr[i];
			maxi = i;
		}
		if (arr[i] < min) {
			min = arr[i];
			mini = i;
		}
	}
	// ����
	// �������һ������
	tmp = arr[maxi];
	arr[maxi] = arr[0];
	arr[0] = tmp;

	// ��С�������һ��Ԫ�ؽ���
	tmp = arr[mini];
	arr[mini] = arr[len - 1];
	arr[len - 1] = tmp;

	for (i = 0; i < 10;i++) {
		printf("%d ", arr[i]);
	}

	return 0;
}


// ��Ŀ����n��������ʹ��ǰ�����˳�������m��λ�ã����m���������ǰ���m������
#include <stdio.h>
void reverse(int* nums, int begin, int end) {
	while (begin < end) {
		int tmp = nums[begin];
		nums[begin] = nums[end];
		nums[end] = tmp;
		begin++;
		end--;
	}
}
int main()
{
	int i, n, m;
	printf("Ҫ��������ָ�����");
	scanf("%d", &n);

	int* num = (int*)malloc(sizeof(int) * n);
	if (num == NULL)return 0;

	printf("�������֣�");
	for (i = 0;i < n;i++)
		scanf("%d", &num[i]);
	printf("������Ҫ��ת���Σ�");
	scanf("%d", &m);
	m %= n;
	reverse(num, 0, n - m - 1);
	reverse(num, n - m, n - 1);
	reverse(num, 0, n - 1);

	for (i = 0;i < n;i++)
		printf("%d ", num[i]);
    free(num);
	return 0;
}


/*
��Ŀ����n����Χ��һȦ��˳���źš��ӵ�һ���˿�ʼ��������1��3��������
������3�����˳�Ȧ�ӣ���������µ���ԭ���ڼ��ŵ���λ��
*/
int main() {
	int n, i = 0;
	printf("����n���ˣ�");
	scanf("%d", &n);
	int* a = (int*)malloc(sizeof(int) * n);
	//���
	for (int i = 0; i < n; ++i)
		a[i] = i + 1;

	int cut = 0; // ����
	i = 0;
	int num = n;  // δ������
	while (num > 1) {
		if (a[i]) {
			cut++;
			if (cut == 3) {
				a[i] = 0;
				cut = 0;
				num--;
			}
		}
		i++;
		if (i == n)
			i = 0;
	}
	for (i = 0;i < n;i++)
		if (a[i])
			printf("�������������%d\n", a[i]);
	free(a);
	a = NULL;
	return 0;
}

// ��Ŀ��дһ����������һ���ַ����ĳ��ȣ���main�����������ַ�����������䳤�ȡ�

#include <assert.h>
int main() {
    int my_strlen(char*);
    char* str = (char*)malloc(sizeof(char) * 100);
    scanf("%s", str);

    printf("�ַ�������Ϊ��%d\n", my_strlen(str));

    free(str);
    str = NULL;
    return 0;
}

int my_strlen(const char* s) {
    assert(s);
    int count = 0;
    while (*s++ != '\0') count++;
    return count;
}

// ��Ŀ����дinput()��output()�������룬���5��ѧ�������ݼ�¼��

struct Stu {
	char name[20];
	char sex[3];
	int age;
};

void input(struct Stu** s, int* n) {
	printf("������ѧ���������Ա����䣺\n");
	for (int i = 0; i < *n;i++)
		scanf("%s %s %d", (*s + i)->name, &(*s + i)->sex, &(*s + i)->age);
}
void output(struct Stu** s, int* n) {
	printf("��ӡѧ���������Ա����䣺\n");
	for (int i = 0; i < *n;i++)
		printf("%s %s %d\n", (*s + i)->name, (*s + i)->sex, (*s + i)->age);
}
int main() {
	int n;
	printf("������Ҫ������ļ�λ��");
	scanf("%d", &n);
	struct Stu* s = (struct Stu*)malloc(sizeof(struct Stu) * n);

	input(&s, &n);
	output(&s, &n);

	free(s);
	s = NULL;
	return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// ��Ŀ������һ������


#include <stdio.h>
#include <malloc.h>

typedef struct LNode
{
    int data;
    struct LNode* next;
}LNode;

LNode* createList(int n)
{
    LNode* list, * p, * q;
    list = (LNode*)malloc(sizeof(LNode));
    list->next = NULL;
    q = list;
    for (int i = 0; i < n; ++i)
    {
        p = (LNode*)malloc(sizeof(LNode));
        printf("�������%d��Ԫ�ص�ֵ��", i + 1);
        scanf("%d", &(p->data));
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return list;
}

void print(LNode* list)
{
    printf("�����ֵΪ:\n");

    LNode* p = list->next;
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    LNode* list = NULL;
    int n;
    scanf("%d", &n);
    list = createList(n);
    print(list);

    return 0;
}


// ��Ŀ������һ�������������䷴ת�������

int main() {
    int n, newn = 0, x;
    scanf("%d", &n);
    while (n) {
        x = n % 10;
        newn = newn * 10 + x;
        n /= 10;
    }
    printf("��ת����Ϊ��%d", newn);
    return 0;
}

// ��Ŀ����дһ������������nΪż��ʱ�����ú�����1/2+1/4+...+1/n,������nΪ����ʱ��
// ���ú���1/1+1/3+...+1/n(����ָ�뺯��)��

double sumup(int n, int flag) {
    double sum = 0;
    if (flag == 2) {
        for (int i = flag;i <= n;i += 2) {
            sum += (double)1 / i;
        }
    }
    else {
        for (int i = flag;i <= n;i += 2) {
            sum += (double)1 / i;
        }
    }
    return sum;
}

int main() {
    int n, flag = 0;
    double (*psum)(int, int);
    scanf("%d", &n);
    if (n % 2 == 0) { // nΪż��
        psum = sumup;
        flag = 2;
    }
    else { // nΪ����
        psum = sumup;
        flag = 1;
    }
    printf("%lf", (*psum)(n, flag));
    return 0;
}


// ��Ŀ���ҵ����������ˣ��������

#include<stdio.h>
#include<stdlib.h>
typedef struct man {
    char name[20];
    int  age;
}man;

int main() {
    man person[] = { {"zhanagsan",18},{"lisi",30},{"wangwu",25} };
    man* p = person, * q = NULL;
    int max = person[0].age;
    int count = sizeof(person) / sizeof(person[0]);
    while (count--) {
        if (max < p->age) {
            max = p->age;
            q = p;
        }
        p++;
    }
    printf("������������%s��%d", q->name, q->age);
    return 0;
}

// �ַ�������ascll������
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// �ȽϺ��������� qsort ����
int compare(const void* e1, const void* e2) {
    return strcmp(*(const char**)e1, *(const char**)e2);
}

int main() {
    // �����ַ�������
    char* str[] = { "ac", "abc", "zz", "yyy", NULL };
    // ���������С������ NULL��
    int n = 0;
    while (str[n] != NULL) n++;

    // ʹ�� qsort �����ַ���ָ������
    qsort(str, n, sizeof(char*), compare);

    for (int i = 0; i < n; i++)
        printf("%s ", str[i]);

    return 0;
}


#include <stdio.h>

int main() {
    int N = 1;  // ��1��ʼ�����С������

    while (1) {
        int peaches = N;
        int valid = 1;

        // ģ��ÿֻ���ӷ����ӵĹ���
        for (int i = 0; i < 5; i++) {
            if ((peaches - 1) % 5 != 0) {
                valid = 0;
                break;
            }
            peaches = (peaches - 1) / 5 * 4;
        }

        // ����������㣬������
        if (valid) {
            printf("��̲��ԭ�������� %d �����ӡ�\n", N);
            break;
        }

        // ��������N�������
        N++;
    }

    return 0;
}
#include <stdio.h>

int main()
{
    for (int i = 10; i < 100; ++i)
    {
        if (809 * i < 10000 && 809 * i>999)
        {
            if (8 * i < 100 && 8 * i>9)
            {
                if (9 * i < 1000 && 9 * i>99)
                {
                    if (809 * i == 800 * i + 9 * i)
                    {
                        printf("%d\n", i);
                        printf("%d\n", 809 * i);
                    }
                }
            }
        }
    }

    return 0;
}


// ��Ŀ����0��7������ɵ�����������

#include <stdio.h>

int main()
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (i == 0)
            cnt = 4;
        else if (i == 1)
            cnt *= 7;
        else
            cnt *= 8;
        sum += cnt;
        printf("%dλ��Ϊ�����ĸ���Ϊ%d\n", i + 1, cnt);
    }
    printf("����Ϊ%d\n", sum);
    return 0;
}


int main()
{
    int i, n, m;
    printf("Ҫ��������ָ�����");
    scanf("%d", &n);

    int* num = (int*)malloc(sizeof(int) * n);
    if (num == NULL)return 0;

    printf("�������֣�");
    for (i = 0;i < n;i++)
        scanf("%d", &num[i]);
    printf("������Ҫ��ת���Σ�");
    scanf("%d", &m);
    m %= n;

    for (i = 0; i < m;i++) {
        int* p = num + n - 1;
        int tmp = *p;   // �������һλ
        while (p > num) { // �ƶ�����
            *p = *(p - 1);
            p--;
        }
        *p = tmp;
    }

    for (i = 0;i < n;i++)
        printf("%d ", num[i]);
    free(num);
    return 0;
}


int main()
{
    int arr[10] = { 1,2,3,4,5,6,7,8 };
    int i = 0;
    int j = 0;
    int count = 0;
    int len = sizeof(arr) / sizeof(int);
    for (j = 0; j < 5; j++)
    {
        printf("��%d�ؽ���֮��", j + 1);
        for (i = 0; i < len; i++)
        {
            if (arr[i] != 0)
            {
                count++;
                if (count % 3 == 0)
                {
                    arr[i] = 0;
                    continue;
                }
                printf("%-4d", arr[i]);
            }
        }
        printf("\n");
    }
    return 0;
}


int main() {
    float s = 0;
    int i = 0,t;
    int fenmu = 1,fenzi = 2;

    for (i = 0;i < 20;i++) {
        t = fenzi; // ��ǰ�������һ��ķ���
        s += (float)fenzi / fenmu; // �����
        fenzi = fenzi + fenmu; // ��һ��ķ���=��һ��ķ��Ӻͷ�ĸ֮��
        fenmu = t;// ��ĸ=��һ��ķ���
    }

    printf("%f", s);// 32.660263
    return 0;
}




// ��Ŀ��809\*??=800\*??+9*?? ����??�������λ��, 809\*??Ϊ��λ����
// 8\*??�Ľ��Ϊ��λ����9\*??�Ľ��Ϊ3λ������??�������λ������809\*??��Ľ������

#include <stdio.h>

int main() {
    for (int i = 10;i <= 99;i++) {
        if ((809 * i >= 1000 && 809 * i <= 10000) && (8 * i <= 99 && 9 * i >= 100)) {
            printf("%d = %d*%d + %d*%d", 809 * i, 800, i, 9, i); // 9708 = 800*12 + 9*12
        }
    }
    return 0;
}



// ��Ŀ���ж�һ�������ܱ�����9������

int is_prime(int num)
{
    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}

int main()
{
    int x,i;
    scanf("%d", &i);
    if (is_prime(i)) 
    {
        for (x = 9; x % i != 0; x = x * 10 + 9)
            if (x > 1000000000)
                return 0;
        printf("����%d���Ա�%d����\n", i, x); // ����13���Ա�999999����
    }
    return 0;
}

#include <assert.h>

char* my_strcat(char* s1, const char* s2) {
    assert(s1 && s2);
    int i = 0;
    int len = strlen(s1);
    while (s1[len++] = s2[i++]);
    return s1;
}

int main() {
    char str1[20] = "abc";
    char str2[10] = "def";

    printf("%s", my_strcat(str1, str2));
    return 0;
}


// ��Ŀ����ȡ7������1��50��������ֵ��ÿ��ȡһ��ֵ�������ӡ����ֵ������*��

#include<stdio.h>

int main() {
    int n, count, j;
    printf("������7������1��50��������ֵ��");
    count = 0;
    while (count < 7) {
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("������7������1��50��������ֵ��");
        }
        else
        {
            for (j = 0;j < n;j++)
                printf("*");
            count++;
            printf("\n");
        }
    }
    return 0;
}


/*
��Ŀ��ĳ����˾���ù��õ绰�������ݣ���������λ���������ڴ��ݹ������Ǽ��ܵģ�
���ܹ������£� ÿλ���ֶ�����5,Ȼ���úͳ���10��������������֣�
�ٽ���һλ�͵���λ�������ڶ�λ�͵���λ������
*/

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
	int n, i = 0, a[4];
	scanf("%d", &n);

	for (i = 0;i < 4;i++) {
		a[3 - i] = n % 10;
		n /= 10;
        a[3 - i] += 5; // ÿλ���ֶ�����5
        a[3 - i] %= 10; // Ȼ���úͳ���10���������������
	}
    swap(&a[0], &a[3]); // �ٽ���һλ�͵���λ����
    swap(&a[1], &a[2]); // �ڶ�λ�͵���λ����

	for (i = 0;i < 4;i++) {
		printf("%d", a[i]); /* 1234
                               9876*/
	}
    return 0;
}


#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//���òµ����ִ�������
#define NUM 10 

void menu()
{
    printf("**********************\n");
    printf("******  1.play *******\n");
    printf("******  0.exit *******\n");
    printf("**********************\n");
}

void game()
{
    int guess = 0;
    int ret = rand() % 100 + 1;
    int count = NUM;
    while (1)
    {
        printf("�㻹��%d�λ��ᣡ\n", count);
        printf("�������(1~100):>");
        scanf("%d", &guess);
        if(guess < 1 || guess > 100)
        {
            printf("������������²����֣�\n");
            continue;
        }
        else if (guess > ret)
        {
            printf("�´��ˣ�\n");
        }
        else if (guess < ret)
        {
            printf("��С�ˣ�\n");
        }
        else
        {
            printf("��ϲ�㣬�¶��ˣ�\n");
            break;
        }
        count--;
        if (count == 0)
        {
            printf("�������꣬��ȷ��������%d\n", ret);
            break;
        }
    }
}
int main()
{
    int input = 0;
    srand((unsigned int)time(NULL));//���������
    do
    {
        menu();
        printf("��ѡ��>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            game();
            break;
        case 0:
            printf("�˳���Ϸ��\n");
            break;
        default:
            printf("ѡ�����������ѡ��\n");
            break;
        }
    } while (input);

    return 0;
}


int main() {
	int i = 0, j = 0, count = 0;
	char* str1 = "789123412356";
	char* str2 = "12";
	int len1 = strlen(str1), len2 = strlen(str2);
	while (i < len1 && j < len2) {
		if (str1[i] == str2[j]) {
			i++;
			j++;
			if (j == len2)
			{
				j = 0;
				count++; // ����++
			}
			continue;    // �����Ⱦͼ������У��������i�ͻ������
		}
		i++;
	}
	printf("%s���ֵĴ�����%d\n", str2, count);
	return 0;
}


// ��Ŀ���Ӽ�������һЩ�ַ�������������͵�������ȥ��ֱ������һ��#Ϊֹ��


int main() {
	char c;
    
    // ���ļ�
	FILE* pf = fopen("data.txt", "w+");
	if (pf == NULL) {
		perror("Open File fail!"); 
        exit(-1);
	}

    // �����ļ�����
    c = getchar();
    while (c != '#') {
        fputc(c, pf);
		c = getchar();
	}

    // �ر��ļ�
    fclose(pf);
    pf = NULL;
	return 0;
}




// �������

int main() {
    int a[10][10], i, j;
    for (i = 0;i < 10;i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for (i = 2;i < 10;i++) {
        for (j = 1;j < i;j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }

    for (i = 0;i < 10;i++) {
        for (j = 0;j <= i;j++) {
           
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}


// ��Ŀ���Ӽ�������һ���ַ�������Сд��ĸȫ��ת���ɴ�д��ĸ��Ȼ�������һ�������ļ�"test"�б��档


int main() {
    int i;
    FILE* pf = fopen("test", "w+");
    if (pf == NULL) {
        perror("Open File fail!");
        exit(-1);
    }

    char str[255] = "";
    scanf("%s", str);
    int len = strlen(str);

    // ��Сд��ĸȫ��ת���ɴ�д��ĸ
    for (i = 0;i < len;i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= 32;
        }
    }

    fprintf(pf, "%s", str);

    // �ر��ļ�
    fclose(pf);
    pf = NULL;
    return 0;
}


/*
��Ŀ�������������ļ�A��B,�����һ����ĸ��
Ҫ����������ļ��е���Ϣ�ϲ�������ĸ˳�����У���
�����һ�����ļ�C�С�
�ȴ���a.txtд��xyz
�ٴ���b.txtд��abc
*/


FILE* open(char* s, char* mode) {
	FILE* p = fopen(s, mode);
	if (p == NULL) {
		perror("Open File fail!");
		exit(-1);
	}
	return p;
}

void close(FILE* p) {
	fclose(p);
	p = NULL;
}

void read(FILE* p, char* s) {
	fgets(s, 50, p);
}

int cmp_char(const void* e1, const void* e2)
{
	return strcmp(e1, e2);
}

void merge(char* s, int len) {
	qsort(s, len, sizeof(s[0]), cmp_char);
}

int main() {
	// �����������ļ�A��B �ȴ���a.txtд��xyz, �ٴ���b.txtд��abc
	FILE* pA = open("a.txt", "w+");
	fprintf(pA, "xyz");
	FILE* pB = open("b.txt", "w+");
	fprintf(pB, "abc");

	// ȷ���ļ�ָ���ڿ�ͷ
	rewind(pA);
	rewind(pB);

	// ��ȡȡ�������ļ��е����ݵ�����
	char strA[100], strB[50];
	read(pA, strA);
	read(pB, strB);

	// Ҫ����������ļ��е���Ϣ�ϲ�������ĸ˳������)
	strcat(strA, strB);
	int len = strlen(strA);
	merge(strA, len);

	// ���ļ�c
	FILE* pC = open("c.txt", "w+");
	fprintf(pC, "%s", strA);
	// fputs(strA, pC);

	// �ر��ļ�
	close(pA);
	close(pB);
	close(pC);
	return 0;
}


/*
��Ŀ�������ѧ����ÿ��ѧ����3�ſεĳɼ���
���������������ݣ�����ѧ���ţ����������ſγɼ�����
�����ƽ���ɼ�����ԭ�е����ݺͼ������ƽ����������ڴ����ļ�"stud"�С�
*/

typedef struct Student
{
    int id;
    char name[20];
    int grade1;
    int grade2;
    int grade3;
    int averageGrade;
}Student;

int main()
{
    Student stu[5];
    for (int i = 0; i < 5; ++i)
    {
        scanf("%d %s %d %d %d", &stu[i].id, &stu[i].name, &stu[i].grade1, &stu[i].grade2, &stu[i].grade3);
        stu[i].averageGrade = (stu[i].grade1 + stu[i].grade2 + stu[i].grade3) / 3;
    }
    /* ����
    1 a 10 20 30
    2 b 20 30 40
    3 c 30 40 50
    4 d 40 50 60
    5 e 50 60 70
    */
    FILE* fp = fopen("stud.txt", "w");
    if (fp == NULL)
    {
        perror("Open File fail!");
        exit(-1);
    }

    for (int i = 0; i < 5; ++i)
        fprintf(fp, "%d %s %d %d %d %d\n", stu[i].id, stu[i].name, stu[i].grade1, stu[i].grade2, stu[i].grade3, stu[i].averageGrade);
    /* �ļ������
    1 a 10 20 30 20
    2 b 20 30 40 30
    3 c 30 40 50 40
    4 d 40 50 60 50
    5 e 50 60 70 60
    */
    fclose(fp);
    fp = NULL;
    return 0;
}


int main() {
    int a[10][10], i, j;
    for (i = 0;i < 10;i++) {
        a[i][0] = 1;
        a[i][i] = 1;
    }

    for (i = 2;i < 10;i++) {
        for (j = 1;j < i;j++) {
            a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
        }
    }
    for (i = 0;i < 10;i++) {
        for (j = 0;j <= i;j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
/*
    1
    1    1
    1    2    1
    1    3    3    1
    1    4    6    4    1
    1    5   10   10    5    1
    1    6   15   20   15    6    1
    1    7   21   35   35   21    7    1
    1    8   28   56   70   56   28    8    1
    1    9   36   84  126  126   84   36    9    1
*/


// ����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ����20Ԫ�����Ժȶ�����ˮ�����ʵ�֣���

int main() {
    int money = 20;
    int total = money;
    int empty = money;

    while (empty >= 2) {
        total += empty / 2;
        empty = empty / 2 + empty % 2;
    }

    printf("�ܹ����Ժ� %d ƿ��ˮ\n", total);
    return 0;
}

// ��ʵ���Ǹ��Ȳ����У�money * 2 - 1
int main() {
    int money = 20;
    printf("�ܹ����Ժ� %d ƿ��ˮ\n", money * 2 - 1);
    return 0;
}


// ��ӡ����

int main() {
    int n = 6,i,j;
    //scanf("%d", &n);
    for (i = 0;i < n + 1;i++) {
        // ��ӡ�ո�
        for (j = 0;j < n - i - 1;j++) {
            printf(" ");
        }

        // ��ӡ�Ǻ�
        for (j = 0;j < i * 2 + 1;j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}


/*
�ݹ�ͷǵݹ�ֱ�ʵ�����n��쳲�������
���磺
���룺5  �����5
���룺10�� �����55
���룺2�� �����1
*/

int f(int i) {
    if (i == 1 || i == 2)
        return 1;
    else
        return f(i - 1) + f(i - 2);
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d ", f(n));
    return 0;
}


int main() {

	int n, i, a = 1, b = 1,c = 1;
    scanf("%d", &n);

    if (n <= 2) {
        c = 1;
    }
    else {
        for (i = 2; i <= n;i++) {
            c = a + b;
            a = b;
            b = c;
        }
    }
    printf("%d ", a);

    return 0;
}
#endif









































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































