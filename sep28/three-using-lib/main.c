#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "string_ops.h"
#include <string.h>


void print_helper();
void _replace_handler(int32_t num, int8_t **args);
void _string_length_handler(int32_t num, int8_t **args);
void _delete_handler(int32_t nums, int8_t **args);
void _sa_handler(int32_t nums, int8_t **args);
void _sd_handler(int32_t nums, int8_t **args);
void _toggle_handler(int32_t nums, int8_t **args);
void _to_upper_handler(int32_t nums, int8_t **args);
void _to_lower_handler(int32_t nums, int8_t **args);
void _print_args(int32_t nums, int8_t **args);
void _check_handler(int32_t nums, int8_t **args);


int main(int argc, char **argv)
{
    if (argc < 3)
    {
        print_helper();
    }
    else
    {
        switch(atoi(argv[1]))
        {
            case 1 :    _replace_handler(argc, argv);
                        break;

            case 2 :    _string_length_handler(argc, argv);
                        break;

            case 3 :    _delete_handler(argc, argv);
                        break;

            case 4 :    _sa_handler(argc, argv);
                        break;

            case 5 :    _sd_handler(argc, argv);
                        break;

            case 6 :    _toggle_handler(argc, argv);
                        break;

            case 7 :    _to_upper_handler(argc, argv);
                        break;

            case 8 :    _to_lower_handler(argc, argv);
                        break;

            case 9 :    _check_handler(argc, argv);
                        break;

            default :   print_helper();
        }
    }
}

void _to_lower_handler(int nums, int8_t **args)
{
    if (nums < 3 || nums > 3)
    {
        printf("\nConvert to lower : \n");
        printf("Usage : <executable-name> 8 \"string\"\n");
    }
    else
    {
        all_to_lower(args[2]);
    }
}

void _to_upper_handler(int nums, int8_t **args)
{
    if (nums < 3 || nums > 3)
    {
        printf("\nConvert to upper : \n");
        printf("Usage : <executable-name> 7 \"string\"\n");
    }
    else
    {
        all_to_upper(args[2]);
    }
}

void _toggle_handler(int nums, int8_t **args)
{
    if (nums < 3 || nums > 3)
    {
        printf("\nToggle the case : \n");
        printf("Usage : <executable-name> 6 \"string\"\n");
    }
    else
    {
        toggle_case(args[2]);
    }
}

void _sd_handler(int32_t nums, int8_t **args)
{
    if (nums < 4)
    {
        printf("\nSort string in descending order : \n");
        printf("Usage : <executable-name> 5 \"(string)+\"\n");
    }
    else
    {
        sort_descending(&args[2], nums - 2);
    }
}

void _sa_handler(int32_t nums, int8_t **args)
{
    if (nums < 4)
    {
        printf("\nSort string in ascending order : \n");
        printf("Usage : <executable-name> 4 \"(string)+\"\n");
    }
    else
    {
        sort_ascending(&args[2], nums - 2);
    }
}

void _delete_handler(int32_t nums, int8_t **args)
{
    if (nums < 4 || nums > 4)
    {
        printf("\nDelete a word from a string : \n");
        printf("Usage : <executable-name> 3 \"string\" \"word-to-delete\"\n");
    }
    else
    {
        delete_word(args[2], args[3]);
    }
}

void _replace_handler(int32_t nums, int8_t **args)
{
    if (nums < 5 || nums > 5)
    {
        printf("\nReplace a word from a string : \n");
        printf("Usage : <executable-name> 1 \"string\" \"word-to-replace\" \"replace-with\"\n");
    }
    else
    {
        replace_word(args[2], args[3], args[4]);
    }
}

void _string_length_handler(int nums, int8_t **args)
{
    if (nums < 3 || nums > 3)
    {
        // print usage
        printf("\nGet length of string : \n");
        printf("Usage : <executable-name> 2 \"string\"\n");
    }
    else
    {
        printf("\nLength : %ld.\n", strlen(args[2]));
    }
}

void _check_handler(int nums, int8_t **args)
{
    if (nums < 4 || nums > 4)
    {
        printf("\nCompares two strings : \n");
        printf("Usage : <executable-name> 9 \"string 1\" \"string 2\"\n");
    }
    else
    {
        if (check_string(args[2], args[3]))
        {
            printf("\nThe strings are equal.\n");
        }
        else
        {
            printf("\nThe strings are not equal.\n");
        }
    }
}

void print_helper()
{
    printf("\nUsage : executable-name option (operand)+\n");
    printf("\nOptions:");
    printf("\n1 -> Replace word, two arguments => <text> and <word to replace> and <replace with>");
    printf("\n2 -> String length => <text>");
    printf("\n3 -> Delete word => <text> and <word-to-delete>");
    printf("\n4 -> Sort ascending => (words)+");
    printf("\n5 -> Sort descending => (words)+");
    printf("\n6 -> Toggle Case => <text>");
    printf("\n7 -> All to upper => <text>");
    printf("\n8 -> All to lower => <text>\n");
    printf("\n9 -> Compare strings => <text1> <text2>\n");
}
