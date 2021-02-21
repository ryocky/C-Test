#include <stdio.h>

int main(){
    int point[3][4]; //A,B,Cの得点を記憶する配列①
    int total[3];
    int i, j;

    /*得点の入力②*/
    for(i=0; i<4; i++){
        for(j=0; j<3; j++){
            switch(j){
                case 0:printf("A"); break;
                case 1:printf("B"); break;
                case 2:printf("C"); break;
            }
            printf("のゲーム%dの得点を入力してください\n", i+1);
            scanf("%d", &point[j][i]);
        }
    }

    /*合計得点の計算③*/
    for(j=0; j < 3; j++){
        total[j]=0;
        for(i=0; i<4; i++){
            total[j] = total[j] + point[j][i];
        }
    }

    /*表の表示④*/
    for(j=0; j < 3; j++){
        for(i=0; i<4; i++){
            printf("%4d", point[j][i]);
        }
        printf(" :%d\n", total[j]);
    }
    return(0);
}