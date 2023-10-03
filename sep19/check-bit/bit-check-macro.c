#include <stdio.h>

#if defined(_INT32)
typedef signed int int32_t;
#define SIZE 31

#elif defined(_UINT32)
typedef unsigned int uint32_t;
#define SIZE 32

#elif defined(_INT8)
typedef signed char int8_t;
#define SIZE 7

#elif defined(_UINT8)
typedef unsigned char uint8_t;
#define SIZE 8

#endif

int main()
{
	#if defined(_INT32)
	int32_t num, pos, shifted;

	#elif defined(_UINT32)
	uint32_t num, pos, shifted;

	#elif defined(_INT8)
	int8_t num, pos, shifted;

	#elif defined(_UINT8)
	uint8_t num, pos, shifted;

	#endif

	printf("\nEnter a value:");
	scanf("%d", &num);

	printf("\nEnter a position:");
	scanf("%d", &pos);

	if (pos > SIZE)
	{
		printf("\nPlease enter values within range. (range -> 0 to %d)\n", SIZE);
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
