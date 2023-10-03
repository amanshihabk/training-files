#include "heap_ops.h"
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


int8_t *get_str_memory();

int main()
{
    int8_t opt;

    Work *work_heap = (Work*)malloc(sizeof(Work) * MAX_HEAP_SIZE);
    Work temp_work;
    Work poppped;

    while (1)
    {
        printf("\n\nGarage Work Scheduling : ");
        printf("\n\n1. Add a work");
        printf("\n2. Retrieve next work");
        printf("\n3. Show all work");
        printf("\n4. Exit");
        printf("\n\nEnter your choice : ");
        scanf("%hhu", &opt);

        switch(opt)
        {
            case 1 :    printf("\nEnter vehicle make : ");
                        temp_work.vehicle_make = get_str_memory(MAX_STR_SIZE);
                        scanf(" %[^\n]%*c", temp_work.vehicle_make);

                        printf("\nEnter vehicle model : ");
                        temp_work.vehicle_model = get_str_memory(MAX_STR_SIZE);
                        scanf(" %[^\n]%*c", temp_work.vehicle_model);

                        printf("\nEnter vehicle owner name : ");
                        temp_work.owner_name = get_str_memory(MAX_STR_SIZE);
                        scanf(" %[^\n]%*c", temp_work.owner_name);

                        printf("\nEnter vehicle owner phone number : ");
                        temp_work.owner_phno = get_str_memory(MAX_PHNO_SIZE);
                        scanf(" %[^\n]%*c", temp_work.owner_phno);

                        printf("\nEnter customer urgency : ");
                        scanf("%d", &temp_work.customer_urgency);

                        heappush(work_heap, &temp_work);

                        break;

            case 2 :    poppped = heappop(work_heap);
                        if (poppped.customer_urgency != -1)
                        {
                            _print_individual_work(poppped);
                        }
                        else
                        {
                            // Do Nothing
                        }

                        break;

            case 3 :    print_heap(work_heap);

                        break;

            case 4 :    return 0;

                        break; 

            default :   printf("\nInvalid option.\n");
        }
    }
}

inline int8_t *get_str_memory(uint32_t size)
{
    int8_t *temp = (int8_t*)malloc(sizeof(int8_t) * size);
    return temp;
}