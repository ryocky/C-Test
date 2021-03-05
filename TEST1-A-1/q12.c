/*問題12*/
#include <stdio.h>

int main()
{
    int i, j;
    for(j = 1; j <= 9; j++){
        for(i = 1; i <= 9; i++){
            printf("%d X %d = %d\n",j, i, j*i);
        }
        printf("----------------\n");
    }
    return(0);
}