#include <stdio.h>
#include "vehicle_database.h"


int main()
{
	uint8_t choice;
	uint32_t index_no;
	Vehicle temp_vehicle;
	int8_t model_name[STR_MAX_SIZE];
	int32_t index_ret, _ret_val;

	_init_db();

	while(1)
	{
		printf("\nThese are your optins:");
		printf("\n-----------------------\n");
		printf("\n1. Write data");
		printf("\n2. Read data");
		printf("\n3. Search data");
		printf("\n4. Exit");
		printf("\n5. List available indices");
		printf("\nEnter your choice : ");
		scanf("%hhu", &choice);

		switch(choice)
		{
			case 1 :	printf("\nEnter an index : ");
						scanf("%u", &index_no);
						if (_index_check(index_no))
						{
							vehicle_db[index_no] = (Vehicle*)malloc(sizeof(Vehicle));

							vehicle_db[index_no] -> brand = (Brand*)malloc(sizeof(Brand));
							vehicle_db[index_no] -> model = (Model*)malloc(sizeof(Model));
							vehicle_db[index_no] -> tech_specs = (TechSpecs*)malloc(sizeof(TechSpecs));
							vehicle_db[index_no] -> vehicle_type = (VechicleType*)malloc(sizeof(VechicleType));

							printf("\nEnter brand name : ");
							scanf(" %[^\n]%*c", vehicle_db[index_no] -> brand -> brand_name);
						
							printf("\nEnter the model name : ");
							scanf(" %[^\n]%*c", vehicle_db[index_no] -> model -> model_name);

							printf("\n\nEnter the technical specs ");
							printf("\nNo. of airbags : ");
							scanf("%hhu", &(vehicle_db[index_no] -> tech_specs -> no_of_airbags));
							printf("\nTraction Control (0/1) : ");
							scanf("%hhu", &(vehicle_db[index_no] -> tech_specs -> traction_control));
							printf("\nABS available (0/1) : ");
							scanf("%hhu", &(vehicle_db[index_no] -> tech_specs -> ABS_available));
							printf("\nESP Available (0/1) : ");
							scanf("%hhu", &(vehicle_db[index_no] -> tech_specs -> ESP_available));
							printf("\nNo. of speakers : ");
							scanf("%hhu", &(vehicle_db[index_no] -> tech_specs -> speakers));

							printf("\nEnter vehicle type (0 - Sedan, 1 - SUV, 2 - Hatchback) : ");
							scanf("%hhu", &(vehicle_db[index_no] -> vehicle_type -> type));

							//write_data(index_no, &temp_vehicle);
						}
						else
						{
							printf("\nData already available at index.");
						}

						break;

			case 2 :	printf("\nEnter the name of the model to read : ");
						scanf(" %[^\n]%*c", model_name);
						
						_ret_val = read_data(model_name, &temp_vehicle);

						if (_ret_val != -1)
						{
							printf("\nBrand name : %s", temp_vehicle.brand.brand_name);
							printf("\nModel name : %s", temp_vehicle.model.model_name);

							printf("\n\nTechnical Specification : ");
							printf("\nNo. of airbags : %hhu", temp_vehicle.tech_specs.no_of_airbags);
							printf("\nTraction Control : %hhu", temp_vehicle.tech_specs.traction_control);
							printf("\nABS : %hhu", temp_vehicle.tech_specs.ABS_available);
							printf("\nESP : %hhu", temp_vehicle.tech_specs.ESP_available);
							printf("\nSpeakers : %hhu", temp_vehicle.tech_specs.speakers);

							printf("\n\nVehicle Type : %hhu", temp_vehicle.vehicle_type.type);
						}
						else
						{
							printf("Model not found in database.");
						}

						break;

			case 3 : 	printf("\nEnter the model to search : ");
					 	scanf(" %[^\n]%*c", model_name);

						index_ret = search(model_name);

						if (index_ret != -1)
						{
							printf("\nModel found!");
						}
						else
						{
							printf("\nModel not found.");
						}

						break;

			case 4 : return 0;
					 break;

			case 5 : list_available_indices();
					 break;

			default : printf("\nInvalid option.");
		}
	}

	return 0;
}
