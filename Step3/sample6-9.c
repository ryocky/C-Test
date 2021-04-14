#include <stdio.h>
#include <string.h>

int main(){
	char name[10][22];
	char phone[10][13];
	char input[21];
	int i;
	FILE *FP;

	/*ファイルのオープン*/
	if((FP = fopen("address.txt", "r")) == NULL){
		printf("ファイルが開けません\n");
		return(1);
	}

	/*ファイルからデータを読み込む*/
	for(i = 0; i < 10; i++){
		fgets(name[i], 22, FP);
		/*読み込んだ文字の最後にある改行を消す*/
		name[i][strlen(name[i])-1] = '\0';
		printf("名前%d:%s\n",i+1 ,name[i]);
		/*電話番号の読み込み*/
		fgets(phone[i], 13, FP);
		/*読み込んだ文字の最後にある改行を消す*/
		phone[i][strlen(phone[i])-1] = '\0';
	}

	/*電話番号を検索したい名前の入力*/
	printf("電話番号を検索したい名前を入力してください\n");
	gets(input);
	/*検索と表示*/
	for(i = 0; i < 10; i++){
		if(strcmp(name[i], input) == 0){
			/*電話番号表示*/
			printf("%sさんの電話番号は:%s\n", input, phone[i]);
		}
	}
	fclose(FP);
	return(0);
}
