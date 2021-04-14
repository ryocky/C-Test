/*問題10*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv){

    char word[81];
    char newLine;
    int i;
    FILE *FP1, *FP2;

    /*読み込み用ファイルの読み込み*/
    if((FP1 = fopen("originFile.txt", "r")) == NULL){
        printf("読み込みファイル読み込めません\n");
        return(1);
    }
    /*書き込み用ファイルの書き出し*/
    if((FP2 = fopen("outputFile.txt", "w")) == NULL){
        printf("書き出しファイル読み込めません\n");
        return(1);
    }

    while(fgets(word, 81, FP1) != NULL){
        i = 0;
        while((word[i] != '\0') && (i < 81)){
            /*小文字なら大文字に変換*/
            if((word[i] >= 'a') && (word[i] <= 'z')){
                fprintf(FP2, "%c", (char)((int)word[i] - 32));
                /*大文字なら小文字に変換*/
            }else if((word[i] >= 'A') && (word[i] <= 'Z')){
                fprintf(FP2, "%c", (char)((int)word[i] + 32));
            }
            i++;
        }
        fputc('\n', FP2);
    }    
    fclose(FP1);
    fclose(FP2);
    return 0;
}