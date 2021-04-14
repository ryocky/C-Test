#include <stdio.h>

int main(){
    int score[10][2];
    int i, j;
    FILE *FP; //①ファイルポインタの宣言

    /*得点結果の入力*/
    for(i=0; i<10; i++){
        printf("A対Bの第%d試合結果を数字2つで入力してください\n", i+1);
        scanf("%d %d", &score[i][0], &score[i][1]);
    }

    /*②ファイル書き込み可能状態にする*/
    FP = fopen("result.text", "w");

    /*③結果表示*/
    fprintf(FP, "----A----|----B----\n");
    for(i=0; i<10; i++){
        for(j=0; j<(10-score[i][0]); j++){
            fprintf(FP, " ");
        }
        for(j=0; j<score[i][0]; j++){
            fprintf(FP, "*");
        }
        fprintf(FP, "|");
        for(j=0; j<score[i][1]; j++){
            fprintf(FP, "*");
        }
        fprintf(FP, "\n");
    }
    fclose(FP); //④
    return(0);
}