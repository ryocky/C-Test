#include <stdio.h>

int main(){
    
    char input[81]; //①文字列を記憶する1次元配列
    int i;

    /*初期化*/
    for(i=0; i<81; i++){
        input[i] = '\0'; //②配列をNullで初期化
    }
    
    /*入力*/
    scanf("%s", input); //③文字列の入力を受付け

    /*出力*/
    printf("入力された文字\n%s\n", input); //④配列inputの文字列表示

    /*⑤1文字ずつ検査と表示*/
    for(i=0; i<81; i++){
        switch (input[i]){
            case 'a':printf("A"); break;
            case 'b':printf("B"); break;
            case 'c':printf("C"); break;
            case 'd':printf("D"); break;
            case 'e':printf("E"); break;
            case 'f':printf("F"); break;
            case 'g':printf("G"); break;
            case 'h':printf("H"); break;
            case 'i':printf("I"); break;
            case 'j':printf("J"); break;
            case 'k':printf("K"); break;
            case 'l':printf("L"); break;
            case 'm':printf("M"); break;
            case 'n':printf("N"); break;
            case 'o':printf("O"); break;
            case 'p':printf("P"); break;
            case 'q':printf("Q"); break;
            case 'r':printf("R"); break;
            case 's':printf("S"); break;
            case 't':printf("T"); break;
            case 'u':printf("U"); break;
            case 'v':printf("V"); break;
            case 'w':printf("W"); break;
            case 'x':printf("X"); break;
            case 'y':printf("Y"); break;
            case 'z':printf("Z"); break;
            default :printf("%c", input[i]);
        }
    }
    return(0);
}