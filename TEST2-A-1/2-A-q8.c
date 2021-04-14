/*問題8*/
#include <stdio.h>
/*再帰関数での文字列長さ取得*/
int rstrlen(char *str)
{
    int num;

    if (*str != '\0'){
        num = rstrlen(++str);
    }else{
        return(0);
    }
    return ++num;
}

int main()
{
    char input[81];
    int i;
    int num = 0;

    /*配列の初期化*/
    for(i = 0; i < 81; i++){
        input[i] = '\0';
    }
    /*文字の入力*/
    gets(input);
    num = rstrlen(input);

    printf("文字列の長さ:%d\n", num);

    return 0;
}