/*問題9*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){

    char word[81];
    int num;
    FILE *FP;

    /*ファイルの読み込み*/
    if((FP = fopen(argv[1], "r")) == NULL){
        printf("ファイル読み込めません\n");
        return(1);
    }
    do{
        fgets(word, 81, FP);
        printf("%s", word);
        /*ファイルが終端なら終了*/
        if(fgetc(FP) == EOF){
           printf("続きはありません\n");
           exit(0); 
        }
        printf("次の行を表示しますか? 0で終了、0以外で続ける:");
        scanf("%d" , &num);
    }while(num != 0);
    
    fclose(FP);
    return 0;
}