#include <stdio.h>

typedef int int32_t;
typedef float float32_t;

int32_t* add(int32_t* a, int32_t* b);
int32_t* subtract(int32_t* a, int32_t* b);
int32_t* multiplication(int32_t* a, int32_t* b);
float32_t* division(int32_t* a, int32_t* b);

int32_t result;
float32_t result_f;

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

			case 1:	 printf("\nThe sum of %d and %d is %d", a, b, *add(&a, &b));
					 break;

			case 2 : printf("\nThe difference of %d and %d is %d", a, b, *subtract(&a, &b));
					 break;

			case 3 : printf("\nThe quotient of %d and %d is %f", a, b, *division(&a, &b));
					 break;

			case 4 : printf("\nThe product of %d and %d is %d", a, b, *multiplication(&a, &b));
					 break;
				
			default : printf("\nInvalid option.\n");
		}
	}

	return 0;
}


int32_t* add(int32_t* a, int32_t* b)
{
	result = *a + *b;
	return &result;
}

int32_t* subtract(int32_t* a, int32_t* b)
{
	result = *a - *b;
	return &result;
}

float32_t* division(int32_t* a, int32_t* b)
{
	result_f = (float)*a / (float)*b;
	return &result_f;
}

int32_t* multiplication(int32_t* a, int32_t* b)
{
	result = (*a) * (*b);
	return &result;
}
