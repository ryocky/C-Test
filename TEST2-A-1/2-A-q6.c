/*問題6*/
#include <stdio.h>

int main()
{
    int i, j = 1;
    while(j != 10){
        for(i = 1; i <= 9; i++){
            printf("%d X %d = %d\n",j, i, j*i);
            /*iが9になったらjの値を1増やす*/
            if(i != 9)
            continue;
            j++;
        }
    printf("----------------\n");
    }
    return(0);
}