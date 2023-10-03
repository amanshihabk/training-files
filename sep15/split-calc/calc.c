#include <stdio.h>
#include "funcs.h"


int main()
{
	int8_t option;
	int32_t a, b;

	while (1)
	{
		printf("\n\nCalculator:");
		printf("\n------------");
		printf("\n1. Addition");
		printf("\n2. Subtraction");
		printf("\n3. Division");
		printf("\n4. Multiplication");
		printf("\n5. Exit\n");
	
		printf("\nEnter your choice:");
		scanf("%hhd", &option);

		if (option == 5)
		{
			break;
		}

		printf("\nEnter a:");
		scanf("%d", &a);

		printf("Enter b:");
		scanf("%d", &b);

		switch(option)
		{

			case 1:	 printf("\nThe sum of %d and %d is %d", a, b, add(a, b));
					 break;

			case 2 : printf("\nThe difference of %d and %d is %d", a, b, subtract(a, b));
					 break;

			case 3 : printf("\nThe quotient of %d and %d is %f", a, b, divide((float)a, (float)b));
					 break;

			case 4 : printf("\nThe product of %d and %d is %d", a, b, multiply(a, b));
					 break;

			default : printf("\nInvalid option.\n");
		}
	}

	return 0;
}
