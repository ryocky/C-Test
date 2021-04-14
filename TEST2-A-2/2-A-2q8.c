/*問題8*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv){

    char word[81];
    int i;
    FILE *FP1, *FP2;

    /*読み込み用ファイルの読み込み*/
    if((FP1 = fopen("import2-A-2.txt", "r")) == NULL)
    {
        printf("読み込みファイル読み込めません\n");
        exit(1);
    }
    /*書き込み用ファイルの書き出し*/
    if((FP2 = fopen("export2-A-2.txt", "w")) == NULL)
    {
        printf("書き出しファイル読み込めません\n");
        exit(1);
    }

    while(fgets(word, 81, FP1) != NULL)
    {
        i = 0;
        while((word[i] != '\0') && (i < 81))
        {
            /*タブ文字をスペース置き換え*/
            if(word[i] == '\t')
            {
                fputc(' ', FP2);
            }else
            {
                fprintf(FP2, "%c", word[i]);
            }
            i++;
        }
    }    
    fclose(FP1);
    fclose(FP2);
    return 0;
}