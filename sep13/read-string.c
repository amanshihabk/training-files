#include <stdio.h>

typedef char int8_t;


int main()
{
	int8_t name[20];

	printf("\nEnter your name(max len = 10):");
	scanf(" %[^\n]%*c", name);

	printf("\nYour name is %s.", name);

	for (int i = 0; name[i] != '\0'; i++)
	{
		printf("\nCharacter at index %d : %c", i, name[i]);
	}

	printf("\n");

	return 0;
}
