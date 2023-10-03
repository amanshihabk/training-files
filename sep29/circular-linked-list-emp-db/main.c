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

    struct EmployeeDatabase *next;
} EmployeeDatabase;

EmployeeDatabase* read_info();
void show_info();
void check_info();
void delete_info();
void update_info();

EmployeeDatabase** search_id(int8_t id);
EmployeeDatabase** search_name(int8_t* name);

EmployeeDatabase *head = NULL;

int main()
{

	int8_t option;

    EmployeeDatabase* to_insert;
    EmployeeDatabase*  temp;

	while(1)
	{
		printf("\n\nWelcome to employee database:\n");
		printf("--------------------------------");
		printf("\n1. Enter info");
		printf("\n2. View info");
		printf("\n3. Exit");
        printf("\n4. Delete data");
        printf("\n5. Print list");
        printf("\n6. Update list");
		printf("\n\nEnter your choice:");
		scanf("%hhd", &option);

		switch(option)
		{
			case 1 :    to_insert = read_info();

                        if (head == NULL)
                        {
                            head = to_insert;
                            head -> next = head;
                        }
                        else
                        {
                            temp = head;

                            while (temp -> next != head)
                            {
                                temp = temp -> next;
                            }

                            temp -> next = to_insert;

                            to_insert -> next = head;
                        }

					    break;

			case 2 :    show_info();
					    break;

			case 3 :    return 0;
					    break;

            case 4 :    delete_info();
                        break;

            case 5 :    print_list();
                        break;

            case 6 :    update_info();
                        break;

			default : printf("\nEnter a valid option!");
		}
	}

	return 0;
}

EmployeeDatabase* read_info()
{
	EmployeeDatabase *new = (EmployeeDatabase*)malloc(sizeof(EmployeeDatabase));

    EmployeeDatabase *temp;
    
    printf("\nEnter the employee id:");
	scanf("%hhd", &(new -> emp_id));

	printf("\nEnter the name:");
	scanf (" %[^\n]%*c", new -> name);

	printf("\nEnter the designation of the employee:");
	scanf (" %[^\n]%*c", new -> designation);

	printf("\nEnter the CTC:");
	scanf("%f", &new -> ctc);

    new -> next = NULL;

    return new;
}

void show_info()
{
	EmployeeDatabase *temp = head;
    
    int8_t opt;
    int8_t _search_id;


    int8_t *_search_name = (int8_t *)malloc(sizeof(int8_t) * STR_SIZE);

    if (temp == NULL)
    {
        printf("\nDatabase is empty.\n");
    }
    else
    {

        printf("\nRead data w.r.t : \n");
        printf("\n1. Name");
        printf("\n2. Id\n");
        printf("\nEnter your choice : ");
        scanf("%hhu", &opt);
	
        switch(opt)
        {
            case 1 :    printf("\nEnter the name of the employee : ");
                        scanf(" %[^\n]%*c", _search_name);

                        break;

            case 2 :    printf("\nEnter the id of the employee : ");
                        scanf("%hhu", &_search_id);

                        break;

            default :   printf("\nInvalid option.\n");
        }

        while (temp != NULL)
        {
            if (opt == 1)
            {
                if (strcmp(_search_name, temp -> name) == 0)
                {
                    printf("\n\nEmployee ID : %hhd", temp -> emp_id);
                    printf("\nName : %s", temp -> name);
                    printf("\nDesignation : %s", temp -> designation);
                    printf("\nCTC : %f", temp -> ctc);

                    return;
                }
                else
                {
                    // Do nothing
                }
            }
            else if (opt == 2)
            {
                if (temp -> emp_id == _search_id)
                {
                    printf("\n\nEmployee ID : %hhd", temp -> emp_id);
                    printf("\nName : %s", temp -> name);
                    printf("\nDesignation : %s", temp -> designation);
                    printf("\nCTC : %f", temp -> ctc);

                    return;
                }
                else
                {
                    // Do nothing
                }
            }
            else
            {
                // Do nothing
            }

            temp = temp -> next;
        }

        printf("\nData not found.\n");
    }

	printf("\n");
}

void check_info()
{
    EmployeeDatabase *temp = head;

    uint32_t count = 0;

    while (temp != NULL)
    {
        count += 1;

        temp = temp -> next;
    }
}

void delete_info()
{
    int8_t opt;

    int8_t temp_id;
    int8_t *temp_name;

    EmployeeDatabase **query_result;

    printf("\nDelete w.r.t : \n");
    printf("\n1. Id");
    printf("\n2. Name");
    printf("\nEnter your choice : ");
    scanf("%hhu", &opt);

    switch(opt)
    {
        case 1 :    printf("\nEnter the id : ");
                    scanf("%hhu", &temp_id);
                    query_result = search_id(temp_id);

                    break;

        case 2 :    printf("\nEnter the name : ");
                    scanf(" %[^\n]%*c", temp_name);
                    query_result = search_name(temp_name);

                    break;

        default :   printf("\nWrong option.\n");
                    return;
    }

    if (query_result[1] == NULL)
    {
        printf("\nData to be deleted not found.\n");
    }
    else if (query_result[0] == NULL)
    {
        if (query_result[2] == head)
        {
            head = NULL;
        }
        else
        {
            head = query_result[2];
            head -> next = head;
        }
    }
    else
    {
        query_result[0] -> next = query_result[2];
        free(query_result[1]);
    }

}

