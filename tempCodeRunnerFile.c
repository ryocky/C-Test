#include <stdio.h>

/*配列の初期化関数*/
int initial_array(int price[5][4]){
	int i, j;

	for(i=0; i<5; i++){
		for(j=0; j<4; j++){
			price[i][j] = 0;
		}
	}

	return(0);
}

/*商品５個の原価入力*/
int input_mod(int price[5][4]){
	int i;

	for(i=0; i<5; i++){
		printf("%d個目の商品の原価を入力してください\n", i+1);
		scanf("%d", &price[i][0]);

	}
	return(0);
}

/*売価・消費税・税込み価格の計算*/
int calc_mod(int price[5][4]){
	int i;
	for(i=0; i<5; i++){
		price[i][1] = (int)(price[i][0] * 1.3);
		price[i][2] = (int)(price[i][1] * 0.1);
		price[i][3] = price[i][1] + price[i][2];
	}
	return(0);
}

/*価格表の表示*/
int print_price(int price[5][4]){
	int i;

	printf("原価      :");
	for(i=0; i<5; i++){
		printf("%6d :", price[i][0]);
	}

	printf("\n売価      :");
	for(i=0; i<5; i++){
		printf("%6d :", price[i][1]);
	}

	printf("\n消費税    :");
	for(i=0; i<5; i++){
		printf("%6d :", price[i][2]);
	}

	printf("\n税込み価格:");
	for(i=0; i<5; i++){
		printf("%6d :", price[i][3]);
	}
	printf("\n");

	return(0);
}

int main(){
	int price[5][4];

	/*初期化*/
	initial_array(price);

	/*原価入力*/
	input_mod(price);

	/*売価・消費税・税込み価格の計算*/
	calc_mod(price);

	/*価格表の表示*/
	print_price(price);

	return(0);
}
