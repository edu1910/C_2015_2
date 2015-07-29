#include <stdio.h>

int main(void)
{
	unsigned short num1 = 0;
	unsigned short num2 = 1;

	printf("\nSequência: 0 ");

	do
	{
		printf("%u ", num2);
		num2 += num1;
		num1  = num2 - num1;
	} while (num2 <= 10000);

	printf("\n\n");

	return 0;
}
