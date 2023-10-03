#include <stdio.h>

#define ADD(a, b) a + b
#define SUB(a, b) a - b
#define DIV(a, b) (float)a / b
#define MUL(a, b) a * b

typedef int int32_t;


int main()
{
	int32_t a, b, option;

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
		scanf("%d", &option);

		if (option == 5)
			break;

		printf("\nEnter a:");
		scanf("%d", &a);
						 
		printf("Enter b:");
		scanf("%d", &b);
		
		switch(option)
		{

			case 1:	 printf("\nThe sum of %d and %d is %d", a, b, ADD(a, b));
					 break;

			case 2 : printf("\nThe difference of %d and %d is %d", a, b, SUB(a, b));
					 break;

			case 3 : printf("\nThe quotient of %d and %d is %f", a, b, DIV(a, b));
					 break;

			case 4 : printf("\nThe product of %d and %d is %d", a, b, MUL(a, b));
					 break;
				
			default : printf("\nInvalid option.\n");
		}
	}

	return 0;
}
