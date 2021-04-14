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
            int E_posX, int E_posY, int E_height, int E_width, char E_name[],
            int mode)
{
	char rect[h][w];
    int i, j;
    FILE *FP;

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

    for(i = 0; i < enameLength; i++)
    {
    	rect[E_posY +((E_height-E_posY)/2)][E_posX +((E_width-E_posX)/2) - (enameLength/2) + i] = E_name[i];
    }

    //mode0
    if(mode == 0){
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
    }else if(mode == 1)
    {

    //mode1
    /*配列の中身出力*/
    FP = fopen("FloorPlan.txt", "a");
    for(j = 0; j < h; j++)
    {

    	for(i = 0; i < w; i++)
    	{
    		fprintf(FP, "%c", rect[j][i]);
    	}
    	fputc('\n', FP);
    }
    fclose(FP);
    }
    return 0;
}


int fileCountLine(char *filename){
    FILE *FP;
    int c;
    int count = 0;

    if((FP = fopen(filename, "r")) == NULL)
    {
        printf("ファイルが開けません\n");
        return 1;
    }
    
    if(FP) {
        while((c = getc(FP)) != EOF) {
        if(c == '\n') count++;
        }
    fclose(FP);
    }
    
    return count;
}



int FileImport(int fileType, int *roomInfo, int *lineCount)
{
    FILE *FP;
    int numCount;
    char *filename;   
    int i, j;

    switch(fileType)
    {
        case 1: filename = "OneRoom.csv"; numCount = 19; break;
        case 2: filename = "1K.csv"; numCount = 23; break;
        case 3: filename = "1DK.csv"; numCount = 31; break;
        case 4: filename = "1LDK.csv"; numCount = 35; break;
        default: break;
    }
    if(fileCountLine(filename) < *lineCount)
    {
        *lineCount = 1;
    }

    FP = fopen(filename, "r");
    
    for(j = 0; j < *lineCount; j++)
    {
        for(i = 0; i < numCount; i++)
        {
            fscanf(FP, "%d", &roomInfo[i]);
        }
    }
    fclose(FP);

    return 0;
}

int FileUpdate(int fileType, int lineCount)
{
	FILE *FP;
	int numCount;
	char *filename;
    int tmp;
	int i, j, k;

	switch(fileType)
	{
		case 1: filename = "OneRoom.csv"; numCount = 19; break;
	    case 2: filename = "1K.csv"; numCount = 23; break;
	    case 3: filename = "1DK.csv"; numCount = 31; break;
	    case 4: filename = "1LDK.csv"; numCount = 35; break;
	    default: break;
	}

    int fileInfo[numCount];
    int lastLine = fileCountLine(filename);
    int fileInfoAll[lastLine][numCount];

	FP = fopen(filename, "r");
    i = 0;
    j = 0;
	
    while(! feof(FP))
    {
        fscanf(FP, "%d", &fileInfo[i]);
        fileInfoAll[j][i] = fileInfo[i];
        i++;
        if(i == numCount)
        {
            i = 0;
            j++;
        }
    }
	fclose(FP);

    fileInfoAll[lineCount-1][0] += 1;
    if(fileInfoAll[lineCount-1][0] >= 100)
    {
        for(i = 0; i < lastLine; i++)
        {
            fileInfoAll[i][0] = fileInfoAll[i][0] * 0.5;
        }
    }
    
    /*降順にソート*/
    for(j = 0; j < lastLine; j++)
    {
        for(i = 0; i < lastLine; i++)
        {
            if(fileInfoAll[i][0] < fileInfoAll[j][0])
            {
                for(k = 0; k < numCount; k++)
                {
                    tmp = fileInfoAll[i][k];
                    fileInfoAll[i][k] = fileInfoAll[j][k];
                    fileInfoAll[j][k] = tmp;
                }
            }
        }
    }

    FP = fopen(filename, "w");
    for(j = 0; j < lastLine; j++)
    {
        for(i = 0; i < numCount; i++)
        {
            fprintf(FP, "%d ", fileInfoAll[j][i]);
        }
        fputc('\n', FP);
    }
    fclose(FP);

	return 0;
}

int main() {

    int roomInfo[35];
    int roomType = 3;
    char selectFloor[5] = {0};
    int lineCount;
    //int fileAddress;
    FILE *FP;

    lineCount = 1;

    do
    {
    	FileImport(roomType, roomInfo, &lineCount);
    	draw_1DK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
    	             roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Closet",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Entrance",0);
        printf("\nこの間取りはどうですか？ 1: 変更 0:決定\n");
        do{
            fgets(selectFloor, sizeof(selectFloor), stdin);
             if(!(selectFloor[0] == '1') && !(selectFloor[0] == '0') || (strlen(selectFloor) > 2))
            {
                selectFloor[0] = '\0';
                printf("もう一度入力してください。\n");
            }
        }while(!(selectFloor[0] == '1') && !(selectFloor[0] == '0') || (strlen(selectFloor) > 2));

    	if((selectFloor[0] == '0') && (strlen(selectFloor) == 2))
    	{
    		FileUpdate(roomType, lineCount);
    	}else if(selectFloor[0] == '1' && (strlen(selectFloor) == 2))
        {
            lineCount += 1;
            
        }
        
    }while(!(selectFloor[0] == '0'));

    

    /*draw_1DK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
    	             roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Closet",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Entrance",1);*/
    return 0;
}
