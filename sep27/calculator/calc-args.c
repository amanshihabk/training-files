#include <stdio.h>
#include <stdint.h>

int32_t add(int, int);
int32_t sub(int, int);
int32_t mul(int, int);
int32_t div(int, int);

int32_t _atoi(int8_t *buff);

void update_ptr(int32_t (**fun_ptr)(int32_t, int32_t), int8_t opt);

int main(int argc, char *argv[])
{
	int32_t a, b, option;
	int32_t (*fun) (int32_t, int32_t);

	if (argc < 4)
	{
		printf("\nUsage : executable-name option operand1 operand2\n\n");
		printf("\noption : 1 - addition, 2 - subtraction, 3 - division, 4 - multiplication\n");
		printf("\noperand 1 & operand 2 : the numbers to which the operations are to be performed.\n");

		return 0;
	}
	else
	{
		a = _atoi(argv[2]);
		b = _atoi(argv[3]);
		option = _atoi(argv[1]);
		
		update_ptr(&fun, option);

		printf("The result is %d.\n", fun(a, b));
	}
		

	return 0;
}


void update_ptr(int32_t (**fun_ptr)(int32_t, int32_t), int8_t opt)
{
	switch(opt)
	{
		case 1 : *fun_ptr = add;
				 break;

		case 2 : *fun_ptr = sub;
				 break;

		case 3 : *fun_ptr = div;
				 break;

		case 4 : *fun_ptr = mul;
				 break;
		default:
				 printf("Wrong Option\r\n");
				 break;
	}
}

int32_t add(int32_t a, int32_t b)
{
	return a + b;
}

int32_t sub(int32_t a, int32_t b)
{
	return a - b;
}

int32_t mul(int32_t a, int32_t b)
{
	return a * b;
}

int32_t div(int32_t a, int32_t b)
{
	return a / b;
}


int32_t _atoi(int8_t *buff)
{
	int32_t num = 0;
	uint32_t i = 0;
	int32_t sign = 1;

	if (buff[i] == '-')
	{
		sign = -1;

		i += 1;
	}
	else
	{
		// Do nothing
	}

	for (; buff[i] != '\0'; i++)
	{
		num = (num * 10) + (buff[i] - '0');
	}

	return sign * num;
}
