#include <stdio.h>
 
// 関数ポインタの宣言
typedef int (*foAO)(int x, int y);
 
/*関数ポインタに代入する関数を定義
  関数ポインタの引数の型と引数の数を統一*/
int sum(int x, int y){
    return x + y;
}

int mns(int x, int y){
    return x - y;
}
 
int mul(int x, int y){
    return x * y;
}

int div(int x, int y){
    return x / y;
}
 
int main() {
    int x, y, result;
    foAO c; //foAO型関数ポインタのオブジェクトを生成
    
    x = 10;
    y = 2;
    printf("x:%d, y:%d\n", x, y);
    
    c = &sum; //関数ポインタに関数アドレスを代入
    result = c(x, y); //関数ポインタより関数の呼び出し
    printf("x + y = %d\n", result);
    
    c = &mns;
    result = c(x, y);
    printf("x - y = %d\n", result);

    c = &mul;
    result = c(x, y);
    printf("x * y = %d\n", result);

    c = &div;
    result = c(x, y);
    printf("x / y = %d\n", result);
 
    return 0;
}