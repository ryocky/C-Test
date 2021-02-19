#include <stdio.h>

int main(){

   /*printfの様々な使いかた*/
   printf("10/3=%d\n", 10/3);//①
   printf("10/3=%f\n", 10.0/3.0);//②
   printf("10/3=%lf\n", 10.0/3.0);//③

   printf("7+1=%3d\n", 7+1);//④
   printf("7*9=%3d\n", 7*9);//⑤
   printf("7/3=%.3f\n", 7.0/3.0);//⑥

   return(0); 
}