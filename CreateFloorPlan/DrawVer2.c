#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int roomsize_storage(int h, int w, char rect[h][w]);
int draw_room(int h, int w, char rect[h][w], int posX, int posY, int height, int width, char name[], int nameLength);
int output_modechange(int h, int w, char rect[h][w], int mode);


int output_OneRoom(int h, int w, char living_name[], 
            int kitchen_posX, int kitchen_posY, int kitchen_height, int kitchen_width, char kitchen_name[],
		    int bath_posX, int bath_posY, int bath_height, int bath_width, char bath_name[],
            int closet_posX, int closet_posY, int closet_height, int closet_width, char closet_name[],
            int entrance_posX, int entrance_posY, int entrance_height, int entrance_width, char entrance_name[],
            int mode)
{
	char rect[h][w];
    int i, j;
    
    /*部屋のサイズを配列に格納*/
    roomsize_storage(h, w, rect);

    /*居室の名前を配列に格納*/
    for(i = 0; i < strlen(living_name); i++)
    {
    	rect[(h-1)/2][w/3 - (strlen(living_name)/2) + i] = living_name[i];
    }

    /*キッチンの情報を配列に格納*/
    draw_room(h, w, rect, kitchen_posX, kitchen_posY, kitchen_height, kitchen_width, kitchen_name, strlen(kitchen_name));

    /*浴槽の情報を配列に格納*/
    draw_room(h, w, rect, bath_posX, bath_posY, bath_height, bath_width, bath_name, strlen(bath_name));

    /*クローゼットの情報を配列に格納*/
    draw_room(h, w, rect, closet_posX, closet_posY, closet_height, closet_width, closet_name, strlen(closet_name));

    /*玄関の情報を配列に格納*/
    draw_room(h, w, rect, entrance_posX, entrance_posY, entrance_height, entrance_width, entrance_name, strlen(entrance_name));

    output_modechange(h, w, rect, mode);
}



int output_1K(int h, int w,
            int living_posX, int living_posY, int living_height, int living_width, char living_name[],
            int kitchen_posX, int kitchen_posY, int kitchen_height, int kitchen_width, char kitchen_name[],
		    int bath_posX, int bath_posY, int bath_height, int bath_width, char bath_name[],
            int closet_posX, int closet_posY, int closet_height, int closet_width, char closet_name[],
            int entrance_posX, int entrance_posY, int entrance_height, int entrance_width, char entrance_name[],
            int mode)
{
	char rect[h][w];
    
    /*部屋のサイズを配列に格納*/
    roomsize_storage(h, w, rect);

    /*居室の情報を配列に格納*/
    draw_room(h, w, rect, living_posX, living_posY, living_height, living_width, living_name, strlen(living_name));

    /*キッチンの情報を配列に格納*/
    draw_room(h, w, rect, kitchen_posX, kitchen_posY, kitchen_height, kitchen_width, kitchen_name, strlen(kitchen_name));

    /*浴槽の情報を配列に格納*/
    draw_room(h, w, rect, bath_posX, bath_posY, bath_height, bath_width, bath_name, strlen(bath_name));

    /*クローゼットの情報を配列に格納*/
    draw_room(h, w, rect, closet_posX, closet_posY, closet_height, closet_width, closet_name, strlen(closet_name));

    /*玄関の情報を配列に格納*/
    draw_room(h, w, rect, entrance_posX, entrance_posY, entrance_height, entrance_width, entrance_name, strlen(entrance_name));

    output_modechange(h, w, rect, mode);
}

int output_1DK(int h, int w,
            int living_posX, int living_posY, int living_height, int living_width, char living_name[],
            int dining_posX, int dining_posY, int dining_height, int dining_width, char dining_name[],
            int kitchen_posX, int kitchen_posY, int kitchen_height, int kitchen_width, char kitchen_name[],
		    int bath_posX, int bath_posY, int bath_height, int bath_width, char bath_name[],
            int toilet_posX, int toilet_posY, int toilet_height, int toilet_width, char toilet_name[],
            int closet_posX, int closet_posY, int closet_height, int closet_width, char closet_name[],
            int entrance_posX, int entrance_posY, int entrance_height, int entrance_width, char entrance_name[],
            int mode)
{
	char rect[h][w];
    
    /*部屋のサイズを配列に格納*/
    roomsize_storage(h, w, rect);

    /*居室の情報を配列に格納*/
    draw_room(h, w, rect, living_posX, living_posY, living_height, living_width, living_name, strlen(living_name));

    /*ダイニングの情報を配列に格納*/   
    draw_room(h, w, rect, dining_posX, dining_posY, dining_height, dining_width, dining_name, strlen(dining_name));

    /*キッチンの情報を配列に格納*/
    draw_room(h, w, rect, kitchen_posX, kitchen_posY, kitchen_height, kitchen_width, kitchen_name, strlen(kitchen_name));

    /*浴槽の情報を配列に格納*/
    draw_room(h, w, rect, bath_posX, bath_posY, bath_height, bath_width, bath_name, strlen(bath_name));

    /*トイレの情報を配列に格納*/
    draw_room(h, w, rect, toilet_posX, toilet_posY, toilet_height, toilet_width, toilet_name, strlen(toilet_name));

    /*クローゼットの情報を配列に格納*/
    draw_room(h, w, rect, closet_posX, closet_posY, closet_height, closet_width, closet_name, strlen(closet_name));

    /*玄関の情報を配列に格納*/
    draw_room(h, w, rect, entrance_posX, entrance_posY, entrance_height, entrance_width, entrance_name, strlen(entrance_name));

    output_modechange(h, w, rect, mode);
}

