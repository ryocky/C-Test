/*問題6*/
#include <stdio.h>

int main()
{
	int room; //部屋数を記憶する変数
    int r_length; //部屋の長さを記憶する変数
    int r_width; //部屋の幅を記憶する変数
    int r_area = 0; //総床面積を記憶する変数
    int i;

	printf("部屋の数を入力してださい:");
	scanf("%d", &room);

    for(i = 0; i < room; i++){
        printf("長さを入力してださい:");
        scanf("%d", &r_length);
        printf("幅を入力してださい:");
        scanf("%d", &r_width);
        r_area = r_area + (r_length * r_width);
    }
    printf("総床面積:%d", r_area);
	
    return 0;
}
