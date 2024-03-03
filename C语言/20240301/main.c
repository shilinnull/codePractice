#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(){
    int8_t myInt8 = INT8_MAX;
    printf("%d\n",myInt8);
    printf("%"PRId8"\n",myInt8);

    int_least32_t plaerScore = INT_LEAST32_MAX;
    printf("%d\n",plaerScore);
    printf("%"PRIdLEAST32"\n",plaerScore);

    int_fast16_t pixelValue = INT_FAST16_MAX;
    printf("%"PRIdFAST16"\n",plaerScore);


    return 0;
}
