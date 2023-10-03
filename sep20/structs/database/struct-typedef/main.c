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
		printf("\n3. Exit");
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

			case 3 : return 0;
					 break;

			default : printf("\nEnter a valid option!");
		}
	}

	return 0;
}

void read_info(st_emp *entry)
{
	printf("\nEnter the employee id:");
	scanf("%hhd", &(entry -> emp_id));

	printf("\nEnter the name:");
	scanf (" %[^\n]%*c", entry -> name);

	printf("\nEnter the designation of the employee:");
	scanf (" %[^\n]%*c", entry -> designation);

	printf("\nEnter the CTC:");
	scanf("%f", &(entry -> ctc));
}

void show_info(int8_t index, st_emp *db)
{
	int32_t i = 0;
	for(i = 0; i< index; i++)
	{
		printf("\n\nEmployee ID : %hhd", db[i].emp_id);
		printf("\nName : %s", db[i].name);
		printf("\nDesignation : %s", db[i].designation);
		printf("\nCTC : %f", db[i].ctc);
	}

	printf("\n");
}
