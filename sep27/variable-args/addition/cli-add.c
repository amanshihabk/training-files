#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_LEN 5

int32_t add_variadic(int cnt, ...);

int main()
{
    uint32_t count = 0;
    int32_t *list = (int32_t*)malloc(sizeof(int32_t) * MAX_LEN);
    uint32_t i;
    int32_t res;

    printf("\nEnter the no. of numbers : ");
    scanf("%u", &count);

    if (count > 5)
    {
        printf("\nNumber of values greater than 5 is not supported.\n");
    }

    for (i = 0; i < MAX_LEN; i++)
    {
        list[i] = 0;
    }

    for (i = 0; i < count; i++)
    {
        scanf("%d", &list[i]);
    }

    switch(count)
    {
        case 1 :    res = add_variadic(1, list[0]);

                    break;

        case 2 :    res = add_variadic(2, list[0], list[1]);

                    break;

        case 3 :    res = add_variadic(3, list[0], list[1], list[2]);

                    break;

        case 4 :    res = add_variadic(4, list[0], list[1], list[2], list[3]);

                    break;

        case 5 :    res = add_variadic(5, list[0], list[1], list[2], list[3], list[4]);
    }

    printf("\nThe result is : %d\n", res);

    return 0;
}


int32_t add_variadic(int cnt, ...)
{
    uint32_t i = 0;    
    int32_t sum = 0;

    va_list args;

    va_start(args, cnt);

    for (i = 0; i < cnt; i++)
    {
        sum += va_arg(args, int32_t);
    }

    return sum;
}