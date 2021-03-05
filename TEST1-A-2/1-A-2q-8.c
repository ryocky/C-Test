/*問題8*/
#include <stdio.h>

int main()
{
    int mode; //メニュー選択用変数
    float num; //求めたい数値を記憶する変数

    do{
	    printf("変換\n");
	    printf("1.フィートからメートルへ\n");
        printf("2.メートルからフィートへ\n");
        printf("3.オンスからポンドへ\n");
        printf("4.ポンドからオンスへ\n");
        printf("5.終了\n");
        printf("番号を選んで入力してださい:");
        scanf("%d", &mode);
        if(mode == 1 || mode == 2 || mode == 3 || mode == 4){
            printf("変換する値を入力してださい:");
            scanf("%f", &num);
        }
        switch (mode){
            case 1:printf("%.2fメートルです\n", num*0.304); break;
            case 2:printf("%.2fフィートです\n", num*3.28); break;
            case 3:printf("%.2fポンドです\n", num*0.062); break;
            case 4:printf("%.2fオンスです\n", num*16); break;
            default: break;
        }
    }while (mode != 5);
    
    return 0;
}
