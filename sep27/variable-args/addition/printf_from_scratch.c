#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>


void format_print(int8_t* fmt, ...);

int main()
{
    format_print("Hello world, I am %f tall and %d years old.\n", 172.4, 22);

    return 0;
}


void format_print(int8_t* fmt, ...)
{
    uint32_t i;

    va_list args;

    va_start(args, fmt);

    for (i = 0; fmt[i] != '\0'; i++)
    {
        if (fmt[i] == '%')
        {
            i += 1;

            switch(fmt[i])
            {
                case 'd' :      printf("%d", va_arg(args, int32_t));

                                break;

                case 'f' :      printf("%.3f", va_arg(args, double));

                                break;

                default :       printf("%c%c", fmt[i - 1], fmt[i]);
                                i -= 1;
            }
        }
        else
        {
            printf("%c", fmt[i]);
        }
    }
}