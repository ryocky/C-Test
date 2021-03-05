#include <stdio.h>

int xor(int a, int b);

int main(void)
{
	int p, q;

	printf("Pは? (0または1): ");
	scanf("%d", &p);
	printf("Qは? (0または1): ");
	scanf("%d", &q);
	printf("P AND Q: %d\n", p && q);
	printf("P OR Q: %d\n", p || q);
	printf("P XOR Q: %d\n", xor(p,q)); 

	return 0;
}

int xor(int a, int b)
{
	~(a & b) && !(a ^ ~b);
}


