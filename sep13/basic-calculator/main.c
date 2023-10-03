#include <stdio.h>

typedef signed int int8_t;

int main()
{
	printf("Enter value for a:");
	int8_t a = 0;
	scanf("%d", &a);

	printf("Enter the value for b:");
	int8_t b = 0;
	scanf("%d", &b);

	printf("\nThe sum of %d and %d is %d.", a, b, a + b);
	printf("\nThe difference of %d and %d is %d.", a, b, a - b);
	
	printf("\nThe product of %d and %d is %d.", a, b, a * b);
	float inter = (float)(a) / b;
	printf("\nThe quotient of %d and %d is %f.\n", a, b, inter);

	printf("Res1 : %f\n", ((4 / 3) + 2));
	printf("Res2 : %d\n", ((4 / 3) + 2));

	return 0;
}
