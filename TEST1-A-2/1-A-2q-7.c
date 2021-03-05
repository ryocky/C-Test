/*問題7*/
#include <stdio.h>

int main()
{
	int num; 
    int i;
    int flag = 0; //素数判定のフラグ

	do{
        printf("正の整数を入力してださい:");
	    scanf("%d", &num);
        for(i = 2; i < num; i++){
            if(num % i == 0){
                flag = 1;
                break;
            }
        }
        if(num != 0){
            if(flag == 0 ){
                printf("その数は素数です。\n");
            }else{
                printf("その数は素数ではありません。\n");
                flag = 0;
            }
        }
    }while(num != 0);

    return 0;
}
