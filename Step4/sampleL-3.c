#include <stdio.h>
 
float pi = 3.14;
  
//関数の定義 
void calc(float r, float *area, float *len) {
    *area = pi * r * r;
    *len = pi * 2 * r;
}
 
void prt(float r, float s, float l) {
    printf("半径%.1fの円の面積は%.2f、円周の長さは%.2f\n", r, s, l);
}

//関数の呼び出し、実行 
int main() {
    float r = 10.0, s = 0, len = 0; //変数の初期化
    calc(r, &s, &len);
    prt(r, s, len);
 
    return 0;
}