/*問題7*/
#include <stdio.h>

int main()
{
    int num[20] = {1,2,3,4,5,6,7,8,9,10,
                   11,12,13,14,15,16,17,18,19,20};
    FILE *FP;

    /*ファイル開けるか確認*/
    if((FP = fopen("test.bin", "wb")) == NULL){
        printf("ファイル開けません");
        return(1);
    }
    fwrite(num, sizeof(num), 1, FP);
    fclose(FP);

    return(0);
}