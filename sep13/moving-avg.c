#include <stdio.h>

typedef int int32_t;
typedef char int8_t;

#define MAX_SIZE 1024

int main()
{

	int32_t size, value, idx = 0, running_sum = 0, flag=1, max_val;
	int32_t array[MAX_SIZE];

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

		if (idx < size && flag)
		{
			array[idx] = value;
			idx += 1;
			running_sum += value;

			if (idx == size)
			{
				printf("\nThe average is %f.", (float)running_sum / size);
				flag = 0;
			}
		}
		else
		{
			idx = (idx % size);
			running_sum -= array[idx];
			running_sum += value;
			array[idx++] = value;
				
			printf("\nThe average is %f.", (float)running_sum / size);
		}
	}

	return 0;
}
