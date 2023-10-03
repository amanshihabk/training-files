#include "strings.h"
#include <stdio.h>
#include <stdlib.h>


int main()
{
	int8_t *tell;
	tell = (int8_t *)malloc(sizeof(char) * MAX_STR_LEN);

	printf("\nEnter value for tell : ");
	scanf(" %[^\n]%*c", tell);

	int8_t *reved;
	reved = (int8_t *)malloc(sizeof(char) * MAX_STR_LEN);
	printf("Hello");
	ReverseString(reved, tell);
	printf("\n Reved = %s\n", reved);

	int8_t *concated = StrConcatinate(tell, reved);
	printf("tell and reved concated : \n%s\n", concated);

	int8_t *destination;
	destination = (int8_t *)malloc(sizeof(char) * MAX_STR_LEN);
	SetBuffer(concated, destination);
	printf("\nCopying concatenated string %s to dest : %s\n", concated, destination);

	ClrBuffer(reved, 2);

	return 0;
}
