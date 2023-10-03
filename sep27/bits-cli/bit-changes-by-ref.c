#include "bit-changes-by-ref.h"
#include <stdio.h>

void print_in_binary(int8_t* num)
{
	uint8_t mask = 128, i = 0;

	for(i = 0; i < 8; i++)
	{
		if ((*num) & mask)
				printf("%hhd", 1);
		else
				printf("%hhd", 0);

		mask >>= 1;
	}

	printf("\n");
}

void set_nth_bit(int8_t* num, int8_t pos)
{
	int8_t to_bitwise_or = 1 << pos;
	*num = (*num) | to_bitwise_or;
}

void clear_nth_bit(int8_t* num, int pos)
{
	int8_t to_bitwise_and = ~(1 << pos);
	*num = (*num) & to_bitwise_and;
}

void swap_bits(int8_t* num, int8_t pos1, int8_t pos2)
{
    int8_t to_xor = 0, _temp;
	_temp = (*num >> pos1) & (*num >> pos2);
	printf("\n%hhu", _temp);
	if (_temp)
	{
		set_nth_bit(&to_xor, pos1);
		set_nth_bit(&to_xor, pos2);
		*num = (*num) ^ to_xor;
	}
	else
	{
		// Do Nothing
	}
}

void toggle_nth_bit(int8_t* num, int8_t pos)
{
	int8_t to_bitwise_xor = 1 << pos;
	*num = (*num) ^ to_bitwise_xor;
}

void flip_sign(int8_t* num)
{
	if (*num < 0)
    {
        *num = *num - 1;
        *num = ~(*num);
    }
    else
    {
        *num = ~(*num);
        *num = *num + 1;
    }
}
