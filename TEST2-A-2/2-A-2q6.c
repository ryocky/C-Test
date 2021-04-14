/*問題6*/
#include <stdio.h>

int output_Alpha(char *n)
{
  printf("%c", *n);
  if((*n)++ != 'Z')
  {
    output_Alpha(n);
  }else
  {
      return(0);
  }
  return 0;
}

int main()
{
  char ch;
  ch = 'A';
  output_Alpha(&ch);
  
  return 0;
}