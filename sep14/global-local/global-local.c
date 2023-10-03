#include <stdio.h>

typedef unsigned char uint8_t;

uint8_t varx = 10;
uint8_t* ptr_varx_global = &varx;

int main()
{
	uint8_t varx = 50, temp;
	uint8_t* ptr_varx_local = &varx;

	printf("\nvarx locally is %d.", *ptr_varx_local);

	printf("\nvarx globally is %d", *ptr_varx_global);

	printf("\nSwapping varx locally and globally..");

	temp = *ptr_varx_global;
	*ptr_varx_global = *ptr_varx_local;
	*ptr_varx_local = temp;

	printf("\nvarx locally is %d.", varx);

	printf("\nvarx globally is %d\n", *ptr_varx_global);

	return 0;
}
