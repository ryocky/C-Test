/*1人暮らし用部屋探しツール 2021.04.05 岡本 遼*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ユーザー情報を管理する構造体
typedef struct 
{
    char name[50];//名前
    char mail[50];//メールアドレス
    char phone[50];//携帯番号
    
}personal_data;

//建物情報を管理する構造体
typedef struct 
{
    char houseRent[80];//家賃
    char others[80];//その他
    char roomType[20];//建物種別

}building_info;

//関数の宣言
int roomsize_storage(int h, int w, char rect[h][w]);
int draw_room(int h, int w, char rect[h][w], int posX, int posY, int height, int width, char name[], int nameLength);
int output_modechange(int h, int w, char rect[h][w], int mode);

//ユーザー情報入力用関数
int input_personal_data()
{
    personal_data data = {0};
    char checkData[10] = {0};
    FILE *FP;

//名前、メールアドレス、携帯番号の入力
    while(strlen(data.name) == 0 && strlen(data.mail) == 0 && strlen(data.phone) == 0)
    {
        printf("名前を入力してください。:");
        do{
            fgets(data.name, sizeof(data.name), stdin);
            if(strlen(data.name) >= 20)
            {
                data.name[0] = '\0';
                printf("名前が長すぎます。修正してください。\n");
            }
        }while(strlen(data.name) == 0);
    
        printf("メールアドレスを入力してください:");
        do{
            fgets(data.mail, sizeof(data.mail), stdin);
            if(strlen(data.mail) >= 20)
            {
                data.mail[0] = '\0';
                printf("メールアドレスが長すぎます。修正してください。\n");
            }
        }while(strlen(data.mail) == 0);

        printf("携帯番号を入力してください:");
        do{
            fgets(data.phone, sizeof(data.phone), stdin);
            if(strlen(data.phone) >= 15)
            {
            data.phone[0] = '\0';
            printf("携帯番号が長すぎます。修正してください。\n");
            }
        }while(strlen(data.phone) == 0);
        
        //入力内容の再確認を行う
        printf("\n入力内容をご確認ください。\n");
        printf("%s", data.name);
        printf("%s", data.mail);
        printf("%s", data.phone);
        printf("次の入力を行ってください。1:修正 0:次へ進む\n");
        do{
            
            fgets(checkData, sizeof(checkData), stdin);
            if((!(checkData[0] == '1') && !(checkData[0] == '0')) || (strlen(checkData) > 2))
            {
                checkData[0] = '\0';
                printf("もう一度入力してください。\n");
            }

        }while(!(checkData[0] == '1') && !(checkData[0] == '0') || (strlen(checkData) > 2));
        if(checkData[0] == '1' && (strlen(checkData) == 2))
        {
            //入力内容の初期化
            data.name[0] = '\0';
            data.mail[0] = '\0';
            data.phone[0] = '\0';
            checkData[0] = '\0';
        }
    }

    //ファイルを作成し、ユーザー情報を出力する
    FP = fopen("FloorPlan.txt", "w");
    fprintf(FP, "名前:%s", data.name);
    fprintf(FP, "メールアドレス:%s", data.mail);
    fprintf(FP, "携帯番号:%s", data.phone);
    fclose(FP);
    return 0;
}

//建物情報入力用関数
int input_building_info(int roomType)
{
    building_info data = {0};
    FILE *FP;

    //希望家賃、その他要望、部屋タイプの入力
    while(strlen(data.houseRent) == 0 && strlen(data.others) == 0 && strlen(data.roomType) == 0)
    {
        printf("\n希望家賃はいくらですか？:");
        do{
            fgets(data.houseRent, sizeof(data.houseRent), stdin);
            if(strlen(data.houseRent) >= 50)
            {
                data.houseRent[0] = '\0';
                printf("文字が長すぎます。修正してください。\n");
            }
        }while(strlen(data.houseRent) == 0);

        printf("その他の要望はありますか？:");
        do{
            fgets(data.others, sizeof(data.others), stdin);
            if(strlen(data.others) >= 50)
            {
                data.others[0] = '\0';
                printf("文字が長すぎます。修正してください。\n");
            }
        }while(strlen(data.others) == 0);

        //番号によって部屋タイプが決定
        switch (roomType)
        {
            case 1: strcpy(data.roomType, "OneRoom"); break;
            case 2: strcpy(data.roomType, "1K"); break;
            case 3: strcpy(data.roomType, "1DK"); break;
            case 4: strcpy(data.roomType, "1LDK"); break;
            default: break;
        }
    }
    
    //ファイルに建物情報を追加
    FP = fopen("FloorPlan.txt", "a");
    fprintf(FP, "希望家賃:%s", data.houseRent);
    fprintf(FP, "要望:%s", data.others);
    fprintf(FP, "希望の部屋タイプは%sです。\n", data.roomType);
    fclose(FP);
    
    return 0;
}

//ファイル内の行数をカウントする関数
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
        //ファイル内の終端までカウント
        while((c = getc(FP)) != EOF) {
        if(c == '\n') count++;
        }
    fclose(FP);
    }
    
    //カウントした数値を返す
    return count;
}

//間取り情報を保存しているファイルから数値を取得する関数
int fileImport(int roomType, int *roomInfo, int *lineCount)
{
    FILE *FP;
    int numCount = 0;
    char *filename;   
    int i, j;

    switch(roomType)
    {
        case 1: filename = "OneRoom.csv"; numCount = 19; break;
        case 2: filename = "1K.csv"; numCount = 23; break;
        case 3: filename = "1DK.csv"; numCount = 31; break;
        case 4: filename = "1LDK.csv"; numCount = 35; break;
        default: break;
    }
    //ファイルの行数を超える行を読み取ろうとしたら最初の行に変更
    if(fileCountLine(filename) < *lineCount)
    {
        *lineCount = 1;
    }

    FP = fopen(filename, "r");
    
    //ファイルの特定の行の数値を取得する
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

//ファイルの中身を更新する関数
int fileUpdate(int roomType, int lineCount)
{
	FILE *FP;
	int numCount = 0;
	char *filename;
    int tmp;
	int i, j, k;

	switch(roomType)
	{
		case 1: filename = "OneRoom.csv"; numCount = 19; break;
	    case 2: filename = "1K.csv"; numCount = 23; break;
	    case 3: filename = "1DK.csv"; numCount = 31; break;
	    case 4: filename = "1LDK.csv"; numCount = 35; break;
	    default: break;
	}

    int fileInfo[numCount];
    int lastLine = fileCountLine(filename); //ファイルの終端行の数値
    int fileInfoAll[lastLine][numCount]; //間取り情報を全て保存

	FP = fopen(filename, "r");
    i = 0;
    j = 0;
	
    //ファイル内の全ての数値を二次元配列として格納
    while(! feof(FP))
    {
        fscanf(FP, "%d", &fileInfo[i]);
        //一次元配列から二次元配列へ
        fileInfoAll[j][i] = fileInfo[i];
        i++;
        if(i == numCount)
        {
            i = 0;
            j++;
        }
    }
	fclose(FP);
    //ファイル内の間取りのランクを変更
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
    //ファイルに更新した数値を上書きして保存
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

//ワンルームの間取り出力をする関数
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

    /*コンソール出力かファイル出力か変更*/
    output_modechange(h, w, rect, mode);

    return 0;
}

