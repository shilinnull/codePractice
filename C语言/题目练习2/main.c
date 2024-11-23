#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
//int max() {
//
//    return 0;
//}
//int main() {
////    printf("%p\n", max);
////    printf("%p\n", &max);
//    char str[]  = "OK";
//    char *p1 = str;
//    char *p2 = &str;
//    char (*p)[3] = &str;
//    printf("%s\n", p1);
//    printf("%s\n", p2);
//    printf("%s\n", p);
//    return 0;
//}


//void main() {
//    char *a = "Turbo C";
//    printf("%c %s\n", a[0], a);
//
//    char *p = &a[4];
//    printf("%c", *p);
//}
//#include <stdio.h>
//#include <string.h>
//
//void reverse(char *str) {
//    int len = strlen(str);
//    for (int i = 0; i < len / 2; i++) {
//        char temp = str[i];
//        str[i] = str[len - i - 1];
//        str[len - i - 1] = temp;
//    }
//}
//int main() {
//    char str[] = "Hello World";
//    reverse(str);
//    printf("%s\n", str);
//    return 0;
//}


//int main()
//{
//    // 汽水
//    int bottle = 21;
//    int sum = 20;
//
//    while(bottle >= 2)
//    {
//        if(bottle % 2 == 0) {
//            sum += bottle / 2;
//            bottle = bottle / 2;
//        }
//        else {
//            sum += bottle / 2 + 1;
//            bottle /= 2;
//        }
//    }
//    printf("%d\n",sum);
//}


//int main()
//{
//    int money = 0;
//    int total = 0;
//    int empty = 0;
//
//
//    scanf("%d", &money);
//
//    //方法1
//    total = money;
//    empty = money;
//    while(empty>1)
//    {
//        total += empty/2;
//        empty = empty/2+empty%2;
//    }
//
//    printf("total = %d\n", total);
//    return 0;
//}
//
//int main()
//{
//    int arr[10] = {0};
//    float fun(int* a);
//    for (int i = 0; i < 10; ++i) {
//        scanf("%d",&arr[i]);
//    }
//    printf("%lf",fun(arr));
//    return 0;
//}
//
//float fun(int *a){
//    int max = a[0],min = a[0];
//    for (int i = 0; i < 10; ++i) {
//        if(a[i] > max)
//            max = a[i];
//        else if(a[i]<min)
//            min = a[i];
//    }
//    return (float)(max + min) / 10;
//}


int main()
{
    bool is_year(int);
    int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int month,year,day;
    scanf("%d %d %d",&year,&month,&day);
    for(int i = 1;i < month;i++){
        day += m[i];
    }
    if(is_year(year) || month >= 2)
        day++;

    printf("there is %d",day);

    return 0;
}

bool is_year(int y)
{
    return ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0);
}





