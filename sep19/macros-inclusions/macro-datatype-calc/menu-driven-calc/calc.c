#include <stdio.h>

#ifdef _INT_32
typedef int int32_t;
#else
typedef char int32_t;
#endif

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
		#ifdef _INT_32
		scanf("%d", &option);
		#else
		scanf("%hhd", &option);
		#endif

		if (option == 5)
			break;

		printf("\nEnter a:");
		#ifdef _INT_32
		scanf("%d", &a);
		#else
		scanf("%hhd", &a);
		#endif
						 
		printf("Enter b:");
		#ifdef _INT_32
		scanf("%d", &b);
		#else
		scanf("%hhd", &b);
		#endif
		
		switch(option)
		{

			case 1:	 
					 #ifdef _INT_32
					 printf("\nThe sum of %d and %d is %d", a, b, a + b);
					 #else
					 printf("\nThe sum of %hhd and %hhd is %hhd", a, b, a + b);
					 #endif
					 break;

			case 2 : 
					 #ifdef _INT_32
					 printf("\nThe difference of %d and %d is %d", a, b, a - b);
					 #else
					 printf("\nThe difference of %hhd and %hhd is %hhd", a, b, a - b);
					 #endif
					 break;

			case 3 : 
					 #ifdef _INT_32
					 printf("\nThe quotient of %d and %d is %f", a, b, (float)a / b);
					 #else
					 printf("\nThe quotient of %hhd and %hhd is %f", a, b, (float)a / b);
					 #endif
					 break;

			case 4 : 
					 #ifdef _INT_32
					 printf("\nThe product of %d and %d is %d", a, b, a * b);
					 #else
					 printf("\nThe product of %hhd and %hhd is %d", a, b, a * b);
					 #endif
					 break;
				
			default : printf("\nInvalid option.\n");
		}
	}

	return 0;
}
