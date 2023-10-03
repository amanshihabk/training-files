/* the following
	a. Sort the stored string in ascending or descending based on the input A or D
	b. Toggle the cases in x string stored
	c. Change case from either all to lower or Upper in stored x string based on t

*/

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define STR_SIZE 20
#define NUM_STRINGS 5
#define STR_SIZE 20


void sort_ascending(int8_t **buff);
void sort_descending(int8_t **buff);
void toggle_case(int8_t **buff);
void all_to_upper(int8_t **buff);
void all_to_lower(int8_t **buff);
void strcpy(int8_t *src, int8_t *dest);

int8_t **buffers;
int main()
{
	FILE *fptr;
	int8_t opt;
	int32_t i = 0;
	int8_t *filename = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);

	buffers = (int8_t **)malloc(NUM_STRINGS * sizeof(int8_t *));

	printf("\nEnter filename :");
	scanf("%s", filename);
	
	fptr = fopen(filename, "r");
	
	for(i = 0; i < 5; i++)
	{
		buffers[i] = (int8_t *)malloc(sizeof(int8_t) * STR_SIZE);
		fscanf(fptr, "%[^\n]%*c", buffers[i]);
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


void sort_ascending(int8_t **buff)
{
	int32_t i, j, k;
	int8_t *temp = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);


	for (i = 0; i < 4; i++)
	{
		for (j = 0, k = 0; j < (4) && (buff[j][k] != '\0') && (buff[j + 1][k] != '\0');)
		{
			if (buff[j][k] > buff[j + 1][k])
			{
				strcpy(buff[j], temp);
				strcpy(buff[j + 1], buff[j]);
				strcpy(temp, buff[j + 1]);;

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


void sort_descending(int8_t **buff)
{
	int32_t i, j, k;
	int8_t *temp = (int8_t *)malloc(sizeof(int8_t));

	for (i = 0; i < 4; i++)
	{
		for (j = 0, k = 0; j < (4 - i), (buff[j][k] != '\0') && (buff[j + 1][k] != '\0');)
		{
			if (buff[j][k] < buff[j + 1][k])
			{
				strcpy(buff[j], temp);
				strcpy(buff[j + 1], buff[j]);
				strcpy(temp, buff[j + 1]);;

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


void toggle_case(int8_t **buff)
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

void all_to_upper(int8_t **buff)
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


void all_to_lower(int8_t **buff)
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


void strcpy(int8_t *src, int8_t *dest)
{
	int32_t i = 0;

	while(src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}

	dest[i] = '\0';
}
