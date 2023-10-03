#include <stdio.h>

#define MAX_SIZE 10

typedef signed int int32_t;
typedef unsigned char uint8_t;
typedef char int8_t;


typedef struct EmployeeDatabase
{
	int8_t emp_id;
	int8_t name[20];
	int8_t designation[20];
	float ctc;
} st_emp;

void read_info(st_emp *entry);
void show_info(int8_t index, st_emp *db);
void update_info(st_emp *db, int32_t index);

int main()
{

	int8_t option;
	int32_t idx = 0;
	st_emp database[MAX_SIZE];

	while(1)
	{
		printf("\n\nWelcome to employee database:\n");
		printf("--------------------------------");
		printf("\n1. Enter info");
		printf("\n2. View info");
		printf("\n3. Update info");
		printf("\n4. Exit");
		printf("\n\nEnter your choice:");
		scanf("%hhd", &option);

		switch(option)
		{
			case 1 : if (idx > 10)
							 printf("\nMax amount of entries reached.");
					 else
					 	read_info(&database[idx++]);
					 break;

			case 2 : show_info(idx, database);
					 break;

			case 3 : update_info(database, idx);
					 break;

			case 4 : return 0;
					 break;

			default : printf("\nEnter a valid option!");
		}
	}

	return 0;
}

void read_info(st_emp *entry)
{
	printf("\nEnter the employee id:");
	scanf("%hhd", &((*entry).emp_id));

	printf("\nEnter the name:");
	scanf (" %[^\n]%*c", (*entry).name);

	printf("\nEnter the designation of the employee:");
	scanf (" %[^\n]%*c", (*entry).designation);

	printf("\nEnter the CTC:");
	scanf("%f", &((*entry).ctc));
}

void show_info(int8_t index, st_emp *db)
{
	int32_t i = 0;
	for(i = 0; i< index; i++)
	{
		printf("\n\nEmployee ID : %hhd", (*(db + i)).emp_id);
		printf("\nName : %s", (*(db + i)).name);
		printf("\nDesignation : %s", (*(db + i)).designation);
		printf("\nCTC : %f", (*(db + i)).ctc);
	}

	printf("\n");
}

void update_info(st_emp *db, int32_t index)
{
	int8_t temp_id, choice;
	int32_t i = 0;

	printf("\nEnter the employee id:");
	scanf("%hhd", &temp_id);

	for(i = 0; i < index; i++)
	{
		if ((*(db + i)).emp_id == temp_id) 
			break;
		else
		{
			// Do nothing
		}
	}

	printf("\n\nEnter the information you want to update:");
	printf("\n 1. Name");
	printf("\n 2. Designation");
	printf("\n 3. CTC");
	printf("\nEnter your choice:");
	scanf("%hhd", &choice);

	switch(choice)
	{
		case 1 : printf("\nEnter the new name:");
				 scanf("%s", (*(db + i)).name);
				 break;

		case 2 : printf("\nEnter new designation:");
				 scanf("%s", (*(db + i)).designation);
				 break;

		case 3 : printf("\nEnter new CTC:");
				 scanf("%f", &(*(db + i)).ctc);
				 break;

		default : printf("\nInvalid choice to update.\n");
	}
}
