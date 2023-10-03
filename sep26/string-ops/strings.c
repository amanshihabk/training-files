#include "strings.h"
#include <stdio.h>
#include <stdint.h>


int32_t Strlen(int8_t *lstr)
{
	int32_t length = 0;

	if (lstr == NULL)
			return length;

	for (int32_t i = 0; lstr[i] != '\0'; i++)
	{
		length += 1;
	}

	return length;
}


int32_t ReverseString(int8_t *Rstr, int8_t *sarr)
{
	int32_t length = 0, i = 0, j = 0;

	printf("\nIm here");

	if (Rstr == NULL)
	{
		Rstr = (int8_t *)malloc(sizeof(char) * MAX_STR_LEN);
	}
	else
	{
		// Do nothign
	}

	if (sarr == NULL)
	{
		printf("\nSource array has no memory allocated to it.\n");

		return -1;
	}
	else
	{
		// Do nothing
	}

	for(i = 0; sarr[i] != '\0'; i++)
	{
		length += 1;
	}

	for(i = length - 1, j = 0; i >= 0; i--, j++)
	{
		Rstr[j] = sarr[i];
	}

	Rstr[j] = '\0';

	return length;
}


int32_t ClrBuffer(int8_t *str, uint8_t size)
{
	int32_t i = 0;

	if (str == NULL)
	{
		return 1;
	}
	else
	{						
		for (i = 0; i < size; i++)
		{
			str[i] = 0;
		}

		return 0;
	}
}


int8_t* StrConcatinate(int8_t *str1, int8_t *str2)
{
	int32_t i = 0, j = 0;

	str1 = realloc(str1, 2 * (MAX_STR_LEN * sizeof(int8_t)));

	for (i = 0; str1[i] != '\0'; i++);

	for(j = 0; str2[j] != '\0'; j++)
	{
		str1[i++] = str2[j];
	}

	str1[i] = '\0';

	return str1;
}


int32_t SetBuffer(int8_t *Src, int8_t *Dest)
{
	int32_t i = 0;

	if (Src == NULL)
	{
		printf("\nSrc buffer not allocated memory.");
		return -1;
	}
	else
	{
		// Do nothing
	}
	if (Dest == NULL)
	{
		Dest = (int8_t *)malloc(sizeof(char) * MAX_STR_LEN);
	}
	else
	{
		// Do nothing
	}
	
	for(i = 0; Src[i] != '\0'; i++)
	{
		Dest[i] = Src[i];
	}
	
	Dest[i] = '\0';

	return i;
}
