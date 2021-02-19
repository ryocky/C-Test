#include <stdio.h>

int main(){
    int ans;

    printf("一日の睡眠時間を入力して下さい\n");
    scanf("%d", &ans);

    switch (ans)
    {
        case 8:
        case 9: printf("健康的です\n"); break;
        case 10: printf("十分な睡眠です\n"); break;
        default: printf("規則正しい生活をしましょう\n");
    }
}