//1Kの間取りの出力をする関数
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

    /*コンソール出力かファイル出力か変更*/
    output_modechange(h, w, rect, mode);

    return 0;
}

//1DKの間取りの出力をする関数
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

    /*コンソール出力かファイル出力か変更*/
    output_modechange(h, w, rect, mode);
   
    return 0;
}

//1LDKの間取りの出力をする関数
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

    /*コンソール出力かファイル出力か変更*/
    output_modechange(h, w, rect, mode);

    return 0;
}

//部屋全体の描画情報を保存する関数
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

//各部屋の描画情報格納する関数
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

    //部屋名を配列に格納
    for(i = 0; i < nameLength; i++)
    {
    	rect[posY +((height-posY)/2)][posX +((width-posX)/2) - (nameLength/2) + i] = name[i];
    }
    return 0;
}

//部屋の間取りの出力先を変更する関数
int output_modechange(int h, int w, char rect[h][w], int mode)
{
    FILE *FP;
    int i, j;
    //mode0
    if(mode == 0){
    /*配列の中身をコンソール画面に表示*/
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

int main()
{
    char roomType[10] = {0}; //部屋タイプの番号
    char selectFloor[3] = {0}; //間取りの選択数値
    int roomInfo[35]; //部屋の間取りの数値
    int lineCount = 1; //ファイルの行数

    //ユーザー情報の入力
    input_personal_data();
    printf("希望のルームを選択肢から選んでください。\n");
    printf("1:OneRoom(8~10畳) 2:1K(10~13畳) 3:1DK(15~17畳) 4:1LDK(18~20畳)\n");
    do{
        fgets(roomType, sizeof(roomType), stdin);
        if(!(roomType[0] == '1') && !(roomType[0] == '2') && !(roomType[0] == '3')&& !(roomType[0] == '4')|| (strlen(roomType) > 2))
        {
            roomType[0] = '\0';
            printf("もう一度入力してください。\n");
        }
    }while(!(roomType[0] == '1') && !(roomType[0] == '2') && !(roomType[0] == '3')&& !(roomType[0] == '4')|| (strlen(roomType) > 2));

    //建物情報の入力
    input_building_info(atoi(roomType));
    do
    {
        //ファイルの情報を受け取る
        fileImport(atoi(roomType), roomInfo, &lineCount);

        //出力する間取りを決定
        switch(atoi(roomType))
        {   
            case 1: output_OneRoom(roomInfo[1], roomInfo[2], "Living", 
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Kitchen",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Bath",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Closet",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Ent",0);
                break;

            case 2: output_1K(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Kitchen",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Bath",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Closet",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Ent",0);
                break;

            case 3: output_1DK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
    	             roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Closet",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Ent",0);
                break;
        
            case 4: output_1LDK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
                     roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Washroom",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Closet",
    	             roomInfo[31], roomInfo[32], roomInfo[33], roomInfo[34], "Ent",0);
                break;
        default: break;
        }

        //間取りの選択を行う
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
            //ファイルの情報更新
    		fileUpdate(atoi(roomType), lineCount);
    	}else if(selectFloor[0] == '1' && (strlen(selectFloor) == 2))
        {
            lineCount += 1;
        }
    }while(!(selectFloor[0] == '0'));

    printf("\nお部屋検索情報をファイルに出力しました。\n");
    //ファイルに間取り情報を出力する
    switch(atoi(roomType))
        {   
            case 1: output_OneRoom(roomInfo[1], roomInfo[2], "Living", 
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Kitchen",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Bath",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Closet",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Ent",1);
                break;

            case 2: output_1K(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Kitchen",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Bath",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Closet",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Ent",1);
                break;

            case 3: output_1DK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
    	             roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Closet",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Ent",1);
                break;
        
            case 4: output_1LDK(roomInfo[1], roomInfo[2],
    	             roomInfo[3], roomInfo[4], roomInfo[5], roomInfo[6], "Living",
    	             roomInfo[7], roomInfo[8], roomInfo[9], roomInfo[10], "Dining",
    	             roomInfo[11], roomInfo[12], roomInfo[13], roomInfo[14], "Kitchen",
    	             roomInfo[15], roomInfo[16], roomInfo[17], roomInfo[18], "Bath",
    	             roomInfo[19], roomInfo[20], roomInfo[21], roomInfo[22], "Toilet",
                     roomInfo[23], roomInfo[24], roomInfo[25], roomInfo[26], "Washroom",
    	             roomInfo[27], roomInfo[28], roomInfo[29], roomInfo[30], "Closet",
    	             roomInfo[31], roomInfo[32], roomInfo[33], roomInfo[34], "Ent",1);
                break;
        default: break;
        }

    return(0);
}