/*問題10*/
#include <stdio.h>

/*再帰関数階乗の計算*/
int fact(int n)
{
    int m;

    if (n == 0)
        return 1; //0! = 1
    /*nが0でないとき*/
    m = fact(n - 1); 
    return n * m;   
}

int main()
{
    int i, num;

    printf("整数を入力してください:");
    scanf("%d", &i);
    num = fact(i);
    printf("%dの階乗は%dです。\n", i, num);

    return 0;
}