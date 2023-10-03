#include <stdio.h>

typedef int int32_t;

int32_t test();

int main()
{
	extern int32_t varx;
	printf("%d", varx);

	test();

	return 0;
}
