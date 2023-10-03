#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE 10
#define STR_SIZE 30


typedef struct
{
	int8_t emp_id;
	int8_t name[STR_SIZE];
	int8_t designation[STR_SIZE];
	float ctc;
} EmployeeDatabase;

EmployeeDatabase* read_info();
void show_info(int8_t id);
void check_info();
void delete_info(int8_t id);
void update_info(int8_t id);
void print_list();

int32_t hash_fn(int8_t id);

EmployeeDatabase **hash_table;

int main()
{

    hash_table = (EmployeeDatabase**)malloc(sizeof(EmployeeDatabase) * MAX_SIZE);

    int8_t temp_id;
	int8_t option;

    int32_t idx;

    EmployeeDatabase*   to_insert;

	while(1)
	{
		printf("\n\nWelcome to employee database:\n");
		printf("--------------------------------");
		printf("\n1. Enter info");
		printf("\n2. View info");
		printf("\n3. Exit");
        printf("\n4. Delete data");
        printf("\n5. Print data");
        printf("\n6. Update list");
		printf("\n\nEnter your choice:");
		scanf("%hhd", &option);

		switch(option)
		{
			case 1 :    to_insert = read_info();
                        idx = hash_fn(to_insert -> emp_id);
                        if (hash_table[idx] != NULL)
                        {
                            printf("\nCollision data already existed at this position.\n");
                        }
                        else
                        {
                            hash_table[idx] = to_insert;
                        }

					    break;

			case 2 :    printf("\nEnter the employee id : ");
                        scanf("%hhu", &temp_id);
                        show_info(temp_id);
					    break;

			case 3 :    return 0;
					    break;

            case 4 :    printf("\nEnter the employee id : ");
                        scanf("%hhu", &temp_id);
                        delete_info(temp_id);
                        break;

            case 5 :    print_list();
                        break;

            case 6 :    printf("\nEnter the employee id : ");
                        scanf("%hhu", &temp_id);
                        update_info(temp_id);
                        break;

			default : printf("\nEnter a valid option!");
		}
	}

	return 0;
}

EmployeeDatabase* read_info()
{
	EmployeeDatabase *new = (EmployeeDatabase*)malloc(sizeof(EmployeeDatabase));
    
    printf("\nEnter the employee id:");
	scanf("%hhd", &(new -> emp_id));

	printf("\nEnter the name:");
	scanf (" %[^\n]%*c", new -> name);

	printf("\nEnter the designation of the employee:");
	scanf (" %[^\n]%*c", new -> designation);

	printf("\nEnter the CTC:");
	scanf("%f", &new -> ctc);

    return new;
}

void show_info(int8_t id)
{
    if (hash_table[id] == NULL)
    {
        printf("\nData does not exist.\n");
    }
    else
    {
        printf("\n\nEmployee ID : %hhd", hash_table[id] -> emp_id);
        printf("\nName : %s", hash_table[id] -> name);
        printf("\nDesignation : %s", hash_table[id] -> designation);
        printf("\nCTC : %f", hash_table[id] -> ctc);
    }
}

void check_info()
{
    uint32_t i, count = 0;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (hash_table[i] != NULL)
        {
            count += 1;
        }
    }

    printf("\n%d data points exist.\n", count);
}

void delete_info(int8_t id)
{
    if (hash_table[id] == NULL)
    {
        printf("\nData to be deleted is not found.\n");
    }
    else
    {
        hash_table[id] = NULL;

        printf("\nData with %d deleted.\n", id);
    }
}

void update_info(int8_t id)
{
    int8_t option;

    if (hash_table[id] == NULL)
    {
        printf("\nData does not exist.\n");
    }
    else
    {
        printf("\nData which you want to manipulate : \n");
        printf("\n1. Name");
        printf("\n2. Designation");
        printf("\n3. CTC");
        printf("\n\nEnter your choice : ");
        scanf("%hhu", &option);

        switch(option)
        {
            case 1 :    printf("\nEnter the new name : ");
                        scanf(" %[^\n]%*c", hash_table[id] -> name);

                        break;

            case 2 :    printf("\nEnter the new designation : ");
                        scanf(" %[^\n]%*c", hash_table[id] -> designation);

                        break;

            case 3 :    printf("\nEnter the new CTC : ");
                        scanf("%f", &hash_table[id] -> ctc);

                        break;

            default :   printf("\nInvalid option.\n");
        }
    }
}

int32_t hash_fn(int8_t id)
{
    return (id % (MAX_SIZE + 1));
}

void print_list()
{
    uint32_t i;

    for (i = 0; i < MAX_SIZE; i++)
    {
        if (hash_table[i] != NULL)
        {
            printf("\n\nEmployee ID : %hhd", hash_table[i] -> emp_id);
            printf("\nName : %s", hash_table[i] -> name);
            printf("\nDesignation : %s", hash_table[i] -> designation);
            printf("\nCTC : %f", hash_table[i] -> ctc);
        }
        else
        {
            // Do nothing
        }
    }
}