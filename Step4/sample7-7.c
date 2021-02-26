#include <stdio.h>

int function2(int a, int b, int x){
    printf("a + b + c = %d\n", a+b+x);
    printf("c - a - b = %d\n", x-a-b);

    return(0);
}

int main(){
    int a,b,c;
    a = 10; b = 20; c = 40;

    function2(a, b, c);

    return(0);
}