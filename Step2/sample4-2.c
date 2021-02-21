#include <stdio.h>

int main(){
    int price[10];
    int number;

    /*値段の初期設定*/
    price[0]=80; price[1]=100; price[2]=120;
    price[3]=140; price[4]=150; price[5]=160;
    price[6]=200; price[7]=198; price[8]=220;
    price[9]=280;

    /*繰り返し処理*/
    do{
        printf("値段を知りたい番号を入力してください");
        printf("[1-10以外なら終了]\n");
        scanf("%d", &number);
        /*値段表示*/
        if((number >= 1) && (number <= 10)){
            printf("%d番の棚は、%d円です\n", number, price[number-1]);
        }
    }while((number>=1) && (number <= 10));
    return(0);
}