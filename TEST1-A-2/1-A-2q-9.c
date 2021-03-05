/*問題9*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num;
    int ans;
    int i;
    /*乱数の初期化*/
    srand((unsigned)time(NULL));
    
    printf("数あてゲームを始めます。\n");
    /*1~100からランダムな値を生成*/
    num = rand() % 100 + 1;

    printf("チャンスは10回です。\n");
    for(i = 1; i <= 10; i++){
        printf("%d回目\n", i);
        printf("1~100の整数値から選んで入力してださい:");
        scanf("%d", &ans);
        if(ans > num) printf("値が大きいです。\n");
        if(ans < num) printf("値が小さいです。\n");
        if(ans == num){
            printf("当たり!\n");
        break;
        }
    }
    
    return(0);
}