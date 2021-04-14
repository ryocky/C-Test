#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int draw_1DK(int h, int w, 
            int L_posX, int L_posY, int L_height, int L_width, char L_name[],
            int D_posX, int D_posY, int D_height, int D_width, char D_name[], 
            int K_posX, int K_posY, int K_height, int K_width, char K_name[],
		    int B_posX, int B_posY, int B_height, int B_width, char B_name[], 
            int T_posX, int T_posY, int T_height, int T_width, char T_name[],
            int C_posX, int C_posY, int C_height, int C_width, char C_name[],
            int E_posX, int E_posY, int E_height, int E_width, char E_name[])
{
	char rect[h][w];
    int i, j;
    /*居室の情報*/
    int lnameLength = strlen(L_name);

    /*ダイニングの情報*/
    int dnameLength = strlen(D_name);

    /*キッチンの情報*/
    int knameLength = strlen(K_name);

    /*浴槽の情報*/
    int bnameLength = strlen(B_name);

    /*トイレの情報*/
    int tnameLength = strlen(T_name);

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

    /*居室の情報を配列に格納*/
    for(j = L_posY; j < L_height; j++)
    {
    	for(i = L_posX; i < L_width; i++)
    	{
    		if((i == L_posX) || (i == L_width-1) || (j == L_posY) || (j == L_height-1))
    			rect[j][i] = '*';
    		else
    			rect[j][i] = ' ';
    	}
    }

    for(i = 0; i < lnameLength; i++)
    {
    	rect[L_posY +((L_height-L_posY)/2)][L_posX +((L_width-L_posX)/2) - (lnameLength/2) + i] = L_name[i];
    }

    /*ダイニングの情報を配列に格納*/
    for(j = D_posY; j < D_height; j++)
    {
    	for(i = D_posX; i < D_width; i++)
    	{
    		if((i == D_posX) || (i == D_width-1) || (j == D_posY) || (j == D_height-1))
    			rect[j][i] = '*';
    		else
    			rect[j][i] = ' ';
    	}
    }

    for(i = 0; i < dnameLength; i++)
    {
    	rect[L_posY +((D_height-D_posY)/2)][D_posX +((D_width-D_posX)/2) - (dnameLength/2) + i] = D_name[i];
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

    /*トイレの情報を配列に格納*/
    for(j = T_posY; j < T_height; j++)
    {
        for(i = T_posX; i < T_width; i++)
        {
        	if((i == T_posX) || (i == T_width-1) || (j == T_posY) || (j == T_height-1))
        		rect[j][i] = '*';
        	else
        		rect[j][i] = ' ';
        }
    }

    for(i = 0; i < tnameLength; i++)
    {
        rect[T_posY +((T_height-T_posY)/2)][T_posX +((T_width-T_posX)/2) - (tnameLength/2) + i] = T_name[i];
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
    printf("\n");
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

int FileImport(int num, int *roomInfo, int count){
    FILE *FP;
    int fileType;
    char *filename;
    //int roomInfo[34];
    char str[3];
    int i, j;

    switch(num)
    {
        case 1: filename = "OneRoom.csv"; fileType = 18; break;
        case 2: filename = "1K.csv"; fileType = 22; break;
        case 3: filename = "1DK.csv"; fileType = 30; break;
        case 4: filename = "1LDK.csv"; fileType = 34; break;
        default: break;
    }

    if((FP = fopen(filename, "r")) == NULL)
    {
        printf("ファイルが開けません\n");
        return 1;
    }

    for(j = 0; j < count; j++)
    {
        for(i = 0; i < fileType; i++)
        {
            fscanf(FP, "%d", &roomInfo[i]);
            //printf("%d ", roomInfo[i]);
        }
    }   
    fclose(FP);

    return 0;
}

int main() {

    int roomInfo[34];
   
    FileImport(1, roomInfo, 2);
    //draw_1DK(roomInfo[0], 100, 0, 0, 20, 36, "居室", 35, 0 , 20, 100, "ダイニング", 50, 13, 20, 75, "キッチン", 50, 0, 6, 75, "浴室", 74, 0, 6, 84, "トイレ", 15, 15, 20, 36, "収納", 90, 10, 15, 100, "玄関");
    draw_1DK(roomInfo[0], roomInfo[1], 
             roomInfo[2], roomInfo[3], roomInfo[4], roomInfo[5], "居室",
             roomInfo[6], roomInfo[7], roomInfo[8], roomInfo[9], "ダイニング",
             roomInfo[10], roomInfo[11], roomInfo[12], roomInfo[13], "キッチン",
             roomInfo[14], roomInfo[15], roomInfo[16], roomInfo[17], "浴室",
             roomInfo[18], roomInfo[19], roomInfo[20], roomInfo[21], "トイレ",
             roomInfo[22], roomInfo[23], roomInfo[24], roomInfo[25], "収納", 
             roomInfo[26], roomInfo[27], roomInfo[28], roomInfo[29], "玄関");

    return 0;
}