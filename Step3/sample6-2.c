#include <stdio.h>

int main(){
    
    char input;

    /*入力*/
    scanf("%c", &input);

    /*出力*/
    printf("入力された文字[%c][%d]", input, (int)input);

    return(0);
}