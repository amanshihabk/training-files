#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define STR_SIZE 100


int main(int argc, char **argv)
{
    int8_t concat = (int8_t *)malloc(sizeof(int8_t) * STR_SIZE);

    switch(atoi(argv[1]))
    {
        case 1 :    printf("\nWord 1 : %s", argv[2]);
                    printf("\nWord 2 : %s", argv[3]);
                    printf("\nConcatenated : %s", strcat(argv[2], argv[3]));

                    break;

        case 2 :    printf("\nWord : %s\n", argv[2]);
                    printf("Character to search : %s\n", argv[3]);
                    printf("\nDeref prs from strchr : %c\n", *strchr(argv[2], argv[3][0]));

                    break;

        case 3 :    printf("\n")
    }
}