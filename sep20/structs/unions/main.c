#include <stdio.h>

typedef signed int int32_t;
typedef signed char int8_t;

/* This ordering has 24 bytes size
struct Emp
{
	int8_t empname[10];
	int32_t empid;
	int8_t desid;
	float ctc;
};
*/

union Emp
{
	int8_t empname[10];
	int32_t empid;
	double x;
	int8_t devid;
	float ctc;
	int8_t desid;
};

int main()
{
	union Emp emp1;

	printf("\nEnter the name:");
	scanf("%s", emp1.empname);

	printf("\nEnter the empid:");
	scanf("%d", &emp1.empid);

	printf("\nEnter the designation id:");
	scanf("%hhd", &emp1.desid);

	printf("\nEnter the ctc:");
	scanf("%f", &emp1.ctc);

	printf("\nEnter device id:");
	scanf("%hhd", &emp1.devid);

	printf("\n\nName : %s", emp1.empname);
	printf("\nEmp id : %d", emp1.empid);
	printf("\nDesignation id : %hhd", emp1.desid);
	printf("\nCTC : %f", emp1.ctc);
	printf("\ndev id : %c", emp1.devid);

	printf("\n\nSize of emp1 struct is %lu.\n", sizeof(emp1));

	return 0;
}
