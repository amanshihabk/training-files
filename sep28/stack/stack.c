#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define STACK_SIZE 10

void push(int8_t, int8_t*, int32_t*);
int8_t pop(int8_t*, int32_t*);
void print_stack(int8_t*, int32_t*);

int main()
{
    int8_t *stack = (int8_t*)malloc(sizeof(int8_t) * STACK_SIZE);
    int32_t top = -1;
    int8_t opt;
    int8_t push_temp, pop_temp;

    while (1)
    {
        printf("\n\nStack Operations : ");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print");
        printf("\n4. Exit");
        printf("\n\nEnter choice : ");

        scanf("%hhu", &opt);

        switch(opt)
        {
            case 1 :    printf("\nEnter the data you want to push (ascii characters): ");
                        scanf(" %c", &push_temp);

                        push(push_temp, stack, &top);

                        break;

            case 2 :    pop_temp = pop(stack, &top);
                        printf("\nData popped from stack : %c\n", pop_temp);

                        break;

            case 3 :    print_stack(stack, &top);

                        break;

            case 4 :    return 0;

            default :   printf("\nWrong option.\n");
        }
    }

    return 0;
}


void push(int8_t to_push, int8_t *the_stack, int32_t *top)
{
    if ((*top + 1) > STACK_SIZE)
    {
        printf("\nStack overflow!");
    }
    else
    {
        the_stack[++(*top)] = to_push;
    }
}

int8_t pop(int8_t *the_stack, int32_t *top)
{
    if (*top < 0)
    {
        printf("\nStack underflow!\n");
        return -1;
    }
    else
    {
        return the_stack[(*top)--];
    }
}

void print_stack(int8_t *stack, int32_t *top)
{
    uint32_t i;

    if (*top < 0)
    {
        printf("\nStack is empty!\n");
    }
    else
    {
        printf("\nThe stack now is : ");

        for (i = 0; i <= *top; i++)
        {
            printf("%c  ", stack[i]);
        }
    }

}