#include <stdio.h>

int main(){
    int num, total;

    /*それぞれの変数に初期値を代入する*/
    num = -1;
    total = 0;

    /*条件式が成り立っている間、処理を繰り返す*/
    while (num!=0){
        printf("整数値を入力してください\n");
        scanf("%d", &num);

        total = total + num;
        printf("これまでの合計:%d\n", total);
    }
    return(0);
}