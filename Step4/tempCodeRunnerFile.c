#include <stdio.h>
 
int main()
{
    int a[5] = {10, 20, 30, 40, 50}; //配列
    int *p; //ポインタ変数
 
    p = &a[0]; //配列の先頭のアドレスを代入する
 
    /*配列の中身表示*/
    printf("繰り返し処理による配列内の値表示:");
    for(int i=0; i<5; i++){
        printf("%d ", a[i]);
    }
    printf("\n");

    /*ポインタを使った配列の中身表示*/
    printf("ポインタを使った配列内の値表示:");
    for(int i=0; i<5; i++){
        printf("%d ", *p);
        p++;
    }

    return(0);
}