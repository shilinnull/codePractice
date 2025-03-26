#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){
//    int8_t myInt8 = INT8_MAX;
//    printf("%d\n",myInt8);
//    printf("%"PRId8"\n",myInt8);
//
//    int_least32_t plaerScore = INT_LEAST32_MAX;
//    printf("%d\n",plaerScore);
/////    printf("%"PRIdLEAST32"\n",plaerScore);
//
//    int_fast16_t pixelValue = INT_FAST16_MAX;
//    printf("%"PRIdFAST16"\n",plaerScore);


    // 如果尾数的整数部分是奇数，向上舍入
//    float num = 3.1415926f; // 3.1
//    float num1 = 3.27f; // 3.3
//    printf("%.1f\n",num);
//    printf("%.1f\n",num1);
//    printf("%a %a\n",num1);
//    float num = 3.95f;
//    printf("%.1f\n",num);
//    for(int i = 6;i <= 40;i++){
//        for(int j = 15;j <= 30;j++){
//            if(2 * i + 5 * j == 120){
//                printf("(%d,%d)\n",i,j);
//            }
//        }
//    }
    int m = 0;
    scanf("%d",&m);
    for(int i  = 1;i<=m ;i++){
        // 打印空格
        for(int k = 1;k <= m - i;k++){
            printf(" ");
        }
        // 打印数字
        for(int j = 1;j<=i;j++){
            printf("%d ",i);
        }
        printf("\n");
    }


    return 0;
}
