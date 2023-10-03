#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int count = 0, sz = 0;

typedef struct
{

    int32_t data;
    struct node *link;
} node;

node *start = NULL, *temp, *loc; // loc for getting location of element in insert operations

void enqueue();
void dequeue();
void display();

void main()
{

    int32_t ans = 0;

    printf("Enter the size of the queue:");
    scanf("%d", &sz);

    while (1)
    {

        printf("\n\nLinked Queue Operations:\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\nEnter your option:");
        scanf("%d", &ans);

        switch (ans)
        {

        case 1:
            ++count;
            enqueue();
            break;
        case 2:
            ++count;
            dequeue();
            break;
        case 3:
            ++count;
            display();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\n!Wrong option!\n");
        }
    }
}

void display()
{

    if (start == NULL)
    {

        printf("\nLinked list is empty!\n");
    }
    else
    {

        printf("\nThe linked list now is:\n");

        temp = start;

        if (temp->link == NULL)
        {

            printf("%d ", temp->data);
        }
        else
        {

            do
            {

                printf("%d ", temp->data);
                temp = temp->link;

                if (temp->link == NULL)
                {

                    printf("%d ", temp->data);
                }
            } while (temp->link != NULL);
        }
    }
}

void dequeue()
{

    if (start == NULL)
        printf("\nNothing to delete! Linked list is empty!\n");
    else
    {
        temp = start;
        start = start->link;

        printf("\n%d is deleted!\n", temp->data);

        free(temp);

        display();
    }
}

void enqueue()
{
    node *p;

    if (count > sz)
        printf("\nQueue is full!");
    else
    {
        p = (node *)malloc(sizeof(node));

        printf("Enter the element to be enqueued:");
        int item;
        scanf("%d", &item);

        p->data = item;
        if (start == NULL)
        {

            p->link = NULL;
            start = p;
        }
        else
        {

            temp = start;
            while (temp->link != NULL)
            {
                temp = temp->link;
            }
            temp->link = p;
            p->link = p;
            p->link = NULL;
        }

        display();
    }
}