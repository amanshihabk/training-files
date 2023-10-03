#include <stdint.h>

#ifndef _STRING_OPS_H
#define _STRING_OPS_H

#define STR_SIZE 100

int32_t check_string(int8_t *word1, int8_t *word2);
void replace_word(int8_t *text, int8_t *old_word, int8_t *new_word);
void delete_word(int8_t *buff, int8_t *word);
void sort_ascending(int8_t **buff, int32_t argc);
void sort_descending(int8_t **buff, int32_t argc);
void toggle_case(int8_t *buff);
void all_to_upper(int8_t *buff);
void all_to_lower(int8_t *buff);
void _print_args(int32_t nums, int8_t **args);

#endif