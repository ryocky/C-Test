/*問題9*/
#include <stdio.h>

int main()
{
    float ans;
    /*体重の入力*/
    printf("体重(kg)を入力してください:");
    scanf("%f", &ans);

    printf("weight = %.2f\n", ans);
    /*月面での体重表示*/
    printf("The weight on the surface of the \"moon\" = %.2f Kg", (ans * 17 / 100));

    return(0);
}