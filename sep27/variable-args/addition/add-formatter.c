#include <stdio.h>
#include <stdarg.h>
#include <stdint.h>


int32_t format_add(int8_t* fmt, ...);

int main()
{

    int32_t res;

    res = format_add("dddd", 10, 20, 30, 40);

    printf("\nThe sum is %d.\n", res);

    return 0;
}

int32_t format_add(int8_t* fmt, ...)
{
    int32_t res = 0;
    uint32_t i = 0;

    va_list args;

    va_start(args, fmt);

    for (i = 0; fmt[i] != '\0'; i++)
    {
        if (fmt[i] == 'd')
        {
            res += (va_arg(args, int32_t));
        }
        else
        {
            // Do nothing
        }
    }

    return res;
}