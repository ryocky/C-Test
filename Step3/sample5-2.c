#include <stdio.h>

int main(){
    int point[10][30];
    int total[10];
    int i, j;
    FILE *FP; //①ファイルを扱うための変数宣言

    /*ファイルを読み込み可能状態にする*/
    FP = fopen("data1.text", "r"); //②用意してあるテキストファイルを読み込み可にする
    
    /*ポイントの入力*/
    for(j=0; j<10; j++){
        for(i=0; i<30; i++){
            printf("背番号%2dの%d打席目のポイント入力\n", j, i+1);
            fscanf(FP, "%d", &point[i][j]); //③テキストファイルからデータを読み込む
        }
    }

    /*ファイルの使用を終了する*/
    fclose(FP);

    /*合計得点の表示*/
    for(j=0; j < 10; j++){
        total[j] = 0;
        for(i=0; i<30; i++){
            total[j] = total[j] + point[j][i];
        }
    }

    /*結果の表示*/
    printf("----結果----\n");
    for(i=0; i< 30; i++){
        for(j=0; j<10; j++){
            printf("%3d", point[j][i]);
        }
        printf("\n");
    }
    printf("---|---|---|---|---|---|---|---|---|---|\n");
    for(j=0; j<10; j++){
        printf("%3d", total[j]);
    }
    return(0);   
}