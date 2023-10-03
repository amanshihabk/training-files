#ifndef _BIT_CHANGES_BY_VALUE
#define _BIT_CHANGES_BY_VALUE

typedef signed char int8_t;
typedef unsigned char uint8_t;

void print_in_binary(int8_t num, uint8_t mask);

int8_t set_nth_bit(int8_t num, int8_t pos);

int8_t clear_nth_bit(int8_t num, int pos);

int8_t swap_bits(int8_t num, int8_t pos1, int8_t pos2);

int8_t toggle_nth_bit(int8_t num, int8_t pos);

int8_t flip_sign(int8_t num);

#endif
