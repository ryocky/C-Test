#include <stdio.h>

int main(){
    double inch, cm;
    int i; //100まで数えるための変数を用意
    inch = 2.54;

    for(i = 1; i <= 100; i++){
        cm = i*inch;
        printf("%3d inch : %.2lf\n", i, cm);
    }
    return(0);
}