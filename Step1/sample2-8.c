#include <stdio.h>

int main(){
    /*変数を用意*/
    int total; //①

    total = (10*8+15*5)*105/100; //②

    /*10000でのお釣り表示*/
    printf("10000: %d\n", 10000-total); //③
    /*5000でのお釣り表示*/
    printf("5000: %d\n", 5000-total);
    /*1000でのお釣り表示*/
    printf("1000: %d\n", 1000-total);

    return(0);
}