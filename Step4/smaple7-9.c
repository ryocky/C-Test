#include <stdio.h>

int function3(int *a, int b){
        *a = *a + 5;
        printf("a + b = %d\n", *a+b);

        return(0);
}

int main(){
    
    int a, b;
    a = 10; b = 20;

    function3(&a, b);
    printf("a = %d\n", a);
    return(0);
}