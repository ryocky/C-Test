#include <stdio.h>

int main(){
	char input[81];
	FILE *FP1, *FP2;

	/*ファイルから読み込みできるようにする*/
	if((FP1 = fopen("read.txt", "r")) == NULL){
		printf("読み込みファイルが開けません\n");
		return(1);
	}

	/*ファイルに書き込み出来るようにする*/
	if((FP2 = fopen("copy.txt", "w")) == NULL){
		printf("書き込みファイルが開けません\n");
		return(1);
	}

	/*繰り返し処理*/
	while(fgets(input, 81, FP1) != NULL){
		fprintf(FP2, "%s", input);
	}
	fclose(FP1);
	fclose(FP2);
	return(0);
}
