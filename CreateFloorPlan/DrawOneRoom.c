#include <stdio.h>
#include <string.h>

int draw_OneRoom(int h, int w, char l_name[], 
                 int K_posX, int K_posY, int K_height, int K_width, char K_name[],
		         int B_posX, int B_posY, int B_height, int B_width, char B_name[], 
                 int C_posX, int C_posY, int C_height, int C_width, char C_name[],
                 int E_posX, int E_posY, int E_height, int E_width, char E_name[])
{
	char rect[h][w];
    int i, j;
    int lnameLength = strlen(l_name);

    /*キッチンの情報*/
    int knameLength = strlen(K_name);

    /*浴槽の情報*/
    int bnameLength = strlen(B_name);

    /*クローゼットの情報*/
    int cnameLength = strlen(C_name);

    /*玄関の情報*/
    int enameLength = strlen(E_name);

    for(j = 0; j < h; j++)
    {

        for(i = 0; i < w; i++)
        {
            if((i == 0) || (i == w-1) || (j == 0) || (j == h-1))
                rect[j][i] = '*';
            else
            {
                rect[j][i] = ' ';
            }
        }
        rect[j][i] = '\n';
    }

    /*居室の名前を配列に格納*/
    for(i = 0; i < lnameLength; i++)
    {
    	rect[(h-1)/2][w/3 - (lnameLength/2) + i] = l_name[i];
    }

    /*キッチンの情報を配列に格納*/
    for(j = K_posY; j < K_height; j++)
    {
    	for(i = K_posX; i < K_width; i++)
    	{
    		if((i == K_posX) || (i == K_width-1) || (j == K_posY) || (j == K_height-1))
    			rect[j][i] = '*';
    		else
    			rect[j][i] = ' ';
    	}
    }

    for(i = 0; i < knameLength; i++)
    {
    	rect[K_posY +((K_height-K_posY)/2)][K_posX +((K_width-K_posX)/2) - (knameLength/2) + i] = K_name[i];
    }

    /*浴槽の情報を配列に格納*/
    for(j = B_posY; j < B_height; j++)
    {
        for(i = B_posX; i < B_width; i++)
        {
        	if((i == B_posX) || (i == B_width-1) || (j == B_posY) || (j == B_height-1))
        		rect[j][i] = '*';
        	else
        		rect[j][i] = ' ';
        }
    }

    for(i = 0; i < bnameLength; i++)
    {
        rect[B_posY +((B_height-B_posY)/2)][B_posX +((B_width-B_posX)/2) - (bnameLength/2) + i] = B_name[i];
    }

    /*クローゼットの情報を配列に格納*/
    for(j = C_posY; j < C_height; j++)
    {
        for(i = C_posX; i < C_width; i++)
        {
        	if((i == C_posX) || (i == C_width-1) || (j == C_posY) || (j == C_height-1))
        		rect[j][i] = '*';
        	else
        		rect[j][i] = ' ';
        }
    }

    for(i = 0; i < cnameLength; i++)
    {
    	rect[C_posY +((C_height-C_posY)/2)][C_posX +((C_width-C_posX)/2) - (cnameLength/2) + i] = C_name[i];
    }

    /*玄関の情報を配列に格納*/
    for(j = E_posY; j < E_height; j++)
    {
        for(i = E_posX; i < E_width; i++)
        {
        	if((i == E_posX) || (i == E_width-1) || (j == E_posY) || (j == E_height-1))
        		rect[j][i] = '*';
        	else
        		rect[j][i] = ' ';
        }
    }

    for(i = 0; i < cnameLength; i++)
    {
    	rect[E_posY +((E_height-E_posY)/2)][E_posX +((E_width-E_posX)/2) - (enameLength/2) + i] = E_name[i];
    }

    /*配列の中身表示*/
    for(j = 0; j < h; j++)
    {

    	for(i = 0; i < w; i++)
    	{
    		printf("%c", rect[j][i]);
    	}
    	printf("\n");
    }

    return 0;
}

int main() {

    draw_OneRoom(16, 92, "居室", 40, 0, 8, 55, "キッチン", 54, 0, 8, 80, "浴室", 0, 10, 16, 15, "収納", 85, 10, 16, 92, "玄関");
    return 0;
}
