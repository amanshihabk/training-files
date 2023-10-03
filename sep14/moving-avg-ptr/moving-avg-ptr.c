#include <stdio.h>

typedef int int32_t;
typedef char int8_t;

#define MAX_SIZE 1024
#define TRUE 1
#define FALSE 0

int main()
{

	int32_t size, value, running_sum = 0, flag=TRUE, max_val;
	int32_t array[MAX_SIZE];
	int32_t *ptr_loc = array;

	int8_t choice;

	printf("Enter the sample size:");
	scanf("%d", &size);

	printf("Enter the maximum value to keep:");
	scanf("%d", &max_val);

	while (1)
	{
		printf("\nEnter number:");
		scanf("%d", &value);

		if (value > max_val)
		{
			printf("\nReceived value greater than threshold. Want to conitnue (y/n)?\n");
			scanf("%c", &choice);

			if (choice == 'n' || choice == 'N')
				break;
		}

		if (flag)
		{
			*ptr_loc = value;
			ptr_loc += 1;
			running_sum += value;

			if (ptr_loc == (array + size))
			{
				printf("\nThe average is %f.", (float)running_sum / size);
				flag = FALSE;
			}
		}
		else
		{
			if (ptr_loc >= (array + size))
			{
				ptr_loc = array;
			}
			else
			{
				ptr_loc += 1;
			}

			running_sum -= *ptr_loc;
			running_sum += value;
			*ptr_loc = value;
				
			printf("\nThe average is %f.", (float)running_sum / size);
		}
	}

	return 0;
}
