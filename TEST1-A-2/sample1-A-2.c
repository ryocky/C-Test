#include <stdio.h>

int main(void)
{
	int total, i, j;

	total = 0;
	do {
		printf("数を入力してください (０で終了)：");
		scanf("%d", &i);
		printf("もう一度、同じ数を入力してください：");
		scanf("%d", &j);
		if (i != j) {
			printf("入力した数が合致しません\n");
            continue;
		}
		total = total + i ;
	} while ((i != 0) || (j != 0));
	printf("合計： %d\n",total);

	return 0;
}
