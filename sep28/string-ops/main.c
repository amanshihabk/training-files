/* the following
	a. Sort the stored string in ascending or descending based on the input A or D
	b. Toggle the cases in x string stored
	c. Change case from either all to lower or Upper in stored x string based on t

*/

#include <stdio.h>
#include <string.h>

#define STR_SIZE 20;

typedef char int8_t;
typedef int int32_t;


void sort_ascending(int8_t buff[][20]);
void sort_descending(int8_t buff[][20]);
void toggle_case(int8_t buffi[][20]);
void all_to_upper(int8_t buff[][20]);
void all_to_lower(int8_t buff[][20]);
// void strcpy(int8_t src[20], int8_t dest[20]);

int8_t buffers[5][20];
int main()
{

	int8_t opt;
	int32_t i = 0;

	printf("\nEnter 5 strings:");
	for(i = 0; i < 5; i++)
	{
		scanf(" %[^\n]%*c", buffers[i]);
	}

	while (1)
	{
		printf("\n\nYou have the following options:\n");
		printf("\n1) Sort - Ascending");
		printf("\n2) Sort - Descending");
		printf("\n3) Toggle case");
		printf("\n4) Change all to upper");
		printf("\n5) Change all to lower");
		printf("\n6) Exit");
		printf("\n7) Print");
		printf("\nEnter your choice:");
		scanf("%hhd", &opt);
			

		switch(opt)
		{
			case 1 : 
					 sort_ascending(buffers);
					 break;

			case 2 : sort_descending(buffers);
					 break;

			case 3 : toggle_case(buffers);
					 break;

			case 4 : all_to_upper(buffers);
					 break;

			case 5 : all_to_lower(buffers);
					 break;

			case 6 : return 0;
				     break;

			case 7 : printf("\nThe strings are:");
					 for (i = 0; i < 5; i++)
					 {
						printf("\n%s", buffers[i]);
					 }
					 break;
			default : printf("\nWrong option");
		}
	}
}


void sort_ascending(int8_t buff[][20])
{
	int32_t i, j, k;
	int8_t *temp;


	for (i = 0; i < 4; i++)
	{
		for (j = 0, k = 0; j < (4 - i), (buff[j][k] != '\0') && (buff[j + 1][k] != '\0');)
		{
			if (buff[j][k] > buff[j + 1][k])
			{
				strcpy(temp, buff[j]);
				strcpy(buff[j], buff[j + 1]);
				strcpy(buff[j + 1], temp);

				j += 1;
				k = 0;
				if (j >= 4) break;
			}
			else if (buff[j][k] == buff[j + 1][k])
			{
				k += 1;
			}
			else
			{
				j += 1;	
			}
		}
	}
}


void sort_descending(int8_t buff[][20])
{
	int32_t i, j, k;
	int8_t *temp;


	for (i = 0; i < 4; i++)
	{
		for (j = 0, k = 0; j < (4 - i), (buff[j][k] != '\0') && (buff[j + 1][k] != '\0');)
		{
			if (buff[j][k] < buff[j + 1][k])
			{
				strcpy(temp, buff[j]);
				strcpy(buff[j], buff[j + 1]);
				strcpy(buff[j + 1], temp);

				j += 1;
				k = 0;
				if (j >= 4) break;
			}
			else if (buff[j][k] == buff[j + 1][k])
			{
				k += 1;
			}
			else
			{
				j += 1;	
			}
		}
	}
}


void toggle_case(int8_t buff[][20])
{
	int32_t i, j = 0, offset;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; buff[i][j] != '\0'; j++)
		{
			if ((buff[i][j] >= 'A') && buff[i][j] <= 'Z')
			{
				offset = buff[i][j] - 'A';
				buff[i][j] = 'a' + offset;
			}
			else if ((buff[i][j] >= 'a') && (buff[i][j] <= 'z'))
			{
				offset = buff[i][j] - 'a';
				buff[i][j] = 'A' + offset;
			}
			else
			{
				// Do nothing
			}
		}
	}
}

void all_to_upper(int8_t buff[][20])
{

	int32_t offset, i, j;
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; buff[i][j] != '\0'; j++)
		{
			if ((buff[i][j] >= 'a') && buff[i][j] <= 'z')
			{
				offset = buff[i][j] - 'a';
				buff[i][j] = 'A' + offset;
			}
			else
			{
				// Do nothing
			}
		}
	}
	
}


void all_to_lower(int8_t buff[][20])
{
	int32_t offset, i, j;
	
	for (i = 0; i < 5; i++)
	{
		for (j = 0; buff[i][j] != '\0'; j++)
		{
			if ((buff[i][j] >= 'A') && buff[i][j] <= 'Z')
			{
				offset = buff[i][j] - 'A';
				buff[i][j] = 'a' + offset;
			}
			else
			{
				// Do nothing
			}
		}
	}
	
}


void strcpy(int8_t src[20], int8_t dest[20])
{
	int32_t i = 0;

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}

	dest[i] = '\0';
}
