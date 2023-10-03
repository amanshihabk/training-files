#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 3
#define MAX_STR_SIZE 50


void push(int8_t* to_push, int8_t** stack, int32_t *the_top);
int8_t* pop(int8_t** stack, int32_t* the_top);
void print_stack(int8_t** stack, int32_t* the_top);


int main()
{
    int8_t **buffers = (int8_t**)malloc(sizeof(int8_t *) * STACK_SIZE);
    int32_t top = -1;
    int8_t opt;
    int8_t *buffer;

    while (1)
    {
        printf("\n\nStack operations : ");
        printf("\n\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print");
        printf("\n4. Exit");
        printf("\n\nEnter the choice : ");

        scanf("%hhu", &opt);

        switch(opt)
        {
            case 1 :    printf("\nEnter the string to push : ");
                        buffer = (int8_t*)malloc(sizeof(int8_t) * MAX_STR_SIZE);
                        scanf(" %[^\n]%*c", buffer);
                        push(buffer, buffers, &top);

                        break;

            case 2 :    buffer = pop(buffers, &top);
                        if (buffer != NULL)
                        {
                            printf("\n%s popped from stack.\n", buffer);
                        }
                        else
                        {
                            // Do nothing
                        }

                        free(buffer);

                        break;

            case 3 :    print_stack(buffers, &top);

                        break;

            case 4 :    return 0;
                        break;

            default :   printf("\nInvalid option!");
        }
    }

    return 0;
}


void push(int8_t* to_push, int8_t** stack, int32_t *the_top)
{
    if ((*the_top + 1) > STACK_SIZE)
    {
        printf("\nStack overflow!\n");
    }
    else
    {
        stack[++(*the_top)] = to_push;
    }
}


int8_t* pop(int8_t** stack, int32_t* the_top)
{
    if (*the_top < 0)
    {
        printf("\nStack underflow!\n");

        return NULL;
    }
    else
    {
        return stack[(*the_top)--];
    }
}

void print_stack(int8_t** stack, int32_t* the_top)
{
    uint32_t i;

    if (*the_top < 0)
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        printf("\nThe stack now is : ");

        for (i = 0; i <= *the_top; i++)
        {
            printf("%s  ", stack[i]);
        }
    }

}