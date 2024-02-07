#define _CRT_SECURE_NO_WARNINGS 1

/*
兔子繁殖问题：假定一对大兔子每月能生一对小兔子，
且每对新生的小兔子经过一个月可以长成一对大兔子,
具备繁殖能力，如果不发生死亡，且每次均生下一雌一雄，
问一年后共有多少对兔子？
*/

#include <stdio.h>

int rabbitPairs(int months) {
    if (months == 1 || months == 2) {
        return 1; // 初始时只有一对兔子
    } else {
        // 递归计算前两个月的兔子数量，然后加上新生的兔子数量
        return rabbitPairs(months - 1) + rabbitPairs(months - 2);
    }
}

int main() {
    int months_per_year = 12;
    int total_rabbits = rabbitPairs(months_per_year);

    printf("一年后共有 %d 对兔子\n", total_rabbits);

    return 0;
}
