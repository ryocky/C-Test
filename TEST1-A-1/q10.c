/*問題10*/
#include <stdio.h>
#include <conio.h>

int main()
{
    int ch;
    int tb_count = 0; //タブのカウント用変数
    int at_count = 0; //@マークカウント用変数
    int er_count = 0; //エンターキーカウント用変数
    
    printf("キーボードから文字を入力してください\n");
    while(ch != 'q'){ //q を入力したら終了
        ch = getch();
        printf("%c", ch);
        /*各文字のカウント*/
        switch (ch){
            case '\t': tb_count++; break;
            case '@': at_count++; break;
            case '\r': er_count++; break;
            default: break;
        }
    }
    /*各カウントの表示*/
    printf("\nタブ:%d\n", tb_count);
    printf("@ :%d\n", at_count);
    printf("改行:%d\n", er_count);

    return(0);
}