int output_1LDK(int h, int w,
            int living_posX, int living_posY, int living_height, int living_width, char living_name[],
            int dining_posX, int dining_posY, int dining_height, int dining_width, char dining_name[],
            int kitchen_posX, int kitchen_posY, int kitchen_height, int kitchen_width, char kitchen_name[],
		    int bath_posX, int bath_posY, int bath_height, int bath_width, char bath_name[],
            int toilet_posX, int toilet_posY, int toilet_height, int toilet_width, char toilet_name[],
            int washroom_posX, int washroom_posY, int washroom_height, int washroom_width, char washroom_name[],
            int closet_posX, int closet_posY, int closet_height, int closet_width, char closet_name[],
            int entrance_posX, int entrance_posY, int entrance_height, int entrance_width, char entrance_name[],
            int mode)
{
	char rect[h][w];
    
    /*部屋のサイズを配列に格納*/
    roomsize_storage(h, w, rect);

    /*居室の情報を配列に格納*/
    draw_room(h, w, rect, living_posX, living_posY, living_height, living_width, living_name, strlen(living_name));

    /*ダイニングの情報を配列に格納*/   
    draw_room(h, w, rect, dining_posX, dining_posY, dining_height, dining_width, dining_name, strlen(dining_name));

    /*キッチンの情報を配列に格納*/
    draw_room(h, w, rect, kitchen_posX, kitchen_posY, kitchen_height, kitchen_width, kitchen_name, strlen(kitchen_name));

    /*浴槽の情報を配列に格納*/
    draw_room(h, w, rect, bath_posX, bath_posY, bath_height, bath_width, bath_name, strlen(bath_name));

    /*トイレの情報を配列に格納*/
    draw_room(h, w, rect, toilet_posX, toilet_posY, toilet_height, toilet_width, toilet_name, strlen(toilet_name));

    /*洗面所の情報を配列に格納*/
    draw_room(h, w, rect, washroom_posX, washroom_posY, washroom_height, washroom_width, washroom_name, strlen(washroom_name));

    /*クローゼットの情報を配列に格納*/
    draw_room(h, w, rect, closet_posX, closet_posY, closet_height, closet_width, closet_name, strlen(closet_name));

    /*玄関の情報を配列に格納*/
    draw_room(h, w, rect, entrance_posX, entrance_posY, entrance_height, entrance_width, entrance_name, strlen(entrance_name));

    output_modechange(h, w, rect, mode);
}




int output_modechange(int h, int w, char rect[h][w], int mode)
{
    FILE *FP;
    int i, j;
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
    /*配列の中身をファイルに出力*/
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

int roomsize_storage(int h, int w, char rect[h][w])
{
    int i, j;
    /*部屋のサイズを配列に格納*/
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

    return 0;
}

int draw_room(int h, int w, char rect[h][w], int posX, int posY, int height, int width, char name[], int nameLength){
    int i, j; 
    /*部屋の情報を配列に格納*/
    for(j = posY; j < height; j++)
    {
    	for(i = posX; i < width; i++)
    	{
    		if((i == posX) || (i == width-1) || (j == posY) || (j == height-1))
    			rect[j][i] = '*';
    		else
    			rect[j][i] = ' ';
    	}
    }

    for(i = 0; i < nameLength; i++)
    {
    	rect[posY +((height-posY)/2)][posX +((width-posX)/2) - (nameLength/2) + i] = name[i];
    }
    return 0;
}



int FileImport(int fileNo, int *roomInfo, int lineCount)
{
    FILE *FP;
    int fileType;
    char *filename;   
    int i, j;

    switch(fileNo)
    {
        case 1: filename = "OneRoom.csv"; fileType = 19; break;
        case 2: filename = "1K.csv"; fileType = 23; break;
        case 3: filename = "1DK.csv"; fileType = 31; break;
        case 4: filename = "1LDK.csv"; fileType = 35; break;
        default: break;
    }

    if((FP = fopen(filename, "r")) == NULL)
    {
        printf("ファイルが開けません\n");
        return 1;
    }

    for(j = 0; j < lineCount; j++)
    {
        for(i = 0; i < fileType; i++)
        {
            fscanf(FP, "%d", &roomInfo[i]);
        }
    }
    fclose(FP);

    return 0;
}

int main() {

    int roomInfo[35];
    int fileNo = 1;
    char selectFloor[3];
    int lineCount;
    int fileAddress;
    FILE *FP;

    lineCount = 0;

   
    FileImport(fileNo, roomInfo, lineCount+1);

    output_OneRoom(roomInfo[1], roomInfo[2], "Living", 
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Kitchen",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Bath",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Closet",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Entrance",0);

    /*output_1K(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Kitchen",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Bath",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Closet",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Entrance",0);*/


    /*output_1DK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
    	             roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Closet",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Entrance",0);*/
        
    /*output_1LDK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
                     roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Washroom",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Closet",
    	             roomInfo[31], roomInfo[32], roomInfo[33], roomInfo[34], "Entrance",0);*/



    /*output_1DK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
    	             roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Closet",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Entrance",1);*/
    return 0;
}