#include <stdio.h>
int main(){
    int num, total;

    total = 0;
    do{
        printf("整数値を入力して下さい\n");
        scanf("%d", &num);

        total = total + num;
        printf("これまでの合計: %d\n", total);
    }while(num != 0);
}