#include <stdio.h>

int main(void){
  short int a;
  short int b;

  a = 11;
  b = 14;

  printf("%d AND %d = %d\n", a, b, a & b);
  printf("%d OR %d = %d\n", a, b, a | b);
  printf("%d XOR %d = %\n", a, b, a ^ b);
  printf("NOT %d = %d\n", a, ~a);

  return 0;
}