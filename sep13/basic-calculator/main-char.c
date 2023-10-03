#include <stdio.h>

typedef signed int int32_t;
typedef signed char int8_t;

int main()
{
	int8_t opcode;
	int32_t a;
	int32_t b;

	printf("\nEnter the opcode:");
	scanf("%c", &opcode);

	if ((opcode != 'A') && (opcode != 'S') && (opcode != 'M') && (opcode != 'D'))
	{
		printf("Not a valid option.\n");
		return 0;
	}

	printf("\nEnter the value for a:");
	scanf("%d", &a);
	
	printf("\nEnter the value for b:");
	scanf("%d", &b);
	
	switch(opcode)
	{
		case 'A' : printf("\nThe sum of %d and %d is %d.\n", a, b, a + b);
			   break;
		case 'S' : printf("\nThe difference of %d and %d is %d.\n", a, b, a - b);
			   break;
		case 'M' : printf("\nThe product of %d and %d is %d.\n", a, b, a * b);
			   break;
		case 'D' : printf("\nThe quotient of %d and %d is %f.\n", a, b, (float)a / (float)b);
			   break;
		default:   break;
	}

	return 0;
}
