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

		for (int j = 0; j < depth - i - 1; j ++)
			printf(" ");

		for (int k = 0; k < i + 1; k++)
		{
			printf("* ");
		}
	}

	printf("\n");

	return 0;
}
