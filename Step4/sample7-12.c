#include <stdio.h>

int function4(int a[2]){
    a[0] = a[0] + 10;
    printf("x[0] + x[1] = %d\n", a[0] + a[1]);

    return(0);
}

int main(){
    int x[2];
    x[0] = 10; x[1] = 20;
    function4(x);

    printf("x[0] = %d\n", x[0]);
    return(0);
}