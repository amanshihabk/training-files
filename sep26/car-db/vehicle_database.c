#include "vehicle_database.h"
#include <stdio.h>

void _init_db()
{
	uint32_t i;
	for (i = 0; i < DB_MAX_SIZE; i++)
	{
		available_index_mask[i] = 1;
	}
}

void list_available_indices()
{
	uint32_t i;
	
	printf("\nAvailable indices are : ");
	for (i = 0; i < DB_MAX_SIZE; i++)
	{
		if (available_index_mask[i])
		{
			printf("%d  ", i);
		}
		else
		{
			// Do nothing
		}
	}
}

uint8_t _index_check(uint32_t i)
{
	if (!available_index_mask[i])
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int8_t _strcmp(int8_t *a, int8_t *b)
{
	uint32_t i;
	int8_t flag = 1;


	for(i = 0; (a[i] != '\0') && (b[i] != '\0'); i++)
	{
		if (a[i] != b[i])
		{
			flag = 0;
			break;
		}
		else
		{
			// Do nothing
		}
	}

	if (a[i] == '\0' || b[i] == '\0')
			flag = 0;

	return flag;
}

void write_data(uint32_t index, Vehicle *info)
{
	vehicle_db[index] = *info;
	available_index_mask[index] = 0;
}

int32_t search(int8_t *model)
{
	int32_t i;

	for (i =0 ; i < DB_MAX_SIZE; i++)
	{
		if (available_index_mask[i] && (_strcmp((vehicle_db[i].model.model_name), model)))
		{
			return i;
		}
		else
		{
			// Do nothing
		}
	}

	return -1;
}


int32_t read_data(int8_t *model_name, Vehicle *info)
{
	int32_t _ret_val = search(model_name);

	if (_ret_val == -1)
	{
		printf("\nVehicle details not found.\n");
		return -1;
	}
	else
	{
		*info = vehicle_db[_ret_val];
		return 1;
	}
}
