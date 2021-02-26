#include <stdio.h>

int fcl(int n)
{
  int m;

  if (n == 0)
    return 1; //0! = 1
  /*nが0でないとき*/
  m = fcl(n - 1); //(n-1)!を求めてそれをmとおく。ここのfcl(n-1)が再帰呼出し。
  return n * m;   //n! = n * m
}

int main()
{
  int i, num;

  scanf("%d", &i);
  num = fcl(i);
  printf("%dの階乗は%dです。\n", i, num);
  return 0;
}