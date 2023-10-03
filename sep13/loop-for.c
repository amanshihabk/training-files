#include <stdio.h>

typedef int int32_t;


int main()
{

	int32_t num;

	printf("\nEnter the number at which to break:");
	scanf("%d", &num);

	int cnt = 0;

	for(; cnt <= 100 ; cnt += 1)
	{
		printf("%d\n", cnt);
		if (cnt == num) cnt = 101;
	}

	return 0;
}
