#include <stdio.h>

typedef int int32_t;

int32_t varx = 99;

extern int32_t test();

extern int32_t test()
{

	printf("\nHello wolrd!\n");

	return 0;
}
