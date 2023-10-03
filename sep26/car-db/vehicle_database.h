#ifndef _VEHICLE_DB
#define _VEHICLE_DB

#define DB_MAX_SIZE 50
#define STR_MAX_SIZE 20

#include <stdint.h>

typedef struct
{
	uint8_t no_of_airbags;
	uint8_t traction_control;
	uint8_t ABS_available;
	uint8_t ESP_available;
	uint8_t speakers;
} TechSpecs;

typedef struct
{
	int8_t brand_name[STR_MAX_SIZE];
} Brand;

typedef struct 
{
	uint8_t type;
} VechicleType;

typedef struct
{
	int8_t model_name[STR_MAX_SIZE];
} Model;

typedef struct
{
	Brand *brand;
	Model *model;
	TechSpecs *tech_specs;
	VechicleType *vehicle_type;
} Vehicle;

Vehicle vehicle_db[DB_MAX_SIZE];

int32_t available_index_mask[DB_MAX_SIZE];

void _init_db();

void list_available_indices();

uint8_t _index_check(uint32_t i);

int8_t _strcmp(int8_t *a, int8_t *b);

void write_data(uint32_t index, Vehicle *info);

int32_t search(int8_t *model);

int32_t read_data(int8_t *model_name, Vehicle *info);

#endif
