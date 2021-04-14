#include <stdio.h>

int draw_Rect(int h, int w)
{
    int i, j;
    for(j = 0; j < h; j++){
        
        for(i = 0; i < w; i++)
        {
            if((i == 0) || (i == w-1) || (j == 0) || (j == h-1))
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main() {

    draw_Rect(12, 50);
    return 0;
}