#include <stdio.h>

typedef unsigned char int8_t;
typedef int int32_t;


int main()
{
	int8_t name[10];
	int32_t size;

	printf("\nEnter the length of your name:");
	scanf("%d", &size);

	printf("\nEnter your name(max len = %d):", size);
	int i = 0;
	for (i = 0; i < size; i++)
	{
		scanf(" %c", &name[i]);
	}

	for (int i = 0; i < size; i++)
	{
		printf("\nCharacter at index %d : %c", i, name[i]);
	}

	printf("\n");

	return 0;
}