void update_info()
{
    int8_t opt;

    int8_t temp_id;
    int8_t *temp_name;

    EmployeeDatabase **query_result;
    EmployeeDatabase *_insertable;
    EmployeeDatabase* temp;

    printf("\nUpdate w.r.t : \n");
    printf("\n1. Id");
    printf("\n2. Name");
    printf("\nEnter your choice : ");
    scanf("%hhu", &opt);

    switch(opt)
    {
        case 1 :    printf("\nEnter the id : ");
                    scanf("%hhu", &temp_id);
                    query_result = search_id(temp_id);

                    break;

        case 2 :    printf("\nEnter the name : ");
                    scanf(" %[^\n]%*c", temp_name);
                    query_result = search_name(temp_name);

                    break;

        default :   printf("\nWrong option.\n");
                    return;
    }

    _insertable = read_info();

    if (query_result[1] == NULL)
    {
        printf("\nInserting at the end.\n");

        temp = head;
        while (temp -> next != head)
        {
            temp = temp -> next;
        }

        temp -> next = _insertable;
        _insertable -> next = head;

    }
    else if (query_result[0] == NULL)
    {
        _insertable -> next = head;
        temp = head;
        while (temp -> next != head)
        {
            temp = temp -> next;
        }
        temp -> next = _insertable;
        head = _insertable;
    }
    else if (query_result[2] == head)
    {
        query_result[2] -> next = _insertable;
        _insertable -> next = head;
    }
    else
    { 
        query_result[0] -> next = _insertable;
        _insertable -> next = query_result[1];
    }
}

EmployeeDatabase** search_id(int8_t id)
{
    EmployeeDatabase *temp = head;
    EmployeeDatabase *prev = temp;
    EmployeeDatabase **to_return = (EmployeeDatabase **)malloc(sizeof(EmployeeDatabase*) * 3);

    while (temp != NULL)
    {
        if (temp -> emp_id == id)
        {
            break;
        }
        else
        {
            // Do nothing
        }
        prev = temp;
        temp = temp -> next;

        if (temp == head)
            break;
    }

    if (temp == head)
    {
        to_return[0] = NULL;
    }
    else if (temp == NULL)
    {
        to_return[0] = NULL;
        to_return[1] = NULL;
        to_return[2] = NULL;

        return to_return;
    }
    else
    {
        to_return[0] = prev;
    }

    to_return[1] = temp;
    to_return[2] = temp -> next;

    return to_return;
}

EmployeeDatabase** search_name(int8_t* name)
{
    EmployeeDatabase *temp = head;
    EmployeeDatabase *prev = temp;
    EmployeeDatabase **to_return = (EmployeeDatabase **)malloc(sizeof(EmployeeDatabase*) * 3);

    while (temp != NULL)
    {
        if (strcmp(temp -> name, name) == 0)
        {
            break;
        }
        else
        {
            // Do nothing
        }
        prev = temp;
        temp = temp -> next;

        if (temp == head)
            break;
    }

    if (temp == NULL)
    {
        to_return[0] = NULL;
        to_return[1] = NULL;
        to_return[2] = NULL;
    }
    else if (temp == head)
    {
        to_return[0] = NULL;
        to_return[1] = temp;
        to_return[2] = temp -> next;
    }
    else
    {
        to_return[0] = prev;
        to_return[1] = temp;
        to_return[2] = temp -> next;
    }

    return to_return;
}

void print_list()
{
    EmployeeDatabase* temp = head;

    if (head == NULL)
    {
        printf("\nDatabase empty.\n");
        return;
    }

    if (temp -> next == head)
    {
        printf("\n\nEmployee ID : %hhd", temp -> emp_id);
        printf("\nName : %s", temp -> name);
        printf("\nDesignation : %s", temp -> designation);
        printf("\nCTC : %f", temp -> ctc);
    }
    else
    {
        // Do nothing
    }

    while (temp -> next != head)
    {
        printf("\n\nEmployee ID : %hhd", temp -> emp_id);
        printf("\nName : %s", temp -> name);
        printf("\nDesignation : %s", temp -> designation);
        printf("\nCTC : %f", temp -> ctc);

        temp = temp -> next;

        if (temp -> next == head)
        {
            printf("\n\nEmployee ID : %hhd", temp -> emp_id);
            printf("\nName : %s", temp -> name);
            printf("\nDesignation : %s", temp -> designation);
            printf("\nCTC : %f", temp -> ctc);
        }
    }
}