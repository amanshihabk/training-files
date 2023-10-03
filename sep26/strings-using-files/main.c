/*4. Program to store string with words and perform the following operations
	a. Find out no of words in string
	b. Search x word in the string
	c. Replace the x word with y word in the string (size of the x and y must be taken care it can be higher or lower in size)
	d. Delete the x words in string
	e. Append the x word after y word or before y word */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define STR_SIZE 50

uint32_t _strlen(int8_t *str);
void find_num_words(int8_t *buffer);
void find_query(int8_t *buffer, int8_t *query);
void delete_word(int8_t *buffer, int8_t *to_delete);
void replace_word(int8_t *buffer, int8_t *to_replace, int8_t *replace_with);

int main()
{
	int8_t opt;
	int8_t *buffer, *query;
	int8_t *delete, *replace, *replace_with;
	FILE *fptr_buffer;

	buffer = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);
	query = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);
	replace = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);
	replace_with = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);
	delete = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);

	fptr_buffer = fopen("buffer.txt", "rw+");

	fscanf(fptr_buffer, "%[^\n]%*c", buffer);

	printf("\nRead : %s", buffer);

	while (1)
	{
		printf("\nWhat do you want to do : ");
		printf("\n1. Search for a word");
		printf("\n2. Replace a word:");
		printf("\n3. Delete a word");
		printf("\n4. Append x word after y word");
		printf("\n5. Find no of words");
		printf("\n6. Exit");
		printf("\nEnter your choice:");
		scanf("%hhd", &opt);

		switch(opt)
		{
			case 1 :	printf("\nEnter a query to search : ");
						scanf(" %[^\n]%*c", query); 	

						find_query(buffer, query);

						break;

			case 2 :	printf("\nEnter the string to replace : ");
						scanf(" %[^\n]%*c", replace);
						
						printf("\nEnter the string to replce with : ");
						scanf(" %[^\n]%*c", replace_with); 	

						replace_word(buffer, replace, replace_with);

						printf("Replcaed : %s", buffer);

						rewind(fptr_buffer);

						fprintf(fptr_buffer, "%s", buffer);

						break;

			case 3 :	printf("\nEnter the word to delete : ");
						scanf(" %[^\n]%*c", delete);
						delete_word(buffer, delete);

						rewind(fptr_buffer);

						fprintf(fptr_buffer, "%s", buffer);

						break;

			case 5 : 	find_num_words(buffer);
					 
					 	break;

			case 6 : return 0;
					 break;

			default : printf("\nInvalid option");
		}
	}

	fclose(fptr_buffer);
}


void find_num_words(int8_t *buffer)
{
	int32_t i, count = 0;

	for (i = 0; buffer[i] != '\0'; i++)
	{
		if (buffer[i] == ' ' || buffer[i] == '\n')
		{
			count += 1;
		}
	}

	printf("\nThe count of words are : %d.\n", count);
}

void find_query(int8_t *buffer, int8_t *query)
{
	uint32_t i, j;
	uint32_t buffer_length = _strlen(buffer);
	uint32_t query_length = _strlen(query);
	uint8_t found = 0;

	for(i = 0; i <= (buffer_length - query_length); i++)
	{
		for (j = 0; j < query_length; j++)
		{
			if (buffer[i + j] != query[j])
			{
				break;
			}
			else
			{
				// Do nothing
			}
		}

		if (j == query_length)
		{
			found = 1;
			break;
		}
		else
		{
			// Do nothing
		}
	}

	if (found)
	{
		printf("\nQuery string exists in buffer.\n");
	}
	else
	{
		printf("\nQuery string does not exist in buffer.\n");
	}
}

void delete_word(int8_t *buffer, int8_t *to_delete)
{
	uint32_t buff_len = _strlen(buffer), word_len = _strlen(to_delete);
	uint32_t i = 0, j = 0;

	while (i < buff_len)
	{
		if (buffer[i] == to_delete[j])
		{
			i +=1;
			j += 1;

			if (j == word_len)
			{
				while (i < buff_len)
				{
					buffer[i - word_len] = buffer[i];
					i += 1;
				}

				buff_len -= word_len;
				i = 0;
				j = 0;
			}
			else
			{
				// Do nothing
			}
		}
		else
		{
			j = 0;
			i += 1;
		}
	}

	buffer[buff_len] = '\0';
}


void replace_word(int8_t *buffer, int8_t *to_replace, int8_t *replace_with)
{
	uint32_t buff_len = _strlen(buffer), word_len = _strlen(to_replace);
	uint32_t i = 0, j = 0, r_index = 0;

	while (i < buff_len)
	{
		if (buffer[i] == to_replace[j])
		{
			i +=1;
			j += 1;

			if (j == word_len)
			{
				r_index = 0;
				while (i < buff_len)
				{
					buffer[i - word_len] = replace_with[r_index];
					i += 1;
					r_index += 1;
				}

				buff_len -= word_len;
				i = 0;
				j = 0;
			}
			else
			{
				// Do nothing
			}
		}
		else
		{
			j = 0;
			i += 1;
		}
	}

	buffer[buff_len] = '\0';
}

uint32_t _strlen(int8_t *str)
{
	int32_t i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		count += 1;
	}

	return count;
}
