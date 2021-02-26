#include <stdio.h>
 
float pi = 3.14;

//関数の定義
float *data(float *nums) {
    static float data[3];
    data[0] = nums[0];
    data[1] = pi * nums[0] * nums[0];
    data[2] = pi * 2 * nums[0];
    return data;
}
 
void prt(float r, float s, float l) {
    printf("半径%.1fの円の面積は%.2f、円周の長さは%.2f\n", r, s, l);
}

//関数の呼び出し、実行
int main() {
    //引数:ポインタ型(配列)
    float nums[3] = {10.0, 0, 0,};
    float *new_nums = data(nums);
    prt(new_nums[0], new_nums[1], new_nums[2]);
 
    return 0;
}
 