#include <stdio.h>

typedef int int32_t;


int main()
{
	int32_t num, pos, shifted;

	printf("\nEnter a value:");
	scanf("%d", &num);

	printf("\nEnter a position:");
	scanf("%d", &pos);

	if (pos > 31)
	{
		printf("\nPlease enter values within range. Only 32 bit signed integer is supported (range -> 0 to 31)\n");
		return 0;
	}
	else
	{

		shifted = num >> pos;

		if (shifted & 1)
		{
			printf("\nThe bit is set.\n");
		}
		else
		{
			printf("\nThe bit is zero.\n");
		}
	}

	return 0;
}
