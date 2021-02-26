#include <stdio.h>

int main(){

    char input;

    /*初期化*/
    input = '\0';

    /*入力*/
    scanf("%c", &input);

    /*小文字英文字の判定*/
    if((input >= 'a') && (input <= 'z')){  //①
    	printf("小文字英字です。\n");
    }else{
    	/*大文字英字の判定*/
    	if((input >= (char)65) && (input <= (char)90)){  //②
    		printf("大文字英字です。\n");
    	}else{
    		printf("英字以外の文字です。\n");
    	}
    }
    return(0);
}
