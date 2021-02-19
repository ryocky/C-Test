#include <stdio.h>

int main(){
    int ans1, ans2;
    int total;

    printf("通勤時は（1:車 2:自転車 3:歩き）で行きますか？\n");
    scanf("%d", &ans1);

    printf("運動は（1:していません 2:たまにする 3:良くする）\n");
    scanf("%d", &ans2);

    total = ans1+ans2;

    if(total < 4){
        printf("運動不足です\n");
    }else{
        printf("良く運動しています\n");
    }

    if(total == 2){
        printf("もっと運動してください\n");
    }
    return(0);
}