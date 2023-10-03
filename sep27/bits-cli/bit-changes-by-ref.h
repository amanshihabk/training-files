#ifndef _BIT_CHANGES_BY_REF
#define _BIT_CHANGES_BY_REF

typedef signed char int8_t;
typedef unsigned char uint8_t;

void print_in_binary(int8_t *num);

void set_nth_bit(int8_t *num, int8_t pos);

void clear_nth_bit(int8_t *num, int pos);

void swap_bits(int8_t *num, int8_t pos1, int8_t pos2);

void toggle_nth_bit(int8_t *num, int8_t pos);

void flip_sign(int8_t *num);

#endif
