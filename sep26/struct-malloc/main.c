#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef signed int int32_t;
typedef unsigned char uint8_t;
//typedef char int8_t;
typedef unsigned int uint32_t;


struct EmployeeDatabase
{
	int8_t emp_id;
	int8_t name[20];
	int8_t designation[20];
	float ctc;
};

struct EmployeeDatabase* database[MAX_SIZE];

void read_info(uint32_t index);
void show_info();
void update_info();

int main()
{

	int8_t option;
	int32_t idx = 0;

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
					 	read_info(idx++);
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

void read_info(uint32_t index)
{
	if (database[index] == NULL)
	{
		database[index] = (struct EmployeeDatabase*)malloc(sizeof(struct EmployeeDatabase));

		printf("\nEnter the employee id:");
		scanf("%hhd", &(database[index] -> emp_id));

		printf("\nEnter the name:");
		scanf (" %[^\n]%*c", database[index] -> name);

		printf("\nEnter the designation of the employee:");
		scanf (" %[^\n]%*c", database[index] -> designation);

		printf("\nEnter the CTC:");
		scanf("%f", &(database[index] -> ctc));
	}
	else
	{
		printf("\nIndex occupied");
	}
}

void show_info()
{
	int32_t i = 0;
	for(i = 0; i < MAX_SIZE; i++)
	{
		if (database[i] != NULL)
		{
			printf("\n\nEmployee ID : %hhd", database[i] -> emp_id);
			printf("\nName : %s", database[i] -> name);
			printf("\nDesignation : %s", database[i] -> designation);
			printf("\nCTC : %f", database[i] -> ctc);
		}
	}
	

	printf("\n");
}

void update_info()
{
	int32_t i = 0;
	int8_t temp_id, choice;

	printf("\nEnter the emp id:");
	scanf("%hhd", &temp_id);

	for (i = 0; i < MAX_SIZE; i++)
	{
		if (database[i] != NULL && database[i] -> emp_id == temp_id)
		{
			break;
		}
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
				 scanf("%s", database[i] -> name);
				 break;

		case 2 : printf("\nEnter new designation:");
				 scanf("%s", database[i] -> designation);
				 break;

		case 3 : printf("\nEnter new CTC:");
				 scanf("%f", &(database[i] -> ctc));
				 break;

		default : printf("\nInvalid choice to update.\n");
	}
}
