#include "bit-changes-by-ref.h"
#include <stdio.h>

void print_in_binary(int8_t *num, uint8_t mask)
{
	if (mask)
	{
		if ((*num) & mask)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}

		print_in_binary(num, mask >> 1);
	}
	else
	{
		// Do nothing
	}
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
    int8_t to_xor = 0;
	set_nth_bit(&to_xor, pos1);
	set_nth_bit(&to_xor, pos2);
	*num = (*num) ^ to_xor;
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
