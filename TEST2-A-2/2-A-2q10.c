/*問題10*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv){

    char word[81];
    int i;
    unsigned long adr;
    FILE *FP;

    /*ファイルの読み込み*/
    if((FP = fopen("import2-A-2.txt", "r")) == NULL)
    {
        printf("ファイル読み込めません\n");
        exit(1);
    }
    adr = 0;
    while(fgets(word, 81, FP) != NULL)
    {
        
        printf("%08lX ", adr);
        
        i = 0;
        while((word[i] != '\0') && (i < 81))
        {
            /*16進数に変換*/
            printf("%02X  ", word[i]);
            i++;
        }
        printf("\n");
        adr += 16;
    }  
    
    fclose(FP);
    return 0;
}