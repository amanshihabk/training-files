#ifndef _STRINGS_H
#define _STRINGS_H

#include <stdint.h>
// typedef char int8_t;
// typedef signed int int32_t;

#define MAX_STR_LEN 50

int32_t Strlen(int8_t *lstr);
int32_t ReverseString(int8_t *Rstr, int8_t *sarr);
int32_t ClrBuffer(int8_t *str, u_int8_t size);
int8_t* StrConcatinate(int8_t *str1, int8_t *str2);
int32_t SetBuffer(int8_t *Src, int8_t *Dest);

#endif