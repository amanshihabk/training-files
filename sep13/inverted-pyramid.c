#include <stdio.h>

typedef int int32_t;


int main()
{
	int32_t depth;

	printf("\nEnter the depth:");
	scanf("%d", &depth);


	for (int i = 0; i < depth; i++)
	{
		printf("\n");

		for (int j = 0; j < i; j ++)
			printf(" ");

		for (int k = 0; k < depth - i; k++)
		{
			printf("* ");
		}
	}

	printf("\n");

	return 0;
}
