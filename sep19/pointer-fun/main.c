#include <stdio.h>

typedef unsigned char uint8_t;


int main()
{
	uint8_t cnt = 0;
	uint8_t arr[10] = {10, 20, 30, 40, 50};
	uint8_t *ptr = arr;

	while (cnt < 5)
	{
		printf("\nFirst : %d\n", *ptr++);
		printf("\nSecond : %d\n", ++*ptr);
		cnt ++;
	}

	return 0;
}
