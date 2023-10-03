#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

int32_t find_max(int32_t count, ...);

int main()
{
    int32_t max = find_max(5, 1, 2, 3, 4, 5);

    printf("\n%d\n", max);

    return 0;
}

int32_t find_max(int count, ...)
{
    int32_t i = 0;

    int32_t cumulative_sum = 0;
    int32_t num;

    va_list args;

    va_start(args, count);

    for (i = 0; i < count; i++)
    {
        num = va_arg(args, int32_t);

        cumulative_sum += num;
    }

    return cumulative_sum;
}