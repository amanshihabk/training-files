#include "bit-changes-by-val.h"
#include <stdio.h>


void print_in_binary(int8_t num, uint8_t mask)
{
	if (mask)
	{
		if (num & mask)
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


int8_t set_nth_bit(int8_t num, int8_t pos)
{
	int8_t to_bitwise_or = 1 << pos;
	return num + to_bitwise_or;
}

int8_t clear_nth_bit(int8_t num, int pos)
{
	int8_t to_bitwise_and = ~(1 << pos);
	return num & to_bitwise_and;
}

int8_t swap_bits(int8_t num, int8_t pos1, int8_t pos2)
{
	int8_t to_xor = set_nth_bit(0, pos1);
	to_xor = set_nth_bit(to_xor, pos2);
	return num ^ to_xor;
}

int8_t toggle_nth_bit(int8_t num, int8_t pos)
{
	int8_t to_bitwise_xor = 1 << pos;
	return num ^ to_bitwise_xor;
}

int8_t flip_sign(int8_t num)
{
	return (num < 0) ?  ~(num - 1) :  (~num) + 1;
}
