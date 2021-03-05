#include <stdio.h>

int main(){
    int ans;
    unsigned int a = 0x08 | 0x55;
    ans = a >> 3;

    printf("%d", ans);
}