#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_STR_SIZE 50

int main()
{
	FILE *fptr;
	FILE *fptr_float;
	int8_t content[20];
	float ft;
	int8_t i1, i2;

	fptr = fopen("test.txt", "r+");

	fptr_float = fopen("float.txt", "r");

	while (fscanf(fptr, "%[^\n]%*c", content) != EOF)
	{
		printf("%s", content);
		fscanf(fptr, "%[^\n]%*c", content);
	}

	fscanf(fptr_float, "%hhd %f %hhd", &i1, &ft, &i2);

	printf("%d   %f   %d", i1, ft, i2);


	rewind(fptr);

	


	fclose(fptr);

	return 0;
}
