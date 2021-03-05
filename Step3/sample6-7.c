#include <stdio.h>
#include <string.h>

int main(){
	char input[3];

	/*質問の表示と解答入力*/
	printf("質問、正しいと思えばYes,誤っていると思えばNoと入力してください\n");
	gets(input);

	/*正解判定と結果表示*/
	if(strcmp(input, "Yes") == 0){
		printf("正解\n");
	}else{
		if(strcmp(input, "No") == 0){
			printf("不正解\n");
		}else{
			printf("入力が不適切\n");
		}
	}
	return(0);
}
