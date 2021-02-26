#include <stdio.h>
 
int main(void) {
    int num = 5; // int型普通の変数
    int *ptr_num; // int型ポインタ変数
    ptr_num = &num; // ポインタ変数ptr_numに変数numのアドレスを代入
    
    printf("int型変数numの値:%d\n", num);
    printf("int型ポインタ変数ptr_num:%p\n", ptr_num);
    printf("int型ポインタ変数p_numの参照先の値:%d\n", *ptr_num);

    return 0;
}