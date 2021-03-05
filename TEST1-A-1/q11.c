/*問題11*/
#include <stdio.h>

int main()
{
    int num; //計算回数を記憶する変数
    float dist; //距離を記憶する変数
    float spd; //速度を記憶する変数
    float time; //時間を記憶する変数
    int i;

    printf("計算する回数を入力してください:");
    scanf("%d", &num);

    for(i = 0; i < num; i++){
        printf("距離(km)を入力してください:");
        scanf("%f", &dist);
        printf("平均速度(km/h)を入力してください:");
        scanf("%f", &spd);
        time = dist / spd;
        printf("所要時間は %.1f 時間です。\n", time);
    }
    return(0);
}