#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_STR_SIZE 50

int main()
{
	FILE *fptr;
	int8_t *content;

	fptr = fopen("test.txt", "w");
	content = (int8_t *)malloc(sizeof(int8_t) * MAX_STR_SIZE); 

	printf("\nEnter some content to write into the file : ");
	scanf(" %[^\n]%*c", content);

	fprintf(fptr, "%s", content);

	return 0;
}
