#include <stdio.h>
#include <string.h>

int main(){
	char input1[10], input2[10];

	/*質問の表示と解答入力*/
	printf("1つめの文字列を入力");
	gets(input1);
	printf("2つめの文字列を入力");
	gets(input2);

	/*文字列を繋ぎ合わせるか判定*/
	if((strlen(input1) + strlen(input2)) <= 10){
		/*文字列を繋ぎ合わせ、結果表示*/
		strcat(input1, input2);
		printf("%s\n", input1);
	}else{
		/*結果の表示*/
		printf("入力した文字列が長いので連結できません\n");
	}
	return(0);
}
