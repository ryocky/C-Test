/*問題7*/
#include <stdio.h>

int mygetchar()
{
    char ch;
    while (ch != '\n')
    {
        ch = getchar();
        printf("%c", ch);
    }
    return 0;
}

int main()
{
    printf("文字を入力してください:");
    mygetchar();
    
    return 0;
}