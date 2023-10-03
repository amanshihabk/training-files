#include <stdio.h>

typedef unsigned int int32_t;



int main()
{
	int32_t a, b;
	int32_t *ptr_a = &a, *ptr_b = &b; 


	printf("\nAddress of variable A is %x.", ptr_a);
	printf("\nAddress of variable B is %x.", ptr_b);

	printf("\nAddress of pointer to A is %x.", &ptr_a);	
	printf("\nAddress of pointer to B is %x.", &ptr_b);

	while (1)
	{
		printf("\n\nCalculator:");
		printf("\n------------");
		printf("\n1. Addition");
		printf("\n2. Subtraction");
		printf("\n3. Division");
		printf("\n4. Multiplication");
		printf("\n5. Exit\n");
	
		int32_t option;
		int32_t *ptr_option = &option;

		
		printf("\nAddress of variable option is %x.", ptr_option);
		printf("\nAddress of pointer to option is %x.", &ptr_option);

		printf("\nEnter your choice:");
		scanf("%d", ptr_option);

		if (*ptr_option == 5)
			break;
		else
				// Do Nothing

		printf("\nEnter a:");
		scanf("%d", ptr_a);
						 
		printf("Enter b:");
		scanf("%d", ptr_b);

		printf("\nValue at ptr_a is %u.", *ptr_a);
		printf("\nValue at ptr_b is %u.", *ptr_b);
		printf("\nValue at ptr_option is %u.", *ptr_option);
		
		switch(*ptr_option)
		{

			case 1:	 printf("\nThe sum of %d and %d is %d", *ptr_a, *ptr_b, *ptr_a + *ptr_b);
					 break;

			case 2 : printf("\nThe difference of %d and %d is %d", *ptr_a, *ptr_b, *ptr_a - *ptr_b);
					 break;

			case 3 : printf("\nThe quotient of %d and %d is %f", *ptr_a, *ptr_b, (float)*ptr_a / *ptr_b);
					 break;

			case 4 : printf("\nThe product of %d and %d is %d", *ptr_a, *ptr_b, (*ptr_a) * (*ptr_b));
					 break;
				
			default : printf("\nInvalid option.\n");
		}
	}

	return 0;
}
