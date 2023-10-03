#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "string_ops.h"
#include <string.h>


int32_t check_string(int8_t *word1, int8_t *word2)
{
    return strcmp(word1, word2) == 0;
}

void delete_word(int8_t *buff, int8_t *word)
{
    int32_t i, j = 0, k = 0, n = 0;
    int32_t flag = 0;

    int8_t *new = (int8_t *)malloc(sizeof(int8_t) * STR_SIZE);

    for (i = 0; buff[i] != '\0'; i++)
    {
        k = i;

        while (buff[i] == word[j])
        {
            i++, j++;
            if (j == strlen(word))
            {
                flag = 1;
                break;
            }
        }
        j = 0;

        if (flag == 0)
            i = k;
        else
            flag = 0;

        new[n++] = buff[i];
    }

    new[n] = '\0';

    printf("\n\nString with word removed is %s.\n", new);
}

void replace_word(int8_t *text, int8_t *old_word, int8_t *new_word)
{
    int i = 0, cnt = 0;
    int len1 = strlen(new_word);
    int len2 = strlen(old_word);
    for (i = 0; text[i] != '\0'; i++)
    {
        if (strstr(&text[i], old_word) == &text[i])
        {
            cnt++;
            i += len2 - 1;
        }
    }
    int8_t *new_string = (int8_t *)malloc(i + cnt * (len1 - len2) + 1);
    i = 0;
    while (*text)
    {
        if (strstr(text, old_word) == text)
        {
            strcpy(&new_string[i], new_word);
            i += len1;
            text += len2;
        }
        else
        {
            new_string[i++] = *text++;
        }
    }

    printf("New String: %s\n", new_string);
}

void sort_ascending(int8_t **buff, int32_t argc)
{
	int32_t i, j, k;
	int8_t *temp = (int8_t*)malloc(sizeof(int8_t) * STR_SIZE);

    _print_args(argc, buff);

	for (i = 0; i < (argc - 1); i++)
	{
		for (j = 0, k = 0; j < (argc - 1 - i) && (buff[j][k] != '\0') && (buff[j + 1][k] != '\0');)
		{
			if (buff[j][k] > buff[j + 1][k])
			{
				// temp = buff[j];
                // buff[j + 1] = buff[j];
                // buff[j] = temp;
				strcpy(temp, buff[j]);
				strcpy(buff[j], buff[j + 1]);
                strcpy(buff[j + 1], temp);

				j += 1;
				k = 0;

                if (j >= (argc - 1)) break;
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

    _print_args(argc, buff);
}


void sort_descending(int8_t **buff, int32_t argc)
{
	int32_t i, j, k;
	int8_t *temp = (int8_t *)malloc(sizeof(int8_t) * STR_SIZE);

    _print_args(argc, buff);

	for (i = 0; i < (argc - 1); i++)
	{
		for (j = 0, k = 0; j < (argc - 1 - i) && (buff[j][k] != '\0') && (buff[j + 1][k] != '\0');)
		{
			if (buff[j][k] < buff[j + 1][k])
			{
				strcpy(temp, buff[j]);
				strcpy(buff[j], buff[j + 1]);
                strcpy(buff[j + 1], temp);

				j += 1;
				k = 0;
				if (j >= (argc - 1)) break;
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

    _print_args(argc, buff);
}

void toggle_case(int8_t *buff)
{
	int32_t i, j = 0, offset;

    for (i = 0; buff[i] != '\0'; i++)
    {
        if ((buff[i] >= 'A') && buff[i] <= 'Z')
        {
            offset = buff[i] - 'A';
            buff[i] = 'a' + offset;
        }
        else if ((buff[i] >= 'a') && (buff[i] <= 'z'))
        {
            offset = buff[i] - 'a';
            buff[i] = 'A' + offset;
        }
        else
        {
            // Do nothing
        }
    }

    printf("\nAfter toggling case : %s\n", buff);
}

void all_to_upper(int8_t *buff)
{
	int32_t offset, i, j;
	
    for (i = 0; buff[i] != '\0'; i++)
    {
        if ((buff[i] >= 'a') && buff[i] <= 'z')
        {
            offset = buff[i] - 'a';
            buff[i] = 'A' + offset;
        }
        else
        {
            // Do nothing
        }
    }

    printf("\nAfter converting all to upper : %s.\n", buff);
}


void all_to_lower(int8_t *buff)
{
	int32_t offset, i, j;
	
    for (i = 0; buff[i] != '\0'; i++)
    {
        if ((buff[i] >= 'A') && buff[i] <= 'Z')
        {
            offset = buff[i] - 'A';
            buff[i] = 'a' + offset;
        }
        else
        {
            // Do nothing
        }
    }

    printf("\nAfter converting all to lower : %s.\n", buff);
}

void _print_args(int32_t nums, int8_t **args)
{
    uint32_t i = 0;

    printf("\nThe list of arguments are : ");

    for (i = 0; i < nums; i++)
    {
        printf("\n%s", args[i]);
    }
}
