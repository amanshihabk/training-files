#include <stdio.h>

typedef int int32_t;
typedef char int8_t;

int32_t add(int, int);
int32_t sub(int, int);
int32_t mul(int, int);
int32_t div(int, int);

void update_ptr(int32_t (**fun_ptr)(int32_t, int32_t), int8_t opt);

int main()
{
	int32_t a, b, option;
	int32_t (*fun) (int32_t, int32_t);

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
		
		update_ptr(&fun, option);

		printf("%p", fun);
		printf("%p", &fun);

		printf("\nThe result is %d.", fun(a, b));
	}

	return 0;
}


void update_ptr(int32_t (**fun_ptr)(int32_t, int32_t), int8_t opt)
{
	switch(opt)
	{
		case 1 : *fun_ptr = add;
				 break;

		case 2 : *fun_ptr = sub;
				 break;

		case 3 : *fun_ptr = div;
				 break;

		case 4 : *fun_ptr = mul;
				 break;
		default:
				 printf("Wrong Option\r\n");
				 break;
	}
}

int32_t add(int32_t a, int32_t b)
{
	return a + b;
}

int32_t sub(int32_t a, int32_t b)
{
	return a - b;
}

int32_t mul(int32_t a, int32_t b)
{
	return a * b;
}

int32_t div(int32_t a, int32_t b)
{
	return a / b;
}
